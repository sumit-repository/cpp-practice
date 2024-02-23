//If there was a source.h
#include"sharedPtr.h"

//forward declaration
class Base;

//------------------------------------------------------//

//source.cpp
#include"sharedPtr.cpp"

template class sharedPtr<int>;
typedef sharedPtr<int> sharedIntPtr;

int main() {
	cout << "main" << endl;
	
	sharedIntPtr ptr1;

	sharedIntPtr ptr2(new int(9));
	cout << *ptr2 << endl;
	cout << ptr2.getCount() << endl;

	sharedIntPtr ptr3(ptr1);
	cout << ptr3.getCount() << endl;

	ptr1 = ptr2;

	sharedIntPtr ptr4(new int(12));
	ptr4 = std::move(ptr4);
	sharedIntPtr ptr5(std::move(ptr4));
	cout << *ptr5 << " " << ptr5.getCount() << endl;

	return 0;
}