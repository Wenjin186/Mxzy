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


typedef struct detail_table{
    char farm_name[FARM_NAME_LENGTH];
    char fishery_name[FISHERY_NAME_LENGTH];
    char pasture_name[PASTURE_NAME_LENGTH];
}DetailTable;

typedef struct character_row{
    int character_id;
    char character_name[CHARACTER_NAME_LENGTH];
    DetailTable detailTable;
}CharacterRow;

#endif /* CharacterRow_h */
