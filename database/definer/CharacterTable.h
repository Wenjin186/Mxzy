//
//  CharacterTable.h
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/22.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#ifndef CharacterTable_h
#define CharacterTable_h

#include "CharacterRow.h"

#define CHARACTER_MAX 3

//判断character_name是否为空
typedef struct character_table{
    CharacterRow c1;
    CharacterRow c2;
    CharacterRow c3;
}CharacterTable;

#endif /* CharacterTable_h */
