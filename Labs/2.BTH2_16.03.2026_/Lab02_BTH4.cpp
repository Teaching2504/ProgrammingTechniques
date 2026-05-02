#include<iostream>
#include<string>
using namespace std;

void vietHoa(string s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = toupper(s[i]);
	}
	cout << s << endl;
}

void vietThuong(string s) {
	for (int i = 0; i < s.length(); i++)
		s[i] = tolower(s[i]);
	cout << s << endl;
}

void xoaNguyenAm(string s) {
	for (int i = 0; i < s.length(); i++) {
		char c = tolower(s[i]);
		if (c == 'a' || c == 'o' || c == 'e' || c == 'u' || c == 'i') {
			s.erase(i, 1);
			//1. Do dai muon xoa
			//2. Do dai muon xoa tu vi tri do
			i--;
		}
	}
	cout << s << endl;

}

int main() {
	string s;
	cout << "Nhap chuoi: ";
	getline(cin, s);
	//TOAN BO VIET HOA
	cout << "CHUOI VIET HOA: ";
	vietHoa(s);
	//chuoi viet thuong
	cout << "Chuoi viet thuong: ";
	vietThuong(s);
	cout << "Chuoi da xoa nguyen am: ";
	xoaNguyenAm(s);
	system("pause");
	return 0;

}