#include <iostream>
#include <iomanip>
using namespace std;

const int N = 10;

struct Date {
    int day;
    int month;
    int year;
};

struct Order {
    int orderID;
    double price;
    Date date;
};

struct Restaurant {
    Order orders[N];
    int num;
};

void listOptions() {
    cout << "~~~~~~~~~Welcome!~~~~~~~~~~" << endl;
    cout << "0: Exit" << endl;
    cout << "1: Add" << endl;
    cout << "2: Show" << endl;
    cout << "3: Delete" << endl;
    cout << "4: Sort" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void add(Restaurant *p) {
    if (p->num >= N){
        cout<<"Restaurant is full"<<endl;
        cout<<endl;
    }else{
        cout << "Input OrderID: "<<endl;
        cin >> p->orders[p->num].orderID;
        cout << "Input Price: "<<endl;
        cin >> p->orders[p->num].price;
        cout << "Input Order Date (dd mm yyyy): " << endl;
        cin >> p->orders[p->num].date.day >> p->orders[p->num].date.month >> p->orders[p->num].date.year;
        cout<<endl;
        p->num++;
    }
}

void show(Restaurant *p) {
    for (int i=0; i<p->num; i++){
        cout<<setfill('0')<<setw(3)<<p->orders[i].orderID<<"     ";
        cout<<fixed<<setprecision(2)<<p->orders[i].price<<"   ";
        cout<<p->orders[i].date.day<<"-"<<p->orders[i].date.month<<"-"<<p->orders[i].date.year<<endl;
    }
    cout<<endl;
    
}

void del(Restaurant *p) {
    int id;
    cout<<"Enter the orderID to be deleted"<<endl;
    cin>>id;
    

    int idx=-1;
    for (int i=0; i<p->num; i++){
        if (p->orders[i].orderID==id){
            idx=i;
            break;
        }
    }

    if (idx!=-1){
        for (int i=idx; i<p->num-1; i++){
            p->orders[i]=p->orders[i+1];
        }
        p->num--;
        cout<<endl;
    }else{
        cout<<"The orderID cannot be found"<<endl;
        cout<<endl;
    }
}

void sort_id(Restaurant *p) {
    for (int i=0; i<p->num-1; i++){
        for (int j=0; j<p->num-i-1; j++){
            if (p->orders[j].orderID > p->orders[j + 1].orderID){
                Order temp = p->orders[j];
                p->orders[j] = p->orders[j + 1];
                p->orders[j + 1] = temp;
            }
        }
    }
    
}

void sort_date(Restaurant *p) {
    for (int i = 0; i < p->num - 1; i++) {
        for (int j = 0; j < p->num - i - 1; j++) {
            bool swap = false;
            if (p->orders[j].date.year > p->orders[j+1].date.year) swap = true;
            else if (p->orders[j].date.year == p->orders[j+1].date.year) {
                if (p->orders[j].date.month > p->orders[j+1].date.month) swap = true;
                else if (p->orders[j].date.month == p->orders[j+1].date.month) {
                    if (p->orders[j].date.day > p->orders[j+1].date.day) swap = true;
                    else if (p->orders[j].date.day == p->orders[j+1].date.day) {
                        if (p->orders[j].orderID > p->orders[j+1].orderID) swap = true;
                    }
                }
            }
            if (swap) {
                Order t = p->orders[j];
                p->orders[j] = p->orders[j+1];
                p->orders[j+1] = t;
            }
        }
    } 
}

void sort(Restaurant *p) {
    int n;
    cout << "1: Sort by orderID" << endl;
    cout << "2: Sort by date" << endl;
    cout<<endl;
    cin >> n;
    if (n == 1) sort_id(p);
    else if (n == 2) sort_date(p);
}

void init(Restaurant *p) {
    p->orders[p->num].orderID = 3;
    p->orders[p->num].price = 10.5;
    p->orders[p->num].date.day = 15;
    p->orders[p->num].date.month = 1;
    p->orders[p->num].date.year = 1990;
    (p->num)++;

    p->orders[p->num].orderID = 2;
    p->orders[p->num].price = 20.55;
    p->orders[p->num].date.day = 15;
    p->orders[p->num].date.month = 2;
    p->orders[p->num].date.year = 2024;
    (p->num)++;

    p->orders[p->num].orderID = 4;
    p->orders[p->num].price = 10.5;
    p->orders[p->num].date.day = 20;
    p->orders[p->num].date.month = 2;
    p->orders[p->num].date.year = 2021;
    (p->num)++;

    p->orders[p->num].orderID = 1;
    p->orders[p->num].price = 30.1;
    p->orders[p->num].date.day = 20;
    p->orders[p->num].date.month = 2;
    p->orders[p->num].date.year = 2021;
    (p->num)++;
}


int main() {
    Restaurant res;
    res.num = 0;
    init(&res);
    
    int opt;
    while (true){
        listOptions();
        cin>>opt;
        if (opt==0){
            cout<<"Bye!"<<endl;
            break;
        }
        switch (opt){
            case 1:add(&res);break;
            case 2:show(&res);break;
            case 3:del(&res);break;
            case 4:sort(&res);break;
        }
    }

    return 0;
}