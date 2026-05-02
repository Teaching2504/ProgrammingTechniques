#include<iostream>
using namespace std;

//Bài 01 - a - Viết đệ quy tính tổng các số nguyên dương từ 1 đến n
int tongA(int n)
{
	if (n == 1)
		return 1;
	return n + tongA(n - 1);
}

//Bài 01 - b - Viết đệ quy tính tổng bình phương từ 1 -> n
int tongB(int n)
{
	if (n == 1)
		return 1;
	return n * n + tongB(n - 1);
}

//Bài 01 - c - 1 + 1/3 + 1/5 + .. + 1/n (n là số nguyên dương và số lẻ)
double tongC(double n)
{
	if (n == 1)
		return 1;
	return 1 / n + tongC(n - 2);
}

//Bài 01 - d - S4 = 1! + 2! + 3! +... + n! (n là số nguyên dương)
//Viết hàm tính giai thừa
long giaiThua(long n)
{
	if (n == 1)
		return 1;
	return n * giaiThua(n - 1);
}
//Viết hàm tính tổng S4
long tongD(long n)
{
	if (n == 1)
		return 1;
	return giaiThua(n) + tongD(n - 1);
}

//Bai 02 - Viết hàm đệ qui tính giá trị Fibonacci của một số nguyên không âm. x=0 => F = 0 hoặc x = 1 => F=1 F = F(n-1) + F(n-2) nếu n>1
long fibonnaci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	return fibonnaci(n - 1) + fibonnaci(n - 2);
}

//Bài 03 - Viết hàm đệ qui tính giá trị của x mũ n với x, n là số nguyên. n=0, n<0, n>0
double hamSoMu(int x, int n)
{
	if (n == 0)
		return 1;
	else if (n < 0)
		return 1.0 / hamSoMu(x, -n);
	return x * hamSoMu(x, n - 1);
}

//Bài 04 - Viết hàm đệ qui đếm số chữ số của một số nguyên không âm.
int demSoChuSo(int n)
{
	if (n < 10)
		return 1;
	return 1 + demSoChuSo(n / 10);
}
//Bài 05 - Viết hàm đệ qui tính số đảo ngược của một số nguyên không âm.
int soDaoNguoc(int n, int kq =0)
{
	if (n==0)
		return kq;
	return soDaoNguoc(n / 10, 10 * kq + n % 10);
}
//Bài 06 - Viết hàm đệ qui tính tổng các chữ số chẵn/lẻ của một số nguyên không âm.
//Tổng chẵn
int tongChuSoChan(int n)
{
	if (n < 10)
	{
		if (n % 2 == 0)
			return n;
		return 0;
	}
	else
	{
		if (n % 2 == 0)
			return n % 10 + tongChuSoChan(n / 10);
		return tongChuSoChan(n / 10);
	}
}
//Tổng lẻ
int tongChuSoLe(int n)
{
	if (n < 10)
	{
		if (n % 2 != 0)
			return n;
		return 0;
	}
	else
	{
		if (n % 2 != 0)
			return n % 10 + tongChuSoLe(n / 10);
		return tongChuSoLe(n / 10);
	}
}

//Bài 07 - Chuyển thập phân sang nhị phân n=0 =) chuyển =0
int chuyen10Sang2(int n)
{
	if (n == 0)
		return 0;
	return chuyen10Sang2(n / 2) * 10 + n % 2;
}

//Bài 08 - Chuyển từ hệ nhị phân sang hệ thập phân
int chuyen2Sang10(int n)
{
	if (n == 0)
		return 0;
	return chuyen2Sang10(n / 10) * 2 + n % 10;
}

//Bài 09 - Ước chung lớn nhất của 2 số nguyên
int UCLN(int a, int b)
{
	if (a == b)
		return a;
	if (a > b)
		return UCLN(a - b, b);
	return UCLN(a, b - a);
}

//Bài 10 - Viết hàm đệ qui tính tổng các giá trị của một mảng 1 chiều lưu trữ số nguyên.
int tongMang(int a[], int n)
{
	if (n == 1)
		return a[0];
	return a[n-1] + tongMang(a, n - 1);
}

//Bài 11 - 12.Viết hàm đệ qui tìm giá trị nhỏ nhất của một mảng 1 chiều lưu trữ số nguyên.
int timNhoNhatMang(int a[], int n)
{
	if (n == 1)
		return a[0];
	int min = timNhoNhatMang(a, n - 1);
	return (min < a[n - 1] ? min : a[n - 1]);
}
int main() {
	int n;
	cout << "Nhap n (So le test Bai 01 - Bai 02): ";
	cin >> n;
	//Bài 01 - a
	cout << "Tong tu 1 -> " << n << " la: " << tongA(n) << endl;
	//Bài 01 - b
	cout << "Tong binh phuong tu 1 -> " << n << " la: " << tongB(n) << endl;
	//Bài 01 - c
	cout << "Tong S3 la: " << tongC(n) << endl;
	//Bài 01 - d
	cout << "Tong S4 la: " << tongD(n) << endl;
	//Bài 02 - Tổng fibonnacy
	cout << "Tong fibonnacy la: " << fibonnaci(n) << endl;
	int m, x;
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap so mu m: ";
	cin >> m;
	//Bai 03 - TÍnh số mũ
	cout << x << "^" << m << " = " << hamSoMu(x, m) << endl;
	//Bai 04 - Dem so chu soo
	int chuSo;
	cout << "Nhap chu so can dem: ";
	cin >> chuSo;
	cout << "So chu so cua " << chuSo << " la: "<<demSoChuSo(chuSo) << endl;
	//Bai 05 - So dao nguoc
	cout << "So dao nguoc cua " << chuSo << " la: " << soDaoNguoc(chuSo) << endl;
	//Bài 06.1 Tong chu so chan
	cout << "Tong chu so chan cua " << chuSo << " la: " << tongChuSoChan(chuSo) << endl;
	//Bài 06.2 Tong chữ số lẻ
	cout << "Tong chu so le cua " << chuSo << " la: " << tongChuSoLe(chuSo) << endl;
	//Bai 07 - Chuyen 10 sang2
	cout << "So nhi phan cua 10 la: " << chuyen10Sang2(10) << endl;
	//Bai 08 - Chuyen 2 sang 10
	cout << "So thap phan cua 1010 la: " << chuyen2Sang10(1010) << endl;
	//Bài 09 - Ước chung lớn nhất
	cout << "Uoc chung lon nhat cua 3 va 6 la: UCLN (3, 6) = " << UCLN(3, 6) << endl;
	int a[4] = {2, 5, 7, 8};
	cout << "Tong so luong phan tu trong mang a la: " << tongMang(a, 4) << endl;
	//Bài 11 - Tìm giá trị nhỏ nhất trong mảng
	cout << "Gia tri nho nhat trong mang a la: " << timNhoNhatMang(a, 4) << endl;
	return 0;
}