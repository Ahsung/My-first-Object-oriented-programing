#include<iostream>
#include<string>
using namespace std;
//������ǰ ������
#include "financeservice.h"


void financeservice::dshow(){
	string a;
	 if(excellence == true)
	{
		a = "�����";
	}
	
	if(excellence == false)
	{
		a = "�Ϲ�";
	}
	
	cout << "��ǰ�̸�:" << product << "  ���:"<<a<<"  ";
}
bool financeservice::excell()
{
	return excellence;
}

