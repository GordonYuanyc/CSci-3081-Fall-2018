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

#include "imagetools/filter_quantize.h"
#include <cmath>
#include "imagetools/mask_factory.h"

namespace image_tools {

FilterQuantize::FilterQuantize(int num) {
  num_bins = num;
}

FilterQuantize::FilterQuantize() {}

FilterQuantize::~FilterQuantize() {}

void FilterQuantize::SetupFilter() {}

// adjust the color of each pixel to the nearest bin
ColorData FilterQuantize::CalculateFilteredPixel(const PixelBuffer& buffer,
                                                 int x, int y) {
  ColorData p = buffer.pixel(x, y);
  int num_steps = num_bins - 1;
  if (num_steps > 0) {
    float CurrentRed = round(p.red() * num_steps) / num_steps;
    float CurrentGreen = round(p.green() * num_steps) / num_steps;
    float CurrentBlue = round(p.blue() * num_steps) / num_steps;

    p.set_red(CurrentRed);
    p.set_green(CurrentGreen);
    p.set_blue(CurrentBlue);

    return p;
  } else {
    p.set_red(0.f);
    p.set_green(0.f);
    p.set_blue(0.f);
    return p;
  }
}

void FilterQuantize::CleanupFilter() {}


} /* namespace image_tools */
