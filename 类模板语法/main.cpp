#include<iostream>

using namespace std;

template<typename T>

class A {
public:
	//函数的参数列表
	A(T t = 0) {
		this->t = t;
	}

	//成员函数返回值使用虚拟类型
	T& getT() {
		return t;
	}
private:
	//成员变量使用虚拟类型
	T t;
};

void printA(A<int>& a) {
	cout << a.getT() << endl;

}
int main(void) {
	//1.模板类定义类对象,必须显示指定类型
	//2.模板中如果使用了构造函数,则遵守以前的类的构造函数的调用规则
	A<int> a(666);
	//cout << a.getT() << endl;
	printA(a);
	system("pause");
	return 0;
}