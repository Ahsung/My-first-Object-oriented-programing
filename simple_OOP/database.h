#ifndef DATABASE
#define DATABASE

#include<string>
#include<fstream>
#include<iostream>
using namespace std;

/*
DataBase Object
file 명을 지정하여 Create or Open
file을 만들어 그곳에 T 타입의 데이터 객체들을 순서대로 저장하는 데이터베이스를 만든다.
수정,추가,읽기 함수를 제공하여 데이터베이스를 관리할 수 있다.
*/
template<class T>
class Database {
	string filename;
	int data_size;
	ofstream mout;
	ifstream in;
	ofstream copen; //Object for file Create.
public:
	~Database(){
		this->mout.close();
		this->copen.close();
		this->in.close();
	}
	Database(string filename) {
		this->copen.open(filename,ios :: out | ios::app | ios::binary); //Object for file Create.
		this->mout.open(filename, ios :: out | ios :: in | ios::binary);
		this->in.open(filename, ios::in | ios::binary);
		// get size
		this->in.seekg(0, ios::end);
		this->data_size = in.tellg()/sizeof(T); 
		this->in.seekg(0, ios::beg);
	}

	inline int cur_idx() {
		return this->in.tellg() / sizeof(T);
	}
	inline int dataSize() {
		return this->data_size;
	}

	inline void flush() {
		this->mout.flush();
	}

	T read(int idx = -1);
	void write(T &data,int idx = -1);
};

//--------------------------------------Template Class definition--------------------------------------
template<class T>
void Database<T>::write(T &data,int idx) {
	if (mout.fail()) return;
	if(idx < 0) idx = data_size;
	int tellp = idx * sizeof(T);

	if (idx >= data_size) {
		
// 		this->mout.seekp(0,ios::end);
// 		this->mout.write((char *)&data, sizeof(data));
		this->copen.write((char *)&data, sizeof(data)); // atomic append 
		
		this->data_size++;
	}
	else {
		this->mout.seekp(tellp);
		this->mout.write((char *)&data, sizeof(data));
	}
}

template<class T>
T Database<T>::read(int idx) {
	T data;
	if (in.fail()) return data;
	if (idx >= 0) {
		int tellg = idx * sizeof(T);
		if (tellg >= data_size) {
			cerr << "fileSize over" << endl;
			return data;
		}
		this->in.seekg(tellg);
	}
	this->in.read((char *)&data, sizeof(data));

	return data;
}

#endif 
