//Room: /d/dali/dalinorth.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�����Ǳ�");
	set("long",@LONG
�����Ǹ���·�ڡ��ϱ߾��Ǵ����ǵı����ˣ���·������ֲ���
��ȥ�ɵ�̫�ͳǣ�����ͨ���¹سǣ�Ҳͨ��ɽ����ȥ�β�ɽ�ͳ�ʥ��
�ıؾ�֮·��
LONG);
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"taihecheng",
	    "south"      : __DIR__"northgate",
	    "northwest"  : __DIR__"ershuiqiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40000);
	set("coor/y", -60000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}