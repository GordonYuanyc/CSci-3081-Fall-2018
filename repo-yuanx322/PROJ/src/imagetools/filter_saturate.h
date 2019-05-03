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

#ifndef IMAGETOOLS_FILTER_SATURATE_H_
#define IMAGETOOLS_FILTER_SATURATE_H_

#include "imagetools/filter.h"
#include <string>
#include "imagetools/color_data.h"
#include "imagetools/float_matrix.h"

namespace image_tools {

/** @brief Adjusts the saturation or colorfulness of an image. A scale factor of
 1.0 will have no effect.  A scale factor of greater than 1.0 will "turn up" the
 saturation of the image, making it more colorful, and a factor less than 1.0
 will "turn down" the saturation.  A value of 0.0 will convert the image to
 grayscale. */
class FilterSaturate : public Filter {
 public:
  explicit FilterSaturate(float scale);
  FilterSaturate();
  virtual ~FilterSaturate();

  void SetupFilter() override;

  /** CalculateFilteredPixel() can adjust the ColorData in PixelBuffer at
    position (x, y). saturate filter adjust the intensity of color */
  ColorData CalculateFilteredPixel(const PixelBuffer& buffer, int x,
                                   int y) override;
  void CleanupFilter() override;

 private:
  float ratio;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_SATURATE_H_
