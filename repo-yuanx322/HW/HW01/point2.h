// Copyright [2018]
#ifndef HW01_POINT2_H_
#define HW01_POINT2_H_

class Point2 {
 public:
    // CONSTRUCTOR
    Point2();
    Point2(float X, float Y);

    float DistanceBetween(Point2 pt);
    float get_x_position();
    float get_y_position();

 private:
    float PositionX;
    float PositionY;
};

#endif  // HW01_POINT2_H_
/* HWK01_POINT2HWK01_POINT2_CLASSES_H_ */
