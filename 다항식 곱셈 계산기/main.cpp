#include<iostream>
#include"polyb.h"
using namespace std;
int main()
{
	Polynomial p1, p2, p3;
	cin >> p1 >> p2;

	p3 = p1 * p2;

	cout << p1 << endl << p2 << endl << p3;
}