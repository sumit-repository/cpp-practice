//operator overloading syntax
//how to overload "cout" for customized printing of a class
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
	bool operator== (const base& obj) {
		return (m == obj.m) && (n == obj.n);
	}
	bool operator!=(const base& obj) {
		return !(*this==obj);
		//return !(operator == (obj));	//other way of using operator in function definition
						                //note that b2 needs to be written in ()
	}
};

std::ostream& operator<<(std::ostream& stream, const base& b) {
	stream << b.m << ", " << b.n << endl;
	return stream;
}

int main() {
	cout << "Hello world!" << endl;
	base b1, b2;
	base b3 = b1 + b2;
	cout << b3;
	base b4(9, 10);
	cout << "IsEquals: " << (b4 == b3) << endl;
	cout << "IsNotEquals: " << (b4 != b3) << endl;
}
