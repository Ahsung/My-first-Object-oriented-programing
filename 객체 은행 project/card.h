#ifndef CARD_H
#define CARD_H
#include<string>
; using namespace std;
//ī�� �����
#include "financeservice.h"

class card : public financeservice
{
private:
	string salelist;
	int limit;
	int password;
public:
	card(string a = "����", int b = 0, string pn = "����", bool ex = false) :financeservice(pn, ex)
		//���θ��, �ѵ�, ��ǰ�̸�, ���//
	{
		this->salelist = a;
		this->limit= b;
		this->password = 0;
	}
	void show();        //ī������(�������) ����
	void setting();     //ī�� ��й�ȣ ����
	void Nameshow();    //ī�� ��������(�̸�,���,���θ��,�ѵ�) ����
};

#endif 