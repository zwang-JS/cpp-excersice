#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

int f(int n) {
    if (n==0) return 1;
    if (n==1) return 2;
    return 2*f(n-1)+f(n-2);
}

void Q2() {
	int n;
    cout<<"Enter a number:"<<endl;
    cin>>n;
    cout<<"The result of f(n) is: "<<f(n)<<endl<<endl;

    int temp=f(n);
    int digit_len = 0;
    while (temp>0) {
        temp/=10;
        digit_len++;
    }
    
    int** arr = new int*[2];
    arr[0] = new int[digit_len];
    arr[1] = new int[digit_len];

    temp=f(n);
    int weight=1;
    for (int i=1; i<digit_len; i++){
        weight *=10;
    }
    
    for (int i=0; i<digit_len; i++){
        arr[0][i] = temp/weight;
        temp %= weight;
        weight /= 10;
        arr[1][i]=i;
    }

    int fengge;
    cout<<"Please input the length of the number:"<<endl;
    cin>>fengge;

    for (int i=0; i<=digit_len-fengge; i++) {
        int num=0;
        for (int j=i; j < i + fengge; j++){
            num = num*10 + arr[0][j];
        }
        cout<<num;
        if (i!=digit_len-fengge) cout<<" ";
    }
    cout<<endl<<endl;

    cout<<"Sorted array"<<endl;
    for (int i=0; i<digit_len-1; i++){
        for (int j=0; j<digit_len-1-i; j++){
            if (arr[0][j] > arr[0][j+1]) {
                int temp1 = arr[0][j];
                arr[0][j] = arr[0][j+1];
                arr[0][j+1] = temp1;

                int temp2 = arr[1][j];
                arr[1][j] = arr[1][j+1];
                arr[1][j+1] = temp2;
            }
        }
    }

    for (int i=0; i<digit_len; i++){
        cout<<arr[0][i]<<" ";
    }
    cout<<endl;

    for (int i=0; i<digit_len; i++){
        cout<<arr[1][i]<<" ";
    }    

    delete[] arr[0];
    delete[] arr[1];
    delete[] arr;
}

int main() {
	Q2();
	return 0;
}