#include<iostream>
#include<string>
using namespace std;

#include "financeservice.h"
#include "saving.h"
//���� ������
void saving::show()  // �������� ����
{
	dshow();
	cout << endl;
	cout << "�ݸ�: "<<intrate<<"%" << "  ���� ��: " << month <<"����"<< "  �� �Աݾ�:" << money<<"����" << endl;
}
void saving::setting()    //���� ��������
{
	cout << "���ݰ��� �Է�:";
	cin >> this->month;
	cout << "�� �Աݾ� �Է�(����):";
	cin >> this->money;
}
void saving::Nameshow()  //���� �������� ����
{
	dshow();
	cout << "  �ݸ�:" << this->intrate <<"%"<< endl;
}
void saving::maturityamount()             //���ݸ��� �ݾ� ���
{
	      
	double mount=0;

	for (int i = 0; i < month; i++)
	{
		double ratepd = 1;

		for (int j = 0; j <= i; j++)
		{
			ratepd *=(1+ (intrate/100));
		}
		mount += (ratepd*money);

	}
	cout << "����ݾ�: "<<mount<<"����"<<endl;
}