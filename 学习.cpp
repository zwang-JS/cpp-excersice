//   万能头文件：#include<bits/stdc++.h>
//   有一个已知：#include<iostream>
//   把这个放头文件下面：using namespace std;
//   1.23e2=1.23*10**2=123

/*
函数主体:    int main(){
                代码在这里;
                return 0;
             }
*/

/*
不写 using namespace std; 时，必须显式写 std::cout std::cin std::endl
推荐：小型程序用 using namespace std;，大型项目显式指定 std::
*/

/*    换行
  cout << "Hello World! \n";
  cout << "I am learning C++";

  cout << "Hello World! \n\n";
  cout << "I am learning C++";

  cout << "Hello World!" << endl;
  cout << "I am learning C++";
*/ 

/*  赋值并输出
    int myNum = 15;
    std::cout << myNum;  
*/

/*   定义变量为空值，赋值，输出
    int myNum;
    myNum = 15;
    cout << myNum;
*/

/*   定义变量后再修改变量
    int myNum = 15;
    myNum = 10;  
    cout << myNum;  
*/

/*  定义数据的类型
    int myNum = 5;          // 整型：存储整数
    double myFloatNum = 5.99; // 双精度浮点型：类似python中的float  注意cpp中也有float，double的精度更高
    char myLetter = 'D';    // 字符型：存储单个字符
    string myText = "Hello";// 字符串型：存储字符串  若要用char来定义字符串，则需在变量名前加*或在变量明后加[]
    bool myBoolean = true;  // 布尔型：存储true/false
*/

/*  数据拼接（字符串加整数）
    法一：
    int myAge = 35;
    cout << "I am " << myAge << " years old.";
    法二：
    string s1 = "Hello";
    string s2 = "World";
    string result = s1 + " " + s2;   结果就是 "Hello World"
*/

/*运算符<<
<<在做运算符时表示二进制左移两位，>>表示二进制右移两位
*/

/*
    int x = 5;
    int y = 6;
    int sum = x + y;
    cout << sum;
*/

/*
    int x = 5, y = 6, z = 50;
    cout << x + y + z;
*/

/*  定义变量前加上const，就相当于使变量固定 
    const int minutesPerHour = 60; 
    const float PI = 3.14; 
*/

/*
    int x;
    cout << "Type a number: ";          // 提示用户输入
    cin >> x;                           // 获取用户从键盘输入的整数
    cout << "Your number is: " << x;    // 输出用户输入的值
*/

/*
    int x, y;
    int sum;
    cout << "Type a number: ";
    cin >> x;
    cout << "Type another number: ";
    cin >> y;
    sum = x + y;
    cout << "Sum is: " << sum;
*/

/*  确认精度，会自动四舍五入
#include <iostream>
#include <iomanip>  // 必须引入：setprecision依赖的头文件
using namespace std;

int main() {
    double num = 3.14159;
    cout << fixed << setprecision(2) << num;  // 输出结果：3.14
    return 0;
}
*/

/*  连续输入要用空格或空行分隔
int main() {
    // 3个盒子（变量），可存整数/小数
    double var1, var2, var3;

    // 连续输入：空格/回车分隔，一次性填3个盒子
    cout << "请输入3个带小数的数字（空格分隔）：";
    cin >> var1 >> var2 >> var3;

    cout << "变量1：" << var1 << endl;
    cout << "变量2：" << var2 << endl;
    cout << "变量3：" << var3 << endl;

    return 0;
}
*/

/*  手动升降级操作 promotion&demotion
    写法：在数值或变量前面加上 (类型名)。
    例如：(int) 3.14 会强行把 3.14 变成整数 3。
*/