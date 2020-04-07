#include<iostream>
#include"demo.h"

using namespace std;

template<typename T>
A<T>::A(T t) {
	this->t = t;
}

//成员函数返回值使用虚拟类型
template<typename T>
T& A<T>::getT() {
	return t;
}

template<typename T>
A<T> A<T>::operator + (const A<T>& other) {
	A tmp; //类的内部类型,可以显示声明也可以不显示
	tmp.t = this->t + other.t;
	return tmp;
}
template<typename T>
void A<T>::print() {
	cout << this->t << endl;
}