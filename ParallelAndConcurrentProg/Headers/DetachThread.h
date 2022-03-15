#ifndef DETACH_THREAD_H
#define DETACH_THREAD_H

#include <iostream>
#include <thread>
#include <chrono>


void threadWork3() {
	std::cout << "Thread 1 work starts with id of " << std::this_thread::get_id() << std::endl;
	while (true) {
		std::cout << "Child thread is still working\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	
	std::cout << "Thread 1 work completed with id of " << std::this_thread::get_id() << std::endl;
}



int main_3() {
	std::cout << "Main thread starts with the id of " << std::this_thread::get_id() << std::endl;

	std::cout << "Calling the threads for work\n";

	std::thread th1(threadWork3);
	th1.detach();
	std::cout << std::boolalpha << th1.joinable() << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	std::cout << "My work is completed i am waiting for other threads to complete\n";
	if (!th1.joinable())
	{
		std::cout << "Not eligible for joining\n";

	}
	
	std::cout << "Main thread completed with id of " << std::this_thread::get_id() << std::endl;

	return 0;
}

#endif // !DETACH_THREAD_H