//
//  InitGlobalInfo.c
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/21.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#include "EnterData.h"

int enterDataForAllGoodsInfo(GlobalInfo *info){
    if (info==NULL) {
        return ERROR;
    }
    
    //输入茄子信息
    info->allgoods_info.detail[0].goods_id = 101;
    info->allgoods_info.detail[0].goods_max = 30;
    info->allgoods_info.detail[0].purchase_price = 300;
    info->allgoods_info.detail[0].sell_price = 200;
    strcpy(info->allgoods_info.detail[0].goods_name, "eggplant");
    info->allgoods_info.detail[0].goods_type = 0; //???
    
    
    return SUCCESS;
}

int enterDataForGoodsBagInfo(GlobalInfo *info){
    if (info == NULL) {
        return ERROR;
    }
    
    //设置背包等级为1的时候，容量是10
    info->goodsbag_info.levels[0].bag_level = 1;
    info->goodsbag_info.levels[0].bag_capacity = 10;
    
    //设置背包等级为2的时候，容量是20
    info->goodsbag_info.levels[1].bag_level = 2;
    info->goodsbag_info.levels[1].bag_capacity = 20;
    
    //设置背包等级为3的时候，容量是30
    info->goodsbag_info.levels[2].bag_level = 3;
    info->goodsbag_info.levels[2].bag_capacity = 30;
    return SUCCESS;
}

int enterDataForAllToolsInfo(GlobalInfo *info){
    if (info == NULL) {
        return ERROR;
    }
    
    info->alltools_info.detail[0].tool_id = 11;
    strcpy(info->alltools_info.detail[0].tool_name, "chuizi");
    return SUCCESS;
}

int enterDataForToolsBagInfo(GlobalInfo *info){
    if (info ==  NULL) {
        return ERROR;
    }
    
    info->toolsbag_info.info[0].bag_level = 1;
    info->toolsbag_info.info[0].bag_capacity = 4;
    
    info->toolsbag_info.info[1].bag_level = 2;
    info->toolsbag_info.info[1].bag_capacity = 8;
    
    
    info->toolsbag_info.info[2].bag_level = 3;
    info->toolsbag_info.info[2].bag_capacity = 10;
    return SUCCESS;
};

int enterDataForCropTable(GlobalInfo *info){
    if (info == NULL) {
        return ERROR;
    }
    
    info->croptable.cp[0].crop_id = 101;
    
    return SUCCESS;
}
