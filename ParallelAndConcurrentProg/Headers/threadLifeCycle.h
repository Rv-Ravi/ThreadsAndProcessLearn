#ifndef THREAD_LIFE_CYCLE_H
#define THREAD_LIFE_CYCLE_H

#include <iostream>
#include <thread>
#include <chrono>


void threadWork1() {
	std::cout << "Thread 1 work starts with id of " << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(4));
	std::cout << "Thread 1 work completed with id of " << std::this_thread::get_id() << std::endl;
}

void threadWork2() {
	std::cout << "Thread 2 work starts with id of " << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(7));
	std::cout << "Thread 2 work completed with id of " << std::this_thread::get_id() << std::endl;
}


int main_2() {
	std::cout << "Main thread starts with the id of " << std::this_thread::get_id() << std::endl;

	std::cout << "Calling the both threads for work\n";

	std::thread th1;
	std::thread th2(threadWork2);

	std::cout << std::boolalpha << th1.joinable() << std::endl;

	th1 = std::thread(threadWork1);

	std::cout << std::boolalpha << th1.joinable() << std::endl;

	std::cout << "main thread waits for 5 a second\n";
	std::this_thread::sleep_for(std::chrono::seconds(5));

	std::cout << "main thread completed and waiting for them to finish the work\n";
	std::cout << "just for testing :" << th1.get_id() << std::endl;
	std::cout << std::thread::id() << std::endl;
	th1.join();
	th2.join();
	std::cout << std::boolalpha << th1.joinable() << std::endl;
	std::cout << "just for testing :" << th1.get_id() << std::endl;
	std::cout << std::thread::id() << std::endl;
	std::cout << "Main thread completed with id of " << std::this_thread::get_id() << std::endl;

	return 0;
}

#endif // !THREAD_LIFE_CYCLE_H