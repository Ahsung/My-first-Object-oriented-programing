#include<iostream>
#include<string>
using namespace std;
//카드 구현부
#include"financeservice.h"
#include"card.h"

void card::show()  //카드정보 보기
{
	dshow();
	cout << endl;
	cout << "할인목록: " << this->salelist << "  한도금액: " << this->limit<<"만원" <<"  비밀번호: "<<password<< endl;
}
void card::setting()     //카드 비밀번호 설정
{
	cout << "비밀번호 입력:";
	cin >> password;
}
void card::Nameshow()   //카드 고유정보 보기
{
	dshow();
	cout << "  할인목록:" << this->salelist << "  한도금액:" << this->limit << "만원" << endl;
}