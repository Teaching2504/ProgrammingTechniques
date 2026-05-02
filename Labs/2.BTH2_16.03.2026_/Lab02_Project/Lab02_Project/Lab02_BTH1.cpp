#include<iostream>
#include<string>
using namespace std;

string ghepHoTen() {
	string ho, tenLot, ten;
	cout << "Nhap ho: ";
	getline(cin, ho);
	cout << "Nhap ten lot: ";
	getline(cin, tenLot);
	cout << "Nhap ten: ";
	getline(cin, ten);

	string hoTen = ho + " " + tenLot + " " + ten;
	return hoTen;
}



int main() {

	cout << ghepHoTen() << endl;
	system("pause");
	return 0;
}