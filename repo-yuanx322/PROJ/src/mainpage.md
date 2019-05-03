My Main Page {#mainpage}
===========

For users:\n
\subpage Start_FlashphotoApp\n
\subpage Start_MiaApp\n
\n
For developers:\n
\subpage Name_Space_Intro\n
\subpage HLD\n
\subpage CS\n
\subpage CT\n

\page Start_FlashphotoApp FlashPhoto Tutorial
\n
The Flashphoto application is a graphic application. For a user who wants to
use the Flashphoto application, the user can double click the executable in
\<directory to PROJ\>/build/bin/ directory. \n
![executable_sample](../../resources/executable.png)\n\n
The user can also input the directory in terminal like \<directory to PROJ\>/build/bin/flashphoto to open the application.\n
![command_line_open_fp](../../resources/command_line_flashphoto.png)\n\n
The Flashphoto application has a GUI window called canvas that user can draw, open
images, apply filters and save the graph on canvas to a location.\n
![fp_window](../../resources/flashphoto_window.png)\n\n
In Flashphoto,
there are seven tools and eight filters. Tools are Pen, Caligraphy Pen, Chalk,
Highlighter, Spray Can, Blur and Eraser. Filters are Blur Filter, Motion Blur Filter,
Sharpen Filter, Edge Detect Filter, Threshold Filter, Saturate Filter, Adjust R,G,B
Filter and Quantize Filter.\n\n
The pen tool is a pen which can be used to draw marks like a real pen. The caligraphy
pen tool is a special pen, which is called caligraphy pen. The chalk tool acts like
using a chalk on board. The highlighter tool works as a general highlighter. A spary can
tool works like a spray can, so the longer applying spray can to one spot, the darker
that spot will be. A blur tool is a specialized blur filter. A blur tool only blurs the
position that the mouse drags through. A eraser tool can erase all marks on canvas.\n\n
Use can open file through Open button and save file through Save button.\n\n
The Blur Filter is used to make the whole image blur. User can adjust the blur
amount. The Motion Blur Filter can blur the whole image in four directions. The four
directions are North-south, East-west, Northeast-Southwest and Northwest-Southeast.
The Sharpen Filter can sharpen the whole image. User can adjust the sharpen amount.
The Edge Detect Filter can print out the outline of the image. The Threshold Filter
can adjust the graph to black and white by a user input called cutoff value. All
pixel with a color data greater than the cutoff value will be turned to white. All
pixel with a color data smaller than the cutoff value will be turned to black. The
Saturate Filter can increase or decrease the colorfulness of the image. The Channels
Filter can independently scale up or down the intensity of each color channel (red,
green, and blue). So, this filter in application is called Adjust R,G,B. The Quantize
Filter will reduce the number of colors in the image by binning.\n\n
Some example output:\n
Original Picture:\n
![548](../../resources/548.png)\n
Apply Blur filter with amount of 5:\n
![blur_5_sample](../../resources/blur_5_sample.png)\n
Apply Motion Blur filter with direction of Northwest-Southeast and amount of 5:\n
![motion_blur_nw_se_5_sample](../../resources/motion_blur_nw_se_5_sample.png)\n
Apply Sharpen filter with amount of 5:\n
![sharpen_5_sample](../../resources/sharpen_5_sample.png)\n
Apply Threshold filter with cutoff value of 5:\n
![threshold_5_sample](../../resources/threshold_5_sample.png)\n\n

\page Start_MiaApp Mia Tutorial
\n
The MIA application is a special version of Flashphoto. For a user who wants to
use the MIA application, the user has two different options. One option is that
the use can open a GUI window which is similar to the Flashphoto application.The
other option is that the user can use terminal input to apply filters to a certain
image and store the output. This version is called command line mode.\n\n
For the general version of MIA, a user can open it through double click the executable
file \n
![executable_sample](../../resources/executable.png)\n\n
or input the command: \<directory to PROJ\>/build/bin/mia. \n
![command_line_open_mia](../../resources/command_line_mia.png)\n\n
This version is slightly different from the usual Flashphoto version.\n
Example: \n
![mia_canvas_ex](../../resources/mia_window.png)\n\n
In MIA, there are only two
tools and five filters. User can still Open and Save files. Tools are Mark and
Pen. Filters are Blur Filter, Sharpen Filter, Edge Detect Filter, Threshold
Filter and Quantize Filter. The mark tool is used to make a stamp (a circle with
a dot at the center) on the canvas. The pen tool is a pen which can be used to draw
marks like a real pen. The Blur Filter is used to make the whole image blur. User
can adjust the blur amount. The Sharpen Filter can sharpen the whole image. User
can adjust the sharpen amount. The Edge Detect Filter can print out the outline
of the image. The Threshold Filter can adjust the graph to black and white by a
user input called cutoff value. All pixel with a color data greater than the cutoff
value will be turned to white. All pixel with a color data smaller than the cutoff
value will be turned to black. The Quantize Filter will adjust the color with number
of bins.\n\n
For the command line mode of MIA, a user can use MIA through terminal. The user
can get helper message by the command: \<directory to PROJ\>/build/bin/mia -h. This
will print out all accepted command of MIA. All invalid command will also print
out the help message. Include input file and output file is necessary. When inputting
the name of the input file and output file, the file name should end with .png or
.PNG. Make sure the directory of the image is also included. Otherwise, unknown
error such as segmentation fault may occur. One example input is as follow:\n
./build/bin/mia ./resources/548.png -edgedetect -blur 5 ./out.png\n
Sample for the input:\n
![sample_input](../../resources/mia_sample_command_line_input.png)\n
Here is the sample output for the command:\n
![sample](../../resources/sample_output_for_tutorial.png)
\n\n
Some example output:\n
Original Picture:\n
![548](../../resources/548.png)\n
Apply Blur filter with amount of 5:\n
![blur_5_sample](../../resources/blur_5_sample.png)\n
Apply Motion Blur filter with direction of Northwest-Southeast and amount of 5:\n
![motion_blur_nw_se_5_sample](../../resources/motion_blur_nw_se_5_sample.png)\n
Apply Sharpen filter with amount of 5:\n
![sharpen_5_sample](../../resources/sharpen_5_sample.png)\n
Apply Threshold filter with cutoff value of 5:\n
![threshold_5_sample](../../resources/threshold_5_sample.png)\n\n

\page Name_Space_Intro Programming Reference
- #image_tools

- #image_tools::MiaApp

- #image_tools::FlashPhotoApp

\page HLD High-Level Design
\n
The whole application contains imagetools, FlashPhoto and MiaApp.\n
imagetools is a library that contains all the functions needed by FlashPhoto and MiaApp.\n
FlashPhoto is the application that uses the imagetools library. MiaApp has two versions.
They both use the imagetools library.\n
The imagetools library contains classes for eight filters and eight tools. The eight filters are
Blur Filter, Motion Blur Filter, Sharpen Filter, Edge Detect Filter, Threshold Filter, Saturate Filter, Adjust R,G,B
Filter and Quantize Filter. The eight tools are Pen, Caligraphy Pen, Chalk,
Highlighter, Spray Can, Blur, Eraser and Stamp. The library also contains some basic classes
which are served as the basic elements of the application. These are ColorData, PixelBuffer,
MaskFactory and ImageToolsMath.\n
FlashPhoto only has one application that use the imagetools library.\n
Mia has two versions. The graphic version, just like the FlashPhoto application, use the imagetools library
directly. The other version, Command Line Version, contains a class called CommandLineProcessor. This processor
operate on the command line and generate a list of ImageEditorCommand, which is
executable to a helper class ImageEditorCommand. The CommandLineProcessor contains a image_editor_,
which has dependency on the imagetools library. The ImageEditorCommand execute the image_editor_.\n
\n\n
The UML graph is here: \n
![u_m_l_](../../resources/UML_new_.png)\n\n

\page CS Coding Style
\n
Generally, the project follows google style.\n\n
To be more specific:\n
-All header files should have #define at the front. The aim is to prevent multiple inclusion.
The format is \<PROJECT\>\_\<PATH\>\_\<FILE\>\_H\_.\n
-Inline functions can only appear when the function is small.\n
-All classes need default constructor and default destructor.\n
-Including dependencies should be in the following order: Related header, C library, C++ library, other libraries' .h file and the project's .h file.\n
-All parameters passed by lvalue reference must be labeled const.\n
-Variable names should be descriptive and do not have abbreviation.\n
-There is space between parenthesis and tokens.\n
-There is space between numbers and operators or comas.\n
-Each file should start with copyright message.
-Use either \/\/ or \/\* \*\/ for comment. Make sure the comment sign is consistent.\n
-Leave a space between the comment sign and the start of the comment.\n
\n\n\n\n\n
More information can be found here: https://google.github.io/styleguide/cppguide.html \n

\page CT Common Tasks
\n
For a programmer who wants to add new filters to the Flashphoto Application, then
this programmer just need to follow several easy steps.\n\n
First, the place that others can add new filters is imagetools. So, navigate to that
directory.\n\n
Second, the programmer needs to identify whether the filter is a regular filter or a
convolution filter. The difference is that a regular filter can calculate in place and
a convolution filter cannot calculate in place so a kernel is required. A better way to
understand this is that for a regular filter, to adjust color data in a pixel, only this
pixel is included in calculation. So, no other pixel is required for that calculation. So,
color data of other pixel will not be changed. So, we say this is a filter that can calculate
in place. For a convolution filter, the adjustment needs not only the pixel that is going
to be operated but also pixels around it. So, we need a kernel to copy all color data that
is required and calculate the new color data in kernel.\n\n
Here is an example of the file structure.\n
![filter_struct](../../resources/filter_structure.png)\n\n
![filter_struct2](../../resources/filter_struct2.png)\n\n
Third, create the filter that extends corresponding class. A regular will extend
filter.h and a convolution filter will extend convolution_filter.h. Implement the
functions in header files.\n\n
The filter.h looks like this:\n
![filter_h](../../resources/filter_h.png)\n\n
The convolution_filter.h looks like this:\n
![convo_filter_h](../../resources/convo_filter_h.png)\n\n
Finally, remember to adjust the flashphoto_app.h and flashphoto_app.cc to make use
of the newly added filter.\n
To be more specific, add new filter here:\n
![fa_1](../../resources/fa_1.png)\n\n
