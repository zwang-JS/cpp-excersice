#include <iostream>
using namespace std;

class Student {
    public:
        int score;
        int* ID;

        Student(int s, int id) {
            score = s;
            ID = new int(id);
        }

        Student& operator=(const Student& s) {
            score = s.score;

            if (ID != NULL) {
                delete ID;
                ID = NULL;
            }
            ID = new int(*s.ID);

            return *this;
        }
};        
/*重点就是深拷贝*/