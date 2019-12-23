#include<stdio.h>
#include<stdlib.h>




int main(void) {
	int i = 0, j = 0;
	int a[3][4];
	

	//使用一个循环给额日为数组成员赋值
	for (int i = 0; i < 12; i++) {
			a[i/4][i%4] = i+1;
	}
	//i = 0 a[0][0]; 1 = > a[0][1]; 3 = > a[0][3]; 	
	//4 = > a[1][0]; 5 = > a[1][1]; ...9=>a[2][1];

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}