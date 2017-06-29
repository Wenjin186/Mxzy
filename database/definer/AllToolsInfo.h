//
//  AllToolsInfo.h
//  mxzydatabase
//
//  Created by Wenjin Zhang on 2017/6/23.
//  Copyright © 2017年 Wenjin Zhang. All rights reserved.
//

#ifndef AllToolsInfo_h
#define AllToolsInfo_h

#define TOOLNAME_LENGTH 20
#define ALLTOOLSINFO_MAX 3

typedef struct tool_detail{
    int tool_id;
    char tool_name[TOOLNAME_LENGTH];
}ToolDetail;

typedef struct alltools_info{
    ToolDetail detail[ALLTOOLSINFO_MAX];
}AllToolsInfo;

#endif /* AllToolsInfo_h */
