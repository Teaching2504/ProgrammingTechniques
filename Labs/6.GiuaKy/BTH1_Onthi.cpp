#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

struct NhanVien
{
	string maNV;
	string hoTen;
	int namvaoLam, namSinh;
};

//a. Viết hàm nhập thông tin Nhân viên
void nhap1NV(NhanVien& nv)
{
	cout << "---------------------\n";
	cout << "Nhap ma Nhan vien: ";
	getline(cin, nv.maNV);
	cout << "Nhap Ho va ten nhan vien: ";
	getline(cin, nv.hoTen);
	cout << "Nhap nam vao lam: ";
	cin >> nv.namvaoLam;
	cout << "Nhap nam sinh: ";
	cin >> nv.namSinh;
	cin.ignore();
}

//b. Viết hàm xuất thông tin nhân viên
void xuat1NV(NhanVien nv)
{
	cout << "-------------------------\n";
	cout << "Ma Nhan vien: " << nv.maNV << endl
		<< "Ten nhan vien: " << nv.hoTen << endl
		<< "Nam vao lam: " << nv.namvaoLam << endl
		<< "Nam sinh: " << nv.namSinh << endl;
}
//c. Viết hàm tính tuổi cho Nhân Viên
int tinhTuoi(NhanVien nv)
{
	time_t hienTai = time(0);
	tm* ntn = localtime(&hienTai);

	int namHienTai = ntn->tm_year + 1900;
	return namHienTai - nv.namSinh;
}

//Tính thâm niên
int thamNien(NhanVien nv)
{
	time_t hienTai = time(0);
	tm* ntn = localtime(&hienTai);

	int namHienTai = ntn->tm_year + 1990;
	return namHienTai - nv.namvaoLam;
}

int main() {
	NhanVien nv;
	nhap1NV(nv);
	xuat1NV(nv);
	cout << "Tuoi cua nhan vien la: " << tinhTuoi(nv) << endl;
	system("pause");
	return 0;
}