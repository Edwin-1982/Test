#include<iostream>
#include<windows.h>

using namespace std;

//һ�����Ҽ���
//24Сʱ,ÿ��һ��

int main(void) {
	int count = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				count++;
				cout << i << ":" << j << ":" << k << " �����" << count << "��" << endl;

				Sleep(1000);//����һ��
			}
		}
	}
	system("pause");
	return 0;
}