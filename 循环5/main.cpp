#include<iostream>
#include<windows.h>

using namespace std;

int main(void) {
	int a, b, c;

	for (int i = 100; i <= 999; i++) {
		//�ж�i�Ƿ���ˮ�ɻ���
		//123=>a:3
		a = i % 10;
		b = i / 10 % 10;
		c = i / 100;
		if (a* a* a + b * b * b + c * c * c ==  i) {
			cout << i << endl;
		}
	}
	system("pause");
	return 0;
}