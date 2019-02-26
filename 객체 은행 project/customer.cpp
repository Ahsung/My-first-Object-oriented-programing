#include<iostream>
#include<string>
using namespace std;
//고객 구현부
#include "customer.h"

; void customer::namesetting()   // 고객정보 입력 함수
{
 
	
	cout << "이름 입력:";   
	getline(cin,name,'\n');
	cout << endl;
}
void customer::incomesetting()
{
	cout << "연봉 입력(만원):";
	cin >> this->yeerincome;
	cout << endl;
}
void customer::custshow()             //고객정보 보기 함수
{                   
	cout <<"이름: "<< name<<"  연봉: " << yeerincome <<"만원"<<"  회원번호:"<<num<< endl;
	if (excellence() == true)
		cout << "우수자입니다." << endl;
	else
		cout << "일반입니다." << endl;
}
void customer::custNameshow()
{
	cout << num << "번 " << name;        //번호와 이름 간단출력 ex) 01번 홍길동
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
void customer::serviceshow()                   //사용중인 서비스상품 보기
{
	cout << "---------사용중인 대출상품---------" << endl;
	loservice.show();
	cout << endl;
	cout << "---------사용중인 적금상품---------"<<endl;
	saservice.show();
	cout << endl;
	cout << "---------사용중인 카드상품---------"<<endl;
	caservice.show();
	cout << endl;
}




