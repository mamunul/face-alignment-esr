//
//  ESRWrapper.m
//  ESR
//
//  Created by Mamunul on 10/24/17.
//  Copyright © 2017 Mamunul. All rights reserved.
//

#import "ESRWrapper.h"

@interface ESRWrapper (){

	ShapeRegressor regressor;

}

@end

@implementation ESRWrapper

- (instancetype)initWithModel:(NSString *)path
{
	self = [super init];
	if (self) {
		regressor.Load([path UTF8String]);
	}
	return self;
}


-(cv::Mat_<double>) PredictShape:(cv::Mat) image FaceRect:(BoundingBox) bounding_box{
	
	int initial_number = 5;
	int landmark_num = 29;
	
	vector<Mat_<uchar> > test_images;
	vector<BoundingBox> test_bounding_box;
	
		Mat_<double> current_shape = regressor.Predict(image,bounding_box,initial_number);

		for(int i = 0;i < landmark_num;i++){
			circle(image,Point2d(current_shape(i,0),current_shape(i,1)),3,Scalar(255,0,0),-1,8,0);
		}

	return current_shape;
}

@end
