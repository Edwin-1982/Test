#include<iostream>
#include<windows.h>

using namespace std;

/*
	i
	j
	k1 k2
	123 45 678

	678 45 123  最终效果
	876 54 321  初步效果
	678 45 123

	方法1           方法2
	初步876 54 321  第一步:321 54 876
	    678 45 123  第二步:678 45 123
	    
	
*/

int main(void) {
	char str[256];
	int i = 0;
	

	cout << "请输入一句话(英文):";
	gets_s(str, sizeof(str));

	while (str[i]) {
		//跳过前面的空格
		//该循环结束后,str[i]是下一个单词的第一个字母
		while (str[i] == ' ')i++;

		int j = i;
		//该循环结束后,str[j]是这个单词后面的第一个空格
		while (str[j] && str[j]!= ' ')j++;
		
		//逆转这个单词
		for (int k1 = i, k2 = j - 1; k1 < k2; k1++, k2--) {
			char tmp = str[k1];
			str[k1] = str[k2];
			str[k2] = tmp;
		}
		i = j;
	}
	//逆转整句话
	for (int k1 = 0, k2 = i - 1; k1 < k2; k1++, k2--) {
		char tmp = str[k1];
		str[k1] = str[k2];
		str[k2] = tmp;
	}

	cout << str << endl;
	system("pause");
	return 0;
}