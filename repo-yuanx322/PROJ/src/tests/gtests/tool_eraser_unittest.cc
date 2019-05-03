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

#include <math.h>
#include <iostream>
#include "gtest/gtest.h"
#include "imagetools/tool_pen.h"
#include "flashphoto/flashphoto_app.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/color_data.h"
#include "imagetools/filter_threshold.h"
#include "imagetools/filter_saturate.h"
#include "imagetools/filter_channels.h"
#include "imagetools/filter_quantize.h"
#include "imagetools/convolution_filter_blur.h"
#include "imagetools/convolution_filter_edge.h"
#include "imagetools/convolution_filter_motion_blur.h"
#include "imagetools/convolution_filter_sharpen.h"

using image_tools::ToolEraser;

class ToolEraserTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  ToolEraser eraser_;
};

TEST_F(ToolEraserTest, HasCorrectName) {
  EXPECT_EQ(eraser_.name(), "Eraser");
}

TEST_F(ToolEraserTest, HasCorrectMask) {
//  EXPECT_EQ(pen_.CreateMask(1.0), )
  // Get Mask from pen and compare with
  // what it is supposed to be.
}
