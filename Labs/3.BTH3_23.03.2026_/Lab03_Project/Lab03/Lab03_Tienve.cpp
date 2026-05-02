#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int MAX_HANG = 7;
const int MAX_COT = 5;

int main() {
	string ds[MAX_HANG][MAX_COT];
	ifstream file("Data.txt");

	if (!file.is_open()) {
		cout << "Khong the mo file!" << endl;
		return 1;
	}

	int i = 0;
	while (!file.eof() && i < MAX_HANG) {

		getline(file, ds[i][0], ',');
		getline(file, ds[i][1], ',');
		getline(file, ds[i][2], ',');
		getline(file, ds[i][3], ',');
		getline(file, ds[i][4]);

		i++;
	}
	file.close();


	//In
	for (int j = 0; j < MAX_HANG; j++) {
		cout << "Vi tri: " << ds[j][0] << endl;
		cout << "So ao: " << ds[j][1] << endl;
		cout << "Ten: " << ds[j][2] << endl;
		cout << "CLB: " << ds[j][3] << endl;
		cout << "Nam sinh: " << ds[j][4] << endl;
		cout << endl;
	}

	system("pause");
	return 0;
}