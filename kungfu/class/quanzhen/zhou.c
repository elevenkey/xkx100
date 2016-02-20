// zhou.c �ܲ�ͨ

#include <ansi.h>

inherit NPC;
//inherit F_SKILL;
int jie_bai();

void create()
{
        set_name("�ܲ�ͨ", ({ "zhou botong", "zhou", "botong" }));
        set("gender", "����");
        set("nickname", CYN "����ͯ" NOR ) ;
        set("title", "ȫ��̵�һ������") ;
        set("age", 45);
        set("long",
        "�������˳ơ�����ͯ�����ܲ�ͨ��\n"
        "��������ȫ��������˵�ʦ�ܣ��书��ǿ��������ȴ����������\n"
        "��ССɽ��֮�У�ͷ�����ӳ����ģ�ë���׵���һ��Ұ�ˡ�\n",
        );

        set("combat_exp", 2000000);
        set("shen_type", 1);

        set("max_neili", 5000);
        set("neili", 5000);
        set("jiali", 0);
        set("no_get",1);

        set_skill("force", 180);
        set_skill("xiantian-qigong", 180);    //��������
        set_skill("sword", 180);
        set_skill("quanzhen-jian", 250);  //ȫ�潣
        set_skill("dodge", 180);
        set_skill("jinyan-gong", 250);   //���㹦
        set_skill("strike", 180);
        set_skill("haotian-zhang", 250);    //�����
        set_skill("cuff", 180);
        set_skill("chunyang-quan", 250);    //����ȭ
        set_skill("unarmed", 200);
        set_skill("kongming-quan", 200);     //����Ȫ
        set_skill("hubo", 100);
        set_skill("parry", 180);
        set_skill("literate", 80);
        set_skill("taoism", 100);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        map_skill("unarmed","kongming-quan");
        map_skill("cuff", "chunyang-quan");
        prepare_skill("cuff", "chunyang-quan");
        prepare_skill("strike", "haotian-zhang");

        set("inquiry", ([
                "�����澭" : "�������澭�������Ҵ��ϣ����б���ɱ���һ���ұƳ�ɽ���Ϳ���ȡ�ߣ�\n",
                "��ҩʦ"   : "��������ʮ���꣬������ұƳ�ɽ����ȡ�������澭����\n����ÿ��������ɨ�˶��飡\n",
                "����"     : "�ҡ��ҡ����Ҳ���ʶ����",
                "��"       : "��Ҫ���ң����������ˣ�\n",
                "���"     :  (: jie_bai :),
                "�ݰ��ֵ�" :  (: jie_bai :),
        ]) );

        create_family("ȫ���", 1, "����");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

int jie_bai()
{
        object ob ;
        ob = this_player ( ) ;
        if ((string)ob->query("gender") != "����")
        {
                message_vision("\n����ͯ�������´�����$Nһ����˵��������ƽ��ϲͬ������\n"
                "�򽻵���һ��Ů�ˣ�����̫�ࡣ�ҿ��㻹�ǳ�����գ���\n", ob);
                return 1;
        }

        if ((int)ob->query("shen") < -1000)
        {
                say("����ͯ����һ��˵����ƾ�����ֶ���Ҳ�����ҳ��ֵ��ܣ���\n");
                return 1;
        }

        say("����ͯ���˵�˵���ã��Ժ����Ǿ��Ǻ��ֵ��ˣ�\n");
        tell_object(ob,GRN "�ܲ�ͨ���Ķ���˵���ϸ����һ�ס�˫�ֻ���֮������һ·\n"
        "������ȭ�����Դ�������Ϊ������Ӵ��\n" NOR );

        this_player()->set_temp("wantong/�ֵ�", 1);
        return 1;
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("wantong/�ֵ�"))
                return 0;
        return 1;
}

int accept_object(object who, object ob)
{
        if (ob->query("id") == "du she")
        {
                message_vision("$N�ó�һ������������ͯ����ǰ���˻Σ�����������\n"
                "����ͯ�ŵ�����������������⣡���ܱߺ������͸�ˣ�����ͯ�ⷬ�����ˣ�\n\n\n"
                "��������Զȥ�����ڲ������š�\n" ,who);
                destruct(this_object());
                return 0;
        }
        return 0;
}