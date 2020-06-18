#include "user_info.h"
using namespace std;


void User::showPri_info() {
	cout << newin;
	cout << "ID: " << this->user_id << endl;
	cout << "name: " << this->name << endl;
	cout << "phone number: " << this->cell_number << endl;
	cout << "email: " << this->email << endl;
	cout << "pass: " << this->password << endl;
	cout << "reli: " << this->reli_rank << endl;
};