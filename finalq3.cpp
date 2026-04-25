#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

template <class T>
class Base {
    private:
        T arr[5];
    public:
        void set(T s[]){
            for (int i=0; i<5; i++){
                arr[i]=s[i];
            }
        }
        T* getArr(){
            return &arr[0];
        }
};

class A: public Base<int> {
    public:
        void set(int s[]){
            Base<int>::set(s);
        }
};

class B: public Base<char> {
    public:
        void set(char s[]){
            Base<char>::set(s);
        }
};

template <class T>
bool isPalindromeSuffix(T arr[], int start, int end){
    while (start<end){
        if(arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

template <class T>
void shortestPalin(T arr[]) {
    int n=5;
    int longest_palin_start = 0;

    for (int i=0; i<n; i++){
        if(isPalindromeSuffix(arr, i, n-1)){
            longest_palin_start = i;
            break;
        }
    }

    cout<<"The shortest palindrome of the given array is:"<<endl;
    for (int i=0; i<n; i++){
        cout<< arr[i]<<" ";
    }
    for (int i=longest_palin_start-1; i>=0; i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void Q3() {
	int opt;
	cout << "1: int; 2: char" << endl;
	cin >> opt;

    if (opt==1) {
        int arr_int[5];
        cout<<"Enter 5 integers:"<<endl;
        for (int i=0; i<5; i++){
            cin>>arr_int[i];
        }
        A objA;
        objA.set(arr_int);
        shortestPalin(objA.getArr());
    }else if(opt==2){
        char arr_char[5];
        cout<<"Enter 5 chars:"<<endl;
        for (int i=0; i<5; i++){
            cin>>arr_char[i];
        }
        B objB;
        objB.set(arr_char);
        shortestPalin(objB.getArr());        
    }
}

int main() {
	Q3();
	return 0;
}