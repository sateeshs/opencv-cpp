#include <iostream>
//#include <opencv2/opencv_modules.hpp>
#include <opencv2/opencv.hpp>
//#include "opencv4/opencv2/opencv.hpp"
#if defined(HAVE_OPENCV_CUDACODEC)
#endif
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include <iostream>
using namespace std;
using namespace cv;

std::string get_current_dir()
{
    char buff[FILENAME_MAX]; // create string buffer to hold path
    GetCurrentDir(buff, FILENAME_MAX);
    string current_working_dir(buff);
    return current_working_dir;
}

int main()
{
    cout << get_current_dir() << endl;
    Mat image = imread("arnold_schwarzenegger.jpg");
    if (!image.empty())
    {
        imshow("image", image);
        waitKey();
    }
    else
    {
        cout << "Empty image!" << endl;
    }
    return 0;
}
