//
//  CropTable.h
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/28.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#ifndef CropTable_h
#define CropTable_h
#define CROPTABLE_MAX 5
#define CROPNAME_LENGTH 30
#define CROPSTAGE_LENGTH 50


#define SPRING 1
#define SUMMER 2
#define FALL 3
#define WINTER 4

typedef struct crop{
    int crop_id;
    //char crop_name[CROPNAME_LENGTH];
    int crop_season;
    int seedstage_days;
    char seedstage_picpath[CROPSTAGE_LENGTH];
    int stage1_days;
    char stage1_picpath[CROPSTAGE_LENGTH];
    int stage2_days;
    char stage2_picpath[CROPSTAGE_LENGTH];
    int stage3_days;
    char stage3_picpath[CROPSTAGE_LENGTH];
    int returnStage;
    int crop_basic_output;
    int crop_high_output;
    int deathdays;
    int goods_id;
}Crop;

typedef struct crop_table{
    Crop cp[CROPTABLE_MAX];
}CropTable;

#endif /* CropTable_h */
