#include<iostream>
#include<string>
using namespace std;
#include "saving.h"
#include "financeservice.h"
#include "loan.h"
#include "customer.h"
#include "card.h"
#include "manager.h"
; /*int main()
{
	cout << "-------------������ǰ �׽�Ʈ--------------" << endl;
	financeservice abc; //�⺻ ������ǰ ����
	financeservice ABC("���",true);
	abc.dshow();
	cout << endl;
	cout << endl;
	ABC.dshow();
	cout << endl;
	cout << endl;
	
	cout << endl;
	cout << endl;
	cout << "-------------���� �׽�Ʈ------------------" << endl;
	loan loave;        //�⺻ �����ǰ ����
	loan love(2.3,"�ູ(���)",true);
	
	loave.show();
	cout << endl;
	love.Nameshow();
	cout << endl;
	love.show();
	cout << endl;
	
	love.show();
	
    
	cout << "-------------���� �׽�Ʈ------------------" << endl;
	saving sav;     //�⺻ ���ݻ�ǰ ����
	saving save(2,"����");
	sav.show();
	cout << endl;
    save.show();
	cout << endl;
	save.Nameshow();
	cout << endl;
	
	
	save.show();
	cout << "------------ī�� �׽�Ʈ--------------------" << endl;
	card gi;          //�⺻ ī���ǰ ����
	card car("������", 800000, "�츮");
	gi.show();
	cout << endl;
	car.show();

	cout << "------------�Ŵ��� �׽�Ʈ------------------" << endl;
	manager girl;     //�⺻ �Ŵ��� ����

	girl.magsetting(save, 0);
	cout << endl;
	girl.magsavingshow();
	cout << endl;
	girl.magsetting(love, 1);
	cout << endl;
	girl.magsetting(car, 0);
	girl.magloanshow();
	
	cout << "------------�� �׽�Ʈ--------------------" << endl;                                                    
	customer custer[100];
	custer[0].custshow();        //�⺻�� ���� ���� ����       
	cout << endl;
	    //������ �Է�
	cout << endl;
	//customer[0].inforsetting();
	//customer[0].custshow();        �Էµ� ������ ����//
	//cout <<"�����?(������1,�ƴϸ�0):"<< girl.excellence(love, customer[0]) << endl;
//	customer[0].servicesetting(car);
	//customer[0].serviceshow();
	
	                                                             // ���� ������ �Ű����� ���� >> ����, ��ǰ�̸�, ���          //
		                                                         // ���� ������ �Ű����� ����  >>  �ݸ�,��ǰ�̸�, ���         //
																 // ī�� ������ �Ű����� ���� >> ���θ��, �ѵ�, ��ǰ�̸�, ���//
	
	cout << "------------��ü �׽�Ʈ--------------------" << endl;
    
	loan loan1(15, "����1(���)", true);
	loan loan2(20, "����2");
	loan loan3(25, "����3");

	saving save1(5, "����1(���)", true);
	saving save2(2.5, "����2");
	saving save3(2, "����3");

	card card1("��ȭ��,��ȭ��", 100, "ī��1(���)", true);
	card card2("������", 50, "ī��2");
	card card3("������", 50, "ī��3");

	customer cust[100];
	
	manager loaner;
	manager saver;
	manager carder;

	loaner.magsetting(loan1, 0);
	loaner.magsetting(loan2, 1);
	loaner.magsetting(loan3, 2);

	saver.magsetting(save1, 0);
	saver.magsetting(save2, 1);
	saver.magsetting(save3, 2);

	carder.magsetting(card1, 0);
	carder.magsetting(card2, 1);
	carder.magsetting(card3, 2);

	customer a;
	a.servicesetting(save1);
	a.serviceshow();
	/*
	int i = 0;
       while (i<100)
	{
		
		cust[i].numsetting(i + 1);
		
		cust[i].namesetting();
		cust[i].incomesetting();
		cust[i].custshow();
	s:;
		cout << "===============����===============" << endl<<endl;
		cout << "1.����\n2.����\n3.ī��" << endl;
		int a = 0;
		cout << "� ���񽺸� �̿��Ͻðڽ��ϱ�?(��ȣ�Է�): ";
		cin >> a;
		if (a == 1)
		{
			loaner.loanmanagement(cust[i]);
		}
		else if (a == 2)
		{
			saver.savingmanagement(cust[i]);
		}
		else if (a == 3)
		{
			carder.cardmanagement(cust[i]);
		}
		else
		{
			cout << "\n1~3�� �߿� ���ÿ�" << endl;
			goto s;
		}
		loaner.custinforshow(cust[i]);
		cout << endl;
		cout << "\n�� ���񽺿� �ϳ����� ��밡���մϴ�, �ߺ����� ������ ���񽺴� ������ϴ�.";
		cout << endl<<endl<<endl;

	d:;
		cout << "���񽺸� ����̿��ϰڽ��ϱ�?(����� 1 �׸��� 0):";
		
		int b;
		
		cin >> b;
		
		if (b == 1)
		{
			goto s;
		}
		else if (b ==0)
		{
			cout << "�����մϴ�" << endl;
			i++;
		}
		
		else
		{
			cout << "\n 1�Ǵ� 0�� �����ּ��� "<<endl;
			goto d;
		}
		cin.sync();


	}*/


