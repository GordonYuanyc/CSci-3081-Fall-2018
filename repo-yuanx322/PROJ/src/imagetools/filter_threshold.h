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

#ifndef IMAGETOOLS_FILTER_THRESHOLD_H_
#define IMAGETOOLS_FILTER_THRESHOLD_H_

#include "imagetools/filter.h"
#include <string>
#include "imagetools/color_data.h"
#include "imagetools/float_matrix.h"

namespace image_tools {

/** @brief A threshold filter that converts each pixel of the image to pure
 black
 or white.  First, each pixel is converted to a grayscale value, then the result
 is compared to the cutoff value.  If greater than the cutoff, then the pixel
 is set to white, and if less it is set to black. */
class FilterThreshold : public Filter {
 public:
  explicit FilterThreshold(float value);
  FilterThreshold();
  virtual ~FilterThreshold();

  void SetupFilter() override;

  /** CalculateFilteredPixel() can adjust the ColorData in PixelBuffer at
    position (x, y). thresold filter adjust the color to white or black
    according to the cutoff point */
  ColorData CalculateFilteredPixel(const PixelBuffer& buffer,
                                   int x, int y) override;
  void CleanupFilter() override;

 private:
  float cut_off;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_THRESHOLD_H_
