#include<iostream>
#include<vector>

using namespace std;
class demo {
public:
	demo(int _k = 0) { 
		k = _k; 
	};
	~demo() {
	};
	int value() {
		return k;
	}
private:
	int k;
};
int main(void) {

	vector<int>v1;
	int i1 = 1;
	int i2 = 2;
	v1.push_back(i1);
	v1.push_back(i2);

	demo d1(10);
	vector<demo>v2;
	v2.push_back(d1);

	for (int i = 0; i < v1.size(); i++) {
		printf_s("vetor v1ÖÐµÄÔªËØ%d:%d\n", i, v1[i]);
	}
	cout << v2[0].value() << endl;
	system("pause");
	return 0;
}

