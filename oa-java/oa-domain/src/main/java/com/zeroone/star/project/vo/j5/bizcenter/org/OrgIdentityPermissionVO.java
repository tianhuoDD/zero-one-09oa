package com.zeroone.star.project.vo.j5.bizcenter.org;

import com.zeroone.star.project.dto.j5.bizcenter.org.OrgIdentityInfoDTO;
import com.zeroone.star.project.dto.j5.bizcenter.org.OrgPersonInfoDTO;
import com.zeroone.star.project.dto.j5.bizcenter.org.OrgUnitInfoDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 组织系统相关信息对象
 */
@Data
@ApiModel("组织系统相关信息对象")
public class OrgIdentityPermissionVO {
    @ApiModelProperty("单位信息对象")
    private OrgUnitInfoDTO woUnit;

    @ApiModelProperty("人员信息对象")
    private OrgPersonInfoDTO woPerson;

    @ApiModelProperty("身份信息对象")
    private OrgIdentityInfoDTO woIdentity;
}
