#pragma once
#ifndef _MSGMESSAGEDO_H_
#define _MSGMESSAGEDO_H_
#include "../DoInclude.h"

class MsgMessageDO
{

    /**
    * ��ϢΨһ��ʶ��
    */
   // private String xid
    CC_SYNTHESIZE(string, xid, xid);
    /**
     * ��Ϣ���к�
     */
    CC_SYNTHESIZE(string, xsequence, xsequence);
    /**
     * ��Ϣ������ʱ��
     */
    CC_SYNTHESIZE(string, xupdateTime, xupdateTime);
    /**
     * ��Ϣ����ʱ��
     */
    CC_SYNTHESIZE(string, xcreateTime, xcreateTime);
    //private LocalDateTime xcreateTime;
    /**
     * ��Ϣ�ķַ�����
     */
    CC_SYNTHESIZE(int, xdistributeFactor, xdistributeFactor);
    /**
     * ��Ϣ�����ı�
     */
    CC_SYNTHESIZE(string, xbody, xbody);
    /**
     * ��Ϣ�Ƿ��ѱ����ѣ�����
     */
    CC_SYNTHESIZE(bool, xconsumed, xconsumed);
    /**
   * �������Ϣ�������߱�ʶ
   */
    CC_SYNTHESIZE(string, xconsumer, xconsumer);
   /**
    * ��Ϣ�Ƿ�Ϊ��ʱ���ͱ�ʶ
    */
    CC_SYNTHESIZE(string, xinstant, xinstant);
      /**
       * ��Ϣ�ķ����߱�ʶ
       */
    CC_SYNTHESIZE(string, xperson, xperson);    
       /**
        * �������ԣ��洢���������Ϣ
        */
    CC_SYNTHESIZE(string, xproperties, xproperties);
    /**
     * ��Ϣ����
     */
    CC_SYNTHESIZE(string, xtitle, xtitle);
    /**
     * ��Ϣ���ͣ����磺���š��ʼ��ȣ�
     */
    CC_SYNTHESIZE(string, xtype, xtype);

};


#endif // !_MSGMESSAGEDO_H_
