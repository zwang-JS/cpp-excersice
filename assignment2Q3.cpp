#include <iostream>
#include <string>

using namespace std;
class Product {
private:
    char Name[15]; 
    int Date;
    bool State;    

public:
    Product() {}
    void setProduct(string n, int d, bool s) {
        int len = (int)n.length();
        int i = 0;
        while (i < len && i < 14) {
            Name[i] = n[i];
            i++;
        }
        Name[i] = '\0';
        Date = d;
        State = s;
    }

    string getName() { return string(Name); }
    int getDate() { return Date; }
    bool getState() { return State; }
    void setState(bool s) { State = s; }
};

class Category {
private:
    Product list[100]; 
    int count;

public:
    Category() { count = 0; }

    void addProduct(string name, int date, bool state) {
        list[count].setProduct(name, date, state);
        count++;
    }
    void sortProducts() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - 1 - i; j++) {
                if (list[j].getDate() < list[j + 1].getDate()) {
                    Product temp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = temp;
                }
            }
        }
    }

    void display() {
        for (int i = 0; i < count; i++) {
            cout << list[i].getName() << " " << list[i].getDate() << " " << list[i].getState() << endl;
        }
    }

    Product* findProduct(string name) {
        for (int i = 0; i < count; i++) {
            if (list[i].getName() == name) {
                return &list[i];
            }
        }
        return NULL; 
    }
};

class Store {
private:
    Category Electronics;
    Category Clothing;
    Category Food;

public:
    void Add() {
        cout << "Input the number of products:" << endl;
        int n;
        cin >> n;
        cout << "Input the information of products (name, date, state, category):" << endl;
        for (int i = 0; i < n; i++) {
            string name, category;
            int date;
            bool state;
            cin >> name >> date >> state >> category;
            if (category == "Electronics") Electronics.addProduct(name, date, state);
            else if (category == "Clothing") Clothing.addProduct(name, date, state);
            else if (category == "Food") Food.addProduct(name, date, state);
        }
    }

    void Show() {
        cout << "Products in the store:" << endl;
        Electronics.sortProducts();
        Clothing.sortProducts();
        Food.sortProducts();

        cout << "Electronics:" << endl;
        Electronics.display();
        
        cout << "Clothing:" << endl;
        Clothing.display();
        
        cout << "Food:" << endl;
        Food.display();
    }

    void Purchase() {
        cout << "Input the name of the product you want to purchase:" << endl;
        string name;
        while (true) {
            cin >> name;
            Product* p = Electronics.findProduct(name);
            if (!p) p = Clothing.findProduct(name);
            if (!p) p = Food.findProduct(name);

            if (p != NULL && p->getState() == 1) {
                p->setState(0); 
                cout << name << endl; 
                cout << "Succeed!" << endl;
                
                break; 
            } else {
                cout << "Sorry, the product is not available. Try again:" << endl;
            }
        }
    }
};

int main() {
    Store myStore;
    int choice;
    do {
        cout << "~~~~~~~~~Welcome!~~~~~~~~~~\n";
        cout << "0: Exit\n";
        cout << "1: Add\n";
        cout << "2: Show\n";
        cout << "3: Purchase\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cin >> choice;

        if (choice == 1) {
            myStore.Add();
        } else if (choice == 2) {
            myStore.Show();
        } else if (choice == 3) {
            myStore.Purchase();              
        }
    } while (choice != 0);
    
    cout << "Bye!" << endl;
    return 0;
}