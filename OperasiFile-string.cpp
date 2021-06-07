#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string str1 = "Halo DUnia!";
	string str2;

	ofstream ofs("opstring.txt");
	if (ofs.is_open())
	{
		ofs << str1;
		//cout << str1; //mirip
		ofs.close();
	}

	ifstream ifs("opstring.txt");
	if (ifs.is_open())
	{
		ifs >> str2;
		//cin >> str2; //mirip

		cout << str2 << endl;
		// halo
		// halo dunia!

		// mengatur posisi stream
		ifs.seekg(ios::beg);
		// ios::beg // awal
		// ios::cur // saat ini
		// ios::end // akhir
		getline(ifs, str2);
		cout << str2;
	}
}
