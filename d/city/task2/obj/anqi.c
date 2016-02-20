// anqi.c ����

#include <ansi.h>
#include <combat.h>
inherit ITEM;

#define tired_damage 20

int * max_damage = ({
	400,
	380,
	410,
	410,
	450,
	390,
});

int * fix_damage = ({
	20,
	20,
	20,
	20,
	25,
	22,
});

string * name_str = ({
	"���ƴ�",
	"����޼",
	"������",
	"��β��",
	"�滨��",
	"���",
});

string * id = ({
	"chuanyun ci",
	"ci jili",
	"feiyan suo",
	"fengwei zhen",
	"lihua ding",
	"xiu jian",
});

string * short_id = ({
	"cc",
	"cj",
	"fs",
	"fz",
	"ld",
	"xj",
});

string * des_str = ({
	"����һ�����ƴ̣�����ϵ��һ��ϸ�����������ڷɴ���������\n",
	"����һ�Ż������ǵ��̵�����޼�����Ե�������ʹ�á�\n",
	"����һ���������ӵ����ڡ�\n",
	"�ⶫ���ƺ��Ƕ�ͯ��ˣ��С��һ��������ͭ�Ͻ����Ĺ������Խ����ɵĹ��Һ���ܽ�ʵ��\n",
	"һ�����µİ��������С���ӣ���������кܶ�ϸ����˿�Ŀס�\n��������һ����ť���Ա���С����š�����֮���������֡�\n",
	"����һ���������Ƶü��侫�ɣ�����װ����Ͳ�����԰�����ˡ�\n�Ա���һ��С��ť��һ����ť������ͻᷢ��(shot)��ȥ�ˡ�\n",
});

string * shot_str = ({
	"$Nһ�����е����������ƴ�������$n�̹�ȥ��\n",
	"$N�ӻ�������һ˫�����״��ã�����������һ�Ŵ���޼������$n��\n",
	"$N��һ�������İ��صķ�����ֱ��$n��\n",
	"$N����С���Ĺ��ң�����һ֧��β�룬��$n��ȥ��\n",
	"$N�������ϵĻ�ťһ�ƣ�ֻ���á����͡��ƿ������ϣ���ʮϸ����˿���滨��һ
�Ӷ�����ֱ��$n��\n",
	"$Ņ�����������˻�ť��һ֧������$N����Ͳ����$n��ȥ��\n",
});

string * target_str = ({
	"���$Nһ��֮�£�û�ж㿪��һ����\n",
	"���$Nһ��֮�£�û�ж㿪��һ����\n",
	"$N�ҽ�һ������������ţ�\n",
	"$N��û���ü��ܿ����ͱ������ˣ�\n",
	"$Nֻ������ǰ��ããһƬ�����޿ɱܣ�������������ţ�\n",
	"ֻ��$N�ҽ�һ����������������ţ�\n",
});

string * escape_str = ({
	"�����;�ƺ���ʲô��������һ�£�����ʧȥ��׼ͷ��û���˵�$N��\n",
	"���$N���ɵ����Ա�һ�ã��������˿ա�\n",
	"���$Nһ��������û�����С�\n",
	"$N����һ�ã���������$N���ֱ��ӹ��������ǻ�����$N��Ƥ�⡣\n",
	"���$Nһ���������а��������˿ա�\n",
	"$N���ܵ����Ա�һ�ã����ֻ�ǲ�����$N��Ƥ�⣬��û����ɶ���˺���\n",
});

int i; 
void init()
{
	add_action("do_shot","shot");
}

void create()
{
	i = random(sizeof(name_str));

	set_name(HIY+name_str[i]+NOR, ({ id[i],short_id[i] }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("value", 0);
		set("material", "steel");
		set("long", des_str[i]);
	}
	setup();
}

int do_shot(string arg)
{
	object obj,weapon;
	object me = this_player();
	int lv1,lv2,lv3,lv4,damage;
	string skill_type;
	int tired;

	if (environment(me)->query("no_fight"))
		return notify_fail("�����ֹս����\n");
	if( !arg)
		return notify_fail("��Ҫ���˭��\n");
	if( !objectp(obj = present(arg, environment(me)) ))
		return notify_fail("����û������ˣ�\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
	if (obj == me) return notify_fail("���Լ������벻������\n");

	message_vision(HIR+shot_str[i]+NOR,me, obj);

	if( objectp(weapon = obj->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else skill_type = "unarmed";

	lv1 = COMBAT_D->skill_power(obj, skill_type, SKILL_USAGE_DEFENSE);
	lv2 = COMBAT_D->skill_power(obj, "dodge", SKILL_USAGE_DEFENSE);

	lv3 = (lv2 + (weapon? lv1: (lv1/10))) / 100 + 1;
	lv4 = obj->query_temp("apply/armor");

	tired = obj -> query("total_tired");
	damage = random(max_damage[i]) - random(lv3+lv4) + fix_damage[i] + random(tired_damage * tired);

	if (damage > 0 )
	{
		obj->receive_wound("qi",damage);
		message_vision(HIR+target_str[random(sizeof(target_str))]+NOR,obj);
	}
	else message_vision(HIW+escape_str[random(sizeof(escape_str))]+NOR,obj);

	destruct(this_object());
	return 1;
}
