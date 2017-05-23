//
// Created by Erik Karlsson on 5/23/17.
//

#ifndef FIRE_EMBLEM_AI_IMAGEPROCESSOR_H
#define FIRE_EMBLEM_AI_IMAGEPROCESSOR_H

// OpenCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>

// Boost
#include <boost/filesystem.hpp>

// tesseract API
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

// STD LIB
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace cv;
using namespace boost::filesystem;

class ImageProcessor
{
    public:
        ImageProcessor(std::string imageName);

        /* Image Processing Methodsd */
        std::string processNameImage();

        int processTotalHealthImage();

        int processRemainingHealthImage();

        int processAtkImage();

        int processDefImage();

        int processResImage();

        int processSpdImage();

    private:
        std::string imageName;
        cv::Mat     imageObject;

        std::string convertMatToPix(cv::Mat image);

        /* Cropping methods */
        cv::Mat cropNameFromImage();

        cv::Mat cropTotalHealthFromImage();

        cv::Mat cropRemainingHealthFromImage();

        cv::Mat cropAtkFromImage();

        cv::Mat cropDefFromImage();

        cv::Mat cropResFromImage();

        cv::Mat cropSpdFromImage();

        cv::Mat cropWeaponFromImage();

        cv::Mat cropAssistFromImage();

        cv::Mat cropSpecialFromImage();

        cv::Mat cropSlotAFromImage();

        cv::Mat cropSlotBFromImage();

        cv::Mat cropSlotCFromImage();

        cv::Mat cropSealFromImage();
};

#endif //FIRE_EMBLEM_AI_IMAGEPROCESSOR_H
