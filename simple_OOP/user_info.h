#ifndef USER_INFO
#define USER_INFO

#include<iostream>
#include<string>
#include<map>
#include<cstring>
#include<fstream>
#include<map>
#define newin "\n--------------------------\n"
#define USER_LIST_FILE "user_list"
#define STR_MAX 30
using namespace std;

struct User {
	char name[STR_MAX];
	int reli_rank;
	char cell_number[STR_MAX];
	char email[STR_MAX];
	char password[STR_MAX];
	char user_id[STR_MAX];

	User():reli_rank(-1) {};
	User(string nam, string cel_n, string uid, string pwd, string eml):reli_rank(0){
		strcpy(name, nam.c_str());
		strcpy(cell_number, cel_n.c_str());
		strcpy(user_id, uid.c_str());
		strcpy(password, pwd.c_str());
		strcpy(email, eml.c_str());
	};
	void showPri_info();
};



#endif