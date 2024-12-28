#pragma once
#pragma once
#pragma once

#ifndef _PUTVO_H_
#define _PUTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/New/NewDTO.h"
#include "../../vo/New/PutVO.h"
#include "../../dto/New/PutDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)



//logo: 栏目标识
//name : 栏目名称
//as : 栏目别名
//ds : 栏目描述
//sort1 : 栏目排序
//type : 栏目类型
//document : 文档类型
//ignore : 忽略标题
//check : 检查草稿
//timed : 定时视图
//column : 栏目视图
//autosave : 自动保存
//edit : 默认编辑表单
//read : 默认阅读表单
class PutJsonVO : public JsonVO<PutDTO::Wrapper>
{
    DTO_INIT(PutJsonVO, JsonVO<PutDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)


#endif