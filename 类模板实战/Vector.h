#pragma once
#include<iostream>

using namespace std;

template <typename T>
class Vector {
	//Vector<int>a(10);cout<<a;

	friend ostream &operator<< <T> (ostream& out, const Vector& object);
public:
	Vector(int size = 128);//���캯��
	Vector(const Vector& object);//�������캯��
	//Vector<int>a(10);a<<
	//operator<<();

	int getLength();//��ȡ�ڲ��洢��Ԫ�ظ���

	//Vector<int>a1; a1[0];
	T& operator[](int index);

	//ʵ��-����������
	//a1=a2=a3;
	Vector& operator=(const Vector& object);

	~Vector();//��������
private:
	T *m_base;
	int m_len;
};