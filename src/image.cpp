/**
 * \file image.cpp
 * \brief type declarations for image buffers
 * \copyright 2015, Juan David Adarve, ANU. See AUTHORS for more details
 * \license 3-clause BSD, see LICENSE for more details
 */

#include <exception>

#include "flowfilter/image.h"

namespace flowfilter {

image_t createImage(const int height, const int width, const std::size_t pixelSize) {

    if(height <= 0) throw std::exception();
    if(width <= 0) throw std::exception();
    if(pixelSize <= 0) throw std::exception();

    // row pitch
    size_t pitch = width*pixelSize;

    // allocate memory
    unsigned char* buffer = new unsigned char[height*pitch];

    // creates image object
    image_t img;
    img.height = height;
    img.width = width;
    img.pitch = pitch;
    img.data = buffer;

    return img;
}


void destroyImage(image_t& image) {

    if(image.data != nullptr) {
        delete image.data;
        image.data = nullptr;
    }
}

}; // namespace flowfilter