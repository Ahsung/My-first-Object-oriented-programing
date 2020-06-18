#include "product.h"


void product::showInfo() {
	cout << newin;
	cout << "Product Number : " << this->pd_num << endl;
	cout << "Product Name : " << this->pd_name << endl;
	cout << "Product Cost : " << this->pd_cost << endl;
	cout << "Product quantity : " << this->pd_quantity << endl;
	if (this->pd_seller.reli_rank >= 0)
		cout << "Product Seller : " << this->pd_seller.user_id << endl;
	else
		cout << "Not exist Seller" << endl;
	if (this->pd_buyer.reli_rank >= 0)
		cout << "Product Current Bidder : " << this->pd_buyer.user_id << endl;
	else
		cout << "On Sale" << endl;

	if (!this->valid)
		cout << "Product Sold" << endl;
}

Product_manger::Product_manger(Database<product>& d):pd_DB(&d) {
	product temp;
	this->pd_list.clear();

	for (int i = 0; i < d.dataSize(); i++) {
		if (i == 0 && d.cur_idx() != 0)
			temp = d.read(0);
		else
			temp = d.read();

		pd_list.push_back(temp);
	}

}

void Product_manger::show_pd_list(int flag) {
	int list = 0;

	for (auto pd : this->pd_list) {
		if (pd.valid) {
			if (flag == All_pd || flag == Selling_pd) 
				list++,pd.showInfo();
		}
		else {
			if (flag == All_pd || flag == Sold_pd) {
				list++,pd.showInfo();
			}
		}
	}
	cout << "\nList Count : " << list << endl;
}

void Product_manger::upLoad_pd(User seller) {
	int newPd_num = this->pd_list.size();
	string name;
	int cost;
	int quantity;

	cout << newin;
	cout << "Enter Product Name : ";
	cin >> name;
	cout << "Enter Product Cost : ";
	cin >> cost;
	cout << "Enter Product Quantity : ";
	cin >> quantity;

	product newPd(newPd_num, name, seller, cost, quantity);


	this->pd_list.push_back(newPd);
	this->pd_DB->write(newPd);
	this->pd_DB->flush(); // not buffering
}

bool Product_manger::bid(User buyer,int pd_idx) {
	if (pd_idx >= this->pd_list.size()) return false;
	product& cpd = this->pd_list[pd_idx];
	if (!cpd.valid) return false;
	int cost;
	cout << "Enter Bidding Cost ( over " << cpd.pd_cost << " ) :";
	cin >> cost;
	if (cost <= cpd.pd_cost) return false;

	cpd.pd_cost = cost;
	cpd.pd_buyer = buyer;
	this->pd_DB->write(cpd, pd_idx);
	this->pd_DB->flush();
	return true;
}

void Product_manger::show_bid_pd(User usr) {
	int list = 0;
	for (auto pid : this->pd_list) {
		if (strcmp(usr.user_id, pid.pd_buyer.user_id) == 0) {
			pid.showInfo(); list++;
			if (!pid.valid)
				cout << "Complete Bid!" << endl;
			else
				cout << "Bidding in progress" << endl;
		}
	}
	cout << "\nList Count : " << list<<endl;

}

void Product_manger::show_sell_pd(User usr) {
	int list = 0;
	for (auto pid : this->pd_list) {
		if (strcmp(usr.user_id, pid.pd_seller.user_id) == 0) {
			pid.showInfo(); list++;
			if (!pid.valid)
				cout << "Complete Sold!" << endl;
			else
				cout << "Selling in progress" << endl;
		}
	}
	cout << "\nList Count : " << list<<endl;
}

bool Product_manger::finish_Bid(User usr, int idx) {
	product& cpd = this->pd_list[idx];
	if (strcmp(usr.user_id, cpd.pd_seller.user_id) != 0) return false;
	if (!cpd.valid) return false;

	cpd.valid = false;
	this->pd_DB->write(cpd, idx);
	this->pd_DB->flush();
}

//Debuging function
void Product_manger::show_pd_list_info() {
	this->show_pd_list();
	cout << "DataBase Size: " << this->pd_DB->dataSize() << endl;
}