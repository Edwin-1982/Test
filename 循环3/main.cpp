#include<iostream>
#include<windows.h>

using namespace std;

int main(void) {
	int n;   //金字塔的层数

	cout << "请输入金字塔的层数:";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		//第i行:2*i-1
		for (int k = 1; k <= n - i; k++) {
			cout << " ";
		}
		for (int j = 0; j < 2 * i - 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	system("pause");
	return 0;
	
}