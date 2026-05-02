#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 70;

int dayBan[MAX], choNgoi[MAX];
string mssv[MAX], hoLot[MAX], ten[MAX], ngaySinh[MAX], nganhHoc[MAX], queQuan[MAX];


int main() {
	ifstream file;
	file.open("SoDoLop.txt");

	if (!file.is_open()) {
		cout << "Khong the mo file!" << endl;
		return 1;
	}

	string line;
    int tongDay, tongCho;

    getline(file, line);

	file >> tongDay;
	file.ignore();
	file >> tongCho;
    file.ignore(); 

    getline(file, line);

	int i = 0;
	while (i < MAX && !file.eof()) {
		file >> dayBan[i];
		file.ignore();
		file >> choNgoi[i];
		file.ignore();
		getline(file, mssv[i], ',');
		getline(file, hoLot[i], ',');
		getline(file, ten[i], ',');
		getline(file, ngaySinh[i], ',');
		getline(file, nganhHoc[i], ',');
		getline(file, queQuan[i]);
	
		i++;
    }
	file.close();


	for (int i = 0; i < MAX; i++) {
		cout << "Day ban: " << dayBan[i] << endl;
		cout << "Cho ngoi: " << choNgoi[i] << endl;
		cout << "MSSV: " << mssv[i] << endl;
		cout << "Ho lot: " << hoLot[i] << endl;
		cout << "Ten: " << ten[i] << endl;
		cout << "Ngay sinh: " << ngaySinh[i] << endl;
		cout << "Nganh hoc: " << nganhHoc[i] << endl;
		cout << "Que quan: " << queQuan[i] << endl;

		cout << "-----------------------------------" << endl;
	}

	system("pause");
	return 0;
}