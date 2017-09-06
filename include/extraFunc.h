#pragma once
#include <opencv2/opencv.hpp>

void printCenterCoord(cv::Point coord);

cv::Rect largerRect(cv::Rect rect1, cv::Rect2d rect2);