#ifndef MUTEX_THREAD_H
#define MUTEX_THREAD_H

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>


std::mutex mutexVar;

unsigned int tmpVar = 0;

void threadWork4(unsigned int timeVar = 500) {
	std::cout << "Thread 1 work starts with id of " << std::this_thread::get_id() << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << "I am reading the data and trying to modify i am in " << timeVar << " gap\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(timeVar));
		mutexVar.lock();
		tmpVar++;
		mutexVar.unlock();
	}
		

	std::cout << "Thread 1 work completed with id of " << std::this_thread::get_id() << std::endl;
}



int main_4() {
	std::cout << "Main thread starts with the id of " << std::this_thread::get_id() << std::endl;

	std::cout << "Calling the threads for work\n";

	std::thread th1(threadWork4,600);
	std::thread th2(threadWork4,900);

	th1.join();
	th2.join();
	
	std::cout << "The value is = " << tmpVar << std::endl;
	std::cout << "Main thread completed with id of " << std::this_thread::get_id() << std::endl;

	return 0;
}

#endif // !MUTEX_THREAD_H