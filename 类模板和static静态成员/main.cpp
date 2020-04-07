#include<iostream>

using namespace std;

/*
//�����ǵ����������T��intʵ������,ģ��������:
class A {
public:
	A( int t = 0);

	int& getT();

	A operator+(const A& other);

	void print();
public:
	static int count;

private:
	int t;
};

int A::count = 666;

A::A(int t) {
	this->t = t;
}

int& A::getT() {

	return t;
}

A A::operator+(const A& other) {
	A tmp;//����ڲ����Ϳ�����ʾ����Ҳ���Բ���ʾ
	tmp.t = this->t + other.t;
	return tmp;
}
void A::print() {
	cout << this->t << endl;
}


int main(void) {
	A a(666), b(888);
	A tmp = a + b;

	a.count = 888;
	cout << b.count << endl;
	system("pause");
	return 0;
}
*/

/*
template<typename T>

class A {
public:
	A(T t = 0);

	//����һ����Ԫ����,ʵ�ֶ�����A�������мӷ�����
	template<typename T>
	friend A<T> addA(const A<T>& a, const A<T>& b);
	T& getT();

	A operator+(const A& other);
public:
	static int count;
	void print();

private:
	T t;
};

template<typename T> 
int A<T>::count = 666;

//�����Ԫ����
template<typename T>
A<T> addA(const A<T>& a, const A<T>& b) {
	A<T> tmp;
	tmp.t = a.t + b.t;
	return tmp;
}
template<typename T>
A<T>::A<T>(T t) {
	this->t = t;
}

template<typename T>
T& A<T>::getT() {

	return t;
}

template<typename T>
A<T> A<T>::operator+(const A<T>& other) {
	A<T>tmp;//����ڲ����Ϳ�����ʾ����Ҳ���Բ���ʾ
	tmp.t = this->t + other.t;
	return tmp;
}
template<typename T>
void A<T>::print() {
	cout << this->t << endl;
}

int main(void) {
	A<int> a(666), b(888);
	A<int> tmp = a + b;
	A<float> c(777), d(999);
	a.count = 888;
	cout << b.count << endl;
	cout << c.count << endl;
	cout << d.count << endl;

	A<int> tmp1 = addA<int>(a, b);
	tmp.print();
	tmp1.print();
	system("pause");
	return 0;
}
*/

/*

class A {
public:
	A(int t = 0);

	int& getT();

	A operator+(const A& other);

	void print();
public:
	static int count;

private:
	int t;
};

int A::count = 666;

A::A(int t) {
	this->t = t;
}

int& A::getT() {

	return t;
}

A A::operator+(const A& other) {
	A tmp;//����ڲ����Ϳ�����ʾ����Ҳ���Բ���ʾ
	tmp.t = this->t + other.t;
	return tmp;
}
void A::print() {
	cout << this->t << endl;
}


int main(void) {
	A a(666), b(888);
	A tmp = a + b;

	a.count = 888;
	cout << b.count << endl;
	system("pause");
	return 0;
}
*/



//�����ǵ����������T��floatʵ�����Ժ�,ģ��������:
class A {
public:
	A(float t = 0);

	float& getT();

	A operator+(const A& other);
	
	void print();

public:
	static int count;

private:
	float t;
};

int A::count = 666;


A::A(float t) {
	this->t = t;
}

float& A::getT() {

	return t;
}

A A::operator+(const A& other) {
	A tmp;//����ڲ����Ϳ�����ʾ����Ҳ���Բ���ʾ
	tmp.t = this->t + other.t;
	return tmp;
}
void A::print() {
	cout << this->t << endl;
}

int main(void) {
	A a(666), b(888);
	A tmp = a + b;
	A c(777), d(999);
	a.count = 888;
	cout << b.count << endl;
	cout << c.count << endl;
	cout << d.count << endl;
	c.count = 1000;
	cout <<"�޸ĺ�,d.count:"<< d.count << endl;

	system("pause");
	return 0;
}