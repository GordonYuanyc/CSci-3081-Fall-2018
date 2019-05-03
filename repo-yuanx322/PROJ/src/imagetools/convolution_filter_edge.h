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

#ifndef IMAGETOOLS_CONVOLUTION_FILTER_EDGE_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_EDGE_H_

#include "imagetools/convolution_filter.h"
#include <string>
#include "imagetools/color_data.h"
#include "imagetools/float_matrix.h"

namespace image_tools {

/** @brief Implements an edge filter using a 3x3 edge kernel. */
class ConvolutionFilterEdge : public ConvolutionFilter {
 public:
  ConvolutionFilterEdge();
  virtual ~ConvolutionFilterEdge();

  /** CreateKernel() is used to create a kernel that the convolution filter takes
   in. Convolution Filter EdgeDetect create a 3*3 kernel with 8 at middle,
   -1 otherwise */
  FloatMatrix *CreateKernel() override;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_CONVOLUTION_FILTER_EDGE_H_
