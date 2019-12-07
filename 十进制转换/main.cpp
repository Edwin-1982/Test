#include<iostream>
#include<windows.h>

using namespace std;

int main(void) {
	int n;
	int ret[32];
	int i;      //表示存放二进制数的数组小标

	cout << "请输入一个正整数:";
	cin >> n;
	if (n < 0) {
		cout << "输入无效,请输入一个正整数!" << endl;
		system("pause");
		return 1;
	}
	i = 0;
	while (n!=0) {
		ret[i] = n % 2;
		n = n / 2;
		i++;
	}

	//输出结果

	for (i--; i >= 0; i--) {
		cout << ret[i];
	}
	cout << endl;
	system("pause");
	return 0;
}