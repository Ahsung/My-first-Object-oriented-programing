#ifndef FINANCESERVICE_H
#define FINANCESERVICE_H
#include<string>
using namespace std;
//������ǰ �����
class financeservice{
private:
	string product;    //��ǰ�̸�
	bool excellence;   //�����
public:
	financeservice(string pn = "����", bool ex = false)  //��ǰ�̸�, ���
	{
		product = pn;       //��ǰ�̸�
		excellence = ex;    //�����
	}
	void dshow();           //������ǰ���� ����
	bool excell();
}

#endif