#include<iostream>
#include<windows.h>
#include<string>

using namespace std;

int main(void) {
	int i;
	int s;

	s = 1;
	i = 2;//i��ʾ����
	// i
	//1+2+3+...+100=?
	//��99��

	while (i<=100) {
		
		s = s + i;
		i++;        //i=i+1 �ı�ѭ�����Ʊ���
	}
	cout << "s=" << s << endl;

	system("pause");
	return 0;
}