#include<iostream>
#include<windows.h>

using namespace std;

/*
	
	I love you! '\0'

	���� ���� ���� ���� ���� ���� ����

	���������ո� �����ǿո���� ���������ո� �����ǿո���� ���������ո�

---------------����ṹ------------
	���������ո�
	while(��ǰ�ַ�����'\0'){
		�����ǿո����
		���������ո�
		���ʼ���+1
	}
-----------------------------------
*/

int main(void) {
	char line[512];   //'\0'����0
	int count = 0;
	int i = 0;

	cout << "������һ�仰:";
	gets_s(line, sizeof(line));

/*
	while (line[i] ==' ') {
		i++;
	}
*/
	//����ǰ��������ո�
	while (line[i] == ' ')i++;
	while (line[i]) {  //while (line[i] != '\0')  '\0'����0
		while (line[i]&&line[i]!=' ')i++;
		while (line[i] == ' ')i++;
		count++;
	}
	cout << "һ����" << count << "������" << endl;
	system("pause");
	return 0;
}