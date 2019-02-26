#include<iostream>
#include "polyb.h"
using namespace std;

istream& operator>> (istream& is, Polynomial& p){
	int noofterms; float coef; int exp;
	cout << "항의 수 입력: ";
	is >> noofterms;
	for (int i = 0; i < noofterms; i++){
		cout << i + 1 << "번째 항 계수, 지수 입력: ";
		is >> coef >> exp;
		p.NewTerm(coef, exp);

	}
	return is;
}

ostream& operator<< (ostream& os, Polynomial& p){

	for (int i = 0; i < p.terms;){
		if (p.termArray[i].coef == 0){
			i++;
		}
		else if (i == 0){
			if (p.termArray[i].exp == 1){

				if (p.termArray[i].coef == 1){
					os << "x";
					i++;
				}
				else if (p.termArray[i].coef == -1){
					os << "-x";
					i++;
				}
				else{
					os << p.termArray[i].coef << "x";
					i++;
				}
			}
			else if (p.termArray[i].exp == 0){
				os << p.termArray[i].coef;
			}

			else{
				if (p.termArray[i].coef == 1){
					os << "x^" << p.termArray[i].exp;
					i++;
				}
				else if (p.termArray[i].coef == -1){
					os << "-x^" << p.termArray[i].exp;
					i++;
				}
				else{
					os << p.termArray[i].coef << "x^" << p.termArray[i].exp;
					i++;
				}

			}


		}

		else{
			if (p.termArray[i].exp == 1){
				if (p.termArray[i].coef == 1){
					os << "+" << "x";
					i++;
				}
				else if (p.termArray[i].coef == -1){
					os << "-" << "x";
					i++;
				}
				else if (p.termArray[i].coef > 0){
					os << "+" << p.termArray[i].coef << "x";
					i++;
				}
				else{
					os << p.termArray[i].coef << "x";
					i++;
				}
			}
			else if (p.termArray[i].exp == 0){
				if (p.termArray[i].coef > 0){
					os << "+" << p.termArray[i].coef;
					i++;
				}
				else{
					os << p.termArray[i].coef;
					i++;
				}
			}
			else{
				if (p.termArray[i].coef == 1){
					os << "+" << "x^" << p.termArray[i].exp;
					i++;
				}
				else if (p.termArray[i].coef == -1){
					os << "-" << "x^" << p.termArray[i].exp;
					i++;
				}
				else if (p.termArray[i].coef > 0){
					os << "+" << p.termArray[i].coef << "x^" << p.termArray[i].exp;
					i++;
				}
				else{
					os << p.termArray[i].coef << "x^" << p.termArray[i].exp;
					i++;
				}


			}

		}
	}
	return os;
}

Polynomial::Polynomial() :capacity(4), terms(0)
{
	termArray = new Term[capacity];
}
void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
	if (terms == capacity){
		capacity *= 2;
		Term *temp = new Term[capacity];
		for (int i = 0; i < terms; i++){
			temp[i] = termArray[i];
		}
		delete[]termArray;
		termArray = temp;
	}
	termArray[terms].coef = theCoeff;
	termArray[terms++].exp = theExp;
}
Polynomial Polynomial::operator*(Polynomial& b)
{
	Polynomial mul;
	for (int j = 0; j < terms; j++) {
		for (int i = 0; i < b.terms; i++) {
			float coef;
			int exp;
			coef = termArray[j].coef*b.termArray[i].coef;
			exp = termArray[j].exp + b.termArray[i].exp;
			if (coef)
				mul.NewTerm(coef, exp);
		}
	}
	for (int j = 0; j < mul.terms; j++)
		for (int i = j + 1; i < mul.terms; i++) {
			if (mul.termArray[j].exp < mul.termArray[i].exp)
			{
				float temcoef;
				int temexp;
				temcoef = mul.termArray[j].coef;
				mul.termArray[j].coef = mul.termArray[i].coef;
				mul.termArray[i].coef = temcoef;

				temexp = mul.termArray[j].exp;
				mul.termArray[j].exp = mul.termArray[i].exp;
				mul.termArray[i].exp = temexp;

			}
			else if (mul.termArray[j].exp == mul.termArray[i].exp) {
			
				mul.termArray[j].coef += mul.termArray[i].coef;
				mul.termArray[i].coef = 0;
			}
		}
	return mul;
}