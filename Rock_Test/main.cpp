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
	cout << "1.ע��" << endl;
	cout << "2.����" << endl;
	cout << "3.��ѯ" << endl;
	cout << "4.ɾ��" << endl;
	system("pause");
	return 0;
}