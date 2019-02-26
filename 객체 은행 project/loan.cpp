#include <iostream>
#include<string>
using namespace std;
#include "financeservice.h"
#include "loan.h"
//대출 구현부
void loan :: show()  //대출정보 보기
{
	dshow();
	cout << endl;
	cout <<"이자: "<<interest <<"%"<< "  대출액: " << loanmoney <<"원"<<"  할부: "<<monthplan<<"개월"<< endl;

}
void loan::setting()
{
	cout << "대출액 입력(만원):";
	cin >> this->loanmoney;  //대출액 설정
	cout << "할부 입력(개월):";    
	cin >> this->monthplan;  //할부 설정
}
void loan::Nameshow()      //대출 고유정보만 보기
{
	dshow();
	cout << "  이자:" << this->interest<<"%" << endl;
}
