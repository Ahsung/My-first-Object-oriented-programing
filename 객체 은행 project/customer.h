#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<string>
; using namespace std;

#include "financeservice.h"
#include "card.h"
#include "loan.h"
#include "saving.h"

//�� �����
; class customer{

private:
	
	int yeerincome;      // ������
	int num;             //ȸ�� ��ȣ
	card caservice;     //������� ī�弭��
	loan loservice;     //������� ���⼭��
	saving saservice;   //������� ���ݼ���
public:
	string name;         // �̸�,���� �̸��� �����̺��� �ؾߵǴµ� ����ȸ�� ��ȸ�ҋ� �̸����� ������ �Լ� ����� �����Ƽ� �ۺ����� �ű�.
	customer()              //������ 
	{
		name = "��";
		yeerincome = 0;
		num = 0;
		
	}
	void custNameshow();       //���̸��� ��ȣ�� ����
	void namesetting();        //���̸� ���� �Լ�
	void incomesetting();      //������ �����Լ�
	void custshow();           //������ ����
	void numsetting(int a);    //ȸ����ȣ ����
	bool excellence()
	{
		if (this->yeerincome >= 5000)
			return true;
		else
			return false;
	
	}

	//*�Լ��ߺ�*//
	void servicesetting(card a);           //���� ������� ī�弭�� ����
	void servicesetting(loan a);          //���� ������� ���⼭�� ����   
	void servicesetting(saving a);        //���� ������� ���ݼ��� ����
	
	void serviceshow();                   //������� ���� ����
	
	
};



#endif