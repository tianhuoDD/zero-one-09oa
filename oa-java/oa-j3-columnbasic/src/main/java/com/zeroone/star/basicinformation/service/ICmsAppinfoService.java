package com.zeroone.star.basicinformation.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.basicinformation.entity.CmsAppinfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.appinfo.dto.AppDTO;
import com.zeroone.star.project.j3.appinfo.dto.AppTypeDTO;
import com.zeroone.star.project.j3.appinfo.query.AppQuery;
import com.zeroone.star.project.j3.columnbasicinformation.dto.AppinfoDTO;
import com.zeroone.star.project.j3.columnbasicinformation.dto.BasicinformationDTO;
import com.zeroone.star.project.j3.columnbasicinformation.query.BasicinformationQuery;
import com.zeroone.star.project.j3.columnbasicinformation.vo.BasicinformationVo;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 */
public interface ICmsAppinfoService extends IService<CmsAppinfo> {
    //查询所有的栏目类型及其对应的个数
    List<AppTypeDTO> listAllType();

    //查询栏目基础信息
    BasicinformationVo queryBasicinformation(BasicinformationQuery basicinformationQuery);

    //修改栏目信息
    BasicinformationVo updateBasicinformation(BasicinformationDTO basicinformationDTO);

    //根据条件查询栏目
    PageDTO<AppDTO> listApp(AppQuery condition);

    //添加栏目
    String addColumn(AppinfoDTO appinfoDTO);

    //删除栏目
    Integer deleteColumn(String xid);


}
