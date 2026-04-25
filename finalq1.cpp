#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

long func(long n){
    if (n<=1) {
        return 1;
    }
    return n*func(n-1);
}

void Q1() {
	long n;
	double f=0.0;
    double x;

    cout<<"Input x:"<<endl;
    cin>>x;

    ifstream infile("input.txt");
    infile>>n;
    infile.close();
    cout<<"Input n:"<<n<<endl;

    for (int i=1; i<=n; i++) {
        f += pow(x, i) / func(i);
    }
    cout<<"Value is: "<<fixed<<setprecision(2)<<f<<endl<<endl;

    cout<<"Formula is:"<<endl;
    for (int i=1; i<=n; i++) {
        if (i != n){
            cout<<"x^"<<i<<"/"<<i<<"!+";
        } else {
            cout<<"x^"<<i<<"/"<<i<<"!";
        }
    }
}

int main() {
	Q1();
	return 0;
}