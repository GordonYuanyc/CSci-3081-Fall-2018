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

#include "imagetools/tool_blur.h"
#include "imagetools/mask_factory.h"
#include "imagetools/convolution_filter.h"
#include "imagetools/convolution_filter_blur.h"

namespace image_tools {

ToolBlur::ToolBlur() {
  b_filter = new ConvolutionFilterBlur(5.0);
  b_filter->SetupFilter();
  // setup your blur filter to use a radius of 5.0 here

  // the blur operation is not fast, so space the repeated applications of the
  // stamp out as far as we can get away with while still having it look good
  // 1/3 overlap is pretty good for this.
  stamp_overlap_ = 0.333;
}

ToolBlur::~ToolBlur() {
  delete b_filter;
}

FloatMatrix* ToolBlur::CreateMask(float radius) {
  return MaskFactory::CreateLinearFalloffMask(radius);
}

ColorData ToolBlur::LookupPaintColor(int x, int y) {
  // here's your hook to calculate a filtered version of the
  // pixel. Use your filter to compute the blurred version of the pixel at (x,y)
  // in *buffer_ and return the new color to make this tool work.
  ColorData np = b_filter->CalculateFilteredPixel(*buffer_, x, y);
  buffer_->set_pixel(x, y, np);
  // Remove this:  As a placeholder, we're just returning the original pixel
  // color for now.
  return buffer_->pixel(x, y);
}

} /* namespace image_tools */
