#include <iostream>
#include <fstream>
#include <string>
#define MAX(A,B)((A>B)? A:B)
using namespace std;

int main(int argc, char* argv[])
{
  cout<<"starting program\n";
  ifstream filename;
  filename.open(argv[1]);
  string word;
    while(getline(filename,word))
      {
	cout<<word<<endl;
      }
    cout<<"READING FILE AGAIN\n";
      filename.clear();
    filename.seekg(0, filename.beg);
    while(getline(filename,word))
      {
	cout<<word<<endl;
      }
    int g = MAX(15,10);
    cout<<g<<endl;
    return 0;
}
