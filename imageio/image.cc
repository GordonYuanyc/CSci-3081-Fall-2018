#include "imageio/image.h"

namespace imageio {

Image::Image(int width, int height, int numChannels) : width_(width), height_(height), numChannels_(numChannels) {
	if (width_*height_*numChannels_ > 0) {
		pixelBuffer_ = new unsigned char[width_*height_*numChannels_];
	}
	else {
		pixelBuffer_ = 0;
	}
}

Image::~Image() {
	if (pixelBuffer_) {
		delete[] pixelBuffer_;
	}
}

const unsigned char* Image::Pixels() const {
	return pixelBuffer_;
};

unsigned char* Image::Pixels() {
	return pixelBuffer_ ;
}

unsigned char* Image::Pixel(int x, int y) {
	return &pixelBuffer_[(y*width_+x)*numChannels_]; 
}

unsigned char& Image::Value(int x, int y, int channel) {
	return pixelBuffer_[(y*width_+x)*numChannels_ + channel]; 
}

float Image::FloatValue(int x, int y, int channel) {
	return static_cast<float>(Value(x, y, channel) / 255.0f);
}

void Image::SetFloatValue(int x, int y, int channel, float value) {
	Value(x, y, channel) = static_cast<unsigned char>(255.0f * value);
}

}
