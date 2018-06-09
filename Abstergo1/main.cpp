#include<iostream>
using namespace std;

#include<opencv2/highgui/highgui.hpp>       //displays images and gui
#include<opencv2/imgproc/imgproc.hpp>       //does main image processing

using namespace cv;

int main()
{
    Mat img,gray,thr,blur;
    int thresh=128,blursize=1;
    VideoCapture cam(0);
    if(!cam.isOpened())
    {
        cout<<"Camera not Open"<<endl;
        return 0;
    }
    namedWindow("Trackbars");
    createTrackbar("Threshold","Trackbars",&thresh,255,NULL);
    createTrackbar("blursize","Trackbars",&blursize,20,NULL);
    while(1)
    {
        if (waitKey(10)==27)
            break;
        if(!cam.read(img))
        {
            cout<<"No image Read"<<endl;
            continue;
        }
        imshow("Frame",img);

        cvtColor(img,gray,CV_BGR2GRAY);     //RGB to grayscale
        imshow("grayscale",gray);

        threshold(gray,thr,thresh,255,CV_THRESH_BINARY);        //thresholding
        imshow("Threshold",thr);

        medianBlur(thr,blur,blursize*2+1);       //blurring
        imshow("MedianBlur",blur);
    }
    return 0;
}

