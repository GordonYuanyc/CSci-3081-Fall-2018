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

#include "mia/command_line_processor.h"
#include <assert.h>
#include <mingfx.h>
#include <stdlib.h>
#include <string.h>
#include <platform.h>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>
#include <utility>
#include <vector>
#include "mia/image_editor_commands.h"
#include "imagetools/image_editor.h"
#include "imagetools/convolution_filter_motion_blur.h"


namespace image_tools {

CommandLineProcessor::CommandLineProcessor() {
  current_buffer_ = new PixelBuffer(100, 100, image_tools::ColorData(1, 1, 1));
  image_editor_ = new ImageEditor();
}

CommandLineProcessor::~CommandLineProcessor() {
}

void CommandLineProcessor::error_printing() {
  std::cout <<
  "usage: mia infile.png [image processing commands ...] outfile.png"
  << std::endl;
  std::cout <<
  "infile.png:\t\t input image file in png format"
  << std::endl;
  std::cout <<
  "outfile.png:\t\t filename to use for saving the result"
  << std::endl;
  std::cout <<
  "-blur r:\t\t apply a gaussian blur of radius r"
  << std::endl;
  std::cout <<
  "-edgedetect:\t\t apply an edge detection filter"
  << std::endl;
  std::cout <<
  "-sharpen r:\t\t apply a sharpening filter of radius r"
  << std::endl;
  std::cout <<
  "-red s:\t\t scale the red channel by factor s"
  << std::endl;
  std::cout <<
  "-green s:\t\t scale the green channel by factor s"
  << std::endl;
  std::cout <<
  "-blue s:\t\t scale the blue channel by factor s"
  << std::endl;
  std::cout <<
  "-quantize n:\t\t quantize each color channel into n bins"
  << std::endl;
  std::cout <<
  "-saturate s:\t\t saturate colors by scale factor s"
  << std::endl;
  std::cout <<
  "-threshold c:\t\t threshold using cutoff value c"
  << std::endl;
  std::cout <<
  "-motionblur-n-s r:\t\t north-south motion blur with kernel radius r"
  << std::endl;
  std::cout <<
  "-motionblur-e-w r:\t\t east-west motion blur with kernel radius r"
  << std::endl;
  std::cout <<
  "-motionblur-ne-sw r:\t\t ne-sw motion blur with kernel radius r"
  << std::endl;
  std::cout <<
  "-motionblur-nw-se r:\t\t nw-se motion blur with kernel radius r"
  << std::endl;
}

void CommandLineProcessor::ProcessCommandLine(int argc, char* argv[]) {
  image_editor_->set_pixel_buffer(current_buffer_);
  std::vector<ImageEditorCommand*> command_list_;
  if (argc == 2) {
    error_printing();
  } else {
    if ((strstr(argv[1], ".png") || strstr(argv[1], ".PNG")) &&
      (strstr(argv[argc - 1], ".png") || strstr(argv[argc - 1], ".PNG")) &&
      mingfx::Platform::FileExists(argv[1])) {
      ImageEditorCommand *load = new LoadCommand(image_editor_, argv[1]);
      command_list_.push_back(load);
      for (int i = 2; i < argc - 1; i++) {
          if (strcmp(argv[i], "-blur") == 0) {
            try {
              ImageEditorCommand *blur = new BlurFilterCommand(image_editor_,
                std::stof(argv[i+1]));
              command_list_.push_back(blur);
              i++;
            }
            catch(std::invalid_argument) {
              error_printing();
            }
          } else if (!strcmp(argv[i], "-edgedetect")) {
            ImageEditorCommand *edge = new EdgeFilterCommand(image_editor_);
            command_list_.push_back(edge);
          } else if (strcmp(argv[i], "-sharpen") == 0) {
            try {
              ImageEditorCommand *sharpen = new SharpenFilterCommand(
                image_editor_, std::stof(argv[i+1]));
              command_list_.push_back(sharpen);
              i++;
            }
            catch(std::invalid_argument) {
              error_printing();
            }
          } else if (strcmp(argv[i], "-red") == 0) {
            try {
              ImageEditorCommand *channelr = new ChannelsFilterCommand(
                image_editor_, std::stof(argv[i+1]), 1.f, 1.f);
              command_list_.push_back(channelr);
              i++;
            }
            catch(std::invalid_argument) {
              error_printing();
            }
          } else if (strcmp(argv[i], "-green") == 0) {
            try {
              ImageEditorCommand *channelg = new ChannelsFilterCommand(
                image_editor_, 1.f, std::stof(argv[i+1]), 1.f);
              command_list_.push_back(channelg);
              i++;
            }
            catch(std::invalid_argument) {
              error_printing();
            }
          } else if (strcmp(argv[i], "-blue") == 0) {
            try {
              ImageEditorCommand *channelb = new ChannelsFilterCommand(
                image_editor_, 1.f, 1.f, std::stof(argv[i+1]));
              command_list_.push_back(channelb);
              i++;
            }
            catch(std::invalid_argument) {
              error_printing();
            }
          } else if (strcmp(argv[i], "-quantize") == 0) {
            try {
              ImageEditorCommand *quantize = new QuantizeFilterCommand(
                image_editor_, std::stoi(argv[i+1]));
              command_list_.push_back(quantize);
              i++;
            }
            catch(std::invalid_argument) {
              error_printing();
            }
          } else if (strcmp(argv[i], "-saturate") == 0) {
            try {
              ImageEditorCommand *saturate = new SaturateFilterCommand(
                image_editor_, std::stof(argv[i+1]));
              command_list_.push_back(saturate);
              i++;
            }
            catch(std::invalid_argument) {
              error_printing();
            }
          } else if (strcmp(argv[i], "-threshold") == 0) {
            try {
              ImageEditorCommand *threshold = new ThresholdFilterCommand(
                image_editor_, std::stof(argv[i+1]));
              command_list_.push_back(threshold);
              i++;
            }
            catch(std::invalid_argument) {
              error_printing();
            }
          } else if (strcmp(argv[i], "-motionblur-n-s") == 0) {
            try {
              ImageEditorCommand *ns = new MotionBlurFilterCommand(
                image_editor_, std::stof(argv[i+1]),
                ConvolutionFilterMotionBlur::MBLUR_DIR_N_S);
              command_list_.push_back(ns);
              i++;
            }
            catch(std::invalid_argument) {
              error_printing();
            }
          } else if (strcmp(argv[i], "-motionblur-e-w") == 0) {
            try {
              ImageEditorCommand *ew = new MotionBlurFilterCommand(
                image_editor_, std::stof(argv[i+1]),
                ConvolutionFilterMotionBlur::MBLUR_DIR_E_W);
              command_list_.push_back(ew);
              i++;
            }
            catch(std::invalid_argument) {
              error_printing();
            }
          } else if (strcmp(argv[i], "-motionblur-ne-sw") == 0) {
            try {
              ImageEditorCommand *nesw = new MotionBlurFilterCommand(
                image_editor_, std::stof(argv[i+1]),
                ConvolutionFilterMotionBlur::MBLUR_DIR_NE_SW);
              command_list_.push_back(nesw);
              i++;
            }
            catch(std::invalid_argument) {
              error_printing();
            }
          } else if (strcmp(argv[i], "-motionblur-nw-se") == 0) {
            try {
              ImageEditorCommand *nwse = new MotionBlurFilterCommand(
                image_editor_, std::stof(argv[i+1]),
                ConvolutionFilterMotionBlur::MBLUR_DIR_NW_SE);
              command_list_.push_back(nwse);
              i++;
            }
            catch(std::invalid_argument) {
              error_printing();
            }
          } else {
            std::cout<< "Invalid argument " << argv[i] << std::endl;
            std::cout<< "\n\n" << std::endl;
            std::cout<< "helper message " << std::endl;
            error_printing();
            std::cout<< "\n\n" << std::endl;
          }
        }
      ImageEditorCommand *save = new SaveCommand(image_editor_, argv[argc - 1]);
      command_list_.push_back(save);
    } else {
      error_printing();
    }
    if (!command_list_.empty()) {
      for (int i = 0; i < static_cast<int>(command_list_.size()); i++) {
        command_list_[i]->Execute();
      }
    }
  }
  delete current_buffer_;
  (void) command_list_;
}

}  // namespace image_tools
