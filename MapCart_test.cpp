/*
 ******************************************************************************************
 * Author: Artem Bielov.                                                                  *
 * Bitmap image interpratator.                                                            *
 * Note: support only 24-bit bitmap image!                                                *
 * Functions: Image -> .txt                      - mapcart.get_txt(float size);           *
 *            Image -> bit image(visualisation)  - mapcart.get_bit_image(float percent);  *
 *            Image -> byte image(visualisation) - mapcart.get_bit_image(float percent);  *
 *            Shapes in image                    - mapcart.get_shape();                   *
 *            Pixel image                        - mapcart.get_half_image(float count)    *
 *                                                                                        *
 *                                                                                        *
 * V.1.0                                                                                  *
 ******************************************************************************************
*/

#include "MapCart.h"
using namespace std;

const string filename = "MapCart_test_0.bmp";

int main(){
    MapCart mapcart(filename);
    mapcart.get_bit_image(50);
    mapcart.get_half_image(4);
    mapcart.get_txt(126);
    mapcart.get_shape();
    return 0;
}