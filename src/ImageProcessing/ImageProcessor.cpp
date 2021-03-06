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
    int  offset_x = 250;
    int  offset_y = 2050;
    Rect roi;
    roi.x      = image.size().width / 3 +  80;
    roi.y      = 10;
    roi.width  = image.size().width / 3;
    roi.height = image.size().height - offset_y + 20;

    /* Crop the original image to the defined ROI */
    this->imageObject = image(roi) > 128;
#if PROCESS_SHOW_IMAGE
    imwrite("../files/processed/processed_" + imageName, this->imageObject);
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
    Mat         nameMat = cropNameFromImage();
    std::string outText = convertMatToPix(nameMat);

    cout << "Character Name : " << outText << endl;
#if PROCESS_SHOW_IMAGE
    imshow("Name Label", nameMat);
    waitKey(0);
#endif

    return outText;
}

cv::Mat ImageProcessor::cropTotalHealthFromImage()
{
    /* Region of interest */
    Rect roi;
    roi.x      = 490;
    roi.y      = 100;
    roi.width  = 70;
    roi.height = 60;

    /* Crop the original image to the defined ROI */
    Mat hpLabel = imageObject(roi);

    return hpLabel;
}

int ImageProcessor::processTotalHealthImage()
{
    cv::Mat hpLabel = cropTotalHealthFromImage();
    std::string outText = convertMatToPix(hpLabel);

    cout << "Character Total Health : " << outText << endl;
#if PROCESS_SHOW_IMAGE
    imshow("Health Label", hpLabel);
    waitKey(0);
#endif
    return stoi(outText);
}

cv::Mat ImageProcessor::cropRemainingHealthFromImage()
{
    /* Region of interest */
    Rect roi;
    roi.x      = 350;
    roi.y      = 100;
    roi.width  = 100;
    roi.height = 60;

    /* Crop the original image to the defined ROI */
    Mat hpLabel = imageObject(roi);

    return hpLabel;
}

int ImageProcessor::processRemainingHealthImage()
{
    cv::Mat hpLabel = cropRemainingHealthFromImage();
    std::string outText = convertMatToPix(hpLabel);

    cout << "Character Remaining Health : " << outText << endl;
#if PROCESS_SHOW_IMAGE
    imshow("Health Remaining Label", hpLabel);
    waitKey(0);
#endif
    return stoi(outText);
}

cv::Mat ImageProcessor::cropAtkFromImage()
{
    /* Region of interest */
    Rect roi;
    roi.x      = 340;
    roi.y      = 185;
    roi.width  = 100;
    roi.height =  45;

    /* Crop the original image to the defined ROI */
    Mat atkLabel = imageObject(roi);

    return atkLabel;
}

int ImageProcessor::processAtkImage()
{
    Mat atkLabel = cropAtkFromImage();
    std::string outText = convertMatToPix(atkLabel);
    
    cout << "Character Attack : " << outText.substr(0,2) << endl;
#if PROCESS_SHOW_IMAGE
    imshow("Attack Label", atkLabel);
    waitKey(0);
#endif
    return stoi(outText.substr(0,2));
}

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

std::string ImageProcessor::convertMatToPix(cv::Mat image)
{
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    string                 outText;

    if (api->Init(nullptr, "eng"))
    {
        cerr << "Could not initialize tesseract.\n";
        exit(1);
    }

    PIX *pixS = pixCreate(image.size().width, image.size().height, 8);

    for (int i = 0; i < image.rows; ++i)
    {
        for (int j = 0; j < image.cols; ++j)
        {
            pixSetPixel(pixS, j, i, (l_uint32) image.at<uchar>(i, j));
        }
    }

    api->SetImage(pixS);
    outText = api->GetUTF8Text();

    api->End();

    pixDestroy(&pixS);
    delete api;
    return outText;
}
