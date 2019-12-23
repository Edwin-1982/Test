#include<iostream>
#include<stdlib.h>

using namespace std;

int main(void) {
	int i = 0, j = 0, k = 0;

	int a[3][3][4] = {  //三维数组的定义
		{{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}},
		{{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}},
		{{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}}
	};
	int a1[3][3][4] = { 0 };//第一个元素 a1[0][0][0],36个元素都初始化为0
	for (i = 0; i < 3; i++) {
		printf("--------第%d 个方阵--------\n",i+1);
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 4; k++) {
				printf("%d ", a[i][j][k]);
			}
			printf("\n");
		}
	}

	system("pause");
	return 0;
}