#include<iostream>
#include<string>
using namespace std;


bool ktDoiXung(string s) {
	int n = s.length();
	for (int i = 0; i < n / 2; i++) {

		if (tolower(s[i]) != tolower(s[n - 1 - i]))
			return false;
	}
	return true;
}

int main() {
	string s;
	cout << "Nhap chuoi s: ";
	getline(cin, s);

	if (ktDoiXung(s) == true)
		cout << s << " Doi xung" << endl;
	else
		cout << s << " Khong doi xung!" << endl;
	system("pause");
	return 0;
}