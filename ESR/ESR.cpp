//
//  ESR.cpp
//  ESR
//
//  Created by Mamunul on 10/31/17.
//  Copyright © 2017 Mamunul. All rights reserved.
//

#include "ESR.hpp"


Params global_params;
string folderPath = "";
string modelPath ="/model_69/";
string dataPath = "/Dataset/";
string cascadeName = "haarcascade_frontalface_alt.xml";

void LoadOpencvBbxData(string _folderPath,string filepath,
					   vector<Mat_<uchar> >& images,
					   vector<Mat_<double> >& ground_truth_shapes,
					   vector<BoundingBox> & bounding_boxs
					   );
// set the parameters when training models.
void InitializeGlobalParam(){
	global_params.bagging_overlap = 0.4;
	global_params.max_numtrees = 10;
	global_params.max_depth = 5;
	global_params.landmark_num = 68;
	global_params.initial_num = 5;
	
	global_params.max_numstage = 7;
	double m_max_radio_radius[10] = {0.4,0.3,0.2,0.15, 0.12, 0.10, 0.08, 0.06, 0.06,0.05};
	double m_max_numfeats[10] = {500, 500, 500, 300, 300, 200, 200,200,100,100};
	for (int i=0;i<10;i++){
		global_params.max_radio_radius[i] = m_max_radio_radius[i];
	}
	for (int i=0;i<10;i++){
		global_params.max_numfeats[i] = m_max_numfeats[i];
	}
	global_params.max_numthreshs = 500;
}

void TrainModel(vector<string> trainDataName,string _folderPath){
	vector<Mat_<uchar> > images;
	vector<Mat_<double> > ground_truth_shapes;
	vector<BoundingBox> bounding_boxs;
	
	extern string folderPath;
	folderPath = _folderPath;
	extern string cascadeName;
	cascadeName = _folderPath + cascadeName;
	
	int img_num = 1345;
	int candidate_pixel_num = 400;
	int fern_pixel_num = 5;
	int first_level_num = 5;
	int second_level_num = 100;
	int landmark_num = 68;
	int initial_number = 5;
	
	for(int i=0;i<trainDataName.size();i++){
		string path;
		//        if(trainDataName[i]=="helen"||trainDataName[i]=="lfpw")
		path = _folderPath + dataPath + trainDataName[i] + "/Path_Images.txt";
		//        else
		//            path = _folderPath + dataPath + trainDataName[i] + "/Path_Images.txt";
		
		
		// LoadData(path, images, ground_truth_shapes, bounding_boxs);
		LoadOpencvBbxData(folderPath + dataPath + trainDataName[i],path, images, ground_truth_shapes, bounding_boxs);
	}
	
	ShapeRegressor regressor;
	regressor.Train(images,ground_truth_shapes,bounding_boxs,first_level_num,second_level_num,
	                    candidate_pixel_num,fern_pixel_num,initial_number);
	regressor.Save(modelPath+"/model.txt");
	
	return;
}
