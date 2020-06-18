#include<iostream>
#include<string>
#include "database.h"
#include "Autentication.h"
#include "product.h"

#define SIGN_PAGE 1
#define MENU_PAGE 2
#define EXIT_PAGE 0
using namespace std;

map<string, User> user_List;

int startSignPage(Authentication& au); // 로그인,회원가입 page
int startMenuPage(Authentication& au, Product_manger& pm); //menu page


int main() {

	Database<User> userDb(USER_LIST_FILE);
	Database<product> pdDb(PRODUCT_LIST_FILE);

	Authentication au(userDb);
	Product_manger pm(pdDb);
	
	/*Print DataBase for Debug*/
	//au.show_user_list_info();
	///pm.show_pd_list_info();
	
	int page_flag = SIGN_PAGE;

	//상태에 따라 page 변경
	while (1) {
		switch (page_flag)
		{
		case SIGN_PAGE : page_flag = startSignPage(au);
						break;
		case MENU_PAGE: page_flag = startMenuPage(au,pm);
						break;
		case EXIT_PAGE: 
			return 0;
		}
	}

}

//---------------------------------function Difinition---------------------------------

//원하는 서비스 제공후 반환
// 로그인 성공시 menu로 이동
int startSignPage(Authentication& au) {
	string command;
		cout << newin;
		cout << "1. Sign In   \n";
		cout << "2. Sing Up\n";
		cout << "0. exit     \n";
		cout << "\nEnter number:";
		cin >> command;

		if (command == "2") {
			au.signUp();
			return SIGN_PAGE;
		}
		else if (command == "0") {
			return EXIT_PAGE;
		}
		else if (command == "1") {
			if (au.signIn()) return MENU_PAGE;
			else cout << "Wrong Input\n";
		}
		else {
			return SIGN_PAGE;
		}
}

// menu page에서는 각 input command에 따라 원하는 서비스를 제공후 반환
int startMenuPage(Authentication &au,Product_manger &pm) {
	string command;

		cout << newin;
		cout << "1. Show User Info\n";
		cout << "2. Search Selling Product\n";
		cout << "3. UpLoad Product\n";
		cout << "4. My Sale Product\n";
		cout << "5. My Bid Product\n";
		cout << "6. Sign Out\n";
		cout << "0. exit\n";
		cout << "\nEnter number:";
		cin >> command;

		if (command == "1") {
			au.get_User().showPri_info();
		}
		else if (command == "2") {
			pm.show_pd_list(Selling_pd);
			cout << "Enter Product_number you wanna bid [Cancel (c)]: ";
			cin >> command;
			if (command == "c") return MENU_PAGE;
			try {
				if (pm.bid(au.get_User(), stoi(command)))
					cout << "Success Bid" << endl;
				else
					cout << "Fail Bid" << endl;
			}
			catch (...) {
				cout << "Not Intager" << endl;
			}
		}
		else if (command == "3") {
			pm.upLoad_pd(au.get_User());
		}
		else if (command == "4") {
			pm.show_sell_pd(au.get_User());
			cout << "Enter Product_number you wanna finish Bidding [Cancel (c)]: ";
			cin >> command;
			if (command == "c") return MENU_PAGE;
			if (pm.finish_Bid(au.get_User(), stoi(command)))
				cout << "Success finish" << endl;
			else
				cout << "Already Finish or Not your Product" << endl;
		}
		else if (command == "5") {
			pm.show_bid_pd(au.get_User());
		}
		else if (command == "6") {
			au.signOut();
			return SIGN_PAGE;
		}
		else if (command == "0") {
			return EXIT_PAGE;
		}
		else {
			return MENU_PAGE;
		}

		return MENU_PAGE;
}