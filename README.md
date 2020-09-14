# COMPUTER VISION PROJECTS

## 1. Image Viewer
   As the name suggests, it is an application to view images with zoom in,zoom out,next,prev buttons
   
## 2. Image Editor
   The Image Viewer was upgraded to an editor with features like rotate,sharpen and many filters like erode and cartoon
   These filters can be added as individual plugin files.
   
## 3. Home Security
   Features-
   * Record and save videos
   * Detect motion using opencv libraries
   * On detecting motion sends a notification to configured phone

### To use the applications
 - Install opencv and qt
 - Edit the .pro file as follows
 >For Linux
  ```
  unix: !mac {
    INCLUDEPATH += /path/to/opencv/include/opencv4
    LIBS += -L/path/to/opencv/lib -lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_video -lopencv_videoio
   }
  ```
  Then run `$ export LD_LIBRARY_PATH=/path/to/opencv/lib`
  >For Mac
  ```
  unix: mac {
    INCLUDEPATH += /path/to/opencv/include/opencv4
    LIBS += -L/path/to/opencv/lib -lopencv_world
  }
  ```
  >For Windows
  ```
   win32 {
    INCLUDEPATH += c:/path/to/opencv/include/opencv4
    LIBS += -lc:/path/to/opencv/lib/opencv_world
   }
  ```
  - Then build project using qmake
