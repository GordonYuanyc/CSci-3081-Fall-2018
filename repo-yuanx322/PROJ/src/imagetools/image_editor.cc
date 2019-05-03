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

#include "imagetools/image_editor.h"
#include <assert.h>
#include <mingfx.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>
#include <utility>
#include <string>
#include <deque>
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

ImageEditor::ImageEditor(PixelBuffer *buffer) {
  current_buffer_ = buffer;
}

ImageEditor::ImageEditor() {
}

ImageEditor::~ImageEditor() {
  delete current_buffer_;
}

void ImageEditor::LoadFromFile(const std::string &filename) {
  if (current_buffer_ != NULL) {
    SaveStateForPossibleUndo();
    current_buffer_->LoadFromFile(filename);
  } else {
    current_buffer_ = new PixelBuffer(filename);
  }
}

void ImageEditor::SaveToFile(const std::string &filename) {
  current_buffer_->SaveToFile(filename);
}

Tool *ImageEditor::GetToolByName(const std::string &name) {
  if (name == t_blur_.name()) {
    return &t_blur_;
  } else if (name == t_calligraphy_pen_.name()) {
    return &t_calligraphy_pen_;
  } else if (name == t_chalk_.name()) {
    return &t_chalk_;
  } else if (name == t_eraser_.name()) {
    return &t_eraser_;
  } else if (name == t_highlighter_.name()) {
    return &t_highlighter_;
  } else if (name == t_pen_.name()) {
    return &t_pen_;
  } else if (name == t_spray_can_.name()) {
    return &t_spray_can_;
  } else if (name == t_stamp_.name()) {
    return &t_stamp_;
  } else {
    return NULL;
  }
}

void ImageEditor::StartStroke(const std::string &tool_name,
                              const ColorData &color, float radius, int x,
                              int y) {
  current_tool_ = GetToolByName(tool_name);
  tool_color_ = color;
  tool_radius_ = radius;
  if ((current_tool_) && (current_buffer_)) {
    SaveStateForPossibleUndo();
    current_tool_->StartStroke(current_buffer_, x, y, tool_color_,
                               tool_radius_);
  }
}

void ImageEditor::AddToStroke(int x, int y) {
  if ((current_tool_) && (current_buffer_)) {
    current_tool_->AddToStroke(x, y);
  }
}

void ImageEditor::EndStroke(int x, int y) {
  if ((current_tool_) && (current_buffer_)) {
    current_tool_->EndStroke(x, y);
  }
}

void ImageEditor::ApplyBlurFilter(float radius) {
  SaveStateForPossibleUndo();
  ConvolutionFilter *f = new ConvolutionFilterBlur(radius);
  f->ApplyToBuffer(current_buffer_);
  delete f;
  (void)radius;
}

void ImageEditor::ApplyMotionBlurFilter(
    float rad, ConvolutionFilterMotionBlur::BlurDir dir) {
  SaveStateForPossibleUndo();
  ConvolutionFilter *f = new ConvolutionFilterMotionBlur(rad,
                             dir);
  f->ApplyToBuffer(current_buffer_);
  delete f;
  (void)rad;
  (void)dir;
}

void ImageEditor::ApplySharpenFilter(float rad) {
  SaveStateForPossibleUndo();
  ConvolutionFilter *f = new ConvolutionFilterSharpen(rad);
  f->ApplyToBuffer(current_buffer_);
  delete f;
  (void)rad;
}

void ImageEditor::ApplyEdgeDetectFilter() {
  SaveStateForPossibleUndo();
  Filter *f = new ConvolutionFilterEdge();
  f->ApplyToBuffer(current_buffer_);
  delete f;
}

void ImageEditor::ApplyThresholdFilter(float value) {
  SaveStateForPossibleUndo();
  Filter *f = new FilterThreshold(value);
  f->ApplyToBuffer(current_buffer_);
  delete f;
  (void)value;
}

void ImageEditor::ApplySaturateFilter(float scale) {
  SaveStateForPossibleUndo();
  Filter *f = new FilterSaturate(scale);
  f->ApplyToBuffer(current_buffer_);
  delete f;
  (void)scale;
}

void ImageEditor::ApplyChannelsFilter(float red, float green, float blue) {
  SaveStateForPossibleUndo();
  Filter *f = new FilterChannels(red, green, blue);
  f->ApplyToBuffer(current_buffer_);
  delete f;
  (void)red;
  (void)green;
  (void)blue;
}

void ImageEditor::ApplyQuantizeFilter(int num) {
  SaveStateForPossibleUndo();
  Filter *f = new FilterQuantize(num);
  f->ApplyToBuffer(current_buffer_);
  delete f;
  (void)num;
}

void ImageEditor::Undo() {
  if (can_undo()) {
    // save state for a possilbe redo
    undone_states_.push_front(current_buffer_);

    // make the top state on the undo stack the current one
    current_buffer_ = saved_states_.front();
    saved_states_.pop_front();
  }
}

void ImageEditor::Redo() {
  if (can_redo()) {
    // save state for a possible undo
    saved_states_.push_front(current_buffer_);

    // make the top state on the redo stack the current one
    current_buffer_ = undone_states_.front();
    undone_states_.pop_front();
  }
}

bool ImageEditor::can_undo() {
  return saved_states_.size();
}

bool ImageEditor::can_redo() {
  return undone_states_.size();
}

PixelBuffer *ImageEditor::pixel_buffer() { return current_buffer_; }

void ImageEditor::set_pixel_buffer(PixelBuffer *buffer) {
  current_buffer_ = buffer;
}

void ImageEditor::SaveStateForPossibleUndo() {
  PixelBuffer *buffer_copy = new PixelBuffer(*current_buffer_);
  saved_states_.push_front(buffer_copy);

  // remove the oldest undos if we've over our limit
  while (saved_states_.size() > max_undos_) {
    delete saved_states_.back();
    saved_states_.pop_back();
  }

  // committing a new state invalidates the states saved in the redo stack,
  // so, we simply clear out this stack.
  while (!undone_states_.empty()) {
    delete undone_states_.back();
    undone_states_.pop_back();
  }
}

}  // namespace image_tools
