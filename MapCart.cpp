#include "MapCart.h"
#include <cstdio>
#include "bitmap_image.hpp"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;


MapCart::MapCart(string filename_in): image(filename_in),
        output_image_bit(image.width(),image.height()),
        output_image_byte(image.width(),image.height()),
        output_image_half(image.width(),image.height()),
        output_image_shape(image.width(),image.height()){
    if (!image){
            printf("Error - Failed to open: input.bmp\n");
    }
    else{
            fout.open("images_out/output_imagetxt_test_0.txt", ios_base::out);
            printf("Image import - ok!");
            height = image.height();
            width  = image.width();
    }

}

MapCart::~MapCart(){
    fout.close();
}

void MapCart::get_half_image(float count){
    if(int(width) % int(count)==0 && int(height) % int(count)==0){
        float ci = width/count;
        float cj = height/count;
        float mid, r, red, blue, green, new_red, new_blue, new_green;
        for(float i=0;i<width;i+=ci){
            for(float j=0;j<height;j+=cj){
                for (float x=i; x < ci+i; ++x){
                    new_red = 0;
                    new_green = 0;
                    new_blue = 0;
                    for (float y = j; y < cj+j; ++y){
                        image.get_pixel(x, y, colour);
                        red = colour.red;
                        blue = colour.blue;
                        green = colour.green;
                        new_red = ((red+new_red)/2);
                        new_green = ((green+new_green)/2);
                        new_blue = ((blue+new_blue)/2);
                        new_red = red;
                        new_blue = blue;
                        new_green = green;
                    }
                }
                for (float x=i; x < ci+i; ++x){
                    for(float y = j;y < cj+j; ++y){
                        output_image_half.set_pixel(x,y,new_red,new_green,new_blue);
                    }
                }
            }
        }
        
        output_image_half.save_image("images_out/output_imagehalf_test_0.bmp");
    }
    count += 1;
}

void MapCart::get_bit_image(float percent){
        float balance;
        balance = (255.0/100.0)*percent;
        cout << balance << endl;
        float mid, r, red, blue, green;
        for (size_t x = 0; x < width; ++x){
            for (size_t y = 0; y < height; ++y){
                image.get_pixel(x, y, colour);
                red = colour.red;
                blue = colour.blue;
                green = colour.green;
                mid = (red+green+blue)/3;
                if(mid<=balance){
                    red = 0;
                    green = 0;
                    blue = 0;
                }
                else{
                    red = 255;
                    green = 255;
                    blue = 255;
                }
                mid = mid*0.3;
                output_image_bit.set_pixel(x,y,red,green,blue);
                output_image_byte.set_pixel(x,y,mid,mid,mid);
            }
        }
        output_image_bit.save_image("images_out/output_imagebit_test_0.bmp");
        output_image_byte.save_image("images_out/output_imagebyte_test_0.bmp");
    }

void MapCart::get_shape(){
    rgb_t neigh;
    int nei_r,nei_g,nei_b;
    int ar[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    float mid_r,mid_g,mid_b, r, red, blue, green;
    for (size_t x = 1; x < width-1; ++x){
        for (size_t y = 1; y < height-1; ++y){
            output_image_byte.get_pixel(x, y, colour);
            mid_r = colour.red;
            mid_g = colour.green;
            mid_b = colour.blue;
            for(int i=0;i<4;i++){
                output_image_byte.get_pixel(x+ar[i][0], y+ar[i][1], neigh);
                nei_r = neigh.red;
                nei_g = neigh.green;
                nei_b = neigh.blue;
                if(abs(nei_r-mid_r)>1 && nei_r != 255 && nei_g != 0 && nei_b != 0){
                    output_image_shape.set_pixel(x+ar[i][0], y+ar[i][1],255,0,0);
                }
                
            }
            output_image_shape.set_pixel(x, y,127,127,127);
            
        }
    }
    output_image_shape.save_image("images_out/output_imageshape_test_0.bmp");
}

void MapCart::get_txt(float count){
    cout << 1 << endl;
    float ci = width/count;
    float cj = height/count;
    int mid, index;
    float r, red, blue, green, new_red, new_blue, new_green;
    for(float i=0;i<height;i+=ci){
            for(float j=0;j<width;j+=cj){
            for (float x=j; x < cj+j; ++x){
                new_red = 0;
                new_green = 0;
                new_blue = 0;
                for (float y = i; y < ci+i; ++y){
                    image.get_pixel(x, y, colour);
                    red = colour.red;
                    blue = colour.blue;
                    green = colour.green;
                    new_red = ((red+new_red)/2);
                    new_green = ((green+new_green)/2);
                    new_blue = ((blue+new_blue)/2);
                    new_red = red;
                    new_blue = blue;
                    new_green = green;
                }
            }
            mid = (new_blue + new_red + new_green) / 3;
            index = mid/25;
            fout << asci[index] << asci[index];
            }
            fout << endl;
        }
}