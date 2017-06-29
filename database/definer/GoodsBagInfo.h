//
//  define_goodsbaginfo.h
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/22.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#ifndef define_goodsbaginfo_h
#define define_goodsbaginfo_h

#define GOODSBAGINFO_MAX 3

typedef struct gblevel_Info{
    int bag_level;
    int bag_capacity;
}GbLevelInfo;

typedef struct goodsbag_info{
    GbLevelInfo levels[GOODSBAGINFO_MAX];
}GoodsBagInfo;

#endif /* define_goodsbaginfo_h */
