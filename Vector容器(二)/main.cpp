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
	v2.push_back(888);

	cout << "v2��Ԫ�ظ���: " << v2.size() << endl;
	cout << "v2�����Ĵ�С:" << v2.capacity() << endl;
	
	//���µ���Vector�Ĵ�С
	
	v2.resize(2,999);//��һ�ַ�ʽ:���¶����С
	//v2.resize(13,888);//�ڶ��ַ�ʽ:���¶����С,������ָ��������ֵ
	//v2.resize(13);//�����ַ�ʽ:���¶����С,����ʱ��ָ��������ֵ.Ĭ�ϲ�����0
	cout << "v2��Ԫ�ظ���: " << v2.size() << endl;
	cout << "v2�����Ĵ�С:" << v2.capacity() << endl;

	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << endl;
	}
	cout << "----- endl----- "<< endl;
	vector<int> v4;
	if (v4.empty()) {
		cout << "v4Ϊ��!" << endl;
	}
}
int main(void) {
	demo1();
	system("pause");
	return 0;
}