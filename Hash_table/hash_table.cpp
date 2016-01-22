#include <iostream>
#include <climits>
#include <string>
#include <assert.h>
using namespace std;


/*
 This here is the implementation of a hash table. Collision resolution method is quadratic probing.
 It maps string keys to any reference.
 */

//QUESTION: should for loop go to <i or to <=i?

//templated struct to be used as private member of class table
template <typename T>
struct item
{
    string key;	//key for the item
    T* ref;
};

//templated class uses templated struct

template <typename T>
class table
{
private:
    item<T> arr[100000];
    int size;
    //Hash function
    int value_calc(string key)
    {
        int value=0;
        for(int i=0;i<key.size();i++)
        {
            value+=key[i]*(i+1)*(i+1);
        }
        value=value%(size);	//making sure it wraps around
        return value;
    }
    
    
    
public:
    table(int size_in)	//constructor for the table
    {
        size=size_in;	//resetting size
        for(int i=0;i<size;i++)	//initializing the object refs to
        {
            arr[i].ref=nullptr;
            arr[i].key="";
        }
    }
    
    
    bool set(string key, T* value)	//check if there is something already set if that is the case then update the reference
    {
        int val=value_calc(key);	//calculate key, if empty // if key exists then update
        
        if(arr[val].key=="")    //empty spot is denoted by empty key
        {
            arr[val].key=key;
            arr[val].ref=value;
            return true;
        }
        if(load()==1)       //if table is full
        {
            for(int i=0;i<size;i++)
            {
                if(arr[val].key==key)		//if table is full look for key
                {
                    arr[val].key=key;
                    arr[val].ref=value;
                    return true;
                }
                val+=i*i;
                val=val%size;
            }
            cout<<"table is full\n";
            return false;	//return false if table is full and key is absent
        }
        else		//check when load ==1 and key exists and to be replaced and when load ==1 and key isnt present
        {
            for(int i=0;i<size;i++)
            {
                if(arr[val].key==key)   //looking if it exists
                {
                    arr[val].key=key;
                    arr[val].ref=value;
                    return true;
                }
                val+=i*i;
                val=val%size;
            }
            //reaches here if doesnt exist, so find blank spot
            for(int i=0;i<size;i++)
            {
                if(arr[val].key=="")   //looking if it exists
                {
                    arr[val].key=key;
                    arr[val].ref=value;
                    return true;
                }
                val+=i*i;
                val=val%size;
            }

            return false;      //cant set in table
        }
        
    };
    
    
    T* get(string key)
    {
        int value=value_calc(key);
        if(arr[value].key == key)
        {
            return arr[value].ref; 	//return the reference
        }
        else
        {
            for(int i=0;i<size;i++)
            {
                if(arr[value].key==key)
                {
                    return arr[value].ref;
                }
                value+=i*i;
                value=value%size;
            }
            return nullptr;	//not found -> return null ptr
        }
        
    };
    
    
    
    T* deleter(string key)	//cant use keyword delete in c++
    {
        int value=value_calc(key);
        if(arr[value].string == key)
        {
            T* ptr=arr[value].ref;
            arr[value].ref=nullptr;
            arr[value].key="";
            return ptr;	//return pointer and set string to empty string
        }
        else
        {
            for(int i=0;i<size;i++)	//i<=?
            {
                if(arr[value].key==key)
                {
                    T* ptr=arr[value].ref;
                    arr[value].ref=nullptr;
                    arr[value].key="";
                    return ptr;
                }
                value+=i*i;
                value=value%size;
            }
            return nullptr;	//not found
        }
    };
    
    
    float load()	//count non nullpointers and / by size
    {
        int counter=0;
        for(int i=0;i<size;i++)
        {
            if(arr[i].ref!=nullptr)
            {
                counter++;
            }
        }
        return counter/size;
    };
};//End of class declaration


void genrandomstring(string &a);

int main ()
{
    table<int> t1(100000);
    string str;
    str.resize (12);    //resizing to make it 12 chars long

    /*
    int e=23;
    int *r=&e;
    int yy=55;
    int *u=&yy;
    cout<<t1.set("this",r)<<endl;
    cout<<*(t1.get("this"))<<endl;
    
    cout<<t1.set("this",u)<<endl;
    cout<<*(t1.get("this"))<<endl;
    */

    for( int i=0;i<100;i++) //100 test simulations
    {
        genrandomstring(str); //generating the random string 

        int num=rand()%10000;
        int *ref=&num;

        t1.set(str,ref);

    }

    
    return  0;	
}

void genrandomstring(string &a)
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < a.length(); ++i) {
        a[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
}
