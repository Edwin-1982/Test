#include<iostream>
#include<windows.h>

using namespace std;

int main(void) {

	string ret;

	for (int i = 0; i < 3; i++) {
		cout << "��ʼ��" << i + 1 << "������..." << endl;
		cout << "��ϲ����������?" << endl;
		cin >> ret;

		if (ret != "yes") {
			continue;
		}
		cout << "�Ӹ�΢�Ű�!" << endl;
	}
	system("pause");
	return 0;
}