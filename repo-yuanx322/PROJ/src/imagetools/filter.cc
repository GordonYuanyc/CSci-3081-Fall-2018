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

#include "imagetools/filter.h"
#include <assert.h>
#include <algorithm>
#include <cmath>
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

Filter::Filter() {}

Filter::~Filter() {}

void Filter::ApplyToBuffer(PixelBuffer* buffer) {
  // simple filters CAN calulate in place
  if (can_calculate_in_place()) {
    for (int i = 0; i < buffer->width(); i++) {
      for (int j = 0; j < buffer->height(); j++) {
        ColorData new_color = CalculateFilteredPixel(*buffer, i, j);
        buffer->set_pixel(i, j, new_color);
      }
    }
  } else {  // convolution filters CANNOT calculate in place
    // have to make a copy of PixelBuffer
    PixelBuffer* copy = new PixelBuffer(*buffer);
    SetupFilter();
    for (int i = 0; i < buffer->width(); i++) {
      for (int j = 0; j < buffer->height(); j++) {
        ColorData new_color = CalculateFilteredPixel(*copy, i, j);
        buffer->set_pixel(i, j, new_color);
      }
    }
    CleanupFilter();

    // remember to delete the dynamically allocated copy
    delete copy;
  }
}


} /* namespace image_tools */
