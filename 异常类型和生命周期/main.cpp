#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define BUFSIZE 1024

//ʵ���ļ��Ķ����ƿ���
//��һ�����,throw��ͨ����,�ͺ������ش�ֵ��ͬ
/*
int copyfile2(const char* dest, const char* src) {
	FILE* fp1 = NULL, * fp2 = NULL;

	//rb ֻ����ʽ��һ���������ļ�,ֻ�����ȡ����
	fopen_s(&fp1, src, "rb");

	if (fp1 == NULL) {
		//int ret = -1;
		char ret = 'a';
		throw ret;
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
int main(void) {
	int ret = 0;

	try {//������
		//printf("��ʼִ��copyfile1...\n");
		ret = copyfile1("E:/Ѹ������/Git�汾��/Test/�쳣���ͺ���������/dest.txt", "E:/Ѹ������/Git�汾��/Test/�쳣���ͺ���������/src.txt");
		//printf("ִ��copyfile1���!\n");
	}
	//catch�Ӿ䰴����try�����ֵ�˳�򱻼��,ƥ���catch�Ӿ佫���񲢰�catch�Ӿ��еĴ��봦��
	catch (int error) {
		printf("�����쳣!%d\n", error);
	}
	catch (char error) {
		printf("�����쳣!%c\n", error);
	}
	
	system("pause");
	return 0;
}
*/

/*
//�ڶ������,throw�ַ�������,ʵ���׳���ָ��,����,����ָ���constҲҪ�ϸ��������ƥ��
int copyfile3(const char* dest, const char* src) {
	FILE* fp1 = NULL, * fp2 = NULL;

	//rb ֻ����ʽ��һ���������ļ�,ֻ�����ȡ����
	fopen_s(&fp1, src, "rb");

	if (fp1 == NULL) {
		const char *error = "����,���Դ�ļ���������!";
		printf("throwǰ,error�ĵ�ַ:%p\n", error);
		throw error;
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

	return copyfile3(dest, src);
}
int main(void) {
	int ret = 0;

	try {//������
		//printf("��ʼִ��copyfile1...\n");
		ret = copyfile1("E:/Ѹ������/Git�汾��/Test/�쳣���ͺ���������/dest.txt", "E:/Ѹ������/Git�汾��/Test/�쳣���ͺ���������/src.txt");
		//printf("ִ��copyfile1���!\n");
	}
	//catch�Ӿ䰴����try�����ֵ�˳�򱻼��,ƥ���catch�Ӿ佫���񲢰�catch�Ӿ��еĴ��봦��
	catch (int error) {
		printf("�����쳣!%d\n", error);
	}
	catch (const char error) {
		printf("�����쳣!%c\n", error);
	}
	catch (string error) {
		printf("�����쳣!%s\n", error.c_str());
	}
	catch (const char *error) {
		printf("�����쳣!(char *)!%s(��ַ:%p)\n", error);
	}
	catch (...) {
		printf("δ��׽���쳣����!\n");
	}
	system("pause");
	return 0;
}
*/

//���������,throw������,��ѵķ�ʽ��ʹ���������Ͳ�׽,�׳���������
//����Ƕ�̬����Ķ���,ֱ���׳���ָ��
//ע��,���ú���ͨ���βδ�ֵ���ܹ���
class ErrorException {
public:
	ErrorException() {
		id = 0;
		printf("ErrorException ����!\n");
	}
	~ErrorException() {
		printf("ErrorException ����!(id:%d)\n",id);
	}
	ErrorException(const ErrorException& e) {
		id = 1;
		printf("ErrorException �������캯��!\n");
	}
	int id;
};
int copyfile4(const char* dest,const char* src) {
	FILE* fp1 = NULL, * fp2 = NULL;

	//rb ֻ����ʽ��һ���������ļ�,ֻ�����ȡ����
	fopen_s(&fp1, src, "rb");

	if (fp1 == NULL) {
		//throw ErrorException();throw������
		throw new ErrorException();//��̬�������
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
int copyfile1(const char* dest,const char* src) {

	return copyfile4(dest, src);
}
int main(void) {
	int ret = 0;

	try {//������
		//printf("��ʼִ��copyfile1...\n");
		ret =copyfile1("E:/Ѹ������/Git�汾��/Test/�쳣���ͺ���������/dest.txt", "E:/Ѹ������/Git�汾��/Test/�쳣���ͺ���������/src.txt");
		//printf("ִ��copyfile1���!\n");
	}
	//catch�Ӿ䰴����try�����ֵ�˳�򱻼��,ƥ���catch�Ӿ佫���񲢰�catch�Ӿ��еĴ��봦��
	
	//�βδ�ֵ
	//catch (ErrorException& error) {
	//	printf("�����쳣!��׽��ErrorException &���� id:%d\n", error.id);
	//}
	catch (ErrorException &error) {
		//error.id = 2;
		printf("�����쳣!��׽��ErrorException &���� id:%d\n",error.id);
	}
	catch (ErrorException* error) {
		//error.id = 2;
		printf("�����쳣!��׽��ErrorException���� id:%d\n", error->id);
		delete error;
	}
	catch (...) {
		printf("û�в�׽���쳣!\n");
	}
	system("pause");
	return 0;
}