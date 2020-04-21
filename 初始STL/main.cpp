#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Student {
public:
	Student(int age, const char* name) {
		this->age = age;
		strncpy_s(this->name, name, 64);
	}
	Student(const Student &s) {
		this->age = s.age;
		strncpy_s(this->name, s.name, 64);
		cout << "拷贝构造函数被调用!" << endl;
	}
public:
	int age;
	char name[64];
};

void demo1(){

	//第一部分 容器
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(3);


	cout << "v1的元素个数: " << v1.size() << endl;
	cout << "v1中保存的元素: " << endl;
	//方式一,下标访问
	/*for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}*/
	//方式二,迭代器访问
	//第二部分 迭代器
	/*vector<int>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		cout << *it << endl;
	}*/

	//第三部分 算法

	/*int ncount = count(v1.begin(), v1.end(), 3);
	cout << "v1中数值为3的元素个数:" << ncount << endl;
	vector<int>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		cout << *it << endl;
	}*/
}

//容器中直接存放对象,会发生拷贝构造
void demo2() {
	vector<Student> v1;

	Student s1(18, "林小美");
	Student s2(19, "王子健");

	v1.push_back(s1);
	v1.push_back(s2);

	cout << "v1 的元素个数: " << v1.size() << endl;
	//方式一,下标访问
	/*for (int i = 0; i < v1.size(); i++) {
		cout << v1[i].name <<": "<<v1[i].age<< endl;
	}*/
	//方式二,迭代器访问
	vector<Student>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		cout << (*it).name << ": " << (*it).age << endl;
	}
}
//容器中存放指针
void demo3() {
	vector<Student *> v1;
	
	Student s1(18, "林小美");
	Student s2(19, "王子健");

	v1.push_back(&s1);
	v1.push_back(&s2);

	cout << "v1 的元素个数: " << v1.size() << endl;
	vector<Student*>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		cout << (**it).name << ": " << (**it).age << endl;
	}
}
int main(void) {
	
	demo3();
	
	system("pause");
	return 0;
}