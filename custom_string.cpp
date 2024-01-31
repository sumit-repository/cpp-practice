//----Incomplete----
//String class implementation
//to be continued from: https://www.youtube.com/watch?v=uQB7jNWnZaI

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class String {
    private:
        //const int i;
        //char* res;
        unsigned int len;
        void strcpy(const char*ch);
    public:
        char* res;
        String():res(nullptr), len(0){}
        String(const char* ch) {
            //strlen method needs to be used with #include<cstring>
            //len = strlen(ch); 
            len=0;
            while(ch[len]!='\0') 
                ++len;
            res = new char[len+1];
            //cout << ch << endl;
            strcpy(ch);
        }
};

void String::strcpy(const char* ch) {
    if (ch == nullptr)
        return;
    char* temp = res;
    while (*ch != '\0') {
        *temp++ = *ch++;
    }
    *temp = '\0';
    //another way while((*temp++=*ch++)!='0'){}
}

std::ostream& operator<<(std::ostream& stream, String s) {
    stream << s.res ;
    return stream;
}

int main() {
    cout << "hello world!" << endl;
    String s1("hello");
    cout << s1 << endl;
    return 0;
}
