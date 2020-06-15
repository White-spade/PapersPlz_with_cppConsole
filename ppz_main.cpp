#include <string>
#include "ppz_game_system.h"
#include "ppz_tage_N_characters.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


int main(void)
{
	Game_system* GS = new Game_system();
	while (true)
	{
		Stage_base* Stg = NULL;
		Game_stories::game_intro(GS->getstage());

		if (GS->getstage() == 1)
			Stg = new Stage_1();
		else if (GS->getstage() == 2)
			Stg = new Stage_2();
		else if (GS->getstage() == 3)
			Stg = new Stage_3;
		else if (GS->getstage() == 4)
			Stg = new Stage_4;
		else if (GS->getstage() == 5)
			Stg = new Stage_5;
		else if (GS->getstage() == 6)
			Stg = new Stage_6;
		else if (GS->getstage() == 7)
			Stg = new Stage_7;
		else if (GS->getstage() == 8)
			Stg = new Stage_8;
		else
		{
			cout << "Stage create Error detected" << endl;
			return 0;
		}

		Game_stories::start_stage();

		//스테이지 들어가는 자리
		int flag=0; //상황판단, 명령 입력 변수
		clock_t start = clock();


		//한스테이지에 6명 출현
		for (int i = 0; i < 6; i++)
		{//한스테이지에 9명 중 6명 등장, 이벤트 캐릭터와 듀토리얼(1스테이지)캐릭터는 항상등장
			clock_t end = clock();
			if (((end - start) / CLOCKS_PER_SEC) > 60 * 1) //시간체크
				break;
			cout << "==============================================================" << endl;
			Stg->Play_stage(GS,flag,i);
		}
		delete Stg;
		
		//stage 끝나고 관리.
		Game_stories::game_outro(GS->getstage());
		GS->stage_end();

		//엔딩들 관리.
		Game_endings::endings(GS);
		if (GS->check_game_over())
			break;
		if (GS->nextstage() > 8)//여기서 스테이지 증가
		{
			Game_endings::end_normal();
			break;
		}
	}
	Game_endings::show_last_result(GS);

	delete GS;
	
	return 0;
}