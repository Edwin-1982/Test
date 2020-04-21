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
		cout << "�������캯��������!" << endl;
	}
public:
	int age;
	char name[64];
};

void demo1(){

	//��һ���� ����
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(3);


	cout << "v1��Ԫ�ظ���: " << v1.size() << endl;
	cout << "v1�б����Ԫ��: " << endl;
	//��ʽһ,�±����
	/*for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}*/
	//��ʽ��,����������
	//�ڶ����� ������
	/*vector<int>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		cout << *it << endl;
	}*/

	//�������� �㷨

	/*int ncount = count(v1.begin(), v1.end(), 3);
	cout << "v1����ֵΪ3��Ԫ�ظ���:" << ncount << endl;
	vector<int>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		cout << *it << endl;
	}*/
}

//������ֱ�Ӵ�Ŷ���,�ᷢ����������
void demo2() {
	vector<Student> v1;

	Student s1(18, "��С��");
	Student s2(19, "���ӽ�");

	v1.push_back(s1);
	v1.push_back(s2);

	cout << "v1 ��Ԫ�ظ���: " << v1.size() << endl;
	//��ʽһ,�±����
	/*for (int i = 0; i < v1.size(); i++) {
		cout << v1[i].name <<": "<<v1[i].age<< endl;
	}*/
	//��ʽ��,����������
	vector<Student>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		cout << (*it).name << ": " << (*it).age << endl;
	}
}
//�����д��ָ��
void demo3() {
	vector<Student *> v1;
	
	Student s1(18, "��С��");
	Student s2(19, "���ӽ�");

	v1.push_back(&s1);
	v1.push_back(&s2);

	cout << "v1 ��Ԫ�ظ���: " << v1.size() << endl;
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