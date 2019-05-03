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

#include "imagetools/filter_saturate.h"
#include "imagetools/mask_factory.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

FilterSaturate::FilterSaturate(float value) {
  ratio = value;
}

FilterSaturate::FilterSaturate() {}

FilterSaturate::~FilterSaturate() {}

void FilterSaturate::SetupFilter() {}

// adjust the intensity of color
ColorData FilterSaturate::CalculateFilteredPixel(const PixelBuffer& buffer,
                                                 int x, int y) {
  ColorData p = buffer.pixel(x, y);
  float r_return = ImageToolsMath::Lerp(p.Luminance(), p.red(), ratio);
  float g_return = ImageToolsMath::Lerp(p.Luminance(), p.green(), ratio);
  float b_return = ImageToolsMath::Lerp(p.Luminance(), p.green(), ratio);
  ColorData ReturnP = ColorData(r_return, g_return, b_return);
  return ReturnP;
}

void FilterSaturate::CleanupFilter() {}


}  /* namespace image_tools */
