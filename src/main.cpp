#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <boost/filesystem.hpp>
#include <iostream>

using namespace std;
using namespace cv;
using namespace boost::filesystem;

int main()
{
    Mat image= imread("../files/Images/Azura_01.png", CV_LOAD_IMAGE_COLOR);

    if (!image.data)
    {
        cout << "Could not open or find image\n";
        return -1;
    }

    /* Region of interest */
    int offset_x = 0;
    int offset_y = 810;
    Rect roi;
    roi.x = 0;
    roi.y = 0;
    roi.width = image.size().width;
    roi.height = image.size().height - (offset_y * 2);

    /* Crop the original image to the defined ROI */
    Mat crop = image(roi);
    imshow("crop", crop);
    waitKey(0);
    
    /*
    namedWindow("Display Window", WINDOW_AUTOSIZE);
    imshow("Display Window", image);
    waitKey(0);
    */
    return 0;
}
