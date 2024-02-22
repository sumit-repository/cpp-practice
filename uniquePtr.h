#pragma once
#include<iostream>
using namespace std;

template<typename T>
class uniquePtr {
private:
	T* res;
public:
	uniquePtr(T* t = nullptr) :res(t) {
		cout << "uniquePtr ctor1" << endl;
	}
	
	//copy constructor and copy assignment operator
	//	need to be disallowed for unique pointer
	uniquePtr(const uniquePtr<T>& t) = delete;
	uniquePtr& operator=(uniquePtr<T>& t) = delete;

	//enabling std::move for copy constructor and 
	// copy assignment operator
	uniquePtr(uniquePtr<T>&& t);
	uniquePtr& operator=(uniquePtr<T>&& t);

	inline  T* operator->() { return res; }
	inline T& operator*() { return *res; }

	inline T* get() { return res; }
	void reset(T* newres = nullptr);

	~uniquePtr();
};


