#include<iostream>
#include<windows.h>
#include<iomanip>

using namespace std;

int main(void) {
	/*
		��ӡ9��
		ѭ��9��,ÿ�δ�ӡ1��
		��i��,��ӡi��
		ÿһ��:
	*/
	int width;
	for (int i = 1; i <= 9; i++) {
		//i��ʾ���ѭ���Ĵ���,��ʾ�ڼ���
		for (int j = 1; j <= i; j++) {
			width = (j == 1) ? 1 : 2;
			cout << j << "��" << i << "=" << setw(1) << left << i * j <<"  ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}