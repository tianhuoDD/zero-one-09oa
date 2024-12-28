package com.zeroone.star.user.controller;

import com.zeroone.star.project.dto.j8.user.user_attributes.UserAttributesDTO;
import com.zeroone.star.project.j8.user.UserAttributesApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.user_attributes.UserAttributesVO;
import com.zeroone.star.user.services.OrgPersonattributeService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import java.util.ArrayList;
import java.util.List;
import javax.annotation.Resource;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;

@Api(tags = "人物属性")
@Controller
@RequestMapping("/org/user/attribute")
public class UserAttributesController implements UserAttributesApis {

    @Resource
    private OrgPersonattributeService personAttributeService;
    /**
     * 根据人物id查询人物属性
     */
    @Override
    @GetMapping("/query")
    @ApiOperation("根据人物id查询人物属性")
    public JsonVO<List<UserAttributesVO>> query(String personId) {
        List<UserAttributesVO> userAttributesVOList = personAttributeService.queryById(personId);
        return JsonVO.success(userAttributesVOList);
    }

    /**
     * 根据属性id及属性相关信息修改
     */
    @Override
    @PutMapping("/update")
    @ApiOperation("根据属性id及属性相关信息修改")
    public JsonVO<String> update(@RequestBody UserAttributesDTO userAttributesDTO) {
        personAttributeService.update(userAttributesDTO);
        return JsonVO.success("修改成功！");
    }

    /**
     * 根据属性id列表进行批量删除
     */
    @DeleteMapping("/delete")
    @ApiOperation("根据属性id列表进行批量删除")
    @Override
    public JsonVO<String> deleteByids(@ModelAttribute ArrayList<String> xidList) {
        if (xidList == null){
            return JsonVO.fail("列表为空！");
        }
        personAttributeService.deleteByXIds(xidList);
        return null;
    }

    /**
     * 根据属性id删除
     */
    @Override
    @DeleteMapping("/delete/{xid}")
    @ApiOperation("根据属性id删除")
    public JsonVO<String> deleteByid(@PathVariable String xid) {
        personAttributeService.deleteByXId(xid);
        return JsonVO.success("删除成功！");
    }



    /**
     * 根据人物id及相关属性信息入库
     */
    @Override
    @PostMapping("save")
    @ApiOperation("根据人物id及相关属性信息入库")
    public JsonVO<String> save(@RequestBody UserAttributesDTO userAttributesDTO) {
        personAttributeService.save(userAttributesDTO);
        return JsonVO.success("保存成功");
    }
}
