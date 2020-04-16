#pragma once
#include<iostream>

using namespace std;

template <typename T>
class Vector {
	//Vector<int>a(10);cout<<a;

	friend ostream &operator<< <T> (ostream& out, const Vector& object);
public:
	Vector(int size = 128);//构造函数
	Vector(const Vector& object);//拷贝构造函数
	//Vector<int>a(10);a<<
	//operator<<();

	int getLength();//获取内部存储的元素个数

	//Vector<int>a1; a1[0];
	T& operator[](int index);

	//实现-操作符重载
	//a1=a2=a3;
	Vector& operator=(const Vector& object);

	~Vector();//析构函数
private:
	T *m_base;
	int m_len;
};