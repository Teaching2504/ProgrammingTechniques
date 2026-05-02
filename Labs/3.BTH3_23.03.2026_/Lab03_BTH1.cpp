#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

struct NhanVien
{
	string maNV;
	string hoTen;
	int namSinh;
	int namVaoLam;

	void nhapNV() {
		cout << "Nhap ma so nhan vien: ";
		getline(cin, maNV);
		cout << "Nhap ho ten: ";
		getline(cin, hoTen);
		cout << "Nhap nam sinh: ";
		cin >> namSinh;
		cout << "Nhap nam vao lam: ";
		cin >> namVaoLam;
		cin.ignore();
		//getline: cho nguoi dung nhap den dau enter(\n) th dung
		//getline: khi gap enter ti dung va bo qua
		//cin: Khi gap enter se dung nhung khong bo qua
		//cin: cho nguoi dung nhap den ky tu dac biet, va bao gom khoang trang
	}
	void xuatNV() {
		cout << maNV << " - "
			<< hoTen << " - "
			<< namSinh << " - "
			<< namVaoLam << endl
			<< "-----------" << endl;

	}

	int tinhTuoi() {
		//Time(0): day so tho gian hien tai
		time_t hienTai = time(0);
		tm*ntn = localtime(&hienTai);
		int namHienTai = ntn->tm_year + 1900;
		return namHienTai - namSinh;
	}

	int tinhThamNien() {
		time_t hienTai = time(0);
		tm*ntn = localtime(&hienTai);
		int namHienTai = ntn->tm_year + 1900;
		return namHienTai - namVaoLam;
	}
};

int main() {
	NhanVien dsnv[10];
	for (int i = 0; i < 10; i++) {
		dsnv[i].nhapNV();
		dsnv[i].xuatNV();
	}

	system("pausee");
	return 0;
}