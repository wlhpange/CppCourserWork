//
// Created by lirui on 2020/4/26.
//
#include <iostream>
#ifndef CPP1_POINT_H
#define CPP1_POINT_H
//class Point
class Point {
public:
    Point* next;
    Point(float x, float y) :xpoint(x), ypoint(y), next(NULL) {}
    float xpoint;
    float ypoint;
};
#endif //CPP1_POINT_H
