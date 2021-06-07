#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	string filename = "opdataterformat.txt";
	//string nama1 = "Buku";
	string nama1 = "Buku yang ajaib";
	double harga1 = 1500.5677770;

	ofstream ofs(filename);
	if (ofs.is_open())
	{
		ofs << left << setw(30) << nama1
			<< right << setprecision(7) << setw(30) << harga1
			<< endl;
		ofs.close();
	}

	string nama2;
	double harga2;
	ifstream ifs(filename);
	if (ifs.is_open())
	{
		ifs >> nama2 >> harga2;
	}

	cout << left << setw(30) << "Nama produk"
		 << right << setw(30) << "Harga"
		 << endl;

	cout << left << setw(30) << nama2
		 << right << setprecision(7) << setw(30) << harga2
		 << endl;
}
