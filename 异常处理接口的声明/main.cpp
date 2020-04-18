#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define BUFSIZE 1024

class ExceptionText {

};
//1.对于异常接口的声明,在函数声明中列出可能抛出的所有异常类型
//2.如果没有包含异常接口声明,次函数可以抛出任何类型的异常
//3.如果函数生命中有列出可能跑出的所有异常类型,那么抛出其他的类型的异常将可能导致程序终止
//4.如果一个函数不想抛出任何异常,可以使用throw()声明

//实现文件的二进制拷贝
int copyfile2(const char* dest, const char* src) throw(float,string*,int){
	FILE* fp1 = NULL, * fp2 = NULL;

	throw ExceptionText();
	//通过throw操作创建一个异常对象并抛掷
	throw 0.01f;
	//rb 只读方式打开一个二进制文件,只允许读取数据
	fopen_s(&fp1, src, "rb");

	if (fp1 == NULL) {
		throw new string("文件不存在");
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
	try {
		copyfile2(dest, src);
	}
	catch (float e) {
		//throw;
		printf("copyfile1-catch...\n");
		throw e;
	}
	return 0;
}
int main(void) {
	int ret = 0;

	//在需要捕捉异常的地方,将可能抛出异常的程序段嵌在try块之中
	//按正常的程序顺序执行到达try语句,然后执行try块{}内的保护段
	//如果在保护段执行期间没有引起异常,那么跟在try块后的catch子句就不执行,程序从try块后跟随的最后一个catch子句

	try {//保护段
		printf("开始执行copyfile1...\n");
		ret = copyfile1("E:/迅雷下载/Git版本库/Test/C++异常处理机制/dest.txt", "E:/迅雷下载/Git版本库/Test/C++异常处理机制/src.txt");
		printf("执行copyfile1完毕!\n");
	}
	//catch子句按其在try块后出现的顺序被检查,匹配的catch子句将捕获并按catch子句中的代码处理
	catch (int error) {
		printf("出现异常!%d\n", error);
	}
	catch (string* error) {
		printf("捕捉到字符串异常!%s\n", error->c_str());
		delete error;
	}
	catch (float error) {
		printf("出现异常!%f\n", error);
	}
	catch (...) {
		printf("catch...\n");
	}

	//如果没有找到匹配,则缺省功能是调用abort终止程序

	system("pause");
	return 0;
}