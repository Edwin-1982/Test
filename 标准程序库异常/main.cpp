
#include<iostream>
#include<exception>
#include<stdexcept>

using namespace std;

class Student {
public:
	Student(int age) {
		if (age > 249) {
			throw out_of_range("年龄太大了,你是外星人吗?");
		}
		m_age = age;
		m_space = new int[1024 * 1024 * 100];
	}
private:
	int m_age;
	int *m_space;
};

int main(void) {
	try {
		for (int i = 1; i < 1024; i++) {
			Student* xiao6lang = new Student(18);
		}
	}
	catch (out_of_range &e) {
		cout << "捕捉到一只异常:" << e.what() << endl;
	}
	catch (bad_alloc& e) {
		cout << "捕捉到动态内存分配异常:" << e.what() << endl;
	}
	system("pause");
	return 0;
}