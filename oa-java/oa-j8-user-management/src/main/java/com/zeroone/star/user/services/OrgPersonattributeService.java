package com.zeroone.star.user.services;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j8.user.user_attributes.UserAttributesDTO;
import com.zeroone.star.project.vo.j8.user.user_attributes.UserAttributesVO;
import com.zeroone.star.user.entity.OrgPersonattribute;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_personattribute】的数据库操作Service
 * @createDate 2024-10-24 20:49:30
 */
public interface OrgPersonattributeService extends IService<OrgPersonattribute> {
    /**
     * 根据id查询数据
     * @param personId
     * @return List<UserAttributesVO>
     */
    List<UserAttributesVO> queryById(String personId);

    /**
     * 保存属性信息到库
     */
    void save(UserAttributesDTO userAttributesDTO);

    /**
     *根据属性id删除相关属性信息
     */
    void deleteByXId(String xid);

    /**
     *根据属性id列表进行批量删除
     */
    void deleteByXIds(List<String> xidList);


    void update(UserAttributesDTO userAttributesDTO);
}
