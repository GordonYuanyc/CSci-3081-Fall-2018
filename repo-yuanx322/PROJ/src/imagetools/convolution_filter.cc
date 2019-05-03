/**
 *This file is part of the CSCI-3081W Project Support Code, which was developed
 *at the University of Minnesota.
 *
 *This code is to be used for student coursework.  It is not an open source
 *project.
 *Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
 *Minnesota.
 *
 *Original Author(s) of this File:
 *  Seth Johnson, 2/15/15, University of Minnesota
 *
 *Author(s) of Significant Updates/Modifications to the File:
 *  ...
 */

#include "imagetools/convolution_filter.h"
#include <assert.h>
#include <algorithm>
#include <cmath>
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/float_matrix.h"

namespace image_tools {

ConvolutionFilter::ConvolutionFilter() {}

ConvolutionFilter::~ConvolutionFilter() {}

void ConvolutionFilter::SetupFilter() {
  kernel_ = CreateKernel();
}


ColorData ConvolutionFilter::CalculateFilteredPixel(const PixelBuffer& buffer,
                                                    int x, int y) {
  int w = kernel_->width();
  int h = kernel_->height();
  float RToSet = 0;
  float GToSet = 0;
  float BToSet = 0;
  float AToSet = 1;

  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      int ni = (x - (w - 1) / 2 + i + buffer.width()) % buffer.width();
      int nj = (y - (h - 1) / 2 + j + buffer.height()) % buffer.height();
      ColorData temp = buffer.pixel(ni, nj);
      RToSet += kernel_->value(i, j) * temp.red();
      GToSet += kernel_->value(i, j) * temp.green();
      BToSet += kernel_->value(i, j) * temp.blue();
      AToSet += kernel_->value(i, j) * temp.alpha();
    }
  }

  ColorData new_color = ColorData(RToSet, GToSet, BToSet, AToSet);
  new_color.Clamp();
  return new_color;
}


void ConvolutionFilter::CleanupFilter() {
  delete kernel_;
}

} /* namespace image_tools */
