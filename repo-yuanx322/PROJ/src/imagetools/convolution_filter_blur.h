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

#ifndef IMAGETOOLS_CONVOLUTION_FILTER_BLUR_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_BLUR_H_

#include "imagetools/convolution_filter.h"
#include <string>
#include "imagetools/color_data.h"
#include "imagetools/float_matrix.h"

namespace image_tools {

/** @brief Implements a blurring filter using a Gaussian kernel (i.e. blurs
  equally in all directions). */
class ConvolutionFilterBlur : public ConvolutionFilter {
 public:
  explicit ConvolutionFilterBlur(float radius);
  ConvolutionFilterBlur();
  virtual ~ConvolutionFilterBlur();
  /** CreateKernel() is used to create a kernel that the convolution filter takes
   in. Convolution Filter Blur use Gaussian Blur to create the kernel */
  FloatMatrix *CreateKernel() override;

 private:
  float r;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_CONVOLUTION_FILTER_BLUR_H_
