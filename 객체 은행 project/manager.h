#ifndef MANAGER_H
#define MANAGER_H
#include<string>
; using namespace std;
//�Ŵ��� �����
#include "saving.h"
#include "financeservice.h"
#include "loan.h"
#include "customer.h"
#include "card.h"



class manager
{
private:
	loan lo[3];      //�Ŵ����� �����ϴ� ���⼭��
	saving sa[3];    //�Ŵ����� �����ϴ� ���ݼ���    
	card ca[3];      //�Ŵ����� �����ϴ� ī�弭��
public:

	void magsetting(loan a, int b);        //�����ϴ� �������  
	void magsetting(saving a, int b);       //�����ϴ� ���ݼ���  ( b�� �� ��° �迭�� �������� �����ϴ� ����)
	void magsetting(card a, int b);        //�����ϴ� ī�����

	void magloanshow();                     //�����ϴ� �����ǰ ����
	void magsavingshow();                   //�����ϴ� ���ݻ�ǰ ����
	void magcardshow();                     //�����ϴ� ī���ǰ ����
	void loanmanagement( customer b);      //���⼭�� b���� ���� 
	void savingmanagement( customer b);     //���ݼ��� b���� ����
	void cardmanagement( customer b);       // ī�弭�� b���� ����
	void custinforshow(customer a);         //a���� ��������� ������� ������ ������ ������
	
	template<typename Y>
	bool excellence(Y a, customer b)
	{
		if (b.excellence() == true)
			return true;
		else if (a.excell() == b.excellence())
			return true;
		else
			return false;
	}
	
};
#endif