#include<iostream>
#include<string>
using namespace std;
const int MAX = 100;

//Tim so lon nhat tren tung cot
void diemCaoNhatTungMon(double diem[MAX][MAX], int r, int c, string hoTen[MAX])
{
	for (int j = 0; j < c; j++)
	{
		double max = diem[0][j];
		int vt = 0;
		for (int i = 0; i < r; i++)
		{
			if (diem[i][j] > max)
			{
				max = diem[i][j];
				vt = i;
			}
		}
		cout << "Diem lon nhat cua mon " << j + 1 << " la: " << max << endl
			<< "Thuoc ve " << hoTen[vt] << endl;
	}
}

void diemTrubgBinhCaoNhat(double diem[MAX][MAX], int r, int c, string hoTen[MAX])
{
	double max = DBL_MIN;
	int vt = -1;
	for (int i = 0; i < r; i++)
	{
		double tong = 0;
		for (int j = 0; j < c; j++)
		{
			tong += diem[i][j];
		}
		double tb = tong / 5;
		if (tb > max)
		{
			max = tb;
			vt = i;
		}
	}
	cout << "Nguoi co diem trung binh cao nhat: " << hoTen[vt] << "(" << max << ")" << endl;
}
int main() {

	string hoTen[MAX] = { "Nguyen Van A", "Tran Thi B", "Le Tien C" };
	double diem[MAX][MAX] = {
		{9, 7.5, 8.3, 7.8, 10},
		{7, 5.5, 6, 6.3, 8 },
		{8.5, 8, 8, 9, 9.5}
	};
	int r = 3;
	int c = 5;
	diemCaoNhatTungMon(diem, r, c);
	system("pause");
	return 0;
}