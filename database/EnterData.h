//
//  InitGlobalInfo.h
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/21.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#ifndef InitGlobalInfo_h
#define InitGlobalInfo_h

#include "definer/GlobalInfo.h"
#include "definer/error.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


int enterDataForAllGoodsInfo(GlobalInfo *info);
int enterDataForGoodsBagInfo(GlobalInfo *info);
int enterDataForAllToolsInfo(GlobalInfo *info);
int enterDataForToolsBagInfo(GlobalInfo *info);
int enterDataForCropTable(GlobalInfo *info);



#endif /* InitGlobalInfo_h */
