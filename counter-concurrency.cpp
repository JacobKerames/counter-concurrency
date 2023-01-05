/*
 * @file counter-concurrency.cpp
 * @author Jacob Kerames
 * @brief Demonstrates concurrency concepts in C++ by creating two threads that act as counters.
 * One thread counts up to 20 and the other counts down to 0. The code addresses performance issues
 * with concurrency, vulnerabilities exhibited with use of strings, and the security of data types.
 *
 */

#include <iostream>
#include <thread>
#include <atomic>
#include <string>
#include <mutex>

// global variables
std::atomic<int> counter1(0);  // use atomic integer for thread-safe incrementing
std::atomic<int> counter2(20);  // use atomic integer for thread-safe decrementing
std::mutex output_mutex;  // use mutex to synchronize output to the console

// function to increment counter1 to 20
void countUp() {
  while (counter1 < 20) {
    counter1++;  // increment counter
    std::lock_guard<std::mutex> guard(output_mutex);  // lock mutex to synchronize output
    std::cout << "Counter 1: " << counter1 << std::endl;  // output counter value
  }
}

// function to decrement counter2 to 0
void countDown() {
  while (counter2 > 0) {
    counter2--;  // decrement counter
    std::lock_guard<std::mutex> guard(output_mutex);  // lock mutex to synchronize output
    std::cout << "Counter 2: " << counter2 << std::endl;  // output counter value
  }
}

int main() {
  // create threads
  std::thread t1(countUp);
  std::thread t2(countDown);

  // wait for threads to finish
  t1.join();
  t2.join();

  return 0;
}
