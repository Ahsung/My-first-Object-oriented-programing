#include<iostream>
#include<string>
using namespace std;
//�� ������
#include "customer.h"

; void customer::namesetting()   // ������ �Է� �Լ�
{
 
	
	cout << "�̸� �Է�:";   
	getline(cin,name,'\n');
	cout << endl;
}
void customer::incomesetting()
{
	cout << "���� �Է�(����):";
	cin >> this->yeerincome;
	cout << endl;
}
void customer::custshow()             //������ ���� �Լ�
{                   
	cout <<"�̸�: "<< name<<"  ����: " << yeerincome <<"����"<<"  ȸ����ȣ:"<<num<< endl;
	if (excellence() == true)
		cout << "������Դϴ�." << endl;
	else
		cout << "�Ϲ��Դϴ�." << endl;
}
void customer::custNameshow()
{
	cout << num << "�� " << name;        //��ȣ�� �̸� ������� ex) 01�� ȫ�浿
}
void customer::numsetting(int a)
{
	this->num = a;
}
void customer::servicesetting(card a)
{
	this->caservice = a;
}
void customer::servicesetting(loan a)
{
	this->loservice = a;
}
void customer::servicesetting(saving a)
{
	this->saservice = a;
}
void customer::serviceshow()                   //������� ���񽺻�ǰ ����
{
	cout << "---------������� �����ǰ---------" << endl;
	loservice.show();
	cout << endl;
	cout << "---------������� ���ݻ�ǰ---------"<<endl;
	saservice.show();
	cout << endl;
	cout << "---------������� ī���ǰ---------"<<endl;
	caservice.show();
	cout << endl;
}




