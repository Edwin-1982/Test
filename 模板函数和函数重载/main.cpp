#include<iostream>

using namespace std;

/*****************************************************
1.模板函数和普通函数并存, 参数类型和普通重载函数更匹配
调用普通函数
******************************************************/
//template<typename T>
//void Swap(T &a, T &b) {
//	T t;
//	t = a;
//	a = b;
//	b = t;
//	cout << "Swap 模板函数被调用了" << endl;
//}
//
//
//void Swap(char& a, int& b) {
//	int t;
//	t = a;
//	a = b;
//	b = t;
//	cout << "Swap 普通函数被调用了" << endl;
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
2.不存在普通函数,函数模板会隐式数据类型转换
  结论:不提供隐式的数据类型转换,必须是严格的匹配
*******************************************************/

//template<typename T,typename T1>
//void Swap(T &a, T1 &b) {
//	T t;
//	t = a;
//	a = b;
//	b = t;
//	cout << "Swap 模板函数被调用了" << endl;
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
3.当函数模板和普通函数都符合调用时,优先选择普通函数
*******************************************************/

//第一版
int Max(int a, int b) {
	cout << "调用 int Max(int a,int b)" << endl;
	return a > b ? a : b;
}

template<typename T>
T Max(T a, T b) {
	
	cout << "调用 T Max(T a,T b)" << endl;
	return a > b ? a : b;
}
template<typename T>
T Max(T a, T b, T c) {
	cout << "调用 T Max(T a,T b,T c)" << endl;
	return Max(Max(a, b), c);
}

//第二版
int Max1(int a, int b) {
	cout << "调用 int Max(int a,int b)" << endl;
	return a > b ? a : b;
}
template<typename T1,typename T2>
T1 Max1(T1 a, T2 b) {

	cout << "调用 T Max1(T1 a,T2 b)" << endl;
	return a > b ? a : b;
}
int main(void) {
	int a = 1;
	int b = 2; 

	//当函数模板和普通函数都符合调用时,优先选择普通函数
	//cout << "Max(a, b)" << Max(a, b) << endl;
	
	//如果显式的使用函数模板,则使用<>类型列表
	//Max<>(a, b);//选择调用模板函数
	
	char c = 'a';
	Max(1.0, 2.0, 3.0);
	//如果函数模板会产生更好的匹配,使用函数模板
	//Max(1.0, 2.0);
	//Max1(c, a);
	system("pause");
	return 0;
}