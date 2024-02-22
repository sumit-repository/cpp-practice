#include "uniquePtr.h"

//template class uniquePtr<int>;

template<typename T>
uniquePtr<T>::uniquePtr(uniquePtr<T>&& t) {
	cout << "uniquePtr ctor2" << endl;
	res = t.res;
	t.res = nullptr;
}

template<typename T>
uniquePtr<T>& uniquePtr<T>::operator=(uniquePtr<T>&& t) {
	cout << "uniquePtr ctor3" << endl;
	if (res)
		delete res;
	res = t.res;
	t.res = nullptr;
	return *this;
}

template<typename T>
void uniquePtr<T>::reset(T* newres) {
	if (res)
		delete res;
	res = newres;
}

template<typename T>
uniquePtr<T>::~uniquePtr() {
	cout << "uniquePtr dtor" << endl;
	if (res) {
		delete res;
		res = nullptr;
	}
}
