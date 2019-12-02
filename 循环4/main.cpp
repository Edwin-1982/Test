#include<iostream>
#include<windows.h>
#include<iomanip>

using namespace std;

int main(void) {
	/*
		打印9行
		循环9次,每次打印1行
		第i行,打印i列
		每一列:
	*/
	int width;
	for (int i = 1; i <= 9; i++) {
		//i表示外层循环的次数,表示第几行
		for (int j = 1; j <= i; j++) {
			width = (j == 1) ? 1 : 2;
			cout << j << "×" << i << "=" << setw(1) << left << i * j <<"  ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}