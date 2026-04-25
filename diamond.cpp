#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the diagonal length: " << endl;
    while (true) {
        if (cin >> n && n > 0 && n % 2 == 1) {
            break; 
        } else {
            cout << "Please enter an odd positive number!" << endl;
        }
    }

    int mid=n/2;
    for (int i=0; i<=mid; i++){
        for (int j=0; j<mid-i; j++){
            cout<<" ";
        }
        for (int j=0; j<2*i+1; j++){
            cout<<"*";
        }
        cout<<endl;
    }

    for (int i=mid-1; i>=0; i--){
        for (int j=0; j<mid-i; j++){
            cout<<" ";
        }
        for (int j=0; j<2*i+1; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}