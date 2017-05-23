#include "ImageProcessor.h"

int main()
{
    ImageProcessor im("Azura_01.png");
    im.processNameImage();
    im.processTotalHealthImage();
    im.processRemainingHealthImage();
    return 0;
}
