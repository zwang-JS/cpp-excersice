#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char arr[50]
    cout << "Enter the student info:" << endl;
    cin.getline(arr, 50);

    int len = strlen(arr); 
    int spaceIdx = -1;

    for (int i = len - 1; i >= 0; i--) {
        if (arr[i] == ' ') {
            spaceIdx = i;
            break;   
        }
    }

    cout << "Student name is: ";
    for (int i = 0; i < spaceIdx; i++) {
        cout << arr[i];
    }
    cout << endl;

    cout << "Student ID is: ";
    for (int i = spaceIdx + 1; i < len; i++) {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}