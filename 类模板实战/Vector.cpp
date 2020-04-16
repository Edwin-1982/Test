#include<iostream>
#include"Vector.h"

template<typename T>

ostream& operator<<(ostream& out, const Vector<T>& object) {
	for (int i = 0; i < object.m_len; i++) {
		cout << object.m_base[i] << " ";
	}
	out << endl;
	return out;
}
template <typename T>
Vector<T>::Vector(int size) {//���캯��
	if (size > 0) {
		this->m_len = size;
		this->m_base = new T[m_len];
	}
}

template <typename T>
Vector<T>::Vector(const Vector<T> &object) {//�������캯��
	
	//���ݴ���Ķ���Ԫ�ظ�������ռ�
	this->m_len = object.m_len;
	this->m_base = new T[m_len];

	//���ݿ���
	for (int i = 0; i < m_len; i++) {
		m_base[i] = object.m_base[i];
	}
}

template<typename T>
int Vector<T>::getLength()
{
	return m_len;
}

//Vector<int>a1; a1[0];
template <typename T>
T& Vector<T>::operator[](int index) {
	return m_base[index];//return *(m_base+index);
}

//ʵ��-����������
//a1=a2=a3;
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& object) {
	if (m_base != NULL) {
		delete[] m_base;
		m_base = NULL;
		m_len = 0;
	}

	//���ݴ���Ķ���Ԫ�ظ�������ռ�
	this->m_len = object.m_len;
	this->m_base = new T[m_len];

	//���ݿ���
	for (int i = 0; i < m_len; i++) {
		m_base[i] = object.m_base[i];
	}
	return *this;
}

template <typename T>
Vector<T>::~Vector() {//��������
	if (m_base != NULL) {
		delete[]m_base;
		m_base = NULL;
		m_len = 0;
	}
}
