#include "lane.h"
#include <cstdlib>
#include <algorithm>

cLane::cLane(int width) {
    for (int i = 0; i < width; i++)
        cars.push_front(rand() % 3 == 0);
    right = rand() % 2;
}

void cLane::Move() {
    if (right) {
        if (rand() % 7 == 1)
            cars.push_front(true);
        else
            cars.push_front(false);
        cars.pop_back();
    }
    else {
        if (rand() % 7 == 1)
            cars.push_back(true);
        else
            cars.push_back(false);
        cars.pop_front();
    }
}

bool cLane::CheckPos(int pos) { return cars[pos]; }
void cLane::ChangeDirection() { right = !right; }
void cLane::ClearCars() { fill(cars.begin(), cars.end(), false); }