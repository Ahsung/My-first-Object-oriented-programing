#ifndef SAVING_H
#define SAVING_H
#include<string>
; using namespace std;

#include "financeservice.h"
//���� �����

; class saving :public financeservice
{
private:
	double intrate;  //�ݸ�
	int month;       //����
	int money;       //�� �Աݾ�
public:
	saving(double ir = 0, string pn = "����", bool ex = false) :financeservice(pn, ex)
	//�ݸ�, ��ǰ�̸�, ���//
	{
		intrate = ir;
		month = 0;
		money = 0;
	}
	void Nameshow();        //���ݻ�ǰ ������ǰ����(�̸�,�ݸ�,���) ����
	void show();            //�������� ����  (�������)
	void setting();         //ȸ���� ���� �Է��Ͽ�(������ǰ����(����,�� �Աݾ�)�� ����
	void maturityamount();  //����ݾ��� ����ϰ� ������
		
}


#endif
