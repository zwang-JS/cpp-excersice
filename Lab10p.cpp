#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Shape {
    public:
        virtual double area() = 0;
        virtual void print() = 0;
};

class Circle : public Shape {
    private:
        double r;
    public:
        Circle(double radius){
            r = radius;
        }
        double area() {
            return 3.14 * r * r;
        }
        void print() {
            cout << "The radius of circle is " << fixed<<setprecision(2)<<r << endl;
            cout<< "The area of circle is " << fixed<<setprecision(2)<< 3.14*r*r << endl;
        }
};

class Rectangle : public Shape {
    private:
        double wide;
        double len;
    public:
        Rectangle(double w, double l){
            wide = w;
            len = l;
        }
        double area() {
            return wide * len;
        }
        void print() {
            cout << "The width of rectangle is " << fixed<<setprecision(2)<<wide << " and the length is "<< fixed<<setprecision(2)<<len << endl;
            cout << "The area of rectangle is " << fixed<<setprecision(2)<<wide*len << endl;
        }
};

class Triangle : public Shape {
    private:
        double a;
        double b;
        double c;
    public: 
        Triangle(double x, double y, double z){
            a = x;
            b = y;
            c = z;
        }
        double area() {
            double p = (a + b + c) / 2;
            return sqrt(p * (p - a) * (p - b) * (p - c));
        }
        void print() {
            cout << "The sides of triangle is " << fixed<<setprecision(2)<<a << ", " << fixed<<setprecision(2)<<b << " and " << fixed<<setprecision(2)<<c << endl;
            cout << "The area of triangle is " << fixed<<setprecision(2)<<area() << endl;
        }
};


int main() {
    int n;
    cout<<"Input the number of shapes:"<<endl;
    cin>>n;
    Shape* shapes[n];
    for (int i = 0; i < n; i++) {
        cout<<"~~~~~~~~"<<n+1<<"~~~~~~~~"<<endl;
        cout<<"c: circle"<<endl;
        cout<<"r: rectangle"<<endl;
        cout<<"t: triangle"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~"<<endl;

        char type;
        cin>>type;
        if (type == 'c') {
            double radius;
            cout<<"Radius:"<<endl;
            cin>>radius;
            shapes[i] = new Circle(radius);
        }else if (type == 'r') {
            double width, length;
            cout<<"Two sides:"<<endl;
            cin>>width>>length;
            shapes[i] = new Rectangle(width, length);
        }else if (type == 't') {
            double a, b, c;
            cout<<"Three sides:"<<endl;
            cin>>a>>b>>c;
            shapes[i] = new Triangle(a, b, c);
        }
    }

    cout<<endl;
    for (int i=0; i<n; i++) {
        shapes[i]->print();
    }
    
    for (int i=0; i<n; i++) {
        delete shapes[i];
    }
    
    return 0;
}