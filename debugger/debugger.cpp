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
		//if you find a semi colon and in it if you find a cout
		size_t sem_found=line.find(";");

		if(sem_found!=string::npos)
		{
			size_t found = line.find("cout");
			if(found!=string::npos)	//found a cout
			{
				cout<<"#ifdef DEBUG"<<endl;
				cout<<line<<endl;
				cout<<"#endif"<<endl;
			}
			else
			{
				cout<<line<<endl;
			}
		}
		else
		{
			cout<<line<<endl;
		}
	line_num++;
	}
	
}
