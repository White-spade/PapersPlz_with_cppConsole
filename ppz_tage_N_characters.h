#pragma once
using std::string;

//자국민만 통과가능, base class
class Stg_character
{
public:
	int identity;
	string name;
	string dateOfBirth;
	bool gender;

	string nationality;
	string city;
	string passport_expiration;
	string passport_number;

	Stg_character();
	Stg_character(int identity, string name, string dob, bool gender,
		string nationality, string city,
		string p_e, string p_n);

	void show_passport();

	void chara_talk_start();

	void chara_talk_deny();
	void chara_talk_allow();
};

//외국인도 통과가능, integrity (출입불가) 추가
class Stg_character2 : public Stg_character
{
public:
	bool integrity;
	Stg_character2();
	Stg_character2(int idt, string name, string dob, bool gender,
		string nationality, string city,
		string p_e, string p_n, bool integ);
	void interrogation();
};

//vticket필요
class Stg_character3 :public Stg_character2
{
public:
	bool entry_ticket;
	Stg_character3();
	Stg_character3(int idt, string name, string dob, bool gender,
		string nationality, string city,
		string p_e, string p_n, bool integ, bool ntr_tk);
	void show_passport();
};

//ticket 필요없음, 외국인은 허가서, 자국민은 신분증 필요 
//>> 외국인 허가서에 destination //스파이 1차접선
class Stg_character4 : public Stg_character2
{
public:
	string purpose;
	string today_date;
	Stg_character4();
	Stg_character4(int idt, string name, string dob, bool gender,
		string nationality, string city,
		string p_e, string p_n, bool integ, string pps);
	void show_passport();
};

//노동 허가서 필요
class Stg_character5 : public Stg_character4
{
public:
	Stg_character5();
	Stg_character5(int idt, string name, string dob, bool gender,
		string nationality, string city,
		string p_e, string p_n, bool integ, string pps);
	void show_passport();
};

//구금 가능, 구금 수당 추가
class Stg_character6 : public Stg_character5
{
public:
	Stg_character6(int idt, string name, string dob, bool gender,
		string nationality, string city,
		string p_e, string p_n, bool integ, string pps);
	void show_passport();
};

//외교관 등장 , 스파이 2차접선
//chara7 == chara 6
class Stg_character7 : public Stg_character6
{
public:
	Stg_character7(int idt, string name, string dob, bool gender,
		string nationality, string city,
		string p_e, string p_n, bool integ, string pps);
};

//스파이가 등장하긴 하는데 추가적인 조건이 없음
//chara8 == chara 6
class Stg_character8 : public Stg_character6
{
public:
	Stg_character8(int idt, string name, string dob, bool gender,
		string nationality, string city,
		string p_e, string p_n, bool integ, string pps);
};


//===================================STAGE===================================
class Stage_base
{
public:
	Stage_base();
	virtual ~Stage_base() {};
	Stg_character chArray[6];
	virtual void Play_stage(Game_system *gs,int flag, int i)=0; //순수가상함수.
};

class Stage_1 : public Stage_base
{
public:
	Stage_1();
	Stg_character chArray[6] = {
		Stg_character(1, "김 형진", "1947.11.15", true, "아스토르츠카", "그레스틴", "1985.01.01", "33T61-QMN96"),
		Stg_character(2, "사요 아이", "1960.06.10", false, "임포르", "슨케이도", "1983.06.10", "0QUQ5-K38FQ"),
		Stg_character(3, "수 펀", "1939.02.04", false, "리퍼블리아", "트루 글로리안", "1984.03.16", "13025-W8TQN"),
		Stg_character(4, "김 정숙", "1950.12.29", false, "아스토르츠카", "오베크 버너", "1985.01.01", "33T61-QMN96"),
		Stg_character(5, "-", "-", true, "-", "-", "-", "-"),
		Stg_character(6, "우 상민", "1950.11.15", true, "오브리스탄", "론다즈", "1983.06.13", "32A1S-9C2E7")
	};
	virtual ~Stage_1() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};

class Stage_2 : public Stage_base
{
public:
	Stage_2();
	Stg_character2 chArray[9] = {
		Stg_character2(7, "히데오 코지마", "1945.06.30", true, "임포르", "은키오", "1983.08.19", "W3K06-LS5QX",true),
		Stg_character2(8, "셰이 피에로프스키", "1955.02.27", false, "안테그리아", "트루 글로리안", "1982.11.10", "LSK34-JWI3K",false),//도시 fail
		Stg_character2(9, "리 영식", "1930.12.01", true, "아스토르츠카", "파라디즈나", "1985.05.29", "KS38K-LQJDI",true),
		Stg_character2(10, "친 찌아하오", "1947.08.13", true, "리퍼블리아", "트루 글로리안", "1984.04.14", "SJF3-JWLK",false),//여권번호 fail
		Stg_character2(11, "류 희열", "1950.04.20", true, "오브리스탄", "스칼", "1984.01.11", "QLRU5-5W6DC",true),
		Stg_character2(12, "앨런 다비리", "1955.06.05", true, "연합 연방", "코리스타 시티", "1982.09.01", "KDU92-K832A",false),//여권 만료
		Stg_character2(13, "즈 웨이", "1953.01.22", false, "콜레치아", "베더", "1985.04.20", "MKJ4W-PJ3KS",true),
		Stg_character2(14, "리 춘옌", "1949.11.02", false, "콜레치아", "베이징", "1987.05.27", "5HC1S-7ER7S",false),//도시 fail
		Stg_character2(15, "하오 란", "1946.08.30", false, "리퍼블리아", "보스탄", "1983.10.09", "5LXK9-SQI3K",true)
	};
	virtual ~Stage_2() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};

class Stage_3 : public Stage_base
{
public:
	Stage_3();
	Stg_character3 chArray[9] = {
		Stg_character3(16, "리 광수", "1929.03.17", true, "아스토르츠카", "오베크 버너", "1990.01.01", "P548L-5742Z",false,false), //티켓없음
		Stg_character3(17, "메이 링", "1949.06.15", false, "콜레치아", "유주", "1982.11.10", "5D4Q5-4W2CS",false,false), //티켓없음
		Stg_character3(18, "알리사 보스코노비치", "1961.01.22", false, "인테그리아", "세인트 바실리카", "1984.01.11", "5JIN2-KT61G",false,true),//도시fail
		Stg_character3(19, "황 쯔 쉬안", "1933.11.03", true, "리퍼블리아", "레스레나디", "1988.08.17", "JY8JG-UHB25",false,false), //가짜티켓
		Stg_character3(20, "최 현우", "1944.05.05", true, "오브리스탄", "머저스", "1987.02.22", "KJWER-83KIC",true,true),
		Stg_character3(21, "토도키 하와도", "1941.04.02", true, "임포르", "하이한", "1985.07.13", "1HDFG-SD24F",true,true),
		Stg_character3(22, "아놀드 슈워제네거", "1937.03.28", true, "연합 연방", "싱레튼", "1994.12.12", "IUNM5-ZX321",true,true),
		Stg_character3(23, "류 수아", "1952.07.22", false, "아스토르츠카", "그레스틴", "1988.04.01", "L2KJ3-MXHA9",true,true),
		Stg_character3(24, "솔져르정 찬수스키", "1950.01.02", true, "안테그리아", "글로리안", "1987.05.18", "54SFK-LK421",true,true)
	};
	virtual ~Stage_3() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};

class Stage_4 : public Stage_base
{
public:
	Stage_4();
	Stg_character4 chArray[9] = {
		Stg_character4(25, "박 수정", "1949.06.15", false, "아스토르츠카", "파라디즈나", "1982.11.10", "DK5N1-5ASD1",true,"귀국"),
		Stg_character4(26, "에직", "1960.01.01", false, "연합 연방", "그레이트 래피드", "1984.01.23", "EZIC1-FFREE",true,"비밀 결사"),//특수케이스
		Stg_character4(27, "코시미즈 사치코", "1954.11.25", false, "임포르", "은키오", "1983.5.27", "NC523-5CJAS",true,"관광"),
		Stg_character4(28, "천 관위", "1946.07.03", true, "콜레치아", "베더", "1984.8.10", "2122S-KU1K5",true,"일"),
		Stg_character4(29, "리 승권", "1955.04.25", true, "오브리스탄", "머저스", "1984.9.22", "JDIO9-4SA1D",true,"일"),
		Stg_character4(30, "황 쯔 쉬안", "1941.09.09", false, "리퍼블리아", "레스레나디", "1983.12.12", "LASKD-LSKC3",false,"관광"),//허가서 없음
		Stg_character4(31, "유 병언", "1939.03.22", true, "아스토르츠카", "파라디즈나", "1985.01.30", "5A2XE-KXM36",false,"귀국"),//신분증 없음
		Stg_character4(32, "니키타", "1941.11.11", true, "안테그리아", "아우터 그로스", "1984.12.08", "13KIC-K5ASK",false,"일"),//허가서 없음
		Stg_character4(33, "웡 레이", "1951.02.12", false, "콜레치아", "서주", "1983.6.20", "A28NX-36DKX",false,"일")//도시 불일치
	};
	virtual ~Stage_4() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};

class Stage_5 : public Stage_base
{
public:
	Stg_character5 chArray[9] = {
		Stg_character5(34, "핑 찐쉬에", "1957.12.15", true, "리퍼블리아", "레스레나디", "1984.03.01", "25S54-4LASD",true,"국경 통과"),//특수케이스
		Stg_character5(35, "재민 킴", "1960.04.30", true, "연합 연방", "코리스타 시티", "1982.11.10", "3LKDS-AXLDS",true,"관광"),
		Stg_character5(36, "야가미 라이토", "1954.12.11", true, "임포르", "슨케이도", "1985.08.03", "3KZJX-LQKX5",true,"일"),
		Stg_character5(37, "젠 홍", "1946.01.18", true, "콜레치아", "유주", "1985.05.18", "5SLJ3-LZ6SA",true,"관광"),
		Stg_character5(38, "웡 레이", "1951.06.26", false, "콜레치아", "유르코", "1984.11.19", "5LJKS-5XD5A",true,"일"),
		Stg_character5(39, "뤄 쉬", "1941.07.07", true, "리퍼블리아", "트루 글로리안", "1986.03.08", "10K83-KLD2A",false,"관광"),//허가서 없음
		Stg_character5(40, "김 병팔", "1939.02.02", true, "아스토르츠카", "오베크 버너", "1984.11.10", "6LKF5-L180M",false,"귀국"),//신분증-허가서 불일치
		Stg_character5(41, "이안 두코프", "1941.10.08", true, "안테그리아", "세인트 마메로", "1983.06.12", "4Q5X2-294KA",false,"관광"),//여권-허가서 불일치
		Stg_character5(42, "박 나래", "1955.07.11", false, "오브리스탄", "머저스", "1988.01.30", "2C6AC-LEUQ8",false,"일")//Wokrpass 없음
	};
	Stage_5();
	virtual ~Stage_5() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};

class Stage_6 : public Stage_base
{
public:
	Stg_character6 chArray[9] = {
		Stg_character6(43, "아르티 옴", "1949.01.02", true, "안테그리아", "글로리안", "1984.03.01", "CH0A7-NSU92",true,"일"),
		Stg_character6(44, "김 혜자", "1954.02.13", false, "오브리스탄", "스칼", "1982.11.10", "ALK29-CH212",true,"관광"),
		Stg_character6(45, "리 택기", "1939.08.23", true, "아스토르츠카", "그레스틴", "1985.08.03", "51KLS-LKCIX",true,"귀국"),
		Stg_character6(46, "아오키지 쿠잔", "1947.05.20", true, "임포르", "하이한", "1985.05.18", "HA192-LJNE3",true,"관광"),
		Stg_character6(47, "에도가와 코난", "1941.07.12", true, "임포르", "은키오", "1984.11.19", "5LJKS-5XD5A",true,"국경 통과"), //아래 사람과 부부, 무조건 처음에나옴
		Stg_character6(48, "미나세 이오리", "1943.08.14", false, "임포르", "은키오", "1986.03.08", "LJ09K-LXKJ2",false,"국경 통과"),//허가서 없음, 안나올수도 있음
		Stg_character6(49, "왕 진레이", "1953.03.07", true, "리퍼블리아", "트루 글로리안", "1982.10.01", "QKVUW-SO382",false,"관광"),//여권 만료
		Stg_character6(50, "황 링인", "1947.12.23", false, "콜레치아", "베더", "1983.06.12", "NASIN-2NEAX",false,"관광"),//3스테이지 입국표 들고옴
		Stg_character6(51, "최 우솔", "-", true, "오브리스탄", "-", "-", "-",false,"-")//여권없음
	};
	Stage_6();
	virtual ~Stage_6() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};

class Stage_7 : public Stage_base
{
public:
	Stg_character7 chArray[9] = {
		Stg_character7(52, "마오 체", "1942.01.01", true, "콜레치아", "베더", "2000.01.01", "AS12L-KQLX3",true,"외교"), //외교관, 스파이
		Stg_character7(53, "김 나성", "1944.05.31", true, "오브리스탄", "스칼", "2000.01.01", "LQLU3-MXI8K",true,"외교"), //일반 외교관
		Stg_character7(54, "조르지 코스타바", "1958.04.02", true, "안테그리아", "아우터 그로스", "1985.02.04", "LZUEK-MXUAI",true,"일"),
		Stg_character7(55, "팡 추링", "1952.02.21", false, "리퍼블리아", "보스탄", "1988.07.01", "QLKU1-LQ0XK",true,"국경통과"),
		Stg_character7(56, "카구야 루나", "1954.07.03", false, "임포르", "슨케이도", "1985.08.23", "L10XK-1KXLX",true,"관광"),
		Stg_character7(57, "림 동권", "1947.09.14", true, "아스토르츠카", "그레스틴", "1986.04.11", "MXI01-MXJ3K",false,"귀국"),//여권, 신분증 불일치
		Stg_character7(58, "레라 멜니코바", "1949.03.21", false, "안테그리아", "글로리안", "1983.04.01", "1LKJX-LK1XL",false,"국경 통과"),//허가서 없음
		Stg_character7(59, "벤 브로드", "1951.11.08", true, "연합 연방", "치코리타 시티", "1985.11.23", "LKQJ8-MX3CK",false,"관광"),//잘못된 도시
		Stg_character7(60, "사카즈키 아카이누", "1946.02.22", true, "임포르", "하이한", "1985.12.24", "QLK34-1KXSK",false,"일")//work pass 업슴
	};
	Stage_7();
	virtual ~Stage_7() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};

class Stage_8 : public Stage_base
{
public:
	Stg_character8 chArray[9] = {
		Stg_character8(61, "김 민제", "1944.04.04", true, "오브리스탄", "론다즈", "1984.01.11", "JK8CK-K1UCK",true,"국경 통과"),//스파이
		Stg_character8(62, "리 샤오메이", "1949.06.15", true, "콜레치아", "유르코", "1988.08.17", "F28YC-KQUU2",true,"-"),
		Stg_character8(63, "황 장엽", "1961.01.22", true, "아스토르츠카", "오베크 버너", "1987.02.22", "QKKXJ-3KCUQ",true,"-"),
		Stg_character8(64, "시엔 윤파", "1933.11.03", true, "콜레치아", "유주", "1985.07.13", "1L3JC-L1KJX",true,"-"),
		Stg_character8(65, "세르게이 스밀노프", "1944.05.05", true, "안테그리아", "글로리안", "1994.12.12", "3KLCJ-L2KJX",true,"-"),
		Stg_character8(66, "진 롱", "1941.04.02", true, "리퍼블리아", "레스레나디", "1988.04.01", "90CKE-2LXJD",true,"-"),
		Stg_character8(67, "미셸 발레리", "1937.03.28", true, "연합 연방", "싱레튼", "1987.05.18", "4XKJH-2KX34",true,"-"),
		Stg_character8(68, "와사카 유리", "1952.07.22", true, "임포르", "은키오", "1985.08.12", "1LJJS-2JOZD",true,"-"),
		Stg_character8(69, "아르고 가르스키", "1950.01.02", true, "안테그리아", "아우터 그로스", "1984.11.05", "3KQXI-JLIXD",true,"-")
	};
	Stage_8();
	virtual ~Stage_8() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};