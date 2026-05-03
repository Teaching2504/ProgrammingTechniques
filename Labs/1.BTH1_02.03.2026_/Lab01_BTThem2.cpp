#include <iostream>
#include <string>
using namespace std;
const int MAX = 100;

void diemCaoNhatTungMon(double diem[MAX][MAX], string hoTen[], int soSV, int soMH)
{
	for (int j = 0; j < soMH; j++)
	{
		double max = diem[0][j];
		int vt = 0;
		for (int i = 0; i < soSV; i++)
		{
			if (diem[i][j] > max)
			{
				max = diem[i][j];
				vt = i;
			}
		}
		cout << "Diem cao nhat cua mon " << j + 1 << ": " << max << " (" << hoTen[vt] << ")\n";
	}
}

void trungBinhCaoNhat(double diem[MAX][MAX], string hoTen[], int soSV, int soMH)
{
	double max = DBL_MIN; 
	int vt = -1;
	for (int i = 0; i < soSV; i++)
	{
		double tong = 0; // tong cua hang
		for (int j = 0; j < soMH; j++)
		{
			tong += diem[i][j];
		}
		double tb = tong / soMH; // trung binh 5 mon
		if (tb > max)
		{
			max = tb;
			vt = i;
		}
	}

	cout << "Diem trung binh cao nhat: " << max << " (" << hoTen[vt] << ")\n";
}

void timKiemSinhVien(double diem[MAX][MAX], string hoTen[], int soSV, int soMH)
{
	string ht;
	cout << "Nhap ho ten sinh vien can tim: ";
	getline(cin, ht);

	int vt = -1;
	for (int i = 0; i < soSV; i++)
	{
		if (hoTen[i] == ht)
			vt = i;
	}

	if (vt != -1)
	{
		cout << "Ho ten: " << ht << ". Diem: ";
		for (int j = 0; j < soMH; j++)
			cout << diem[vt][j] << "\t";
		cout << endl;
	}
	else
		cout << "Khong tim thay sinh vien\n";
}

void themSinhVien(double diem[MAX][MAX], string hoTen[], int &soSV, int soMH)
{	
	if (soSV < MAX)
	{
		cout << "Nhap ho ten sinh vien: ";
		getline(cin, hoTen[soSV]);
		for (int j = 0; j < soMH; j++)
		{
			cout << "Nhap diem mon " << j + 1 << ": ";
			cin >> diem[soSV][j];
		}
		soSV++;
	}
	else
		cout << "Danh sach da day\n";
}

void xuatDSSV(double diem[MAX][MAX], string hoTen[], int soSV, int soMH)
{
	cout << "Danh sach sinh vien:\n";
	for (int i = 0; i < soSV; i++)
	{
		cout << hoTen[i] << "\t";
		for (int j = 0; j < soMH; j++)
		{
			cout << diem[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	string hoTen[MAX] = { 
		"Nguyen Van A", 
		"Tran Thi B", 
		"Le Tien C",
		"Ly Minh D",
		"Nguyen Thi E",
		"Cao Van F",
		"Bui Thi G",
		"Tran Minh H"
	};

	double diem[MAX][MAX] = {
		{9.0, 7.5, 8.3, 7.8, 10},
		{7, 5.5, 6, 6.3, 8},
		{8.5, 8, 8, 9, 9.5},
		{6, 4.5, 5, 5.3, 7},
		{7.8, 7, 8, 6.8, 8.8},
		{10, 9, 8.5, 10, 10},
		{5, 6, 4.5, 4.3, 6.5},
		{7, 7.8, 7.5, 6.5, 8.3}
	};

	int soSV = 8; // so sinh vien
	int soMH = 5; // so mon hoc
	int luaChon;

	do
	{
		cout << "====HE THONG QUAN LY SINH VIEN====\n";
		cout << "0. Thoat\n";
		cout << "1. In ra diem cao nhat cua tung mon\n";
		cout << "2. In ra sinh vien co diem trung binh cao nhat\n";
		cout << "3. Tim kiem sinh vien theo ho ten\n";
		cout << "4. Them sinh vien moi\n";
		cout << "Nhap lua chon cua ban: ";
		cin >> luaChon;
		cin.ignore();

		switch (luaChon)
		{
		case 0:
			cout << "Chao tam biet\n";
			break;
		case 1:
			diemCaoNhatTungMon(diem, hoTen, soSV, soMH);
			break;
		case 2:
			trungBinhCaoNhat(diem, hoTen, soSV, soMH);
			break;
		case 3:
			timKiemSinhVien(diem, hoTen, soSV, soMH);
			break;
		case 4:
			themSinhVien(diem, hoTen, soSV, soMH);
			xuatDSSV(diem, hoTen, soSV, soMH);
			break;			
		default:
			cout << "Lua chon khong hop le\n";
		}
				
	} while (luaChon != 0);
	return 0;
}
