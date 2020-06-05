#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void demo1() {

	vector<int> v2(10, 666);
	int test[] = { 1,2,3,4,5 };
	vector<int>v3(test, test + 2);

	cout << "v2的元素个数: " << v2.size() << endl;
	cout << "v2容器的大小:" << v2.capacity() << endl;

	//vector的插入
	vector<int>::iterator it= v2.insert(v2.begin()+1,888);
	
	for (; it != v2.begin()+3; it++) {
		cout << *it << endl;
	}
	//插入多个元素
	//v2.insert(v2.begin(), 3, 888);

	v2.insert(v2.begin()+3,v3.begin(),v3.end());

	for (int i = 0; i < v2.size(); i++) {
		cout << v2.at(i) << endl;
	}


}
int main(void) {
	demo1();
	system("pause");
	return 0;
}