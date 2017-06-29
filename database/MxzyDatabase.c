//
//  MxzyDatabase.c
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/19.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#include "MxzyDatabase.h"

int createOrGetLocalStorage(FILE **fpp, const char *path){
    if (path==NULL) {
        perror("pointer cannot be null");
        return ERROR;
    }
    
    int ret = access(path, F_OK);
    
    //如果文件不存在，新建该文件
    if (ret < 0) {
        *fpp = fopen(path, "wb+");
        if (*fpp==NULL)
            return ERROR;
    }
    //如果存在
    else{
        *fpp = fopen(path, "rb+");
        if (*fpp==NULL)
            return ERROR;
    }
    return SUCCESS;
}
void closeLocalStorage(FILE *fp){
    if (fp == NULL) {
        perror("pointer cannot be null");
        return;
    }
    fclose(fp);
}
void initCharacterTable(CharacterTable **table){
    *table = (CharacterTable *)malloc(sizeof(CharacterTable));
    memset(*table, 0, sizeof(CharacterTable));
}
void freeCharacterTable(CharacterTable *table){
    if (table == NULL) {
        perror("pointer cannot be null");
        return;
    }
    free(table);
}
int createCharacter(CharacterTable *table){
    if (table==NULL) {
        return ERROR;
    }
    CharacterRow *row = &table->c1;
    
    for (int i = 1; i<=CHARACTER_MAX; i++, row++) {
        if (row->character_id == 0) {
            row->character_id = i;
            return i;
        }
        
        if (i==CHARACTER_MAX && row->character_id!=0) {
            return ERROR; //无法注册 角色已经满了
        }
    }
    return ERROR;
}
int getCharacterRowById(CharacterRow **row, CharacterTable *table, int id){
    if (table==NULL) {
        perror("pointer cannot be null");
        return ERROR;
    }
    
    CharacterRow *temp = NULL;
    temp = &table->c1;
    for (int i = 0; i<CHARACTER_MAX; i++, temp++) {
        if (temp->character_id==id) {
            *row = temp;
            return SUCCESS;
        }
    }
    return ERROR;
}
int toWriteData(FILE *fp, CharacterTable *table){
    if (fp==NULL || table==NULL) {
        perror("pointer cannot be null");
        return ERROR;
    }
    fseek(fp, 0, SEEK_SET);
    int fd = fileno(fp); //通过FILE结构体获得文件描述符
    int ret = ftruncate(fd, 0);
    if (ret < 0) {
        return ERROR;
    }
    
    fwrite(table, sizeof(CharacterTable), 1, fp);
    return SUCCESS;
}
int toReadData(FILE *fp, CharacterTable *table){
    if (fp == NULL || table == NULL) {
        perror("pointer cannot be null");
        return ERROR;
    }
    int ret = fread(table, sizeof(CharacterTable), 1, fp);
    if (ret == 0) {
        return ERROR;
    }
    return SUCCESS;
}


int setCharacterName(CharacterRow *row, const char *name){
    if (row == NULL || name == NULL) {
        return ERROR;
    }
    strcpy(row->character_name, name);
    return SUCCESS;
}
char *getCharacterName(CharacterRow *row){
    if (row == NULL) {
        printf("CharacterRow cannot be NULL.\n");
        return NULL;
    }
    return row->character_name;
};

int createOrGetGlobalInfoFile(FILE **fpp, const char *path){
    if (path==NULL)
        return ERROR;
    
    int ret = access(path, F_OK);
    
    //如果文件不存在，新建该文件
    if (ret < 0) {
        *fpp = fopen(path, "wb+");
        if (*fpp==NULL)
            return ERROR;
    }
    //如果存在
    else{
        *fpp = fopen(path, "rb+");
        if (*fpp==NULL)
            return ERROR;
    }
    return SUCCESS;
}
void closeGlobalInfoFile(FILE *fp){
    if (fp == NULL) {
        return;
    }
    fclose(fp);
};
void initGlobalInfo(GlobalInfo **info){
    *info = (GlobalInfo *)malloc(sizeof(GlobalInfo));
    memset(*info, 0, sizeof(GlobalInfo));
};
void enterGlobalInfoDataBeforeSaving(GlobalInfo *info){
    enterDataForAllGoodsInfo(info);
    enterDataForGoodsBagInfo(info);
    enterDataForAllToolsInfo(info);
    enterDataForToolsBagInfo(info);
};
void freeGlobalInfo(GlobalInfo *info){
    if (info == NULL) {
        return;
    }
    free(info);
};
int toWriteGlobalInfo(FILE *fp, GlobalInfo *info){
    if (fp==NULL || info==NULL) {
        perror("pointer cannot be null");
        return ERROR;
    }
    
    int fd = fileno(fp);
    int ret = ftruncate(fd, 0);
    if (ret < 0) {
        return ERROR;
    }
    
    fwrite(info, sizeof(GlobalInfo), 1, fp);
    return SUCCESS;
};
int toReadGlobalInfo(FILE *fp, GlobalInfo *info){
    if (fp == NULL || info == NULL) {
        perror("pointer cannot be null");
        return ERROR;
    }
    fread(info, sizeof(GlobalInfo), 1, fp);
    return SUCCESS;
};
int getGoodsBagCapacity(GlobalInfo *info, int bag_level){
    if (info == NULL) {
        printf("Info pointer is NULL.\n");
        return ERROR;
    }
    
    int i = 0;
    for (; i<GOODSBAGINFO_MAX; i++) {
        if (info->goodsbag_info.levels[i].bag_level == bag_level)
            return info->goodsbag_info.levels[i].bag_capacity;
    }
    
    return ERROR;
}
int getToolsBagCapacity(GlobalInfo *info, int bag_level){
    if (info == NULL) {
        printf("Info pointer is NULL. \n");
        return ERROR;
    }
    
    int i = 0;
    for (; i<TOOLSBAGINFO_MAX; i++) {
        if (info->toolsbag_info.info[i].bag_level == bag_level)
            return info->toolsbag_info.info[i].bag_capacity;
    }
    return ERROR;
};
GoodsDetail *getGoodsDetailById(GlobalInfo *info, int goods_id){
    if (info == NULL) {
        printf("GlobalInfo cannot be NULL\n");
        return NULL;
    }
    
    for (int i = 0; i<ALLGOODSINFO_MAX; i++) {
        if (info->allgoods_info.detail[i].goods_id == goods_id)
            return &info->allgoods_info.detail[i];
    }
    return NULL;
}
ToolDetail  *getToolDetailById(GlobalInfo *info, int tool_id){
    if (info == NULL) {
        printf("GlobalInfo cannot be NULL\n");
        return NULL;
    }
    
    for (int i = 0; i<ALLTOOLSINFO_MAX; i++) {
        if (info->alltools_info.detail[i].tool_id == tool_id)
            return &info->alltools_info.detail[i];
    }
    return NULL;
}


