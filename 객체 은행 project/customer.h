#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<string>
; using namespace std;

#include "financeservice.h"
#include "card.h"
#include "loan.h"
#include "saving.h"

//고객 선언부
; class customer{

private:
	
	int yeerincome;      // 연수입
	int num;             //회원 번호
	card caservice;     //사용중인 카드서비스
	loan loservice;     //사용중인 대출서비스
	saving saservice;   //사용중인 적금서비스
public:
	string name;         // 이름,원래 이름은 프라이빗에 해야되는데 기존회원 조회할떄 이름값을 리턴할 함수 만들기 귀찮아서 퍼블릭으로 옮김.
	customer()              //생성자 
	{
		name = "무";
		yeerincome = 0;
		num = 0;
		
	}
	void custNameshow();       //고객이름과 번호만 보기
	void namesetting();        //고객이름 셋팅 함수
	void incomesetting();      //고객연봉 셋팅함수
	void custshow();           //고객정보 보기
	void numsetting(int a);    //회원번호 설정
	bool excellence()
	{
		if (this->yeerincome >= 5000)
			return true;
		else
			return false;
	
	}

	//*함수중복*//
	void servicesetting(card a);           //고객이 사용중인 카드서비스 저장
	void servicesetting(loan a);          //고객이 사용중인 대출서비스 저장   
	void servicesetting(saving a);        //고객이 사용중인 적금서비스 저장
	
	void serviceshow();                   //사용중인 서비스 보기
	
	
};



#endif