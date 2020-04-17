#include<stdio.h>
#include<stdlib.h>

#define BUFSIZE 1024
//实现文件的二进制拷贝
int copyfile2(const char* dest,const char* src) {
	FILE* fp1 = NULL,* fp2 = NULL;

	//rb 只读方式打开一个二进制文件,只允许读取数据
	fopen_s(&fp1, src, "rb");

	if (fp1 == NULL) {
		return -1;
	}

	//wb 以只写方式打开或新建一个二进制文件,只允许写数据

	fopen_s(&fp2, dest, "wb");
	if (fp2 == NULL) {
		return -2;
	}

	char buffer[BUFSIZE];
	int readlen, writelen;

	//如果读到数据,则大于0
	while ((readlen=(int)fread(buffer, 1, BUFSIZE, fp1)) > 0) {
		writelen = (int)fwrite(buffer, 1, readlen, fp2);
		if (readlen != writelen ) {
			return -3;
		}
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}
int copyfile1(const char* dest,const char* src) {
	return copyfile2(dest, src);
}
 int main(void) {

	int ret = 0;
	ret = copyfile1("e:/迅雷下载/Git版本库/Test/传统错误处理机制/dest.txt", "e:/迅雷下载/Git版本库/Test/传统错误处理机制/src.txt");
	
	if (ret != 0) {
		switch (ret){
		case  -1:
			printf("打开源文件失败!\n");
			break;
		case  -2:
			printf("打开目标文件失败!\n");
			break;
		case  -3:
			printf("拷贝文件失败!\n");
			break;
		default:
			printf("出现未知情况!\n");
			break;
		}
	}
	system("pause");
	return 0;
}