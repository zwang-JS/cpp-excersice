#include <iostream>
using namespace std;

// 这里的 a[][3] 表示这是一个列数为3的二维数组
void sort2D(int a[][3]) {
    int rows = 3; // 总共有3行
    int n = 3;    // 每行有3个元素 (相当于你例子中的 s.length())

    // 第一层循环：遍历每一行 (i 代表行号)
    for (int i = 0; i < rows; i++) {
        
        // -------------------------------------------------------
        // 下面这部分就是完全套用你的 sortString 逻辑
        // 只是把 s[x] 换成了 a[i][x] (表示第 i 行的第 x 个元素)
        // -------------------------------------------------------
        
        // 冒泡排序外层：控制轮数
        for (int j = 0; j < n - 1; j++) {
            // 冒泡排序内层：执行比较和交换
            for (int k = 0; k < n - j - 1; k++) {
                // 如果前一个比后一个大，就交换
                if (a[i][k] > a[i][k + 1]) {
                    int temp = a[i][k];
                    a[i][k] = a[i][k + 1];
                    a[i][k + 1] = temp;
                }
            }
        }
    }
}

int main() {
    int a[3][3] = {0}; // 初始化

    // 输入部分
    cout << "请输入 9 个数字 (3x3):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    // 调用排序
    sort2D(a);

    // 输出验证一下结果
    cout << "按行排序后的结果:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}