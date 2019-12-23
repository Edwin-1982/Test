#include<stdio.h>
#include<stdlib.h>

//版本1 
void print1(int a1[3][4]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ",a1[i][j]);
		}
		printf("\n");
	}
}

//版本2
void print2(int a2[][4],int lines) {
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", a2[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	int a[3][4] = {0};
	int a1[4][4] = { 0 };
	int i = 0;
	int j = 0;

	//给数组成员赋值
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = 4 * i + j + 1;
		}
	}
	//print1(a);
	print2(a1, 4);
	printf("------------\n");
	print2(a,3);

	system("pause");
	return 0;
}