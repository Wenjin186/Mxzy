//
//  CharacterRow.h
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/22.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#ifndef CharacterRow_h
#define CharacterRow_h

#define CHARACTER_NAME_LENGTH 20
#define FARM_NAME_LENGTH 20
#define FISHERY_NAME_LENGTH 20
#define PASTURE_NAME_LENGTH 20
#define LAND_ROW_MAX 20
#define LAND_COLUMN_MAX 30
#define GOODSBAG_MAX 30

#define LANDTYPE_BARREN 1

typedef struct goods{
    int goods_id;
    int amount;
}_Goods;


typedef struct goods_bag{
    _Goods goods[GOODSBAG_MAX];
    int bag_level;
}_GoodsBag;

typedef struct inLand{
    int stuff_id;
    int water_days;
    int unwater_days;
}InLand;

typedef struct land{
    InLand il;
    int land_type;
}Land;

typedef struct farmland_info{
    Land land[LAND_ROW_MAX][LAND_COLUMN_MAX];
}FarmLandInfo;


typedef struct island_table{
    FarmLandInfo finfo;
}IslandTable;


typedef struct character_row{
    int character_id;
    char character_name[CHARACTER_NAME_LENGTH];
    IslandTable island;
    _GoodsBag bag;
}CharacterRow;

#endif /* CharacterRow_h */
