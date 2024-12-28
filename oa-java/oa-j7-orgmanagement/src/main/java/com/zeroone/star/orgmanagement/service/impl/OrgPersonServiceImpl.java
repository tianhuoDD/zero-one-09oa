package com.zeroone.star.orgmanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.alibaba.excel.EasyExcel;
import com.zeroone.star.orgmanagement.entity.EasyExcelOrgPerson;
import com.zeroone.star.orgmanagement.entity.OrgPerson;
import com.zeroone.star.orgmanagement.listen.UserListener;
import com.zeroone.star.orgmanagement.mapper.OrgPersonMapper;
import com.zeroone.star.orgmanagement.service.IOrgPersonService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author zlw
 * @since 2024-10-18
 */
@Service
public class OrgPersonServiceImpl extends ServiceImpl<OrgPersonMapper, OrgPerson> implements IOrgPersonService {

    @Autowired
    private OrgPersonMapper orgPersonMapper;

    @Override
    public void importPerson(MultipartFile file) {
        String fileName = file.getOriginalFilename();
        EasyExcel.read(fileName, EasyExcelOrgPerson.class,new UserListener(this)).sheet().doRead();
    }

    @Override
    public void exportPerson() {
     String fileName = "组织管理人员导出.xlsx";  //输出文件名

        //查找数据
        List<OrgPerson> orgPersonList = orgPersonMapper.selectList(null);
        //转换数据
        List<EasyExcelOrgPerson> easyExcelOrgPersonList = BeanUtil.copyToList(orgPersonList, EasyExcelOrgPerson.class);
        EasyExcel.write(fileName, EasyExcelOrgPerson.class)
             .sheet("人员导出信息")
             .doWrite(easyExcelOrgPersonList);
    }
}
