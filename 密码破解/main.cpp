#include<iostream>
#include<windows.h>

using namespace std;

int main(void) {
	char pwd[7];
	char dict[64];//10+26+26+1=63;
	char tmp[32];
	int index = 0;

	//dict数组存放每一位密码的可能值
	for (int i = 0; i < 10; i++) {
		//'3'='0'+3
		dict[index++] = '0' + i;
	}
	/*for (int i = 0; i < 26; i++) {
		//'c'='a'+2
		dict[index++] = 'a' + i;
	}
	for (int i = 0; i < 26; i++) {
		//'c'='a'+2
		dict[index++] = 'A' + i;
	}
	dict[index++]='-';
	*/

	//dict[index] = '\0';
	int n = index;//字符个数

	
	for (int p1 = 0; p1 < n; p1++) {
		for (int p2 = 0; p2 < n; p2++) {
			for (int p3 = 0; p3 < n; p3++) {
				for (int p4 = 0; p4 < n; p4++) {
					for (int p5 = 0; p5 < n; p5++) {
						for (int p6 = 0; p6 < n; p6++){
							tmp[0] = dict[p1];
							tmp[1] = dict[p2];
							tmp[2] = dict[p3];
							tmp[3] = dict[p4];
							tmp[4] = dict[p3];
							tmp[5] = dict[p4];
							tmp[6] = '\0';
							
							cout << tmp << endl;
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}