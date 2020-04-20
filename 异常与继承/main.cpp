#include<iostream>

using namespace std;

/*
���һ������������Vector, �����Ų���, �����ʼ��ʱ, ������ĸ���������Ч���
1)index < 0�׳��쳣errNegaLiveException
2)index = 0�׳��쳣errZeroException
3)index > 1000�׳��쳣errTooBigException
4)index < 10�׳��쳣errTooSmallException
5)errSizeException����������ĸ���, ʵ���в�������\������virtual void printError()�������.
*/

class errSizeException {
public:
	errSizeException(int size) {
		m_size = size;
	}
	virtual void printError() {
		cout << "size: " << m_size << endl;
	}

protected:
	int m_size;
};
class errNegaLiveException :public errSizeException {
public:
	errNegaLiveException(int size) :errSizeException(size) {

	}
	virtual void printError() {
		cout << "errNegaLiveException size: " << m_size << endl;
	}
};
class errZeroException :public errSizeException {
public:
	errZeroException(int size) :errSizeException(size) {

	}
	virtual void printError() {
		cout << "errZeroException size: " << m_size << endl;
	}
};
class errTooBigException :public errSizeException {
public:
	errTooBigException(int size) :errSizeException(size) {

	}
	virtual void printError() {
		cout << "errTooBigException size: " << m_size << endl;
	}
};
class errTooSmallException :public errSizeException {
public:
	errTooSmallException(int size) :errSizeException(size) {

	}
	virtual void printError() {
		cout << "errTooSmallException size: " << m_size << endl;
	}
};
class Vector {
public:
	Vector(int size = 128);
	Vector(const Vector& object);//�������캯��

	int getLength();//��ȡ�ڲ��洢��Ԫ�ظ���

	int& operator[](int index);

	~Vector();
private:
	int* m_base;
	int m_len;
};

Vector::Vector(int len) {
	if (len < 0) {
		throw errNegaLiveException(len);
	}
	else if(len==0){
		throw errZeroException(len);
	}
	else if (len > 1000) {
		throw errTooBigException(len);
	}
	else if (len < 10) {
		throw errTooSmallException(len);
	}
	m_len = len;
	m_base = new int[len];
}

Vector::~Vector() {
	if (m_base)delete[]m_base;
	m_len = 0;
}

int Vector::getLength() {
	return m_len;
}

int& Vector::operator[](int index) {
	return m_base[index];
}

int main(void) {
	try {
		Vector v(5);
		for (int i = 0; i < v.getLength(); i++) {
			v[i] = i + 10;
			printf("v[i]:%d\n", v[i]);
		}
	}
	/*catch (errSizeException& err) {
		err.printError();
	}*/
	catch (errNegaLiveException &err) {

		cout << "errNegativeException..." << endl;
	}
	catch (errZeroException &err) {

		cout << "errZeroException..." << endl;

	}
	catch (errTooBigException &err) {

		cout << "errTooBigException..." << endl;

	}
	catch (errTooSmallException &err) {

		cout << "errTooSmallException..." << endl;

	}

	system("pause");
	return 0;
}