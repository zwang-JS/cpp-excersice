#include <iostream>
using namespace std;

int main() {
    int n;
    int a[10][10]; // 题目说明最大 size 为 10 [cite: 33]

    cout << "Please input the size of the matrix:" << endl;
    cin >> n;
    cout << "Please input the matrix row by row:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "The clockwise spiral form of the matrix is:" << endl; // 匹配输出格式 [cite: 41, 50]

    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // 1. 从左向右 (Top row)
        for (int i = left; i <= right; i++)
            cout << a[top][i] << " ";
        top++;

        // 2. 从上向下 (Right column)
        for (int i = top; i <= bottom; i++)
            cout << a[i][right] << " ";
        right--;

        // 3. 从右向左 (Bottom row) - 必须检查是否还有行可走
        if (top <= bottom) {
            for (int i = right; i >= left; i--) // 注意这里是 i--
                cout << a[bottom][i] << " ";
            bottom--;
        }

        // 4. 从下向上 (Left column) - 必须检查是否还有列可走
        if (left <= right) {
            for (int i = bottom; i >= top; i--) // 注意这里是 i--
                cout << a[i][left] << " ";
            left++;
        }
    }
    cout << endl;

    return 0;
}