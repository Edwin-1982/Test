#include<iostream>
#include<windows.h>
#include<string>

using namespace std;

int main(void) {
	//int i;
	//int s;

	//s = 0;
	//i = 0;//i��ʾ����
	//// i
	////1+2+3+...+100=?
	////��99��

	//while (i<100) {//i:  0 1 2 3 4 5...99
	//	
	//	s = s + i;
	//	i++;        //i=i+1 �ı�ѭ�����Ʊ���
	//}
	int i=1;
	int s=0;

	while (1) {
		s += i;//s=s+1
		i++;
		if (i > 100) {
			break;
		}
	}

	cout << "s=" << s << endl;

	system("pause");
	return 0;
}