#ifndef CARD_H
#define CARD_H
#include<string>
; using namespace std;
//카드 선언부
#include "financeservice.h"

class card : public financeservice
{
private:
	string salelist;
	int limit;
	int password;
public:
	card(string a = "없음", int b = 0, string pn = "없음", bool ex = false) :financeservice(pn, ex)
		//할인목록, 한도, 상품이름, 우수//
	{
		this->salelist = a;
		this->limit= b;
		this->password = 0;
	}
	void show();        //카드정보(모든정보) 보기
	void setting();     //카드 비밀번호 설정
	void Nameshow();    //카드 고유정보(이름,등급,할인목록,한도) 보기
};

#endif 