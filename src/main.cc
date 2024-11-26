#include <iostream>
#include "color.h"
#include "vec3.h"

int main(){
    int w = 256;
    int h = 256;

    std::cout << "P3\n" << w << ' ' << h << '\n' << "\n255\n";

    for(int i =0;i<h;i++){
        for(int j =0;j<w;j++){
            std::clog << "\rScanlines remaining: " << (h - j) << ' ' << std::flush;

            auto r = float(j) / (w-1);
            auto g = float(i) / (h-1);
            auto b = 0.0;

            auto pixel_color = color(r,g,b);
            write_color(std::cout,pixel_color);
        }

    std::clog << "\rDone.                 \n";
}

}