#include <iostream>
using namespace std;
const int MAXR = 5, MAXC = 6;

void nhapMang(int a[MAXR][MAXC], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << "Nhap a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
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

double tinhTrungBinh(int a[MAXR][MAXC], int r, int c)
{
	double tong = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			tong += a[i][j];
		}
	}
	double tb = tong / (r * c);
	return tb;
}

pair<int, int> timViTriMin(int a[MAXR][MAXC], int r, int c)
{
	int min = a[0][0];
	int minr = 0;
	int minc = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] < min)
			{
				min = a[i][j];
				minr = i;
				minc = j;
			}
		}
	}
	return{ minr, minc };
}

int timMin(int a[MAXR][MAXC], int r, int c)
{
	int min = a[0][0];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] < min)
				min = a[i][j];
		}
	}
	return min;
}

int timMax(int a[MAXR][MAXC], int r, int c)
{
	int max = a[0][0];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < r; j++)
		{
			if (a[i][j] > max)
				max = a[i][j];
		}
	}
	return max;
}

//int main() {
//	int r, c;
//	int a[MAXR][MAXC];
//
//	do
//	{
//		cout << "Nhap so dong va cot: ";
//		cin >> r >> c;
//		if (r > MAXR || c > MAXC || r <= 0 || c <= 0)
//			cout << "Nhap sai yeu cau\n";
//	} while (r > MAXR || c > MAXC || r <= 0 || c <= 0);
//
//	nhapMang(a, r, c);
//	xuatMang(a, r, c);
//	cout << "Trung binh: " << tinhTrungBinh(a, r, c) << endl;
//	cout << "So lon nhat: " << timMax(a, r, c) << endl;
//	cout << "So nho nhat: " << timMin(a, r, c) << endl;
//
//	pair<int, int> kq = timViTriMin(a, r, c);
//	cout << "Hang cua gia tri Min: " << kq.first << endl
//		<< "Cot cua gia tri Min: " << kq.second << endl;
//	system("pause");
//	return 0;
//}