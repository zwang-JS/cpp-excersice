#include <iostream>
#include <string>

using namespace std;

// 1. Product 类
class Product {
private:
    char Name[15]; // cstring 格式，题目提示最多 10 个字符，留点余量
    int Date;
    bool State;    // 1: available, 0: not available

public:
    Product() {} // 默认构造函数
    
    // 初始化产品信息
    void setProduct(string n, int d, bool s) {
        // 使用 (int) 显式转换 n.length()，彻底消除不同类型比较的 sign-compare 编译报错
        int len = (int)n.length();
        int i = 0;
        while (i < len && i < 14) {
            Name[i] = n[i];
            i++;
        }
        Name[i] = '\0'; // 加上字符串结束符
        Date = d;
        State = s;
    }

    // Getter 和 Setter 方法，保证私有成员的封装性
    string getName() { return string(Name); }
    int getDate() { return Date; }
    bool getState() { return State; }
    void setState(bool s) { State = s; }
};

// 2. Category 类
class Category {
private:
    Product list[100]; // 题目提示最多 100 个产品
    int count;

public:
    Category() { count = 0; }

    void addProduct(string name, int date, bool state) {
        list[count].setProduct(name, date, state);
        count++;
    }

    // 按日期从新到旧排序 (降序)
    void sortProducts() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - 1 - i; j++) {
                if (list[j].getDate() < list[j + 1].getDate()) {
                    // 交换
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

    // 查找产品：如果找到返回指针，找不到返回 NULL
    Product* findProduct(string name) {
        for (int i = 0; i < count; i++) {
            if (list[i].getName() == name) {
                return &list[i];
            }
        }
        return NULL; // 找不到
    }
};

// 3. Store 类
class Store {
private:
    // 分别声明三个分类对象，不使用数组
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
            
            // 根据输入的分类放入对应的 Category 对象
            if (category == "Electronics") Electronics.addProduct(name, date, state);
            else if (category == "Clothing") Clothing.addProduct(name, date, state);
            else if (category == "Food") Food.addProduct(name, date, state);
        }
    }

    void Show() {
        cout << "Products in the store:" << endl;
        
        // 打印前分别对三个分类排序
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
            // 依次在三个分类中查找
            Product* p = Electronics.findProduct(name);
            if (!p) p = Clothing.findProduct(name);
            if (!p) p = Food.findProduct(name);

            // 如果找到了该产品且状态为 1 (可用)
            if (p != NULL && p->getState() == 1) {
                p->setState(0); // 购买成功，状态改为 0 (不可用)
                
                // 【修复细节】：购买成功后，先回显一次商品名称，再打印 Succeed!
                cout << name << endl; 
                cout << "Succeed!" << endl;
                
                break; // 退出死循环
            } else {
                // 如果找不到，或者状态为 0，打印提示并等待下一次输入循环
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