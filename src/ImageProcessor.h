//
// Created by Erik Karlsson on 5/23/17.
//

#ifndef FIRE_EMBLEM_AI_IMAGEPROCESSOR_H
#define FIRE_EMBLEM_AI_IMAGEPROCESSOR_H

#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <boost/filesystem.hpp>

class ImageProcessor
{
    public:
        ImageProcessor(std::string imageName);

        cv::Mat cropNameFromImage();
        cv::Mat cropHealthFromImage();
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

    private:
        std::string imageName;
        cv::Mat     image;
};

#endif //FIRE_EMBLEM_AI_IMAGEPROCESSOR_H
