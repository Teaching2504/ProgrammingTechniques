#include <iostream>
#include <cstdlib>
#include <ctime>
//#include "lab1_Bai3.cpp"
using namespace std;
const int MAXR = 5, MAXC = 6;

//Khoi tao ngau nhien tu 1 den 10 cho mang 2 chieu
void khoiTaoMang(int a[MAXR][MAXC], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			a[i][j] = rand() % 10 + 1;
			//0 --> RAND_MAX: rand()
			//0 --> 9: rand() % 10 (Chia lay du cho 10)
			//1 --> 10: rand() % 10 + 1
			//0 --> 90: rand() % 91
			//10 --> 100: rand() % 91 + 10
			//min --> max: rand() % (max - min + 1) + min
		}
	}
}

void xuatMang(int a[MAXR][MAXC], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

void tinhTongCot(int a[MAXR][MAXC], int r, int c)
{
	int cot;
	do {
		cout << "Nhap so cot muon tinh tong: ";
		cin >> cot;
		if (cot < 0 || cot > c - 1)
			cout << "Nhap sai dieu kien!\n";
	} while (cot < 0 || cot > c - 1);

	int tong = 0;
	for (int i = 0; i < r; i++)
		tong += a[i][cot];
	cout << "Tong cua cot " << cot << " la: " << tong << endl;
}

void tinhTongHang(int a[MAXR][MAXC], int r, int c)
{
	int hang;
	do {
		cout << "Nhap so hang muon tinh tong: ";
		cin >> hang;
		if (hang < 0 || hang > r - 1)
			cout << "Nhap sai! vui long nhap lai!\n";
	} while (hang < 0 || hang > r - 1);
	int tong = 0;
	for (int j = 0; j < c; j++)
	{
		tong += a[hang][j];
	}
	cout << "Tong cua hang " << hang << " la: " << tong << endl;
}

pair<int, int> timKiem(int a[MAXR][MAXC], int r, int c)
{
	int x;
	cout << "Nhap so muon tim: ";
	cin >> x;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == x)
				return{ i, j }; //Tra ve vi tri dau tien tim thay
		}
	}

	return{ -1, -1 };
}

int main() {

	srand(time(0));
	int r, c;
	int a[MAXR][MAXC];

	do {
		cout << "Nhap so dong va cot: ";
		cin >> r >> c;
		if (r > MAXR || c > MAXC || r <= 0 || c <= 0)
			cout << "Nhap sai yeu cau\n";

	} while (r > MAXR || c > MAXC || r <= 0 || c <= 0);

	khoiTaoMang(a, r, c);
	xuatMang(a, r, c);
	tinhTongCot(a, r, c);
	tinhTongHang(a, r, c);

	pair<int, int> kq = timKiem(a, r, c);
	if (kq.first == -1)
		cout << "Khong tim thay\n";
	else
		cout << "Tim thay tai hang " << kq.first << " cot " << kq.second << endl;


	system("pause");
	return 0;
}