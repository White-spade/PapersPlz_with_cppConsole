#include "ppz_game_system.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
using namespace std;
using std::cout;

//define Game system
Game_system::Game_system()
{
	game_over = false;
	family_count = 4;
	mistake = 0;
	today_mistake = 0;
	money = 300;
	stage = 1;
	success = 0;
	total_success = 0;

	total_allow_pass = 0;
	total_deny_pass = 0;

	detain_pass = 0;
	total_detain_pass = 0;

	house_is_cold = false;
	family_cold = false;
	family_critical = false;
	pay_foodCost = false;
}

int Game_system::nextstage()
{
	stage ++;
	return stage;
}
int Game_system::getstage()
{
	return stage;
}
bool Game_system::check_game_over()
{
	return game_over;
}
void Game_system::add_success()
{
	success++;
}
void Game_system::new_mistake()
{
	cout << "======= ���� ������ ������ =======" << endl;
	if (mistake == 0)
		cout << "�����߱� - ���� ������" << endl;
	else if (mistake == 1)
		cout << "�������� ��� - ���ݾ�����" << endl;
	else
		cout << "�����ݺΰ� ������" << endl;

	mistake++;
	if (mistake >= 3)
		today_mistake++;
}
void Game_system::add_total_allow()
{
	total_allow_pass++;
}
void Game_system::add_total_deny()
{
	total_deny_pass++;
}
void Game_system::add_detain()
{
	detain_pass++;
}

void Game_system::stage_end()
{
	//result ���
	char flag;
	cout << "\n\n---------------------" << stage << "�� ��" << "----------------------" << endl;
	cout << "����� :" << money << endl;
	cout << "���� : 100 x " << success << "(���� ó�� ����) = " << success * 100 << endl; money += (success * 100);
	if (stage < 6)
	{
		cout << "���� : -200" << endl;
		money -= 200;
	}
	else
	{
		cout << "���� : -300 (100�̳� �����ٴ�...)" << endl;
		money -= 300;
	}
	if (Game_events::request_of_friend)
	{
		Game_events::request_of_friend = false;
		cout << "ģ���� ��� :100" << endl;
		money += 100;
	}
	if (mistake >= 3 && today_mistake >0)
	{
		if (mistake >= 5)
		{
			cout << "������ ���� ���� ���� : -100x" << today_mistake << " = " << -100 * today_mistake << endl;
			money -= (100 * today_mistake);
		}
		else
		{
			cout << "���� ���� ���� : -50x" << today_mistake << " = " << -50 * today_mistake << endl;
			money -= (50 * today_mistake);
		}
	}
	if (stage >= 6)
	{
		cout << "ü������ : 50x" << detain_pass << "(������ ��� ��) = " << 50 * detain_pass << endl;
		money += 50 * detain_pass;
	}
	cout << "-------------------------------------------------" << endl;
	cout << "���� ���� �ݾ� : " << money << "\n" << endl;
	cout << "\ny�� �Է��� ����� ������ �� �ֽ��״�. \n������ �Һ�� ������ �����Ͻö��." << endl;

	if (house_is_cold)
		cout << "\n���� ����ϴ�. \n����� ���� ������ ������ ���� �ɸ� �� �ֽ��ϴ�." << endl;

	if (family_critical)
	{
		cout << "\n���� �ɷȴ� ������ �����մϴ�. \nġ���� 100���Դϴٸ�, ġ������ ������ �Ƹ� ����� ���Գ״�." << endl;
		cout << "ġ���Ͻðڽ��ױ�? y/n" << endl;
		while (true)
		{
			cin >> flag;
			if (cin.fail())
			{
				cout << "�߸��� �Է��Գ״�." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				continue;
			}
			if (flag == 'y')
			{
				cout << "ġ�Ḧ �����߽��״�. \n������ �̷��� �������� ���� �����״�." << endl;
				money -= 100;
				family_critical = false;
				break;
			}
			else if (flag == 'n')
			{
				cout << "��¿ �� ���� �����̾����״�." << endl;
				cout << "���� �Ѹ��� ���� �������ϴ�." << endl;
				family_count--;
				family_critical = false;
				break;
			}
			else
			{
				cout << "�߸��� �Է��Գ״�." << endl;
			}
		}
		cout << "-------------------------------------------------" << endl;
		cout << "���� ���� �ݾ� : " << money << "\n" << endl;
	}

	if (family_cold)
	{
		cout << "\n������ �Ѹ��� ���⿡ �ɷȽ��ϴ�. ������� 50���Գ״�." << endl;
		cout << "ġ���Ͻðڽ��ױ�? y/n" << endl;
		while (true)
		{
			cin >> flag;
			if (flag == 'y')
			{
				cout << "�������� ���� �����߽��״�. \n�� �ǰ��� �� ���Գ״�." << endl;
				family_cold = false;
				break;
			}
			else if (flag == 'n')
			{
				cout << "��¿ ������ �����̾����״�." << endl;
				family_cold = false;
				family_critical = true;
				break;
			}
			else
			{
				cout << "�߸��� �Է��Գ״�." << endl;
			}
		}
		cout << "-------------------------------------------------" << endl;
		cout << "���� ���� �ݾ� : " << money << endl;
	}

	cout << "\n�ĺ� : -50 x " << family_count << "(���� ��) = " << family_count * -50 << endl;
	cout << "�ĺ� �������� ������ ������ ����� �� �ֽ��ϴ�. \n�����Ͻðڽ��ϱ�? y/n" << endl;
	while (true)
	{
		cin >> flag;
		if (cin.fail())
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 'y')
		{
			cout << "�ĺ� �����߽��״�. \n����� ������ ���ָ��� ���� ���Գ״�." << endl;
			money -= (50 * family_count);
			break;
		}
		else if (flag == 'n')
		{
			cout << "�ĺ� �������� �ʱ�� �߽��״�." << endl;
			cout << "���� �Ѹ��� ���� �������ϴ�." << endl;
			family_count--;
			break;
		}
		else
		{
			cout << "�߸��� �Է��Գ״�." << endl;
		}
	}
	cout << "-------------------------------------------------" << endl;
	cout << "���� ���� �ݾ� : " << money << "\n" << endl;

	cout << "\n����� : -100" << endl;
	cout << "����� �������� ������ ������ ���⿡ �ɸ� �� �ֽ��ϴ�. \n�����Ͻðڽ��ϱ�? y/n" << endl;
	while (true)
	{
		cin >> flag;
		if (cin.fail())
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 'y')
		{
			cout << "����� �����߽��״�. \n����� ������ �����ϰ� ���� ���Գ״�." << endl;
			house_is_cold = false;
			money -= 100;
			break;
		}
		else if (flag == 'n')
		{
			cout << "����� �������� �ʱ�� �߽��״�." << endl;
			if (house_is_cold)
			{
				family_cold = true;
			}
			else
				house_is_cold = true;
			break;
		}
		else
		{
			cout << "�߸��� �Է��Գ״�." << endl;
		}
	}
	cout << "-------------------------------------------------" << endl;
	cout << "���� ���� �ݾ� : " << money << "\n" << endl;

	Sleep(1000);
	cout << "\n\n�������� ��ҽ��ϴ� \n\n" << endl;
	Sleep(1000);
	total_success += success;
	success = 0;
	total_detain_pass += detain_pass;
	detain_pass = 0;
	today_mistake = 0;
}


//define Game events
bool Game_events::chara_first_talk = true;
bool Game_events::request_of_friend = false;
bool Game_events::first_spy_mission = false;
bool Game_events::first_spy_mission_clear = false;
bool Game_events::murder_pass_event = false;
//�κμմ� ���� x���� �Ƴ� ����
bool Game_events::diploma_spy_mission_clear = true;
bool Game_events::last_spy_mission_clear = true;


//define Game stories����
void Game_stories::game_intro(int n)
{
	if (n == 1)
	{
		cout << "�����ճ״�." << endl;
		Sleep(2000);
		cout << "11�� �ε� ���ǿ��� ������ �̸��� �������״�.\n" << endl;
		Sleep(2000);
		cout << "���� �˿����� �׷���ƾ ���� �˹��ҿ� �ﰢ �ο� ��ġ�� �ʿ����� ����޾ҽ��״�.\n" << endl;
		Sleep(2000);
		cout << "������ �������� ���� ���ܼ� ��ó�� �츲���� ���޵Ǿ����״�." << endl;
		cout << "8��� �������� �Գ״�." << endl;
		cout << "�ε��� ���� ������ �̹����ϱ⸦ �ٶ��״�.\n" << endl;
		Sleep(4000);
		cout << "������ ����, �ƽ��丣��ī�� ������!\n" << endl;
		Sleep(2500);

		cout << "==========================�ε� �Ź�==========================" << endl;
		cout << "|\n|1982�� 11�� 23��\n|" << endl;
		cout << "|���׷���ƾ�� ���� �˹��� ��ħ�� ����Ǵ�!��" << endl;
		cout << "|-6�⸸�� ����� ����, ������ ������ �� �ִ°�?-" << endl;
		cout << "|......" << endl;
		cout << "|        ���������� �ٽ� �����١�......" << endl;
		cout << "|......" << endl;
		cout << "|���ɰ��� �����.. ������ �ε��� ���� �ε� ���� ����. ��" << endl;
		cout << "|......" << endl;
		cout << "=============================================================\n\n\n" << endl;

		Sleep(5000);

		cout << "=============================================================" << endl;
		cout << "�ƽ��丣��ī 1982.11.23" << endl;
		cout << "���� �˿��� ���� ����\n" << endl;
		cout << "�˹���, ���� ���ܼ��� �� ��å�� �ð� �� ���� ȯ���ճ״�." << endl;
		cout << "���ǰ� �������� Ȯ���ϰ� ���� �㰡�� �����ִ°��� ����� �� �����Գ״�.\n" << endl;
		cout << "���� �㰡�� �ƽ��丣��ī�� �ιε�� ���ѵ˳״�." << endl;
		cout << "���� ��� �ܱ��ε鿡 ���ؼ��� ������ �����ճ״�.\n" << endl;
		cout << "������ ����, �ƽ��丣��ī�� ������!\n" << endl;
		cout << "-�ƽ��丣��ī ��ġ��-" << endl;
		cout << "=============================================================" << endl;
	}
	else if (n == 2)
	{
		cout << "==========================�ε� �Ź�==========================" << endl;
		cout << "|\n|1982�� 11�� 24��\n|" << endl;
		cout << "|���������̾��� ���� �˹���!��" << endl;
		cout << "|-���� ������ ��ȭ�ϰ�, �ܱ����� �޾Ƶ��δ�-" << endl;
		cout << "|......" << endl;
		cout << "|���������� �м�. ��" << endl;
		cout << "|-������ ������ �����ɰŶ� ������-" << endl;
		cout << "|        ��������......" << endl;
		cout << "|......" << endl;
		cout << "|......" << endl;
		cout << "=============================================================\n\n\n" << endl;

		Sleep(5000);

		cout << "=============================================================" << endl;
		cout << "�ƽ��丣��ī 1982.11.24" << endl;
		cout << "���� �˿��� ���� ����\n" << endl;
		cout << "�˹���, ���ú��� ��ȿ�� ������ ������ �� �ܱ��ε��� ������ �㰡�˳״�.\n" << endl;
		cout << "������ ��� ������ ���Ǳ�� ���� �߸��� ���� ������ Ȯ���Ͻÿ�" << endl;
		cout << "��ġ���� �ʴ� ������ ����� �����ڵ��� ��� �����Ͻÿ�\n" << endl;
		cout << "�ǽɽ����� �ڵ��� ������ ���� �ɷ����ÿ�" << endl;
		cout << "���� �˿����� ������ ������ �򰥸��ٸ� �������� ������ ���캸�ÿ�" << endl;
		cout << "\n������ ����, �ƽ��丣��ī�� ������!\n" << endl;
		cout << "-�ƽ��丣��ī ��ġ��-" << endl;
		cout << "=============================================================" << endl;
	}
	else if (n == 3)
	{
		cout << "==========================�ε� �Ź�==========================" << endl;
		cout << "|\n|1982�� 11�� 25��\n|" << endl;
		cout << "|���ݷ�ġ�� ��� �ݵ������� ����!��" << endl;
		cout << "|-�׷���ƾ ���濡�� Ȱ���ϴ� �ݷ�ġ�� ��� ������, ��������.-" << endl;
		cout << "|......" << endl;
		cout << "|���˹��� ���� ��" << endl;
		cout << "|-������ ����, ������� �Ա��ɻ�-" << endl;
		cout << "|        ��������......" << endl;
		cout << "|......" << endl;
		cout << "|......" << endl;
		cout << "=============================================================\n\n\n" << endl;

		Sleep(10000);

		cout << "=============================================================" << endl;
		cout << "�ƽ��丣��ī 1982.11.25" << endl;
		cout << "���� �˿��� ���� ����\n" << endl;
		cout << "�˹���, ���� ��� ������ �����˳״�.\n" << endl;
		cout << "��� �ιε��� ��ȿ�� ���� ǥ�� �ʿ��ճ״�." << endl;
		cout << "���� ǥ�� ���ٸ� �ܱ��� �ڱ��� ���, �Ա��� �����Ͻÿ�\n" << endl;
		cout << "\n������ ����, �ƽ��丣��ī�� ������!\n" << endl;
		cout << "-�ƽ��丣��ī ��ġ��-" << endl;
		cout << "=============================================================\n\n\n" << endl;

		Sleep(10000);
		cout << "=============================================================" << endl;
		cout << "ģ���ϴ� ������, ������ �׷���ƾ �˹��ҿ��� �ε��Ѵٴ� �ҽ��� ���" << endl;
		cout << "�� �������� �������� �̷��� ���� ������ ������" << endl;
		cout << "�ݵ������� �������� ���� ������ ��������ٴ� �ҽ��� �����," << endl;
		cout << "������ ������ �� �ʳⰣ ������� ���� �ƹ����� ���ƿ��� ���ϼ�." << endl;
		cout << "'�� ����' ��� ������ �Ż簡 ���������� ���´ٸ�, �ε�, ��������ְ�" << endl;
		cout << "�� ������ ��� ���� �ʰڳ�. \n-����� ���� �����κ���" << endl;
		cout << "=============================================================" << endl;

	}
	else if (n == 4)
	{
	cout << "==========================�ε� �Ź�==========================" << endl;
	cout << "|\n|1982�� 11�� 26��\n|" << endl;
	cout << "|�����ܼ� Ȯ���� ���⡹" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
	cout << "|���Ͻ��� �Ը� ������ ��" << endl;
	cout << "|-���� ������ ���ΰ�, ���ΰ�-" << endl;
	cout << "|        ��� ��⡹......" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
	cout << "=============================================================\n\n\n" << endl;

	Sleep(5000);

	cout << "=============================================================" << endl;
	cout << "�ƽ��丣��ī 1982.11.26" << endl;
	cout << "���� �˿��� ���� ����\n" << endl;
	cout << "�˹���, ������ �ڰ� ����� �����Ǿ����״�.\n" << endl;
	cout << "��� �ڱ� �ιε��� �ݵ�� �ź����� ������ �ճ״�." << endl;
	cout << "�ܱ��ε��� �����ϰ� ��ȿ�� ���� �㰡���� ������ �־�� �ճ״�.\n" << endl;
	cout << "������ ����ǥ�� ���̻� ������� �ʽ��ϴ�.\n" << endl;
	cout << "\n������ ����, �ƽ��丣��ī�� ������!\n" << endl;
	cout << "-�ƽ��丣��ī ��ġ��-" << endl;
	cout << "=============================================================\n\n\n" << endl;
		if (Game_events::request_of_friend)
		{
			Sleep(5000);
			cout << "=============================================================" << endl;
			cout << "ģ���ϴ� ������, �� �� ������ ��� ǥ���ؾ� �� �� �𸣰ڳ�." << endl;
			cout << "�ƹ����� �˹��� �ѹ� �� ���ϼ�����" << endl;
			cout << "������ ���� ���� ���� ���ƿ��̳�" << endl;
			cout << "���� �ʾ� �� �� �Ѻ� ���� ���� ����" << endl;
			cout << "�� �̰����� �� ������ �� ���� ���� ��������,���� ���� �����ϼ�" << endl;
			cout << "�� ������ ��� ���� �ʰڳ�. \n-����� ���� �����κ���" << endl;
			cout << "(���� �ӿ� �ణ�� ���� ����ִ�.)" << endl;
			cout << "=============================================================" << endl;
		}
	}
	else if (n == 5)
	{
	cout << "==========================�ε� �Ź�==========================" << endl;
	cout << "|\n|1982�� 11�� 27��\n|" << endl;
	cout << "|�����ۺ��� ���� ���󼱼��� �����˷� ����!��" << endl;
	cout << "|-�� �𽬿��� ��� ����, ���ۺ��ƿ��� ����ģ ������ ����-" << endl;
	cout << "|.....�� �𽬿��� �ι� ����..." << endl;
	cout << "|....������ ���̰� ����ģ���� �����߳�?-" << endl;
	cout << "|......" << endl;
	cout << "|�������, ���ڸ� ���� �پ��" << endl;
	cout << "|-�̹ι���, ���ڸ� ��Ż�� �ɰ���...-" << endl;
	cout << "|        ����ġ��......" << endl;
	cout << "|......" << endl;
	cout << "=============================================================\n\n\n" << endl;

	Sleep(5000);

	cout << "=============================================================" << endl;
	cout << "�ƽ��丣��ī 1982.11.27" << endl;
	cout << "���� �˿��� ���� ����\n" << endl;
	cout << "�˹���, �ε������� ���� �ε��� �����ϱ�����," << endl;
	cout << "Ư�� ���α׷��� �����߽��״�.\n" << endl;
	cout << "�ε��� ���� �����ϰ��� �ϴ� �����ڴ�" << endl;
	cout << "��ȿ�� �ε� �㰡���� �ʿ��ճ״�.\n" << endl;
	cout << "\n������ ����, �ƽ��丣��ī�� ������!\n" << endl;
	cout << "-�ƽ��丣��ī ��ġ��-" << endl;
	cout << "=============================================================\n\n\n" << endl;
	}
	else if (n == 6)
	{
	cout << "==========================�ε� �Ź�==========================" << endl;
	cout << "|\n|1982�� 11�� 28��\n|" << endl;
	cout << "|������ ���ܼ�. �� �ٽ� ���ݹ޴�!��" << endl;
	cout << "|-����� ���� ƴ���� �ݵ����ڰ� ������...-" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
		if(Game_events::murder_pass_event)
		{
			cout << "|���� �𽬿�, �׷���ƾ���� ü���Ǵ١�" << endl;
			cout << "|-���� �������� ����� �����ڷ�-" << endl;
		}
		else
		{
			cout << "|���� �𽬿� : �ƽ�����ī, �ݷ�ġ�� ���濡�� ��ݡ�" << endl;
			cout << "|-���� ������ ������-" << endl;
		}
		cout << "|        ����ġ��......" << endl;
		cout << "|......" << endl;
		cout << "|......" << endl;
		cout << "=============================================================\n\n\n" << endl;

	Sleep(5000);

	cout << "=============================================================" << endl;
	cout << "�ƽ��丣��ī 1982.11.28" << endl;
	cout << "���� �˿��� ���� ����\n" << endl;
	cout << "�˹���,���������� ��ſ��� Ư���� ������ �ֱ�� �߽��״�.\n" << endl;
	cout << "������ �ǽɽ����� ����� ���ݽ�ų ������ ������״�." << endl;
	cout << "���� �˿����� �ö� ������ �α�� �߽��״�.\n" << endl;
	cout << "���� ���� �ö����� �湮�� �����̴� ��ٸ��ÿ�.\n" << endl;
	cout << "\n������ ����, �ƽ��丣��ī�� ������!\n" << endl;
	cout << "-�ƽ��丣��ī ��ġ��-" << endl;
	cout << "=============================================================\n\n\n" << endl;
	Sleep(5000);

	cout << "??? : �ȳ��ϽŰ�." << endl;
	Sleep(1500);
	cout << "��� : ���� �̹��� ���� �� �ö������� ����̶��." << endl;
	Sleep(1500);
	cout << "��� : �븥���� ���� �������� �߷ɹ��� �� �˾Ҵµ�, �ܿ� ����α�." << endl;
	Sleep(1500);
	cout << "��� : ��� �����̾� ���� ��ġ�ݳ�." << endl;
	Sleep(1500);
	cout << "��� : �� �׷��� �ƴ϶��, �����״� ü�� �����̶�� �� �������ŵ�" << endl;
	Sleep(1500);
	cout << "��� : �� ���� ����� ü���Ҽ��� �ָӴϰ� �ε�������." << endl;
	Sleep(1500);
	cout << "��� : �㳪 �Ұ������ݳ�? ��, �������Ե� ������ �ְڳ�." << endl;
	Sleep(1500);
	cout << "��� : �������� ������ �δ� �ټ� �� �� ġ���� �ϰڳ�." << endl;
	Sleep(1500);
	cout << "��� : �Ͼ��� �������ݳ�. �����Ҹ��� �˾Ƶ�������� �ϳ�, ����" << endl;
	Sleep(1500);
	cout << "��� : ......." << endl;
	Sleep(1500);
	cout << "��� : ���� �� �� �������, �׷� �̸�." << endl;
	}
	else if (n == 7)
	{
	cout << "==========================�ε� �Ź�==========================" << endl;
	cout << "|\n|1982�� 11�� 29��\n|" << endl;
	cout << "|������ �ɵ��ڰ� �Ҹ��� ǥ�ϴ١�" << endl;
	cout << "|-���� �ƽ�Ʈ����ī���� ������ ȸ�� ����-" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
	cout << "|���ƽ�Ʈ����ī�� ���� ��ȭ��" << endl;
	cout << "|-��ȭ�Ǵ� ����, �ذ�å�� �ִ°�?-" << endl;
	cout << "|        ����ġ��......" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
	cout << "=============================================================\n\n\n" << endl;

	Sleep(5000);

	cout << "=============================================================" << endl;
	cout << "�ƽ��丣��ī 1982.11.29" << endl;
	cout << "���� �˿��� ���� ����\n" << endl;
	cout << "�˹���," << endl;
	cout << "���� �ܱ������� ������ ȸ���� ���� ������ �����Գ״�." << endl;
	cout << "�ܱ������� ������ �־� ���ǰ� ��ȿ�� �ܱ��� ���Ѽ��� ������ �˳״�." << endl;
	cout << "�������� ���ŵ� ���� ������ Ȯ���� ���ö��." << endl;
	cout << "\n������ ����, �ƽ��丣��ī�� ������!\n" << endl;
	cout << "-�ƽ��丣��ī ��ġ��-" << endl;
	cout << "=============================================================\n\n\n" << endl;
	}
	else if (n == 8)
	{
	cout << "==========================�ε� �Ź�==========================" << endl;
	cout << "|\n|1982�� 11�� 30��\n|" << endl;
	cout << "|���ݷ�ġ�� �� ���� �ܱ����� ��ø���� ������!!��" << endl;
	cout << "|-���濡������ ��� ����, ������� ����-" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
	cout << "|��������" << endl;
	cout << "|......" << endl;
	cout << "|        ����ġ��......" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
	cout << "=============================================================\n\n\n" << endl;

	Sleep(5000);

	cout << "=============================================================" << endl;
	cout << "�ƽ��丣��ī 1982.11.30" << endl;
	cout << "���� �˿��� ���� ����\n" << endl;
	cout << "�˹���," << endl;
	cout << "���� �ʾ� �׷���ƾ ���Ա� �㰡 �μ����� �湮�� �����Գ״�." << endl;
	cout << "�Ǽ� ���� �ּ��� ���ϵ��� �Ͻÿ�" << endl;
	cout << "\n������ ����, �ƽ��丣��ī�� ������!\n" << endl;
	cout << "-�ƽ��丣��ī ��ġ��-" << endl;
	cout << "=============================================================\n\n\n" << endl;
	}
	else
	{
		cout << "stage flag error detected _in_game_intro" << endl;
		return;
	}
}

void Game_stories::game_outro(int n)
{
	if (n == 2 || n == 5 )
	{
		cout << "\n-��-!\n" << endl;
		cout << "���濡 ������ ��ź�� �������ϴ�." << endl;
		cout << "���� �� ���� ����ϰ� �˹� ���� ���� ������� ��� ���������ϴ�." << endl;
		cout << "�ݵ������� �������� �˹��� ���� ������ �߽��ϴ�." << endl;
		Sleep(5000);
	}
	else if (n == 6)
	{
		cout << "����� ���ƿ��� �濡 ���� ����ִ� �ǹ��� �Ӵ�ᰡ �ö��ٴ� �ҽ��� ������ϴ�.";
	}
	cout << "\n������ ������ ����Ǿ����ϴ�." << endl;
	Sleep(3000);
}

void Game_stories::start_stage()
{
	cout << "\n\n������ ������ �غ� �Ǿ��ٸ� y�� �Է����ּ���" << endl;
	cout << "�Է��� �������� �ð��� �������ϴ�." << endl;
	cout << "�� ���������� 1���� �ҿ�˴ϴ�." << endl;
	char check;
	while (true)
	{
		cin >> check;
		if (check == 'y')
		{
			cout << "������ ������ �����մϴ�.\n\n" << endl;
			return;
		}
	}
}

//define Game endings
void Game_endings::endings(Game_system *gs)
{
	if (gs->money < 0) //end_dept
	{
		gs->game_over = true;
		cout << "������ ���� ��ü�ϴ� �ε��ڿ��� ������ ��Ǯ�� �ʽ��״�." << endl;
		Sleep(1000);
		cout << "������ �������� �������� �ǵ��ư����״�." << endl;
		Sleep(1000);
		cout << "������ ���� ��ȯ�� �� ���� �ƿ����� ���� ���Գ״�." << endl;
		Sleep(1000);
		cout << "��ü�� �˹��� ������ �ηȽ��״�." << endl;
		Sleep(1000);
		cout << "\n������ ����, �ƽ��丣��ī�� ������!\n" << endl;
		Sleep(5000);
		cout << "BAD ENDING - DEPT" << endl;
	}
	if (gs->family_count <= 0) //end_bad
	{
		gs->game_over = true;
		cout << "������ �������� ��� ����߽��״�." << endl;
		Sleep(1000);
		cout << "�ε��������� �̷��� �ϲ��� �� �ڳ� ������ ������ ���߰� �ֽ��״�." << endl;
		Sleep(1000);
		cout << "�ε��ڵ鿡�� �ǰ��� ������ �䱸�Ǵ� �� �Գ״�." << endl;
		Sleep(1000);
		cout << "������ ��å���� �ٸ� �����ڰ� ��ġ �� ���Գ״�." << endl;
		Sleep(1000);
		cout << "\n������ ����, �ƽ��丣��ī�� ������!\n" << endl;
		Sleep(5000);
		cout << "BAD ENDING - FAMILY DEATH" << endl;
	}
	if (Game_events::first_spy_mission) //�����̰� �Ǳ�� ���� ��
	{
		if (Game_events::first_spy_mission_clear && Game_events::diploma_spy_mission_clear && Game_events::last_spy_mission_clear)
		{//������ �̼� ��� �޼��� end_spy
			gs->game_over = true;
			cout << "�˹���, ���������� ���Գ״�!" << endl;
			Sleep(1000);
			cout << "������ �庮�� ���������״�." << endl;
			Sleep(1000);
			cout << "���п� Ž���� ����� ���߰�, ���ǰ� ����� �巯�½��״�." << endl;
			Sleep(1000);
			cout << "������ �������� ������ �ְ����� �����ϰڽ��״�." << endl;
			Sleep(1000);
			cout << "�� �̻� �˹������� ���� �ʿ�� �����״�." << endl;
			Sleep(1000);
			cout << "���ܿ� �ɸ´� �ܿ��� �Ǿ��ֽö��" << endl;
			Sleep(1000);
			cout << "���ܰ� �Բ� ������ ������ �ϼ��սô�!" << endl;
			Sleep(1000);
			cout << "\n���ο� �ƽ��丣��ī�� ������!\n" << endl;
			Sleep(5000);
			cout << "HIDDEN ENDING - MEMBER OF ASSOCIATION" << endl;
		}
		else if ((Game_events::first_spy_mission_clear == false && gs->stage >= 4) || //ù��° �̼� ����
			(Game_events::diploma_spy_mission_clear == false && gs->stage >= 7) || //�ι�° �̼� ����
			(Game_events::last_spy_mission_clear == false && gs->stage >=8)) //����° �̼� ����
		{//spy_end_bad
			gs->game_over = true;
			cout << "������ �ǽɽ����� ��ü�� ����Ǿ� ü�����߽��״�." << endl;
			Sleep(1000);
			cout << "�������� ������ Ȱ���� ���� ö���� ������ ���Գ״�." << endl;
			Sleep(1000);
			cout << "\n������ ����, �ƽ��丣��ī�� ������!\n" << endl;
			Sleep(5000);
			cout << "BAD ENDING - INCOMPLETE SPY" << endl;
		}
	}
}

void Game_endings::end_normal()
{
	cout << "���� ������ :�˹���, 20�Ⱓ ������ Ȱ�� ����� �����غôٿ�." << endl;
	Sleep(1000);
	cout << "���� ������ :�� ���� ������ �ֱ� �߳׸�..." << endl;
	Sleep(1000);
	cout << "���� ������ :��� �ƽ��丣��ī�� ���� ���ؿ��ݳ�." << endl;
	Sleep(1000);
	cout << "���� ������ :���� �㹰 ������ �� ���� ������." << endl;
	Sleep(1000);
	cout << "���� ������ :�������� ã�ƺ� �� ������." << endl;
	Sleep(1000);
	cout << "���� ������ :������ �ƽ��丣��ī�� ���Ͽ�." << endl;
	Sleep(1000);
	cout << "\n\n\n==========================�ε� �Ź�==========================" << endl;
	cout << "|\n|1982�� 12�� 1��\n|" << endl;
	cout << "| ���ݷ�ġ�ƿ� ���ο� ������ �δ�!��" << endl;
	cout << "|......" << endl;
	cout << "| -�׷���ƾ ���� ���ܼҰ� �ٽ� ����� ��-" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
	cout << "=============================================================\n\n\n" << endl;
	Sleep(5000);
	cout << "���� ������ :�����ε� �� ��Ź�ճ״� ����." << endl;
	Sleep(1000);
	cout << "\n������ ����, �ƽ��丣��ī�� ������!\n" << endl;
	Sleep(5000);
	cout << "NORMAL ENDING CLEAR!" << endl;
	cout << "������ ������ ������ ã�ƺ�����." << endl;
}

void Game_endings::show_last_result(Game_system *gs)
{
	//���� ���޽�������
	cout << "\n���� ���� �������� :";
	if (gs->stage > 8)
		cout << "8(Final)" << endl;
	else
		cout << gs->stage << endl;
	cout << "���� ���� �� :" << gs->family_count << endl;
	cout << gs->total_success << "���� ���ఴ ó��" << endl;
	cout << gs->total_allow_pass << "�� ����" << endl;
	cout << gs->total_deny_pass<< "�� ����" << endl;
	cout << gs->total_detain_pass << "�� ����" << endl;
	cout << gs->mistake << "ȸ ���" << endl;

	cout << "\n-�� ���Ӱ� ��ü�� �����Դϴ�.-" << endl;
	cout << "\n-�� ������ '3909' ���߻��� 'PAPERS, PLEASE'������ ī�� �������Դϴ�.-" << endl;
	cout << "Thanks for play!" << endl;
}