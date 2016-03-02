#include<iostream>
#include<vector>
#include<thread>

using namespace std;
mutex mtx;


vector<bool> before;
void printhello(int j)
{
	int z = 0;
	if(j==0)
	{
	for(int p =0;p<1000; p++)
	{
		mtx.lock();
		cout<<"Hello "<<p<<" from "<<j<<endl;
		mtx.unlock();	
	}
	before[0] = 1;
	}
	else
	{
	while(before[j-1] != 1 ) {}
	while(z<1000)
	{
		mtx.lock();
		cout<<"Hello "<<z<<" from " <<j <<"\n";
		mtx.unlock();
		z++;
	}
	}
	before[j] = 1;
}

int main(int argc,char * argv[])
{
	for(int i =0;i < 100; i++)
	{
		before.push_back(false);
	}
	//before[0] = 1;
	#ifdef threadzzzzz
	vector<thread> th;
	for(int i =0;i<100;i++)
	{
		th.push_back(thread(printhello,i));
	}
	for(auto & t:th)
	{
	t.join();
	}
	#else
	for(int i =0 ;i < 100000; i++)
	{
		cout <<"Hello\n";
	}
	#endif
}
