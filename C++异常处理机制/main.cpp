#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define BUFSIZE 1024

//实现文件的二进制拷贝
int copyfile2(const char* dest, const char* src) {
	FILE* fp1 = NULL, * fp2 = NULL;

	//rb 只读方式打开一个二进制文件,只允许读取数据
	fopen_s(&fp1, src, "rb");

	if (fp1 == NULL) {
		throw new string("文件不存在");
	}

	//wb 以只写方式打开或新建一个二进制文件,只允许写数据

	fopen_s(&fp2, dest, "wb");
	if (fp2 == NULL) {
		throw -2;
	}

	char buffer[BUFSIZE];
	int readlen, writelen;

	//如果读到数据,则大于0
	while ((readlen = (int)fread(buffer, 1, BUFSIZE, fp1)) > 0) {
		writelen = (int)fwrite(buffer, 1, readlen, fp2);
		if (readlen != writelen) {
			throw -3;
		}
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}
int copyfile1(const char* dest, const char* src) {
	return copyfile2(dest, src);
}
int main(void) {

	int ret = 0;
	try {
		ret = copyfile1("E:/迅雷下载/Git版本库/Test/C++异常处理机制/dest.txt", "E:/迅雷下载/Git版本库/Test/C++异常处理机制/src.txt");
	}
	catch (int error) {
		printf("出现异常!%d\n",error);
	}
	catch (string *error) {
		printf("捕捉到字符串异常:%s\n", error->c_str());
		delete error;
	}
	system("pause");
	return 0;
}