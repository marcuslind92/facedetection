#include "extraFunc.h"

#include<iostream>

#include <opencv2/opencv.hpp>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    VideoCapture cap;
    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    if (!cap.open(0))
        return 0;

    //load the classifier
    CascadeClassifier face_cascade, eyes_cascade;
    face_cascade.load("C:/opencv/opencv/data/Haarcascades/haarcascade_frontalface_alt2.xml");
    eyes_cascade.load("C:/opencv/opencv/data/Haarcascades/haarcascade_eye_tree_eyeglasses.xml");

    for (;;)
    {
        Mat frame, frame_gray;
        cap >> frame; //size of webcam images: 480x640
        if (frame.empty()) break; // end of video stream

        cvtColor(frame, frame_gray, CV_BGR2GRAY);
        equalizeHist(frame_gray, frame_gray);

        // Detect faces
        std::vector<Rect> faces;
        face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(100, 100));

        // Draw circles on the detected faces
        for (int i = 0; i < faces.size(); i++)
        {
            Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
            ellipse(frame, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 0), 3, 8, 0);

            printCenterCoord(center);

            Mat faceROI = frame_gray(faces[i]);
            std::vector<Rect> eyes;

            //-- In each face, detect eyes
            eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(20, 20));

            for (size_t j = 0; j < eyes.size(); j++)
            {
                Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5);
                int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
                circle(frame, center, radius, Scalar(255, 255, 0), 2, 8, 0);
            }
        }

        cv::namedWindow("webcam");
        moveWindow("webcam", 20, 20);
        imshow("webcam", frame);

        if (waitKey(10) == 27) break; // stop capturing by pressing ESC 
    }



    return 0;
}