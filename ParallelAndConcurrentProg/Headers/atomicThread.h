#ifndef ATOMIC_THREAD_H
#define ATOMIC_THREAD_H

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>


std::atomic<unsigned int> mutexVar(0);

void threadWork5(unsigned int timeVar = 500) {
	std::cout << "Thread work starts with id of " << std::this_thread::get_id() << std::endl;
	for (int i = 0; i < 5000000; i++) {
		mutexVar++;
	}


	std::cout << "Thread 1 work completed with id of " << std::this_thread::get_id() << std::endl;
}



int main_5() {
	std::cout << "Main thread starts with the id of " << std::this_thread::get_id() << std::endl;

	std::cout << "Calling the threads for work\n";

	std::thread th1(threadWork5, 600);
	std::thread th2(threadWork5, 900);

	th1.join();
	th2.join();

	std::cout << "The value is = " << mutexVar << std::endl;
	std::cout << "Main thread completed with id of " << std::this_thread::get_id() << std::endl;

	return 0;
}

#endif // !MUTEX_THREAD_H