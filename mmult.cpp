#include<iostream>
#include<vector>
#include<thread>
using namespace std;

vector<vector<int>> mat(4);
vector<vector<int>> result = mat;


//takes a row multiplies by entire matrix
void rowmult(int a)
{
  for(int i = a;j<mat[a].size();i++)
  {
    for(int j=0; j<mat[a].size();j++)
    {
      cout << mat[i][j] << endl;
    }
  }
}
int main(int argc, char*argv[])
{
  
 // cout << mat.size() << endl;
  for(int i =0 ; i< mat.size(); i++)
    {
      mat[i].reserve(mat.size());
    }
  for(int i =0 ; i< mat.size(); i++)
    {
      for(int j = 0;j<mat.size();j++)
	   {
	     mat[i][j]=(i+i*j);
	   }
    }

  for(int i =0 ; i< mat.size(); i++)
    {
      for(int j = 0;j<mat.size();j++)
     {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  //cout << mat[1].size() << endl;
  //cout << mat.size() << endl;
   // / cout << "here\n";
  return 0;
}
