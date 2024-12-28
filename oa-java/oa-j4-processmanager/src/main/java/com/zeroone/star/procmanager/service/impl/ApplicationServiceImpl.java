package com.zeroone.star.procmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.procmanager.entity.OrgIdentity;
import com.zeroone.star.procmanager.entity.PpEApplication;
import com.zeroone.star.procmanager.entity.PpEForm;
import com.zeroone.star.procmanager.mapper.ApplicationMapper;
import com.zeroone.star.procmanager.mapper.FormMapper;
import com.zeroone.star.procmanager.mapper.IdentityMapper;
import com.zeroone.star.procmanager.service.ApplicationService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j4.procmanager.application.manage.ApplicationQuery;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.ApplicationPropertiesVo;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.ApplicationVo;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.CategoryVo;
//import io.seata.spring.annotation.GlobalTransactional;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author nefertari
 * @since 2024-10-20
 */
@Service
//@GlobalTransactional
public class ApplicationServiceImpl extends ServiceImpl<ApplicationMapper, PpEApplication> implements ApplicationService {

    /**
     * 应用mapper
     */
    @Autowired
    ApplicationMapper applicationMapper;

    /**
     * 表单mapper
     */
    @Autowired
    FormMapper formMapper;
    /**
     * 成员认证mapper
     */

    @Autowired
    IdentityMapper identityMapper;
    /**
     * 查询所有应用分类和对应的应用的个数
     * @return
     */
    @Override
    public List<CategoryVo> listAndCountApplicationCategory() {
        // 构建查询条件
        QueryWrapper<PpEApplication> wrapper = new QueryWrapper<>();
        wrapper.select("xapplicationCategory category", "COUNT(xid) count")
                .ne("xapplicationCategory", "")
                .groupBy("xapplicationCategory");//查询每个类型及每个类型的应用个数
        // 执行查询
        List<Map<String, Object>> mapList = applicationMapper.selectMaps(wrapper);
        //转换 返回集合
        return mapList.stream().map(map -> {
                CategoryVo categoryVo = new CategoryVo();
                categoryVo.setName((String) map.get("category"));// 应用类型
                categoryVo.setCount((Long) map.get("count"));// 个数
                return categoryVo;
        }).collect(Collectors.toList());
    }

    /**
     * 查询所有应用
     * @return
     */
    @Override
    public PageDTO<ApplicationVo> listApplication(ApplicationQuery query) {
        // 构建分页对象
        Page<ApplicationVo> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //查询
        Page<ApplicationVo> applicationVoPage = applicationMapper.selectApplication(page, query);
        //创建分页模型 返回
        return PageDTO.create(applicationVoPage);
    }

    /**
     * 查询指定应用
     * @param id
     * @return
     */
    @Override
    public ApplicationPropertiesVo getApplication(String id) {
        //查询
        ApplicationPropertiesVo applicationPropertiesVos = applicationMapper.selectApplicationById(id);
        //构建查询流程维护人条件
        LambdaQueryWrapper<OrgIdentity> identityLambdaQueryWrapper = new LambdaQueryWrapper<>();
        identityLambdaQueryWrapper.select(OrgIdentity::getXname).eq(OrgIdentity::getXdistinguishedName, applicationPropertiesVos.getPropertiesVo().getMaintenanceIdentity());
        //执行查询 并赋值
        applicationPropertiesVos.getPropertiesVo().setMaintenanceIdentity(identityMapper.selectOne(identityLambdaQueryWrapper).getXname());
        //构建表单查询条件
        LambdaQueryWrapper<PpEForm> formLambdaQueryWrapper = new LambdaQueryWrapper<>();
        formLambdaQueryWrapper.select(PpEForm::getXname).eq(PpEForm::getXid, applicationPropertiesVos.getPropertiesVo().getDefaultForm());
        //执行查询 并复制
        applicationPropertiesVos.getPropertiesVo().setDefaultForm(formMapper.selectOne(formLambdaQueryWrapper).getXname());
        //返回vo
        return applicationPropertiesVos;
    }
}
