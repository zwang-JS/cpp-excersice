#include <iostream>
#include <cmath>
using namespace std;

/*
class Triangle {
    private:
        int side1, side2, side3;
        double area;
        void computeArea();
    public:
        Triangle();
        Triangle (int, int, int);
        void setSides(int, int, int);
        double getArea() { return area; }
};

void Triangle::setSides(int a, int b, int c){
    side1=a; side2=b; side3=c;
    computeArea();
}

Triangle::Triangle() : side1(0),side2(0), side3(0){
    computeArea();
    //side1=0; side2=0; side3=0;
    //setSides(0,0,0);
}

Triangle::Triangle(int a, int b, int c): side1(a),side2(b), side3(c){
    computeArea();
    //side1=a; side2=b; side3=c;
    //setSides(a,b,c);
}

void Triangle::computeArea(){
    double s=(side1+side2+side3)/2.0;
    area = sqrt(s*(s-side1)*(s-side2)*(s-side3));
}

int main(){
    Triangle t1;
    cout<<"Area of Triangle (i.e. triangle1): "<<t1.getArea()<<endl;
    Triangle t2(3,4,5);
    cout<<"Area of Triangle (i.e. triangle2 with sides 3, 4 and 5): "<<t2.getArea()<<endl;
    cout<<"Enter New Sides for Triangle:"<<endl;
    int s1,s1,s3;
    cin>>s1>>s2>>s3;
    t3.setSides(s1,s2,s3);
    cout<<"Area of Triangle: "<<t3.getArea()<<endl;
    return 0;
}

*/


/*

#include <iostream>
using namespace std;

class Record{
    private:
        int month, day;
        double balance;
    public:
        void set(int m, int d, double b);
        int getMonth();      {return month;}
        int getDay();        {return day;}
        double getBalance(); {return balance;}
};

void Record::set(int m, int d, double b) {
    month=m; day=d; balance=b;
}

void print(Record arr[], int n){
    
}

void sorrByBalance(){
    
}

bool isGreater(){
    
}

void sortByDate(){
    
}


int main(){
    Record arr[30];
    int n;
    cout<<"Enter the number of records:"<<endl;
    cin>>n;
    cout<<"Enter the contents of each records:"<<endl;
    int m,d;
    int b;
    
    return 0;
}

*/

class Record{
    private:
        int month, day;
        double balance;
    public:
        void set(int m, int d, double b);
        int getMonth()       {return month;}
        int getDay()         {return day;}
        double getBalance()  {return balance;} 
};

void Record::set(int m, int d, double b){
    month=m; day=d; balance=b;
}

void print(Record arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i].getMonth<<" "<<arr[i].getDay<<" "<<arr[i].getBalance<<endl;
    }
}

