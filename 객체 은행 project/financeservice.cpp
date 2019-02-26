#include<iostream>
#include<string>
using namespace std;
//금융상품 구현부
#include "financeservice.h"


void financeservice::dshow(){
	string a;
	 if(excellence == true)
	{
		a = "우수자";
	}
	
	if(excellence == false)
	{
		a = "일반";
	}
	
	cout << "상품이름:" << product << "  등급:"<<a<<"  ";
}
bool financeservice::excell()
{
	return excellence;
}

