// Room: /d/shaolin/hantan3.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ź�̶");
	set("long", @LONG
���Ǻ�̶֮�С�����ˮ�����һ��ʹ����̶ˮ�ڴ˴����
��ϡ��һ�������ܵı���������һ����飬����˫������͸����
�������⣬ȫ���������Ѷ������ã�ֻ������ˮ�������������
��ȥ��
LONG );
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 830);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}