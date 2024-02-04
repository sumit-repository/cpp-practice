//----Incomplete----
//String class implementation
//to be continued from: https://www.youtube.com/watch?v=uQB7jNWnZaI

//#include "String.h"
//#pragma once
#include<iostream>
using namespace std;

class String
{
private:
	unsigned int len;
	char* str;
	void strcpy(const char* ch);
public:
	String() :str(nullptr), len(0) {}
	String(const char* ch);
	String(const String & obj);
	const int length() { return len; }
	String& operator= (const String& obj); //Refer Note 1
};

int main() {
	cout << "Test run begins!" << endl;

	String str1; //default constructor
	String str2 = "hello"; //parameterised constructor
	String str3 = str1; //copy constructor
	str3 = str2; //assignment operator
	int len = str2.length();
	//cout << str2; //overload <<
	//cin >> str1; //overload >>
	cout << str2.length() << endl;
	cout << "Test run ends!" << endl;
	return 0;
}

String::String(const char* ch) {

	if (ch == nullptr) {
		String();
		return;
		}

	len = 0;
	while (ch[len] != '\0')
		len++;
	str = new char[len + 1];
	strcpy(ch);
}

String::String(const String& obj) {
	len = obj.len;
	str = new char[len + 1];
	strcpy(obj.str);
}

String& String::operator=(const String& obj) {
	if (this != &obj) {
		delete[] this->str;
		len = obj.len;
		str = new char[len + 1];
		strcpy(obj.str);
	}
	//cout << "Assignment operator" << endl;
	return *this;
}

void String::strcpy(const char* ch) {
	if (ch == nullptr)
		return;
	char* temp = str;
	while ((*temp++ == *ch++) != '\0') {}
	*temp = '\0';
}

//Notes:
//1. Operator overloading can also be done in two ways: 
//		i.	void operator =(const String& obj);
//		ii.	String& operator =(const String& obj);
//		In both cases, the assignment operator works as expected.
//		The only difference being, in case(i), (str1 = str2 = str3)
//			will give an error as there is no return type defined
