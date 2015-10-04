#include <iostream>
#include <climits>
#include <string>
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
		}
	}

	
	bool set(string key, T* value)	//check if there is something already set if that is the case then update the reference
	{
		int val=value_calc(key);	//calculate key, if empty

		if(arr[val].string=="")
		{
			arr[val].key=key;
			arr[val].ref=value;
		}
		else
		{
			for(int i=0;i<size;i++)
			{
				if(arr[val].string=="")
				{
					arr[val].key=key;
					arr[val].ref=value;
					return true;
				}
				val+=i*i;
				val=val%size;
			}
			return false;
		}

	};


	T* get(string key)
	{		 
		int value=value_calc(key);
		if(arr[value].string == key)
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

int main ()
{
	table<int> t1(1);
	

	return  0;	
}