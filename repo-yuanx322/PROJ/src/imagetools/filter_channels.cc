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

#include "imagetools/filter_channels.h"
#include "imagetools/mask_factory.h"

namespace image_tools {

FilterChannels::FilterChannels(float r, float g, float b) {
  RScale = r;
  GScale = g;
  BScale = b;
}

FilterChannels::FilterChannels() {}

FilterChannels::~FilterChannels() {}

void FilterChannels::SetupFilter() {}

// adjust the color by the scale of color on each pixel
ColorData FilterChannels::CalculateFilteredPixel(const PixelBuffer& buffer,
                                                 int x, int y) {
  ColorData p = buffer.pixel(x, y);
  p.set_red(p.red() * RScale);
  p.set_green(p.green() * GScale);
  p.set_blue(p.blue() * BScale);
  return p;
}

void FilterChannels::CleanupFilter() {}


}  /* namespace image_tools */
