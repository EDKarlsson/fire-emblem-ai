//
// Created by Erik Karlsson on 5/23/17.
//
#include "ImageProcessor.h"

#define PROCESS_SHOW_IMAGE 1

ImageProcessor::ImageProcessor(std::string imageName)
{
    Mat image = imread("../files/Images/" + imageName, CV_LOAD_IMAGE_GRAYSCALE);
    this->imageName = imageName;

    if (!image.data)
    {
        cout << "Could not open or find image\n";
        return;
    }

    /* Region of interest */
    int  offset_x = 0;
    int  offset_y = 810;
    Rect roi;
    roi.x      = 0;
    roi.y      = 0;
    roi.width  = image.size().width;
    roi.height = image.size().height - (offset_y * 2);

    /* Crop the original image to the defined ROI */
    this->imageObject = image(roi) > 128;
    imwrite("../files/processed/processed_" + imageName, this->imageObject);
#if PROCESS_SHOW_IMAGE
    imshow("crop", this->imageObject);
    waitKey(0);
#endif
}

/* Cropping methods */
cv::Mat ImageProcessor::cropNameFromImage()
{

    /* Region of interest */
    Rect roi;
    roi.x      = 350;
    roi.y      = 25;
    roi.width  = 200;
    roi.height = 40;

    /* Crop the original image to the defined ROI */
    Mat nameLabel = imageObject(roi);

    imwrite("../files/processed/processed_name_" + imageName, nameLabel);
    return nameLabel;
}

std::string ImageProcessor::processNameImage()
{
    Mat                    nameMat = cropNameFromImage();
    tesseract::TessBaseAPI *api    = new tesseract::TessBaseAPI();

    if(api->Init(nullptr, "eng"))
    {
        cerr << "Could not initialize tesseract.\n";
        exit(1);
    }
    
    PIX *pixS = pixCreate(nameMat.size().width, nameMat.size().height, 8);

    for (int i = 0; i < nameMat.rows; ++i)
    {
        for (int j = 0; j < nameMat.cols; ++j)
        {
            pixSetPixel(pixS, j, i, (l_uint32) nameMat.at<uchar>(i, j));
        }
    }

    api->SetImage(pixS);
    char *outText = api->GetUTF8Text();

    cout << "OCR  output: \n" << outText;
    api->End();
    delete [] outText;

    pixDestroy(&pixS);

#if PROCESS_SHOW_IMAGE
    imshow("Name Label", nameMat);
    waitKey(0);
#endif
    return "Merp";
}

cv::Mat ImageProcessor::cropHealthFromImage()
{
    /* Region of interest */
    Rect roi;
    roi.x      = 360;
    roi.y      = 100;
    roi.width  = 200;
    roi.height = 60;

    /* Crop the original image to the defined ROI */
    Mat hpLabel = imageObject(roi);

    imwrite("../files/processed/processed_hp_" + imageName, hpLabel);
#if PROCESS_SHOW_IMAGE
    imshow("HP Label", hpLabel);
    waitKey(0);
#endif
    return hpLabel;
}

cv::Mat ImageProcessor::cropRemainingHealthFromImage()
{}

cv::Mat ImageProcessor::cropAtkFromImage()
{}

cv::Mat ImageProcessor::cropDefFromImage()
{}

cv::Mat ImageProcessor::cropResFromImage()
{}

cv::Mat ImageProcessor::cropSpdFromImage()
{}

cv::Mat ImageProcessor::cropWeaponFromImage()
{}

cv::Mat ImageProcessor::cropAssistFromImage()
{}

cv::Mat ImageProcessor::cropSpecialFromImage()
{}

cv::Mat ImageProcessor::cropSlotAFromImage()
{}

cv::Mat ImageProcessor::cropSlotBFromImage()
{}

cv::Mat ImageProcessor::cropSlotCFromImage()
{}

cv::Mat ImageProcessor::cropSealFromImage()
{}
