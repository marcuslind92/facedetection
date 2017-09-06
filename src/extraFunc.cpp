#include "extraFunc.h"

void printCenterCoord(cv::Point coord) {
    std::cout << coord << std::endl;
}

cv::Rect largerRect(cv::Rect rect1, cv::Rect2d rect2) {
    cv::Rect newRect;

    if (rect1.x < rect2.x) {
        newRect.x = rect1.x;
    }
    else {
        newRect.x = rect2.x;
    }

    if (rect1.y < rect2.y) {
        newRect.y = rect1.y;
    }
    else {
        newRect.y = rect2.y;
    }
    //not done yet, trying to make a large rect that covers both eyes

    return newRect;
}