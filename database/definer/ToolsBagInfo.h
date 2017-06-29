//
//  ToolsBagInfo.h
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/23.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#ifndef ToolsBagInfo_h
#define ToolsBagInfo_h

#define TOOLSBAGINFO_MAX 3

typedef struct tblevel_info{
    int bag_level;
    int bag_capacity;
}TbLevelInfo;

typedef struct toolsbag_info{
    TbLevelInfo info[TOOLSBAGINFO_MAX];
}ToolsBagInfo;

#endif /* ToolsBagInfo_h */
