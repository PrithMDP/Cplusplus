// This program takes an input file and appends #ifdef DEBUG before and #endif after every "std::cout" if finds
//will first attempt with I/O redirection and then file handling
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char ** argv)
{
	string line; 
	int line_num=1;
	while(getline(cin,line))
	{
		cout<<"here\n";
		cout<<line<<endl;
		size_t found = line.find("cout");
		if(found!=string::npos)
		{
			cout<<"found a cout at line "<<line_num<<endl;
		}
	line_num++;
	}
	
}
