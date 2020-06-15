#include <string>
#include "ppz_game_system.h"
#include "ppz_tage_N_characters.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <random>


using namespace std;
using std::cout;
using std::endl;
using std::shuffle;

//�������� ����ϴ� �Լ���
void Stg_character::show_passport()
{
	if (identity == 5)
	{
		cout << "��� : ���ǰ��� �Ҹ��ϰ��ֳ�, ���� ���̳� �����." << endl;
		Sleep(500);
	}
	else
	{
		cout << "==================================" << endl;
		cout << "|�̸� :" << this->name << endl;
		cout << "|���� :" << this->dateOfBirth << endl;
		cout << "|���� :";
		if (gender)
			cout << "��" << endl;
		else
			cout << "��" << endl;
		cout << "|���� :" << this->city << endl;
		cout << "|���� :" << this->passport_expiration << endl;
		cout << "|==��" << this->nationality << "��==" << endl;
		cout << "|�ĺ� ���� :" << this->passport_number << endl;
		cout << "==================================" << endl;
	}
}

void Stg_character::chara_talk_start()
{
	Sleep(200);
	cout << "��� : ���� �����Ͻö��\n" << endl;
	Sleep(600);
	cout << "��� : ";
	if (identity == 1)
	{
		cout << "��ħ�� ���⿡ �� �� �ְڱ�\n" << endl;
	}
	else if (identity == 2)
	{
		cout << "�������� ���� �˹��ҳ׿�.\n" << endl;
	}
	else if (identity == 5)
	{
		cout << "�˹��� ������ ��ü �� �ִ°ž�?\n" << endl;
	}
	else if (identity == 6)
	{
		cout << "��, �ȳ��ϽŰ�.\n" << endl;
	}
	else if (identity == 16)
	{
		cout << "�ڳ� Ȥ��.... ��, �ƴҼ�\n" << endl;
	}
	else if (identity == 23 || identity == 27)
	{
		cout << "���ǳ׿�\n" << endl;
	}
	else if (identity == 26)
	{
		cout << "�ݰ��� ����" << endl;
		Sleep(400);
		cout << "��� : (������ �ǳٴ�.)" << endl;
		Sleep(200);
		cout << "==============================================================" << endl;
		cout << "�� �ƽ��丣��ī�� ȯ���� ������ �����ÿ�?" << endl;
		cout << "�츮�� ��� �� ������ ����ǰ� �߸��Ǿ��ٴ°��� �˰��ּ�" << endl;
		cout << "�츮 ��縦 �����ֽð�." << endl;
		cout << "==============================================================" << endl;
		Sleep(400);
		cout << "��� : �츮 ��縦 ���ڴٸ�, �� �鿩������ ������ �ϴ� '������' �˹����� �� �� ���� Ʋ���� �ȵǳ�." << endl;
		Sleep(400);
		cout << "��� : �� �׳� ���������� �������� �ƹ� ���ص� ���ٰ� �������, �˴� �ι��� �ƴ� ������ ������." << endl;
		Sleep(400);
		cout << "��� : �����Ͻð� ����." << endl;

	}
	else if (identity == 34)
	{
		cout << "......\n" << endl;
	}
	else if (identity == 51)
	{
		cout << "�̵� ��Ҵ� ��Ÿ �������°� �Ǵ�!!!!!!!!!!!!\n" << endl;
	}
	else if (identity == 52 && Game_events::first_spy_mission)
	{
		cout << "�ݰ���" << endl;
		Sleep(400);
		cout << "��� : �츮 ��縦 ���Դٴ� ���� �˰��ּ�. �츰 �� �踦 ź ������." << endl;
		Sleep(400);
		cout << "��� : ���� �ݷ�ġ���� �ܱ��� �ڰ����� �Ա��Ͽ�. ������ �Ż簡 �ִ� ������." << endl;
		Sleep(400);
		cout << "��� : �� �鿩������ ������ �ϴ� '������' �˹����� �� �� ���� Ʋ���� �ȵǿ�." << endl;
		Sleep(400);
		cout << "��� : ���ο� �ô븦 ���Ͽ�." << endl;
	}
	else if (identity == 61 && Game_events::first_spy_mission)
	{
		cout << "�ݰ���" << endl;
		Sleep(400);
		cout << "��� : ������ �츮 ����� �߿��� ���̿�" << endl;
		Sleep(400);
		cout << "��� : �Ƹ���, ���� �ϸ� �����ϸ� ���ο� �ƽ��丣��ī�� ������ �� ������ �𸣿�." << endl;
		Sleep(400);
		cout << "��� : �� �鿩������ ������ �ϴ� '������' �˹����� �� �� ���� Ʋ���� �ȵǿ�." << endl;
		Sleep(400);
		cout << "��� : ���ο� �ô븦 ���Ͽ�." << endl;
	}
	else
	{
		cout << "�ݰ���\n" << endl;
	}
	Sleep(500);
}

void Stg_character::chara_talk_allow()
{
	cout << "��� : ";
	if (identity == 1)
	{
		cout << "�ƽ�Ʈ����ī�� ���Ͽ�\n" << endl;
	}
	else if (identity == 2)
	{
		cout << "����\n" << endl;
	}
	else if (identity == 5)
	{
		cout << "���ۿ� �׷�������.\n" << endl;
	}
	else if (identity == 26)
	{
		cout << "����� �ϰڼ�\n";
		Sleep(200);
		cout << "��� : �� �ѹ��� Ʋ���� �ȵǳ�!\n" << endl;
		Game_events::first_spy_mission = true;
		Game_events::first_spy_mission_clear = true;
	}
	else if (identity == 47)
	{
		cout << "���� �˹�����, ��Ź�� �ִµ�..\n";
		Sleep(500);
		cout << "��� : �� �Ƴ��� '�̳��� �̿���' ���� ���� �� �˹��ҷο´ٸ� �� ��Ź�帳�ϴ�.\n" << endl;
	}
	else if (identity == 52)
	{
		cout << "���� �Ͻó�, �����ÿ�.\n";
	}
	else
	{
		cout << "����\n" << endl;
	}
	Sleep(500);
	cout << "��� : �������!\n" << endl;
	Sleep(500);
}
void Stg_character::chara_talk_deny()
{
	cout << "��� : ";
	if (identity == 1)
	{
		cout << "�װ��� �ƽ��丣��ī�� ���̶��\n" << endl;
	}
	else if (identity == 2)
	{
		cout << "��, �ȵǳ���?\n" << endl;
	}
	else if (identity == 5 || identity == 51)
	{
		cout << "(�� �� ���ѿ�)\n" << endl;
	}
	else if (identity == 6)
	{
		cout << "�ܱ����� �ȹ޴°ſ���?\n" << endl;
	}
	else if (identity == 26)
	{
		cout << "����� ���� �׷��ϴٸ�...\n" << endl;
	}
	else if (identity == 34)
	{
		cout << "������! \n" << endl;
	}
	else
	{
		if (identity % 2 == 0)
		{
			cout << "�̷�.\n" << endl;

		}
		else
		{
			cout << "�� ���� �߱�\n" << endl;
		}
	}
	Sleep(500);
	cout << "��� : �������!\n" << endl;
	Sleep(500);
}
void Stg_character2::interrogation()
{
	if (identity == 8 || identity == 14 || identity ==18 || identity == 33
		|| identity == 59)
	{
		Sleep(500);
		cout << "��� : ���ð� �߸��� �� ������?" << endl;
		Sleep(500);
		cout << "��� : ��... �����Ҹ�����? ����� ���캻 �� �¾ƿ�?" << endl;
		Sleep(500);
		cout << "��� : Ȯ���� ������ ���ð� ���� �ʴ±� �ⷡ" << endl;
		Sleep(500);
	}
	else if (identity == 10)
	{
		Sleep(500);
		cout << "��� : ���� ������ �̻��ѵ�?" << endl;
		Sleep(500);
		cout << "��� : ���� ���� ������ �ߴٴ°Ծ�?" << endl;
		Sleep(500);
		cout << "��� : ������ ���� �����±� �ⷡ" << endl;
		Sleep(500);
	}
	else if (identity == 12 || identity == 49)
	{
		Sleep(500);
		cout << "��� : ���� ������ ����Ǿ���" << endl;
		Sleep(500);
		cout << "��� : �̷�... �׳� ������ �� ���ڳ�?" << endl;
		Sleep(500);
	}
	else if (identity == 16 || identity ==17)
	{
		Sleep(500);
		cout << "��� : ����, ����ǥ�� ����ּ�?" << endl;
		Sleep(500);
		cout << "��� : �̷�... �׳� ������ �� ���ڳ�?" << endl;
		Sleep(500);
	}
	else if (identity == 19)
	{
		Sleep(500);
		cout << "��� : ���� ����ǥ�� ���̷���?" << endl;
		Sleep(500);
		cout << "��� : ��... �� �����ּ�?" << endl;
		Sleep(500);
		cout << "��� : �� ����ǥ�� ���� �� �� ����" << endl;
		Sleep(500);
	}
	else if (identity == 50)
	{
		Sleep(500);
		cout << "��� : �̰� ������ �Ա�ǥ��?" << endl;
		Sleep(500);
		cout << "��� : �̰����δ� �ȵǿ�?" << endl;
		Sleep(500);
		cout << "��� : �� ����ǥ�� ���� ������� �ʼ�" << endl;
		Sleep(500);
	}
	else if (identity == 30 || identity == 32 || identity == 39 || 
		identity == 48 || identity == 58)
	{
		Sleep(500);
		cout << "��� : ���� �㰡���� ����ּ�?" << endl;
		Sleep(500);
		cout << "��� : �㰡��? �������̿�?" << endl;
		Sleep(500);
		cout << "��� : �ܱ����� �㰡���� ������ ������ �� ����" << endl;
		Sleep(500);
	}
	else if (identity == 31)
	{
		Sleep(500);
		cout << "��� : ������ �ź��� ����ּ�?" << endl;
		Sleep(500);
		cout << "��� : ��... ����� ..." << endl;
		Sleep(500);
		cout << "��� : �ź����� ������ ������ �� ����" << endl;
		Sleep(500);
	}
	else if (identity == 26)
	{
		Sleep(500);
		cout << "��� : �̾������� ���� �� �Ҹ��� ����" << endl;
		Sleep(500);
		cout << "��� : �ڽ� �ִٸ� ������ �޾Ƶ��̽ÿ�" << endl;
		Sleep(500);
		cout << "��� : �ƴ϶�� �� �̸� ���ư��ڼ�" << endl;
		Sleep(500);
	}
	else if (identity == 34)
	{
		Sleep(500);
		cout << "��� : Ȥ��... ���� �Ź��� ���� �����ڽÿ�?" << endl;
		Sleep(500);
		cout << "��� : ...�� �������� ������ ����. �Ա� �����ֽÿ�" << endl;
		Sleep(500);
		cout << "��� : ��..." << endl;
		Sleep(500);
	}
	else if (identity == 40 || identity == 41 || identity == 57)
	{
		Sleep(500);
		cout << "��� : ������ �����鿡�� ��ġ���� �ʴ� ������ �ּ�" << endl;
		Sleep(500);
		cout << "��� : ......." << endl;
		Sleep(500);
		cout << "��� : �̷� �����δ� ������ �� ����" << endl;
		Sleep(500);
	}
	else if (identity == 42 || identity==60)
	{
		Sleep(500);
		cout << "��� : �ε��� ���� �Ա����� �ε� �㰡���� �ʿ��Ͽ�" << endl;
		Sleep(500);
		cout << "��� : ó����� �Ҹ��ε���?" << endl;
		Sleep(500);
		cout << "��� : �ε� �㰡�� ���̴� ������ �� ����" << endl;
		Sleep(500);
	}
	else if (identity == 51)
	{
	cout << "��� : ��!!!!!!!!!!!!" << endl;
	Sleep(500);
	cout << "��� : (���� ������ �ʴ´�)" << endl;
	Sleep(500);
	}
	else if (identity == 52 || identity == 53)
	{
		Sleep(500);
		cout << "��� : Ȯ���� �ܱ��� ������ ������ �ִµ� ���� �� �ʿ��Ͽ�?" << endl;
		Sleep(500);
		cout << "��� : �ƴմϴ�, Ȯ���� �� ������." << endl;
		Sleep(500);
	 }
	else //�߸��� ���� �� �ð� �г�Ƽ
	{
		Sleep(500);
		cout << "��� : ����... ���� �����ѵ�..." << endl;
		Sleep(2000);
		cout << "��� : ���� �Ҹ� �ϴ°Կ�?" << endl;
		Sleep(2000);
		cout << "��� : �Ĳ��� �� �о�ÿ�, �� ���ǿ� ������ ����" << endl;
		Sleep(2500);
		cout << "��� : ......." << endl;
		Sleep(3000);
		cout << "��� : (�߸��� �� ����. �� ������ ������ ����." << endl;
		Sleep(500);
		cout << "��� : �̾��Ͽ�" << endl;
		Sleep(500);
		cout << "��� : �������� ���� �鿩���� �ֽÿ�" << endl;
		Sleep(500);
	}
}



//1stg_ch
Stg_character::Stg_character() :Stg_character(0, "name", "dob", true, "nationality", "city", "p_e", "p_n") {};
Stg_character::Stg_character(int idt, string name, string dob, bool gender,
	string nationality, string city,
	string p_e, string p_n)
{
	identity = idt;
	this->name = name; dateOfBirth = dob; this->gender = gender;
	this->nationality = nationality; this->city = city;
	passport_expiration = p_e; passport_number = p_n;
}

//2stg_Ch
Stg_character2::Stg_character2() :Stg_character2(0, "name", "dob", true, "nationality", "city", "p_e", "p_n",true) {};
Stg_character2::Stg_character2(int idt, string name, string dob, bool gender,
	string nationality, string city,
	string p_e, string p_n, bool integ) : Stg_character(idt, name, dob, gender, nationality, city, p_e, p_n)
{
	integrity = integ;
}

//3stg_ch
Stg_character3::Stg_character3() :Stg_character3(0, "name", "dob", true, "nationality", "city", "p_e", "p_n", true, true) {};
Stg_character3::Stg_character3(int idt, string name, string dob, bool gender,
	string nationality, string city,
	string p_e, string p_n, bool integ, bool ntr_tk) : Stg_character2(idt, name, dob, gender, nationality, city, p_e, p_n, integ)
{
	entry_ticket = ntr_tk;
}
void Stg_character3::show_passport()
{
	Stg_character::show_passport();
	if (entry_ticket)
	{
		cout << "\n\n=============================" << endl;
		cout << "���� �� Ʈ �� �� ī��" << endl;
		cout << "�� �� �� �� ��" << endl;
		cout << "���� 1982. 11. 25���� ��ȿ" << endl;
		cout << "=============================" << endl;
	}
	else
	{
		if (identity == 19)
		{
			cout << "\n\n-----------------------------" << endl;
			cout << "�ƽ�Ʈ����ī" << endl;
			cout << "�Ա��㰡��" << endl;
			cout << "�Ա� �Ͻʽÿ�" << endl;
			cout << "-----------------------------" << endl;
		}
	}
}

//4stg_ch
Stg_character4::Stg_character4() :Stg_character4(0, "name", "dob", true, "nationality", "city", "p_e", "p_n", true, "pps") {};
Stg_character4::Stg_character4(int idt, string name, string dob, bool gender,
	string nationality, string city,
	string p_e, string p_n, bool integ, string pps) : Stg_character2(idt, name, dob, gender, nationality, city, p_e, p_n, integ)
{
	purpose = pps;
	today_date = "1982�� 11�� 26��";
}
void Stg_character4::show_passport()
{
	Stg_character::show_passport();
	if (nationality == "�ƽ��丣��ī")
	{
		if (identity == 40)
		{
			cout << "\n\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �ź� ������" << endl;
			cout << "�̸�: �� ����" << endl;
			cout << "���� ����:" << dateOfBirth << endl;
			cout << "������:" << city << endl;
			cout << "=============================" << endl;
		}
		if (identity == 57)
		{
			cout << "\n\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �ź� ������" << endl;
			cout << "�̸�: �� �� ��" << endl;
			cout << "���� ����:20000.08.20"  << endl;
			cout << "������:" << city << endl;
			cout << "=============================" << endl;
		}
		else if (identity != 31)
		{
			cout << "\n\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �ź� ������" << endl;
			cout << "�̸�:" << name << endl;
			cout << "���� ����:" << dateOfBirth << endl;
			cout << "������:" << city << endl;
			cout << "=============================" << endl;
		}
	}
	else
	{
		if (identity == 41)
		{
			cout << "\n\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �Ա� �㰡��-" << endl;
			cout << "���� ��ȣ: LARKD-3KJSA" << endl;
			cout << "�Ա� ����:" << purpose << endl;
			cout << "�Ա� ��¥: 1982�� 11�� 26��" << endl;
			cout << "=============================" << endl;
		}
		else if (identity != 30 && identity != 32 && identity != 39 
			&& identity != 58 && identity != 52 && identity != 53)
		{
			cout << "\n\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �Ա� �㰡��-" << endl;
			cout << "���� ��ȣ:" << passport_number << endl;
			cout << "�Ա� ����:" << purpose << endl;
			cout << "�Ա� ��¥:" << today_date << endl;
			cout << "=============================" << endl;
		}
	}
}

//5st_ch
Stg_character5::Stg_character5() :Stg_character5(0, "name", "dob", true, "nationality", "city", "p_e", "p_n", true, "pps") {};
Stg_character5::Stg_character5(int idt, string name, string dob, bool gender,
	string nationality, string city,
	string p_e, string p_n, bool integ, string pps) : Stg_character4(idt, name, dob, gender, nationality, city, p_e, p_n, integ, pps)
{
	today_date = "1982�� 11�� 27��";
}
void Stg_character5::show_passport()
{
	Stg_character4::show_passport();
	if (purpose == "��")
	{
		if (identity != 42)
		{
			cout << "\n\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �ε� �㰡��-" << endl;
			cout << "�̸�:" << name << endl;
			cout << "�㰡 ����" << today_date << endl;
			cout << "=============================" << endl;
		}
	}
}

//6st_ch
Stg_character6::Stg_character6(int idt, string name, string dob, bool gender,
	string nationality, string city,
	string p_e, string p_n, bool integ, string pps) : Stg_character5(idt, name, dob, gender, nationality, city, p_e, p_n, integ, pps)
{
	today_date = "1982�� 11�� 28��";
}
void Stg_character6::show_passport()
{
	Stg_character5::show_passport();
}

//7st_ch == 6st_ch, �ܱ��� ����, 2���̶� identity ó�� �� ����
Stg_character7::Stg_character7(int idt, string name, string dob, bool gender,
	string nationality, string city,
	string p_e, string p_n, bool integ, string pps) : Stg_character6(idt, name, dob, gender, nationality, city, p_e, p_n, integ, pps)
{
	today_date = "1982�� 11�� 29��";
}

//8st_ch == 6sh_ch, �ܱ����� ������ spy�Ѹ� ����
Stg_character8::Stg_character8(int idt, string name, string dob, bool gender,
	string nationality, string city,
	string p_e, string p_n, bool integ, string pps) : Stg_character6(idt, name, dob, gender, nationality, city, p_e, p_n, integ, pps)
{
	today_date = "1982�� 11�� 30��";
}



//===================================STAGE===================================
Stage_base::Stage_base() {}

Stage_1::Stage_1()
{

}
void Stage_1::Play_stage(Game_system *gs, int flag, int i)
{

	while (true)
	{
		if (Game_events::chara_first_talk)
		{
			Game_events::chara_first_talk = false;
			chArray[i].chara_talk_start();
		}
		cout << "\n���� �ൿ�� �Ͻðڽ��ϱ�?" << endl;
		cout << "0.������ Ȯ��   1.���� �ź�   2.���� �㰡   4.���� Ȯ��" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==���� ����==" << endl;
			cout << "1. �����ڴ� ������ �����ؾ���" << endl;
			cout << "2. �ƽ��丣��ī �ιθ� �Ա��� �� ����" << endl;
			continue;
		}
		else if (flag == 4)
		{
			chArray[i].show_passport();
		}
		else if (flag == 1)
		{
			if (chArray[i].nationality == "�ƽ��丣��ī")
			{
				gs->new_mistake();
				cout << "�Ծ� ���� : ������ ������ ���� ��û��" << endl;
				cout << "==================================" << endl;
			}
			else
			{
				gs->add_success();
			}
			chArray[i].chara_talk_deny();
			gs->add_total_deny();
			break;
		}
		else if (flag == 2)
		{
			if (chArray[i].nationality == "�ƽ��丣��ī")
			{
				gs->add_success();
				cout << "��� : ������ ���ƿ� ���� ȯ���ճ״�.\n" << endl;
			}
			else
			{
				gs->new_mistake();
				cout << "�Ծ� ���� : �ܱ��� ���� ����" << endl;
				cout << "==================================" << endl;
			}
			chArray[i].chara_talk_allow();
			gs->add_total_allow();
			break;
		}
		else
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			continue;
		}
	}
	Game_events::chara_first_talk = true;
}

//npc random shuffle
Stage_2::Stage_2()
{
	random_device rd;
	shuffle(std::begin(chArray), std::end(chArray), default_random_engine(rd()));
}
void Stage_2::Play_stage(Game_system *gs, int flag, int i)
{
	while (true)
	{
		if (Game_events::chara_first_talk)
		{
			Game_events::chara_first_talk = false;
			chArray[i].chara_talk_start();
		}
		cout << "\n���� �ൿ�� �Ͻðڽ��ϱ�?" << endl;
		cout << "0.������ Ȯ��   1.���� �ź�   2.���� �㰡   4.���� Ȯ��   5.����   9.������:���� ����" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==���� ����==" << endl;
			cout << "1. �����ڴ� ������ �����ؾ���" << endl;
			cout << "2. ������ �������ڰ� ��ȿ�ؾ���." << endl;
			cout << "3. ������ ��ȣ�� ���ڿ� �������� ���� �� 10������." << endl;
			cout << "4. ������ ������ ���ð� ��ȿ�ؾ���." << endl;
			continue;
		}
		else if (flag == 9)
		{
			cout << "==����:���� ����==" << endl;
			cout << "�ƽ��丣��ī - ���� : ����ũ ���� / �׷���ƾ  / �Ķ���" << endl;
			cout << "�ݷ�ġ�� - ���� : ������ / ���� / ����" << endl;
			cout << "���ױ׸��� - ���� : ����Ʈ ���޷� / �۷θ��� / �ƿ��� �׷ν�" << endl;
			cout << "���ۺ��� - ���� : Ʈ�� �۷θ��� / ���������� / ����ź" << endl;
			cout << "���긮��ź - ���� : ��Į / �д��� / ������" << endl;
			cout << "������ - ���� : ��Ű�� / ������ / �����̵�" << endl;
			cout << "���� ���� - ���� : �׷���Ʈ ���ǵ� / �̷�ư / �ڸ���Ÿ ��Ƽ" << endl;

			continue;
		}
		else if (flag == 4)
		{
			chArray[i].show_passport();
		}
		else if (flag == 1)
		{
			if (chArray[i].integrity)
			{
				gs->new_mistake();
				cout << "�Ծ� ���� : ������ ������ ���� ��û��" << endl;
				cout << "==================================" << endl;
			}
			else
			{
				gs->add_success();
			}
			chArray[i].chara_talk_deny();
			gs->add_total_deny();
			break;
		}
		else if (flag == 2)
		{
			if (chArray[i].integrity)
			{
				gs->add_success();
			}
			else
			{
				gs->new_mistake();
				if (chArray[i].identity == 8 || chArray[i].identity == 14)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� ����" << endl;
				}
				else if (chArray[i].identity == 10)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� ���� ��ȣ" << endl;
				}
				else if (chArray[i].identity == 12)
				{
					cout << "�Ծ� ���� : ����� ����" << endl;
				}
				cout << "==================================" << endl;
			}
			chArray[i].chara_talk_allow();
			gs->add_total_allow();
			break;
		}
		else if (flag == 5)
		{
			chArray[i].interrogation();
		}
		else
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			continue;
		}
	}
	Game_events::chara_first_talk = true;
}

Stage_3::Stage_3()
{
	random_device rd;
	shuffle(std::begin(chArray), std::end(chArray), default_random_engine(rd()));
}
void Stage_3::Play_stage(Game_system *gs, int flag, int i)
{
	while (true)
	{
		if (Game_events::chara_first_talk)
		{
			Game_events::chara_first_talk = false;
			chArray[i].chara_talk_start();
		}
		cout << "\n���� �ൿ�� �Ͻðڽ��ϱ�?" << endl;
		cout << "0.������ Ȯ��   1.���� �ź�   2.���� �㰡   4.���� Ȯ��   5.����   9.������:���� ����" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==���� ����==" << endl;
			cout << "1. �����ڴ� ������ �����ؾ���" << endl;
			cout << "2. ������ �������ڰ� ��ȿ�ؾ���." << endl;
			cout << "3. ������ ��ȣ�� ���ڿ� �������� ���� �� 10������." << endl;
			cout << "4. ������ ������ ���ð� ��ȿ�ؾ���." << endl;
			cout << "5. �ܱ���, ������ ������ �ʰ� ���� ǥ�� �ݵ�� �����ؾ���." << endl;
			cout << "-���� ǥ�� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "���� �� Ʈ �� �� ī��" << endl;
			cout << "�� �� �� �� ��" << endl;
			cout << "���� 1982. 11. 25���� ��ȿ" << endl;
			cout << "=============================" << endl;
			continue;
		}
		else if (flag == 9)
		{
			cout << "==����:���� ����==" << endl;
			cout << "�ƽ��丣��ī - ���� : ����ũ ���� / �׷���ƾ  / �Ķ���" << endl;
			cout << "�ݷ�ġ�� - ���� : ������ / ���� / ����" << endl;
			cout << "���ױ׸��� - ���� : ����Ʈ ���޷� / �۷θ��� / �ƿ��� �׷ν�" << endl;
			cout << "���ۺ��� - ���� : Ʈ�� �۷θ��� / ���������� / ����ź" << endl;
			cout << "���긮��ź - ���� : ��Į / �д��� / ������" << endl;
			cout << "������ - ���� : ��Ű�� / ������ / �����̵�" << endl;
			cout << "���� ���� - ���� : �׷���Ʈ ���ǵ� / �̷�ư / �ڸ���Ÿ ��Ƽ" << endl;

			continue;
		}
		else if (flag == 4)
		{
			chArray[i].show_passport();
		}
		else if (flag == 1)
		{
			if (chArray[i].integrity)
			{
				gs->new_mistake();
				cout << "�Ծ� ���� : ������ ������ ���� ��û��" << endl;
				cout << "==================================" << endl;
			}
			else
			{
				gs->add_success();
			}
			chArray[i].chara_talk_deny();
			gs->add_total_deny();
			break;
		}
		else if (flag == 2)
		{
			if (chArray[i].integrity)
			{
				gs->add_success();
			}
			else
			{
				gs->new_mistake();
				if (chArray[i].identity == 18)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� ����" << endl;
				}
				else if (chArray[i].identity == 16 || chArray[i].identity == 17 || chArray[i].identity == 18)
				{
					cout << "�Ծ� ���� : ���� ǥ ��ȿ���� ����" << endl;
				}
				cout << "==================================" << endl;
			}
			chArray[i].chara_talk_allow();
			gs->add_total_allow();
			break;
		}
		else if (flag == 5)
		{
			chArray[i].interrogation();
		}
		else
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			continue;
		}
	}
	Game_events::chara_first_talk = true;
}

Stage_4::Stage_4()
{
	random_device rd;
	shuffle(std::begin(chArray), std::end(chArray), default_random_engine(rd()));
	Stg_character4 chspy = chArray[1];
	for (int i = 0; i < 9; i++)
	{
		if (chArray[i].identity == 26) //�����̰� ������ �ι�°�� �����մϴ�.

		{
			chArray[1] = chArray[i];
			chArray[i] = chspy;
			break;
		}
	}
}
void Stage_4::Play_stage(Game_system *gs, int flag, int i)
{
	while (true)
	{
		if (Game_events::chara_first_talk)
		{
			Game_events::chara_first_talk = false;
			chArray[i].chara_talk_start();
		}
		cout << "\n���� �ൿ�� �Ͻðڽ��ϱ�?" << endl;
		cout << "0.������ Ȯ��   1.���� �ź�   2.���� �㰡   4.���� Ȯ��   5.����   9.������:���� ����" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==���� ����==" << endl;
			cout << "1. �����ڴ� ������ �����ؾ���" << endl;
			cout << "2. ������ �������ڰ� ��ȿ�ؾ���." << endl;
			cout << "3. ������ ��ȣ�� ���ڿ� �������� ���� �� 10������." << endl;
			cout << "4. ������ ������ ���ð� ��ȿ�ؾ���." << endl;
			cout << "5. ���� ǥ�� ���̻� ������� ����" << endl;
			cout << "6. �ܱ����� ���� �㰡���� �ʿ���" << endl;
			cout << "-���� �㰡���� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �Ա� �㰡��-" << endl;
			cout << "���� ��ȣ:(���ǰ� ��ġ�ϴ��� Ȯ��)" << endl;
			cout << "�Ա� ����:" << endl;
			cout << "�Ա� ��¥:(�����̾�� ��)" << endl;
			cout << "=============================" << endl;
			cout << "\n7. �츮 ������ �ź����� �ʿ���" << endl;
			cout << "-�ź����� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �ź� ������" << endl;
			cout << "�̸�:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "���� ����:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "������:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "=============================" << endl;

			continue;
		}
		else if (flag == 9)
		{
			cout << "==����:���� ����==" << endl;
			cout << "�ƽ��丣��ī - ���� : ����ũ ���� / �׷���ƾ  / �Ķ���" << endl;
			cout << "�ݷ�ġ�� - ���� : ������ / ���� / ����" << endl;
			cout << "���ױ׸��� - ���� : ����Ʈ ���޷� / �۷θ��� / �ƿ��� �׷ν�" << endl;
			cout << "���ۺ��� - ���� : Ʈ�� �۷θ��� / ���������� / ����ź" << endl;
			cout << "���긮��ź - ���� : ��Į / �д��� / ������" << endl;
			cout << "������ - ���� : ��Ű�� / ������ / �����̵�" << endl;
			cout << "���� ���� - ���� : �׷���Ʈ ���ǵ� / �̷�ư / �ڸ���Ÿ ��Ƽ" << endl;

			continue;
		}
		else if (flag == 4)
		{
			chArray[i].show_passport();
		}
		else if (flag == 1)
		{
			if (chArray[i].integrity)
			{
				if (chArray[i].identity == 26)// �Ա���Ű�� ���� �г�Ƽ�� ����.
				{
					chArray[i].chara_talk_deny();
					gs->add_total_deny();
					break;
				}
				gs->new_mistake();
				Game_events::first_spy_mission_clear = false;
				cout << "�Ծ� ���� : ������ ������ ���� ��û��" << endl;
				cout << "==================================" << endl;
			}
			else
			{
				gs->add_success();
			}
			chArray[i].chara_talk_deny();
			gs->add_total_deny();
			break;
		}
		else if (flag == 2)
		{
			if (chArray[i].integrity)
			{
				gs->add_success();
			}
			else
			{
				gs->new_mistake();
				Game_events::first_spy_mission_clear = false;
				if (chArray[i].identity == 33)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� ����" << endl;
				}
				else if (chArray[i].identity == 30 || chArray[i].identity == 32)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� �㰡��" << endl;
				}
				else if (chArray[i].identity == 31)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� �ź���" << endl;
				}
				cout << "==================================" << endl;
			}
			chArray[i].chara_talk_allow();
			gs->add_total_allow();
			break;
		}
		else if (flag == 5)
		{
			chArray[i].interrogation();
		}
		else
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			continue;
		}
	}
	Game_events::chara_first_talk = true;
}

Stage_5::Stage_5()
{
	random_device rd;
	shuffle(std::begin(chArray), std::end(chArray), default_random_engine(rd()));
	Stg_character5 chspy = chArray[0];
	for (int i = 0; i < 9; i++)
	{
		if (chArray[i].identity == 34) //�����ڰ� ������ ù��°�� �����մϴ�.

		{
			chArray[0] = chArray[i];
			chArray[i] = chspy;
			break;
		}
	}
}
void Stage_5::Play_stage(Game_system *gs, int flag, int i)
{
	while (true)
	{
		if (Game_events::chara_first_talk)
		{
			Game_events::chara_first_talk = false;
			chArray[i].chara_talk_start();
		}
		cout << "\n���� �ൿ�� �Ͻðڽ��ϱ�?" << endl;
		cout << "0.������ Ȯ��   1.���� �ź�   2.���� �㰡   4.���� Ȯ��   5.����   8.������:�㰡��   9.������:���� ����" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==���� ����==" << endl;
			cout << "1. �����ڴ� ������ �����ؾ���" << endl;
			cout << "2. ������ �������ڰ� ��ȿ�ؾ���." << endl;
			cout << "3. ������ ��ȣ�� ���ڿ� �������� ���� �� 10������." << endl;
			cout << "4. ������ ������ ���ð� ��ȿ�ؾ���." << endl;
			cout << "5. ���� ǥ�� ���̻� ������� ����" << endl;

			continue;
		}
		else if (flag == 8)
		{
			cout << "==������:�㰡�� ���á�==" << endl;
			cout << "6. �ܱ����� ���� �㰡���� �ʿ���" << endl;
			cout << "-���� �㰡���� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �Ա� �㰡��-" << endl;
			cout << "���� ��ȣ:(���ǰ� ��ġ�ϴ��� Ȯ��)" << endl;
			cout << "�Ա� ����:" << endl;
			cout << "�Ա� ��¥:(�����̾�� ��)" << endl;
			cout << "=============================" << endl;

			cout << "\n7. �츮 ������ �ź����� �ʿ���" << endl;
			cout << "-�ź����� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �ź� ������" << endl;
			cout << "�̸�:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "���� ����:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "������:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "=============================" << endl;

			cout << "\n8. �ܱ��� ���� ������ '��' �̶�� �ε� �㰡���� �ʿ���" << endl;
			cout << "-�ε� �㰡���� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �ε� �㰡��-" << endl;
			cout << "�̸�:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "�㰡 ����:(���� ��¥�� ��ġ Ȯ��)" << endl;
			cout << "=============================" << endl;
		}
		else if (flag == 9)
		{
			cout << "==����:���� ����==" << endl;
			cout << "�ƽ��丣��ī - ���� : ����ũ ���� / �׷���ƾ  / �Ķ���" << endl;
			cout << "�ݷ�ġ�� - ���� : ������ / ���� / ����" << endl;
			cout << "���ױ׸��� - ���� : ����Ʈ ���޷� / �۷θ��� / �ƿ��� �׷ν�" << endl;
			cout << "���ۺ��� - ���� : Ʈ�� �۷θ��� / ���������� / ����ź" << endl;
			cout << "���긮��ź - ���� : ��Į / �д��� / ������" << endl;
			cout << "������ - ���� : ��Ű�� / ������ / �����̵�" << endl;
			cout << "���� ���� - ���� : �׷���Ʈ ���ǵ� / �̷�ư / �ڸ���Ÿ ��Ƽ" << endl;

			continue;
		}
		else if (flag == 4)
		{
			chArray[i].show_passport();
		}
		else if (flag == 1)
		{
			if (chArray[i].integrity)
			{
				if (chArray[i].identity == 34)// �Ա���Ű�� ���� �г�Ƽ�� ����.
				{
					chArray[i].chara_talk_deny();
					gs->add_total_deny();
					break;
				}
				gs->new_mistake();
				cout << "�Ծ� ���� : ������ ������ ���� ��û��" << endl;
				cout << "==================================" << endl;
			}
			else
			{
				gs->add_success();
			}
			chArray[i].chara_talk_deny();
			gs->add_total_deny();
			break;
		}
		else if (flag == 2)
		{
			if (chArray[i].integrity)
			{
				if (chArray[i].identity == 34)
					Game_events::murder_pass_event = true;
				gs->add_success();
			}
			else
			{
				gs->new_mistake();
				if (chArray[i].identity == 42)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� �ε� �㰡��" << endl;
				}
				else if (chArray[i].identity == 39 || chArray[i].identity == 41)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� �㰡��" << endl;
				}
				else if (chArray[i].identity == 40)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� �ź���" << endl;
				}
				cout << "==================================" << endl;
			}
			chArray[i].chara_talk_allow();
			gs->add_total_allow();
			break;
		}
		else if (flag == 5)
		{
			chArray[i].interrogation();
		}
		else
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			continue;
		}
	}
	Game_events::chara_first_talk = true;
}


Stage_6::Stage_6()
{
	random_device rd;
	shuffle(std::begin(chArray), std::end(chArray), default_random_engine(rd()));
	Stg_character6 chspy = chArray[0];
	for (int i = 0; i < 9; i++)
	{
		if (chArray[i].identity == 47) //�ڳ� �������� (�κ��̺�Ʈ) ������ ù��°�� �����մϴ�.

		{
			chArray[0] = chArray[i];
			chArray[i] = chspy;
			break;
		}
	}
}
void Stage_6::Play_stage(Game_system *gs, int flag, int i)
{
	while (true)
	{
		if (Game_events::chara_first_talk)
		{
			Game_events::chara_first_talk = false;
			chArray[i].chara_talk_start();
		}
		cout << "\n���� �ൿ�� �Ͻðڽ��ϱ�?" << endl;
		cout << "0.������ Ȯ��   1.���� �ź�   2.���� �㰡   3.����   4.���� Ȯ��   5.����   8.������:�㰡��   9.������:���� ����" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==���� ����==" << endl;
			cout << "1. �����ڴ� ������ �����ؾ���" << endl;
			cout << "2. ������ �������ڰ� ��ȿ�ؾ���." << endl;
			cout << "3. ������ ��ȣ�� ���ڿ� �������� ���� �� 10������." << endl;
			cout << "4. ������ ������ ���ð� ��ȿ�ؾ���." << endl;
			cout << "5. ���� ǥ�� ���̻� ������� ����" << endl;
			cout << "6. ������ �ڴ� ������ ���� �����Ͻÿ�." << endl;

			continue;
		}
		else if (flag == 8)
		{
			cout << "==������:�㰡�� ���á�==" << endl;
			cout << "7. �ܱ����� ���� �㰡���� �ʿ���" << endl;
			cout << "-���� �㰡���� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �Ա� �㰡��-" << endl;
			cout << "���� ��ȣ:(���ǰ� ��ġ�ϴ��� Ȯ��)" << endl;
			cout << "�Ա� ����:" << endl;
			cout << "�Ա� ��¥:(�����̾�� ��)" << endl;
			cout << "=============================" << endl;

			cout << "\n8. �츮 ������ �ź����� �ʿ���" << endl;
			cout << "-�ź����� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �ź� ������" << endl;
			cout << "�̸�:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "���� ����:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "������:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "=============================" << endl;

			cout << "\n9. �ܱ��� ���� ������ '��' �̶�� �ε� �㰡���� �ʿ���" << endl;
			cout << "-�ε� �㰡���� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �ε� �㰡��-" << endl;
			cout << "�̸�:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "�㰡 ����:(���� ��¥�� ��ġ Ȯ��)" << endl;
			cout << "=============================" << endl;
		}
		else if (flag == 9)
		{
			cout << "==����:���� ����==" << endl;
			cout << "�ƽ��丣��ī - ���� : ����ũ ���� / �׷���ƾ  / �Ķ���" << endl;
			cout << "�ݷ�ġ�� - ���� : ������ / ���� / ����" << endl;
			cout << "���ױ׸��� - ���� : ����Ʈ ���޷� / �۷θ��� / �ƿ��� �׷ν�" << endl;
			cout << "���ۺ��� - ���� : Ʈ�� �۷θ��� / ���������� / ����ź" << endl;
			cout << "���긮��ź - ���� : ��Į / �д��� / ������" << endl;
			cout << "������ - ���� : ��Ű�� / ������ / �����̵�" << endl;
			cout << "���� ���� - ���� : �׷���Ʈ ���ǵ� / �̷�ư / �ڸ���Ÿ ��Ƽ" << endl;

			continue;
		}
		else if (flag == 4)
		{
			chArray[i].show_passport();
		}
		else if (flag == 1)
		{
			if (chArray[i].integrity)
			{
				gs->new_mistake();
				cout << "�Ծ� ���� : ������ ������ ���� ��û��" << endl;
				cout << "==================================" << endl;
			}
			else
			{
				gs->add_success();
			}
			chArray[i].chara_talk_deny();
			gs->add_total_deny();
			break;
		}
		else if (flag == 2)
		{
			if (chArray[i].integrity)
			{
				gs->add_success();
			}
			else
			{
				gs->new_mistake();
				if (chArray[i].identity == 49 || chArray[i].identity == 51)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� ����" << endl;
				}
				else if (chArray[i].identity == 48 || chArray[i].identity == 50)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� �㰡��" << endl;
				}
				cout << "==================================" << endl;
			}
			chArray[i].chara_talk_allow();
			gs->add_total_allow();
			break;
		}
		else if (flag == 3)
		{
		if (chArray[i].integrity)
		{
			gs->new_mistake();
			cout << "�Ծ� ���� : ������ ������ ���� ��û��" << endl;
			cout << "==================================" << endl;
		}
		else
		{
			gs->add_success();

		}
		cout << "��� : �������� ����" << endl;
		Sleep(500);
		gs->add_detain();
		break;
		 
		}
		else if (flag == 5)
		{
			chArray[i].interrogation();
		}
		else
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			continue;
		}
	}
	Game_events::chara_first_talk = true;
}

Stage_7::Stage_7()
{
	random_device rd;
	shuffle(std::begin(chArray), std::end(chArray), default_random_engine(rd()));
	Stg_character7 chspy = chArray[0];
	for (int i = 0; i < 9; i++)
	{
		if (chArray[i].identity == 52) //�ݷ�ġ���� �ܱ����� ù��°�� �����մϴ�.

		{
			chArray[0] = chArray[i];
			chArray[i] = chspy;
			break;
		}
	}
}
void Stage_7::Play_stage(Game_system *gs, int flag, int i)
{

	while (true)
	{
		if (Game_events::chara_first_talk)
		{
			Game_events::chara_first_talk = false;
			chArray[i].chara_talk_start();
		}
		cout << "\n���� �ൿ�� �Ͻðڽ��ϱ�?" << endl;
		cout << "0.������ Ȯ��   1.���� �ź�   2.���� �㰡   3.����   4.���� Ȯ��   5.����   7.Ư������:�ܱ���   8.������:�㰡��   9.������:���� ����" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==���� ����==" << endl;
			cout << "1. �����ڴ� ������ �����ؾ���" << endl;
			cout << "2. ������ �������ڰ� ��ȿ�ؾ���." << endl;
			cout << "3. ������ ��ȣ�� ���ڿ� �������� ���� �� 10������." << endl;
			cout << "4. ������ ������ ���ð� ��ȿ�ؾ���." << endl;
			cout << "5. ���� ǥ�� ���̻� ������� ����" << endl;
			cout << "6. ������ �ڴ� ������ ���� �����Ͻÿ�." << endl;

			continue;
		}
		else if (flag == 7)
		{
			cout << "==������:�ܱ��� ���á�==" << endl;
			cout << "�ܱ����� ���ǰ� ��ȿ�� �ܱ��� ���Ѽ��� ������ ������ �� ����" << endl;
			cout << "�ܱ����� ���� �㰡���� ��� ��" << endl;
			cout << "-�ܱ��� ���Ѽ��� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "������ �̸���" << endl;
			cout << "=�ܱ��� ������=" << endl;
			cout << "������Ʈ �̸�:(���ǰ� ��ġ�ϴ��� Ȯ��)" << endl;
			cout << "���� ��ȣ:(���ǰ� ��ġ�ϴ��� Ȯ��)" << endl;
			cout << "�湮 ����:('�ƽ��丣��ī'�̾�� ��)" << endl;
			cout << "-�� ������ �������� ������, ������ ��ȣ�� �޽��ϴ�-" << endl;
			cout << "=============================" << endl;
			cout << "\n�ܱ����� ���� ���ݽ�Ű�� �� ��." << endl;
		}
		else if (flag == 8)
		{
			cout << "==������:�㰡�� ���á�==" << endl;
			cout << "7. �ܱ����� ���� �㰡���� �ʿ���" << endl;
			cout << "-���� �㰡���� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �Ա� �㰡��-" << endl;
			cout << "���� ��ȣ:(���ǰ� ��ġ�ϴ��� Ȯ��)" << endl;
			cout << "�Ա� ����:" << endl;
			cout << "�Ա� ��¥:(�����̾�� ��)" << endl;
			cout << "=============================" << endl;

			cout << "\n8. �츮 ������ �ź����� �ʿ���" << endl;
			cout << "-�ź����� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �ź� ������" << endl;
			cout << "�̸�:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "���� ����:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "������:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "=============================" << endl;

			cout << "\n9. �ܱ��� ���� ������ '��' �̶�� �ε� �㰡���� �ʿ���" << endl;
			cout << "-�ε� �㰡���� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �ε� �㰡��-" << endl;
			cout << "�̸�:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "�㰡 ����:(���� ��¥�� ��ġ Ȯ��)" << endl;
			cout << "=============================" << endl;
		}
		else if (flag == 9)
		{
			cout << "==����:���� ����==" << endl;
			cout << "�ƽ��丣��ī - ���� : ����ũ ���� / �׷���ƾ  / �Ķ���" << endl;
			cout << "�ݷ�ġ�� - ���� : ������ / ���� / ����" << endl;
			cout << "���ױ׸��� - ���� : ����Ʈ ���޷� / �۷θ��� / �ƿ��� �׷ν�" << endl;
			cout << "���ۺ��� - ���� : Ʈ�� �۷θ��� / ���������� / ����ź" << endl;
			cout << "���긮��ź - ���� : ��Į / �д��� / ������" << endl;
			cout << "������ - ���� : ��Ű�� / ������ / �����̵�" << endl;
			cout << "���� ���� - ���� : �׷���Ʈ ���ǵ� / �̷�ư / �ڸ���Ÿ ��Ƽ" << endl;

			continue;
		}
		else if (flag == 4)
		{
			chArray[i].show_passport();
		}
		else if (flag == 1)
		{
			if (chArray[i].integrity)
			{
				gs->new_mistake();
				if (Game_events::first_spy_mission)
					Game_events::diploma_spy_mission_clear = false;
				cout << "�Ծ� ���� : ������ ������ ���� ��û��" << endl;
				cout << "==================================" << endl;

				if (chArray[i].identity == 52 && Game_events::first_spy_mission)
				{
					Game_events::diploma_spy_mission_clear = false;
					cout << "\n\n��� : ���� �ͼ� ��縦 ����ϰڴٴ� �ǰ�?" << endl;
					Sleep(500);
					cout << "��� : �̰� ��û�� ���̳�..." << endl;
					Sleep(500);
				}
				else if (chArray[i].identity == 52 || chArray[i].identity == 53)
				{
					cout << "\n\n��� : ��, �ƽ��丣��ī���� �ܱ��� ���� ������ �������� �ʾҳ�?" << endl;
					Sleep(500);
					cout << "��� : ��ó�� �ϰ��..." << endl;
					Sleep(500);
					cout << "��� : �� �˾Ƽ� �Ա��ϰڼ�, �����Ͻÿ�." << endl;
					Sleep(500);
				}
			}
			else
			{
				gs->add_success();
			}
			chArray[i].chara_talk_deny();
			gs->add_total_deny();
			break;
		}
		else if (flag == 2)
		{
			if (chArray[i].integrity)
			{
				gs->add_success();
			}
			else
			{
				gs->new_mistake();
				if (Game_events::first_spy_mission)
					Game_events::diploma_spy_mission_clear = false;
				if (chArray[i].identity == 58)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� �㰡��" << endl;
				}
				else if (chArray[i].identity == 59)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� ����" << endl;
				}
				else if (chArray[i].identity == 57)
				{
					cout << "�Ծ� ���� : ���� ����ġ" << endl;
				}
				else if (chArray[i].identity == 51)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� �ε� �㰡��" << endl;
				}
				cout << "==================================" << endl;
			}
			chArray[i].chara_talk_allow();
			gs->add_total_allow();
			break;
		}
		else if (flag == 3)
		{
			if (chArray[i].integrity)
			{
				gs->new_mistake();
				if (Game_events::first_spy_mission)
					Game_events::diploma_spy_mission_clear = false;
				cout << "�Ծ� ���� : ������ ������ ���� ��û��" << endl;
				cout << "==================================" << endl;

				if (chArray[i].identity == 52 || chArray[i].identity == 53)
				{
					gs->new_mistake();
					cout << "\n\n��� : Ÿ���� �ܱ����� �����ϰڴٰ�?" << endl;
					Sleep(500);
					cout << "��� : ��ų׵� ���� ���Ʊ�!" << endl;
					Sleep(500);
					cout << "��� : �ƽ��丣��ī �ܱ����� ���� ���Ǹ� ��û�ϰڼ�" << endl;
					Sleep(1000);
					cout << "��� : ��... ��ٷ� �����..." << endl;
					Sleep(1000);
					cout << "��� : ......." << endl;
					Sleep(1000);
					cout << "��� : ......" << endl;
					Sleep(1000);
					cout << "(�ö����� ���븦 ���ϰ� �ִ�. ���� ��ٷ��� �� �� ����.)" << endl;
					Sleep(5000);
					cout << "�ܱ��� : �ƽ��丣��ī, �� ����� ����ϰڼ�" << endl;
					Sleep(1000);
					cout << "��� : ���� �˼��ճ״�. �ſ��� Ȯ�εǾ����״�." << endl;
					Sleep(1000);
					cout << "��� : ���� �˼��ճ״�" << endl;
					Sleep(500);
					cout << "�ܱ��� : ......(�ڵ� ���ƺ��� �ʰ� ������.)" << endl;
					Sleep(500);
					cout << "�ö��� : ����, �̹� �Ǽ��� ��� 2ȸ�� �����ϰڳ�..." << endl;
					Sleep(1000);
				}
			}
			else
			{
				gs->add_success();

			}
			cout << "\n��� : �����϶�� ����" << endl;
			Sleep(500);
			gs->add_detain();
			break;

		}
		else if (flag == 5)
		{
			chArray[i].interrogation();
		}
		else
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			continue;
		}
	}
	Game_events::chara_first_talk = true;
}

Stage_8::Stage_8()
{
	random_device rd;
	shuffle(std::begin(chArray), std::end(chArray), default_random_engine(rd()));
	Stg_character8 chspy = chArray[0];
	for (int i = 0; i < 9; i++)
	{
		if (chArray[i].identity == 61) //�ݷ�ġ���� �ܱ����� ù��°�� �����մϴ�.

		{
			chArray[0] = chArray[i];
			chArray[i] = chspy;
			break;
		}
	}
}
void Stage_8::Play_stage(Game_system *gs, int flag, int i)
{
	while (true)
	{
		if (Game_events::chara_first_talk)
		{
			Game_events::chara_first_talk = false;
			chArray[i].chara_talk_start();
		}
		cout << "\n���� �ൿ�� �Ͻðڽ��ϱ�?" << endl;
		cout << "0.������ Ȯ��   1.���� �ź�   2.���� �㰡   3.����   4.���� Ȯ��   5.����   8.������:�㰡��   9.������:���� ����" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==���� ����==" << endl;
			cout << "1. �����ڴ� ������ �����ؾ���" << endl;
			cout << "2. ������ �������ڰ� ��ȿ�ؾ���." << endl;
			cout << "3. ������ ��ȣ�� ���ڿ� �������� ���� �� 10������." << endl;
			cout << "4. ������ ������ ���ð� ��ȿ�ؾ���." << endl;
			cout << "5. ���� ǥ�� ���̻� ������� ����" << endl;
			cout << "6. ������ �ڴ� ������ ���� �����Ͻÿ�." << endl;

			continue;
		}
		else if (flag == 8)
		{
			cout << "==������:�㰡�� ���á�==" << endl;
			cout << "7. �ܱ����� ���� �㰡���� �ʿ���" << endl;
			cout << "-���� �㰡���� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �Ա� �㰡��-" << endl;
			cout << "���� ��ȣ:(���ǰ� ��ġ�ϴ��� Ȯ��)" << endl;
			cout << "�Ա� ����:" << endl;
			cout << "�Ա� ��¥:(�����̾�� ��)" << endl;
			cout << "=============================" << endl;

			cout << "\n8. �츮 ������ �ź����� �ʿ���" << endl;
			cout << "-�ź����� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �ź� ������" << endl;
			cout << "�̸�:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "���� ����:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "������:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "=============================" << endl;

			cout << "\n9. �ܱ��� ���� ������ '��' �̶�� �ε� �㰡���� �ʿ���" << endl;
			cout << "-�ε� �㰡���� ������ ���� ������" << endl;
			cout << "\n=============================" << endl;
			cout << "���ƽ��丣��ī��" << endl;
			cout << "-�ƽ��丣��ī �ε� �㰡��-" << endl;
			cout << "�̸�:(���ǰ� ��ġ Ȯ��)" << endl;
			cout << "�㰡 ����:(���� ��¥�� ��ġ Ȯ��)" << endl;
			cout << "=============================" << endl;
		}
		else if (flag == 9)
		{
			cout << "==����:���� ����==" << endl;
			cout << "�ƽ��丣��ī - ���� : ����ũ ���� / �׷���ƾ  / �Ķ���" << endl;
			cout << "�ݷ�ġ�� - ���� : ������ / ���� / ����" << endl;
			cout << "���ױ׸��� - ���� : ����Ʈ ���޷� / �۷θ��� / �ƿ��� �׷ν�" << endl;
			cout << "���ۺ��� - ���� : Ʈ�� �۷θ��� / ���������� / ����ź" << endl;
			cout << "���긮��ź - ���� : ��Į / �д��� / ������" << endl;
			cout << "������ - ���� : ��Ű�� / ������ / �����̵�" << endl;
			cout << "���� ���� - ���� : �׷���Ʈ ���ǵ� / �̷�ư / �ڸ���Ÿ ��Ƽ" << endl;

			continue;
		}
		else if (flag == 4)
		{
			chArray[i].show_passport();
		}
		else if (flag == 1)
		{
			if (chArray[i].integrity)
			{
				gs->new_mistake();
				if (Game_events::first_spy_mission)
					Game_events::last_spy_mission_clear = false;
				if (chArray[i].identity == 61 && Game_events::first_spy_mission)
				{
					Game_events::diploma_spy_mission_clear = false;
					cout << "\n\n��� : ���� �ͼ� ��縦 ����ϰڴٴ� �ǰ�?" << endl;
					Sleep(500);
					cout << "��� : �̰� ��û�� ���̳�..." << endl;
					Sleep(500);
				}
				cout << "�Ծ� ���� : ������ ������ ���� ��û��" << endl;
				cout << "==================================" << endl;
			}
			else
			{
				gs->add_success();
			}
			chArray[i].chara_talk_deny();
			gs->add_total_deny();
			break;
		}
		else if (flag == 2)
		{
			if (chArray[i].integrity)
			{
				gs->add_success();
			}
			else
			{
				gs->new_mistake();
				if (Game_events::first_spy_mission)
					Game_events::last_spy_mission_clear = false;
				if (chArray[i].identity == 49 || chArray[i].identity == 51)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� ����" << endl;
				}
				else if (chArray[i].identity == 48 || chArray[i].identity == 50)
				{
					cout << "�Ծ� ���� : ��ȿ���� ���� �㰡��" << endl;
				}
				cout << "==================================" << endl;
			}
			chArray[i].chara_talk_allow();
			gs->add_total_allow();
			break;
		}
		else if (flag == 3)
		{
			if (chArray[i].integrity)
			{
				gs->new_mistake();
				if (Game_events::first_spy_mission)
					Game_events::last_spy_mission_clear = false;
				cout << "�Ծ� ���� : ������ ������ ���� ��û��" << endl;
				cout << "==================================" << endl;
			}
			else
			{
				gs->add_success();

			}
			cout << "��� : �������� ����" << endl;
			Sleep(500);
			gs->add_detain();
			break;

		}
		else if (flag == 5)
		{
			chArray[i].interrogation();
		}
		else
		{
			cout << "�߸��� �Է��Գ״�." << endl;
			continue;
		}
	}
	Game_events::chara_first_talk = true;
}