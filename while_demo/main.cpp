#include<iostream>
#include<windows.h>
#include<string>

using namespace std;

int main(void) {
	int i;
	int s;

	s = 1;
	i = 2;//i表示加数
	// i
	//1+2+3+...+100=?
	//加99次

	while (i<=100) {
		
		s = s + i;
		i++;        //i=i+1 改变循环控制变量
	}
	cout << "s=" << s << endl;

	system("pause");
	return 0;
}