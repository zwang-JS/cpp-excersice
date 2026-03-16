#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

string getEnglishDigit(int digit) {
    switch (digit) {
        case 0: return "Zero";
        case 1: return "One";
        case 2: return "Two";
        case 3: return "Three";
        case 4: return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
        default: return "";
    }
}

int main(){
    int num;
    cout<<"Please enter an integer number:"<<endl;
    cin>>num;
    int segments[10];
    int count=0;

    while (num>0){
        segments[count]=num%1000;
        num/=1000;
        count++;
    }

    cout << "3-digit Segment(s):" << endl;

    for (int i=count-1; i>=0; i--){

        if (segments[i]==0){
            continue;
        }

        int lsd=segments[i]%10;
        cout<<setfill('0')<<setw(3)<<segments[i]<<" "<<getEnglishDigit(lsd)<<endl;
    }
    return 0;
}