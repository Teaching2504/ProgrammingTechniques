#include<iostream>
#include<string>
#include<fstream>

using namespace std;

ifstream fin;

struct HocSinh
{
	string hoTen;
	string ngaySinh; //dd-mm-yyyy
	string queQuan;
	double toan;
	double van;
	double anh;
};

void nhapHS(HocSinh& hs) {
	cout << "------------" << endl;
	cout << "Nhap ho ten: ";
	getline(cin, hs.ngaySinh);
	cout << "Nhap ngay sinh dd-mm-yyyy: ";
	getline(cin, hs.ngaySinh);
	cout << "Nhap qua quan: ";
	getline(cin, hs.queQuan);
	cout << "Nhap diem toan van anh: ";
	cin >> hs.toan >> hs.van >> hs.anh;
}
void nhapFile(HocSinh danhSach[60], int& n) {
	fin.open("HocSinh.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			HocSinh hs;
			getline(fin, hs.hoTen, ';');
			fin.ignore();
			getline(fin, hs.ngaySinh, ';');
			fin.ignore();
			getline(fin, hs.queQuan, ';');
			fin.ignore();
			fin >> hs.toan;
			fin.ignore();
			fin >> hs.van;
			fin.ignore();
			fin >> hs.anh;
			danhSach[n] = hs;
			n++;
		}
		fin.close();
	}
	else
		cout << "Khong mo duoc file!\n";
}

void xuatHocSinh(HocSinh hs) {
	cout << hs.hoTen << "; " << hs.ngaySinh << "; "
		<< hs.queQuan << "; " << hs.toan << "; "
		<< hs.van << "; " << hs.anh;
}

void xuatDS(HocSinh danhSach[60], int n) {
	for (int i = 0; i < n; i++)
		xuatHocSinh(danhSach[i]);
}
int main() {
	HocSinh danhSach[60];
	int n=0;
	nhapFile(danhSach, n);
	xuatDS(danhSach, n);
	system("pause");
	return 0;
}