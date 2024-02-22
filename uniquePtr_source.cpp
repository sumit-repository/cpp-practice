#include "uniquePtr.h"

class Base;

#include "uniquePtr.cpp"
template class uniquePtr<Base>;
template class uniquePtr<int>;

typedef uniquePtr<Base> baseUniquePtr;
typedef uniquePtr<int> intUniquePtr;

class Base {
public:
	Base() { cout << "base cotr" << endl; }
	void func() { cout << "base func" << endl; }
	virtual ~Base() { cout << "base dtor" << endl; }
};

int main() {
	cout << "main" << endl;

	//....	uniquePtr with "int"	.....

	/*uniquePtr<int>*/intUniquePtr ptr1(new int(10));
	cout << *ptr1 << endl;

	//should give compilation error
	//uniquePtr<int> ptr2(ptr1);
	//uniquePtr<int> ptr3 = ptr1;

	intUniquePtr ptr2(std::move(ptr1));
	cout << *ptr2 << endl;
	intUniquePtr ptr3 = std::move(ptr2);
	cout << *ptr3 << endl;

	ptr3.get();
	ptr3.reset(new int(4));
	cout << *ptr3 << endl;

	baseUniquePtr b1(new Base());
	b1->func();

  return 0;
}
