#include<iostream>
#include<stdlib.h>
#include<iomanip>

#define N 10
using namespace std;

int main(void) {

	int a[N][N] = {0};//二维数组所有元素清零

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == 0 || i == j) {
				a[i][j] = 1;
			}
			else {
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
		}
	}
		
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <=i; j++) {
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
	*/

	for (int i = 0; i < N;i++) {
		cout << setw((N - i) * 2) << a[i][0];

		for (int j = 1; j <= i; j++) {
			cout << setw(4) << a[i][j];
		}
		cout << endl;

	}
	system("pause");
	return 0;
}