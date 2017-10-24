//
//  ESRWrapper.h
//  ESR
//
//  Created by Mamunul on 10/24/17.
//  Copyright © 2017 Mamunul. All rights reserved.
//

#include "FaceAlignment.h"
#import <opencv2/opencv.hpp>
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <VideoToolbox/VideoToolbox.h>

using namespace std;
using namespace cv;

@interface ESRWrapper : NSObject

- (instancetype)initWithModel:(NSString *)path;
- (cv::Mat_<double>) PredictShape:(cv::Mat) image FaceRect:(BoundingBox) bounding_box;

@end
