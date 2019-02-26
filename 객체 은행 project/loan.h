#ifndef LOAN_H
#define LOAN_H
//대출 선언부

#include "financeservice.h"

; using namespace std;

class loan :public financeservice
{
private:
	double interest;   //이자
	int loanmoney;     //대출액
	int monthplan;     //할부
public:
	loan(double in = 0,  string pn = "없음", bool ex = false) :financeservice(pn, ex)
		//이자, 상품이름, 우수//
	{
		interest = in;
		loanmoney = 0;
		monthplan = 0;
	}
	void Nameshow();               //대출상품 고유 상품정보(이름,이자,등급) 보기
	void show();                   //대출정보 보기(모든 정보)
	void setting();                //회원이 직접 입력하여 가변 상품정보(대출액,할부)를 설정
}


#endif
