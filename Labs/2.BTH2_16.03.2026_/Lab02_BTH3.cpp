#include<iostream>
#include<string>
using namespace std;

pair<int, int> demChuSo(string s) {
	int chu = 0, so = 0;

	for (int i = 0; i <= s.length() - 1; i++) {
		if (isalpha(s[i]) != 0)
			chu++;
		if (isdigit(s[i]) != 0)
			so++;
	}
	return{ chu, so };
}


int main() {
	string chuoi;
	cout << "Nhap chuoi: ";
	getline(cin, chuoi);
	pair<int, int> kq = demChuSo(chuoi);
	cout << "So chu: " << kq.first << endl;
	cout << "So luong so: " << kq.second << endl;
	system("pause");
	return 0;
}