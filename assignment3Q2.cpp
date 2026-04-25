#include <iostream>
using namespace std;

template <class T>
class MyArray {
    private:
        T* pAddress;
        int mSize;
        int mCapacity;
    public:
        MyArray(int capacity) {
            mCapacity = capacity;
            mSize = 0;
            pAddress = new T[mCapacity];
        }

        MyArray(const MyArray& a) {}

        ~MyArray() {
            if (pAddress != NULL) {
                delete[] pAddress;
                pAddress = NULL;
            }
        }

        getMax() {}

        MyArray& operator=(const MyArray& a) {}

        
};