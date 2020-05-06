//
// Created by lirui on 2020/4/26.
//
#include <iostream>
#include"Point.h"
#include"polygon.h"
using namespace std;
//output 不作为成员函数
int judge();
int main() {
    int count, key;
    cout << "请输入多边形顶点个数：" << endl;
    cin >> count;
    polygon polygoni(count);
    cout << "输入已完成"<<endl;
    do {
        cout << "1.移动多边形并输出移动后多边形各点坐标" << endl << "2.删除多边形的一点并输出删除后各点坐标" << endl << "3.增加多边形的一点并输出增加后各点的坐标" << endl << "4.删除并释放顶点对象" << endl;
        cout << "请输入将要执行的操作:" << endl;
        cin >> key;
        switch (key) {
            case 1:polygoni.Move(); break;
            case 2:polygoni.RemovePoint(); break;
            case 3:polygoni.InsertPoint(); break;
            case 4: {polygoni.~polygon(); system("pause"); cout << "多边形顶点对象已释放，程序结束。" << endl; } break;
            default:cout << "输入有误，请重新操作。" << endl; break;
        }
    } while (judge() != 0);
}
int judge() {
    system("pause");
    system("cls");
    int x;
    cout << "是否返回菜单?" << endl << "(若是,输入1;不是;输入0)";
    cin >> x;
    if (x != 0 && x != 1) {
        cout << "输入有误,程序将结束。";
        system("pause");
        x = 0;
    }
    else if (x == 0) {
        system("cls");
        cout << "感谢使用，程序已结束。";
    }
    return x;
}