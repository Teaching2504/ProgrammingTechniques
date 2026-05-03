//Cho tap tin du lieu Sach.txt chua thong tin nhieu cuon sach. 
//Moi cuon sach bao gom: ten sach (String), ten tac gia (String), so trang (int), gia ban (double), 
//moi thong tin cach nhau bang dau phay. Thuc hien cac yeu cau sau:
//1. Tao mot mang chua toi da 30 cuon sach, sau do viet ham doc du lieu tu tap tin Sach.txt vao mang.
//2. Viet ham in ra cac cuon sach co gia tu x den y (x va y do nguoi dung nhap).
//3. Viet ham ghi ra tap tin Nguyen.txt cac cuon sach co ten tac gia chua chuoi Nguyen.

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

fstream fin;
ofstream fout;

//Khai báo cấu trúc sách
struct Sach
{
	string tenSach,tenTG;
	int soTrang;
	double giaBan;
};

//Tạo mảng chứa tối đa 30 quyển sách
const int MAX = 30;

//Viết hàm đọc dữ liệu từ tập tin Sach.txt
void docFile(Sach sach[], int& sl)
{
	fin.open("Sach.txt", ios::in);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			Sach s;
			//Đọc tên sách
			getline(fin, s.tenSach, ',');
			//Đọc tên tác giả
			getline(fin, s.tenTG, ',');
			//Đọc số trang
			fin >> s.soTrang;
			fin.ignore();
			//Đọc giá bán
			fin >> s.giaBan;
			//Inoge cho tên sách phía trên
			fin.ignore();
			sach[sl] = s;
			sl++;
		}
		fin.close();
	}
	else
		cout << "Khong mo duoc file!\n";
}


//Hàm in 1 cuốn sách
void xuat1Sach(Sach sach)
{
	cout << sach.tenSach << "," << sach.tenTG << "," 
		<< sach.soTrang << "," << sach.giaBan << endl;
}

//Xuất danh sách sách
void xuatDSSach(Sach sach[], int sl)
{
	for (int i = 0; i < sl; i++)
	{
		xuat1Sach(sach[i]);
	}
}
//In sách từ x đến y (x và y là do người dùng nhập)
void xuatSachXDenY(Sach sach[], int sl)
{
	int x, y;
	cout << "Nhap vi tri bat dau - x: ";
	cin >> x;
	cout << "Nhap vi tri ket thuc - y: ";
	cin >> y;
	if (x<0 || x >= y || y <= 0 || y>sl)
		cout << "Vi tri nhap khong hop le!\n";
	else
	{
		for (int i = x;i <= y;i++)
			xuat1Sach(sach[i]);
	}
}

//2. Viết hàm in ra file Nguyen.txt những cuốn sách tác giả có tên Nguyen
void ghiFile(Sach sach[], int sl)
{
	fout.open("Nguyen.txt");
	if (fout.is_open())
	{
		string s = "Nguyen";
		for (int i = 0; i < sl;i++)
		{
			if (sach[i].tenTG.find(s) != string::npos)
			{
				fout << sach[i].tenSach << "," << sach[i].tenTG << "," << sach[i].soTrang << "," << sach[i].giaBan << endl;
			}

		}

		fout.close();
		cout << "Da ghi vao file thanh cong!" << endl;
	}
	else
		cout << "Mo file ghi that bai!\n";
}

int main()
{
	Sach sach[MAX];
	int sl = 0;
	docFile(sach, sl);
	xuatDSSach(sach, sl);
	cout << "-------------------------\n";
	xuatSachXDenY(sach, sl);
	ghiFile(sach, sl);
	system("pause");
	return 0;
}