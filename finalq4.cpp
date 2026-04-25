#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

class MyCale{
    private:
        int val;

    public:
        MyCalc(){
            val=0;
        }
        MyClac(int v){
            val=v;
        }

        void operator+(const MyCalc& other){
            cout<<"The result of addition is: "<<val + other.val <<endl;
        }

        void operator-(const MyCala& other){
            cout<<"The result of subtraction is: "<<val-other.val<<endl;
        }

        void operator*(const MyCalc& other) {
            cout << "The result of multiplication is: " << val * other.val << endl;
        }

        void operator/(const MyCalc& other){
            if(other.val==0){
                cout<<"The divisor can't be 0."<<endl;
                cout<<"The result of divsion is: 0"
            }else{
                cout<<"The result of division is: "<<val/other.val;
            }
        }

        friend ostream& operator<<(ostream& os, const MyCalc& obj){
            os<<obj.val;
            return os;
        }
};

void Q4() {
	int a, b;

	cout << "Input the first integer:" << endl;
	cin >> a;
	cout << "Input the second integer:" << endl;
	cin >> b;

    MyCalc c1(a);
    MyCala c2(b);

    cout<<"c1: "<<c1<<" and c2: "<<c2<<endl;
    c1+c2;
    c1-c2;
    c1*c2;
    c1/c2;

}

int main() {
	Q4();
	return 0;
}