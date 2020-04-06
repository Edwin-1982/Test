#include<iostream>

using namespace std;

template<typename T>

class A{
public:
	//�����Ĳ����б�ʹ����������
	A(T t = 0);

	//��Ա��������ֵʹ����������
	T& getT();

	A operator + (const A & other) ;

	void print();
private:
	//��Ա����ʹ����������
	T t;
};

/*
class A {
public:
	A(int t = 0);

	int& getT();

	A operator + (const A& other);

	void print();
private:
	int t;
};
*/
template<typename T>
A<T>::A(T t) {
	this->t = t;
}

//��Ա��������ֵʹ����������
template<typename T>
T &A<T>::getT() {
	return t;
}

template<typename T>
A<T> A<T>::operator + (const A<T> & other) {
	A tmp; //����ڲ�����,������ʾ����Ҳ���Բ���ʾ
	tmp.t = this->t + other.t;
	return tmp;
}
template<typename T>
void A<T>::print() {
	cout << this->t << endl;
}

int main(void) {
	A<int> a(666), b(888);
	//cout << a.getT() << endl;
	A<int> tmp = a + b;
	tmp.print();

	system("pause");
	return 0;
}
