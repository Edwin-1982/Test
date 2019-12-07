#include<iostream>
#include<windows.h>

using namespace std;

/*
	
	I love you! '\0'

	读书 恋爱 分手 恋爱 分手 恋爱 分手

	跳过连续空格 跳过非空格组合 跳过连续空格 跳过非空格组合 跳过连续空格

---------------程序结构------------
	跳过连续空格
	while(当前字符不是'\0'){
		跳过非空格组合
		跳过连续空格
		单词计数+1
	}
-----------------------------------
*/

int main(void) {
	char line[512];   //'\0'就是0
	int count = 0;
	int i = 0;

	cout << "请输入一句话:";
	gets_s(line, sizeof(line));

/*
	while (line[i] ==' ') {
		i++;
	}
*/
	//跳过前面的连续空格
	while (line[i] == ' ')i++;
	while (line[i]) {  //while (line[i] != '\0')  '\0'就是0
		while (line[i]&&line[i]!=' ')i++;
		while (line[i] == ' ')i++;
		count++;
	}
	cout << "一共有" << count << "个单词" << endl;
	system("pause");
	return 0;
}