// Copyright [2018]
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>

#include "/home/yuanx322/csci3081/3081_F18/repo-yuanx322/HW/HW01/point2.h"

using std::cout;
using std::endl;

Point2::Point2() {
  PositionX = 0;
  PositionY = 0;
}

Point2::Point2(float X, float Y ) {
  PositionX = X;
  PositionY = Y;
}

float Point2::DistanceBetween(Point2 pt) {
  float DX = PositionX - pt.get_x_position();
  float DY = PositionY - pt.get_y_position();
  float Distance = sqrt(DX * DX + DY * DY);
  return Distance;
}

float Point2::get_x_position() {
  return PositionX;
}

float Point2::get_y_position() {
  return PositionY;
}
