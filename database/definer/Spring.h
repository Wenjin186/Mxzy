//
//  Spring.h
//  MxzyStorage
//
//  Created by Wenjin Zhang on 2017/6/29.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#ifndef Spring_h
#define Spring_h

#define SPRINGSEEDTABLE_MAX 10

typedef struct seed{
    int seed_id;
    int seedstage_days;
    char seedstage_picpath[CROPSTAGE_LENGTH];
    int stage1_days;
    char stage1_picpath[CROPSTAGE_LENGTH];
    int stage2_days;
    char stage2_picpath[CROPSTAGE_LENGTH];
    int stage3_days;
    char stage3_picpath[CROPSTAGE_LENGTH];
    int returnStage;
    int seed_basic_output;
    int seed_high_output;
    int deathdays;
    int goods_id;
}Seed;


typedef struct spring_seed_table{
    Seed sd[SPRINGSEEDTABLE_MAX];
}SpringSeedTable;

typedef struct spring{
    SpringSeedTable sstable;
}Spring;

#endif /* Spring_h */
