#include<iostream>
#include<windows.h>

using namespace std;

int main(void) {
	int row;

	cout << "����������:";
	cin >> row;

	/*
		i  *�ĸ���(i+1)
		��0�� 1�� *
		��1�� 2�� *
		��2�� 3�� *
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
