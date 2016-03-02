#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
using namespace std;

mutex mtx;
void loop_a_lot() {

  // to prevent the compiler from performing static analysis and unrolling the
  // loop out
  int loop_roller = NUM_CPUS;
  for (int i = 0; i < 1e9; ++i) {
    loop_roller = loop_roller << i;
  }
    
  mtx.lock();
  cout << loop_roller << endl;
  mtx.unlock();
}

int main() {

  // create NUM_CPUS threads
  vector<thread> threads;
  for (int i = 0; i < NUM_CPUS; ++i) {
    threads.emplace_back(loop_a_lot);
  }

  // join threads
  for (auto& th : threads) {
    th.join();
  }

  return 0;
}
