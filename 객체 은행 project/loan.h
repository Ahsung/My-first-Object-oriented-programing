#ifndef LOAN_H
#define LOAN_H
//���� �����

#include "financeservice.h"

; using namespace std;

class loan :public financeservice
{
private:
	double interest;   //����
	int loanmoney;     //�����
	int monthplan;     //�Һ�
public:
	loan(double in = 0,  string pn = "����", bool ex = false) :financeservice(pn, ex)
		//����, ��ǰ�̸�, ���//
	{
		interest = in;
		loanmoney = 0;
		monthplan = 0;
	}
	void Nameshow();               //�����ǰ ���� ��ǰ����(�̸�,����,���) ����
	void show();                   //�������� ����(��� ����)
	void setting();                //ȸ���� ���� �Է��Ͽ� ���� ��ǰ����(�����,�Һ�)�� ����
}


#endif
