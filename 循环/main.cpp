#include<iostream>
#include<windows.h>

using namespace std;

int main(void) {
	int row;
	int col;

	cout << "����������:";
	cin >> row;
	cout << "����������";
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