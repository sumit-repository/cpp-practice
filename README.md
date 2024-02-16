# cpp-practice
cpp C++ practice

Notes:

-----  Strings  -----
> char* str="name"    //this is string literal and it is immutable
  char str[]="name"  //this is array of string - mutable
> char c1[]="hello" //in this case c is a const pointer - c1++ is not allowed
  char* c2 = new char[5]; //in this case c2 is a dynamically allocated pointer - hence c2++ is allowed
> Resources:
	Keerti: https://www.youtube.com/watch?v=uQB7jNWnZaI&t=741s
	cherno: copying and copy constructor c++: https://www.youtube.com/watch?v=BvR1Pgzzr38&t=343s
> 

-----  Class    -----
> Initializer List: extremely useful in the following cases:
  >>  1. In case we have a reference member in the class
  >>  2. In case we have another class object as a member of our class, and the former class does not have a default constructor
      class A {
         public:
	  	   int n;
	  	   A(int n):n(n){}
	    };
  	  class B {
  		  public:
  		  int& ref_i;
  		  A a;
  		  B(int n, const int& m){} //Error: both "a" and "ref_i" expects initiation
  	  };

-----	Copy Constructor    -----
> Ways to write copy constructor for a class say "Base":
	1. Base(const Base& b);
	2. Base(Base& b);
	3. Base(Base b); //wrong - reaons - ?

