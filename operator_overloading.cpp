#include <iostream>
#include <string>

using namespace std;

class Candy {
private:
    string name;
    double price;
    int amount;

public:
    Candy() : name(""), price(0), amount(0) {} // 初始化列表写法

    // 重载输出运算符 <<
    friend ostream& operator<<(ostream& os, const Candy& c) {
        os << "Name: " << c.name << ", Price: " << c.price << ", Amount: " << c.amount;
        return os;
    }

    // 重载输入运算符 >>
    friend istream& operator>>(istream& is, Candy& c) {
        // 注意：这里可以添加一些提示，但通常标准的 >> 只负责读取数据
        is >> c.name >> c.price >> c.amount;
        return is;
    }
};

int main() {
    Candy myCandy;
    
    cout << "请输入糖果的名字、价格和数量（用空格隔开）: ";
    // 此时直接调用了重载的 >> 运算符
    cin >> myCandy; 
    
    // 此时直接调用了重载的 << 运算符
    cout << "你输入的糖果信息是: \n" << myCandy << endl; 

    return 0;
}