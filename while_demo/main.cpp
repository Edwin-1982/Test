#include<iostream>
#include<windows.h>
#include<string>

using namespace std;

int main(void) {
	int i;
	int s;

	s = 0;
	i = 0;//i��ʾ����
	// i
	//1+2+3+...+100=?
	//��99��

	while (i<100) {//i:  0 1 2 3 4 5...99
		
		s = s + i+1;
		i++;        //i=i+1 �ı�ѭ�����Ʊ���
	}
	cout << "s=" << s << endl;

	system("pause");
	return 0;
}