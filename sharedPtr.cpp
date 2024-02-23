#include"sharedPtr.h"

template<typename T>
sharedPtr<T>::sharedPtr(T* t) :res(t), count(new int(1)) {
	cout << "default & parameterized ctor" << endl;
}

template<typename T>
sharedPtr<T>::sharedPtr(const sharedPtr<T>& t) {
	res = t.res;
	count = t.count;
	increaseCount();
}

template<typename T>
sharedPtr<T>& sharedPtr<T>::operator=(const sharedPtr<T>& t) {
	cout << "assignment operator" << endl;
	if (this != &t) {
		decreaseCount();
		res = t.res;
		count = t.count;
		increaseCount();
	}
	return *this;
}

template<typename T>
sharedPtr<T>::sharedPtr(sharedPtr<T>&& t) {
	res = t.res;
	count = t.count;
	t.res = nullptr;
	t.count = nullptr;
}

template<typename T>
sharedPtr<T>& sharedPtr<T>::operator=(sharedPtr<T>&& t) {
	if (this != &t) {
		decreaseCount();
		res = t.res;
		count = t.count;
		t.res = nullptr;
		t.count = nullptr;
	}
	else
		cout << "this" << endl;
	return *this;
}

template<typename T>
void sharedPtr<T>::reset(T* newres) {
	decreaseCount();
	res = newres;
	count = new int(1);
}

template<typename T>
void sharedPtr<T>::increaseCount() {
	if (count)
		(*count)++;
}

template<typename T>
void sharedPtr<T>::decreaseCount() {
	if (!count)
		return;
	else if (count)
		(*count)--;
	if ((*count) == 0){
		delete count;
		count = nullptr;
		if (res) {
			delete res;
			res = nullptr;
		}
	}
}