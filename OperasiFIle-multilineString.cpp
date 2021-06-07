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
			ofs << "ini baris ke-" << i + 1 << endl;
		}
		ofs.close();
	}

	ifstream ifs(filename);
	if (ifs.is_open())
	{
		string str;

		// Baca per baris
		while (getline(ifs, str))
		{
			cout << str << endl;
		}

		// baca per kata
		//while(ifs >> str){
		//	cout << str << endl;
		//}
	}
}
