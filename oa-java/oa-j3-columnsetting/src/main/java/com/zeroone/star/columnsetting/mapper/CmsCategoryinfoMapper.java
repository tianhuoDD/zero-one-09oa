package com.zeroone.star.columnsetting.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.columnsetting.entity.CmsCategoryinfo;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author jungle
 * @since 2024-10-22
 */
@Mapper
public interface CmsCategoryinfoMapper extends BaseMapper<CmsCategoryinfo> {

    public int addManageablegroupList(String categoryId);
    public int updateManageablegroupList(String manageablegroupList, String categoryId);
    public void deleteManageablegroupList(String xid);
    public int addManageablepersonList(String categoryId);
    public int updateManageablepersonList(String manageablepersonList, String categoryId);
    public void deleteManageablepersonList(String xid);
    public int addManageableunitList(String categoryId);
    public int updateManageableunitList(String manageableunitList, String categoryId);
    public void deleteManageableunitList(String xid);

    public int addPublishablegroupList(String categoryId);
    public int updatePublishablegroupList(String publishablegroupList, String categoryId);
    public void deletePublishablegroupList(String xid);
    public int addPublishablepersonList(String categoryId);
    public int updatePublishablepersonList(String publishablepersonList, String categoryId);
    public void deletePublishablepersonList(String xid);
    public int addPublishableunitList(String categoryId);
    public int updatePublishableunitList(String publishableunitList, String categoryId);
    public void deletePublishableunitList(String xid);

    public int addViewablegroupList(String categoryId);
    public int updateViewablegroupList(String viewablegroupList, String categoryId);
    public void deleteViewablegroupList(String xid);
    public int addViewablepersonList(String categoryId);
    public int updateViewablepersonList(String viewablepersonList, String categoryId);
    public void deleteViewablepersonList(String xid);
    public int addViewableunitList(String categoryId);
    public int updateViewableunitList(String viewableunitList, String categoryId);
    public void deleteViewableunitList(String xid);

    public String getManageablegroupList(String categoryId);
    public String getManageablepersonList(String categoryId);
    public String getManageableunitList(String categoryId);
    public String getPublishablegroupList(String categoryId);
    public String getPublishablepersonList(String categoryId);
    public String getPublishableunitList(String categoryId);
    public String getViewablegroupList(String categoryId);
    public String getViewablepersonList(String categoryId);
    public String getViewableunitList(String categoryId);
}
