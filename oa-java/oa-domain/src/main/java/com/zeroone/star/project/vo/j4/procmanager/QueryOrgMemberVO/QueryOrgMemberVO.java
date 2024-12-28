package com.zeroone.star.project.vo.j4.procmanager.QueryOrgMemberVO;

import com.zeroone.star.project.utils.tree.TreeNode;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

@EqualsAndHashCode(callSuper = true)
@Data
public class QueryOrgMemberVO extends TreeNode {
    @ApiModelProperty(value = "唯一标识", example = "1")
    private String xid;
    @ApiModelProperty(value = "名称", example = "张三")
    private String xname;
    @ApiModelProperty(value = "图标", example = "dashboard")
    private String xicon;
    @ApiModelProperty(value = "父节点", example = "null")
    private String xpid;
    @ApiModelProperty(value = "子节点", example = "null")
    private QueryOrgMemberVO children;
}
