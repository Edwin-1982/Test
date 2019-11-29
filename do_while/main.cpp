#include<iostream>
#include<windows.h>

using namespace std;

int main(void) {

	int s = 0;
	int i = 1;

	do {
		s += i;
		i++;
	} 
	while (i <= 100);

	cout << s << endl;

	system("pause");
		return 0;
}