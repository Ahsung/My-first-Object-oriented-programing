#ifndef PRODUCT
#define PRODUCT
#include<string>
#include "user_info.h"
#include "database.h"
#include<cstring>
#include<vector>

#define All_pd 0
#define Selling_pd 1
#define Sold_pd 2
#define PRODUCT_LIST_FILE "product_list"
using namespace std;

/*
판매되는 물품의 정보를 담은 구조체이다.
판매번호, 물품 이름, 판매자, 구매자, 현재 입찰시작 가능 가격
vaild는 입찰이 완료됬는지 입찰중인지 status, 그리고 물량
*/
struct product
{
	int pd_num;
	char pd_name[STR_MAX];
	User pd_seller;
	User pd_buyer;
	int pd_cost;
	bool valid;
	int pd_quantity;
public:
	product() :pd_num(-1),pd_cost(0),valid(false),pd_quantity(0) {
		strcpy(pd_name, "None");
	};
	product(int num, string name,User seller, int cost, int quantity) :pd_num(num),pd_seller(seller),
		valid(true),pd_cost(cost),pd_quantity(quantity) {
		strcpy(pd_name, name.c_str());
	}

	void showInfo();
};

/*
Product_manger로서
모든 product를 관리할 수 있는 함수를 제공하고,
데이터베이스에 추가 및 수정을 한다.
*/
class Product_manger {
	vector<product> pd_list;
	Database<product> *pd_DB;
public:
	Product_manger(Database<product>& d);
	void show_pd_list(int flag = All_pd);
	void upLoad_pd(User seller);
	bool bid(User buyer,int pd_idx);
	void show_bid_pd(User usr);
	void show_sell_pd(User usr);
	bool finish_Bid(User usr, int idx);

	//Debuging function
	void show_pd_list_info();
};

#endif

