//
//  ViewController.m
//  ESR
//
//  Created by Mamunul on 10/24/17.
//  Copyright © 2017 Mamunul. All rights reserved.
//

#import <opencv2/opencv.hpp>
#import "ESRWrapper.h"
#import "ESR.hpp"

#import "ViewController.h"



@implementation ViewController

- (void)viewDidLoad {
	[super viewDidLoad];
	
//	NSString *path;
//	BoundingBox bounding_box;
//	
//	ESRWrapper *esr = [[ESRWrapper alloc] initWithModel:path];
//	
//	cv::Mat_<double>  shape = [esr PredictShape:image FaceRect:bounding_box];

	// Do any additional setup after loading the view.
	
	[self startTraining];
	
}

-(void)startTraining{
	
	std::vector<std::string> trainDataName;
	extern string modelPath;
	extern string dataPath;
	extern string folderPath;
	
	dataPath = "";
	modelPath = "/Users/mamunul/Downloads/Shape_Prediction_Database/esr/";
	folderPath = "/Users/mamunul/Downloads/Shape_Prediction_Database/";
	
	
	trainDataName.push_back("helen/trainset");
	trainDataName.push_back("lfpw/trainset");
	trainDataName.push_back("afw");
	InitializeGlobalParam();
	
	TrainModel(trainDataName, folderPath);


}

- (void)setRepresentedObject:(id)representedObject {
	[super setRepresentedObject:representedObject];

	// Update the view, if already loaded.
}


@end
