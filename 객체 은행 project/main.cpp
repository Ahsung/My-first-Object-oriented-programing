#include<iostream>
#include<string>
using namespace std;
#include "saving.h"
#include "financeservice.h"
#include "loan.h"
#include "customer.h"
#include "card.h"
#include "manager.h"

int main(void)
{
	loan loan1(15, "신용등급대출", true);  // 신용등급대출객체 생성!
	loan loan2(20, "일반등급대출");        // 일반등급대출객체 생성! 
	loan loan3(25, "위험등급대출");        // 위험등급대출객체 생성!

	saving save1(5, "고이율적금", true);   //고이율적금객체 생성!
	saving save2(2.5, "일반이율적금");     //일반이율적금객체 생성!
	saving save3(2, "저이율적금");         //저이율적금객체 생성!

	card card1("요식업, 편의시설, 엔터테이먼트", 100, "우수회원카드", true);   //우수회원카드객체 생성!
	card card2("요식업, 편의시설", 60, "일반회원카드");                        //일반회원카드객체 생성!
	card card3("요식업", 50, "준회원카드");                                    //준회원카드객체 생성!

	customer cust[100];   //회원객체 100명 생성!
	int cusNum = 0;       //가입 순서대로 기입할 회원번호 생성!

	manager loaner;    //대출만 관리하는 대출매니저 생성!
	manager saver;     //적금만 관리하는 적금매니저 생성!
	manager carder;    //카드만 관리하는 카드매니저 생성!

	manager searcher;  //고객정보조회를 관리하는 조회매니저 생성!

	//대출매니저가 관리할 대출상품들 등록//
	loaner.magsetting(loan1, 0);
	loaner.magsetting(loan2, 1);
	loaner.magsetting(loan3, 2);

	//적금매니저가 관리할 적금상품들 등록//
	saver.magsetting(save1, 0);
	saver.magsetting(save2, 1);
	saver.magsetting(save3, 2);

	//카드매니저가 관리할 카드상품들 등록//
	carder.magsetting(card1, 0);
	carder.magsetting(card2, 1);
	carder.magsetting(card3, 2);

	while (true)
	{
		cout << "**************************홍익은행 프로그램**************************" << endl << endl;
		int sel = 0;
		cout << "원하는 작업을 선택하세요.\n" << "1. 신규회원 등록 \n" << "2. 기존회원 조회" << endl << "3. 나가기 \n" << endl << "선택: ";
		cin >> sel; //원하는 작업 선택
		system("cls");
		switch (sel)
		{
		case 1:
		{cusNum++;
		if (cusNum > 100) //생성된 회원객체를 모두 사용하면 더 이상 신규회원 등록은 불가능
		{
			cout << "회원목록이 모두 입력되었습니다. 신규회원 등록은 더 이상 불가능합니다." << endl << endl;
			break;
		}

		cout << "---------------신규회원 등록---------------" << endl << endl;
		getchar();
		cust[cusNum - 1].numsetting(cusNum);   //회원번호 기입
		cust[cusNum - 1].namesetting();        //회원이름 입력
		cust[cusNum - 1].incomesetting();      //회원연수입 입력
		//system("cls");
		cust[cusNum - 1].custshow();           //입력된 회원정보를 출력
		cout << endl;
	s:;
		cout << "===============서비스===============" << endl << endl;
		cout << "1.대출\n2.적금\n3.카드" << endl;
		int a = 0;
		cout << "어떤 서비스를 이용하시겠습니까?(번호입력): ";
		cin >> a;    //이용할 금융서비스 선택
		cout << endl;
		system("cls");
		if (a == 1)  //대출서비스 선택
		{
			loaner.loanmanagement(cust[cusNum - 1]);   //대출매니저가 자신의 관리목록에 있는 대출상품들을 고객과 연동
		}
		else if (a == 2)  //적금서비스 선택
		{
			saver.savingmanagement(cust[cusNum - 1]);  //적금매니저가 자신의 관리목록에 있는 적금상품들을 고객과 연동
		}
		else if (a == 3)  //카드서비스 선택
		{
			carder.cardmanagement(cust[cusNum - 1]);   //카드매니저가 자신의 관리목록에 있는 카드상품들을 고객과 연동
		}

		else  //범위를 벗어난 번호 입력
		{
			cout << "\n1~3번 중에 고르시오" << endl;
			goto s;
		}
		cout << endl;
		cout << "\n한 서비스에 하나의 상품만 사용가능합니다, 중복사용시 이전의 서비스는 사라집니다.";
		cout << endl;
	d:;
		cout << "상품등록을 계속하시겠습니까?(계속은 1 그만은 0):"; //연속해서 다른서비스들을 이용할지 말지 결정
		int b;
		cin >> b;
		if (b == 1)
		{
			system("cls");
			goto s;
		}
		else if (b == 0)
		{
			searcher.custinforshow(cust[cusNum - 1]);
			cout << "이용해주셔서 감사합니다" << endl << endl;
		}

		else  //범위에서 벗어난 값 입력
		{
			cout << "\n 1또는 0을 눌러주세요 " << endl;
			goto d;
		}
		cin.sync();  //회원이름입력할때 생긴 버퍼를 비움
		}
		break;

		case 2:
		{
			cout << "---------------기존회원 조회---------------" << endl << endl;
			string temp;
			cout << "조회하고자하는 회원의 이름을 입력하세요: ";
			cin >> temp; //조회하고자하는 회원의 이름 입력
			cout << endl;
			int i = 0;
			int count = 0; //입력된 이름을 갖는 고객의 수
			while (i<cusNum)
			{
				if (temp == cust[i].name) // 이름,원래 이름은 프라이빗에 해야되는데 기존회원 조회할떄 이름값을 리턴할 함수 만들기 귀찮아서 퍼블릭으로 옮김.
				{
					searcher.custinforshow(cust[i]); //조회매니저가 cust[i]고객의 정보를 보여줌
					count++;

				}
				i++;
			}
			if (count == 0)        //아무도 없을 시
				cout << "그러한 이름의 고객은 없습니다" << endl;
		}
		break;
		case 3:
			cout << "프로그램을 종료합니다";
			return 0;
		}
	}

}




