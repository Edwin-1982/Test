#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define BUFSIZE 1024

//实现文件的二进制拷贝
//第一种情况,throw普通类型,和函数返回传值相同
/*
int copyfile2(const char* dest, const char* src) {
	FILE* fp1 = NULL, * fp2 = NULL;

	//rb 只读方式打开一个二进制文件,只允许读取数据
	fopen_s(&fp1, src, "rb");

	if (fp1 == NULL) {
		//int ret = -1;
		char ret = 'a';
		throw ret;
	}

	//wb 以只写方式打开或新建一个二进制文件,只允许写数据

	fopen_s(&fp2, dest, "wb");
	if (fp2 == NULL) {
		throw - 2;
	}

	char buffer[BUFSIZE];
	int readlen, writelen;

	//如果读到数据,则大于0
	while ((readlen = (int)fread(buffer, 1, BUFSIZE, fp1)) > 0) {
		writelen = (int)fwrite(buffer, 1, readlen, fp2);
		if (readlen != writelen) {
			throw - 3;
		}
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}
int main(void) {
	int ret = 0;

	try {//保护段
		//printf("开始执行copyfile1...\n");
		ret = copyfile1("E:/迅雷下载/Git版本库/Test/异常类型和生命周期/dest.txt", "E:/迅雷下载/Git版本库/Test/异常类型和生命周期/src.txt");
		//printf("执行copyfile1完毕!\n");
	}
	//catch子句按其在try块后出现的顺序被检查,匹配的catch子句将捕获并按catch子句中的代码处理
	catch (int error) {
		printf("出现异常!%d\n", error);
	}
	catch (char error) {
		printf("出现异常!%c\n", error);
	}
	
	system("pause");
	return 0;
}
*/

/*
//第二种情况,throw字符串类型,实际抛出的指针,而且,修饰指针的const也要严格进行类型匹配
int copyfile3(const char* dest, const char* src) {
	FILE* fp1 = NULL, * fp2 = NULL;

	//rb 只读方式打开一个二进制文件,只允许读取数据
	fopen_s(&fp1, src, "rb");

	if (fp1 == NULL) {
		const char *error = "大佬,你的源文件打开有问题!";
		printf("throw前,error的地址:%p\n", error);
		throw error;
	}

	//wb 以只写方式打开或新建一个二进制文件,只允许写数据

	fopen_s(&fp2, dest, "wb");
	if (fp2 == NULL) {
		throw - 2;
	}

	char buffer[BUFSIZE];
	int readlen, writelen;

	//如果读到数据,则大于0
	while ((readlen = (int)fread(buffer, 1, BUFSIZE, fp1)) > 0) {
		writelen = (int)fwrite(buffer, 1, readlen, fp2);
		if (readlen != writelen) {
			throw - 3;
		}
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}
int copyfile1(const char* dest, const char* src) {

	return copyfile3(dest, src);
}
int main(void) {
	int ret = 0;

	try {//保护段
		//printf("开始执行copyfile1...\n");
		ret = copyfile1("E:/迅雷下载/Git版本库/Test/异常类型和生命周期/dest.txt", "E:/迅雷下载/Git版本库/Test/异常类型和生命周期/src.txt");
		//printf("执行copyfile1完毕!\n");
	}
	//catch子句按其在try块后出现的顺序被检查,匹配的catch子句将捕获并按catch子句中的代码处理
	catch (int error) {
		printf("出现异常!%d\n", error);
	}
	catch (const char error) {
		printf("出现异常!%c\n", error);
	}
	catch (string error) {
		printf("出现异常!%s\n", error.c_str());
	}
	catch (const char *error) {
		printf("出现异常!(char *)!%s(地址:%p)\n", error);
	}
	catch (...) {
		printf("未捕捉到异常类型!\n");
	}
	system("pause");
	return 0;
}
*/

//第三种情况,throw类类型,最佳的方式是使用引用类型捕捉,抛出匿名对象
//如果是动态分配的对象,直接抛出其指针
//注意,引用和普通的形参传值不能共存
class ErrorException {
public:
	ErrorException() {
		id = 0;
		printf("ErrorException 构造!\n");
	}
	~ErrorException() {
		printf("ErrorException 析构!(id:%d)\n",id);
	}
	ErrorException(const ErrorException& e) {
		id = 1;
		printf("ErrorException 拷贝构造函数!\n");
	}
	int id;
};
int copyfile4(const char* dest,const char* src) {
	FILE* fp1 = NULL, * fp2 = NULL;

	//rb 只读方式打开一个二进制文件,只允许读取数据
	fopen_s(&fp1, src, "rb");

	if (fp1 == NULL) {
		//throw ErrorException();throw类类型
		throw new ErrorException();//动态分配对象
	}

	//wb 以只写方式打开或新建一个二进制文件,只允许写数据

	fopen_s(&fp2, dest, "wb");
	if (fp2 == NULL) {
		throw - 2;
	}

	char buffer[BUFSIZE];
	int readlen, writelen;

	//如果读到数据,则大于0
	while ((readlen = (int)fread(buffer, 1, BUFSIZE, fp1)) > 0) {
		writelen = (int)fwrite(buffer, 1, readlen, fp2);
		if (readlen != writelen) {
			throw - 3;
		}
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}
int copyfile1(const char* dest,const char* src) {

	return copyfile4(dest, src);
}
int main(void) {
	int ret = 0;

	try {//保护段
		//printf("开始执行copyfile1...\n");
		ret =copyfile1("E:/迅雷下载/Git版本库/Test/异常类型和生命周期/dest.txt", "E:/迅雷下载/Git版本库/Test/异常类型和生命周期/src.txt");
		//printf("执行copyfile1完毕!\n");
	}
	//catch子句按其在try块后出现的顺序被检查,匹配的catch子句将捕获并按catch子句中的代码处理
	
	//形参传值
	//catch (ErrorException& error) {
	//	printf("出现异常!捕捉到ErrorException &类型 id:%d\n", error.id);
	//}
	catch (ErrorException &error) {
		//error.id = 2;
		printf("出现异常!捕捉到ErrorException &类型 id:%d\n",error.id);
	}
	catch (ErrorException* error) {
		//error.id = 2;
		printf("出现异常!捕捉到ErrorException类型 id:%d\n", error->id);
		delete error;
	}
	catch (...) {
		printf("没有捕捉到异常!\n");
	}
	system("pause");
	return 0;
}