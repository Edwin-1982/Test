#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void demo1() {

	//vector 带参构造函数
	//vector<int>v2(10);//构造时就分配空间,同时插入10个元素,元素大小为0
	vector<int> v2(10, 666);
	//vector<int>v3(v2);
	//vector<int>v3(v2.begin()+3, v2.end());
	int test[] = { 1,2,3,4,5 };
	vector<int>v3(test, test + 2);
	
	cout << "v2的元素个数: " << v2.size() << endl;
	cout << "v2容器的大小:" << v2.capacity() << endl;
	v2.push_back(888);

	cout << "v2的元素个数: " << v2.size() << endl;
	cout << "v2容器的大小:" << v2.capacity() << endl;
	
	//重新调整Vector的大小
	
	v2.resize(2,999);//第一种方式:重新定义大小
	//v2.resize(13,888);//第二种方式:重新定义大小,扩大是指定新增的值
	//v2.resize(13);//第三种方式:重新定义大小,扩大时不指定新增的值.默认补充是0
	cout << "v2的元素个数: " << v2.size() << endl;
	cout << "v2容器的大小:" << v2.capacity() << endl;

	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << endl;
	}
	cout << "----- endl----- "<< endl;
	vector<int> v4;
	if (v4.empty()) {
		cout << "v4为空!" << endl;
	}
}
int main(void) {
	demo1();
	system("pause");
	return 0;
}