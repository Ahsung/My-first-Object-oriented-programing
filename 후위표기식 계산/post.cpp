#include<iostream>
#include<stack>
#include"post.h"
using namespace std;

Token::Token(){}
Token::Token(char c) : len(1), type(c)
{
	str = new char[1]; str[0] = c;
}
Token::Token(char c,char c2, int ty) : len(2), type(ty)
{
	str = new char[2]; str[0] = c; str[1] = c2;
}
Token::Token(char* arr, int l) : type(ID), len(l)
{
	str = new char[len + l];
	for (int i = 0; i < len; i++) str[i] = arr[i];
	str[len] = '\0';
}
Token::Token(float v) : val(v), type(NUM){}

bool Token::operator==(char b){ return len == 1 && str[0] == b;}
bool Token::operator!=(char b){ return len != 1 || str[0] != b;}   
bool Token::IsOperand() { return type == ID || type == NUM; }

ostream& operator<<(ostream& os, Token t){
	if (t.type == UMINUS) os << "-u";
	/*else if (t.type == NUM && t.val == (int)t.val) printf("%.1f", t.val); // ex)34같은 수를 34.0으로 출력하게 해줌.*/
	else if (t.type == NUM) os << t.val;
	else for (int i = 0; i < t.len; i++)  os << t.str[i];
	os << " "; return os;
}

bool IsAlpha(char c){ return c >= 'a' &&c <= 'z' || c >= 'A' && c <= 'Z'; }
bool IsDigit(char c){ return c >= '0' && c <= '9'; }
bool GetID(Expression& e, Token& tok) {
	char c = e.buf[e.pos];
	if (!IsAlpha(c)) return false;
	int pos_start = e.pos; e.pos++;
	while (IsAlpha(c = e.buf[e.pos]) || IsDigit(c)) e.pos++;
	int idlen = e.pos - pos_start;
	tok = Token(e.buf + pos_start, idlen);
	return true;
	
}

bool GetNUM(Expression& e, Token& tok){
	
	char c; //ostream& operator에 else if (t.type == NUM && t.val == (int)t.val) printf("%.1f", t.val);을 추가해서 정수들을 정수.0 형태로 바꿈.
	if (!IsDigit(c = e.buf[e.pos])) return false;
	float val = c - '0'; e.pos++;
	while (IsDigit(c = e.buf[e.pos]))
	{
		val = val * 10 + c - '0'; e.pos++;
	}
	if ((c = e.buf[e.pos]) == '.'){
		e.pos++;
		int a = 1;  //소수 a번째 자리를 의미
		while (IsDigit(c = e.buf[e.pos]))
		{
			
			float b = (c - '0');
			for (int i = 0; i < a; i++){      //0.1의 a제곱만큼 곱해줌.
				b = b / (float)10;
			}
			val = val + b; e.pos++;
			a++;
		}
	}
	
	tok = Token(val);
	return true;
}

void SkipBlanks(Expression& e){
	char c;
	while (e.pos < e.len && ((c = e.buf[e.pos]) == ' ' || c == '\t'))
		e.pos++;
}
bool TwoCharOp(Expression& e, Token& tok)
{
	char c = e.buf[e.pos]; char c2 = e.buf[e.pos + 1];
	int op;
	if (c == '<' && c2 == '=') op = LE;
	else if (c == '>' && c2 == '=') op = GE;
	else if (c == '!' && c2 == '=') op = NE;
	else if (c == '=' && c2 == '=') op = EQ;
	else if (c == '&' && c2 == '&') op = AND;
	else if (c == '|' && c2 == '|') op = OR;
	else if (c == '-' && c2 == 'u') op = UMINUS;

	else return false;
	tok = Token(c, c2, op); e.pos += 2;
	return true;
}
bool OneCharOp(Expression& e, Token& tok){
	char c = e.buf[e.pos];
	if (c == '-' || c == '!' || c == '*' || c == '/' || c == '%' || c == '+' || c == '<' || c == '>' || c == '(' || c == ')' || c == '=')
	{
		tok = Token(c); e.pos++; return true;
	}
	return false;
}
Token NextToken(Expression& e){
	static bool opndFound = false;
	Token tok;
	SkipBlanks(e);
	if (e.pos == e.len)tok = Token('#');
	else if (GetID(e, tok) || GetNUM(e, tok)){}
	else if (TwoCharOp(e, tok)){}
	else if (OneCharOp(e, tok)){
		if (e.infix && tok.type == '-' && !opndFound)
			tok = Token('-', 'u', UMINUS);
	}
	else throw "I legal Character Found";
	if (e.infix) opndFound = tok.IsOperand();
	return tok;
}

int icp(Token& t){
	if (t.type == '(') return 0;
	else if (t.type == UMINUS || t.type=='!') return 1;
	else if (t.type == '*' || t.type=='/') return 2;
	else if (t.type =='+'|| t.type=='-') return 3;
	else if (t.type == '<' || t.type == '>' || t.type == GE || t.type == LE) return 4;
	else if (t.type == NE || t.type == EQ) return 5;
	else if (t.type == AND) return 6;
	else if (t.type == OR) return 7;
	else if (t.type == '=') return 8;
	else if (t.type == '#') return 10;
	else throw "그 외 문자는 오류여~";
}
int isp(Token& t){
	if (t.type == '(')return 9;
	else return icp(t);
}

void Postfix(Expression e){
	
	stack<Token> stack;
	stack.push(Token('#'));
	for (Token x = NextToken(e); x.type != '#'; x = NextToken(e))
		if (x.IsOperand()) cout << x;
		else if (x == ')'){
			for (; stack.top() != '('; stack.pop())
				cout << stack.top();
			stack.pop();
		}
		else{
			for (; isp(stack.top()) <= icp(x); stack.pop()){
				if (x.type == '=' && stack.top().type == '=') break;
				cout << stack.top();
			}
			stack.push(x);
		}
		while (stack.top() != '#'){ cout << stack.top(); stack.pop(); }
		stack.pop();
}  
