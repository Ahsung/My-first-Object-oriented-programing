#include<iostream>
#include<string>
using namespace std;
//�Ŵ��� ������
#include "saving.h"
#include "financeservice.h"
#include "loan.h"
#include "customer.h"
#include "card.h"
#include "manager.h"

void manager::magsetting(loan a, int b)            //���� a�� �Ŵ��� �������(�Ŵ����� �����ϴ� ����)�� ����
{
	this->lo[b] = a;
}
void manager::magsetting(saving a, int b)       //���� a�� �Ŵ��� �������(�Ŵ����� �����ϴ� ����)�� ����
{
	this->sa[b] = a;
}
void manager::magsetting(card a, int b)           //���� a�� �Ŵ��� ���ī��(�Ŵ����� �����ϴ� ī��)�� ����
{
	this->ca[b] = a;
}
void manager::magloanshow()                   //�����ϴ� �����ǰ ����
{
	cout << "�����ϴ� �����ǰ: "<<endl;
	for (int i =0 ; i < 3; i++)
	{                      
		cout << i + 1 << ": ";
		lo[i].Nameshow();
		cout << endl;
	}
}
void manager::magsavingshow()                 //�����ϴ� ���ݻ�ǰ ����
{
	cout << "�����ϴ� ���ݻ�ǰ: "<<endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ": ";
		sa[i].Nameshow();
		cout << endl;
	}
}
void manager::magcardshow()                   //�����ϴ� ī���ǰ ����
{
	cout << "�����ϴ� ī���ǰ: "<<endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ": ";
		ca[i].Nameshow();
		cout << endl;
	}
}
void manager::custinforshow(customer a)
{
	cout << "=======";
	a.custNameshow();
	cout << "������ ����======="<<endl<<endl<<endl;
	a.custshow();
	a.serviceshow();

}
void manager::loanmanagement( customer b)        //a��° ���⼭�� b���� ���� 
{
c:;
	int a;
	magloanshow();
	cout << "��� ��ǰ�� �����Ͻðڽ��ϱ�?:";
	cin >> a;
	cout << endl;
	cout << endl;
	if (excellence(lo[a - 1], b))
	{
		cout << "-----------------�����Ͻ� ��ǰ--------------" << endl << endl;
		lo[a - 1].Nameshow();
		cout << endl;
		lo[a - 1].setting();
		cout << endl;
		cout << "-------";
		b.custNameshow();
		b.servicesetting(lo[a - 1]);           //������� ���� ����!     
		cout << "������ �����Ͻ� ��ǰ��---------" << endl << endl;                
		lo[a - 1].show();
	}
	else
	{
		cout << "����� ��ǰ�Դϴ� �ٽ� ����ֽʽÿ�" << endl << endl;
		goto c;
	}
}
void manager::savingmanagement( customer b)      //���ݼ��� b���� ����
{
c:;
	int a;
	magsavingshow();
	cout << "��� ��ǰ�� �����Ͻðڽ��ϱ�?:";
	cin >> a;
	cout << endl;
	cout << endl;
	if (excellence(sa[a - 1], b))
	{
		cout << "-----------------�����Ͻ� ��ǰ--------------" << endl << endl;
		sa[a - 1].Nameshow();
		cout << endl;
		sa[a - 1].setting();
		cout << endl;
		cout << "-------";
		b.custNameshow();
		b.servicesetting(sa[a - 1]);                //������� ���� ����!  
		cout << "������ �����Ͻ� ��ǰ��---------" << endl << endl;
		sa[a - 1].show();
		cout << endl;
		sa[a - 1].maturityamount();
	}
	else
	{
		cout << "����� ��ǰ�Դϴ� �ٽ� ����ֽʽÿ�" << endl << endl;
		goto c;
	}

}
void manager::cardmanagement( customer b)
{
c:;
	int a;
	magcardshow();
	cout << "��� ��ǰ�� �����Ͻðڽ��ϱ�?:";
	cin >> a;
	cout << endl;
	cout << endl;
	if (excellence(ca[a - 1], b))
	{
		cout << "-----------------�����Ͻ� ��ǰ--------------" << endl << endl;
		ca[a - 1].Nameshow();
		cout << endl;
		ca[a - 1].setting();
		cout << endl;
		cout << "-------";
		b.custNameshow();
		b.servicesetting(ca[a - 1]);                //������� ���� ����
		cout << "������ �����Ͻ� ��ǰ��---------" << endl << endl;       
		ca[a - 1].show();
	}
	else
	{
		cout << "����� ��ǰ�Դϴ� �ٽ� ����ֽʽÿ�"<<endl<<endl;
		goto c;
	}
}

