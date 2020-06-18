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
모든 User의 정보를 담고있고,
현재 Login한 User의 정보 Session을 유지하며
서비스에 이용한다.
User의 회원가입, 로그인, 로그아웃, 현재 로그인 정보 확인 기능을 갖는다.
cUsr의 reli_ranck가 -1이면 아무런 로그인 세션도 없는 상태이다.
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
