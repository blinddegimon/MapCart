#ifndef MAPCART_H
#define MAPCART_H
#include <string>
#include "bitmap_image.hpp"

using namespace std;


class MapCart{
private:
    ofstream fout;
    string asci = "@8#?|!=+-,.";    
    string filename;
    bitmap_image image;
    bitmap_image output_image_bit;
    bitmap_image output_image_byte;
    bitmap_image output_image_half;
    bitmap_image output_image_shape;
    float height;
    float width;
    int max_c;
    rgb_t colour;
public:
    MapCart(string filename_in): image(filename_in),
        output_image_bit(image.width(),image.height()),
        output_image_byte(image.width(),image.height()),
        output_image_half(image.width(),image.height()),
        output_image_shape(image.width(),image.height()){}
    ~MapCart(){}
    void get_bit_image(float percent);
    void get_half_image(float count);
    void get_shape();
    void get_txt(float count);
};

#endif