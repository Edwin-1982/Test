#include<iostream>

using namespace std;

/*****************************************************
1.ģ�庯������ͨ��������, �������ͺ���ͨ���غ�����ƥ��
������ͨ����
******************************************************/
//template<typename T>
//void Swap(T &a, T &b) {
//	T t;
//	t = a;
//	a = b;
//	b = t;
//	cout << "Swap ģ�庯����������" << endl;
//}
//
//
//void Swap(char& a, int& b) {
//	int t;
//	t = a;
//	a = b;
//	b = t;
//	cout << "Swap ��ͨ������������" << endl;
//}
//
//
//int main(void) {
//	char cNum = 'c';
//	int iNum = 65;
//
//	
//	
//	Swap(cNum, iNum);
//
//	system("pause");
//	return 0;
//}

/******************************************************
2.��������ͨ����,����ģ�����ʽ��������ת��
  ����:���ṩ��ʽ����������ת��,�������ϸ��ƥ��
*******************************************************/

//template<typename T,typename T1>
//void Swap(T &a, T1 &b) {
//	T t;
//	t = a;
//	a = b;
//	b = t;
//	cout << "Swap ģ�庯����������" << endl;
//}
//
//int main(void) {
//	char cNum = 'c';
//	int iNum = 65;
//
//	Swap(cNum, iNum);
//
//	system("pause");
//	return 0;
//}

/******************************************************
3.������ģ�����ͨ���������ϵ���ʱ,����ѡ����ͨ����
*******************************************************/

//��һ��
int Max(int a, int b) {
	cout << "���� int Max(int a,int b)" << endl;
	return a > b ? a : b;
}

template<typename T>
T Max(T a, T b) {
	
	cout << "���� T Max(T a,T b)" << endl;
	return a > b ? a : b;
}
template<typename T>
T Max(T a, T b, T c) {
	cout << "���� T Max(T a,T b,T c)" << endl;
	return Max(Max(a, b), c);
}

//�ڶ���
int Max1(int a, int b) {
	cout << "���� int Max(int a,int b)" << endl;
	return a > b ? a : b;
}
template<typename T1,typename T2>
T1 Max1(T1 a, T2 b) {

	cout << "���� T Max1(T1 a,T2 b)" << endl;
	return a > b ? a : b;
}
int main(void) {
	int a = 1;
	int b = 2; 

	//������ģ�����ͨ���������ϵ���ʱ,����ѡ����ͨ����
	//cout << "Max(a, b)" << Max(a, b) << endl;
	
	//�����ʽ��ʹ�ú���ģ��,��ʹ��<>�����б�
	//Max<>(a, b);//ѡ�����ģ�庯��
	
	char c = 'a';
	Max(1.0, 2.0, 3.0);
	//�������ģ���������õ�ƥ��,ʹ�ú���ģ��
	//Max(1.0, 2.0);
	//Max1(c, a);
	system("pause");
	return 0;
}