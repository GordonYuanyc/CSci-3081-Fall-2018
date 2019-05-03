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

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>
#include <utility>
#include <string>
#include <deque>
#include "gtest/gtest.h"
#include "mia/command_line_processor.h"
#include "flashphoto/flashphoto_app.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/image_editor.h"
#include "imagetools/color_data.h"

using image_tools::CommandLineProcessor;
using image_tools::ImageEditorCommand;
using image_tools::ImageEditor;

class RegressionTest : public ::testing::Test {
 public:
  void SetUp() override {
    sample = new ImageEditor();
    sample->set_pixel_buffer(new image_tools::PixelBuffer(500, 500,
      image_tools::ColorData(1.f, 1.f, 1.f)));
    new_output = new ImageEditor();
    sample->set_pixel_buffer(new image_tools::PixelBuffer(500, 500,
      image_tools::ColorData(1.f, 1.f, 1.f)));
  }
 protected:
  ImageEditor *sample;
  ImageEditor *new_output;
};

TEST_F(RegressionTest, BlurFilterTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/blur_5_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->ApplyBlurFilter(5.0);
  new_output->SaveToFile("./resources/blur_5_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/blur_5_test.png");
  EXPECT_EQ(*test, *expected) << "BlurFilter has different result";
}

TEST_F(RegressionTest, EdgeDetectFilterTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/edge_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->ApplyEdgeDetectFilter();
  new_output->SaveToFile("./resources/edge_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/edge_test.png");
  EXPECT_EQ(*test, *expected) << "EdgeDetectFilter has different result";
}

TEST_F(RegressionTest, SharpenFilterTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/sharpen_5_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->ApplySharpenFilter(5.0);
  new_output->SaveToFile("./resources/sharpen_5_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/sharpen_5_test.png");
  EXPECT_EQ(*test, *expected) << "SharpenFilter has different result";
}

TEST_F(RegressionTest, ThresholdFilterTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/threshold_5_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->ApplyThresholdFilter(0.5);
  new_output->SaveToFile("./resources/threshold_5_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/threshold_5_test.png");
  EXPECT_EQ(*test, *expected) << "ThresholdFilter has different result";
}

TEST_F(RegressionTest, SaturateFilterTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/saturate_5_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->ApplySaturateFilter(5.0);
  new_output->SaveToFile("./resources/saturate_5_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/saturate_5_test.png");
  EXPECT_EQ(*test, *expected) << "SaturateFilter has different result";
}

TEST_F(RegressionTest, RedChannelFilterTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/red_channel_5_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->ApplyChannelsFilter(5.0, 1.0, 1.0);
  new_output->SaveToFile("./resources/red_channel_5_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/red_channel_5_test.png");
  EXPECT_EQ(*test, *expected) << "RedChannelFilter has different result";
}

TEST_F(RegressionTest, GreenChannelFilterTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/green_channel_5_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->ApplyChannelsFilter(1.0, 5.0, 1.0);
  new_output->SaveToFile("./resources/green_channel_5_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/green_channel_5_test.png");
  EXPECT_EQ(*test, *expected) << "GreenChannelFilter has different result";
}

TEST_F(RegressionTest, BlueChannelFilterTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/blue_channel_5_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->ApplyChannelsFilter(1.0, 1.0, 5.0);
  new_output->SaveToFile("./resources/blue_channel_5_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/blue_channel_5_test.png");
  EXPECT_EQ(*test, *expected) << "BlueChannelFilter has different result";
}

TEST_F(RegressionTest, QuantizeFilterTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/quantize_5_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->ApplyQuantizeFilter(5);
  new_output->SaveToFile("./resources/quantize_5_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/quantize_5_test.png");
  EXPECT_EQ(*test, *expected) << "QuantizeFilter has different result";
}

TEST_F(RegressionTest, MotioinBlurFilterTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/motion_blur_nw_se_5_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->ApplyMotionBlurFilter(5.0,
    image_tools::ConvolutionFilterMotionBlur::MBLUR_DIR_NW_SE);
  new_output->SaveToFile("./resources/motion_blur_nw_se_5_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/motion_blur_nw_se_5_test.png");
  EXPECT_EQ(*test, *expected) << "MotionBlurFilter has different result";
}

TEST_F(RegressionTest, BlurToolTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/tool_blur_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->StartStroke("Blur", image_tools::ColorData(0.f, 0.f, 0.f, 1.f),
  100.f, 0, 0);
  for (int i = 0; i < 500; i++) {
    new_output->AddToStroke(i, 0);
  }
  new_output->EndStroke(500, 0);
  new_output->SaveToFile("./resources/tool_blur_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/tool_blur_test.png");
  EXPECT_EQ(*test, *expected) << "ToolBlur has different result";
}

TEST_F(RegressionTest, CalligraphyToolTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/tool_calligraphy_pen_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->StartStroke("Calligraphy Pen", image_tools::ColorData(
    0.f, 0.f, 0.f, 1.f), 100.f, 0, 0);
  for (int i = 0; i < 500; i++) {
    new_output->AddToStroke(i, 0);
  }
  new_output->EndStroke(500, 0);
  new_output->SaveToFile("./resources/tool_calligraphy_pen_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/tool_calligraphy_pen_test.png");
  EXPECT_EQ(*test, *expected) << "Tool Calligraphy Pen has different result";
}

TEST_F(RegressionTest, ChalkToolTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/tool_chalk_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->StartStroke("Chalk", image_tools::ColorData(
    0.f, 0.f, 0.f, 1.f), 100.f, 0, 0);
  for (int i = 0; i < 500; i++) {
    new_output->AddToStroke(i, 0);
  }
  new_output->EndStroke(500, 0);
  new_output->SaveToFile("./resources/tool_chalk_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/tool_chalk_test.png");
  EXPECT_EQ(*test, *expected) << "Tool Chalk has different result";
}

TEST_F(RegressionTest, EraserToolTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/tool_eraser_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->StartStroke("Eraser", image_tools::ColorData(
    0.f, 0.f, 0.f, 1.f), 100.f, 0, 0);
  for (int i = 0; i < 500; i++) {
    new_output->AddToStroke(i, 0);
  }
  new_output->EndStroke(500, 0);
  new_output->SaveToFile("./resources/tool_eraser_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/tool_eraser_test.png");
  EXPECT_EQ(*test, *expected) << "Tool Eraser has different result";
}

TEST_F(RegressionTest, HighlighterToolTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/tool_highlighter_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->StartStroke("Highlighter", image_tools::ColorData(
    0.f, 0.f, 0.f, 1.f), 100.f, 0, 0);
  for (int i = 0; i < 500; i++) {
    new_output->AddToStroke(i, 0);
  }
  new_output->EndStroke(500, 0);
  new_output->SaveToFile("./resources/tool_highlighter_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/tool_highlighter_test.png");
  EXPECT_EQ(*test, *expected) << "Tool highlighter has different result";
}

TEST_F(RegressionTest, PenToolTest) {
  image_tools::PixelBuffer *input = new image_tools::PixelBuffer(
    "./resources/548.png");
  image_tools::PixelBuffer *expected = new image_tools::PixelBuffer(
    "./resources/tool_pen_sample.png");
  new_output->set_pixel_buffer(input);
  new_output->StartStroke("Pen", image_tools::ColorData(
    0.f, 0.f, 0.f, 1.f), 100.f, 0, 0);
  for (int i = 0; i < 500; i++) {
    new_output->AddToStroke(i, 0);
  }
  new_output->EndStroke(500, 0);
  new_output->SaveToFile("./resources/tool_pen_test.png");
  image_tools::PixelBuffer *test = new image_tools::PixelBuffer(
    "./resources/tool_pen_test.png");
  EXPECT_EQ(*test, *expected) << "Tool Pen has different result";
}
