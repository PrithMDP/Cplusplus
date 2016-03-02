#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	fstream f1;
	fstream f2;
	f1.open("a.txt");
	f2.open("b.txt");
	string line_1 = "";
	string line_2 = "";
	getline(f1,line_1);
	getline(f2,line_2);

	cout << line_1 << " file_2 " << line_2 << endl;
}