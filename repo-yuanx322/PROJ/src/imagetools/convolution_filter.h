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

#ifndef IMAGETOOLS_CONVOLUTION_FILTER_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_H_

#include <string>
#include <vector>
#include "imagetools/filter.h"
#include "imagetools/color_data.h"
#include "imagetools/float_matrix.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

/** @brief The base class for filters that use convolution.  These filters
 convolve a kernel with the image by first making a tmp copy of the image
 buffer.
 Then, they loop through each pixel of this copy, centering the kernel on that
 pixel and computing a new color by looking at the original colors of not just
 the current pixel but also its neighbors.  The output is written back to the
 original pixel buffer. */
class ConvolutionFilter : public Filter {
 public:
  ConvolutionFilter();
  virtual ~ConvolutionFilter();

  /** CreateKernel() is used to create a kernel that the convolution filter takes
   in. Different convolution filters have different rules to create the
   kernel. */
  virtual FloatMatrix *CreateKernel() = 0;

  /** SetupFilter() use the function CreateKernel() to create a filter */
  void SetupFilter() override;

  /** CalculateFilteredPixel() use the kernel to adjust the pixel at position
   (x, y) in PixelBuffer */
  ColorData CalculateFilteredPixel(const PixelBuffer& buffer,
                                             int x, int y) override;

  void CleanupFilter() override;

  /** can_calculate_in_place() make sure that all convolution filters use the
   kernel to adjust the ColorData in PixelBuffer */
  bool can_calculate_in_place() override { return false; }

 protected:
  FloatMatrix* kernel_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_CONVOLUTION_FILTER_H_
