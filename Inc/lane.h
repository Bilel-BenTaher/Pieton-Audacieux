#ifndef LANE_H
#define LANE_H

#include <deque>

class cLane {
private:
    std::deque<bool> cars;
    bool right;
public:
    cLane(int width);
    void Move();
    bool CheckPos(int pos);
    void ChangeDirection();
    void ClearCars();
};

#endif