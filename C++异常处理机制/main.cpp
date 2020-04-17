#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define BUFSIZE 1024

//ʵ���ļ��Ķ����ƿ���
int copyfile2(const char* dest, const char* src) {
	FILE* fp1 = NULL, * fp2 = NULL;

	//rb ֻ����ʽ��һ���������ļ�,ֻ�����ȡ����
	fopen_s(&fp1, src, "rb");

	if (fp1 == NULL) {
		throw new string("�ļ�������");
	}

	//wb ��ֻд��ʽ�򿪻��½�һ���������ļ�,ֻ����д����

	fopen_s(&fp2, dest, "wb");
	if (fp2 == NULL) {
		throw -2;
	}

	char buffer[BUFSIZE];
	int readlen, writelen;

	//�����������,�����0
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
		ret = copyfile1("E:/Ѹ������/Git�汾��/Test/C++�쳣�������/dest.txt", "E:/Ѹ������/Git�汾��/Test/C++�쳣�������/src.txt");
	}
	catch (int error) {
		printf("�����쳣!%d\n",error);
	}
	catch (string *error) {
		printf("��׽���ַ����쳣:%s\n", error->c_str());
		delete error;
	}
	system("pause");
	return 0;
}