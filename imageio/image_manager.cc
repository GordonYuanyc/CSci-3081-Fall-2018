#include "imageio/image_manager.h"


// FOR IMAGE SAVING / LOADING ONLY!
//#ifdef WIN32
// this is not needed on OSX or Linux, it must pick up the symbols from
// libnanogui.so, but it appears to be needed on Windows.
#define STB_IMAGE_IMPLEMENTATION
//#endif
#include "imageio/impl/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "imageio/impl/stb_image_write.h"

namespace imageio {

Image* ImageManager::LoadFromFile(const std::string &filename) const {
	stbi_set_unpremultiply_on_load(1);
    stbi_convert_iphone_png_to_rgb(1);
	int width, height, numChannels;
    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &numChannels, 4);
    Image* image = new Image(width, height, numChannels);
    std::copy(data, data+width*height*numChannels, image->Pixels());
    stbi_image_free(data);
	return image;
}

void ImageManager::SaveToFile(const std::string &filename, const Image& image) const {
  stbi_write_png_compression_level = 0;
  stbi_write_png(filename.c_str(), image.Width(), image.Height(), image.NumChannels(), image.Pixels(), 0);
}

ImageManager& ImageManager::instance() {
	static ImageManager manager;
	return manager;
}

}
