#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream fin;
	ofstream fout;

	int a, b, c;
	cout << "Nhap 3 so nguyen: ";
	cin >> a >> b >> c;

	fout.open("BTH7.txt");
	//ios::app -> ghi tiep sau file cu
	//ios::out -> ghi de file cu

	if (fout.is_open()) {
		fout << a << "#" << b << "#" << c;
		fout.close();
	}
	else
		cout << "Mo file ghi that bai!\n";

	int x, y, z;
	fin.open("BTH7.txt", ios::in);
	if (fin.is_open())
	{
		fin >> x;
		fin.ignore();
		fin >> y;
		fin.ignore();
		fin >> z;

		cout << "Trung binh: " << (double)(x + y + z) / 3 << endl;
		fin.close();
	}
	system("pause");
	return 0;
}