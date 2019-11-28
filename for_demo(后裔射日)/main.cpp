#include<iostream>
#include<windows.h>

using namespace std;

//int main(void) {
//	for (int i = 0; i < 9; i++) {
//		cout << "ÉäµÚ" << i+1 << "¸öÌ«Ñô" << endl;
//	}
//	system("pause");
//	return 0;
//}

int main(void) {
	int s = 0;

	//1+2+3+...100
	for (int i = 0; i <= 100; i++) {
		s += i;
		cout << "s=" << s << endl;
	}
	system("pause");
	return 0;
}