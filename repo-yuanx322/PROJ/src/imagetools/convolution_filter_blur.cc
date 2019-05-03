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

#include "imagetools/convolution_filter_blur.h"
#include <cmath>
#include <algorithm>
#include "imagetools/mask_factory.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

ConvolutionFilterBlur::ConvolutionFilterBlur(float radius) {
  r = radius;
}

ConvolutionFilterBlur::ConvolutionFilterBlur() {}

ConvolutionFilterBlur::~ConvolutionFilterBlur() {}

// use Gaussian blur to create the kernel
FloatMatrix *ConvolutionFilterBlur::CreateKernel() {
  kernel_ = new FloatMatrix(static_cast<int>(r));
  for (int j = 0; j < kernel_->height(); j++) {
    for (int i = 0; i < kernel_->width(); i++) {
      float distance = sqrt(pow((i - (kernel_->height() + 1) / 2), 2) +\
                            pow((j - (kernel_->width() + 1) / 2), 2));
      float g = ImageToolsMath::Gaussian(distance, r);
      kernel_->set_value(i, j, g);
    }
  }
  kernel_->Normalize();
  return kernel_;
}


}  /* namespace image_tools */
