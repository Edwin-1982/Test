#include<iostream>
#include"demo.hpp"

int main(void) {
	A<int> a(666), b(888);
	//cout << a.getT() << endl;
	A<int> tmp = a + b;
	tmp.print();

	system("pause");
	return 0;
}
