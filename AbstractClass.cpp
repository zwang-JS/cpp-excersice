#include <iostream>
using namespace std;

// 抽象类
class Animal {
public:
    // 纯虚函数：强制子类实现“叫声”
    virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
    // 子类必须实现父类的纯虚函数，否则 Dog 也是抽象类
    void makeSound() override {
        cout << "汪汪！" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "喵喵~" << endl;
    }
};

int main() {
    // Animal a; // ❌ 报错：抽象类不能创建对象
    
    Animal* ptr1 = new Dog(); // ✅ 虽然不能创建对象，但可以定义指针
    Animal* ptr2 = new Cat();
    
    ptr1->makeSound(); // 输出：汪汪！
    ptr2->makeSound(); // 输出：喵喵~
    
    delete ptr1;
    delete ptr2;
    return 0;
}