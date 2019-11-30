#include<iostream>
#include<windows.h>

using namespace std;


//方法1

//void happy(void) {
//happy: //标签
//	cout << "开启没羞没臊的二人世界..." << endl;
//}
//
//int main(void) {
//
//	string ret;
//
//
//	for (int i = 0; i < 5; i++) {
//		cout << "开始第" << i + 1 << "次相亲..." << endl;
//		cout << "你喜欢打王者吗?";
//		cin >> ret;
//
//
//	
//		if (ret != "yes") {
//			continue;
//		}
//		cout << "加个微信吧..." << endl;
//
//		cout << "我中意你,你中意我吗?" << endl;
//		cin >> ret;
//	
//		if (ret == "yes") {
//			happy();
//			system("pause");
//			return 0;
//		}
//	}
//	system("pause");
//	return 0;
//}

//方法2
//int main(void) {
//
//	string ret;
//
//
//	for (int i = 0; i < 5; i++) {
//		cout << "开始第" << i + 1 << "次相亲..." << endl;
//		cout << "你喜欢打王者吗?";
//		cin >> ret;
//
//
//	
//		if (ret != "yes") {
//			continue;
//		}
//		cout << "加个微信吧..." << endl;
//
//		cout << "我中意你,你中意我吗?" << endl;
//		cin >> ret;
//	
//		if (ret == "yes") {
//			goto happy;
//		}
//	}
//	system("pause");
//	return 0;
//
//happy:
//
//	cout << "开始没羞没臊的生活..."<<endl;
//	system("pause");
//	return 0;
//}

//方法3
int main(void) {
	bool flag;
	string ret;


	for (int i = 0; i < 5; i++) {
		cout << "开始第" << i + 1 << "次相亲..." << endl;
		cout << "你喜欢打王者吗?";
		cin >> ret;

		if (ret != "yes") {
			continue;
		}
		cout << "加个微信吧..." << endl;

		cout << "我中意你,你中意我吗?" << endl;
		cin >> ret;
	
		if (ret == "yes") {
			flag=true;
			break;
		}
	}
	if (flag) {
		cout << "开始没羞没臊的生活..." << endl;

	}
	system("pause");
	return 0;

}
