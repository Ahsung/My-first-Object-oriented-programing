#include <iostream>
#include<string>
using namespace std;
#include "financeservice.h"
#include "loan.h"
//���� ������
void loan :: show()  //�������� ����
{
	dshow();
	cout << endl;
	cout <<"����: "<<interest <<"%"<< "  �����: " << loanmoney <<"��"<<"  �Һ�: "<<monthplan<<"����"<< endl;

}
void loan::setting()
{
	cout << "����� �Է�(����):";
	cin >> this->loanmoney;  //����� ����
	cout << "�Һ� �Է�(����):";    
	cin >> this->monthplan;  //�Һ� ����
}
void loan::Nameshow()      //���� ���������� ����
{
	dshow();
	cout << "  ����:" << this->interest<<"%" << endl;
}
