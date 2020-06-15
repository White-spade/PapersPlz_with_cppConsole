#pragma once /* ��������� �ߺ� ������ ���� ���� ��ó����. visual studio���� �����Ѵ�.
#ifndef ABCD_H
#define ABCD_H
~������� ����~
#endif
�� ����ϴ� ����� �ִ�. ������ ���� �������̴�.*/

class Game_system
{
	bool game_over;
	int family_count;
	int mistake;
	int today_mistake;
	int money;
	int stage;
	int success;
	int total_success;

	int total_allow_pass;
	int total_deny_pass;
	int detain_pass;
	int total_detain_pass;


	bool house_is_cold;
	bool family_cold;
	bool family_critical;

	bool pay_foodCost;
	bool pay_heatingCost;

	//���ð��ӿ��� �Ǽ��� �� bool�� üũ�ؼ� panelty ���Ͽ���.

public:
	Game_system();
	int nextstage();
	int getstage();
	bool check_game_over();
	void add_success();
	void new_mistake();
	void add_total_allow();
	void add_total_deny();
	void add_detain();

	void stage_end();


	friend class Game_endings;
};
class Game_events
{
public:
	static bool chara_first_talk;
	static bool request_of_friend;
	static bool first_spy_mission;
	static bool first_spy_mission_clear;
	static bool murder_pass_event;
	static bool diploma_spy_mission_clear;
	static bool last_spy_mission_clear;
};

class Game_stories
{
public:
	static void game_intro(int n);
	static void game_outro(int n);
	static void start_stage();
};

class Game_endings
{
public:
	static void endings(Game_system *gs);
	static void end_normal(); //������ Ŭ���� �� ���
	static void show_last_result(Game_system *gs);
};