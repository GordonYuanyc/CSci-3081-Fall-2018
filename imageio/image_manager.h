#ifndef IMAGEIO_IMAGE_MANAGER_H_
#define IMAGEIO_IMAGE_MANAGER_H_

#include <string>
#include "imageio/image.h"

namespace imageio {

/** The ImageManager class has methods for loading and saving files using
 a file path and a basic image object.*/
class ImageManager {
 public:
 	/** Loads an image from a file.
   		* @param filename path the to the file to be loaded.
   		* @return an image object that holds the image data.
   	*/ 
 	Image* LoadFromFile(const std::string &filename) const;

 	/** Saves an image to a file.
   		* @param filename path the to the file to be saved.
   		* @param image an image object that holds the image data.
   	*/ 
 	void SaveToFile(const std::string &filename, const Image& image) const;

 	/** A singleton instance for ImageManager.  To access the image manager
 	  use ImageManager::instance().  For example: 
 	  Image* image = ImageManager::instance().LoadFromFile("/path/to/file")
   	*/ 
 	static ImageManager& instance();

 private:
 	ImageManager() {}
};

}

#endif  // IMAGEIO_IMAGE_MANAGER_H_
