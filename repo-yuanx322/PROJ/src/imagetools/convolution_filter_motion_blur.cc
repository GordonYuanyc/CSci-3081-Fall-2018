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

#include "imagetools/convolution_filter_motion_blur.h"
#include <cmath>
#include <algorithm>
#include <string>
#include "imagetools/mask_factory.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

ConvolutionFilterMotionBlur::ConvolutionFilterMotionBlur(float radius,
                                                         BlurDir dir) {
  r = radius;
  s = dir;
}

ConvolutionFilterMotionBlur::ConvolutionFilterMotionBlur() {}

ConvolutionFilterMotionBlur::~ConvolutionFilterMotionBlur() {}

// create a kernel based on the given direction
// set horizontal middle line or vertical middle line or cross line to 1
// set other point to 0
FloatMatrix *ConvolutionFilterMotionBlur::CreateKernel() {
  kernel_ = new FloatMatrix(static_cast<int>(r));

  for (int j = 0; j < kernel_->height(); j++) {
    for (int i = 0; i < kernel_->width(); i++) {
      kernel_->set_value(i, j, 0.f);
    }
  }

  if (s == MBLUR_DIR_N_S) {
    for (int i = 0; i < kernel_->height(); i++) {
      kernel_->set_value((r + 1) / 2, i, 1.f);
    }
  } else if (s == MBLUR_DIR_E_W) {
    for (int i = 0; i < kernel_->width(); i++) {
      kernel_->set_value(i, (r + 1) / 2, 1.f);
    }
  } else if (s == MBLUR_DIR_NW_SE) {
    for (int i = 0; i < kernel_->height(); i++) {
      kernel_->set_value(i, i, 1.f);
    }
  } else {
    for (int i = 0; i < kernel_->height(); i++) {
      kernel_->set_value(r - i, i, 1.f);
    }
  }

  kernel_->Normalize();
  return kernel_;
}


}  /* namespace image_tools */
