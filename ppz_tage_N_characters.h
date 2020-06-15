#pragma once
using std::string;

//�ڱ��θ� �������, base class
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

//�ܱ��ε� �������, integrity (���ԺҰ�) �߰�
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

//vticket�ʿ�
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

//ticket �ʿ����, �ܱ����� �㰡��, �ڱ����� �ź��� �ʿ� 
//>> �ܱ��� �㰡���� destination //������ 1������
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

//�뵿 �㰡�� �ʿ�
class Stg_character5 : public Stg_character4
{
public:
	Stg_character5();
	Stg_character5(int idt, string name, string dob, bool gender,
		string nationality, string city,
		string p_e, string p_n, bool integ, string pps);
	void show_passport();
};

//���� ����, ���� ���� �߰�
class Stg_character6 : public Stg_character5
{
public:
	Stg_character6(int idt, string name, string dob, bool gender,
		string nationality, string city,
		string p_e, string p_n, bool integ, string pps);
	void show_passport();
};

//�ܱ��� ���� , ������ 2������
//chara7 == chara 6
class Stg_character7 : public Stg_character6
{
public:
	Stg_character7(int idt, string name, string dob, bool gender,
		string nationality, string city,
		string p_e, string p_n, bool integ, string pps);
};

//�����̰� �����ϱ� �ϴµ� �߰����� ������ ����
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
	virtual void Play_stage(Game_system *gs,int flag, int i)=0; //���������Լ�.
};

class Stage_1 : public Stage_base
{
public:
	Stage_1();
	Stg_character chArray[6] = {
		Stg_character(1, "�� ����", "1947.11.15", true, "�ƽ��丣��ī", "�׷���ƾ", "1985.01.01", "33T61-QMN96"),
		Stg_character(2, "��� ����", "1960.06.10", false, "������", "�����̵�", "1983.06.10", "0QUQ5-K38FQ"),
		Stg_character(3, "�� ��", "1939.02.04", false, "���ۺ���", "Ʈ�� �۷θ���", "1984.03.16", "13025-W8TQN"),
		Stg_character(4, "�� ����", "1950.12.29", false, "�ƽ��丣��ī", "����ũ ����", "1985.01.01", "33T61-QMN96"),
		Stg_character(5, "-", "-", true, "-", "-", "-", "-"),
		Stg_character(6, "�� ���", "1950.11.15", true, "���긮��ź", "�д���", "1983.06.13", "32A1S-9C2E7")
	};
	virtual ~Stage_1() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};

class Stage_2 : public Stage_base
{
public:
	Stage_2();
	Stg_character2 chArray[9] = {
		Stg_character2(7, "������ ������", "1945.06.30", true, "������", "��Ű��", "1983.08.19", "W3K06-LS5QX",true),
		Stg_character2(8, "���� �ǿ�������Ű", "1955.02.27", false, "���ױ׸���", "Ʈ�� �۷θ���", "1982.11.10", "LSK34-JWI3K",false),//���� fail
		Stg_character2(9, "�� ����", "1930.12.01", true, "�ƽ��丣��ī", "�Ķ���", "1985.05.29", "KS38K-LQJDI",true),
		Stg_character2(10, "ģ ����Ͽ�", "1947.08.13", true, "���ۺ���", "Ʈ�� �۷θ���", "1984.04.14", "SJF3-JWLK",false),//���ǹ�ȣ fail
		Stg_character2(11, "�� ��", "1950.04.20", true, "���긮��ź", "��Į", "1984.01.11", "QLRU5-5W6DC",true),
		Stg_character2(12, "�ٷ� �ٺ�", "1955.06.05", true, "���� ����", "�ڸ���Ÿ ��Ƽ", "1982.09.01", "KDU92-K832A",false),//���� ����
		Stg_character2(13, "�� ����", "1953.01.22", false, "�ݷ�ġ��", "����", "1985.04.20", "MKJ4W-PJ3KS",true),
		Stg_character2(14, "�� �Ὼ", "1949.11.02", false, "�ݷ�ġ��", "����¡", "1987.05.27", "5HC1S-7ER7S",false),//���� fail
		Stg_character2(15, "�Ͽ� ��", "1946.08.30", false, "���ۺ���", "����ź", "1983.10.09", "5LXK9-SQI3K",true)
	};
	virtual ~Stage_2() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};

class Stage_3 : public Stage_base
{
public:
	Stage_3();
	Stg_character3 chArray[9] = {
		Stg_character3(16, "�� ����", "1929.03.17", true, "�ƽ��丣��ī", "����ũ ����", "1990.01.01", "P548L-5742Z",false,false), //Ƽ�Ͼ���
		Stg_character3(17, "���� ��", "1949.06.15", false, "�ݷ�ġ��", "����", "1982.11.10", "5D4Q5-4W2CS",false,false), //Ƽ�Ͼ���
		Stg_character3(18, "�˸��� �����ڳ��ġ", "1961.01.22", false, "���ױ׸���", "����Ʈ �ٽǸ�ī", "1984.01.11", "5JIN2-KT61G",false,true),//����fail
		Stg_character3(19, "Ȳ �� ����", "1933.11.03", true, "���ۺ���", "����������", "1988.08.17", "JY8JG-UHB25",false,false), //��¥Ƽ��
		Stg_character3(20, "�� ����", "1944.05.05", true, "���긮��ź", "������", "1987.02.22", "KJWER-83KIC",true,true),
		Stg_character3(21, "�䵵Ű �Ͽ͵�", "1941.04.02", true, "������", "������", "1985.07.13", "1HDFG-SD24F",true,true),
		Stg_character3(22, "�Ƴ�� �������װ�", "1937.03.28", true, "���� ����", "�̷�ư", "1994.12.12", "IUNM5-ZX321",true,true),
		Stg_character3(23, "�� ����", "1952.07.22", false, "�ƽ��丣��ī", "�׷���ƾ", "1988.04.01", "L2KJ3-MXHA9",true,true),
		Stg_character3(24, "�������� ������Ű", "1950.01.02", true, "���ױ׸���", "�۷θ���", "1987.05.18", "54SFK-LK421",true,true)
	};
	virtual ~Stage_3() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};

class Stage_4 : public Stage_base
{
public:
	Stage_4();
	Stg_character4 chArray[9] = {
		Stg_character4(25, "�� ����", "1949.06.15", false, "�ƽ��丣��ī", "�Ķ���", "1982.11.10", "DK5N1-5ASD1",true,"�ͱ�"),
		Stg_character4(26, "����", "1960.01.01", false, "���� ����", "�׷���Ʈ ���ǵ�", "1984.01.23", "EZIC1-FFREE",true,"��� ���"),//Ư�����̽�
		Stg_character4(27, "�ڽù��� ��ġ��", "1954.11.25", false, "������", "��Ű��", "1983.5.27", "NC523-5CJAS",true,"����"),
		Stg_character4(28, "õ ����", "1946.07.03", true, "�ݷ�ġ��", "����", "1984.8.10", "2122S-KU1K5",true,"��"),
		Stg_character4(29, "�� �±�", "1955.04.25", true, "���긮��ź", "������", "1984.9.22", "JDIO9-4SA1D",true,"��"),
		Stg_character4(30, "Ȳ �� ����", "1941.09.09", false, "���ۺ���", "����������", "1983.12.12", "LASKD-LSKC3",false,"����"),//�㰡�� ����
		Stg_character4(31, "�� ����", "1939.03.22", true, "�ƽ��丣��ī", "�Ķ���", "1985.01.30", "5A2XE-KXM36",false,"�ͱ�"),//�ź��� ����
		Stg_character4(32, "��ŰŸ", "1941.11.11", true, "���ױ׸���", "�ƿ��� �׷ν�", "1984.12.08", "13KIC-K5ASK",false,"��"),//�㰡�� ����
		Stg_character4(33, "�� ����", "1951.02.12", false, "�ݷ�ġ��", "����", "1983.6.20", "A28NX-36DKX",false,"��")//���� ����ġ
	};
	virtual ~Stage_4() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};

class Stage_5 : public Stage_base
{
public:
	Stg_character5 chArray[9] = {
		Stg_character5(34, "�� �𽬿�", "1957.12.15", true, "���ۺ���", "����������", "1984.03.01", "25S54-4LASD",true,"���� ���"),//Ư�����̽�
		Stg_character5(35, "��� Ŵ", "1960.04.30", true, "���� ����", "�ڸ���Ÿ ��Ƽ", "1982.11.10", "3LKDS-AXLDS",true,"����"),
		Stg_character5(36, "�߰��� ������", "1954.12.11", true, "������", "�����̵�", "1985.08.03", "3KZJX-LQKX5",true,"��"),
		Stg_character5(37, "�� ȫ", "1946.01.18", true, "�ݷ�ġ��", "����", "1985.05.18", "5SLJ3-LZ6SA",true,"����"),
		Stg_character5(38, "�� ����", "1951.06.26", false, "�ݷ�ġ��", "������", "1984.11.19", "5LJKS-5XD5A",true,"��"),
		Stg_character5(39, "�� ��", "1941.07.07", true, "���ۺ���", "Ʈ�� �۷θ���", "1986.03.08", "10K83-KLD2A",false,"����"),//�㰡�� ����
		Stg_character5(40, "�� ����", "1939.02.02", true, "�ƽ��丣��ī", "����ũ ����", "1984.11.10", "6LKF5-L180M",false,"�ͱ�"),//�ź���-�㰡�� ����ġ
		Stg_character5(41, "�̾� ������", "1941.10.08", true, "���ױ׸���", "����Ʈ ���޷�", "1983.06.12", "4Q5X2-294KA",false,"����"),//����-�㰡�� ����ġ
		Stg_character5(42, "�� ����", "1955.07.11", false, "���긮��ź", "������", "1988.01.30", "2C6AC-LEUQ8",false,"��")//Wokrpass ����
	};
	Stage_5();
	virtual ~Stage_5() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};

class Stage_6 : public Stage_base
{
public:
	Stg_character6 chArray[9] = {
		Stg_character6(43, "�Ƹ�Ƽ ��", "1949.01.02", true, "���ױ׸���", "�۷θ���", "1984.03.01", "CH0A7-NSU92",true,"��"),
		Stg_character6(44, "�� ����", "1954.02.13", false, "���긮��ź", "��Į", "1982.11.10", "ALK29-CH212",true,"����"),
		Stg_character6(45, "�� �ñ�", "1939.08.23", true, "�ƽ��丣��ī", "�׷���ƾ", "1985.08.03", "51KLS-LKCIX",true,"�ͱ�"),
		Stg_character6(46, "�ƿ�Ű�� ����", "1947.05.20", true, "������", "������", "1985.05.18", "HA192-LJNE3",true,"����"),
		Stg_character6(47, "�������� �ڳ�", "1941.07.12", true, "������", "��Ű��", "1984.11.19", "5LJKS-5XD5A",true,"���� ���"), //�Ʒ� ����� �κ�, ������ ó��������
		Stg_character6(48, "�̳��� �̿���", "1943.08.14", false, "������", "��Ű��", "1986.03.08", "LJ09K-LXKJ2",false,"���� ���"),//�㰡�� ����, �ȳ��ü��� ����
		Stg_character6(49, "�� ������", "1953.03.07", true, "���ۺ���", "Ʈ�� �۷θ���", "1982.10.01", "QKVUW-SO382",false,"����"),//���� ����
		Stg_character6(50, "Ȳ ����", "1947.12.23", false, "�ݷ�ġ��", "����", "1983.06.12", "NASIN-2NEAX",false,"����"),//3�������� �Ա�ǥ ����
		Stg_character6(51, "�� ���", "-", true, "���긮��ź", "-", "-", "-",false,"-")//���Ǿ���
	};
	Stage_6();
	virtual ~Stage_6() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};

class Stage_7 : public Stage_base
{
public:
	Stg_character7 chArray[9] = {
		Stg_character7(52, "���� ü", "1942.01.01", true, "�ݷ�ġ��", "����", "2000.01.01", "AS12L-KQLX3",true,"�ܱ�"), //�ܱ���, ������
		Stg_character7(53, "�� ����", "1944.05.31", true, "���긮��ź", "��Į", "2000.01.01", "LQLU3-MXI8K",true,"�ܱ�"), //�Ϲ� �ܱ���
		Stg_character7(54, "������ �ڽ�Ÿ��", "1958.04.02", true, "���ױ׸���", "�ƿ��� �׷ν�", "1985.02.04", "LZUEK-MXUAI",true,"��"),
		Stg_character7(55, "�� �߸�", "1952.02.21", false, "���ۺ���", "����ź", "1988.07.01", "QLKU1-LQ0XK",true,"�������"),
		Stg_character7(56, "ī���� �糪", "1954.07.03", false, "������", "�����̵�", "1985.08.23", "L10XK-1KXLX",true,"����"),
		Stg_character7(57, "�� ����", "1947.09.14", true, "�ƽ��丣��ī", "�׷���ƾ", "1986.04.11", "MXI01-MXJ3K",false,"�ͱ�"),//����, �ź��� ����ġ
		Stg_character7(58, "���� ����ڹ�", "1949.03.21", false, "���ױ׸���", "�۷θ���", "1983.04.01", "1LKJX-LK1XL",false,"���� ���"),//�㰡�� ����
		Stg_character7(59, "�� ��ε�", "1951.11.08", true, "���� ����", "ġ�ڸ�Ÿ ��Ƽ", "1985.11.23", "LKQJ8-MX3CK",false,"����"),//�߸��� ����
		Stg_character7(60, "��ī��Ű ��ī�̴�", "1946.02.22", true, "������", "������", "1985.12.24", "QLK34-1KXSK",false,"��")//work pass ����
	};
	Stage_7();
	virtual ~Stage_7() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};

class Stage_8 : public Stage_base
{
public:
	Stg_character8 chArray[9] = {
		Stg_character8(61, "�� ����", "1944.04.04", true, "���긮��ź", "�д���", "1984.01.11", "JK8CK-K1UCK",true,"���� ���"),//������
		Stg_character8(62, "�� ��������", "1949.06.15", true, "�ݷ�ġ��", "������", "1988.08.17", "F28YC-KQUU2",true,"-"),
		Stg_character8(63, "Ȳ �忱", "1961.01.22", true, "�ƽ��丣��ī", "����ũ ����", "1987.02.22", "QKKXJ-3KCUQ",true,"-"),
		Stg_character8(64, "�ÿ� ����", "1933.11.03", true, "�ݷ�ġ��", "����", "1985.07.13", "1L3JC-L1KJX",true,"-"),
		Stg_character8(65, "�������� ���г���", "1944.05.05", true, "���ױ׸���", "�۷θ���", "1994.12.12", "3KLCJ-L2KJX",true,"-"),
		Stg_character8(66, "�� ��", "1941.04.02", true, "���ۺ���", "����������", "1988.04.01", "90CKE-2LXJD",true,"-"),
		Stg_character8(67, "�̼� �߷���", "1937.03.28", true, "���� ����", "�̷�ư", "1987.05.18", "4XKJH-2KX34",true,"-"),
		Stg_character8(68, "�ͻ�ī ����", "1952.07.22", true, "������", "��Ű��", "1985.08.12", "1LJJS-2JOZD",true,"-"),
		Stg_character8(69, "�Ƹ��� ������Ű", "1950.01.02", true, "���ױ׸���", "�ƿ��� �׷ν�", "1984.11.05", "3KQXI-JLIXD",true,"-")
	};
	Stage_8();
	virtual ~Stage_8() {};
	virtual void Play_stage(Game_system *gs, int flag, int i) override;
};