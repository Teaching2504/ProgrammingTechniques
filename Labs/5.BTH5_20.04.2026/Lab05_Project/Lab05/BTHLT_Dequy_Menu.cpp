#include<iostream>
using namespace std;
//Bai 01 - Tìm chữ số lớn nhất trong số nguyên N 
//VD 123 => lớn nhất là 3
int timChuSoLonNhat(int n)
{
	if (n < 10)
		return n;
	int max = timChuSoLonNhat(n % 10);
	return (max > timChuSoLonNhat(n / 10) ? max : timChuSoLonNhat(n / 10));
}
//Bài 02 - Ao có diện tích A m vuông, thả xuống B mét vuông bèo, sau 1 ngày thì bèo sẽ gấp 2 lần, tính số ngày bèo đầy bể
int ngay(int a, int b)
{
	if (b >= a)
		return 0;
	return 1 + ngay(a, b * 2);
}

//Bài 03 - Giếng sau H mét, một con ốc bò lên từ đáy giếng, buổi sáng ốc bò lên N mét, tối ốc tụt xuống M mét, tính số ngày ốc sên bò lên miệng giếng
int ngay2(int h, int n, int m)
{
	if (n >= h)
		return 1;
	return 1 + ngay2(h - (n - m), n, m);
}

//Bài 04 - Tìm ký tự đầu tiên của số nguyên
int timKyTuDau(int n)
{
	if (n < 10)
		return n;
	return timKyTuDau(n / 10);
}

//Bài 05 - In ra hình vuông có cạnh H bằng ký tự C
void inHinhVuong(int h, char c)
{
	static int canh = h;
	if (h == 0)
		return;
	for (int i = 0; i < canh;i++)
		cout << c;
	cout << endl;
	inHinhVuong(h - 1, c);
	return;

}
//Bài 06 - In ra tam giác vuông cân cạnh H bằng ký tự c
void inTamGiacVuongCan(int h, char c)
{
	if (h == 0)
		return;
	inTamGiacVuongCan(h - 1, c);
	for (int i = 1;i <= h;i++)
		cout << c;
	cout << endl;
}

//Bài 07 - Đếm số ký số X trong số nguyên N VD: x=2 n = 42126 => kq = 2
int demSoKySo(int n, int x)
{
	if (n == 0)
	{
		if (n == x)
			return 1;
		return 0;
	}
	int dem = (n%10 == x ? 1 : 0);
	return dem + demSoKySo(n / 10, x);
}
//Bài 08 - Viết hàm đệ quy tính tổng số dương trong mảng có n phần tử số nguyên
int tongSoDuong(int a[], int n)
{
	if (n == 0)
	{
		if (a[1] > 0)
			return a[1];
		return 0;
	}
		int tong = (a[n-1] > 0 ? a[n-1] : 0);
	return tong + tongSoDuong(a, n - 1);
}
//Bài 09 - Kiểm tra xem mảng a có chứa số lẻ không, nếu có thì trả ra true
bool ktSoLe(int a[], int n)
{
	if (n == 0)
	{
		if (a[1] % 2 != 0)
			return true;
		return false;
	}
	else
	{
		if (a[n - 1] % 2 != 0)
			return true;
		return ktSoLe(a, n - 1);
	}
}
//Hàm menu
void menu(long& luachon)
{
	do
	{
		cout << "----------------MENU----------------\n"
			"1. Tim chu so lon nhat trong so nguyen N\n"
			"2. Bai toan ao ca\n"
			"3. Bai toan gieng va con oc sen\n"
			"4. Tim ky tu dau tien cua so nguyen N\n"
			"5. In ra hinh vuong co canh la H bang ky tu C\n"\
			"6. In ra hinh tam giac vuong can co canh la H bang ky tu C\n"
			"7. Dem so ky so X trong so nguyen N\n"
			"8. Viet ham de quy tinh tong so duong trong mang co n phan tu so nguyen\n"
			"9. Kiem tra mang a co chua so le khong, co thi tra ve true\n"
			"10. Thoat\n";
		cout << "------------------------------------\n";
		cout << "Moi ban chon yeu cau!\n";
		cin >> luachon;
		if (luachon >= 1 && luachon <= 10)
			break;
		else
			cout << "Lua chon khong hop le!\n";


	} while (true);
}

int main()
{
	long luachon = 0;
	do
	{
		system("cls");
		menu(luachon);
		switch (luachon) {
			case 1:
			{
				cout << "1. Tim chu so lon nhat trong so nguyen N\n";
				int n;
				cout << "Nhap n: ";
				cin >> n;
				cout << "Chu so lon nhat trong " << n << " la: " << timChuSoLonNhat(n) << endl;
				break;
			}
			case 2:
			{
				cout << "2. Bai toan ao ca\n";
				int a, b;
				cout << "Nhap vao a va b: ";
				cin >> a >> b;
				cout << "So ngay de beo day ao la: " << ngay(a, b) << endl;
				break;
			}
			case 3:
			{
				cout << "3. Bai toan gieng va con oc sen\n";
				int h, n, m;
				cout << "Nhap chieu cao gieng: "; cin >> h;
				cout << "Sang oc bo len n met: "; cin >> n;
				cout << "Toi oc tut xuong m met (m<n): "; cin >> m;
				cout << "So ngay oc bo len tren mieng gieng: " << ngay2(h, n, m) << endl;
				break;
			}
			case 4:
			{
				cout << "4. Tim ky tu dau tien cua so nguyen N\n";
				int n;
				cout << "Nhap so n tim ky tu dau: ";
				cin >> n;
				cout << "Ky tu dau tien cua so nguyen n la: " << timKyTuDau(n) << endl;
				break;
			}
			case 5:
			{
				cout << "5. In ra hinh vuong co canh la H bang ky tu C\n";
				int h;
				char c;
				cout << "Nhap h: "; cin >> h;
				cout << "Nhap c: "; cin >> c;
				cout << "Hinh vuong co canh la H bang ky tu C la: " << endl;
				inHinhVuong(h, c);
				break;
			}
			case 6:
			{
				cout << "6. In ra hinh tam giac vuong can co canh la H bang ky tu C\n";
				int h;
				char c;
				cout << "Nhap h: "; cin >> h;
				cout << "Nhap c: "; cin >> c;
				cout << "Hinh tam giac vuong can co canh H va ky tu C la: " << endl;
				inTamGiacVuongCan(h, c);
				break;
			}
			case 7: 
			{
				cout << "7. Dem so ky so X trong so nguyen N\n";
				int x, n;
				cout << "Nhap vao n va x: ";
				cin >> n >> x;
				cout << "So ky so " << x << " trong " << n << " la: " << demSoKySo(n, x) << endl;
				break;
			}
			case 8:
			{
				cout << "8. Viet ham de quy tinh tong so duong trong mang co n phan tu so nguyen\n";
				int a[5] = {1, -3, 5, -9, 0};
				cout << "Tong so duong trong mang a la: " << tongSoDuong(a, 5) << endl;
				break;
			}
			case 9:
			{
				cout << "9. Kiem tra mang a co chua so le khong, co thi tra ve true\n";
				int a[5] = { 4, 8, 6, 8, 0 };
				if (ktSoLe(a, 5) == true)
					cout << "Mang a co chua so le!" << endl;
				else
					cout << "Mang a khong chua so le!" << endl;
				break;
			}
			case 10:
			{
				cout << "Cam on ban da su dung chuong trinh!\n";
				break;
			}
		}
		system("pause");
	} while (luachon!=10);

	return 0;
}