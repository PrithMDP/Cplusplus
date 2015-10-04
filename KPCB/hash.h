template <typename T>
class table
{
private:
	T* arr[10000];
	int size;
	int keyval(string key)
	{
		int value=0;
		for(int i=0;i<key.size();i++)
		{
			value+=key[i]*(i+1)*(i+1);
		}
		cout<<value<<" "<<size<<endl;
		return(value%size);
	}
public:
	table(int len)
	{
		size=len;
		for(int i=0;i<size;i++)
		{
			arr[i]=nullptr;
		}
	}
	bool set(string key, T* value)
	{
		arr[keyval(key)]=value;
		return true;
	}
	T* get(string key)
	{		 
		 return (arr[keyval(key)]);
	};

	void deleter(string key)	//cant use keyword delete in c++
	{
		arr[keyval(key)]=nullptr;
	}

	float load()
	{
		int counter=0;
		for(int i=0;i<size;i++)
		{
			if(arr[i]!=nullptr)
			{
				counter++;
				cout<<"inc\n";
			}
		}
		return counter/size;
	};

};