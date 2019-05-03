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

#include "imagetools/filter_threshold.h"
#include "imagetools/mask_factory.h"

namespace image_tools {

FilterThreshold::FilterThreshold(float value) {
  cut_off = value;
}

FilterThreshold::FilterThreshold() {}

FilterThreshold::~FilterThreshold() {}

void FilterThreshold::SetupFilter() {}

// adjust the color to white or black according to the cutoff point
ColorData FilterThreshold::CalculateFilteredPixel(const PixelBuffer& buffer,
                                                  int x, int y) {
  ColorData p = buffer.pixel(x, y);
  float f = (p.red() + p.green() + p.blue()) / 3;
  if (f >= cut_off) {
    p.set_red(1.f);
    p.set_green(1.f);
    p.set_blue(1.f);
  } else {
    p.set_red(0.f);
    p.set_green(0.f);
    p.set_blue(0.f);
  }
  return p;
}

void FilterThreshold::CleanupFilter() {}


}  /* namespace image_tools */
