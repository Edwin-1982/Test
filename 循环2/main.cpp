#include<iostream>
#include<windows.h>

using namespace std;

int main(void) {
	int row;

	cout << "����������:";
	cin >> row;
	/*
		��row=8ʱ

		i		*�ĸ���
		��0��	8�� *
		��1��	7�� *
		��2��	6�� *
		��m��	row-m��*
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