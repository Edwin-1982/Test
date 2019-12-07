#include<iostream>
#include<windows.h>

using namespace std;

/*
序号:1 2 3 4 5 6 7 8 ...n
	 1,1,2,3,5,8,13,21...x
	 a,b
*/
int main(void) {
	LONG64 n = 0;
	LONG64 a = 1;
	LONG64 b = 1;
	LONG64 value;
	cout << "请输入斐波拉切数列的个数:";
	cin >> n;

	if (n <= 0) {
		cout << "非法输入,请输入大于0的整数!" << endl;
		system("pause");
		return 1;
	}
	if (n == 1) {
		cout <<"1"<< endl;
		system("pause");
		return 0;
	}
	if (n == 2) {
		cout << " 1 1" << endl;
		system("pause");
		return 0;
	}
	cout << "1 1 ";
	for (int i = 3; i <= n; i++) {
		value = a + b;
		//a和b前进一位
		a = b;
		b = value;
		cout << value << " ";
	}
	system("pause");
	return 0;
}