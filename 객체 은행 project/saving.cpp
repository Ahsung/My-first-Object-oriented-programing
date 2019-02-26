#include<iostream>
#include<string>
using namespace std;

#include "financeservice.h"
#include "saving.h"
//적금 구현부
void saving::show()  // 적금정보 보기
{
	dshow();
	cout << endl;
	cout << "금리: "<<intrate<<"%" << "  개월 수: " << month <<"개월"<< "  월 입금액:" << money<<"만원" << endl;
}
void saving::setting()    //적금 정보설정
{
	cout << "적금개월 입력:";
	cin >> this->month;
	cout << "월 입금액 입력(만원):";
	cin >> this->money;
}
void saving::Nameshow()  //적금 고유정보 보기
{
	dshow();
	cout << "  금리:" << this->intrate <<"%"<< endl;
}
void saving::maturityamount()             //적금만기 금액 출력
{
	      
	double mount=0;

	for (int i = 0; i < month; i++)
	{
		double ratepd = 1;

		for (int j = 0; j <= i; j++)
		{
			ratepd *=(1+ (intrate/100));
		}
		mount += (ratepd*money);

	}
	cout << "만기금액: "<<mount<<"만원"<<endl;
}