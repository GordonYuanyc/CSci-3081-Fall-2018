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

#ifndef MIA_COMMAND_LINE_PROCESSOR_H_
#define MIA_COMMAND_LINE_PROCESSOR_H_

#include "imagetools/image_editor.h"
#include "mia/image_editor_commands.h"
#include "imagetools/convolution_filter_motion_blur.h"

namespace image_tools {

class CommandLineProcessor {
 public:
  CommandLineProcessor();
  virtual ~CommandLineProcessor();

  /** ProcessCommandLine() takes in command line input as parameter and
    do corresponding operation according to the command line. return
    error message if the command line input is not correct */
  void ProcessCommandLine(int argc, char* argv[]);

 private:
  ImageEditor *image_editor_;
  PixelBuffer *current_buffer_;
  void error_printing();
};

}  // namespace image_tools

#endif  // MIA_COMMAND_LINE_PROCESSOR_H_
