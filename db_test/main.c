//
//  main.c
//  db_test
//
//  Created by Wenjin Zhang on 2017/6/19.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#include <stdio.h>
#include "../database/MxzyDatabase.h"


void mxzyRead(){
    FILE *fp = NULL;
    CharacterTable *table;
    int ret = createOrGetLocalStorage(&fp, "test.bin");
    
    if (ret == ERROR) {
        perror("get failure");
        return;
    }
    
    initCharacterTable(&table);
    
    toReadData(fp, table);
    printf("row1 = %d\n", table->c1.character_id);
    printf("row2 = %d\n", table->c2.character_id);
    printf("row3 = %d\n", table->c3.character_id);
    
    freeCharacterTable(table);
    closeLocalStorage(fp);
}

void mxzyWrite(){
    FILE *fp = NULL;
    CharacterTable *table;
    int ret = createOrGetLocalStorage(&fp, "test.bin");
    
    if (ret == ERROR) {
        perror("create failure");
        return;
    }
    
    
    initCharacterTable(&table);
    
    createCharacter(table);
    createCharacter(table);
    createCharacter(table);
    ret = createCharacter(table);
    if (ret == ERROR) {
        printf("FULL\n");
    }
    printf("row1 = %d\n", table->c1.character_id);
    printf("row2 = %d\n", table->c2.character_id);
    printf("row3 = %d\n", table->c3.character_id);
    
    
    ret = toWriteData(fp, table);
    if (ret == ERROR) {
        printf("no writing operation\n");
    }
    
    freeCharacterTable(table);
    
    closeLocalStorage(fp);
}

void getCharacterData(){
    FILE *fp;
    CharacterTable *table;
    CharacterRow *row;
    
    int ret = createOrGetLocalStorage(&fp, "test.bin");
    if (ret == ERROR) {
        perror("error happened");
        return;
    }
    initCharacterTable(&table);
    toReadData(fp, table);
    
    ret = getCharacterRowById(&row, table, 1);
    if (ret == ERROR) {
        printf("hello world!\n");
        return;
    }
    
    setCharacterName(row, "张温金");
    printf("Current character name is %s\n", getCharacterName(row));
    
    freeCharacterTable(table);
    closeLocalStorage(fp);
}

void writeGlobalInfo(){
    FILE *fp = NULL;
    GlobalInfo *info = NULL;
    int ret = createOrGetGlobalInfoFile(&fp, "global.bin");
    if (ret == ERROR) {
        printf("error!\n");
        return;
    }
    initGlobalInfo(&info);
    
    enterGlobalInfoDataBeforeSaving(info);
    
    
    toWriteGlobalInfo(fp, info);
    freeGlobalInfo(info);
    closeGlobalInfoFile(fp);
}

void readGlobalInfo(){
    FILE *fp = NULL;
    GlobalInfo *info = NULL;
    int ret = createOrGetGlobalInfoFile(&fp, "global.bin");
    if (ret == ERROR) {
        printf("error!\n");
        return;
    }
    initGlobalInfo(&info);
    toReadGlobalInfo(fp, info);
    
//    printf("eggplat id is %d\n", info->allgoods_info.d1.goods_id);
//    printf("eggplat name is %s\n", info->allgoods_info.d1.goods_name);
//    printf("eggplat purchase price is %lf\n", info->allgoods_info.d1.purchase_price);

    int capacity = getGoodsBagCapacity(info, 3);
    printf("Goods bag capacity is %d.\n", capacity);
    
    GoodsDetail *d = getGoodsDetailById(info, 101);
    printf("Goods name is %s\n", d->goods_name);
    
    ToolDetail *tool = getToolDetailById(info, 11);
    printf("Tool name is %s\n", tool->tool_name);
    
    int tb_capacity = getToolsBagCapacity(info, 3);
    printf("ToolsBag capacity is %d\n", tb_capacity);
    
    freeGlobalInfo(info);
    closeGlobalInfoFile(fp);
}

void simulateStartGame(){
    FILE *fp = NULL;
    CharacterTable *table = NULL;
    CharacterRow *row = NULL;
    int ret = createOrGetLocalStorage(&fp, ".test.bin");
    if (ret == ERROR) {
        return;
    }
    
    initCharacterTable(&table);
    ret = toReadData(fp, table);
    if (ret == ERROR){
        memset(table, 0, sizeof(CharacterTable));
        printf("There is no character. Please create a new one to start the game!\n");
        int id = createCharacter(table);
        if (id==ERROR) {
            printf("Error happens\n");
            return;
        }
        getCharacterRowById(&row, table, id);
        setCharacterName(row, "小村长");
    }else{
        int id = 1;
        getCharacterRowById(&row, table, id);
    }
    
    printf("Character's name is %s\n", getCharacterName(row));
    
    toWriteData(fp, table);
    
    freeCharacterTable(table);
    closeLocalStorage(fp);
}

int main(int argc, const char * argv[]) {
    
    //mxzyRead();
    //getCharacterData();
    //mxzyWrite();
    //writeGlobalInfo();
    //readGlobalInfo();
    simulateStartGame();
    return 0;
}


