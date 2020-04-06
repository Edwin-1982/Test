#include<iostream>

using namespace std;

class demo {
public:
	demo(int _k = 0) {
		k = _k;
	}
	~demo() {

	}
	int value() {
		return k;
	}
	bool operator>(demo& dest) {
		if (this->k > dest.k) {
			return true;
		}
		else {
			return false;
		}
	}
private:
	int k;
};
/*********************************************
template 泛型关键字,T 参数化数据类型
template<类型形式参数表>
类型形式参数的形式:
typename T1, typename T2, ...typename Tn
*********************************************/
template<typename T, typename T2>
T Max(T a, T2 b) { //函数定义
	//T tmp = 0;
	return a > b ? a : b;
}
int main(void) {
	char c = 'c';
	int x = 1;
	int y = 2;
	cout << "max(1,2)=" << Max(x, c) << endl;//实现参数类型的自动推导
	cout << "max(1,2)=" << Max<int>(x, y) << endl;//实现显示调用

	float a = 1.0;
	float b = 2.5;
	cout << "max(1.0,2.0)=" << Max(a, b) << endl;

	demo d1(10);
	demo d2(11);
	cout << "max(d1,d2)=" << Max(d1, d2).value() << endl;
	system("pause");
	return 0;

}