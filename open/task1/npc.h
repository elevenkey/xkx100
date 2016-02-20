// Room: /d/city/npc.c

#include <ansi.h> 
 
mapping *dizhia=({
	(["cdizhi":	"����ɽ",
	"weizhi2" :	"/d/baituo/cao1",]),  
	(["cdizhi":	"����",
	"weizhi2" :	"/d/changcheng/changcheng13",]),  
	(["cdizhi":	"���ݳ�",
	"weizhi2" :	"/d/city/bingyin",]),  
	(["cdizhi":	"������",
	"weizhi2" :	"/d/city2/huayuan",]),  
	(["cdizhi":	"�ɶ���",
	"weizhi2" :	"/d/city3/wuhouci",]),  
	(["cdizhi":	"������",
	"weizhi2" :	"/d/city4/chaguan",]),  
	(["cdizhi":	"������",
	"weizhi2" :	"/d/dali/tingyuan",]),  
	(["cdizhi":	"����ɽ",
	"weizhi2" :	"/d/emei/jieyindian",]),  
	(["cdizhi":	"��ɽ��",
	"weizhi2" :	"/d/foshan/street4",]),  
	(["cdizhi":	"���ݳ�",
	"weizhi2" :	"/d/fuzhou/luoxingta",]),  
	(["cdizhi":	"����",
	"weizhi2" :	"/d/guanwai/xuedi2",]),  
	(["cdizhi":	"���ݳ�",
	"weizhi2" :	"/d/hangzhou/shiwudong",]),  
	(["cdizhi":	"��ľ��",
	"weizhi2" :	"/d/heimuya/shijie2",]),  
	(["cdizhi":	"��ɽ",
	"weizhi2" :	"/d/hengshan/yuyang",]),  
	(["cdizhi":	"��ɽ",
	"weizhi2" :	"/d/henshan/nantaisi",]),  
	(["cdizhi":	"�ƺ�",
	"weizhi2" :	"/d/huanghe/weifen",]),  
	(["cdizhi":	"��ɽ",
	"weizhi2" :	"/d/huashan/yunuci",]),  
	(["cdizhi":	"�����",
	"weizhi2" :	"/d/jiangling/longzhong",]),  
	(["cdizhi":	"���˳�",
	"weizhi2" :	"/d/jiaxing/njroad2",]),  
	(["cdizhi":	"����ɽ",
	"weizhi2" :	"/d/kunlun/jiuqulang2",]),  
	(["cdizhi":	"���ݳ�",
	"weizhi2" :	"/d/lanzhou/street1",]),  
	(["cdizhi":	"���շ�",
	"weizhi2" :	"/d/lingjiu/jian",]),  
	(["cdizhi":	"���ݳ�",
	"weizhi2" :	"/d/lingzhou/kongdi",]),  
	(["cdizhi":	"������",
	"weizhi2" :	"/d/luoyang/wanghuating",]),  
	(["cdizhi":	"������",
	"weizhi2" :	"/d/mingjiao/tohsq1",]),  
	(["cdizhi":	"����ɽ",
	"weizhi2" :	"/d/qilian/zhutishan",]),  
	(["cdizhi":	"���ɽ",
	"weizhi2" :	"/d/qingcheng/huyingting",]),  
	(["cdizhi":	"��ɽ",
	"weizhi2" :	"/d/songshan/junjigate",]),  
	(["cdizhi":	"���ݳ�",
	"weizhi2" :	"/d/suzhou/liuyuan",]),  
	(["cdizhi":	"̩ɽ",
	"weizhi2" :	"/d/taishan/tianjie",]),  	 
	(["cdizhi":	"������",
	"weizhi2" :	"/d/tianlongsi/tading",]),  
	(["cdizhi":	"���Ʒ�",
	"weizhi2" :	"/d/tiezhang/guangchang",]),  
	(["cdizhi":	"��ɽ��",
	"weizhi2" :	"/d/village/wexit",]),  
	(["cdizhi":	"��ٹ�",
	"weizhi2" :	"/d/wanjiegu/port2",]),  
	(["cdizhi":	"�嶾��",
	"weizhi2" :	"/d/wudujiao/wdsl2",]),  
	(["cdizhi":	"����ɽ",
	"weizhi2" :	"/d/wuliang/road4",]),  
	(["cdizhi":	"������",
	"weizhi2" :	"/d/wuxi/road15",]),  
	(["cdizhi":	"������",
	"weizhi2" :	"/d/xiangyang/walle3",]),  
	(["cdizhi":	"���޺�",
	"weizhi2" :	"/d/xingxiu/shidao",]),  
	(["cdizhi":	"ѩ��",
	"weizhi2" :	"/d/xuedao/shandong2",]),  
	(["cdizhi":	"������",
	"weizhi2" :	"/d/xueshan/zoulang2",]),  
	(["cdizhi":	"������",
	"weizhi2" :	"/d/yanziwu/qiushuan",]),
	(["cdizhi": "Ȫ��",
	"weizhi2" : "/d/quanzhou/jiangjunfu1",]),
	(["cdizhi": "Į��",
	"weizhi2" : "/d/mobei/caocong1",]),	
});
void init()
{
	object ob, me;
	mapping dizhis;
	int exp, nei, nei1;

	::init();

	ob = this_player();
	me = this_object();
	nei = me->query("neili",1);
	nei1 = ob->query("neili",1);
	

	dizhis = dizhia[random(sizeof(dizhia))];
	exp = ob->query("combat_exp");

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );

	if (interactive(ob)
		&& !environment(ob)->query("no_fight")
//		&& ob->query_condition("guanfu_task")
		&& present("wenshu", ob)
		&& (string)me->query("id") == ob->query_temp("guanfu_target"))
	{
		if (ob->query_temp("mark/gkill1"))
		{
			message_vision( HIR"$n����$NĿ������ע�����Լ�һ������������ͣ���˽Ų���\n"NOR, ob, me);

			switch(random(4))
			{
				case 0:
					message_vision("$n�ٺټ�Ц��������æ��Ц������λ"+RANK_D->query_respect(ob)+ "�ǹٸ��Ĳ�ͷ�ɣ�����Ҷ����������ˣ������ܷ��̧���֣��ұ�����л����ú�����һ�£��Ƿ�Ը�⣿\n",ob,me);
					write (HIY"�����ѡ��ͬ��(yes)���߾ܾ�(no)��\n"NOR);
					ob->set_temp("guanf_huida1", me->query("name"));
					break;
				case 1:
					message_vision( HIR"$n��Цһ��˵��������಻�����ģ�����ʮ����ү��Ҳ���£�\n�漴�۾�һ�ɣ�����$N�ͳ��˹�ȥ��\n"NOR,ob,me);
					me->set_leader(ob);
					remove_call_out("kill_ob");
					call_out("kill_ob", 1, ob);
					ob->delete_temp("mark/gkill1");
					break;
				case 2:
					message_vision( WHT"$n��$N�ߵ���ǰ������һЦ��˵������ǧ��׷������ҿ����������ҺΣ�\n"NOR,ob,me);
					write(WHT"��е�һ�����ε�ɱ�������в���һ����\n"NOR);
					ob->delete_temp("mark/gkill1");
					break;
				case 3:
					message_vision("$n��Ȼ�������棬һ�������������$N˵����С������������С��������ȫ�ǹٸ���\n�ݺ�����˵ز����������������������һ�棬�ҽ���һ���м�������\n",ob,me);
					ob->delete_temp("mark/gkill1");
			}
		}
		if (ob->query_temp("mark/gkill1") &&
		(string)me->query("name") == ob->query_temp("guanfu_huida1"))
		{
			message_vision( HIR"$n����$N�ߵ���ǰ���ݺݵ��������ʶ̧�ٵĶ������Һ�����Ȱû�ã�\n��������㳢����ү��������\n"NOR,ob,me);
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob);
			ob->delete_temp("guanf_huida1");
			ob->delete_temp("mark/gkill1");
			if ((int)exp<3000000) 
			    me->set("combat_exp",exp*3/2);
			else 
			    me->set("combat_exp",exp*2);   
			me->set("jiali",nei1/15);
//			me->set("combat_exp",exp+exp/4);
		}
		if (ob->query_temp("mark/gkill2"))
		{
			switch(random(2))
			{
				case 0:
					message_vision( HIR"$n��ͷ��������������һ��������ͨ����۾�����$N�ͳ��˹�ȥ��\n"NOR, ob,me);
					me->set_leader(ob);
					if ((int)exp<3000000) 
			                   me->set("combat_exp",exp*3/2);
			                else 
			                   me->set("combat_exp",exp*2);   
			                me->set("jiali",nei1/15);
					remove_call_out("kill_ob");
					call_out("kill_ob", 1, ob);
					break;
				case 1:
					message_vision( HIY"$nһ����$N���ٺ�һЦ��ͷҲ���ؼ�������֮�У�����Ĩ�����ˡ�\n"NOR,ob,me); 
					ob->delete_temp("mark/gkill2");
					ob->set_temp("mark/gkill3",1); 
					write(WHT"��"+ob->query_temp("guanfu_targetnm")+"����������"+dizhis["cdizhi"]+"���ķ�����ȥ�ˡ�\n"NOR);
					me->move(dizhis["weizhi2"]);
					return; 
			}	 
		}
		if (ob->query_temp("mark/gkill3"))
		{
			message_vision(HIR "$n�����ܻ��Ķ�$N�µ���ɱ�˲���ͷ��أ���һ�ٿ����ƣ���ү����ͺ���ƴ���������ơ�\n"NOR,ob,me);
			if(nei<nei1&& (!me->query_temp("gf_nlset")))
			{
				me->set("neili",nei1);
				me->set_temp("gf_nlset",1);
			}
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob);
			if ((int)exp<3000000) 
			    me->set("combat_exp",exp*3/2);
			else 
			    me->set("combat_exp",exp*2);   
			me->set("jiali",nei1/15);
			me->reincarnate(); 
		}
	}
	call_out("dest", 2000); 
	add_action("do_yes","yes");
	add_action("do_no","no");
} 

int do_yes()
{
	object r_shen, me, ob;
	me = this_object();
	ob = this_player();

	if (!ob->query_temp("guanf_huida1")) return 0;
	if (ob->query_temp("guanf_huida1") != (string)me->query("name"))
		return 0;
	if ((int)ob->query("shen") < 1 && ob->query("combat_exp",1) < 180000)
	{
		command("say ��λ"+RANK_D->query_respect(ob)+"һ��ǰ;Զ�󣬺ٺ٣����ǲ��������ġ�\n");
		me->add_money("gold",20+random(20));
		command("give "+ob->query("id")+" gold");
		message_vision("$N�ٺ�һЦ��ת���뿪��һգ�۾���ʧ�����ˡ�\n",me);
		destruct(me);
		return 1;
	}
	if ((int)ob->query("shen") < 1 &&
		ob->query("combat_exp",1) > 180000 &&
		ob->query("combat_exp",1) < 500000)
	{
		command("say ����Ϳ�����λ"+RANK_D->query_respect(ob)+"�ǵ����Ŀ��ܣ��ٺ٣����С������������¡�\n");
		message_vision("$N�ٺټ�Ц����������������$nһ���˲Ρ�\n",me,ob);
		r_shen=new("/clone/medicine/vegetable/renshen");
		r_shen->move(ob);
		command("give "+ob->query("id")+" gold");
		message_vision("$N�ٺ�һЦ��ת���뿪��һգ�۾���ʧ�����ˡ�\n",me);
		destruct(me);
		return 1;
	}
	if ((int)ob->query("shen") < 1 && ob->query("combat_exp",1) > 500000)
	{
		command( "say �����˼ҹ�����˳��ڣ�С��ʵ���벻����ʲ��Т�����ϣ���ͷ��������˵�ɡ�\n");
		message_vision("$N�ٺ�һЦ��ת���뿪��һգ�۾���ʧ�����ˡ�\n",me);
		destruct(me);
		return 1;
	}
	if ((int)ob->query("shen") > 1 && ob->query("combat_exp",1) < 120000)
	{
		command("say ��λ"+RANK_D->query_respect(ob)+"ǰ;Զ��һ���������ٺ٣������\n");
		me->add_money("gold",20+random(30));
		command("give "+ob->query("id")+" gold");
		ob->add("shen",-1000);
		message_vision("$N�ٺ�һЦ��ת���뿪��һգ�۾���ʧ�����ˡ�\n",me);
		destruct(me);
		return 1;
	}
	if ((int)ob->query("shen") > 1 &&
		ob->query("combat_exp",1) > 120000 &&
		ob->query("combat_exp",1) < 500000)
	{
		command("say ��λ"+RANK_D->query_respect(ob)+"�����屡���죬���С���ﾴ��������¡�\n");
		me->add_money("gold",30+random(30));
		command("give "+ob->query("id")+" gold");
		message_vision("$N�ٺټ�Ц����������������$nһ���˲Ρ�\n",me,ob);
		r_shen=new("/clone/medicine/vegetable/renshen");
		r_shen->move(ob);
		ob->add("shen",-3000);
		message_vision("$N�ٺ�һЦ��ת���뿪��һգ�۾���ʧ�����ˡ�\n",me);
		destruct(me);
		return 1;
	}
	command("say �Թ�а���Ʋ����������²�������СС��Ц��ǧ��Ҫ���氡��\n");
	command("laugh " + ob->query("id"));
	write("�Է�����������ȡЦ���㲻��ŭ�����ա�\n");
	tell_room(environment(me), me->query("name")+"������������֮�У�ת�۾Ͳ����ˡ�\n", ({me}));	
	destruct(me);
	return 1;
}
   

int do_no()
{
	object me, ob;
	me = this_object();
	ob = this_player();

	if (!ob->query_temp("guanf_huida1")) return 0;
	if (ob->query_temp("guanf_huida1") != (string)me->query("name"))
		return 0;
	if ((int)ob->query("shen") < 1)
	{
		command("say ��λ"+RANK_D->query_respect(ob)+"һ�����������ұ���һ·��ɫ��ȴ������װʲô����Ӣ���أ���\n");
		ob->delete_temp("guanf_huida1");
		ob->delete_temp("mark/gkill1");
		return 1;
	}
	command("say ��λ"+RANK_D->query_respect(ob)+"һ�������������������ɵ��ӣ�������֪����������������\n");
	command("hehe " + ob->query("id"));
	ob->delete_temp("guanf_huida1");
	ob->delete_temp("mark/gkill1");
	return 1;
}

void die()
{
	object ob, me;
	mapping dizhis;
	
	ob = this_object();
	me = query_temp("last_damage_from");
	dizhis = dizhia[random(sizeof(dizhia))];  
	
	if (!me->query_temp("mark/gkill3") &&
		!me->query_temp("mark/gkill2") &&
		(string)ob->query("id") == me->query_temp("guanfu_target"))
	{
		message_vision(WHT"$N������������Ц���������֣�˵��ǿ����ʹ������"+dizhis["cdizhi"]+"�������ߡ�\n"NOR,ob,me);
		me->set_temp("mark/gkill2",1);
//		message_vision(WHT"��"+ob->query_temp("guanfu_targetnm")+"����������"+dizhis["cdizhi"]+"���ķ�����ȥ�ˡ�\n"NOR);
		new(me->query_temp("path_rooms"))->move(dizhis["weizhi2"]);
		destruct(ob);
		return;
	}
	if (me->query_temp("mark/gkill2") &&
		(string)ob->query("id") == me->query_temp("guanfu_target"))
	{
		message_vision(WHT"$N��Цһ����˵�����ÿ��Ĺ���˵��������"+dizhis["cdizhi"]+"�������ߡ�\n"NOR,ob,me);
		me->delete_temp("mark/gkill2");
		me->set_temp("mark/gkill3",1);
//		message_vision(WHT"��"+ob->query_temp("guanfu_targetnm")+"����������"+dizhis["cdizhi"]+"���ķ�����ȥ�ˡ�\n"NOR);
		new(me->query_temp("path_rooms"))->move(dizhis["weizhi2"]);
		destruct(ob);
		return;
	}
	::die();
}
int accept_fight(object me)
{
	command("say ��ү����Ҫ��·��û��˼���㶯�֡�");
	return 0;
}
void dest()
{
	object ob;
	ob = this_object();
	if (environment())
	message_vision("ֻ��$N��Ȼ��ת���У�������������У�ת�۾��ټ����ޡ�\n", ob);  
	destruct(this_object());
}