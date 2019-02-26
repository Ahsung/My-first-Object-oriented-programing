#ifndef FINANCESERVICE_H
#define FINANCESERVICE_H
#include<string>
using namespace std;
//금융상품 선언부
class financeservice{
private:
	string product;    //상품이름
	bool excellence;   //우수자
public:
	financeservice(string pn = "없음", bool ex = false)  //상품이름, 우수
	{
		product = pn;       //상품이름
		excellence = ex;    //우수자
	}
	void dshow();           //금융상품정보 보기
	bool excell();
}

#endif