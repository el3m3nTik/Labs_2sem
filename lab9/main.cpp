#include <iostream>
#include <fstream>
#include "BMP.hpp"

int main() {
    BMP image;
    image.Read("in.bmp");

    image.Filter();

    image.Write("out.bmp");

    return 0;
}