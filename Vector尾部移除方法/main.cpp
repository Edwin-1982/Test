#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void demo1() {

	//vector ���ι��캯��
	//vector<int>v2(10);//����ʱ�ͷ���ռ�,ͬʱ����10��Ԫ��,Ԫ�ش�СΪ0
	vector<int> v2(10, 666);
	//vector<int>v3(v2);
	//vector<int>v3(v2.begin()+3, v2.end());
	int test[] = { 1,2,3,4,5 };
	vector<int>v3(test, test + 2);

	cout << "v2��Ԫ�ظ���: " << v2.size() << endl;
	cout << "v2�����Ĵ�С:" << v2.capacity() << endl;
	v2.push_back(888); //int &&_val=��ֵ���� C++ 11��������

	cout << "v2��Ԫ�ظ���: " << v2.size() << endl;
	cout << "v2�����Ĵ�С:" << v2.capacity() << endl;

	//β����Ӻ�ɾ��Ԫ��

	/*
	//v2.push_back(999);
	//v2.push_back();
	v2.pop_back();
	cout << "v2β��ɾ��һ��Ԫ��" << endl;
	cout << "v2��Ԫ�ظ���: " << v2.size() << endl;
	cout << "v2�����Ĵ�С:" << v2.capacity() << endl;
	*/

	//��һ ʹ���±����
	//�ڶ� ʹ��at
	//���� ʹ�÷��ص�����
	//��һ�͵ڶ��ַ�ʽ����ע��Խ��

	cout << "v2�е�Ԫ��:" << endl;
	//v2[0] = 555;
	v2.front() = 555;
	v2.back() = 999;
	v2.at(2) = 777;

	for (int i = 0; i < v2.size(); i++) {
		cout << v2.at(i) << endl;
	}

	cout << "v2 ��һ��Ԫ��:" << v2.front() << endl;
	cout << "v2 ���һ��Ԫ��:" << v2.back() << endl;

}
int main(void) {
	demo1();
	system("pause");
	return 0;
}