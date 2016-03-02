#include <iostream>
#include <vector> 
#include <thread>
#include <mutex>

using namespace std;

mutex mtxprint;

vector<mutex> mtx(101); //vector of mutexes(ices)

void printhello(int i)
{

	int z = 0;
	//check if mutex is unlocked
	mtx[i].lock();
	while(z<1000)
	{
		mtxprint.lock();
		cout << "hello " << z << " from thread " << i << endl;
		mtxprint.unlock();
		z++;
	}
	//unlock the mutex for i 
	mtx[i+1].unlock();
}

int main(int argc, char* argv[])
{

for(int i =0;i<100;i++)
{
	mtx[i].lock();
}
mtx[0].unlock();

vector<thread> th;

for(int i =0;i<100;i++)
{
  th.push_back(thread(printhello,i));
}

for(auto & t:th)
{
  t.join();
}

return 0;


}
