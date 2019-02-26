/*#include<iostream>
#include"post.h"
#include <stack>
using namespace std;
void Postfix(Expression);
int main(){
         char linebuf[MAXLEN];
         while (cin.getline(linebuf, MAXLEN)){

                 Expression e(linebuf, true);

                 try{ Postfix(e); }
                 catch (char const *msg){
                         cerr << "Exception: " << msg << endl;
		}
	}
}*/
#include<iostream>
#include "post.h"
using namespace std;
void Eval(Expression);

int main(void){
	char line[MAXLEN];
	while (cin.getline(line, MAXLEN)){
		Expression e(line);
		try {
			Eval(e);
		}
		catch (char const *msg){
			cerr << "Excption: " << msg << endl;
		}
	}
}

