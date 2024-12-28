#pragma once
#ifndef _MSGMESSAGEDO_H_
#define _MSGMESSAGEDO_H_
#include "../DoInclude.h"

class MsgMessageDO
{

    /**
    * 消息唯一标识符
    */
   // private String xid
    CC_SYNTHESIZE(string, xid, xid);
    /**
     * 消息序列号
     */
    CC_SYNTHESIZE(string, xsequence, xsequence);
    /**
     * 消息最后更新时间
     */
    CC_SYNTHESIZE(string, xupdateTime, xupdateTime);
    /**
     * 消息创建时间
     */
    CC_SYNTHESIZE(string, xcreateTime, xcreateTime);
    //private LocalDateTime xcreateTime;
    /**
     * 消息的分发因子
     */
    CC_SYNTHESIZE(int, xdistributeFactor, xdistributeFactor);
    /**
     * 消息内容文本
     */
    CC_SYNTHESIZE(string, xbody, xbody);
    /**
     * 消息是否已被消费（处理）
     */
    CC_SYNTHESIZE(bool, xconsumed, xconsumed);
    /**
   * 处理该消息的消费者标识
   */
    CC_SYNTHESIZE(string, xconsumer, xconsumer);
   /**
    * 消息是否为即时发送标识
    */
    CC_SYNTHESIZE(string, xinstant, xinstant);
      /**
       * 消息的发送者标识
       */
    CC_SYNTHESIZE(string, xperson, xperson);    
       /**
        * 附加属性，存储其他相关信息
        */
    CC_SYNTHESIZE(string, xproperties, xproperties);
    /**
     * 消息标题
     */
    CC_SYNTHESIZE(string, xtitle, xtitle);
    /**
     * 消息类型（例如：短信、邮件等）
     */
    CC_SYNTHESIZE(string, xtype, xtype);

};


#endif // !_MSGMESSAGEDO_H_
