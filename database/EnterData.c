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
    
    //输入茄子种子信息
    info->allgoods_info.detail[0].goods_id = 101;
    info->allgoods_info.detail[0].goods_max = 30;
    info->allgoods_info.detail[0].purchase_price = 300;
    info->allgoods_info.detail[0].sell_price = 200;
    strcpy(info->allgoods_info.detail[0].goods_name, "eggplant seed");
    info->allgoods_info.detail[0].goods_type = GOODSTYPE_SEED; //???
    //输入对应茄子信息
    info->allgoods_info.detail[1].goods_id = 301;
    info->allgoods_info.detail[1].goods_max = 30;
    info->allgoods_info.detail[1].purchase_price = 450;
    info->allgoods_info.detail[1].sell_price = 400;
    strcpy(info->allgoods_info.detail[1].goods_name, "eggplant");
    info->allgoods_info.detail[1].goods_type = GOODSTYPE_GROWN;
    
    //杂草信息
    info->allgoods_info.detail[2].goods_id = 601;
    info->allgoods_info.detail[2].goods_max = 1;
    info->allgoods_info.detail[2].purchase_price = 0;
    info->allgoods_info.detail[2].sell_price = 0;
    strcpy(info->allgoods_info.detail[2].goods_name, "grass");
    info->allgoods_info.detail[2].goods_type = GOODSTYPE_TRASH;
    
    
    
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
    
    //茄子种子的信息
    info->croptable.cp[0].crop_id = 101; //茄子种子的id是101
    //strcpy(info->croptable.cp[0].crop_name,"test");
    info->croptable.cp[0].crop_season = SPRING;
    info->croptable.cp[0].seedstage_days = 2; //种子阶段需要两天
    strcpy(info->croptable.cp[0].seedstage_picpath, "eggplant_seed.png"); //种子阶段图片路径
    info->croptable.cp[0].stage1_days = 2;
    strcpy(info->croptable.cp[0].stage1_picpath, "eggplant_stage1.png"); //阶段1图片路径
    info->croptable.cp[0].returnStage = 1; //返回阶段1
    info->croptable.cp[0].crop_basic_output = 2; //最低产值
    info->croptable.cp[0].crop_high_output = 3;  //最高产值
    info->croptable.cp[0].deathdays = 5; // 未浇水死亡天数
    info->croptable.cp[0].goods_id = 301; //茄子的ID
    
    
    
    return SUCCESS;
}

int enterDataForSpring(GlobalInfo *info){
    if (info == NULL) {
        return ERROR;
    }
    //茄子种子的信息
    
    info->spring.sstable.sd[0].seed_id = 101; //茄子种子的id是101
    info->spring.sstable.sd[0].seedstage_days = 2; //种子阶段需要两天
    
    info->spring.sstable.sd[0].stage1_days = 2;
    
    info->spring.sstable.sd[0].returnStage = 1; //返回阶段1
    info->spring.sstable.sd[0].seed_basic_output = 2; //最低产值
    info->spring.sstable.sd[0].seed_high_output = 3;  //最高产值
    info->spring.sstable.sd[0].deathdays = 5; // 未浇水死亡天数
    info->spring.sstable.sd[0].goods_id = 301; //茄子的ID
    
    strcpy(info->spring.sstable.sd[0].seedstage_picpath, "eggplant_seed.png"); //种子阶段图片路径
    strcpy(info->spring.sstable.sd[0].stage1_picpath, "eggplant_stage1.png"); //阶段1图片路径
    
    return SUCCESS;
}
