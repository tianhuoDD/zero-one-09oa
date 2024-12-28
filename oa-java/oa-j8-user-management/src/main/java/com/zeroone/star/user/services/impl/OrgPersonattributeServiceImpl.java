package com.zeroone.star.user.services.impl;

import cn.hutool.core.date.DateTime;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j8.user.user_attributes.UserAttributesDTO;
import com.zeroone.star.project.dto.j8.user.user_attributes.UserAttributesDTO1;
import com.zeroone.star.project.vo.j8.user.user_attributes.UserAttributesVO;
import com.zeroone.star.user.entity.OrgPersonattribute;
import com.zeroone.star.user.entity.OrgPersonattributeAttributelist;
import com.zeroone.star.user.mapper.OrgPersonattributeAttributelistMapper;
import com.zeroone.star.user.mapper.OrgPersonattributeMapper;
import com.zeroone.star.user.services.OrgPersonattributeAttributelistService;
import com.zeroone.star.user.services.OrgPersonattributeService;
import java.util.ArrayList;
import java.util.List;
import javax.annotation.Resource;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_personattribute】的数据库操作Service实现
 * @createDate 2024-10-24 20:49:30
 */

@Service
public class OrgPersonattributeServiceImpl extends ServiceImpl<OrgPersonattributeMapper, OrgPersonattribute>
    implements OrgPersonattributeService {

    @Resource
    private OrgPersonattributeMapper personAttributeMapper;
    @Resource
    private OrgPersonattributeAttributelistMapper personAttributeListMapper;
    @Resource
    private OrgPersonattributeAttributelistService personAttributeListService;

    /**
     * 根据id查询人物属性
     * @param personId
     * @return List<UserAttributesVO>
     */
    @Override
    public List<UserAttributesVO> queryById(String personId) {
        List<UserAttributesDTO1> userAttributesDTOS = personAttributeMapper.queryById(personId);
        List<UserAttributesVO> userAttributesVOList = new ArrayList<>();
        for (UserAttributesDTO1 userAttributesDTO : userAttributesDTOS) {
            String xId = userAttributesDTO.getXid();
            String personAttributeList = personAttributeListMapper.getByPersonAttributeXid(xId);
            userAttributesVOList.add(UserAttributesVO.builder()
                    .xName(userAttributesDTO.getXName())
                    .xDescription(userAttributesDTO.getXDescription())
                    .xAttribute(personAttributeList)
                    .build());
        }
        return userAttributesVOList;
    }

    /**
     * 将数据保存到数据库中
     */
    @Override
    @Transactional
    public void save(UserAttributesDTO userAttributesDTO) {
        // 生成一个唯一属性id
        String xPerson = userAttributesDTO.getXPerson();
        String nowTime = DateTime.now().toString("yyyy-MM-dd-HH-mm-ss");
        String xid = xPerson + "-" + nowTime;
        // 将数据保存到对应的两个表
        OrgPersonattribute orgPersonattribute = OrgPersonattribute.builder()
                .xid(xid)
                .xperson(userAttributesDTO.getXPerson())
                .xname(userAttributesDTO.getXName())
                .xdescription(userAttributesDTO.getXDescription())
                .xcreatetime(DateTime.now())
                .xupdatetime(DateTime.now())
                .xunique(xid)
                .build();
        this.save(orgPersonattribute);

        OrgPersonattributeAttributelist orgPersonattributeAttributelist = OrgPersonattributeAttributelist.builder()
                .personattributeXid(xid)
                .xattributelist(userAttributesDTO.getXAttributeList())
                .build();
        personAttributeListService.save(orgPersonattributeAttributelist);
    }

    /**
     *根据属性ID删除对应属性信息
     */
    @Override
    @Transactional
    public void deleteByXId(String xid) {
        LambdaUpdateWrapper<OrgPersonattribute> qw = new LambdaUpdateWrapper<>();
        qw.eq(xid != null, OrgPersonattribute::getXid, xid);
        personAttributeMapper.delete(qw);
        LambdaUpdateWrapper<OrgPersonattributeAttributelist> lqw = new LambdaUpdateWrapper<>();
        lqw.eq(xid != null,OrgPersonattributeAttributelist::getPersonattributeXid,xid);
        personAttributeListMapper.delete(lqw);

    }

    /**
     * 根据属性id列表进行批量删除
     */

    @Override
    @Transactional
    public void deleteByXIds(List<String> xidList) {
        personAttributeMapper.deleteByXIds(xidList);
        personAttributeListMapper.deleteByXIds(xidList);
    }

    @Override
    @Transactional
    public void update(UserAttributesDTO userAttributesDTO) {
        String xid = userAttributesDTO.getXid();
        if (xid == null) return;
        String xAttributeList = userAttributesDTO.getXAttributeList();
        if (xAttributeList != null){
            LambdaUpdateWrapper<OrgPersonattributeAttributelist> lqw = new LambdaUpdateWrapper<>();
            lqw.set(OrgPersonattributeAttributelist::getXattributelist, xAttributeList);
            lqw.eq(OrgPersonattributeAttributelist::getPersonattributeXid, xid);
            personAttributeListMapper.update(null, lqw); // 注意这里传入 null
        }
        LambdaUpdateWrapper<OrgPersonattribute> qw = new LambdaUpdateWrapper<>();
        qw.set(userAttributesDTO.getXName() != null, OrgPersonattribute::getXname, userAttributesDTO.getXName());
        qw.set(userAttributesDTO.getXDescription() != null, OrgPersonattribute::getXdescription, userAttributesDTO.getXDescription());
        qw.eq(OrgPersonattribute::getXid, xid);
        personAttributeMapper.update(null, qw); // 注意这里传入 null
    }

}




