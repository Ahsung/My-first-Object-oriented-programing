#include<iostream>
#include<string>
using namespace std;
//ī�� ������
#include"financeservice.h"
#include"card.h"

void card::show()  //ī������ ����
{
	dshow();
	cout << endl;
	cout << "���θ��: " << this->salelist << "  �ѵ��ݾ�: " << this->limit<<"����" <<"  ��й�ȣ: "<<password<< endl;
}
void card::setting()     //ī�� ��й�ȣ ����
{
	cout << "��й�ȣ �Է�:";
	cin >> password;
}
void card::Nameshow()   //ī�� �������� ����
{
	dshow();
	cout << "  ���θ��:" << this->salelist << "  �ѵ��ݾ�:" << this->limit << "����" << endl;
}