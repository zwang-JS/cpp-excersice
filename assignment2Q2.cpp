#include <iostream>
using namespace std;

class Combination {
    private:
        int dNum;// number of dices
        int cNum;// number of different point sums
        long long int **pPtr; // pointing to a 2D array for each pair of occurrence and sum. Use long int to avoid overflow.
    public:
        Combination(int i = 1) {
            dNum=i;
            cNum=5*dNum+1;
            pPtr=new long long int*[cNum]
            for (int j=0; j<cNum; j++0) {
                pPtr[j]=new long long int *[2];
                pPtr[j][0]=0;
                pPtr[j][1]=dNum+j;
            }

            if (dNum==1) findSum1();
            else if (dNum==2) findSum2();
            else if (dNum==3) findSum3();

        /************** to be finished **************/

        }
        ~Combination() {
            for (int j=0; j < cNum; j++){
                delete[] pPtr[j];
            }
            delete[] pPtr;
            
/************** to be finished **************/
/***********Remember to release memory*******/

        cout << "Memory is released" << endl;
        }
        void findSum1();
        void findSum2();
        void findSum3();
        
        /************** to be finished **************/
        void sortBySum();
        void sortByOcc();
};

void Combination::findSum1() {
    for (int i=1; i<=6; i++){
        pPtr[i-1][0]++;
    } 
}
void Combination::findSum2() {
    for (int i=1; i<=6; i++){
        for (int j=1; j<=6; j++){
            pPtr[i+j-2][0]++;
        }
    }
}
void Combination::findSum3() {
    for (int i=1; i<=6; i++){
        for (int j=1; j<=6; j++){
            for (int k=1; k<=6; k++){
                pPtr[i+j+k-3][0]++;
            }
        }
    }
}
void Combination::sortBySum() {
    for (int i=0; i<cNum-1; i++){
        for (int j=0; j<cNum-1-i; j++){
            if (pPtr[j][1] > pPtr[j+1][1]){
                long long int *temp = pPtr[j];
                pPtr[j] = pPtr[j+1];
                pPtr[j+1] = temp;
            }
        }
    }
    for (int i=0; i<cNum; i++){
        cout << pPtr[i][0] << "occurrence(s) of sum " << pPtr[i][1] << endl;
    }
}
void Combination::sortByOcc() {
    for (int i=0; i<cNum-1; i++){
        for (int j=0; j<cNum-1-i; j++){
            if (pPtr[j][0] > pPtr[j+1][0]){
                long long int *temp = pPtr[j];
                pPtr[j] = pPtr[j+1];
                pPtr[j+1] = temp;
            }
        }
    }
    for (int i=0; i<cNum; i++){
        cout << pPtr[i][0] << "occurrence(s) of sum " << pPtr[i][1] << endl;
    }
}

void display(Combination &com) {
    int n;
    do {
        cout << "~~~~~~~~~~~~~~~~~" << endl;
        cout << "0 exit" << endl;
        cout << "1 sort by sum" << endl;
        cout << "2 sort by occurrence" << endl;
        cout << "~~~~~~~~~~~~~~~~~" << endl;
        cin >> n;
        switch(n) {
        case 0: cout << "Bye!" << endl; break;
        case 1: com.sortBySum(); break;
        case 2: com.sortByOcc(); break;
        }
        cout << endl;
    } while(n != 0);
}

int main() {
    int diceNum;
    cout << "Enter the number of dice:" << endl;
    cin >> diceNum;
    Combination com(diceNum);
    display(com);
    return 0;
}