#ifndef AUTEN
#define AUTEN

#include<iostream>
#include<string>
#include<map>
#include<cstring>
#include<fstream>
#include<map>
#include "user_info.h"
#include "database.h"
#define USER_LIST_FILE "user_list"


/*
��� User�� ������ ����ְ�,
���� Login�� User�� ���� Session�� �����ϸ�
���񽺿� �̿��Ѵ�.
User�� ȸ������, �α���, �α׾ƿ�, ���� �α��� ���� Ȯ�� ����� ���´�.
cUsr�� reli_ranck�� -1�̸� �ƹ��� �α��� ���ǵ� ���� �����̴�.
*/
class Authentication {
	User cUsr;
	map<string, User> user_list;
	Database<User> *user_DB;
public:
	Authentication(Database<User> &d);
	void signUp();
	void init_user_list();
	bool signIn();
	inline map<string, User> getUserList() { return user_list; }
	inline User get_User() { return cUsr; }
	void signOut();

	//Debuging function
	void show_user_list_info();
};
#endif
