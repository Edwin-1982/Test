#include<iostream>

using namespace std;

template<typename T>

class A{
public:
	//函数的参数列表使用虚拟类型
	A(T t = 0);

	//成员函数返回值使用虚拟类型
	T& getT();

	A operator + (const A & other) ;

	void print();
private:
	//成员变量使用虚拟类型
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

//成员函数返回值使用虚拟类型
template<typename T>
T &A<T>::getT() {
	return t;
}

template<typename T>
A<T> A<T>::operator + (const A<T> & other) {
	A tmp; //类的内部类型,可以显示声明也可以不显示
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
