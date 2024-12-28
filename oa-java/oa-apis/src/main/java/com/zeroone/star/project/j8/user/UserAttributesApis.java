package com.zeroone.star.project.j8.user;

import com.zeroone.star.project.dto.j8.user.user_attributes.UserAttributesDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.user.user_attributes.UserAttributesVO;

import java.util.ArrayList;
import java.util.List;

public interface UserAttributesApis {

    /**
     * 根据人物id和属性id查询人物属性
     * @param userAttributesQuery
     * @return JsonVO<List<UserAttributesVO>>
     */
    JsonVO<List<UserAttributesVO>> query(String userAttributesQuery);

    /**
     * 根据属性id修改属性信息
     * @param userAttributesDTO
     * @return JsonVO<String>
     */
    JsonVO<String> update(UserAttributesDTO userAttributesDTO);

    /**
     * 根据属性id列表批量删除
     * @param xidList
     * @return JsonVO<String>
     */
    JsonVO<String> deleteByids(ArrayList<String> xidList);

    /**
     * 根据属性id删除
     * @param xid
     * @return JsonVO<String>
     */
    JsonVO<String> deleteByid(String xid);


    /**
     * 通过人物id以及对应的属性信息入库
     * @param userAttributesDTO
     * @return
     */
    JsonVO<String> save(UserAttributesDTO userAttributesDTO);
}
