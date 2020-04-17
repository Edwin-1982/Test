#include<stdio.h>
#include<stdlib.h>

#define BUFSIZE 1024
//ʵ���ļ��Ķ����ƿ���
int copyfile2(const char* dest,const char* src) {
	FILE* fp1 = NULL,* fp2 = NULL;

	//rb ֻ����ʽ��һ���������ļ�,ֻ�����ȡ����
	fopen_s(&fp1, src, "rb");

	if (fp1 == NULL) {
		return -1;
	}

	//wb ��ֻд��ʽ�򿪻��½�һ���������ļ�,ֻ����д����

	fopen_s(&fp2, dest, "wb");
	if (fp2 == NULL) {
		return -2;
	}

	char buffer[BUFSIZE];
	int readlen, writelen;

	//�����������,�����0
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
	ret = copyfile1("e:/Ѹ������/Git�汾��/Test/��ͳ���������/dest.txt", "e:/Ѹ������/Git�汾��/Test/��ͳ���������/src.txt");
	
	if (ret != 0) {
		switch (ret){
		case  -1:
			printf("��Դ�ļ�ʧ��!\n");
			break;
		case  -2:
			printf("��Ŀ���ļ�ʧ��!\n");
			break;
		case  -3:
			printf("�����ļ�ʧ��!\n");
			break;
		default:
			printf("����δ֪���!\n");
			break;
		}
	}
	system("pause");
	return 0;
}