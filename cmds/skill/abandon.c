// abandon.c
// Modified by zeratul,2000.3.31

inherit F_CLEAN_UP;
#include <ansi.h>

mapping valid_skill = ([
/*
        "jiuyin-baiguzhao":  "�����׹�ץ",
        "bixie-jian":        "��а����",
        "zhengqijue":        "������",
*/
]);
int main(object me, string arg)
{
	int skill_lvl, lvl=0, i;
	string skill, *sname;
	mapping smap, pmap, skl;

	smap = me->query_skill_map();
	pmap = me->query_skill_prepare();
	if(arg == "all" && wizardp(me))
	{
		skl = me->query_skills();
		if(!sizeof(skl))
		{
			write("��Ŀǰ��û��ѧ���κμ��ܡ�\n");
			return 1;
		}
		sname = sort_array( keys(skl), (: strcmp :) );
		write("���������ѧϰ���м��ܡ�\n");
		for( i = sizeof(skl)-1; i >= 0; i--)
		{
			me->delete_skill(sname[i]);
		}
		for (i = sizeof(smap)-1; i >= 0; i --)
			me->map_skill(keys(smap)[i]);
		for (i = sizeof(pmap)-1; i >= 0; i -- )
			me->prepare_skill(keys(pmap)[i]);
		me->reset_action();
		return 1;
	}
	if(!arg || arg == "" || sscanf(arg, "%s %d", skill, lvl)!=2 &&
		sscanf(arg, "%s", skill)!=1)
		return notify_fail("��Ҫ������һ��ܣ�\n");
	if( !undefinedp(valid_skill[skill]) )
		return notify_fail(to_chinese(skill)+"�總��֮���������޷�������\n");
	skill_lvl = me->query_skill(skill,1);
	if( lvl <0 )
		return notify_fail("���ܼ�����Ϊ����\n");
	if( lvl == skill_lvl && lvl>0)
		return notify_fail("�������Ⱑ���㲻�����⼶��ô��\n");
	if( lvl > skill_lvl || lvl > 800)
		return notify_fail("������ܲ�û��ѧ���������\n");
	if( undefinedp((me->query_skills())[skill]) )
		return notify_fail("�㲢û��ѧ������ܡ�\n");
	if ((int)skill_lvl >= 100)
  {
  	write(HIW"ȷ����"+to_chinese(skill)+"("+skill+")"+
           "��"+HIR+chinese_number(skill_lvl)+HIW+"��������"+
           HIR+chinese_number(lvl)+HIW+"����(y/n)\n"NOR
           );
  	input_to("check_input",1,me,skill,lvl);
  }
  else
  {
		if( !me->delete_skill(skill) )
	    	return notify_fail("�㲢û��ѧ������ܡ�\n");
  	write("�������������ѧϰ" + to_chinese(skill) + "��\n");
		if( lvl > 0 ) me->set_skill(skill, lvl);
// ����������䣬����ȫ����ĳһ���ʱ���Զ���enable�б���ɾ��֮������ս���е�Bad action�� Added by Spacenet@FXLT
		else 
		{
			for (i = sizeof(smap)-1; i >= 0; i --)
				if ((string)smap[keys(smap)[i]] == skill)
					me->map_skill(keys(smap)[i]);
// ����ʱҲ��prepare����ɾ����Added by zeratul
			for (i = sizeof(pmap)-1; i >= 0; i -- )
				if ( ( string ) values(pmap)[i] == skill )
					me->prepare_skill(keys(pmap)[i]);
			me->reset_action();
		}
  }
  return 1;
}
int check_input(string arg,object me,string skill,int lvl)
{
	int i;
	mapping smap, pmap, skl;

	smap = me->query_skill_map();
	pmap = me->query_skill_prepare();
	if (strsrch(arg,"y")>=0)
	{
		if( !me->delete_skill(skill) )
	    	return notify_fail("�㲢û��ѧ������ܡ�\n");
		if( lvl > 0 ) {
  		write(HIW"������������ֵ�" + to_chinese(skill)+"��\n"NOR);
			me->set_skill(skill, lvl);
		}
	// ����������䣬����ȫ����ĳһ���ʱ���Զ���enable�б���ɾ��֮������ս���е�Bad action�� Added by Spacenet@FXLT
		else {
		write(HIW"����ľ�����ѧ֮" + to_chinese(skill) + "��\n"NOR);
			for (i = sizeof(smap)-1; i >= 0; i --)
				if ((string)smap[keys(smap)[i]] == skill)
					me->map_skill(keys(smap)[i]);
	// ����ʱҲ��prepare����ɾ����Added by zeratul
			for (i = sizeof(pmap)-1; i >= 0; i -- )
				if ( ( string ) values(pmap)[i] == skill )
					me->prepare_skill(keys(pmap)[i]);
			me->reset_action();
		}
	return 1;
	}
	else
//  	write("�������������ѧϰ" + to_chinese(skill) + "��\n");
	return 1;
}
int help()
{
	write(@TEXT
ָ���ʽ��abandon | fangqi <��������> [����]

    ���ָ��������ȫ�򲿷ַ���һ������ѧ���ļ��ܣ�����������������
�������ʾ����ȫ����һ��ܣ�������ܴ��������������ɾ���������
�Ժ�Ҫ��������ӣ���ʼ����������ؿ��������������˼������������
���ʾ���ַ���ĳ���ܣ���������һ����

    ���磺�������| �����������| ����  ��ʾ������ֻʣ�£���
������д�֣����ָ��ʹ�õĳ���ͨ��������ɾ��һЩ��С���������ļ��ܣ�
����ÿ�������Ų�ͬ���츳������ϰ���书Ҳ������ͬ�����������ѧ����ͷ
��ֻ������������

TEXT
	);
	return 1;
}