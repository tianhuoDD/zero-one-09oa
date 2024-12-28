package com.zeroone.star.bizcenter.service.impl;


import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.bizcenter.entity.PpCTask;
import com.zeroone.star.bizcenter.entity.QryItem;
import com.zeroone.star.bizcenter.mapper.QryItemMapper;
import com.zeroone.star.bizcenter.service.IQryItemService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.lang.reflect.Field;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-25
 */
@Service
public class QryItemServiceImpl extends ServiceImpl<QryItemMapper, QryItem> implements IQryItemService {

    @Autowired
    private QryItemMapper qryItemMapper;

    /**
     * 将ppCTask对象的属性名 批量插入到qry_item表的path1字段中 ；
     * 将对应的ppCTask对象的属性值 批量插入到qry_item表的xstringLongValue字段中
     *
     * @param ppCTask
     */

    public void saveItem(PpCTask ppCTask) {
        List<QryItem> items = new ArrayList<>();
        // 获取ppCTask对象的Class对象
        Class<?> clazz = ppCTask.getClass();
        // 获取所有属性（包括私有属性）
        Field[] fields = clazz.getDeclaredFields();

        for (Field field : fields) {
            try {
                // 设置属性可访问，包括私有属性
                field.setAccessible(true);
                // 获取属性名
                String fieldName = field.getName();
                // 获取属性值
                Object fieldValue = field.get(ppCTask);
                // 创建QryItem对象并设置属性
                //这里无法编译
               /* QryItem item = new QryItem();
                String uuid = UUID.randomUUID().toString();
                item.setXid(uuid);
                item.setXcreateTime(LocalDateTime.now());
                item.setXsequence(LocalDateTime.now()+uuid);
                item.setXupdateTime(LocalDateTime.now());
                item.setXbundle(ppCTask.getXjob());
                item.setXitemCategory("string");
                item.setXpath0("$work");


                item.setXitemCategory("pp");
                item.setXitemPrimitiveType("s");
                item.setXitemStringValueType("s");
                item.setXitemType("p");
                item.setXpath0Location(-1);
                item.setXpath1Location(-1);
                item.setXpath2Location(-1);
                item.setXpath3Location(-1);
                item.setXpath4Location(-1);
                item.setXpath5Location(-1);
                item.setXpath6Location(-1);

                item.setXpath1(fieldName);
                item.setXstringShortValue(fieldValue != null ? fieldValue.toString() : null);
                items.add(item);*/


            } catch (IllegalAccessException e) {
                e.printStackTrace();
            }
        }
        // 批量插入到数据库
        qryItemMapper.saveItems(items);
    }
}
