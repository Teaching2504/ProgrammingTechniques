#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream fin;
ofstream fout;
struct SoDoLop
{ 
	int soDay, soCho;
	string mssv, hoLot, ten, ngaySinh, nganhHoc, queQuan;

};

//Tạo mảng chứa tối đa 100 sinh viên
const int MAX = 100;

//Viết hàm đọc dữ liệu từ file SoDoLop.txt
void docFile(SoDoLop sodo[], int& sl)
{
	fin.open("SoDoLop.txt", ios::in);
	if (fin.is_open()) {
		while (!fin.eof())
		{
			SoDoLop s;
			fin >> s.soDay;
			fin.ignore();
			fin >> s.soCho;
			fin.ignore();
			getline(fin, s.mssv, ',');
			getline(fin, s.hoLot, ',');
			getline(fin, s.ten, ',');
			getline(fin, s.ngaySinh, ',');
			getline(fin, s.nganhHoc, ',');
			getline(fin, s.queQuan);

			sodo[sl] = s;
			sl++;
		}
		fin.close();
	}
	else
		cout << "Khong mo duoc file!\n";
}

//Xuất 1 bạn trong sơ đồ lớp
void xuat1HS(SoDoLop s)
{
	cout << s.soDay << "," << s.soCho << "," << s.mssv << ","
		<< s.hoLot << "," << s.ten << "," << s.ngaySinh << ","
		<< s.nganhHoc << "," << s.queQuan << endl;
}

//Xuất sơ đồ lớp
void xuatSoDo(SoDoLop sodo[], int sl)
{
	for (int i = 0;i < sl;i++)
		xuat1HS(sodo[i]);
}

//Xuất sơ đồ lớp vừa đọc ra file mới
void xuatFile(SoDoLop s[], int sl)
{
	fout.open("SoDoLopXuatFile.txt", ios::out);
	if (fout.is_open())
	{
		for(int i=0;i<sl;i++)
			fout << s[i].soDay << "," << s[i].soCho << "," << s[i].mssv << ","
			<< s[i].hoLot << "," << s[i].ten << "," << s[i].ngaySinh << ","
			<< s[i].nganhHoc << "," << s[i].queQuan << endl;

		fout.close();
		cout << "Ghi file thanh cong!\n";
	}
	else
		cout << "Ghi file khong thanh cong!\n";
}

int main() {
	SoDoLop sodo[MAX];
	int sl = 0;
	docFile(sodo, sl);
	xuatSoDo(sodo, sl);
	xuatFile(sodo, sl);
	system("pause");
	return 0;
}