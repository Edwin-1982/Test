#include<iostream>

using namespace std;



//�̳��и������ģ��Ľ�����
//1.����һ����,������ģ����,����ͨ�̳�����

/*
class B {
public:
	B(int b) {
		this->b=b;
	}
private:
	int b;
};

template<typename T>

class A:public B{
public:
	//�����Ĳ����б�ʹ����������
	A(T t = 0) :B(0){
		this->t = t;
	}

	//��Ա��������ֵʹ����������
	T& getT() {
		return t;
	}
private:
	//��Ա����ʹ����������
	T t;
};

void printA(A<int>& a) {
	cout << a.getT() << endl;
}
*/

//2.����һ����,������ģ����,�̳�ʱ����ʵ�����������Ͳ���

/*
template<typename T>

class A  {
public:
	//�����Ĳ����б�ʹ����������
	A(T t = 0) {
		this->t = t;
	}

	//��Ա��������ֵʹ����������
	T& getT() {
		return t;
	}
private:
	//��Ա����ʹ����������
	T t;
};

class B :public A<int>{
public:
	B(int b) :A<int>(666) {
		this->b = b;
	}
private:
	int b;
};

void printA(A<int>& a) {
	cout << a.getT() << endl;

}
*/

//3.�����������ģ����ʱ,�������������Ϳ��Դ��ݵ�������
template<typename T>

class A  {
public:
	//�����Ĳ����б�ʹ����������
	A(T t = 0) {
		this->t = t;
	}

	//��Ա��������ֵʹ����������
	T& getT() {
		return t;
	}
private:
	//��Ա����ʹ����������
	T t;
};

template<typename Tb>

class B :public A<int>{
public:
	B(Tb b) :A<Tb>(888) {
		this->b = b;
	}
private:
	Tb b;
};

void printA(A<int>& a) {
	cout << a.getT() << endl;

}

int main(void) {
	//1.ģ���ඨ�������,������ʾָ������
	//2.ģ�������ʹ���˹��캯��,��������ǰ����Ĺ��캯���ĵ��ù���
	A<int> a(666);
	cout << a.getT() << endl;
	B<int> b(888);
	cout << b.getT() << endl;
	printA(a);
	system("pause");
	return 0;
}