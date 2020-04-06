#include<iostream>

using namespace std;



//继承中父子类和模板的结合情况
//1.父类一般类,子类是模板类,和普通继承类似

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
	//函数的参数列表使用虚拟类型
	A(T t = 0) :B(0){
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
*/

//2.子类一般类,父类是模板类,继承时必须实例化父类类型参数

/*
template<typename T>

class A  {
public:
	//函数的参数列表使用虚拟类型
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

//3.父类和子类是模板类时,子类的虚拟的类型可以传递到父类中
template<typename T>

class A  {
public:
	//函数的参数列表使用虚拟类型
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
	//1.模板类定义类对象,必须显示指定类型
	//2.模板中如果使用了构造函数,则遵守以前的类的构造函数的调用规则
	A<int> a(666);
	cout << a.getT() << endl;
	B<int> b(888);
	cout << b.getT() << endl;
	printA(a);
	system("pause");
	return 0;
}