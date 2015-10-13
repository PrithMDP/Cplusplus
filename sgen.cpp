// Example program
#include <iostream>
#include <string>
using namespace std;

int main()
{
  const string first= "hge";
  char arr[]={'a','b','c','d','e','f','g','h'}; //array of chars 
 
  for(int i=0;i<8;i++)
  {
      for(int j=0;j<8;j++)
      {
          for(int k=0;k<8;k++)
          {
             string test="";
             test+=arr[i];
             test+=arr[j];
             test+=arr[k];
             cout<<test<<endl;
             if(test == first)
             {
                 cout<<"match"<<endl;
                 i=j=k=8; //exit the loop
             }
          }
      }      
  }

  
  
}
