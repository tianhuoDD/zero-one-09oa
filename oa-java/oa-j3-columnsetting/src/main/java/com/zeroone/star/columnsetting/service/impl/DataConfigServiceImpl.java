package com.zeroone.star.columnsetting.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.IdWorker;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.columnsetting.entity.CmsAppdictitem;
import com.zeroone.star.columnsetting.entity.CmsAppndict;
import com.zeroone.star.columnsetting.mapper.CmsAppdictitemMapper;
import com.zeroone.star.columnsetting.mapper.CmsAppndictMapper;
import com.zeroone.star.columnsetting.service.IDataConfigService;
import com.zeroone.star.columnsetting.utils.JsonParse;
import com.zeroone.star.project.j3.datacofig.dto.DataConfigDTO;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author luo
 * @since 2024-10-20
 */
@Service
public class DataConfigServiceImpl extends ServiceImpl<CmsAppdictitemMapper, CmsAppdictitem> implements IDataConfigService {


    @Resource
    CmsAppdictitemMapper itemMapper;

    @Resource
    CmsAppndictMapper dictMapper;

    @Resource
    JsonParse jsonParse;

    /**
     * 删除配置
     *
     * @param id 数据配置的id
     * @return 删除的数据配置的id
     */
    @Transactional
    @Override
    public String removeById(String id) {
       //删除目录数据
        dictMapper.deleteById(id);
       //删除详细数据
        LambdaQueryWrapper<CmsAppdictitem> wrapper = new LambdaQueryWrapper<CmsAppdictitem>()
                .eq(CmsAppdictitem::getXbundle,id);
        itemMapper.delete(wrapper);
        return id;
    }

    /**
     * 添加数据配置接口
     *
     * @param dataConfigDTO 接收的数据配置参数
     * @return 数据配置的id
     */
    @Transactional
    @Override
    public String saveDataConfig(DataConfigDTO dataConfigDTO) {
        //向目录表插入数据
        //拷贝数据
        CmsAppndict cmsAppndict = new CmsAppndict();
        cmsAppndict.setXname(dataConfigDTO.getName());
        cmsAppndict.setXalias(dataConfigDTO.getAlias());
        cmsAppndict.setXappId(dataConfigDTO.getAppid());
        cmsAppndict.setXdescription(dataConfigDTO.getDescription());
        //手动设置数据
        cmsAppndict.setXcreateTime(LocalDateTime.now());
        cmsAppndict.setXupdateTime(LocalDateTime.now());
        //使用雪花算个生成id
        String dictId = IdWorker.getIdStr();
        cmsAppndict.setXid(dictId);
        //设置xsequence
        DateTimeFormatter pattern = DateTimeFormatter.ofPattern("yyyyMMddHHmmss");
        String formatTime = LocalDateTime.now().format(pattern);
        cmsAppndict.setXsequence(formatTime+dictId);


        //插入数据
        dictMapper.insert(cmsAppndict);

        //向详细表插入数据
        ArrayList<CmsAppdictitem> appdictitems = jsonParse.
                jsonToCmsAppdictitemList(dataConfigDTO.getData(), dataConfigDTO.getAppid(), dictId);

        boolean b=false;
        //插入数据
        if (!appdictitems.isEmpty()){
             b = saveBatch(appdictitems,100);
        }
        if (b){
            return dictId;
        }

        return "插入失败";
    }

    /**
     * 修改配置接口
     *
     * @param dataConfigDTO 接收的数据配置参数
     * @return 数据配置的id
     */
    @Transactional
    @Override
    public String update(DataConfigDTO dataConfigDTO) {
        //更新目录表
        //构建cmsappndict对象
       CmsAppndict cmsAppndict = new CmsAppndict();
       cmsAppndict.setXid(dataConfigDTO.getId());
       cmsAppndict.setXupdateTime(LocalDateTime.now());
       cmsAppndict.setXalias(dataConfigDTO.getAlias());
       cmsAppndict.setXdescription(dataConfigDTO.getDescription());
       cmsAppndict.setXname(dataConfigDTO.getName());
       //更新数据库
        dictMapper.updateById(cmsAppndict);

        //更新详细数据
        ArrayList<CmsAppdictitem> appdictitems = jsonParse
                .jsonToCmsAppdictitemList(dataConfigDTO.getData(), dataConfigDTO.getAppid(), dataConfigDTO.getId());
        //删除原来的数据
        LambdaQueryWrapper<CmsAppdictitem> wrapper = new LambdaQueryWrapper<CmsAppdictitem>()
                .eq(CmsAppdictitem::getXbundle,dataConfigDTO.getId());
        itemMapper.delete(wrapper);
        //重新插入数据
        //插入数据
        if (!appdictitems.isEmpty()){
            boolean b = saveBatch(appdictitems,100);
            if (b){
                return dataConfigDTO.getId();
            }
        }

        return "更新失败";
    }


}















