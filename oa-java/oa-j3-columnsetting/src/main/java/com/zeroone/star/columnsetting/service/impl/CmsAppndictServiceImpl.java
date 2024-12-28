package com.zeroone.star.columnsetting.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.columnsetting.entity.CmsAppdictitem;
import com.zeroone.star.columnsetting.entity.CmsAppndict;
import com.zeroone.star.columnsetting.mapper.CmsAppdictitemMapper;
import com.zeroone.star.columnsetting.mapper.CmsAppndictMapper;
import com.zeroone.star.columnsetting.service.ICmsAppndictService;
import com.zeroone.star.project.j3.dataconfig.vo.dataConfigDetailVO;
import com.zeroone.star.project.j3.dataconfig.vo.dataConfigVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author ikun
 * @since 2024-10-20
 */
@Service
public class CmsAppndictServiceImpl extends ServiceImpl<CmsAppndictMapper, CmsAppndict> implements ICmsAppndictService {

    @Resource
    private CmsAppndictMapper cmsAppndictMapper;

    @Resource
    private CmsAppdictitemMapper cmsAppdictitemMapper;

    @Override
    public List<dataConfigVO> getDataConfigList() {
        //查找所有数据配置
        List<CmsAppndict> list = cmsAppndictMapper.selectList(new QueryWrapper<>());
        //把数据配置对象转化为VO对象
        List<dataConfigVO> dataConfigVOList = list.stream().map(dataConfig -> {
            dataConfigVO dataConfigVO = new dataConfigVO();
            dataConfigVO.setId(dataConfig.getXid());
            dataConfigVO.setAppId(dataConfig.getXappId());
            dataConfigVO.setName(dataConfig.getXname());
            dataConfigVO.setAlias(dataConfig.getXalias());
            dataConfigVO.setDescription(dataConfig.getXdescription());
            dataConfigVO.setCreateTime(dataConfig.getXcreateTime());
            dataConfigVO.setUpdateTime(dataConfig.getXupdateTime());
            return dataConfigVO;
        }).collect(Collectors.toList());
        return dataConfigVOList;
    }

    @Override
    public dataConfigDetailVO  getDataConfig(String xid) {
        //查找相应xid的数据配置
        CmsAppndict cmsAppndict = cmsAppndictMapper.selectById(xid);
        //查找数据配置项的返回xpath0和xstringShortValue的为键值对的列表
        QueryWrapper<CmsAppdictitem> cmsAppdictitemQueryWrapper = new QueryWrapper<>();
        cmsAppdictitemQueryWrapper.eq("xappId",cmsAppndict.getXappId());
        List<CmsAppdictitem> cmsAppdictitems = cmsAppdictitemMapper.selectList(cmsAppdictitemQueryWrapper);
        Map<String,String> map=new HashMap<>();
        for (CmsAppdictitem item:cmsAppdictitems)
        {
            map.put(item.getXpath0(),item.getXstringShortValue());
        }
         dataConfigDetailVO dataConfigDetailvo= dataConfigDetailVO.builder()
                .id(cmsAppndict.getXid())
                .appId(cmsAppndict.getXappId())
                .name(cmsAppndict.getXname())
                .alias(cmsAppndict.getXalias())
                .description(cmsAppndict.getXdescription())
                .createTime(cmsAppndict.getXcreateTime())
                .updateTime(cmsAppndict.getXupdateTime())
                .data(map)
                .build();
         return dataConfigDetailvo;
    }

}
