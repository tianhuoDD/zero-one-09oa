package com.zeroone.star.oaj2sysbasic.service;

import com.zeroone.star.project.vo.j2.system.basic.information.SystemBasicInformationVO;

/**
 * @ClassName: SystemBasicInformationService
 * @Package: com.zeroone.star.oaj2sysbasic.service
 * @Description: 系统基本信息service层接口
 * @Author: zk
 * @Create: 2024/10/24 - 下午12:27
 */
public interface SystemBasicInformationService {
    /**
    * description：获取系统的基本信息
    * @return 信息的基本信息VO对象
    */

    SystemBasicInformationVO getSysBasicInfo();

    /**
    * description：修改系统标题
    * @param sysTitle 系统标题
     * @return 是否修改成功
    */

    String updateSysTitle(String sysTitle);

    /**
    * description：修改系统副标题
    * @param sysFooter 系统副标题，底部申明
    * @return 是否修改成功
    */
    String updateSysFooter(String sysFooter);
}
