#include<iostream>
#include<string>
using namespace std;
#include "saving.h"
#include "financeservice.h"
#include "loan.h"
#include "customer.h"
#include "card.h"
#include "manager.h"
; /*int main()
{
	cout << "-------------금융상품 테스트--------------" << endl;
	financeservice abc; //기본 금융상품 생성
	financeservice ABC("사랑",true);
	abc.dshow();
	cout << endl;
	cout << endl;
	ABC.dshow();
	cout << endl;
	cout << endl;
	
	cout << endl;
	cout << endl;
	cout << "-------------대출 테스트------------------" << endl;
	loan loave;        //기본 대출상품 생성
	loan love(2.3,"행복(우수)",true);
	
	loave.show();
	cout << endl;
	love.Nameshow();
	cout << endl;
	love.show();
	cout << endl;
	
	love.show();
	
    
	cout << "-------------적금 테스트------------------" << endl;
	saving sav;     //기본 적금상품 생성
	saving save(2,"우정");
	sav.show();
	cout << endl;
    save.show();
	cout << endl;
	save.Nameshow();
	cout << endl;
	
	
	save.show();
	cout << "------------카드 테스트--------------------" << endl;
	card gi;          //기본 카드상품 생성
	card car("편의점", 800000, "우리");
	gi.show();
	cout << endl;
	car.show();

	cout << "------------매니저 테스트------------------" << endl;
	manager girl;     //기본 매니저 생성

	girl.magsetting(save, 0);
	cout << endl;
	girl.magsavingshow();
	cout << endl;
	girl.magsetting(love, 1);
	cout << endl;
	girl.magsetting(car, 0);
	girl.magloanshow();
	
	cout << "------------고객 테스트--------------------" << endl;                                                    
	customer custer[100];
	custer[0].custshow();        //기본고객 상태 정보 보기       
	cout << endl;
	    //고객정보 입력
	cout << endl;
	//customer[0].inforsetting();
	//customer[0].custshow();        입력된 고객정보 보기//
	//cout <<"우수자?(맞으면1,아니면0):"<< girl.excellence(love, customer[0]) << endl;
//	customer[0].servicesetting(car);
	//customer[0].serviceshow();
	
	                                                             // 대출 생성자 매개변수 순서 >> 이자, 상품이름, 우수          //
		                                                         // 적금 생성자 매개변수 순서  >>  금리,상품이름, 우수         //
																 // 카드 생성자 매개변수 순서 >> 할인목록, 한도, 상품이름, 우수//
	
	cout << "------------전체 테스트--------------------" << endl;
    
	loan loan1(15, "대출1(우수)", true);
	loan loan2(20, "대출2");
	loan loan3(25, "대출3");

	saving save1(5, "적금1(우수)", true);
	saving save2(2.5, "적금2");
	saving save3(2, "적금3");

	card card1("백화점,영화관", 100, "카드1(우수)", true);
	card card2("편의점", 50, "카드2");
	card card3("음식점", 50, "카드3");

	customer cust[100];
	
	manager loaner;
	manager saver;
	manager carder;

	loaner.magsetting(loan1, 0);
	loaner.magsetting(loan2, 1);
	loaner.magsetting(loan3, 2);

	saver.magsetting(save1, 0);
	saver.magsetting(save2, 1);
	saver.magsetting(save3, 2);

	carder.magsetting(card1, 0);
	carder.magsetting(card2, 1);
	carder.magsetting(card3, 2);

	customer a;
	a.servicesetting(save1);
	a.serviceshow();
	/*
	int i = 0;
       while (i<100)
	{
		
		cust[i].numsetting(i + 1);
		
		cust[i].namesetting();
		cust[i].incomesetting();
		cust[i].custshow();
	s:;
		cout << "===============서비스===============" << endl<<endl;
		cout << "1.대출\n2.적금\n3.카드" << endl;
		int a = 0;
		cout << "어떤 서비스를 이용하시겠습니까?(번호입력): ";
		cin >> a;
		if (a == 1)
		{
			loaner.loanmanagement(cust[i]);
		}
		else if (a == 2)
		{
			saver.savingmanagement(cust[i]);
		}
		else if (a == 3)
		{
			carder.cardmanagement(cust[i]);
		}
		else
		{
			cout << "\n1~3번 중에 고르시오" << endl;
			goto s;
		}
		loaner.custinforshow(cust[i]);
		cout << endl;
		cout << "\n한 서비스에 하나씩만 사용가능합니다, 중복사용시 이전의 서비스는 사라집니다.";
		cout << endl<<endl<<endl;

	d:;
		cout << "서비스를 계속이용하겠습니까?(계속은 1 그만은 0):";
		
		int b;
		
		cin >> b;
		
		if (b == 1)
		{
			goto s;
		}
		else if (b ==0)
		{
			cout << "감사합니다" << endl;
			i++;
		}
		
		else
		{
			cout << "\n 1또는 0을 눌러주세요 "<<endl;
			goto d;
		}
		cin.sync();


	}*/


