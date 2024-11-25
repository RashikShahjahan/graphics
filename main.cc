#include <iostream>

int main(){
    int w = 256;
    int h = 256;

    std::cout << "P3\n" << w << ' ' << h << '\n' << "\n255\n";

    for(int i =0;i<h;i++){
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for(int j =0;j<w;j++){
            auto r = double(j) / (w-1);
            auto g = double(i) / (h-1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';    }   
        }

    std::clog << "\rDone.                 \n";
}

