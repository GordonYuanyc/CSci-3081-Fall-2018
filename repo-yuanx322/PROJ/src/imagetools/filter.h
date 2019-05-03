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

#ifndef IMAGETOOLS_FILTER_H_
#define IMAGETOOLS_FILTER_H_

#include <string>
#include "imagetools/color_data.h"
#include "imagetools/float_matrix.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

/** @brief The base class for image processing filters that can be used to
 modify a PixelBuffer.  The ApplyToBuffer method implements a template algorithm
 that applies to all filters, and the other methods of the class provide hooks
 for sub-classes to modify specific steps of that algorithm. */
class Filter {
 public:
  Filter();
  virtual ~Filter();

  /** ApplyToBuffer() can apply the filter to the buffer to adjust the pixel */
  void ApplyToBuffer(PixelBuffer* buffer);

  virtual void SetupFilter() = 0;

  /** CalculateFilteredPixel() have different rules for different filters
    this function adjust the ColorData at position (x, y) in PixelBuffer */
  virtual ColorData CalculateFilteredPixel(const PixelBuffer& buffer,
                                            int x, int y) = 0;

  virtual void CleanupFilter() = 0;

  /** can_calculate_in_place() ensures that filters are applied to PixelBuffer
    directly, without creating a kernel */
  virtual bool can_calculate_in_place() { return true; }
};


}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_H_
