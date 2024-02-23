#pragma once
#include<iostream>
using namespace std;

template<typename T>
class sharedPtr {
private:
	T* res;
	int* count;
	void increaseCount();
	void decreaseCount();


public:
	sharedPtr(T* t = nullptr); //default and parameterised constructor

	sharedPtr(const sharedPtr <T>& t); //copy constructor
	sharedPtr& operator=(const sharedPtr <T>& t); //assignment operator
	
	sharedPtr(sharedPtr <T>&& t); //move copy constructor
	sharedPtr& operator=(sharedPtr<T>&& t); //move-assignment operator

	inline T& operator*() { return *res; }
	inline T* operator->() { return res; }
	
	inline int getCount() { return *count; }
	void reset(T* newres = nullptr);

	//~sharedPtr() {}	
};