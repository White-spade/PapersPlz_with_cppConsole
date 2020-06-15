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
	cout << "======= 국경 관리성 고지문 =======" << endl;
	if (mistake == 0)
		cout << "「경고발급 - 벌금 없음」" << endl;
	else if (mistake == 1)
		cout << "「마지막 경고 - 벌금없음」" << endl;
	else
		cout << "「벌금부과 예정」" << endl;

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
	//result 출력
	char flag;
	cout << "\n\n---------------------" << stage << "일 차" << "----------------------" << endl;
	cout << "저축금 :" << money << endl;
	cout << "봉급 : 100 x " << success << "(금일 처리 업무) = " << success * 100 << endl; money += (success * 100);
	if (stage < 6)
	{
		cout << "집세 : -200" << endl;
		money -= 200;
	}
	else
	{
		cout << "집세 : -300 (100이나 오르다니...)" << endl;
		money -= 300;
	}
	if (Game_events::request_of_friend)
	{
		Game_events::request_of_friend = false;
		cout << "친구의 답례 :100" << endl;
		money += 100;
	}
	if (mistake >= 3 && today_mistake >0)
	{
		if (mistake >= 5)
		{
			cout << "과도한 업무 실패 벌금 : -100x" << today_mistake << " = " << -100 * today_mistake << endl;
			money -= (100 * today_mistake);
		}
		else
		{
			cout << "업무 실패 벌금 : -50x" << today_mistake << " = " << -50 * today_mistake << endl;
			money -= (50 * today_mistake);
		}
	}
	if (stage >= 6)
	{
		cout << "체포수당 : 50x" << detain_pass << "(구금한 사람 수) = " << 50 * detain_pass << endl;
		money += 50 * detain_pass;
	}
	cout << "-------------------------------------------------" << endl;
	cout << "현재 남은 금액 : " << money << "\n" << endl;
	cout << "\ny를 입력해 비용을 지불할 수 있습네다. \n현명한 소비로 가정을 구원하시라요." << endl;

	if (house_is_cold)
		cout << "\n집이 춥습니다. \n난방비를 내지 않으면 가족이 병에 걸릴 수 있습니다." << endl;

	if (family_critical)
	{
		cout << "\n병에 걸렸던 가족이 위독합니다. \n치료비는 100원입니다만, 치료하지 않으면 아마 사망할 것입네다." << endl;
		cout << "치료하시겠습네까? y/n" << endl;
		while (true)
		{
			cin >> flag;
			if (cin.fail())
			{
				cout << "잘못된 입력입네다." << endl;
				cin.clear();
				cin.ignore(256, '\n');
				continue;
			}
			if (flag == 'y')
			{
				cout << "치료를 결정했습네다. \n가족을 이렇게 떠나보낼 수는 없습네다." << endl;
				money -= 100;
				family_critical = false;
				break;
			}
			else if (flag == 'n')
			{
				cout << "어쩔 수 없는 선택이었습네다." << endl;
				cout << "가족 한명이 곁을 떠났습니다." << endl;
				family_count--;
				family_critical = false;
				break;
			}
			else
			{
				cout << "잘못된 입력입네다." << endl;
			}
		}
		cout << "-------------------------------------------------" << endl;
		cout << "현재 남은 금액 : " << money << "\n" << endl;
	}

	if (family_cold)
	{
		cout << "\n가족중 한명이 감기에 걸렸습니다. 감기약은 50원입네다." << endl;
		cout << "치료하시겠습네까? y/n" << endl;
		while (true)
		{
			cin >> flag;
			if (flag == 'y')
			{
				cout << "가족에게 약을 지급했습네다. \n곧 건강해 질 것입네다." << endl;
				family_cold = false;
				break;
			}
			else if (flag == 'n')
			{
				cout << "어쩔 수없는 선택이었습네다." << endl;
				family_cold = false;
				family_critical = true;
				break;
			}
			else
			{
				cout << "잘못된 입력입네다." << endl;
			}
		}
		cout << "-------------------------------------------------" << endl;
		cout << "현재 남은 금액 : " << money << endl;
	}

	cout << "\n식비 : -50 x " << family_count << "(가족 수) = " << family_count * -50 << endl;
	cout << "식비를 지불하지 않으면 가족이 사망할 수 있습니다. \n지불하시겠습니까? y/n" << endl;
	while (true)
	{
		cin >> flag;
		if (cin.fail())
		{
			cout << "잘못된 입력입네다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 'y')
		{
			cout << "식비를 지불했습네다. \n당신의 가족은 굶주리지 않을 것입네다." << endl;
			money -= (50 * family_count);
			break;
		}
		else if (flag == 'n')
		{
			cout << "식비를 지불하지 않기로 했습네다." << endl;
			cout << "가족 한명이 곁을 떠났습니다." << endl;
			family_count--;
			break;
		}
		else
		{
			cout << "잘못된 입력입네다." << endl;
		}
	}
	cout << "-------------------------------------------------" << endl;
	cout << "현재 남은 금액 : " << money << "\n" << endl;

	cout << "\n난방비 : -100" << endl;
	cout << "난방비를 지불하지 않으면 가족이 감기에 걸릴 수 있습니다. \n지불하시겠습니까? y/n" << endl;
	while (true)
	{
		cin >> flag;
		if (cin.fail())
		{
			cout << "잘못된 입력입네다." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		if (flag == 'y')
		{
			cout << "난방비를 지불했습네다. \n당신의 가족은 따듯하게 지낼 것입네다." << endl;
			house_is_cold = false;
			money -= 100;
			break;
		}
		else if (flag == 'n')
		{
			cout << "난방비를 지불하지 않기로 했습네다." << endl;
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
			cout << "잘못된 입력입네다." << endl;
		}
	}
	cout << "-------------------------------------------------" << endl;
	cout << "현재 남은 금액 : " << money << "\n" << endl;

	Sleep(1000);
	cout << "\n\n다음날이 밝았습니다 \n\n" << endl;
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
//부부손님 남편 x문제 아내 문제
bool Game_events::diploma_spy_mission_clear = true;
bool Game_events::last_spy_mission_clear = true;


//define Game stories「」
void Game_stories::game_intro(int n)
{
	if (n == 1)
	{
		cout << "축하합네다." << endl;
		Sleep(2000);
		cout << "11월 로동 복권에서 동무의 이름이 뽑혔습네다.\n" << endl;
		Sleep(2000);
		cout << "국가 검열성은 그레스틴 국경 검문소에 즉각 인원 배치가 필요함을 보고받았습네다.\n" << endl;
		Sleep(2000);
		cout << "동무의 가족들을 위해 차단소 근처에 살림집이 지급되었습네다." << endl;
		cout << "8등급 연립주택 입네다." << endl;
		cout << "로동을 통해 국가에 이바지하기를 바랍네다.\n" << endl;
		Sleep(4000);
		cout << "위대한 국가, 아스토르츠카에 영광을!\n" << endl;
		Sleep(2500);

		cout << "==========================로동 신문==========================" << endl;
		cout << "|\n|1982년 11월 23일\n|" << endl;
		cout << "|「그레스틴의 국경 검문소 마침내 개방되다!」" << endl;
		cout << "|-6년만에 개방된 국경, 안전을 보장할 수 있는가?-" << endl;
		cout << "|......" << endl;
		cout << "|        「가족들을 다시 만나다」......" << endl;
		cout << "|......" << endl;
		cout << "|「심각한 취업난.. 공평한 로동을 위한 로동 복권 도입. 」" << endl;
		cout << "|......" << endl;
		cout << "=============================================================\n\n\n" << endl;

		Sleep(5000);

		cout << "=============================================================" << endl;
		cout << "아스토르츠카 1982.11.23" << endl;
		cout << "국가 검열성 공식 공고\n" << endl;
		cout << "검문관, 국경 차단소의 새 직책을 맡게 된 것을 환영합네다." << endl;
		cout << "려권과 문서들을 확인하고 립국 허가를 내려주는것이 당신의 주 업무입네다.\n" << endl;
		cout << "립국 허가는 아스토르츠카의 인민들로 제한됩네다." << endl;
		cout << "따라서 모든 외국인들에 대해서는 립국을 불허합네다.\n" << endl;
		cout << "위대한 국가, 아스토르츠카에 영광을!\n" << endl;
		cout << "-아스토르츠카 정치국-" << endl;
		cout << "=============================================================" << endl;
	}
	else if (n == 2)
	{
		cout << "==========================로동 신문==========================" << endl;
		cout << "|\n|1982년 11월 24일\n|" << endl;
		cout << "|「성공적이었던 국경 검문소!」" << endl;
		cout << "|-립국 제한을 완화하고, 외국인을 받아들인다-" << endl;
		cout << "|......" << endl;
		cout << "|「낙관적인 분석. 」" << endl;
		cout << "|-무역과 협력이 증가될거라 예측돼-" << endl;
		cout << "|        「날씨」......" << endl;
		cout << "|......" << endl;
		cout << "|......" << endl;
		cout << "=============================================================\n\n\n" << endl;

		Sleep(5000);

		cout << "=============================================================" << endl;
		cout << "아스토르츠카 1982.11.24" << endl;
		cout << "국가 검열성 공식 공고\n" << endl;
		cout << "검문관, 오늘부터 유효한 려권을 가지고 온 외국인들은 립국이 허가됩네다.\n" << endl;
		cout << "려권의 모든 정보를 주의깊게 살펴 잘못된 것이 없는지 확인하시오" << endl;
		cout << "일치하지 않는 정보가 기재된 립국자들은 모두 불허하시오\n" << endl;
		cout << "의심스러운 자들은 취조를 통해 걸러내시오" << endl;
		cout << "국가 검열성의 규정과 법령이 헷갈린다면 규정집을 찬찬히 살펴보시오" << endl;
		cout << "\n위대한 국가, 아스토르츠카에 영광을!\n" << endl;
		cout << "-아스토르츠카 정치국-" << endl;
		cout << "=============================================================" << endl;
	}
	else if (n == 3)
	{
		cout << "==========================로동 신문==========================" << endl;
		cout << "|\n|1982년 11월 25일\n|" << endl;
		cout << "|「콜레치아 출신 반동분자의 공격!」" << endl;
		cout << "|-그레스틴 지방에서 활동하던 콜레치아 출신 선동가, 붙잡히다.-" << endl;
		cout << "|......" << endl;
		cout << "|「검문소 봉쇄 」" << endl;
		cout << "|-많아진 경비원, 어려워진 입국심사-" << endl;
		cout << "|        「날씨」......" << endl;
		cout << "|......" << endl;
		cout << "|......" << endl;
		cout << "=============================================================\n\n\n" << endl;

		Sleep(10000);

		cout << "=============================================================" << endl;
		cout << "아스토르츠카 1982.11.25" << endl;
		cout << "국가 검열성 공식 공고\n" << endl;
		cout << "검문관, 이제 모든 립국은 규제됩네다.\n" << endl;
		cout << "모든 인민들은 유효한 립국 표가 필요합네다." << endl;
		cout << "립국 표가 없다면 외국민 자국민 모두, 입국을 불허하시오\n" << endl;
		cout << "\n위대한 국가, 아스토르츠카에 영광을!\n" << endl;
		cout << "-아스토르츠카 정치국-" << endl;
		cout << "=============================================================\n\n\n" << endl;

		Sleep(10000);
		cout << "=============================================================" << endl;
		cout << "친애하는 동무여, 동무가 그레스틴 검문소에서 로동한다는 소식을 듣고" << endl;
		cout << "내 무례함을 무릅쓰고 이렇게 몰래 쪽지를 보내네" << endl;
		cout << "반동분자의 공격으로 인해 립국이 어려워졌다는 소식을 들었네," << endl;
		cout << "하지만 오늘은 몇 십년간 헤어졌던 나의 아버지가 돌아오는 날일세." << endl;
		cout << "'리 광수' 라는 중후한 신사가 립국장으로 들어온다면, 부디, 통과시켜주게" << endl;
		cout << "이 은혜는 평생 잊지 않겠네. \n-당신의 오랜 동무로부터" << endl;
		cout << "=============================================================" << endl;

	}
	else if (n == 4)
	{
	cout << "==========================로동 신문==========================" << endl;
	cout << "|\n|1982년 11월 26일\n|" << endl;
	cout << "|「차단소 확장이 연기」" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
	cout << "|「암시장 규모 증가돼 」" << endl;
	cout << "|-국경 개방은 독인가, 약인가-" << endl;
	cout << "|        「운동 경기」......" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
	cout << "=============================================================\n\n\n" << endl;

	Sleep(5000);

	cout << "=============================================================" << endl;
	cout << "아스토르츠카 1982.11.26" << endl;
	cout << "국가 검열성 공식 공고\n" << endl;
	cout << "검문관, 엄격한 자격 요건이 제정되었습네다.\n" << endl;
	cout << "모든 자국 인민들은 반드시 신분증을 보여야 합네다." << endl;
	cout << "외국인들은 안전하고 유효한 립국 허가서를 가지고 있어야 합네다.\n" << endl;
	cout << "이전의 립국표는 더이상 사용하지 않습니다.\n" << endl;
	cout << "\n위대한 국가, 아스토르츠카에 영광을!\n" << endl;
	cout << "-아스토르츠카 정치국-" << endl;
	cout << "=============================================================\n\n\n" << endl;
		if (Game_events::request_of_friend)
		{
			Sleep(5000);
			cout << "=============================================================" << endl;
			cout << "친애하는 동무여, 내 이 고마움을 어떻게 표현해야 할 지 모르겠네." << endl;
			cout << "아버지는 검문을 한번 더 당하셨지만" << endl;
			cout << "지금은 나와 같이 집에 돌아오셨네" << endl;
			cout << "머지 않아 내 술 한병 사들고 보러 감세" << endl;
			cout << "내 이것으로 이 은혜를 다 갚을 수는 없겠지만,그저 작은 성의일세" << endl;
			cout << "이 은혜는 평생 잊지 않겠네. \n-당신의 오랜 동무로부터" << endl;
			cout << "(쪽지 속에 약간의 돈이 들어있다.)" << endl;
			cout << "=============================================================" << endl;
		}
	}
	else if (n == 5)
	{
	cout << "==========================로동 신문==========================" << endl;
	cout << "|\n|1982년 11월 27일\n|" << endl;
	cout << "|「리퍼블리아 유명 육상선수가 살인죄로 수배!」" << endl;
	cout << "|-핑 찐쉬에의 행방 묘연, 리퍼블리아에서 도망친 것으로 추정-" << endl;
	cout << "|.....핑 찐쉬에의 인물 정보..." << endl;
	cout << "|....질투에 못이겨 여자친구를 살해했나?-" << endl;
	cout << "|......" << endl;
	cout << "|「취업난, 일자리 더욱 줄어들어」" << endl;
	cout << "|-이민문제, 일자리 쟁탈이 심각해...-" << endl;
	cout << "|        「정치」......" << endl;
	cout << "|......" << endl;
	cout << "=============================================================\n\n\n" << endl;

	Sleep(5000);

	cout << "=============================================================" << endl;
	cout << "아스토르츠카 1982.11.27" << endl;
	cout << "국가 검열성 공식 공고\n" << endl;
	cout << "검문관, 로동성에서 이주 로동을 제어하기위해," << endl;
	cout << "특별 프로그램을 제정했습네다.\n" << endl;
	cout << "로동을 위해 립국하고자 하는 여행자는" << endl;
	cout << "유효한 로동 허가서가 필요합네다.\n" << endl;
	cout << "\n위대한 국가, 아스토르츠카에 영광을!\n" << endl;
	cout << "-아스토르츠카 정치국-" << endl;
	cout << "=============================================================\n\n\n" << endl;
	}
	else if (n == 6)
	{
	cout << "==========================로동 신문==========================" << endl;
	cout << "|\n|1982년 11월 28일\n|" << endl;
	cout << "|「조선 차단소. 또 다시 공격받다!」" << endl;
	cout << "|-허술한 보안 틈새로 반동분자가 자폭해...-" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
		if(Game_events::murder_pass_event)
		{
			cout << "|「핑 찐쉬에, 그레스틴에서 체포되다」" << endl;
			cout << "|-유명 선수에서 흉악한 범죄자로-" << endl;
		}
		else
		{
			cout << "|「핑 찐쉬에 : 아스토츠카, 콜레치아 지방에서 목격」" << endl;
			cout << "|-국가 단위의 수배중-" << endl;
		}
		cout << "|        「정치」......" << endl;
		cout << "|......" << endl;
		cout << "|......" << endl;
		cout << "=============================================================\n\n\n" << endl;

	Sleep(5000);

	cout << "=============================================================" << endl;
	cout << "아스토르츠카 1982.11.28" << endl;
	cout << "국가 검열성 공식 공고\n" << endl;
	cout << "검문관,정보성에서 당신에게 특수한 권한을 주기로 했습네다.\n" << endl;
	cout << "동무는 의심스러운 사람을 구금시킬 권한이 생겼습네다." << endl;
	cout << "국가 검열성이 련락 담당관을 두기로 했습네다.\n" << endl;
	cout << "오늘 내로 련락관이 방문할 예정이니 기다리시오.\n" << endl;
	cout << "\n위대한 국가, 아스토르츠카에 영광을!\n" << endl;
	cout << "-아스토르츠카 정치국-" << endl;
	cout << "=============================================================\n\n\n" << endl;
	Sleep(5000);

	cout << "??? : 안녕하신가." << endl;
	Sleep(1500);
	cout << "경비병 : 내가 이번에 새로 온 련락관이자 경비병이라우." << endl;
	Sleep(1500);
	cout << "경비병 : 노른자위 같은 보직으로 발령받은 줄 알았는데, 겨우 여기로군." << endl;
	Sleep(1500);
	cout << "당신 : 당신 봉급이야 차고 넘치잖나." << endl;
	Sleep(1500);
	cout << "경비병 : 꼭 그런건 아니라우, 나한테는 체포 수당이라는 게 떨어지거든" << endl;
	Sleep(1500);
	cout << "경비병 : 더 많은 사람을 체포할수록 주머니가 두둑해지지." << endl;
	Sleep(1500);
	cout << "경비병 : 허나 불공평하잖나? 내, 동무에게도 떡고물을 주겠네." << endl;
	Sleep(1500);
	cout << "경비병 : 성과금을 받으면 두당 다섯 장 씩 치도록 하겠네." << endl;
	Sleep(1500);
	cout << "경비병 : 일없는 조건이잖나. 무슨소린지 알아들었으리라 믿네, 동무" << endl;
	Sleep(1500);
	cout << "당신 : ......." << endl;
	Sleep(1500);
	cout << "경비병 : 같이 돈 좀 벌어보세나, 그럼 이만." << endl;
	}
	else if (n == 7)
	{
	cout << "==========================로동 신문==========================" << endl;
	cout << "|\n|1982년 11월 29일\n|" << endl;
	cout << "|「각국 령도자가 불만을 표하다」" << endl;
	cout << "|-오늘 아스트로츠카에서 고위급 회담 성사-" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
	cout << "|「아스트로츠카의 경제 악화」" << endl;
	cout << "|-악화되는 경제, 해결책은 있는가?-" << endl;
	cout << "|        「정치」......" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
	cout << "=============================================================\n\n\n" << endl;

	Sleep(5000);

	cout << "=============================================================" << endl;
	cout << "아스토르츠카 1982.11.29" << endl;
	cout << "국가 검열성 공식 공고\n" << endl;
	cout << "검문관," << endl;
	cout << "오늘 외교관들이 고위급 회담을 위해 도착할 예정입네다." << endl;
	cout << "외교관들은 립국에 있어 려권과 유효한 외교관 권한서만 있으면 됩네다." << endl;
	cout << "규정집의 갱신된 문서 정보를 확인해 보시라요." << endl;
	cout << "\n위대한 국가, 아스토르츠카에 영광을!\n" << endl;
	cout << "-아스토르츠카 정치국-" << endl;
	cout << "=============================================================\n\n\n" << endl;
	}
	else if (n == 8)
	{
	cout << "==========================로동 신문==========================" << endl;
	cout << "|\n|1982년 11월 30일\n|" << endl;
	cout << "|「콜레치아 최 고위 외교관은 간첩으로 밝혀져!!」" << endl;
	cout << "|-국경에서부터 행방 묘연, 사망으로 추정-" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
	cout << "|「날씨」" << endl;
	cout << "|......" << endl;
	cout << "|        「정치」......" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
	cout << "=============================================================\n\n\n" << endl;

	Sleep(5000);

	cout << "=============================================================" << endl;
	cout << "아스토르츠카 1982.11.30" << endl;
	cout << "국가 검열성 공식 공고\n" << endl;
	cout << "검문관," << endl;
	cout << "머지 않아 그레스틴 출입국 허가 부서에서 방문할 예정입네다." << endl;
	cout << "실수 없이 최선을 다하도록 하시오" << endl;
	cout << "\n위대한 국가, 아스토르츠카에 영광을!\n" << endl;
	cout << "-아스토르츠카 정치국-" << endl;
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
		cout << "\n-쾅-!\n" << endl;
		cout << "국경에 누군가 폭탄을 던졌습니다." << endl;
		cout << "경비원 몇 명이 사망하고 검문 줄을 서던 사람들은 모두 도망갔습니다." << endl;
		cout << "반동분자의 공격으로 검문을 급히 마무리 했습니다." << endl;
		Sleep(5000);
	}
	else if (n == 6)
	{
		cout << "당신은 돌아오는 길에 현재 살고있는 건물의 임대료가 올랐다는 소식을 들었습니다.";
	}
	cout << "\n오늘의 업무가 종료되었습니다." << endl;
	Sleep(3000);
}

void Game_stories::start_stage()
{
	cout << "\n\n업무를 시작할 준비가 되었다면 y를 입력해주세요" << endl;
	cout << "입력한 순간부터 시간이 지나갑니다." << endl;
	cout << "한 스테이지는 1분이 소요됩니다." << endl;
	char check;
	while (true)
	{
		cin >> check;
		if (check == 'y')
		{
			cout << "오늘의 업무를 시작합니다.\n\n" << endl;
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
		cout << "국가는 빚을 연체하는 로동자에게 관용을 베풀지 않습네다." << endl;
		Sleep(1000);
		cout << "동무의 가족들은 고향으로 되돌아갔습네다." << endl;
		Sleep(1000);
		cout << "동무는 빚을 상환할 때 까지 아오지에 있을 것입네다." << endl;
		Sleep(1000);
		cout << "대체할 검문관 정도는 널렸습네다." << endl;
		Sleep(1000);
		cout << "\n위대한 국가, 아스토르츠카에 영광을!\n" << endl;
		Sleep(5000);
		cout << "BAD ENDING - DEPT" << endl;
	}
	if (gs->family_count <= 0) //end_bad
	{
		gs->game_over = true;
		cout << "동무의 가족들이 모두 사망했습네다." << endl;
		Sleep(1000);
		cout << "로동성에서는 미래의 일꾼이 될 자녀 양육에 초점을 맞추고 있습네다." << endl;
		Sleep(1000);
		cout << "로동자들에겐 건강한 가족이 요구되는 바 입네다." << endl;
		Sleep(1000);
		cout << "동무의 직책에는 다른 적임자가 배치 될 것입네다." << endl;
		Sleep(1000);
		cout << "\n위대한 국가, 아스토르츠카에 영광을!\n" << endl;
		Sleep(5000);
		cout << "BAD ENDING - FAMILY DEATH" << endl;
	}
	if (Game_events::first_spy_mission) //스파이가 되기로 했을 때
	{
		if (Game_events::first_spy_mission_clear && Game_events::diploma_spy_mission_clear && Game_events::last_spy_mission_clear)
		{//스파이 미션 모두 달성시 end_spy
			gs->game_over = true;
			cout << "검문관, 영광스러운 날입네다!" << endl;
			Sleep(1000);
			cout << "국경의 장벽은 무너졌습네다." << endl;
			Sleep(1000);
			cout << "부패와 탐욕이 모습을 감추고, 정의가 모습을 드러냈습네다." << endl;
			Sleep(1000);
			cout << "동무와 가족에게 쾌적한 주거지를 제공하겠습네다." << endl;
			Sleep(1000);
			cout << "더 이상 검문관으로 일할 필요는 없습네다." << endl;
			Sleep(1000);
			cout << "결사단에 걸맞는 단원이 되어주시라우" << endl;
			Sleep(1000);
			cout << "결사단과 함께 혁명의 과업을 완수합시다!" << endl;
			Sleep(1000);
			cout << "\n새로운 아스토르츠카에 영광을!\n" << endl;
			Sleep(5000);
			cout << "HIDDEN ENDING - MEMBER OF ASSOCIATION" << endl;
		}
		else if ((Game_events::first_spy_mission_clear == false && gs->stage >= 4) || //첫번째 미션 실패
			(Game_events::diploma_spy_mission_clear == false && gs->stage >= 7) || //두번째 미션 실패
			(Game_events::last_spy_mission_clear == false && gs->stage >=8)) //세번째 미션 실패
		{//spy_end_bad
			gs->game_over = true;
			cout << "동무는 의심스러운 단체와 연루되어 체포당했습네다." << endl;
			Sleep(1000);
			cout << "정보성은 동무의 활동에 대해 철저히 조사할 것입네다." << endl;
			Sleep(1000);
			cout << "\n위대한 국가, 아스토르츠카에 영광을!\n" << endl;
			Sleep(5000);
			cout << "BAD ENDING - INCOMPLETE SPY" << endl;
		}
	}
}

void Game_endings::end_normal()
{
	cout << "고위 공무원 :검문관, 20년간 동무의 활동 기록을 감사해봤다우." << endl;
	Sleep(1000);
	cout << "고위 공무원 :몇 가지 문제가 있긴 했네만..." << endl;
	Sleep(1000);
	cout << "고위 공무원 :평생 아스토르츠카를 위해 일해왔잖나." << endl;
	Sleep(1000);
	cout << "고위 공무원 :작은 허물 정도는 일 없을 일이지." << endl;
	Sleep(1000);
	cout << "고위 공무원 :혐의점은 찾아볼 수 없었네." << endl;
	Sleep(1000);
	cout << "고위 공무원 :위대한 아스토르츠카를 위하여." << endl;
	Sleep(1000);
	cout << "\n\n\n==========================로동 신문==========================" << endl;
	cout << "|\n|1982년 12월 1일\n|" << endl;
	cout << "| 「콜레치아와 새로운 협약을 맺다!」" << endl;
	cout << "|......" << endl;
	cout << "| -그레스틴 국경 차단소가 다시 개방될 것-" << endl;
	cout << "|......" << endl;
	cout << "|......" << endl;
	cout << "=============================================================\n\n\n" << endl;
	Sleep(5000);
	cout << "고위 공무원 :앞으로도 잘 부탁합네다 동무." << endl;
	Sleep(1000);
	cout << "\n위대한 국가, 아스토르츠카에 영광을!\n" << endl;
	Sleep(5000);
	cout << "NORMAL ENDING CLEAR!" << endl;
	cout << "숨겨진 엔딩이 있으니 찾아보세요." << endl;
}

void Game_endings::show_last_result(Game_system *gs)
{
	//최종 도달스테이지
	cout << "\n최종 도달 스테이지 :";
	if (gs->stage > 8)
		cout << "8(Final)" << endl;
	else
		cout << gs->stage << endl;
	cout << "남은 가족 수 :" << gs->family_count << endl;
	cout << gs->total_success << "명의 려행객 처리" << endl;
	cout << gs->total_allow_pass << "명 승인" << endl;
	cout << gs->total_deny_pass<< "명 불허" << endl;
	cout << gs->total_detain_pass << "명 구금" << endl;
	cout << gs->mistake << "회 경고" << endl;

	cout << "\n-이 게임과 어체는 컨셉입니다.-" << endl;
	cout << "\n-이 게임은 '3909' 개발사의 'PAPERS, PLEASE'게임의 카피 연습작입니다.-" << endl;
	cout << "Thanks for play!" << endl;
}