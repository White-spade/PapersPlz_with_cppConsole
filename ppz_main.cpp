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

		//�������� ���� �ڸ�
		int flag=0; //��Ȳ�Ǵ�, ��� �Է� ����
		clock_t start = clock();


		//�ѽ��������� 6�� ����
		for (int i = 0; i < 6; i++)
		{//�ѽ��������� 9�� �� 6�� ����, �̺�Ʈ ĳ���Ϳ� ���丮��(1��������)ĳ���ʹ� �׻����
			clock_t end = clock();
			if (((end - start) / CLOCKS_PER_SEC) > 60 * 1) //�ð�üũ
				break;
			cout << "==============================================================" << endl;
			Stg->Play_stage(GS,flag,i);
		}
		delete Stg;
		
		//stage ������ ����.
		Game_stories::game_outro(GS->getstage());
		GS->stage_end();

		//������ ����.
		Game_endings::endings(GS);
		if (GS->check_game_over())
			break;
		if (GS->nextstage() > 8)//���⼭ �������� ����
		{
			Game_endings::end_normal();
			break;
		}
	}
	Game_endings::show_last_result(GS);

	delete GS;
	
	return 0;
}