#include<iostream>
#include<fstream>

using namespace std;

const int MAX = 100;
//
//void vietHoaKTDau(string s) {
//	int n = s.length();
//	for (int i = 0;i < n - 1;i++)
//
//}

int main() {

	string ten[MAX] = { "phap", "nhat ban", "hoa ky", "duc", "y", "uc","ha lan", "trung quoc","anh", "han quoc" };
	int soHC[MAX][MAX] = {
		{16, 26, 22},
		{20, 12, 13},
		{40, 44, 42},
		{12, 13, 8},
		{12, 13, 15},
		{18, 19, 16},
		{15, 7, 12},
		{40, 27, 24},
		{14, 22, 29},
		{13, 9, 10}
	};

	system("pause");
	return 0;
}