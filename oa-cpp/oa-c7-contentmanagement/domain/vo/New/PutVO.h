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



//logo: ��Ŀ��ʶ
//name : ��Ŀ����
//as : ��Ŀ����
//ds : ��Ŀ����
//sort1 : ��Ŀ����
//type : ��Ŀ����
//document : �ĵ�����
//ignore : ���Ա���
//check : ���ݸ�
//timed : ��ʱ��ͼ
//column : ��Ŀ��ͼ
//autosave : �Զ�����
//edit : Ĭ�ϱ༭��
//read : Ĭ���Ķ���
class PutJsonVO : public JsonVO<PutDTO::Wrapper>
{
    DTO_INIT(PutJsonVO, JsonVO<PutDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)


#endif