#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define BUFSIZE 1024

class ExceptionText {

};
//1.�����쳣�ӿڵ�����,�ں����������г������׳��������쳣����
//2.���û�а����쳣�ӿ�����,�κ��������׳��κ����͵��쳣
//3.����������������г������ܳ��������쳣����,��ô�׳����������͵��쳣�����ܵ��³�����ֹ
//4.���һ�����������׳��κ��쳣,����ʹ��throw()����

//ʵ���ļ��Ķ����ƿ���
int copyfile2(const char* dest, const char* src) throw(float,string*,int){
	FILE* fp1 = NULL, * fp2 = NULL;

	throw ExceptionText();
	//ͨ��throw��������һ���쳣��������
	throw 0.01f;
	//rb ֻ����ʽ��һ���������ļ�,ֻ�����ȡ����
	fopen_s(&fp1, src, "rb");

	if (fp1 == NULL) {
		throw new string("�ļ�������");
	}

	//wb ��ֻд��ʽ�򿪻��½�һ���������ļ�,ֻ����д����

	fopen_s(&fp2, dest, "wb");
	if (fp2 == NULL) {
		throw - 2;
	}

	char buffer[BUFSIZE];
	int readlen, writelen;

	//�����������,�����0
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

	//����Ҫ��׽�쳣�ĵط�,�������׳��쳣�ĳ����Ƕ��try��֮��
	//�������ĳ���˳��ִ�е���try���,Ȼ��ִ��try��{}�ڵı�����
	//����ڱ�����ִ���ڼ�û�������쳣,��ô����try����catch�Ӿ�Ͳ�ִ��,�����try����������һ��catch�Ӿ�

	try {//������
		printf("��ʼִ��copyfile1...\n");
		ret = copyfile1("E:/Ѹ������/Git�汾��/Test/C++�쳣�������/dest.txt", "E:/Ѹ������/Git�汾��/Test/C++�쳣�������/src.txt");
		printf("ִ��copyfile1���!\n");
	}
	//catch�Ӿ䰴����try�����ֵ�˳�򱻼��,ƥ���catch�Ӿ佫���񲢰�catch�Ӿ��еĴ��봦��
	catch (int error) {
		printf("�����쳣!%d\n", error);
	}
	catch (string* error) {
		printf("��׽���ַ����쳣!%s\n", error->c_str());
		delete error;
	}
	catch (float error) {
		printf("�����쳣!%f\n", error);
	}
	catch (...) {
		printf("catch...\n");
	}

	//���û���ҵ�ƥ��,��ȱʡ�����ǵ���abort��ֹ����

	system("pause");
	return 0;
}