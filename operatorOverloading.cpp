//operator overloading syntax
//how to overload cout for customized printing of a class
#include<iostream>
using namespace std;

class base {
public:
	int m, n;
	base() :m(4), n(5) {}
	base(int m, int n) : m(m), n(n) {}
	base operator+ (const base& b1) {
		return base(this->m + b1.m, this->n + b1.n);
	}
};

std::ostream& operator<<(std::ostream& stream, const base& b) {
	stream << b.m << ", " << b.n << endl;
	return stream;
}

int main() {
	cout << "Hello world!" << endl;
	base b1;
	cout << b1;
	base b2(10, 11);
	base b3 = b1 + b2;
	cout << b3;
}
