#ifndef IMAGEIO_IMAGE_H_
#define IMAGEIO_IMAGE_H_

namespace imageio {

/** An Image class stores image information and image data.*/
class Image {
 public:
 	/// Initializes an image with width, height and number of channels (i.e. 4 for RGBA)
 	Image(int width, int height, int numChannels);
 	virtual ~Image();

 	/// The width of the image
 	int Width() const { return width_; }
 	/// The height of the image
 	int Height() const { return height_; }
 	/// The number of channels in the image
 	int NumChannels() const { return numChannels_; }

 	/// Get the raw read-only pixel buffer
	const unsigned char* Pixels() const;
	/// Get the raw pixel buffer
 	unsigned char* Pixels();
 	/// Get a specific x, y pixel value which includes and RGBA array
 	unsigned char* Pixel(int x, int y);
 	/// Get an editable RGBA value for a specific pixel at x and y
 	unsigned char& Value(int x, int y, int channel);
 	/// Get a normalized pixel value for a channel (0.0 - 1.0)
 	float FloatValue(int x, int y, int channel);
 	/// Set a normalized pixel value for a channel (0.0 - 1.0)
 	void SetFloatValue(int x, int y, int channel, float value);

 private:
 	int width_, height_, numChannels_;
 	unsigned char* pixelBuffer_;
};

}

#endif  // IMAGEIO_IMAGE_H_
