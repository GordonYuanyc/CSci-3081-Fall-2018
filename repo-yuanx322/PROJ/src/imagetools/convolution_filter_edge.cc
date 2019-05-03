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

#include "imagetools/convolution_filter_edge.h"
#include <cmath>
#include <algorithm>
#include "imagetools/mask_factory.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

ConvolutionFilterEdge::ConvolutionFilterEdge() {}

ConvolutionFilterEdge::~ConvolutionFilterEdge() {}

// create a 3*3 kernel with 8 at middle, -1 otherwise
FloatMatrix *ConvolutionFilterEdge::CreateKernel() {
  kernel_ = new FloatMatrix(1);
  for (int i = 0; i < kernel_->width(); i++) {
    for (int j = 0; j < kernel_->height(); j++) {
      if (i == 1 && j == 1) {
        kernel_->set_value(i, j, 8.0);
      } else {
        kernel_->set_value(i, j, -1.0);
      }
    }
  }
  return kernel_;
}


}  /* namespace image_tools */
