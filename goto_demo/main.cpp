#include<iostream>
#include<windows.h>

using namespace std;


//����1

//void happy(void) {
//happy: //��ǩ
//	cout << "����û��û���Ķ�������..." << endl;
//}
//
//int main(void) {
//
//	string ret;
//
//
//	for (int i = 0; i < 5; i++) {
//		cout << "��ʼ��" << i + 1 << "������..." << endl;
//		cout << "��ϲ����������?";
//		cin >> ret;
//
//
//	
//		if (ret != "yes") {
//			continue;
//		}
//		cout << "�Ӹ�΢�Ű�..." << endl;
//
//		cout << "��������,����������?" << endl;
//		cin >> ret;
//	
//		if (ret == "yes") {
//			happy();
//			system("pause");
//			return 0;
//		}
//	}
//	system("pause");
//	return 0;
//}

//����2
//int main(void) {
//
//	string ret;
//
//
//	for (int i = 0; i < 5; i++) {
//		cout << "��ʼ��" << i + 1 << "������..." << endl;
//		cout << "��ϲ����������?";
//		cin >> ret;
//
//
//	
//		if (ret != "yes") {
//			continue;
//		}
//		cout << "�Ӹ�΢�Ű�..." << endl;
//
//		cout << "��������,����������?" << endl;
//		cin >> ret;
//	
//		if (ret == "yes") {
//			goto happy;
//		}
//	}
//	system("pause");
//	return 0;
//
//happy:
//
//	cout << "��ʼû��û��������..."<<endl;
//	system("pause");
//	return 0;
//}

//����3
int main(void) {
	bool flag;
	string ret;


	for (int i = 0; i < 5; i++) {
		cout << "��ʼ��" << i + 1 << "������..." << endl;
		cout << "��ϲ����������?";
		cin >> ret;

		if (ret != "yes") {
			continue;
		}
		cout << "�Ӹ�΢�Ű�..." << endl;

		cout << "��������,����������?" << endl;
		cin >> ret;
	
		if (ret == "yes") {
			flag=true;
			break;
		}
	}
	if (flag) {
		cout << "��ʼû��û��������..." << endl;

	}
	system("pause");
	return 0;

}
