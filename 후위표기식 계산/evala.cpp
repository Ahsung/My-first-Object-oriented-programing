#include<iostream>
#include<stack>
#include "post.h"
#include<map>
#include<cstring>
using namespace std;
ostream& operator<<(ostream&, Token);
Token NextToken(Expression&);

struct cmp_str{
	bool operator()(char const *a, char const *b)
	{
		return strcmp(a, b) < 0;
	}
};
map<char *, float, cmp_str> ST;
map<char *, float, cmp_str> ::iterator iter;
float GetVal(Token& opnd){
	if (opnd.type == NUM) return opnd.val;
	else if (opnd.type == ID){
		iter = ST.find(opnd.str);
		return iter->second;
	}
	return 0;
}

Token Unaryop(int op, Token& x)
{
	if (!x.IsOperand()) throw "Operand Only for Unary Operator";
	Token tmp; tmp.type = NUM;
	if (op == UMINUS) tmp.val = -GetVal(x);
	else if (op == '!') tmp.val = ! GetVal(x);
	else throw "InValid unary operator";
	return tmp;
}

Token BinaryOp(int op, Token& left, Token& right)
{
	if (!left.IsOperand() || !right.IsOperand())
		throw "Two Operands required for Binary Operation";
	Token tmp; tmp.type = NUM;
	float val1 = GetVal(left), val2 = GetVal(right);
	if (op == '+') tmp.val = val1 + val2;
	else if (op == '-') tmp.val= val1 - val2;
	else if (op == '*') tmp.val = val1*val2;
	else if (op == '/') tmp.val = val1 / val2;
	else if (op == '<') tmp.val = val1 < val2;
	else if (op == '>') tmp.val = val1 > val2;
	else if (op == GE) tmp.val = val1 >= val2;
	else if (op == LE) tmp.val = val1 <= val2;
	else if (op == EQ) tmp.val = val1 == val2;
	else if (op == NE) tmp.val = val1 != val2;
	else if (op == AND) tmp.val = val1 && val2;
	else if (op == OR) tmp.val = val1 || val2;
	else if (op == '=' && left.type == ID){
		ST[left.str] = val2;
		left.val = val2;
		return left;
	}
	else throw "No such binary operator";
	return tmp;
}
void Eval(Expression e)
{
	stack<Token> stack;
	Token opnd1, opnd2;
	for (Token x = NextToken(e); x.type != '#'; x = NextToken(e))
		if (x.IsOperand()) stack.push(x);
		else{
			int op = x.type;
			if (op == UMINUS || op == '!'){
				opnd1 = stack.top(); stack.pop();
				stack.push(Unaryop(op, opnd1));
			}
			else {
				opnd2 = stack.top(); stack.pop();
				opnd1 = stack.top(); stack.pop();
				stack.push(BinaryOp(op, opnd1, opnd2));			
			}
		}
		cout << stack.top() << endl; stack.pop();
}