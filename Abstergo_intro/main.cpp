#include<iostream>
using namespace std;

#include<opencv2/highgui/highgui.hpp>       //displays images and gui
#include<opencv2/imgproc/imgproc.hpp>       //does main image processing

using namespace cv;

int main()
{
    Mat img,img1;
    VideoCapture cam(0);
    if(!cam.isOpened())
    {
        cout<<"Camera not Open"<<endl;
        return 0;
    }
    while(1)
    {
        if(!cam.read(img))
        {
            cout<<"No image Read"<<endl;
            continue;
        }
        flip(img,img1,1);
        imshow("Frame",img1);
        if(waitKey(10)==27)
            break;
    }
    return 0;
}

