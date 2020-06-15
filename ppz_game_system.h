#pragma once /* 헤더파일의 중복 포함을 막기 위한 전처리기. visual studio에서 지원한다.
#ifndef ABCD_H
#define ABCD_H
~헤더파일 내용~
#endif
를 사용하는 방법도 있다. 이쪽이 좀더 범용적이다.*/

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

	//오늘게임에서 실수한 점 bool로 체크해서 panelty 먹일예정.

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
	static void end_normal(); //게임을 클리어 한 경우
	static void show_last_result(Game_system *gs);
};