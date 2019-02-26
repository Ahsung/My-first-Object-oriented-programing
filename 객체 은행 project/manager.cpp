#include<iostream>
#include<string>
using namespace std;
//매니저 구현부
#include "saving.h"
#include "financeservice.h"
#include "loan.h"
#include "customer.h"
#include "card.h"
#include "manager.h"

void manager::magsetting(loan a, int b)            //대출 a를 매니저 멤버대출(매니저가 관리하는 대출)에 저장
{
	this->lo[b] = a;
}
void manager::magsetting(saving a, int b)       //적금 a를 매니저 멤버적금(매니저가 관리하는 적금)에 저장
{
	this->sa[b] = a;
}
void manager::magsetting(card a, int b)           //대출 a를 매니저 멤버카드(매니저가 관리하는 카드)에 저장
{
	this->ca[b] = a;
}
void manager::magloanshow()                   //관리하는 대출상품 보기
{
	cout << "관리하는 대출상품: "<<endl;
	for (int i =0 ; i < 3; i++)
	{                      
		cout << i + 1 << ": ";
		lo[i].Nameshow();
		cout << endl;
	}
}
void manager::magsavingshow()                 //관리하는 적금상품 보기
{
	cout << "관리하는 적금상품: "<<endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ": ";
		sa[i].Nameshow();
		cout << endl;
	}
}
void manager::magcardshow()                   //관리하는 카드상품 보기
{
	cout << "관리하는 카드상품: "<<endl;
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
	cout << "고객님의 정보======="<<endl<<endl<<endl;
	a.custshow();
	a.serviceshow();

}
void manager::loanmanagement( customer b)        //a번째 대출서비스 b고객과 연동 
{
c:;
	int a;
	magloanshow();
	cout << "몇번 상품을 선택하시겠습니까?:";
	cin >> a;
	cout << endl;
	cout << endl;
	if (excellence(lo[a - 1], b))
	{
		cout << "-----------------선택하신 상품--------------" << endl << endl;
		lo[a - 1].Nameshow();
		cout << endl;
		lo[a - 1].setting();
		cout << endl;
		cout << "-------";
		b.custNameshow();
		b.servicesetting(lo[a - 1]);           //고객멤버에 서비스 저장!     
		cout << "고객님이 선택하신 상품은---------" << endl << endl;                
		lo[a - 1].show();
	}
	else
	{
		cout << "우수자 상품입니다 다시 골라주십시오" << endl << endl;
		goto c;
	}
}
void manager::savingmanagement( customer b)      //적금서비스 b고객과 연동
{
c:;
	int a;
	magsavingshow();
	cout << "몇번 상품을 선택하시겠습니까?:";
	cin >> a;
	cout << endl;
	cout << endl;
	if (excellence(sa[a - 1], b))
	{
		cout << "-----------------선택하신 상품--------------" << endl << endl;
		sa[a - 1].Nameshow();
		cout << endl;
		sa[a - 1].setting();
		cout << endl;
		cout << "-------";
		b.custNameshow();
		b.servicesetting(sa[a - 1]);                //고객멤버에 서비스 저장!  
		cout << "고객님이 선택하신 상품은---------" << endl << endl;
		sa[a - 1].show();
		cout << endl;
		sa[a - 1].maturityamount();
	}
	else
	{
		cout << "우수자 상품입니다 다시 골라주십시오" << endl << endl;
		goto c;
	}

}
void manager::cardmanagement( customer b)
{
c:;
	int a;
	magcardshow();
	cout << "몇번 상품을 선택하시겠습니까?:";
	cin >> a;
	cout << endl;
	cout << endl;
	if (excellence(ca[a - 1], b))
	{
		cout << "-----------------선택하신 상품--------------" << endl << endl;
		ca[a - 1].Nameshow();
		cout << endl;
		ca[a - 1].setting();
		cout << endl;
		cout << "-------";
		b.custNameshow();
		b.servicesetting(ca[a - 1]);                //고객멤버에 서비스 저장
		cout << "고객님이 선택하신 상품은---------" << endl << endl;       
		ca[a - 1].show();
	}
	else
	{
		cout << "우수자 상품입니다 다시 골라주십시오"<<endl<<endl;
		goto c;
	}
}

