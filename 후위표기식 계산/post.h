#ifndef POSTFIX_H
#define POSTFIX_H

#define ID              257
#define NUM             258
#define EQ              259
#define NE              260
#define GE              261
#define LE              262
#define AND             263
#define OR              264
#define UMINUS  265

#define MAXLEN  80
#include<cstring>

struct Expression {
	Expression(char* linebuf, bool inf = false)
                 : buf(linebuf), pos(0), len(strlen(buf)), infix(inf){}
	   	 char *buf;
         int pos;
         int len;
         bool infix;

};

struct Token {
   		 bool operator==(char);
         bool operator!=(char);
         Token();
         Token(char);
		 Token(char, char, int);
         Token(char*,int);
         Token(float);
         bool IsOperand();
         int type;
         union{
                 struct{ char *str; int len; };
                 float val;

	};

};

#endif

