#include<iostream>
#include<string>


using namespace std;

bool checkTimKiem(string s1, string s2) {
	int a = s1.find(s2);
	if (a >= 0)
		return true;
	else
		return false;
}

int main() {
	string s1, s2;
	cout << "Nhap chuoi s1: ";
	getline(cin, s1);
	cout << "Nhap chuoi s2: ";
	getline(cin, s2);
	if (checkTimKiem(s1, s2) == true) {
		cout << s2 << " Co trong " << s1 << endl;
		string s3;
		cout << "Nhap s3: ";
		getline(cin, s3);
		cout << s1.replace(s1.find(s2), s2.length(), s3) << endl;
	}

	else
		cout << s2 << " Khong co trong " << s1 << endl;


	system("pause");
	return 0;
}