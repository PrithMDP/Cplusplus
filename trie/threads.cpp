#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;
int accum=0;

// void square(int x)
// {
// 	int temp=x*x;
// 	mtx.lock();
// 	accum += temp;
// 	mtx.unlock();
// }

int is_printed;

void print(int i)
{
	while (true) {
		 mtx.lock();
		
			if (is_printed == i - 1) {
				cout<<i<<endl;
				++is_printed;
				 mtx.unlock();
				break;
			}

		 mtx.unlock();
	}
}

// int main(int argc, char const *argv[])
// {
// 	vector<thread> ths;

// 	for( int i=1;i<=20;i++)
// 	{
// 		ths.push_back(thread(&square,i));
// 	}

// 	for(auto& th : ths)
// 	{
// 		th.join();
// 	}
// 	cout<<"Accum = "<<accum<<endl;
// 	return 0;
// }

int  main(int argc, char const *argv[])
{
	vector<thread> ths;
	is_printed = 0;
	for(int i=1;i<=10;i++)
	{
		ths.push_back(thread(print,i));
	}
	for(auto& th: ths)
	{
		th.join();
	}
	return 0;
}