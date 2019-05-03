/** @file */ 

#include <iostream>
#include "imageio/image_manager.h"

using namespace imageio;

/**
 *  @example main.cc
 *  An example of Loading and saving an image.
 */
int main(int argc, char* argv[]) {
  if (argc < 3) {
  	std::cout << "Usage: ./build/image-test test/test.png test.out.png"  << std::endl;
  	exit(0);
  }

  std::string inputFile(argv[1]);
  std::string outputFile(argv[2]);

  /// Load image from file
  Image* image = ImageManager::instance().LoadFromFile(inputFile);

  /// Print out image dimensions
  std::cout << "Width: " << image->Width() << ", Height: " << image->Height() << ", NumChannels: " << image->NumChannels() << std::endl;

  /// Draw red / blue X over loaded image
  for (int f = 0; f < image->Width() && f < image->Height(); f++) {
  	image->Value(f,f,0) = 255;
  	image->Value(f,f,1) = 0;
  	image->Value(f,f,2) = 0;
  	image->Value(f,f,3) = 255;

  	image->Value(f,image->Height()-f,0) = 0;
  	image->Value(f,image->Height()-f,1) = 0;
  	image->Value(f,image->Height()-f,2) = 255;
  	image->Value(f,image->Height()-f,3) = 255;
  }

  /// Save image output
  ImageManager::instance().SaveToFile(outputFile, *image);
  delete image;
}
