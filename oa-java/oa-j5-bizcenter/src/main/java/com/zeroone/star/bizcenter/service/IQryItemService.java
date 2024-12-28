package com.zeroone.star.bizcenter.service;

import com.zeroone.star.bizcenter.entity.PpCTask;
import com.zeroone.star.bizcenter.entity.QryItem;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-25
 */
public interface IQryItemService extends IService<QryItem> {

    /**
     * 将ppCTask对象的属性名 批量插入到qry_item表的path1字段中 ；
     * 将对应的ppCTask对象的属性值 批量插入到qry_item表的xstringLongValue字段中
     *
     * @param ppCTask
     */
    public void saveItem(PpCTask ppCTask);

}
