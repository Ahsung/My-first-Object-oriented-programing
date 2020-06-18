#include "Autentication.h"


Authentication::Authentication(Database<User> &d):user_DB(&d){
	User temp;

	for (int i = 0; i < d.dataSize(); i++) {
		if (i == 0 && d.cur_idx() != 0)
			temp = d.read(0);
		else
			temp = d.read();

		user_list[temp.user_id] = temp;
	}

}

void Authentication::init_user_list() {
	this->user_list.clear();
	User temp;
	for (int i = 0; i < user_DB->dataSize(); i++) {
		temp = user_DB->read();
		user_list[temp.user_id] = temp;
	}
}

void Authentication::signUp()
{
	cout << newin;
	string name, id, cell_number, pwd, email;
	do {
		cout << "Input ID:";
		cin >> id;
		if (user_list.count(id))
			cout << "Duplicate ID." << endl;
		else break;
	} while (1);

	cout << "Enter Password:";
	cin >> pwd;

	cout << "Enter Name:";
	cin >> name;

	cout << "Enter Phone Number:";
	cin >> cell_number;

	cout << "Enter Email:";
	cin >> email;

	User newu(name, cell_number, id, pwd, email);
	user_list[id] = newu;
	this->user_DB->write(newu);
	this->user_DB->flush(); // not buffering
}

bool Authentication::signIn() {
	string id;
	string pw;
	cout << newin;
	cout << "Enter ID:";
	cin >> id;
	cout << "Enter Password:";
	cin >> pw;

	if(this->user_list.count(id) == 0){
		return false;
	}
	else if (this->user_list[id].password == pw) {
		this->cUsr = user_list[id];
		return true;
	}
	else
		return false;
}

void Authentication::signOut() {
	this->cUsr = User();
}

//Debuging function
void Authentication ::show_user_list_info(){
	
	for (auto usr : this->user_list) {
		usr.second.showPri_info();
	}
	cout << "DataBase Size: " << this->user_DB->dataSize() << endl;
}