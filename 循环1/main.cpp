#include<iostream>
#include<windows.h>

using namespace std;

int main(void) {
	int row;

	cout << "请输入行数:";
	cin >> row;

	/*
		i  *的个数(i+1)
		第0次 1个 *
		第1次 2个 *
		第2次 3个 *
	*/
	/*
		for (int i = 0; i < n; i++);
		for (int i = 1; i <= n; i++);
	*/
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
