#include<iostream>
#include"Vector.cpp"

int main(void) {

	Vector<int>myVector(10);
	//int a1[10];len:sizeof(a)/sizeof(a[0])
	for (int i = 0; i < myVector.getLength(); i++) {
		myVector[i] = i;
	}
	
	cout << myVector << endl;
	for (int i = 0; i < myVector.getLength(); i++) {
		cout << myVector[i] << endl;
	}
	//测试拷贝构造函数
	Vector<int>myIntVector1(myVector);
	cout << "myIntVector1中的元素如下:" << endl;
	for (int i = 0; i < myIntVector1.getLength(); i++) {
		cout << myVector[i] << endl;
	}
	cout << "---end---" << endl;

	//测试运算符重载
	Vector<int>myIntVector2(1);
	myIntVector2 = myIntVector1;
	
	cout << "myIntVector2中的元素如下:" << endl;
	for (int i = 0; i < myIntVector2.getLength(); i++) {
		cout << myIntVector2[i] << endl;
	}
	cout << "---end---" << endl;

	Vector<float>myVecctor1(10);
	//int a1[10];len:sizeof(a)/sizeof(a[0])
	for (int i = 0; i < myVecctor1.getLength(); i++) {
		myVecctor1[i] = i*0.1f;
	}
	for (int i = 0; i < myVecctor1.getLength(); i++) {
		cout << myVecctor1[i] << endl;
	}
	system("pause");
	return 0;
}
