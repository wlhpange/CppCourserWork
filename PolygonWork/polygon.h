//
// Created by lirui on 2020/4/26.
//
#include <iostream>
#include"Point.h"
using namespace std;
#ifndef CPP1_POLYGON_H
#define CPP1_POLYGON_H
void output(Point* h) {
    cout << "此时多边形各个顶点坐标为：" << endl;
    Point* m = h;
    while (m != nullptr)
    {
        cout << m->xpoint << "," << m->ypoint << endl;
        m = m->next;
    }
}
class polygon {
public:
    polygon(int c) :count(c) { input(); }
    Point input()//动态输入坐标
    {
        cout << "请输入第1组坐标" << endl;
        int x, y;
        cin >> x >> y;
        h = new Point(x, y);
        Point* p = h;
        for (int i = 1; i < count; i++) {
            cout << "请输入第" << i + 1 << "组坐标" << endl;
            cin >> x >> y;
            Point* q = new Point(x, y);
            p->next = q;
            p = p->next;
        }
        return *h;
    }
    ~polygon() {
        delete h;
    };//在多边形的析构函数中删除和释放顶点对象；
    void Move()//位置的整体移动，并输出各个顶点的新位置
    {
        system("cls");
        int xmove, ymove;
        cout << "请输入你想移动的数量：(支持正负数输入）" << endl << "x:" << endl; cin >> xmove; cout << "y:" << endl; cin >> ymove;
        Point* m = h;
        while (m != nullptr)
        {
            m->xpoint = m->xpoint + xmove;
            m->ypoint = m->ypoint + ymove;
            m = m->next;
        }
        output(h);
    }
    Point InsertPoint(){system("cls");
        int x, y;
        cout << "请输入你想增加的点的坐标" << endl << "x:"; cin >> x; cout << endl << "y:"; cin >> y;
        Point* m = h;
        Point* addpoint = new Point(x, y);
        while (m->next != nullptr) { m = m->next; }
        m->next = addpoint;
        output(h);
        return*h;}//动态增加顶点，并输出更改后的顶点列表；
    Point RemovePoint(){
        system("cls");
        int x, y;
        cout << "请输入你想删除的点的坐标" << endl << "x:"; cin >> x; cout << endl << "y:"; cin >> y;
        Point* m = h;
        if (m->xpoint == x && m->ypoint == y)//head node judgement
        {
            h = m->next;
            delete m;
            return *h;
        }
        else {
            while (m->next != nullptr && m->next->xpoint != x && m->next->ypoint != y)
            {
                m = m->next;
            }
            if (m->next == nullptr) { return*h; }
            else {
                Point* deletepoint = m->next;
                m->next = deletepoint->next;
                delete deletepoint;

            }
        }
        output(h);
        return *h;
    }//删除顶点，并输出顶点列表
private:
    int count;
    Point* h;
};
#endif //CPP1_POLYGON_H
