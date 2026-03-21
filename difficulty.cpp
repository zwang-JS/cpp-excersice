//构造函数，析构函数，动态内存分配，深拷贝

#include <iostream>
#include <string>

using namespace std;

class Player {
public:
    string name;
    int hp;
    int level;
    int* backpack; // 🎒 指向动态分配的背包内存

    // 1. 🛠️ 构造函数：负责初始化和申请动态内存 (new)
    Player(string p_name) {
        name = p_name;
        hp = 100;
        level = 1;
        backpack = new int[10]; 
        cout << "玩家 [" << name << "] 诞生了！领到了新背包。\n";
    }

    // 2. 👯 拷贝构造函数：负责深拷贝，分配独立内存并复制数据
    Player(const Player& other) {
        name = other.name + " (分身)";
        hp = other.hp;
        level = other.level;
        
        backpack = new int[10]; // 核心一：申请独立的新背包
        for (int i = 0; i < 10; i++) {
            backpack[i] = other.backpack[i]; // 核心二：搬运旧背包的数据
        }
        cout << "玩家 [" << name << "] 的完美分身诞生了！拥有独立的背包。\n";
    }

    // 3. 💥 析构函数：负责清理现场，归还动态内存 (delete)
    ~Player() {
        delete[] backpack; 
        cout << "玩家 [" << name << "] 归还了背包，断开连接...\n";
    }
};

int main() {
    cout << "--- 游戏开始 ---\n";
    Player realArthur("亚瑟");

    cout << "\n--- 发动分身术 ---\n";
    Player fakeArthur = realArthur; // 这里会自动调用拷贝构造函数

    cout << "\n--- 游戏结束，准备退出 ---\n";
    
    return 0; 
    // 💡 注意：当 main 函数结束时，系统会自动清理里面创建的对象！
}