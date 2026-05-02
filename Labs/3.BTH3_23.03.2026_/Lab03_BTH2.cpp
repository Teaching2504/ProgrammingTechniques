#include<iostream>>
#include<string>

using namespace std;
const int MAX = 45;
struct SinhVien {
	string mssv;
	string hoTen;
	string diaChi;
	int namSinh;
	double toan;
	double van;
	double ngoaiNgu;


	void nhapSV() {
		cout << "Nhap mssv: ";
		getline(cin, mssv);
		cout << "Nhap ten sinh vien: ";
		getline(cin, hoTen);
		cout << "Nhap dia chi: ";
		getline(cin, diaChi);
		cout << "Nhap nam sinh: ";
		cin >> namSinh;
		cout << "Nhap diem toan: ";
		cin >> toan;
		cout << "Nhap diem van: ";
		cin >> van;
		cout << "Nhap diem Ngoai Ngu: ";
		cin >> ngoaiNgu;
		cin.ignore();

	}
	void xuatSV() {
		cout << mssv << " - " << hoTen << " - "
			<< diaChi << " - " << toan << " - "
			<< van << " - " << ngoaiNgu << " - "<< diemTrungBinh() <<" - "<<xepLoai()<< endl
			<< "-----------" << endl;
	}

	double diemTrungBinh() {
		return ((toan + van) * 2 + ngoaiNgu) / 5;
	}
	string xepLoai() {
		double d = diemTrungBinh();
		if (d >= 8)
			return "Gioi";
		else if (d >= 6.5)
			return "Kha";
		else if (d >= 5)
			return "Trung binh";
		else
			return "Duoi TB";

	}

};

struct LopHoc
{
	SinhVien dssv[MAX];
	int n;
	void nhapDSSV() {
		cout << "Nhap so luong sinh vien: ";
		cin >> n;//0<n<=45
		cin.ignore();
		for (int i = 0; i < n; i++)
			dssv[i].nhapSV();
	}
	void xuatTheoThuTu(int i) {
		//i tu 0 -> n-1
		dssv[i].xuatSV();
	}

	void xuatDSSV() {
		for (int i = 0; i < n; i++)
			dssv[i].xuatSV();
	}

};




int main() {
	LopHoc lop1;
	lop1.nhapDSSV();
	lop1.xuatDSSV();
	system("pause");
	return 0;
}