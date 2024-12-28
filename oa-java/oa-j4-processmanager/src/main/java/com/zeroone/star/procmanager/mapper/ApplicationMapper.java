package com.zeroone.star.procmanager.mapper;

import com.zeroone.star.procmanager.entity.OrgPerson;
import com.zeroone.star.procmanager.entity.OrgUnit;
import com.zeroone.star.procmanager.entity.PpEApplication;
import com.zeroone.star.project.dto.j4.procmanager.application.manage.ApplicationPropertiesDto;
import com.zeroone.star.project.vo.j4.procmanager.QueryOrgMemberVO.QueryOrgMemberVO;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.procmanager.entity.PpEApplication;
import com.zeroone.star.project.query.j4.procmanager.application.manage.ApplicationQuery;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.ApplicationPropertiesVo;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.ApplicationVo;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.IdentityVo;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.UnitVo;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author nefertari
 * @since 2024-10-20
 */
@Mapper
public interface ApplicationMapper extends BaseMapper<PpEApplication> {
    /**
     *根据xid查询应用信息
     * @param xid
     * @return
     */
    PpEApplication selectById(String xid);

    /**
     * 插入应用
     * @param eApplication
     * @return
     */
    boolean insertApplication( PpEApplication eApplication);

    /**
     * 更新应用基本属性
     * @param eApplication
     * @return
     */
    boolean updateApplication(PpEApplication eApplication);

    /**
     * 根据id删除应用
     * @param id
     * @return
     */
    boolean deleteById(String id);

    /**
     * 查询所有组织
     * @return
     */
    List<OrgUnit> selectAllUnit();

    /**
     * 根据组织id查询人员id
     * @param xid
     * @return
     */
    String selectPersonIdByUnitId(String xid);

    /**
     * 根据id查找人员
     * @param id
     * @return
     */
    OrgPerson selectPersonById(String id);


    /**
     * 根据id查找所有可用组织
     * @param id
     * @return
     */
    List<String> selectAvailableUnitsById(@Param("xid")String id);

    /**
     * 根据id，可用组织列表和最大的order值插入可用组织
     * @param availableUnit
     * @param xid
     * @param startOrder
     */
    void insertAvailableIdentityUnit(@Param("availableUnit")List<String> availableUnit,@Param("xid") String xid,@Param("startOrder") int startOrder);

    /**
     * 根据id查找所有管理者
     * @param id
     * @return
     */
    List<String> selectControllersById(@Param("xid") String id);

    /**
     * 根据id，管理者列表和最大的order值插入管理者
     * @param controllers
     * @param xid
     * @param startOrder
     */
    void insertController(@Param("controllers") List<String> controllers,@Param("xid") String xid,@Param("startOrder") int startOrder );

    /**
     * 根据id查找可用身份
     * @param id
     * @return
     */
    List<String> selectIdentitiesById(@Param("xid") String id);

    /**
     * 根据id，可用身份列表和最大的order值插入可用身份
     * @param availableIdentities
     * @param xid
     * @param startOrde
     */
    void insertIdentities(@Param("availableIdentities") List<String> availableIdentities,@Param("xid") String xid,@Param("startOrder") int startOrde);

    /**
     * 获得最大的xorderColumn的值
     * @param id
     * @return
     */
    Integer getMaxUtilOrderColumn(@Param("xid") String id);

    /**
     * 根据id删除对应可用组织
     * @param id
     */
    void deleteAvailableIdentityUnitById(@Param("xid")String id);

    /**
     * 根据id删除对应管理者
     * @param id
     */
    void deleteControllerById(@Param("xid")String id);
    /**
     * 获得最大的xorderColumn的值
     * @param id
     * @return
     */
    Integer getMaxControllerOrderColumn(@Param("xid") String id);
    /**
     * 获得最大的xorderColumn的值
     * @param id
     * @return
     */
    Integer getMaxIdentityOrderColumn(@Param("xid") String id);

    /**
     * 根据id删除对应可用身份
     * @param id
     */
    void deleteIdentityById(@Param("xid") String id);


    List<OrgUnit> selectAllUnitByKeywords(String keywords);

    /**
     * 查询所有应用
     * @param page
     * @param query
     * @return
     */
    Page<ApplicationVo> selectApplication(Page<ApplicationVo> page, @Param("query") ApplicationQuery query);

    /**
     * 根据id查询应用属性
     * @param id
     * @return
     */
    ApplicationPropertiesVo selectApplicationById(@Param("xid") String id);


    /**
     * 根据应用查询可用身份
     * @param id
     * @return
     */
    List<IdentityVo> selectApplicationIdentityListById(@Param("APPLICATION_XID") String id);

    /**
     * 根据应用查询可用组织及组织树
     * @param id
     * @return
     */
    List<UnitVo> selectApplicationUnitListById(@Param("APPLICATION_XID") String id);

    /**
     * 根据应用查询管理者
     * @param id
     * @return
     */
    List<String> selectApplicationControllerListById(@Param("APPLICATION_XID") String id);
}
