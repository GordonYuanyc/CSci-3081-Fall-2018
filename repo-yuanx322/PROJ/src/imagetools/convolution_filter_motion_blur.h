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

#ifndef IMAGETOOLS_CONVOLUTION_FILTER_MOTION_BLUR_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_MOTION_BLUR_H_

#include "imagetools/convolution_filter.h"
#include <string>
#include "imagetools/color_data.h"
#include "imagetools/float_matrix.h"

namespace image_tools {

/** @brief Implements a motion blurring filter.  This is different that a
 blurring filter, which blurs in all directions. A motion blur filter only blurs
 in one direction. */
class ConvolutionFilterMotionBlur : public ConvolutionFilter {
 public:
  enum BlurDir { MBLUR_DIR_N_S, MBLUR_DIR_E_W, MBLUR_DIR_NE_SW,
    MBLUR_DIR_NW_SE };
  ConvolutionFilterMotionBlur(float radius, BlurDir dir);
  ConvolutionFilterMotionBlur();
  virtual ~ConvolutionFilterMotionBlur();

  /** CreateKernel() is used to create a kernel that the convolution filter takes
   in. Convolution Filter Motion Blur create a kernel based on the given
   direction set horizontal middle line or vertical middle line or cross
   line to 1 set other point to 0 use Gaussian Blur to create the kernel */
  FloatMatrix *CreateKernel() override;

 private:
  float r;
  BlurDir s;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_CONVOLUTION_FILTER_MOTION_BLUR_H_
