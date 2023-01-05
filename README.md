# Counter Concurrency

This program demonstrates concurrency concepts in C++ by creating two threads that act as counters. One thread counts up to 20 and the other counts down to 0. The code addresses performance issues with concurrency, vulnerabilities exhibited with use of strings, and the security of data types.

## Dependencies

This program requires the following dependencies:

  * iostream
  * thread
  * atomic
  * string
  * mutex
  
## Global Variables

Two atomic integers, `counter1` and `counter2`, are used as the counters in this program. They are initialized to 0 and 20, respectively. An output mutex, `output_mutex`, is also defined to synchronize output to the console.

## Functions

Two functions, `countUp` and `countDown`, are defined to increment and decrement the counters, respectively. Both functions use a mutex lock to synchronize output to the console.

## Threads

Two threads, `t1` and `t2`, are created to run the `countUp` and `countDown` functions, respectively. The main thread waits for both threads to finish before exiting.
