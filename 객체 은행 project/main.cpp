#include<iostream>
#include<string>
using namespace std;
#include "saving.h"
#include "financeservice.h"
#include "loan.h"
#include "customer.h"
#include "card.h"
#include "manager.h"

int main(void)
{
	loan loan1(15, "�ſ��޴���", true);  // �ſ��޴��ⰴü ����!
	loan loan2(20, "�Ϲݵ�޴���");        // �Ϲݵ�޴��ⰴü ����! 
	loan loan3(25, "�����޴���");        // �����޴��ⰴü ����!

	saving save1(5, "����������", true);   //���������ݰ�ü ����!
	saving save2(2.5, "�Ϲ���������");     //�Ϲ��������ݰ�ü ����!
	saving save3(2, "����������");         //���������ݰ�ü ����!

	card card1("��ľ�, ���ǽü�, �������̸�Ʈ", 100, "���ȸ��ī��", true);   //���ȸ��ī�尴ü ����!
	card card2("��ľ�, ���ǽü�", 60, "�Ϲ�ȸ��ī��");                        //�Ϲ�ȸ��ī�尴ü ����!
	card card3("��ľ�", 50, "��ȸ��ī��");                                    //��ȸ��ī�尴ü ����!

	customer cust[100];   //ȸ����ü 100�� ����!
	int cusNum = 0;       //���� ������� ������ ȸ����ȣ ����!

	manager loaner;    //���⸸ �����ϴ� ����Ŵ��� ����!
	manager saver;     //���ݸ� �����ϴ� ���ݸŴ��� ����!
	manager carder;    //ī�常 �����ϴ� ī��Ŵ��� ����!

	manager searcher;  //��������ȸ�� �����ϴ� ��ȸ�Ŵ��� ����!

	//����Ŵ����� ������ �����ǰ�� ���//
	loaner.magsetting(loan1, 0);
	loaner.magsetting(loan2, 1);
	loaner.magsetting(loan3, 2);

	//���ݸŴ����� ������ ���ݻ�ǰ�� ���//
	saver.magsetting(save1, 0);
	saver.magsetting(save2, 1);
	saver.magsetting(save3, 2);

	//ī��Ŵ����� ������ ī���ǰ�� ���//
	carder.magsetting(card1, 0);
	carder.magsetting(card2, 1);
	carder.magsetting(card3, 2);

	while (true)
	{
		cout << "**************************ȫ������ ���α׷�**************************" << endl << endl;
		int sel = 0;
		cout << "���ϴ� �۾��� �����ϼ���.\n" << "1. �ű�ȸ�� ��� \n" << "2. ����ȸ�� ��ȸ" << endl << "3. ������ \n" << endl << "����: ";
		cin >> sel; //���ϴ� �۾� ����
		system("cls");
		switch (sel)
		{
		case 1:
		{cusNum++;
		if (cusNum > 100) //������ ȸ����ü�� ��� ����ϸ� �� �̻� �ű�ȸ�� ����� �Ұ���
		{
			cout << "ȸ������� ��� �ԷµǾ����ϴ�. �ű�ȸ�� ����� �� �̻� �Ұ����մϴ�." << endl << endl;
			break;
		}

		cout << "---------------�ű�ȸ�� ���---------------" << endl << endl;
		getchar();
		cust[cusNum - 1].numsetting(cusNum);   //ȸ����ȣ ����
		cust[cusNum - 1].namesetting();        //ȸ���̸� �Է�
		cust[cusNum - 1].incomesetting();      //ȸ�������� �Է�
		//system("cls");
		cust[cusNum - 1].custshow();           //�Էµ� ȸ�������� ���
		cout << endl;
	s:;
		cout << "===============����===============" << endl << endl;
		cout << "1.����\n2.����\n3.ī��" << endl;
		int a = 0;
		cout << "� ���񽺸� �̿��Ͻðڽ��ϱ�?(��ȣ�Է�): ";
		cin >> a;    //�̿��� �������� ����
		cout << endl;
		system("cls");
		if (a == 1)  //���⼭�� ����
		{
			loaner.loanmanagement(cust[cusNum - 1]);   //����Ŵ����� �ڽ��� ������Ͽ� �ִ� �����ǰ���� ���� ����
		}
		else if (a == 2)  //���ݼ��� ����
		{
			saver.savingmanagement(cust[cusNum - 1]);  //���ݸŴ����� �ڽ��� ������Ͽ� �ִ� ���ݻ�ǰ���� ���� ����
		}
		else if (a == 3)  //ī�弭�� ����
		{
			carder.cardmanagement(cust[cusNum - 1]);   //ī��Ŵ����� �ڽ��� ������Ͽ� �ִ� ī���ǰ���� ���� ����
		}

		else  //������ ��� ��ȣ �Է�
		{
			cout << "\n1~3�� �߿� ���ÿ�" << endl;
			goto s;
		}
		cout << endl;
		cout << "\n�� ���񽺿� �ϳ��� ��ǰ�� ��밡���մϴ�, �ߺ����� ������ ���񽺴� ������ϴ�.";
		cout << endl;
	d:;
		cout << "��ǰ����� ����Ͻðڽ��ϱ�?(����� 1 �׸��� 0):"; //�����ؼ� �ٸ����񽺵��� �̿����� ���� ����
		int b;
		cin >> b;
		if (b == 1)
		{
			system("cls");
			goto s;
		}
		else if (b == 0)
		{
			searcher.custinforshow(cust[cusNum - 1]);
			cout << "�̿����ּż� �����մϴ�" << endl << endl;
		}

		else  //�������� ��� �� �Է�
		{
			cout << "\n 1�Ǵ� 0�� �����ּ��� " << endl;
			goto d;
		}
		cin.sync();  //ȸ���̸��Է��Ҷ� ���� ���۸� ���
		}
		break;

		case 2:
		{
			cout << "---------------����ȸ�� ��ȸ---------------" << endl << endl;
			string temp;
			cout << "��ȸ�ϰ����ϴ� ȸ���� �̸��� �Է��ϼ���: ";
			cin >> temp; //��ȸ�ϰ����ϴ� ȸ���� �̸� �Է�
			cout << endl;
			int i = 0;
			int count = 0; //�Էµ� �̸��� ���� ���� ��
			while (i<cusNum)
			{
				if (temp == cust[i].name) // �̸�,���� �̸��� �����̺��� �ؾߵǴµ� ����ȸ�� ��ȸ�ҋ� �̸����� ������ �Լ� ����� �����Ƽ� �ۺ����� �ű�.
				{
					searcher.custinforshow(cust[i]); //��ȸ�Ŵ����� cust[i]���� ������ ������
					count++;

				}
				i++;
			}
			if (count == 0)        //�ƹ��� ���� ��
				cout << "�׷��� �̸��� ���� �����ϴ�" << endl;
		}
		break;
		case 3:
			cout << "���α׷��� �����մϴ�";
			return 0;
		}
	}

}




