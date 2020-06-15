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

//범용으로 사용하는 함수들
void Stg_character::show_passport()
{
	if (identity == 5)
	{
		cout << "상대 : 여권같은 소리하고있네, 빨리 문이나 열라고." << endl;
		Sleep(500);
	}
	else
	{
		cout << "==================================" << endl;
		cout << "|이름 :" << this->name << endl;
		cout << "|생년 :" << this->dateOfBirth << endl;
		cout << "|성별 :";
		if (gender)
			cout << "남" << endl;
		else
			cout << "여" << endl;
		cout << "|도시 :" << this->city << endl;
		cout << "|만료 :" << this->passport_expiration << endl;
		cout << "|==「" << this->nationality << "」==" << endl;
		cout << "|식별 숫자 :" << this->passport_number << endl;
		cout << "==================================" << endl;
	}
}

void Stg_character::chara_talk_start()
{
	Sleep(200);
	cout << "당신 : 려권 제출하시라우\n" << endl;
	Sleep(600);
	cout << "상대 : ";
	if (identity == 1)
	{
		cout << "마침내 고향에 갈 수 있겠군\n" << endl;
	}
	else if (identity == 2)
	{
		cout << "생각보다 작은 검문소네요.\n" << endl;
	}
	else if (identity == 5)
	{
		cout << "검문소 따위는 대체 왜 있는거야?\n" << endl;
	}
	else if (identity == 6)
	{
		cout << "여, 안녕하신가.\n" << endl;
	}
	else if (identity == 16)
	{
		cout << "자네 혹시.... 아, 아닐세\n" << endl;
	}
	else if (identity == 23 || identity == 27)
	{
		cout << "기대되네요\n" << endl;
	}
	else if (identity == 26)
	{
		cout << "반갑소 동무" << endl;
		Sleep(400);
		cout << "상대 : (쪽지를 건넨다.)" << endl;
		Sleep(200);
		cout << "==============================================================" << endl;
		cout << "이 아스토르츠카에 환멸을 느끼지 않으시오?" << endl;
		cout << "우리는 모두 이 국가가 모순되고 잘못되었다는것을 알고있소" << endl;
		cout << "우리 결사를 도와주시게." << endl;
		cout << "==============================================================" << endl;
		Sleep(400);
		cout << "상대 : 우리 결사를 돕겠다면, 날 들여보내고 앞으로 하는 '오늘의' 검문들을 단 한 개도 틀리면 안되네." << endl;
		Sleep(400);
		cout << "상대 : 날 그냥 돌려보내도 동무에게 아무 위해도 없다고 약속하지, 죄는 인민이 아닌 국가에 있으니." << endl;
		Sleep(400);
		cout << "상대 : 선택하시게 동무." << endl;

	}
	else if (identity == 34)
	{
		cout << "......\n" << endl;
	}
	else if (identity == 51)
	{
		cout << "이딴 장소는 불타 없어지는게 옳다!!!!!!!!!!!!\n" << endl;
	}
	else if (identity == 52 && Game_events::first_spy_mission)
	{
		cout << "반갑소" << endl;
		Sleep(400);
		cout << "상대 : 우리 결사를 도왔다는 것을 알고있소. 우린 한 배를 탄 셈이지." << endl;
		Sleep(400);
		cout << "상대 : 나는 콜레치아의 외교관 자격으로 입국하오. 오늘은 거사가 있는 날이지." << endl;
		Sleep(400);
		cout << "상대 : 날 들여보내고 앞으로 하는 '오늘의' 검문들을 단 한 개도 틀리면 안되오." << endl;
		Sleep(400);
		cout << "상대 : 새로운 시대를 위하여." << endl;
	}
	else if (identity == 61 && Game_events::first_spy_mission)
	{
		cout << "반갑소" << endl;
		Sleep(400);
		cout << "상대 : 오늘은 우리 결사의 중요한 날이오" << endl;
		Sleep(400);
		cout << "상대 : 아마도, 오늘 일만 성공하면 새로운 아스토르츠카를 맞이할 수 있을지 모르오." << endl;
		Sleep(400);
		cout << "상대 : 날 들여보내고 앞으로 하는 '오늘의' 검문들을 단 한 개도 틀리면 안되오." << endl;
		Sleep(400);
		cout << "상대 : 새로운 시대를 위하여." << endl;
	}
	else
	{
		cout << "반갑소\n" << endl;
	}
	Sleep(500);
}

void Stg_character::chara_talk_allow()
{
	cout << "상대 : ";
	if (identity == 1)
	{
		cout << "아스트로츠카를 위하여\n" << endl;
	}
	else if (identity == 2)
	{
		cout << "고마워\n" << endl;
	}
	else if (identity == 5)
	{
		cout << "진작에 그럴것이지.\n" << endl;
	}
	else if (identity == 26)
	{
		cout << "당신을 믿겠소\n";
		Sleep(200);
		cout << "상대 : 단 한번도 틀리면 안되네!\n" << endl;
		Game_events::first_spy_mission = true;
		Game_events::first_spy_mission_clear = true;
	}
	else if (identity == 47)
	{
		cout << "저기 검문관님, 부탁이 있는데..\n";
		Sleep(500);
		cout << "상대 : 제 아내인 '미나세 이오리' 양이 만약 이 검문소로온다면 잘 부탁드립니다.\n" << endl;
	}
	else if (identity == 52)
	{
		cout << "수고 하시네, 힘내시오.\n";
	}
	else
	{
		cout << "고맙소\n" << endl;
	}
	Sleep(500);
	cout << "당신 : 다음사람!\n" << endl;
	Sleep(500);
}
void Stg_character::chara_talk_deny()
{
	cout << "상대 : ";
	if (identity == 1)
	{
		cout << "그것이 아스토르츠카의 뜻이라면\n" << endl;
	}
	else if (identity == 2)
	{
		cout << "아, 안되나요?\n" << endl;
	}
	else if (identity == 5 || identity == 51)
	{
		cout << "(욕 욕 심한욕)\n" << endl;
	}
	else if (identity == 6)
	{
		cout << "외국인은 안받는거였나?\n" << endl;
	}
	else if (identity == 26)
	{
		cout << "당신의 뜻이 그러하다면...\n" << endl;
	}
	else if (identity == 34)
	{
		cout << "젠장할! \n" << endl;
	}
	else
	{
		if (identity % 2 == 0)
		{
			cout << "이런.\n" << endl;

		}
		else
		{
			cout << "헛 걸음 했군\n" << endl;
		}
	}
	Sleep(500);
	cout << "당신 : 다음사람!\n" << endl;
	Sleep(500);
}
void Stg_character2::interrogation()
{
	if (identity == 8 || identity == 14 || identity ==18 || identity == 33
		|| identity == 59)
	{
		Sleep(500);
		cout << "당신 : 도시가 잘못된 것 같은데?" << endl;
		Sleep(500);
		cout << "상대 : 무... 무슨소리에요? 제대로 살펴본 것 맞아요?" << endl;
		Sleep(500);
		cout << "당신 : 확실히 국가와 도시가 맞지 않는군 기래" << endl;
		Sleep(500);
	}
	else if (identity == 10)
	{
		Sleep(500);
		cout << "당신 : 동무 려권이 이상한데?" << endl;
		Sleep(500);
		cout << "상대 : 내가 려권 위조라도 했다는게야?" << endl;
		Sleep(500);
		cout << "당신 : 도둑이 제발 저리는군 기래" << endl;
		Sleep(500);
	}
	else if (identity == 12 || identity == 49)
	{
		Sleep(500);
		cout << "당신 : 동무 려권은 만료되었소" << endl;
		Sleep(500);
		cout << "상대 : 이런... 그냥 보내줄 순 없겠나?" << endl;
		Sleep(500);
	}
	else if (identity == 16 || identity ==17)
	{
		Sleep(500);
		cout << "당신 : 동무, 립국표는 어디있소?" << endl;
		Sleep(500);
		cout << "상대 : 이런... 그냥 보내줄 순 없겠나?" << endl;
		Sleep(500);
	}
	else if (identity == 19)
	{
		Sleep(500);
		cout << "당신 : 동무 립국표가 왜이렇소?" << endl;
		Sleep(500);
		cout << "상대 : ㅁ... 뭐 문제있소?" << endl;
		Sleep(500);
		cout << "당신 : 이 립국표는 인정 할 수 없소" << endl;
		Sleep(500);
	}
	else if (identity == 50)
	{
		Sleep(500);
		cout << "당신 : 이게 언제적 입국표요?" << endl;
		Sleep(500);
		cout << "상대 : 이것으로는 안되오?" << endl;
		Sleep(500);
		cout << "당신 : 이 립국표는 이제 사용하지 않소" << endl;
		Sleep(500);
	}
	else if (identity == 30 || identity == 32 || identity == 39 || 
		identity == 48 || identity == 58)
	{
		Sleep(500);
		cout << "당신 : 동무 허가서는 어디있소?" << endl;
		Sleep(500);
		cout << "상대 : 허가서? 무슨말이오?" << endl;
		Sleep(500);
		cout << "당신 : 외국인은 허가서가 없으면 립국할 수 없소" << endl;
		Sleep(500);
	}
	else if (identity == 31)
	{
		Sleep(500);
		cout << "당신 : 동무의 신분증 어디있소?" << endl;
		Sleep(500);
		cout << "상대 : 어... 어디갔지 ..." << endl;
		Sleep(500);
		cout << "당신 : 신분증이 없으면 립국할 수 없소" << endl;
		Sleep(500);
	}
	else if (identity == 26)
	{
		Sleep(500);
		cout << "상대 : 미안하지만 나는 더 할말이 없소" << endl;
		Sleep(500);
		cout << "상대 : 자신 있다면 혁명을 받아들이시오" << endl;
		Sleep(500);
		cout << "상대 : 아니라면 난 이만 돌아가겠소" << endl;
		Sleep(500);
	}
	else if (identity == 34)
	{
		Sleep(500);
		cout << "당신 : 혹시... 오늘 신문에 나온 도망자시오?" << endl;
		Sleep(500);
		cout << "상대 : ...내 문서에는 문제가 없소. 입국 시켜주시오" << endl;
		Sleep(500);
		cout << "당신 : 흠..." << endl;
		Sleep(500);
	}
	else if (identity == 40 || identity == 41 || identity == 57)
	{
		Sleep(500);
		cout << "당신 : 동무의 문서들에는 일치하지 않는 정보가 있소" << endl;
		Sleep(500);
		cout << "상대 : ......." << endl;
		Sleep(500);
		cout << "당신 : 이런 문서로는 립국할 수 없소" << endl;
		Sleep(500);
	}
	else if (identity == 42 || identity==60)
	{
		Sleep(500);
		cout << "당신 : 로동을 위한 입국에는 로동 허가서가 필요하오" << endl;
		Sleep(500);
		cout << "상대 : 처음듣는 소리인데요?" << endl;
		Sleep(500);
		cout << "당신 : 로동 허가서 없이는 립국할 수 없소" << endl;
		Sleep(500);
	}
	else if (identity == 51)
	{
	cout << "상대 : 뭐!!!!!!!!!!!!" << endl;
	Sleep(500);
	cout << "당신 : (말이 통하지 않는다)" << endl;
	Sleep(500);
	}
	else if (identity == 52 || identity == 53)
	{
		Sleep(500);
		cout << "상대 : 확실한 외교관 증명서와 여권이 있는데 뭐가 더 필요하오?" << endl;
		Sleep(500);
		cout << "당신 : 아닙니다, 확실한 것 같군요." << endl;
		Sleep(500);
	 }
	else //잘못된 취조 시 시간 패널티
	{
		Sleep(500);
		cout << "당신 : 동무... 뭔가 수상한데..." << endl;
		Sleep(2000);
		cout << "상대 : 무슨 소리 하는게요?" << endl;
		Sleep(2000);
		cout << "상대 : 꼼꼼히 잘 읽어보시오, 내 여권엔 문제가 없소" << endl;
		Sleep(2500);
		cout << "당신 : ......." << endl;
		Sleep(3000);
		cout << "당신 : (잘못본 것 같다. 이 여권은 문제가 없다." << endl;
		Sleep(500);
		cout << "당신 : 미안하오" << endl;
		Sleep(500);
		cout << "상대 : 괜찮으니 빨리 들여보내 주시오" << endl;
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
		cout << "「아 스 트 로 츠 카」" << endl;
		cout << "립 국 허 가 서" << endl;
		cout << "오직 1982. 11. 25에만 유효" << endl;
		cout << "=============================" << endl;
	}
	else
	{
		if (identity == 19)
		{
			cout << "\n\n-----------------------------" << endl;
			cout << "아스트로츠카" << endl;
			cout << "입국허가서" << endl;
			cout << "입국 하십시오" << endl;
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
	today_date = "1982년 11월 26일";
}
void Stg_character4::show_passport()
{
	Stg_character::show_passport();
	if (nationality == "아스토르츠카")
	{
		if (identity == 40)
		{
			cout << "\n\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 신분 인증서" << endl;
			cout << "이름: 김 정은" << endl;
			cout << "생년 월일:" << dateOfBirth << endl;
			cout << "거주지:" << city << endl;
			cout << "=============================" << endl;
		}
		if (identity == 57)
		{
			cout << "\n\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 신분 인증서" << endl;
			cout << "이름: 임 동 권" << endl;
			cout << "생년 월일:20000.08.20"  << endl;
			cout << "거주지:" << city << endl;
			cout << "=============================" << endl;
		}
		else if (identity != 31)
		{
			cout << "\n\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 신분 인증서" << endl;
			cout << "이름:" << name << endl;
			cout << "생년 월일:" << dateOfBirth << endl;
			cout << "거주지:" << city << endl;
			cout << "=============================" << endl;
		}
	}
	else
	{
		if (identity == 41)
		{
			cout << "\n\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 입국 허가서-" << endl;
			cout << "여권 번호: LARKD-3KJSA" << endl;
			cout << "입국 목적:" << purpose << endl;
			cout << "입국 날짜: 1982년 11월 26일" << endl;
			cout << "=============================" << endl;
		}
		else if (identity != 30 && identity != 32 && identity != 39 
			&& identity != 58 && identity != 52 && identity != 53)
		{
			cout << "\n\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 입국 허가서-" << endl;
			cout << "여권 번호:" << passport_number << endl;
			cout << "입국 목적:" << purpose << endl;
			cout << "입국 날짜:" << today_date << endl;
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
	today_date = "1982년 11월 27일";
}
void Stg_character5::show_passport()
{
	Stg_character4::show_passport();
	if (purpose == "일")
	{
		if (identity != 42)
		{
			cout << "\n\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 로동 허가서-" << endl;
			cout << "이름:" << name << endl;
			cout << "허가 일자" << today_date << endl;
			cout << "=============================" << endl;
		}
	}
}

//6st_ch
Stg_character6::Stg_character6(int idt, string name, string dob, bool gender,
	string nationality, string city,
	string p_e, string p_n, bool integ, string pps) : Stg_character5(idt, name, dob, gender, nationality, city, p_e, p_n, integ, pps)
{
	today_date = "1982년 11월 28일";
}
void Stg_character6::show_passport()
{
	Stg_character5::show_passport();
}

//7st_ch == 6st_ch, 외교관 등장, 2명이라 identity 처리 할 예정
Stg_character7::Stg_character7(int idt, string name, string dob, bool gender,
	string nationality, string city,
	string p_e, string p_n, bool integ, string pps) : Stg_character6(idt, name, dob, gender, nationality, city, p_e, p_n, integ, pps)
{
	today_date = "1982년 11월 29일";
}

//8st_ch == 6sh_ch, 외교관은 없지만 spy한명 등장
Stg_character8::Stg_character8(int idt, string name, string dob, bool gender,
	string nationality, string city,
	string p_e, string p_n, bool integ, string pps) : Stg_character6(idt, name, dob, gender, nationality, city, p_e, p_n, integ, pps)
{
	today_date = "1982년 11월 30일";
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
		cout << "\n무슨 행동을 하시겠습니까?" << endl;
		cout << "0.규정집 확인   1.립국 거부   2.립국 허가   4.여권 확인" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "잘못된 입력입네다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==「규 정」==" << endl;
			cout << "1. 립국자는 려권을 소지해야함" << endl;
			cout << "2. 아스토르츠카 인민만 입국할 수 있음" << endl;
			continue;
		}
		else if (flag == 4)
		{
			chArray[i].show_passport();
		}
		else if (flag == 1)
		{
			if (chArray[i].nationality == "아스토르츠카")
			{
				gs->new_mistake();
				cout << "규약 위반 : 립국에 문제가 없는 신청자" << endl;
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
			if (chArray[i].nationality == "아스토르츠카")
			{
				gs->add_success();
				cout << "당신 : 조국에 돌아온 것을 환영합네다.\n" << endl;
			}
			else
			{
				gs->new_mistake();
				cout << "규약 위반 : 외국인 립국 금지" << endl;
				cout << "==================================" << endl;
			}
			chArray[i].chara_talk_allow();
			gs->add_total_allow();
			break;
		}
		else
		{
			cout << "잘못된 입력입네다." << endl;
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
		cout << "\n무슨 행동을 하시겠습니까?" << endl;
		cout << "0.규정집 확인   1.립국 거부   2.립국 허가   4.여권 확인   5.취조   9.규정집:국가 정보" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "잘못된 입력입네다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==「규 정」==" << endl;
			cout << "1. 립국자는 려권을 소지해야함" << endl;
			cout << "2. 려권의 만료일자가 유효해야함." << endl;
			cout << "3. 려권의 번호는 숫자와 영문자의 조합 총 10글자임." << endl;
			cout << "4. 려권의 국가와 도시가 유효해야함." << endl;
			continue;
		}
		else if (flag == 9)
		{
			cout << "==규정:국가 정보==" << endl;
			cout << "아스토르츠카 - 도시 : 오베크 버너 / 그레스틴  / 파라디즈나" << endl;
			cout << "콜레치아 - 도시 : 유르코 / 베더 / 유주" << endl;
			cout << "안테그리아 - 도시 : 세인트 마메로 / 글로리안 / 아우터 그로스" << endl;
			cout << "리퍼블리아 - 도시 : 트루 글로리안 / 레스레나디 / 보스탄" << endl;
			cout << "오브리스탄 - 도시 : 스칼 / 론다즈 / 머저스" << endl;
			cout << "임포르 - 도시 : 은키오 / 하이한 / 슨케이도" << endl;
			cout << "연합 연방 - 도시 : 그레이트 래피드 / 싱레튼 / 코리스타 시티" << endl;

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
				cout << "규약 위반 : 립국에 문제가 없는 신청자" << endl;
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
					cout << "규약 위반 : 유효하지 않은 도시" << endl;
				}
				else if (chArray[i].identity == 10)
				{
					cout << "규약 위반 : 유효하지 않은 여권 번호" << endl;
				}
				else if (chArray[i].identity == 12)
				{
					cout << "규약 위반 : 만료된 여권" << endl;
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
			cout << "잘못된 입력입네다." << endl;
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
		cout << "\n무슨 행동을 하시겠습니까?" << endl;
		cout << "0.규정집 확인   1.립국 거부   2.립국 허가   4.여권 확인   5.취조   9.규정집:국가 정보" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "잘못된 입력입네다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==「규 정」==" << endl;
			cout << "1. 립국자는 려권을 소지해야함" << endl;
			cout << "2. 려권의 만료일자가 유효해야함." << endl;
			cout << "3. 려권의 번호는 숫자와 영문자의 조합 총 10글자임." << endl;
			cout << "4. 려권의 국가와 도시가 유효해야함." << endl;
			cout << "5. 외국인, 내국인 가리지 않고 립국 표가 반드시 존재해야함." << endl;
			cout << "-립국 표는 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「아 스 트 로 츠 카」" << endl;
			cout << "립 국 허 가 서" << endl;
			cout << "오직 1982. 11. 25에만 유효" << endl;
			cout << "=============================" << endl;
			continue;
		}
		else if (flag == 9)
		{
			cout << "==규정:국가 정보==" << endl;
			cout << "아스토르츠카 - 도시 : 오베크 버너 / 그레스틴  / 파라디즈나" << endl;
			cout << "콜레치아 - 도시 : 유르코 / 베더 / 유주" << endl;
			cout << "안테그리아 - 도시 : 세인트 마메로 / 글로리안 / 아우터 그로스" << endl;
			cout << "리퍼블리아 - 도시 : 트루 글로리안 / 레스레나디 / 보스탄" << endl;
			cout << "오브리스탄 - 도시 : 스칼 / 론다즈 / 머저스" << endl;
			cout << "임포르 - 도시 : 은키오 / 하이한 / 슨케이도" << endl;
			cout << "연합 연방 - 도시 : 그레이트 래피드 / 싱레튼 / 코리스타 시티" << endl;

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
				cout << "규약 위반 : 립국에 문제가 없는 신청자" << endl;
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
					cout << "규약 위반 : 유효하지 않은 도시" << endl;
				}
				else if (chArray[i].identity == 16 || chArray[i].identity == 17 || chArray[i].identity == 18)
				{
					cout << "규약 위반 : 립국 표 유효하지 않음" << endl;
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
			cout << "잘못된 입력입네다." << endl;
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
		if (chArray[i].identity == 26) //스파이가 무조건 두번째에 출현합니다.

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
		cout << "\n무슨 행동을 하시겠습니까?" << endl;
		cout << "0.규정집 확인   1.립국 거부   2.립국 허가   4.여권 확인   5.취조   9.규정집:국가 정보" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "잘못된 입력입네다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==「규 정」==" << endl;
			cout << "1. 립국자는 려권을 소지해야함" << endl;
			cout << "2. 려권의 만료일자가 유효해야함." << endl;
			cout << "3. 려권의 번호는 숫자와 영문자의 조합 총 10글자임." << endl;
			cout << "4. 려권의 국가와 도시가 유효해야함." << endl;
			cout << "5. 립국 표는 더이상 사용하지 않음" << endl;
			cout << "6. 외국인은 립국 허가서가 필요함" << endl;
			cout << "-립국 허가서는 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 입국 허가서-" << endl;
			cout << "여권 번호:(여권과 일치하는지 확인)" << endl;
			cout << "입국 목적:" << endl;
			cout << "입국 날짜:(오늘이어야 함)" << endl;
			cout << "=============================" << endl;
			cout << "\n7. 우리 국민은 신분증이 필요함" << endl;
			cout << "-신분증은 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 신분 인증서" << endl;
			cout << "이름:(여권과 일치 확인)" << endl;
			cout << "생년 월일:(여권과 일치 확인)" << endl;
			cout << "거주지:(여권과 일치 확인)" << endl;
			cout << "=============================" << endl;

			continue;
		}
		else if (flag == 9)
		{
			cout << "==규정:국가 정보==" << endl;
			cout << "아스토르츠카 - 도시 : 오베크 버너 / 그레스틴  / 파라디즈나" << endl;
			cout << "콜레치아 - 도시 : 유르코 / 베더 / 유주" << endl;
			cout << "안테그리아 - 도시 : 세인트 마메로 / 글로리안 / 아우터 그로스" << endl;
			cout << "리퍼블리아 - 도시 : 트루 글로리안 / 레스레나디 / 보스탄" << endl;
			cout << "오브리스탄 - 도시 : 스칼 / 론다즈 / 머저스" << endl;
			cout << "임포르 - 도시 : 은키오 / 하이한 / 슨케이도" << endl;
			cout << "연합 연방 - 도시 : 그레이트 래피드 / 싱레튼 / 코리스타 시티" << endl;

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
				if (chArray[i].identity == 26)// 입국시키건 말건 패널티가 없다.
				{
					chArray[i].chara_talk_deny();
					gs->add_total_deny();
					break;
				}
				gs->new_mistake();
				Game_events::first_spy_mission_clear = false;
				cout << "규약 위반 : 립국에 문제가 없는 신청자" << endl;
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
					cout << "규약 위반 : 유효하지 않은 도시" << endl;
				}
				else if (chArray[i].identity == 30 || chArray[i].identity == 32)
				{
					cout << "규약 위반 : 유효하지 않은 허가서" << endl;
				}
				else if (chArray[i].identity == 31)
				{
					cout << "규약 위반 : 유효하지 않은 신분증" << endl;
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
			cout << "잘못된 입력입네다." << endl;
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
		if (chArray[i].identity == 34) //살인자가 무조건 첫번째에 출현합니다.

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
		cout << "\n무슨 행동을 하시겠습니까?" << endl;
		cout << "0.규정집 확인   1.립국 거부   2.립국 허가   4.여권 확인   5.취조   8.규정집:허가서   9.규정집:국가 정보" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "잘못된 입력입네다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==「규 정」==" << endl;
			cout << "1. 립국자는 려권을 소지해야함" << endl;
			cout << "2. 려권의 만료일자가 유효해야함." << endl;
			cout << "3. 려권의 번호는 숫자와 영문자의 조합 총 10글자임." << endl;
			cout << "4. 려권의 국가와 도시가 유효해야함." << endl;
			cout << "5. 립국 표는 더이상 사용하지 않음" << endl;

			continue;
		}
		else if (flag == 8)
		{
			cout << "==「규정:허가서 관련」==" << endl;
			cout << "6. 외국인은 립국 허가서가 필요함" << endl;
			cout << "-립국 허가서는 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 입국 허가서-" << endl;
			cout << "여권 번호:(여권과 일치하는지 확인)" << endl;
			cout << "입국 목적:" << endl;
			cout << "입국 날짜:(오늘이어야 함)" << endl;
			cout << "=============================" << endl;

			cout << "\n7. 우리 국민은 신분증이 필요함" << endl;
			cout << "-신분증은 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 신분 인증서" << endl;
			cout << "이름:(여권과 일치 확인)" << endl;
			cout << "생년 월일:(여권과 일치 확인)" << endl;
			cout << "거주지:(여권과 일치 확인)" << endl;
			cout << "=============================" << endl;

			cout << "\n8. 외국인 립국 목적이 '일' 이라면 로동 허가서가 필요함" << endl;
			cout << "-로동 허가서는 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 로동 허가서-" << endl;
			cout << "이름:(여권과 일치 확인)" << endl;
			cout << "허가 일자:(오늘 날짜와 일치 확인)" << endl;
			cout << "=============================" << endl;
		}
		else if (flag == 9)
		{
			cout << "==규정:국가 정보==" << endl;
			cout << "아스토르츠카 - 도시 : 오베크 버너 / 그레스틴  / 파라디즈나" << endl;
			cout << "콜레치아 - 도시 : 유르코 / 베더 / 유주" << endl;
			cout << "안테그리아 - 도시 : 세인트 마메로 / 글로리안 / 아우터 그로스" << endl;
			cout << "리퍼블리아 - 도시 : 트루 글로리안 / 레스레나디 / 보스탄" << endl;
			cout << "오브리스탄 - 도시 : 스칼 / 론다즈 / 머저스" << endl;
			cout << "임포르 - 도시 : 은키오 / 하이한 / 슨케이도" << endl;
			cout << "연합 연방 - 도시 : 그레이트 래피드 / 싱레튼 / 코리스타 시티" << endl;

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
				if (chArray[i].identity == 34)// 입국시키건 말건 패널티가 없다.
				{
					chArray[i].chara_talk_deny();
					gs->add_total_deny();
					break;
				}
				gs->new_mistake();
				cout << "규약 위반 : 립국에 문제가 없는 신청자" << endl;
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
					cout << "규약 위반 : 유효하지 않은 로동 허가서" << endl;
				}
				else if (chArray[i].identity == 39 || chArray[i].identity == 41)
				{
					cout << "규약 위반 : 유효하지 않은 허가서" << endl;
				}
				else if (chArray[i].identity == 40)
				{
					cout << "규약 위반 : 유효하지 않은 신분증" << endl;
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
			cout << "잘못된 입력입네다." << endl;
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
		if (chArray[i].identity == 47) //코난 아조씨가 (부부이벤트) 무조건 첫번째에 출현합니다.

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
		cout << "\n무슨 행동을 하시겠습니까?" << endl;
		cout << "0.규정집 확인   1.립국 거부   2.립국 허가   3.구금   4.여권 확인   5.취조   8.규정집:허가서   9.규정집:국가 정보" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "잘못된 입력입네다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==「규 정」==" << endl;
			cout << "1. 립국자는 려권을 소지해야함" << endl;
			cout << "2. 려권의 만료일자가 유효해야함." << endl;
			cout << "3. 려권의 번호는 숫자와 영문자의 조합 총 10글자임." << endl;
			cout << "4. 려권의 국가와 도시가 유효해야함." << endl;
			cout << "5. 립국 표는 더이상 사용하지 않음" << endl;
			cout << "6. 수상한 자는 망설임 없이 구금하시오." << endl;

			continue;
		}
		else if (flag == 8)
		{
			cout << "==「규정:허가서 관련」==" << endl;
			cout << "7. 외국인은 립국 허가서가 필요함" << endl;
			cout << "-립국 허가서는 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 입국 허가서-" << endl;
			cout << "여권 번호:(여권과 일치하는지 확인)" << endl;
			cout << "입국 목적:" << endl;
			cout << "입국 날짜:(오늘이어야 함)" << endl;
			cout << "=============================" << endl;

			cout << "\n8. 우리 국민은 신분증이 필요함" << endl;
			cout << "-신분증은 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 신분 인증서" << endl;
			cout << "이름:(여권과 일치 확인)" << endl;
			cout << "생년 월일:(여권과 일치 확인)" << endl;
			cout << "거주지:(여권과 일치 확인)" << endl;
			cout << "=============================" << endl;

			cout << "\n9. 외국인 립국 목적이 '일' 이라면 로동 허가서가 필요함" << endl;
			cout << "-로동 허가서는 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 로동 허가서-" << endl;
			cout << "이름:(여권과 일치 확인)" << endl;
			cout << "허가 일자:(오늘 날짜와 일치 확인)" << endl;
			cout << "=============================" << endl;
		}
		else if (flag == 9)
		{
			cout << "==규정:국가 정보==" << endl;
			cout << "아스토르츠카 - 도시 : 오베크 버너 / 그레스틴  / 파라디즈나" << endl;
			cout << "콜레치아 - 도시 : 유르코 / 베더 / 유주" << endl;
			cout << "안테그리아 - 도시 : 세인트 마메로 / 글로리안 / 아우터 그로스" << endl;
			cout << "리퍼블리아 - 도시 : 트루 글로리안 / 레스레나디 / 보스탄" << endl;
			cout << "오브리스탄 - 도시 : 스칼 / 론다즈 / 머저스" << endl;
			cout << "임포르 - 도시 : 은키오 / 하이한 / 슨케이도" << endl;
			cout << "연합 연방 - 도시 : 그레이트 래피드 / 싱레튼 / 코리스타 시티" << endl;

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
				cout << "규약 위반 : 립국에 문제가 없는 신청자" << endl;
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
					cout << "규약 위반 : 유효하지 않은 려권" << endl;
				}
				else if (chArray[i].identity == 48 || chArray[i].identity == 50)
				{
					cout << "규약 위반 : 유효하지 않은 허가서" << endl;
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
			cout << "규약 위반 : 립국에 문제가 없는 신청자" << endl;
			cout << "==================================" << endl;
		}
		else
		{
			gs->add_success();

		}
		cout << "경비병 : 따라오라우 동무" << endl;
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
			cout << "잘못된 입력입네다." << endl;
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
		if (chArray[i].identity == 52) //콜레치아의 외교관이 첫번째로 등장합니다.

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
		cout << "\n무슨 행동을 하시겠습니까?" << endl;
		cout << "0.규정집 확인   1.립국 거부   2.립국 허가   3.구금   4.여권 확인   5.취조   7.특별규정:외교관   8.규정집:허가서   9.규정집:국가 정보" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "잘못된 입력입네다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==「규 정」==" << endl;
			cout << "1. 립국자는 려권을 소지해야함" << endl;
			cout << "2. 려권의 만료일자가 유효해야함." << endl;
			cout << "3. 려권의 번호는 숫자와 영문자의 조합 총 10글자임." << endl;
			cout << "4. 려권의 국가와 도시가 유효해야함." << endl;
			cout << "5. 립국 표는 더이상 사용하지 않음" << endl;
			cout << "6. 수상한 자는 망설임 없이 구금하시오." << endl;

			continue;
		}
		else if (flag == 7)
		{
			cout << "==「규정:외교관 관련」==" << endl;
			cout << "외교관은 려권과 유효한 외교관 권한서만 있으면 립국할 수 있음" << endl;
			cout << "외교관은 립국 허가서가 없어도 됨" << endl;
			cout << "-외교관 권한서는 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「국가 이름」" << endl;
			cout << "=외교관 인증서=" << endl;
			cout << "에이전트 이름:(여권과 일치하는지 확인)" << endl;
			cout << "여권 번호:(여권과 일치하는지 확인)" << endl;
			cout << "방문 국가:('아스토르츠카'이어야 함)" << endl;
			cout << "-이 문서는 만료일이 없으며, 국가의 보호를 받습니다-" << endl;
			cout << "=============================" << endl;
			cout << "\n외교관은 절대 구금시키지 말 것." << endl;
		}
		else if (flag == 8)
		{
			cout << "==「규정:허가서 관련」==" << endl;
			cout << "7. 외국인은 립국 허가서가 필요함" << endl;
			cout << "-립국 허가서는 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 입국 허가서-" << endl;
			cout << "여권 번호:(여권과 일치하는지 확인)" << endl;
			cout << "입국 목적:" << endl;
			cout << "입국 날짜:(오늘이어야 함)" << endl;
			cout << "=============================" << endl;

			cout << "\n8. 우리 국민은 신분증이 필요함" << endl;
			cout << "-신분증은 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 신분 인증서" << endl;
			cout << "이름:(여권과 일치 확인)" << endl;
			cout << "생년 월일:(여권과 일치 확인)" << endl;
			cout << "거주지:(여권과 일치 확인)" << endl;
			cout << "=============================" << endl;

			cout << "\n9. 외국인 립국 목적이 '일' 이라면 로동 허가서가 필요함" << endl;
			cout << "-로동 허가서는 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 로동 허가서-" << endl;
			cout << "이름:(여권과 일치 확인)" << endl;
			cout << "허가 일자:(오늘 날짜와 일치 확인)" << endl;
			cout << "=============================" << endl;
		}
		else if (flag == 9)
		{
			cout << "==규정:국가 정보==" << endl;
			cout << "아스토르츠카 - 도시 : 오베크 버너 / 그레스틴  / 파라디즈나" << endl;
			cout << "콜레치아 - 도시 : 유르코 / 베더 / 유주" << endl;
			cout << "안테그리아 - 도시 : 세인트 마메로 / 글로리안 / 아우터 그로스" << endl;
			cout << "리퍼블리아 - 도시 : 트루 글로리안 / 레스레나디 / 보스탄" << endl;
			cout << "오브리스탄 - 도시 : 스칼 / 론다즈 / 머저스" << endl;
			cout << "임포르 - 도시 : 은키오 / 하이한 / 슨케이도" << endl;
			cout << "연합 연방 - 도시 : 그레이트 래피드 / 싱레튼 / 코리스타 시티" << endl;

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
				cout << "규약 위반 : 립국에 문제가 없는 신청자" << endl;
				cout << "==================================" << endl;

				if (chArray[i].identity == 52 && Game_events::first_spy_mission)
				{
					Game_events::diploma_spy_mission_clear = false;
					cout << "\n\n상대 : 이제 와서 결사를 배신하겠다는 건가?" << endl;
					Sleep(500);
					cout << "상대 : 이건 멍청한 짓이네..." << endl;
					Sleep(500);
				}
				else if (chArray[i].identity == 52 || chArray[i].identity == 53)
				{
					cout << "\n\n상대 : 허, 아스토르츠카에서 외교관 관련 공문이 내려오지 않았나?" << endl;
					Sleep(500);
					cout << "상대 : 일처리 하고는..." << endl;
					Sleep(500);
					cout << "상대 : 내 알아서 입국하겠소, 수고하시오." << endl;
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
					cout << "규약 위반 : 유효하지 않은 허가서" << endl;
				}
				else if (chArray[i].identity == 59)
				{
					cout << "규약 위반 : 유효하지 않은 려권" << endl;
				}
				else if (chArray[i].identity == 57)
				{
					cout << "규약 위반 : 문서 불일치" << endl;
				}
				else if (chArray[i].identity == 51)
				{
					cout << "규약 위반 : 유효하지 않은 로동 허가서" << endl;
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
				cout << "규약 위반 : 립국에 문제가 없는 신청자" << endl;
				cout << "==================================" << endl;

				if (chArray[i].identity == 52 || chArray[i].identity == 53)
				{
					gs->new_mistake();
					cout << "\n\n상대 : 타국의 외교관을 구금하겠다고?" << endl;
					Sleep(500);
					cout << "상대 : 당신네들 정말 미쳤군!" << endl;
					Sleep(500);
					cout << "상대 : 아스토르츠카 외교성에 직접 의의를 신청하겠소" << endl;
					Sleep(1000);
					cout << "경비병 : 기... 기다려 보라우..." << endl;
					Sleep(1000);
					cout << "당신 : ......." << endl;
					Sleep(1000);
					cout << "경비병 : ......" << endl;
					Sleep(1000);
					cout << "(련락관이 조취를 취하고 있다. 오래 기다려야 할 것 같다.)" << endl;
					Sleep(5000);
					cout << "외교관 : 아스토르츠카, 이 모욕은 기억하겠소" << endl;
					Sleep(1000);
					cout << "경비병 : 정말 죄송합네다. 신원이 확인되었습네다." << endl;
					Sleep(1000);
					cout << "당신 : 정말 죄송합네다" << endl;
					Sleep(500);
					cout << "외교관 : ......(뒤도 돌아보지 않고 떠났다.)" << endl;
					Sleep(500);
					cout << "련락관 : 동무, 이번 실수는 경고 2회를 누적하겠네..." << endl;
					Sleep(1000);
				}
			}
			else
			{
				gs->add_success();

			}
			cout << "\n경비병 : 수고하라우 동무" << endl;
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
			cout << "잘못된 입력입네다." << endl;
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
		if (chArray[i].identity == 61) //콜레치아의 외교관이 첫번째로 등장합니다.

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
		cout << "\n무슨 행동을 하시겠습니까?" << endl;
		cout << "0.규정집 확인   1.립국 거부   2.립국 허가   3.구금   4.여권 확인   5.취조   8.규정집:허가서   9.규정집:국가 정보" << endl;
		cin >> flag;
		if (cin.fail())
		{
			cout << "잘못된 입력입네다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 0)
		{
			cout << "==「규 정」==" << endl;
			cout << "1. 립국자는 려권을 소지해야함" << endl;
			cout << "2. 려권의 만료일자가 유효해야함." << endl;
			cout << "3. 려권의 번호는 숫자와 영문자의 조합 총 10글자임." << endl;
			cout << "4. 려권의 국가와 도시가 유효해야함." << endl;
			cout << "5. 립국 표는 더이상 사용하지 않음" << endl;
			cout << "6. 수상한 자는 망설임 없이 구금하시오." << endl;

			continue;
		}
		else if (flag == 8)
		{
			cout << "==「규정:허가서 관련」==" << endl;
			cout << "7. 외국인은 립국 허가서가 필요함" << endl;
			cout << "-립국 허가서는 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 입국 허가서-" << endl;
			cout << "여권 번호:(여권과 일치하는지 확인)" << endl;
			cout << "입국 목적:" << endl;
			cout << "입국 날짜:(오늘이어야 함)" << endl;
			cout << "=============================" << endl;

			cout << "\n8. 우리 국민은 신분증이 필요함" << endl;
			cout << "-신분증은 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 신분 인증서" << endl;
			cout << "이름:(여권과 일치 확인)" << endl;
			cout << "생년 월일:(여권과 일치 확인)" << endl;
			cout << "거주지:(여권과 일치 확인)" << endl;
			cout << "=============================" << endl;

			cout << "\n9. 외국인 립국 목적이 '일' 이라면 로동 허가서가 필요함" << endl;
			cout << "-로동 허가서는 다음과 같은 형태임" << endl;
			cout << "\n=============================" << endl;
			cout << "「아스토르츠카」" << endl;
			cout << "-아스토르츠카 로동 허가서-" << endl;
			cout << "이름:(여권과 일치 확인)" << endl;
			cout << "허가 일자:(오늘 날짜와 일치 확인)" << endl;
			cout << "=============================" << endl;
		}
		else if (flag == 9)
		{
			cout << "==규정:국가 정보==" << endl;
			cout << "아스토르츠카 - 도시 : 오베크 버너 / 그레스틴  / 파라디즈나" << endl;
			cout << "콜레치아 - 도시 : 유르코 / 베더 / 유주" << endl;
			cout << "안테그리아 - 도시 : 세인트 마메로 / 글로리안 / 아우터 그로스" << endl;
			cout << "리퍼블리아 - 도시 : 트루 글로리안 / 레스레나디 / 보스탄" << endl;
			cout << "오브리스탄 - 도시 : 스칼 / 론다즈 / 머저스" << endl;
			cout << "임포르 - 도시 : 은키오 / 하이한 / 슨케이도" << endl;
			cout << "연합 연방 - 도시 : 그레이트 래피드 / 싱레튼 / 코리스타 시티" << endl;

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
					cout << "\n\n상대 : 이제 와서 결사를 배신하겠다는 건가?" << endl;
					Sleep(500);
					cout << "상대 : 이건 멍청한 짓이네..." << endl;
					Sleep(500);
				}
				cout << "규약 위반 : 립국에 문제가 없는 신청자" << endl;
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
					cout << "규약 위반 : 유효하지 않은 려권" << endl;
				}
				else if (chArray[i].identity == 48 || chArray[i].identity == 50)
				{
					cout << "규약 위반 : 유효하지 않은 허가서" << endl;
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
				cout << "규약 위반 : 립국에 문제가 없는 신청자" << endl;
				cout << "==================================" << endl;
			}
			else
			{
				gs->add_success();

			}
			cout << "경비병 : 따라오라우 동무" << endl;
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
			cout << "잘못된 입력입네다." << endl;
			continue;
		}
	}
	Game_events::chara_first_talk = true;
}