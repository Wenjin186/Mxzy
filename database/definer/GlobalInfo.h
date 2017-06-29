//
//  define_globalinfo.h
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/21.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#ifndef define_globalinfo_h
#define define_globalinfo_h

#include "AllGoodsInfo.h"
#include "GoodsBagInfo.h"
#include "AllToolsInfo.h"
#include "ToolsBagInfo.h"
#include "CropTable.h"

typedef struct global_info{
    AllGoodsInfo allgoods_info;
    GoodsBagInfo goodsbag_info;
    AllToolsInfo alltools_info;
    ToolsBagInfo toolsbag_info;
    CropTable croptable;
}GlobalInfo;


#endif /* define_globalinfo_h */
