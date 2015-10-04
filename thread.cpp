// Example program
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <mutex>

using namespace std;
mutex mtx;

void print_block(int n, char c)
{
   // critical section (exclusive access to std::cout signaled by locking mtx):
  mtx.lock();
  for (int i=0; i<n; ++i) { cout << c; }
  cout << '\n';
  mtx.unlock();
}
int main()
{

  thread th1 (print_block,50,'*');
  thread th2 (print_block,50,'$');

  th1.join();
  th2.join();

  return 0;
}
