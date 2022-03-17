#ifndef SHARED_MUTEX_THREAD_H
#define SHARED_MUTEX_THREAD_H

#include <iostream>
#include <thread>
#include <shared_mutex>
#include <chrono>

std::shared_mutex tmpMutex, tmpMutex_1;
unsigned int recurInc = 0, funcInc = 0;


//Recursive function or The function in which mutex is locked is 
//caled by another function which locks same mutex again
void threadWork7() {
	
	while (funcInc < 30) {
		tmpMutex.lock_shared();
		std::cout << recurInc << " This is the value for this thread with id " << std::this_thread::get_id() << std::endl;
		tmpMutex.unlock_shared();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		funcInc++;
	}
	
	
	
}

void threadWork8() {
	while (funcInc < 100) {
		if (funcInc % 5 == 0) {
			tmpMutex.lock();
			recurInc++;
			std::cout << recurInc << " Updating the value for this thread with id " << std::this_thread::get_id() << std::endl;
			tmpMutex.unlock();
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		funcInc++;
	}
	
}

int main_7() {
	std::cout << "Main thread starts with the id of " << std::this_thread::get_id() << std::endl;

	std::cout << "Calling the threads for work\n";

	std::thread th1(threadWork7);
	std::thread th2(threadWork7);
	std::thread th3(threadWork7);
	std::thread th4(threadWork7);
	std::thread th5(threadWork8);





	th1.join(); th2.join(); th3.join(); th4.join(); th5.join();
	std::cout << "Main thread completed with id of " << std::this_thread::get_id() << std::endl;

	return 0;
}








#endif //!SHARED_MUTEX_THREAD_H