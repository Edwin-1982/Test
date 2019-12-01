#include<iostream>
#include<windows.h>

using namespace std;

int main(void) {

	string pwd;
	while (1) {
		cout << "Please input your password:";
		cin >> pwd;

		if (pwd == "000123") {
			break;
		}
		else {
			cout << "Passeword error." << endl;
		}
	}
	cout << "login success!" << endl;
	cout << "1.×¢²á" << endl;
	cout << "2.¹ÜÀí" << endl;
	cout << "3.²éÑ¯" << endl;
	cout << "4.É¾³ý" << endl;
	system("pause");
	return 0;
}