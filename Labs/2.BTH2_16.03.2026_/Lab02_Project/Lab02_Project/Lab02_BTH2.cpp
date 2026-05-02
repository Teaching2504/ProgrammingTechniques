#include<iostream>
#include<string>
using namespace std;


void daoNguoc(string& s) {

	int n = s.length();

	for (int i = 0; i < n / 2; i++) {
		char tmp;
		tmp = s[i];
		s[i] = s[n - 1 - i];
		s[n - 1 - i] = tmp;
	}

}

string daoNguoc2(string s) {
	string kq = "";
	for (int i = s.length() - 1; i >= 0; i--)
		kq += s[i];
	return s;
}
int main() {

	string chuoi;
	cout << "Nhap chuoi: ";
	getline(cin, chuoi);
	daoNguoc(chuoi);
	cout << "Chuoi dao nguoc: " << chuoi << endl;
	cout << "Chuoi dao nguoc 2: " << daoNguoc2(chuoi) << endl;
	cout << "Chuoi dao nguoc 3: ";
	reverse(chuoi.begin(), chuoi.end());
	system("pause");
	return 0;
}