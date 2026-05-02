#include<iostream>
#include<fstream>
#include<string>

using namespace std;
ofstream fout;

struct NTN {
	int ngay, thang, nam;
};

struct SanPham
{
	string maSP;
	string tenSP;
	double donGia;
	int soLuong;
	NTN ngaySX;
};

void nhapSanPham(SanPham& sp) {
	cout << "---------------\n"
		<< "Nhap ma san pham: ";
	getline(cin, sp.maSP);
	cout << "Nhap ten san pham: ";
	getline(cin, sp.tenSP);
	cout << "Nhap don gia: ";
	cin >> sp.donGia;
	cout << "Nhap so luong: ";
	cin >> sp.soLuong;
	cout << "Nhap ngay san xuat: ";
	cin >> sp.ngaySX.ngay >> sp.ngaySX.thang >> sp.ngaySX.nam;
	cin.ignore();
}

void NhapCH(SanPham cuaHang[60], int n) {
	for (int i = 0; i < n; i++)
		nhapSanPham(cuaHang[i]);
}

void xuatSP(SanPham sp) {
	cout << sp.maSP << " - " << sp.tenSP
		<< " - " << sp.donGia << " - "
		<< sp.soLuong << " - " << sp.ngaySX.ngay
		<< "/" << sp.ngaySX.thang << "/" << sp.ngaySX.nam << endl;
}

void xuatCH(SanPham cuaHang[60], int n) {
	for (int i = 0; i<n;i++)
		xuatSP(cuaHang[i]);
}

void timTenSP(SanPham cuaHang[60], int n) {
	string s;
	cout << "Nhap chuoi can tim: ";
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		//1.Nhap chuoi/ky tu muon tim
		//2. Vi tri bat dau
		if (cuaHang[i].tenSP.find(s) != cuaHang[i].tenSP.npos) {
			xuatSP(cuaHang[i]);
		}
		else
			cout << "Khong tim thay ten san pham\n";
	}
}

void xoaMaSP(SanPham cuaHang[06], int& n) {
	//Buoc 1. Tim vi tri cua sp muon xoa
	string s;
	int vt = -1;
	cout << "Nhap ma SP xoa: ";
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		if (cuaHang[i].maSP == s) {
			vt = i;
			//Buoc 02. Thuc hien xoa san pham
			for (int j=vt; j< n - 1; j++)
				cuaHang[i] = cuaHang[i + 1];
			n--;
		}
	}
	if(vt == -1)
		cout << "Khong co ma SP trong cua hang!\n";
}
void sapXep(SanPham cuaHang[60], int n) {
	//interchange sort
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (cuaHang[j].donGia < cuaHang[i].donGia)
				swap(cuaHang[i], cuaHang[j]);
		}
	}
}

void ghiSanPham(SanPham cuaHang[60], int n) {
	fout.open("DSSP.txt", ios::out);
	if (fout.is_open()) {
		for (int i = 0; i < n; i++) {
			SanPham sp = cuaHang[i];
			fout << sp.maSP << ", " << sp.tenSP
				<< ", " << sp.donGia << ", "
				<< sp.soLuong << ", " << sp.ngaySX.ngay
				<< "/" << sp.ngaySX.thang << "/" << sp.ngaySX.nam << endl;
		}
		fout.close();
	}
	else
		cout << "Khong mo duoc file!\n";
}

int main() {
	SanPham cuaHang[60];
	int n;
	cout << "Nhap so luong san pham: ";
	cin >> n;
	cin.ignore();
	NhapCH(cuaHang, n);
	xuatCH(cuaHang, n);
	//timTenSP(cuaHang, n);
	//xoaMaSP(cuaHang, n);
	sapXep(cuaHang, n);
	xuatCH(cuaHang, n);
	ghiSanPham(cuaHang, n);
	system("pause");
	return 0;
}
