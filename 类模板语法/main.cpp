#include<iostream>

using namespace std;

template<typename T>

class A {
public:
	//�����Ĳ����б�
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

void printA(A<int>& a) {
	cout << a.getT() << endl;

}
int main(void) {
	//1.ģ���ඨ�������,������ʾָ������
	//2.ģ�������ʹ���˹��캯��,��������ǰ����Ĺ��캯���ĵ��ù���
	A<int> a(666);
	//cout << a.getT() << endl;
	printA(a);
	system("pause");
	return 0;
}