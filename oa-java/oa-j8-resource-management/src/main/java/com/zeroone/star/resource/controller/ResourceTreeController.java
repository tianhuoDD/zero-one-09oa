package com.zeroone.star.resource.controller;

import com.zeroone.star.project.j8.resource.ResourceTreeApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.resource.resource_tree.ResourceTreeVO;
import com.zeroone.star.resource.services.OrgMenuService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import java.util.List;
import javax.annotation.Resource;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@Api(tags = "资源树")
@RestController
@RequestMapping("/org/menu/resource")
@RequiredArgsConstructor
public class ResourceTreeController implements ResourceTreeApis {


    @Resource
    private OrgMenuService orgMenuService;

    /**
     * 获取资源名称树
     */
    @ApiOperation("获取资源名称树")
    @GetMapping("/tree")
    public JsonVO<List<ResourceTreeVO>> getResourceTree() {
       List<ResourceTreeVO> resourceTree= orgMenuService.getResourceTree();
       return JsonVO.success(resourceTree);
    }
}
