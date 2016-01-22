// Example program
#include <iostream>
#include <string>
using namespace std;

bool checker(string s1,string s2)
{
  // enforce lengths to be equal
  // POTS OPTS
  bool diff = 0;
  for(int i =0;i<s1.length();i++)   
    {
      if(s1[i]!=s2[i])    //different
        {
	  if(diff)
            {
	      return false;
            }
	  diff = 1;
	  if(s1[i] == s2[i+1] && s2[i] == s1[i+1])
            {
	      i+=2;
            }
	  else
            {
	      return false;
            }
        }
    }
  return true;
}

bool checker2(string &s1,string &s2)
{
  // enforce lengths to be equal                                                                                  
  // POTS OPTS                                                                                                    
  bool diff = 0;
  for(int i =0;i<s1.length();i++)
    {
      if(s1[i]!=s2[i])    //different                                                                             
        {
          if(diff)
            {
              return false;
            }
          diff = 1;
          if(s1[i] == s2[i+1] && s2[i] == s1[i+1])
            {
              i+=2;
            }
          else
            {
              return false;
            }
        }
    }
  return true;
}
int main()
{
  int i =0;
  string a = "pots";
  string b = "post";
  while(i<10000000)
    {
      #ifdef var
      checker(a,b);
      #endif
     
      #ifdef n_var
      checker("pots","post");
      #endif
      
      #ifdef r_eff
      checker2(a,b);
      #endif
      i++;
    }
}
