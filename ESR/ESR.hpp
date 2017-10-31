//
//  ESR.hpp
//  ESR
//
//  Created by Mamunul on 10/31/17.
//  Copyright © 2017 Mamunul. All rights reserved.
//

#ifndef ESR_hpp
#define ESR_hpp
#import <opencv2/opencv.hpp>
#include <stdio.h>
#include "FaceAlignment.h"

using namespace std;
using namespace cv;



struct Params{
	
	double bagging_overlap;
	int max_numtrees;
	int max_depth;
	int landmark_num;// to be decided
	int initial_num;
	
	int max_numstage;
	double max_radio_radius[10];
	int max_numfeats[10]; // number of pixel pairs
	int max_numthreshs;
};
extern Params global_params;
extern std::string modelPath;
extern std::string dataPath;
extern std::string folderPath;

void InitializeGlobalParam();

void TrainModel(vector<string> trainDataName,string _folderPath);

#endif /* ESR_hpp */
