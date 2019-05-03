// Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
// Minnesota.

#include <iostream>
#include "gtest/gtest.h"
#include "flashphoto/flashphoto_app.h"

using image_tools::FlashPhotoApp;

class FlashPhotoAppTest : public ::testing::Test {
  void SetUp() override {
    app_ = new FlashPhotoApp(1024, 780, image_tools::ColorData(1, 1, 1));
  }

  void TearDown() override {
    delete app_;
  }

  // We need to write this method
  // void ComparePixelBuffers(PixelBuffer& bufA, PixelBuffer& bufB) {}

 protected:
  FlashPhotoApp *app_;
};

TEST_F(FlashPhotoAppTest, GetToolTest) {
  image_tools::Tool* pen = app_->GetToolByName("Pen");
  EXPECT_TRUE(pen);
  image_tools::Tool* unknownTool = app_->GetToolByName("Unknown");
  EXPECT_FALSE(unknownTool);
}

TEST_F(FlashPhotoAppTest, CanApplyFilters) {
  // For each filter {
  //   Copy pixel buffer from app_
  //   Apply filter
  //   Get new pixel buffer
  //   ComparePixelBuffers() to see if there was a change
  // }
}
