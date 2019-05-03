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
#include "imagetools/pixel_buffer.h"
#include "imagetools/image_editor.h"
#include "imagetools/color_data.h"

using image_tools::CommandLineProcessor;
using image_tools::ImageEditorCommand;
using image_tools::ImageEditor;

class CommandLineParsingTest : public ::testing::Test {
 public:
  void SetUp() override {}
};

TEST_F(CommandLineParsingTest, ImageEndingError) {
  CommandLineProcessor c = CommandLineProcessor();
  const char* input_1[] = { "./build/bin/mia", "./resources/548",
    "./out.png"};

  testing::internal::CaptureStdout();
  c.ProcessCommandLine(3, const_cast<char**>(input_1));
  std::string output = testing::internal::GetCapturedStdout();
  int i = 0;
  if (!output.empty()) {
    i = -1;
  }
  EXPECT_EQ(i, -1) << "Image name not ending with .png";
}

TEST_F(CommandLineParsingTest, NoInputImageError) {
  CommandLineProcessor c = CommandLineProcessor();
  const char* input_1[] = { "./build/bin/mia", "./out.png"};

  testing::internal::CaptureStdout();
  c.ProcessCommandLine(2, const_cast<char**>(input_1));
  std::string output = testing::internal::GetCapturedStdout();
  int i = 0;
  if (!output.empty()) {
    i = -1;
  }
  EXPECT_EQ(i, -1) << "No input image";
}

TEST_F(CommandLineParsingTest, NoOutputImageError) {
  CommandLineProcessor c = CommandLineProcessor();
  const char* input_1[] = { "./build/bin/mia", "./resources/548.png"};

  testing::internal::CaptureStdout();
  c.ProcessCommandLine(2, const_cast<char**>(input_1));
  std::string output = testing::internal::GetCapturedStdout();
  int i = 0;
  if (!output.empty()) {
    i = -1;
  }
  EXPECT_EQ(i, -1) << "No output image";
}

TEST_F(CommandLineParsingTest, WrongCommandError) {
  CommandLineProcessor c = CommandLineProcessor();
  const char* input_1[] = { "./build/bin/mia", "./resources/548",
    "-blur", "5", "./out.png"};

  testing::internal::CaptureStdout();
  c.ProcessCommandLine(5, const_cast<char**>(input_1));
  std::string output = testing::internal::GetCapturedStdout();
  int i = 0;
  if (!output.empty()) {
    i = -1;
  }
  EXPECT_EQ(i, -1) << "CommandLineInput has mistake";
}

TEST_F(CommandLineParsingTest, CommandMissingElementError) {
  CommandLineProcessor c = CommandLineProcessor();
  const char* input_1[] = { "./build/bin/mia", "./resources/548.png",
    "-threshold", "./out.png"};

  testing::internal::CaptureStdout();
  c.ProcessCommandLine(4, const_cast<char**>(input_1));
  std::string output = testing::internal::GetCapturedStdout();
  int i = 0;
  if (!output.empty()) {
    i = -1;
  }
  EXPECT_EQ(i, -1) << "CommandLineInput missing element";
}
