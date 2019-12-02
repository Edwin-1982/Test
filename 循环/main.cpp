#include<iostream>
#include<windows.h>

using namespace std;

int main(void) {
	int row;
	int col;

	cout << "请输入行数:";
	cin >> row;
	cout << "请输入列数";
	cin >> col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << "*";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}