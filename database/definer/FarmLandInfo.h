//
//  FarmLandInfo.h
//  MxzyStorage
//
//  Created by Wenjin Zhang on 2017/7/2.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#ifndef FarmLandInfo_h
#define FarmLandInfo_h

#define LANDINFO_MAX;

typedef struct land_level_info{
    int land_level;
    int land_row;
    int land_column;
}LandLevelInfo;


typedef struct land_info{
    
}LandInfo;
typedef struct farmisland_info{
    LandInfo land_info;
}FarmIslandInfo;

#endif /* FarmLandInfo_h */
