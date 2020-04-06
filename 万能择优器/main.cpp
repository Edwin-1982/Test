#include<iostream>

using namespace std;

class demo {
public:
	demo(int _k = 0) {
		k = _k;
	}
	~demo() {

	}
	int value() {
		return k;
	}
	bool operator>(demo& dest) {
		if (this->k > dest.k) {
			return true;
		}
		else {
			return false;
		}
	}
private:
	int k;
};
/*********************************************
template ���͹ؼ���,T ��������������
template<������ʽ������>
������ʽ��������ʽ:
typename T1, typename T2, ...typename Tn
*********************************************/
template<typename T, typename T2>
T Max(T a, T2 b) { //��������
	//T tmp = 0;
	return a > b ? a : b;
}
int main(void) {
	char c = 'c';
	int x = 1;
	int y = 2;
	cout << "max(1,2)=" << Max(x, c) << endl;//ʵ�ֲ������͵��Զ��Ƶ�
	cout << "max(1,2)=" << Max<int>(x, y) << endl;//ʵ����ʾ����

	float a = 1.0;
	float b = 2.5;
	cout << "max(1.0,2.0)=" << Max(a, b) << endl;

	demo d1(10);
	demo d2(11);
	cout << "max(d1,d2)=" << Max(d1, d2).value() << endl;
	system("pause");
	return 0;

}