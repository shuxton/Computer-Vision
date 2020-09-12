#include "rotate_plugin.h"

QString RotatePlugin::name()
{
    return "Rotate";
}

void RotatePlugin::edit(const cv::Mat &input, cv::Mat &output)
{
	double angle=90.0;
	double scale=1.0;
	cv::Point2f center=cv::Point(input.cols/2,input.rows/2);
	cv::Mat rotateMatrix=cv::getRotationMatrix2D(center,angle,scale);
	
	    cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), input.size(), angle).boundingRect2f();
	
	rotateMatrix.at<double>(0,2) += bbox.width/2.0 - input.cols/2.0;
    rotateMatrix.at<double>(1,2) += bbox.height/2.0 - input.rows/2.0;
	
	cv::Mat result;
	cv::warpAffine(input,result,rotateMatrix,bbox.size(),
	               cv::INTER_LINEAR,cv::BORDER_CONSTANT);
	output=result;
	}
