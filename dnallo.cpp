#include <iostream>
using namespace std;

class Base{
    public:
        virtual void func()=0;
        virtual ~Base() {}
};

class Paisheng : public Base{
    public:
        void func(){
            cout<<"Paisheng func"<<endl;
        }
};

int main(){
    Base* ptr = new Paisheng();
    ptr->func();
    delete ptr;

    return 0;
}