#include <iostream>
using namespace std;

int main(){
    int num;
    int sum=0;

    cout<<"Please enter an integer number:"<<endl;
    cin>>num;
    int temp=num;

    do{
        sum+=temp%10;
        temp/=10;
    }while(temp>0);

    cout<<"Sum of "<<num<<" is: "<<sum<<endl;
    int N=sum%10;
    cout<<"The last digit of the sum is: "<<N<<endl;

    for (int i=1; i<=N; i++){
        for (int j=0; j<=i; j++){
            for (int k=0; k<N-j; k++){
                cout<<" ";
            }
            
            if (j==0){
                cout<<"*";
            }else if (j==i){
                for (int k=0; k<2*i+1; k++){
                    cout<<"*";
                }
            }else{
                cout<<"*";
                for (int k=0; k<2*j-1; k++){
                    cout<<" ";
                }
                cout<<"*";
            }
            cout<<endl;
        }
    }

    for (int k=0; k<N; k++){
        for (int s=0; s<N; s++){
            cout<<" ";
        }
        cout<<"*"<<endl;
    }

    return 0;
}