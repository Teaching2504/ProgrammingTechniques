#include <iostream>
#include <ctime>
using namespace std;
const int MAXR = 100, MAXC = 100;


void khoiTaoMang(int a[MAXR][MAXC], int r, int c) {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] = rand() % (100 - 1 + 1) + 1;
		}
	}
}

void xuatMang(int a[MAXR][MAXC], int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

}

int tinhsum(int a[MAXR][MAXC], int r, int c) {
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			sum += a[i][j];
		}
	}
	return sum;
}

int main() {
	int r, c;
	int a[MAXR][MAXR];
	int tong = 0;
	srand(time(0));

	cout << "nhap so dong va cot: ";
	cin >> r >> c;


	do {
		khoiTaoMang(a, r, c);
		tong = tinhsum(a, r, c);
	} while (tong != 200);

	xuatMang(a, r, c);

	return 0;
}