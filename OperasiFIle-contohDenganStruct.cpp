// 1. struct ke file (output)
// 2. struktur isi file terformat
// 3. lebih dari tiga data
// 4. terdapat inputan lebih dari satu kata
// 5. struct dari file (input)
// 6. asumsi jumlah data tidak diketahui
// 7. tampilkan data

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

struct dataB
{
	char nama[30];
	double harga;
	int qty;
};
string filename = "contohcoding.txt";

string replacespasi(string str)
{
	for (int i = 0; str[i]; i++)
	{ // Buku_yang_ajaib
		if (str[i] == ' ')
		{
			str.replace(i, 1, 1, '_');
		}
	}
	return str;
}

string replaceunderscore(string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '_')
		{
			str.replace(i, 1, 1, ' ');
		}
	}
	return str;
}

int main()
{

	dataB barang[4] = {{"Buku yang ajaib2", 123.400, 1},
					   {"pintu kemana saja2", 9999.99999, 0},
					   {"Mjolnir2", 1500.982, 3},
					   {"PC Sungjin2", 500000, 2}};

	dataB temp[100];

	for (int i = 0; i < 4; i++)
	{
		string str = barang[i].nama;
		strcpy(barang[i].nama, replacespasi(str).c_str());
	}

	// output/tulis data
	ofstream ofs(filename, ios::app);
	if (ofs.is_open())
	{
		for (int i = 0; i < 4; i++)
		{
			ofs << left << setw(35) << barang[i].nama
				<< right << setprecision(7)
				<< setw(30) << barang[i].harga
				<< setw(5) << barang[i].qty
				<< endl;
		}
		ofs.close();
	}

	// input/baca data
	ifstream ifs(filename);
	int banyak_data = 0;
	if (ifs.is_open())
	{
		int i = banyak_data; //untuk iterasi
		while (!ifs.eof())
		{
			ifs >> temp[i].nama >> temp[i].harga >> temp[i].qty;
			i++;
		}
		// 5
		banyak_data += i - 1;
		ifs.close();
	}

	cout << left << setw(35) << "Nama Barang"
		 << right << setprecision(7) << setw(30) << "Harga"
		 << setw(5) << "QTY" << endl;

	for (int i = 0; i < banyak_data; i++)
	{
		cout << left << setw(35) << replaceunderscore(temp[i].nama)
			 << right << setprecision(7)
			 << setw(30) << temp[i].harga
			 << setw(5) << temp[i].qty << endl;
	}
}
