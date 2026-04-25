#include <iostream>
using namespace std;

struct MyComplex {
    double Real;
    double Imaginary;
    MyComplex(double r=0.0, double i=0.0) : Real(r), Imaginary(i) {}

    friend ostream& operator<<(ostream& os, const MyComplex& c) {
        if (c.Real ==0 && c.Imaginary ==0) {
            os << "0";
        }else{
            os << c.Real <<  " + " << c.Imaginary << "i";
        }
        return os;
    }
};

class Calculator {
    protected:
        MyComplex num1, num2;
    
    public:
        void set(MyComplex n1, MyComplex n2) {
            num1 = n1;
            num2 = n2;
        }
        virtual MyComplex getResult()=0;
        virtual ~Calculator() {}
};

class AdditionCal : public Calculator {
    public:
        MyComplex getResult() {
            MyComplex result;
            result.Real = num1.Real + num2.Real;
            result.Imaginary = num1.Imaginary + num2.Imaginary;
            return result;
        }
};

class SubtractionCal : public Calculator {
    public:
        MyComplex getResult() {
            MyComplex result;
            result.Real = num1.Real - num2.Real;
            result.Imaginary = num1.Imaginary - num2.Imaginary;
            return result;
        }
};

class MultiplyCal : public Calculator {
    public:
        MyComplex getResult() {
            MyComplex result;
            result.Real = num1.Real*num2.Real - num1.Imaginary*num2.Imaginary;
            result.Imaginary = num1.Real*num2.Imaginary + num1.Imaginary*num2.Real;
            return result;
        }
};

class DivisionCal : public Calculator {
    public:
        MyComplex getResult() {
            denominator = (num2.Real*num2.Real + num2.Imaginary*num2.Imaginary)
            if (denominator == 0) {
                cout << "Error: Division by zero!" << endl;
                return MyComplex(0, 0); 
            }
            MyComplex result;
            result.Real = (num1.Real*num2.Real + num1.Imaginary*num2.Imaginary)/denominator;
            result.Imaginary = (num1.Imaginary*num2.Real - num1.Real*num2.Imaginary)/denominator;
            return result;
        }
};

int main() {
    double r1, i1, r2, i2;
    cout << "Input the first operand:" << endl;
    cin >> r1 >> i1;
    cout << "Input the second operand:" << endl;
    cin >> r2 >> i2;

    MyComplex n1(r1, i1);
    MyComplex n2(r2, i2);

    Calculator* Cal;

    Cal = new AdditionCal();
    Cal->set(n1, n2);
    cout << "The result of (" << n1 << ")+(" << n2 << ") is " << Cal->getResult() << endl;
    delete Cal;

    Cal = new SubtractionCal();
    Cal->set(n1, n2);
    cout << "The result of (" << n1 << ")-(" << n2 << ") is " << Cal->getResult() << endl;
    delete Cal;

    Cal = new MultiplyCal();
    Cal->set(n1, n2);
    cout << "The result of (" << n1 << ")*(" << n2 << ") is " << Cal->getResult() << endl;
    delete Cal;

    Cal = new DivisionCal();
    Cal->set(n1, n2);
    MyComplex divResult = Cal->getResult(); 
    cout << "The result of (" << n1 << ")/(" << n2 << ") is " << divResult << endl;
    delete Cal;

    return 0;
}