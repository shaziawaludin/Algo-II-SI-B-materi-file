#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

	string filename = "opmultipleline-string.txt";
	ofstream ofs(filename);

	if (ofs.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			ofs << "ini baris ke-" << i << endl;
		}
		ofs.close();
	}

	ifstream ifs(filename);
	if (ifs.is_open())
	{
		string str;
		int n = 3; // line yang dicari
		int i = 0; // iterasi
		while (getline(ifs, str) && i < n)
		{
			i++;
		}
		cout << str << endl;
	}
}
