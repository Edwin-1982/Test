#include<iostream>
#include<windows.h>

using namespace std;

/*
	i
	j
	k1 k2
	123 45 678

	678 45 123  ����Ч��
	876 54 321  ����Ч��
	678 45 123

	����1           ����2
	����876 54 321  ��һ��:321 54 876
	    678 45 123  �ڶ���:678 45 123
	    
	
*/

int main(void) {
	char str[256];
	int i = 0;
	

	cout << "������һ�仰(Ӣ��):";
	gets_s(str, sizeof(str));

	while (str[i]) {
		//����ǰ��Ŀո�
		//��ѭ��������,str[i]����һ�����ʵĵ�һ����ĸ
		while (str[i] == ' ')i++;

		int j = i;
		//��ѭ��������,str[j]��������ʺ���ĵ�һ���ո�
		while (str[j] && str[j]!= ' ')j++;
		
		//��ת�������
		for (int k1 = i, k2 = j - 1; k1 < k2; k1++, k2--) {
			char tmp = str[k1];
			str[k1] = str[k2];
			str[k2] = tmp;
		}
		i = j;
	}
	//��ת���仰
	for (int k1 = 0, k2 = i - 1; k1 < k2; k1++, k2--) {
		char tmp = str[k1];
		str[k1] = str[k2];
		str[k2] = tmp;
	}

	cout << str << endl;
	system("pause");
	return 0;
}