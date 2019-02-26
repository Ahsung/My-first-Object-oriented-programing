#ifndef MANAGER_H
#define MANAGER_H
#include<string>
; using namespace std;
//매니저 선언부
#include "saving.h"
#include "financeservice.h"
#include "loan.h"
#include "customer.h"
#include "card.h"



class manager
{
private:
	loan lo[3];      //매니저가 관리하는 대출서비스
	saving sa[3];    //매니저가 관리하는 적금서비스    
	card ca[3];      //매니저가 관리하는 카드서비스
public:

	void magsetting(loan a, int b);        //관리하는 대출셋팅  
	void magsetting(saving a, int b);       //관리하는 적금셋팅  ( b는 몇 번째 배열에 저장할지 지정하는 변수)
	void magsetting(card a, int b);        //관리하는 카드셋팅

	void magloanshow();                     //관리하는 대출상품 보기
	void magsavingshow();                   //관리하는 적금상품 보기
	void magcardshow();                     //관리하는 카드상품 보기
	void loanmanagement( customer b);      //대출서비스 b고객과 연동 
	void savingmanagement( customer b);     //적금서비스 b고객과 연동
	void cardmanagement( customer b);       // 카드서비스 b고객과 연동
	void custinforshow(customer a);         //a고객의 모든정보와 사용중인 서비스의 정보를 보여줌
	
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