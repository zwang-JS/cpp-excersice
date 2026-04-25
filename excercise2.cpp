#include <iostream>
#include <string>
using namespace std;

void findWord(char *arr, int *i, int *count){
    int wordlen=0;
    while (arr[*i] != ' ' && arr[*i] != '\0'){
        wordlen++;
        (*i)++;
    }
    (*count)++;
    cout<<"Word "<<*count<<" has "<<wordlen<<" characters."<<endl;
}