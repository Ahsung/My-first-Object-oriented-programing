#ifndef SAVING_H
#define SAVING_H
#include<string>
; using namespace std;

#include "financeservice.h"
//적금 선언부

; class saving :public financeservice
{
private:
	double intrate;  //금리
	int month;       //개월
	int money;       //월 입금액
public:
	saving(double ir = 0, string pn = "없음", bool ex = false) :financeservice(pn, ex)
	//금리, 상품이름, 우수//
	{
		intrate = ir;
		month = 0;
		money = 0;
	}
	void Nameshow();        //적금상품 고유상품정보(이름,금리,등급) 보기
	void show();            //적금정보 보기  (모든정보)
	void setting();         //회원이 직접 입력하여(가변상품정보(개월,월 입금액)을 설정
	void maturityamount();  //만기금액을 계산하고 보여줌
		
}


#endif
