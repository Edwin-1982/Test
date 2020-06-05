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
	v2.push_back(888); //int &&_val=右值引用 C++ 11的新特性

	cout << "v2的元素个数: " << v2.size() << endl;
	cout << "v2容器的大小:" << v2.capacity() << endl;

	//尾部添加和删除元素

	/*
	//v2.push_back(999);
	//v2.push_back();
	v2.pop_back();
	cout << "v2尾部删除一个元素" << endl;
	cout << "v2的元素个数: " << v2.size() << endl;
	cout << "v2容器的大小:" << v2.capacity() << endl;
	*/

	//第一 使用下标操作
	//第二 使用at
	//第三 使用返回的引用
	//第一和第二种方式必须注意越界

	cout << "v2中的元素:" << endl;
	//v2[0] = 555;
	v2.front() = 555;
	v2.back() = 999;
	v2.at(2) = 777;

	for (int i = 0; i < v2.size(); i++) {
		cout << v2.at(i) << endl;
	}

	cout << "v2 第一个元素:" << v2.front() << endl;
	cout << "v2 最后一个元素:" << v2.back() << endl;

}
int main(void) {
	demo1();
	system("pause");
	return 0;
}