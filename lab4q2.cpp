#include <iostream>
#include <string> 
using namespace std;

int main() {
    string mainStr;  
    string subStr;   

    while (cin >> mainStr >> subStr) {
        cout << "The word and chars are:" << endl;
        size_t position = mainStr.rfind(subStr);
        cout << "The last position of " << subStr << " is: ";

        if (position == string::npos) {
            cout << -1 << endl;
        } else {
            cout << position << endl;
        }
    }

    return 0;
}