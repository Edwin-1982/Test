#include<iostream>
#include<windows.h>

using namespace std;

int main(void) {
	string str;
	int i;
	int j;
	char temp;

	cout << "ÇëÊäÈëÒ»¸ö×Ö·û´®:" << endl;
	cin >> str;

	i = 0;
	j = str.length() - 1;
	while (i<j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	cout << str << endl;
	system("pause");
	return 0;
}