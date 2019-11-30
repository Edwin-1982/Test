#include<iostream>
#include<windows.h>

using namespace std;

//一天想我几次
//24小时,每秒一次

int main(void) {
	int count = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				count++;
				cout << i << ":" << j << ":" << k << " 想你第" << count << "次" << endl;

				Sleep(1000);//休眠一秒
			}
		}
	}
	system("pause");
	return 0;
}