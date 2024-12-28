package com.zeroone.star.project.j2.system.basic.information;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.system.basic.information.SystemBasicInformationVO;
import io.swagger.annotations.ApiModel;

/**
 * @ClassName: SystemInformationApis
 * @Package: com.zeroone.star.project.j2.system.basic.information
 * @Description: 系统基本信息api接口层
 * @Author: zk
 * @Create: 2024/10/20 - 下午5:19
 */
@ApiModel(description = "系统基本信息apis")
public interface SystemInformationApis {
    /**
     * description：获取系统基本信息
     *
     * @return 系统基本信息
     */
    JsonVO<SystemBasicInformationVO> queryBasicInfo();

    /**
     * description：修改系统名称
     *
     * @return 是否修改成功
     */
    JsonVO<String> modifySystemTitle(String systemTitle);

    /**
     * description：修改系统副标题
     *
     * @return 是否修改成功
     */
    JsonVO<String> modifySystemFooter(String systemFooter);
}
