package com.zeroone.star.procmanager.controller;


import com.zeroone.star.procmanager.entity.PpEApplication;
import com.zeroone.star.procmanager.service.AppService;
import com.zeroone.star.procmanager.service.ApplicationService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.procmanager.application.manage.ApplicationPropertiesDto;
import com.zeroone.star.project.j4.procmanager.application.ApplicationManageApis;
import com.zeroone.star.project.query.j4.procmanager.application.manage.ApplicationQuery;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.procmanager.QueryOrgMemberVO.QueryOrgMemberVO;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.IdentityVo;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.ApplicationPropertiesVo;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.ApplicationVo;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.CategoryVo;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.swing.tree.TreeNode;
import javax.validation.constraints.NotEmpty;
import java.util.List;

@RestController
@RequestMapping("/application-manage")
@Api(tags = "流程应用管理")
@Validated
public class ApplicatoinController implements ApplicationManageApis {

    @Autowired
    ApplicationService applicationService;

    @Autowired
    AppService appService;

    @Override
    @ApiOperation("获取组织成员名称树")
    @GetMapping("organization-member-tree")
    public JsonVO<List<QueryOrgMemberVO>> queryOrganizationMemberTree() {
        List<QueryOrgMemberVO> node = appService.queryOrganizationMemberTree();
        return JsonVO.success(node);
    }

    @Override
    @ApiOperation("获取组织名称树")
    @GetMapping("organization-tree")
    public JsonVO<List<QueryOrgMemberVO>> queryOrganizationTree(@RequestParam(value = "keywords", required = false) String keywords) {
        List<QueryOrgMemberVO> node = appService.queryOrganizationTree(keywords);
        return JsonVO.success(node);
    }

    @Override
    @ApiOperation("分页获取人员名称列表")
    @GetMapping("identity")
    public JsonVO<PageDTO<IdentityVo>> queryIdentityList(@RequestParam(value = "keywords", required = false) String keywords) {
        return null;
    }
    @Override
    @ApiOperation("查询所有应用类型")
    @GetMapping("application-category")
    public JsonVO<List<CategoryVo>> queryCategoryAll() {
        return JsonVO.success(applicationService.listAndCountApplicationCategory());
    }

    @Override
    @ApiOperation("查询所有应用")
    @GetMapping("application")
    public JsonVO<PageDTO<ApplicationVo>> queryApplicationAll(@Validated ApplicationQuery query) {
        return JsonVO.success(applicationService.listApplication(query));
    }

    public JsonVO<ApplicationPropertiesVo> queryApplicationOne(@NotEmpty String id) {
        return queryApplicationById(id);
    }

    @Override
    @ApiOperation("查询应用的属性")
    @GetMapping("application-properties")
    public JsonVO<ApplicationPropertiesVo> queryApplicationById(String id) {
        return JsonVO.success(applicationService.getApplication(id));
    }

    @PutMapping("add-application")
    @ApiOperation("新增应用")
    public JsonVO<ApplicationPropertiesVo> addApplication(@RequestBody ApplicationPropertiesDto applicationPropertiesDTO) throws Exception{

        boolean flag =  appService.addApplication(applicationPropertiesDTO);

        String msg = "新增失败";

        if(flag){
            msg = "新增成功";
            return new JsonVO<>(200,msg,null);
        }

        return new JsonVO<>(200,msg,null);

    }

    @PostMapping("/update-application")
    @ApiOperation("修改应用信息")
    public JsonVO<ApplicationPropertiesVo> updateApplication(ApplicationPropertiesDto applicationPropertiesDTO)
    {

        //flag标识数据库数据是否修改成功
        boolean flag =  appService.updateApplication(applicationPropertiesDTO);
        if(flag){
            return new JsonVO<>(200,"修改成功",null);
        }
        return new JsonVO<>(200,"修改失败",null);
    }

    @DeleteMapping("/delete-application/{id}")
    @ApiOperation("删除应用")
    public JsonVO deleteApplication(@PathVariable String id){
        //flag标识数据库数据是否删除成功
        boolean flag = appService.deleteApplication(id);

        if(flag){
            return new JsonVO<>(200,"删除成功",null);
        }

        return new JsonVO<>(200,"删除失败",null);
    }
}
