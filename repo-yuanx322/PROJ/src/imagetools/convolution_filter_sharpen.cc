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

#include "imagetools/convolution_filter_sharpen.h"
#include <cmath>
#include <algorithm>
#include "imagetools/mask_factory.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

ConvolutionFilterSharpen::ConvolutionFilterSharpen(float radius) {
  r = radius;
}

ConvolutionFilterSharpen::ConvolutionFilterSharpen() {}

ConvolutionFilterSharpen::~ConvolutionFilterSharpen() {}

// create a kernnel with -1 to every point except the middle one
// set the middle one to the number of points in the kernel
FloatMatrix *ConvolutionFilterSharpen::CreateKernel() {
  kernel_ = new FloatMatrix(round(r * 2.0) + 1, round(r * 2.0) + 1);
  for (int j = 0; j < kernel_->height(); j++) {
    for (int i = 0; i < kernel_->width(); i++) {
      int x = i - kernel_->width() / 2;
      int y = j - kernel_->height() / 2;
      float d = sqrt(x * x + y * y);
      float intensity = ImageToolsMath::Gaussian(d, r);
      kernel_->set_value(i, j, intensity);
    }
  }
  kernel_->Normalize();
  kernel_->Scale(-1.0);
  float m = kernel_->value(kernel_->width() / 2, kernel_->height() / 2);
  kernel_->set_value(kernel_->width() / 2, kernel_->height() / 2,
                    m + 2.0);
  return kernel_;
}


}  /* namespace image_tools */
