// Include libraries
#include "../resource/lib/public/includeLibraries.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "../resource/lib/public/displayImages.h"
#include "../resource/lib/public/matplotlibcpp.h"

using namespace std;

using namespace cv;

using namespace matplotlibcpp;

string imagePath = DATA_PATH + "/images/number_zero.jpg";

// Read image in Grayscale format
Mat testImage = imread(imagePath,0);

cout << testImage;

string type2str(int type) {
  string r;

  uchar depth = type & CV_MAT_DEPTH_MASK;
  uchar chans = 1 + (type >> CV_CN_SHIFT);

  switch ( depth ) {
    case CV_8U:  r = "8U"; break;
    case CV_8S:  r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default:     r = "User"; break;
  }

  r += "C";
  r += (chans+'0');

  return r;
}

cout << "Data type = " << type2str(testImage.type()) << endl;
cout << "Image Dimensions = " << testImage.size();

cout << (int)testImage.at<uchar>(0,0);

testImage.at<uchar>(0,0)=200;

cout << testImage;

Mat test_roi = testImage(Range(0,2),Range(0,4));
cout << "Original Matrix\n" << testImage << endl << endl;

cout << "Selected Region\n" << test_roi;

testImage(Range(0,2),Range(0,4)).setTo(111);

cout << "Modified Matrix\n" << testImage;

plt::figure_size(800,200);
plt::imshow(testImage);
auto pltImg = displayImage(testImage);
pltImg

imwrite("../results/test.jpg",testImage);

// Path of the image to be loaded
// Here we are supplying a relative path
imagePath = DATA_PATH + "/images/musk.jpg";

// Read the image
Mat img = imread(imagePath);

cout << "image size = " << img.size() << endl;
cout << "image channels = " << img.channels();

// Show the channels
Mat imgChannels[3];
split(img, imgChannels);

plt::figure_size(1000,200);
plt::subplot(1,4,1);
plt::imshow(imgChannels[0]);
pltImg = displayImage(imgChannels[0]);
plt::subplot(1,4,2);
plt::imshow(imgChannels[1]);
pltImg = displayImage(imgChannels[1]);
plt::subplot(1,4,3);
plt::imshow(imgChannels[2]);
pltImg = displayImage(imgChannels[2]);
plt::subplot(1,4,4);
plt::imshow(img);
pltImg = displayImage(img);
pltImg

imagePath = DATA_PATH + "/images/number_zero.jpg";
testImage = imread(imagePath,1);

plt::figure_size(800,200);
plt::imshow(testImage);
pltImg = displayImage(testImage);
pltImg

cout << testImage.at<Vec3b>(0,0);

testImage.at<Vec3b>(0,0) = Vec3b(0,255,255);
plt::figure_size(1000,200);
plt::subplot(1,3,1);
plt::imshow(testImage);
pltImg = displayImage(testImage);

testImage.at<Vec3b>(1,1) = Vec3b(255,255,0);
plt::subplot(1,3,2);
plt::imshow(testImage);
pltImg = displayImage(testImage);

testImage.at<Vec3b>(2,2) = Vec3b(255,0,255);
plt::subplot(1,3,3);
plt::imshow(testImage);
pltImg = displayImage(testImage);

pltImg

testImage(Range(0,3),Range(0,3)).setTo(Scalar(255,0,0));

testImage(Range(3,6),Range(0,3)).setTo(Scalar(0,255,0));
testImage(Range(6,9),Range(0,3)).setTo(Scalar(0,0,255));

plt::figure_size(800,200);
plt::imshow(testImage);
pltImg = displayImage(testImage);
pltImg

// Path of the PNG image to be loaded
imagePath = DATA_PATH + "/images/panther.png";

// Read the image
// Note that we are passing flag = -1 while reading the image ( it will read the image as is)
Mat imgPNG = imread(imagePath,-1);
cout << "image size = " << imgPNG.size() << endl;
cout << "number of channels = " << imgPNG.channels() << endl;

Mat imgBGR;
Mat imgPNGChannels[4];
split(imgPNG,imgPNGChannels);

merge(imgPNGChannels,3,imgBGR);

Mat imgMask = imgPNGChannels[3];

plt::figure_size(1000,200);
plt::subplot(1,2,1);
plt::imshow(imgBGR);
pltImg = displayImage(imgBGR);
plt::subplot(1,2,2);
plt::imshow(imgMask);
pltImg = displayImage(imgMask);
pltImg
