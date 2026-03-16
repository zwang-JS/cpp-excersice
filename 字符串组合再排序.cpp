#include <iostream>
#include <string>
using namespace std;

void sortString(string &s){
    int n=s.length();
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (s[j]>s[j+1]){
                char temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}

string mergeandsort(string str1,string str2){
    string combined=str1+str2;
    sortString(combined);
    return combined;
}

int main(){
    string s1;
    cout<<"put in s1:"<<endl;
    cin>>s1;

    string s2;
    cout<<"put in s2:"<<endl;
    cin>>s2;

    string res=mergeandsort(s1,s2);
    cout<<"the result is: "<<res<<endl;
    return 0;
}