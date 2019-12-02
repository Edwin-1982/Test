#include<iostream>
#include<windows.h>

using namespace std;

int main(void) {
	int row;

	cout << "请输入行数:";
	cin >> row;
	/*
		但row=8时

		i		*的个数
		第0次	8个 *
		第1次	7个 *
		第2次	6个 *
		第m次	row-m个*
	*/
	for (int i = 0; i <= row; i++) {
		for (int j = 0; j <=row-i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}