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

#ifndef IMAGETOOLS_FILTER_CHANNELS_H_
#define IMAGETOOLS_FILTER_CHANNELS_H_

#include "imagetools/filter.h"
#include <string>
#include "imagetools/color_data.h"
#include "imagetools/float_matrix.h"

namespace image_tools {

/** @brief Filter one or more of the RGB channels, scaling each by the specified
 amount.  Scale factors of 1.0 have no affect.  Less than 1.0 "turns down" the
 intensity of the corresponding channel, and greater than 1.0 "turns up" the
 intensity.
 */
class FilterChannels : public Filter {
 public:
  FilterChannels(float r, float g, float b);
  FilterChannels();
  virtual ~FilterChannels();

  void SetupFilter() override;

  /** CalculateFilteredPixel() can adjust the ColorData in PixelBuffer at
    position (x, y). channels filter adjust the color by the scale of color
    on each pixel */
  ColorData CalculateFilteredPixel(const PixelBuffer& buffer, int x,
                                   int y) override;
  void CleanupFilter() override;

 private:
  float RScale;
  float GScale;
  float BScale;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_CHANNELS_H_
