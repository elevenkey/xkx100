// Room: /d/songshan/westpath3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "西廊");
	set("long", @LONG
这里是环绕池塘的走廊，画阑雕栋，却也美仑美奂。一路走来，脚
底木板响动，别有韵味。嵩岳独立天心，八方天风，只吹得天边云起云
落，满山树浪起伏。
LONG );
	set("outdoors", "songshan");
	set("exits", ([
		"west" : __DIR__"westwuchang",
		"east" : __DIR__"huayuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 920);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
