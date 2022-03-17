#ifndef RECURSIVE_MUTEX_THRED_H
#define RECURSIVE_MUTEX_THRED_H

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::recursive_mutex tmpMutex, tmpMutex_1;
unsigned int recurInc = 0, funcInc = 0;


//Recursive function or The function in which mutex is locked is 
//caled by another function which locks same mutex again
void threadWork6(int count) {
	std::cout << "Thread started with thread ID of " << count << " " << std::this_thread::get_id << std::endl;
	if (count < 0)
		return;
	else {
		if (tmpMutex.try_lock())
		{
			recurInc++;
			threadWork6(--count);
			tmpMutex.unlock();
		}
	}
	std::cout << "Thread Ended with thread ID of " << std::this_thread::get_id << std::endl;
}



int main_6() {
	std::cout << "Main thread starts with the id of " << std::this_thread::get_id() << std::endl;

	std::cout << "Calling the threads for work\n";

	std::thread th1(threadWork6,5);

	th1.join();
	std::cout << "Main thread completed with id of " << std::this_thread::get_id() << std::endl;

	return 0;
}







#endif //!RECURSIVE_MUTEX_THRED_H