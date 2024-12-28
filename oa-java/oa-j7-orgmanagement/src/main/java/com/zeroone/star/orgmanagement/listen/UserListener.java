package com.zeroone.star.orgmanagement.listen;

import cn.hutool.core.bean.BeanUtil;
import com.alibaba.excel.context.AnalysisContext;
import com.alibaba.excel.event.AnalysisEventListener;
import com.zeroone.star.orgmanagement.entity.EasyExcelOrgPerson;
import com.zeroone.star.orgmanagement.entity.OrgPerson;
import com.zeroone.star.orgmanagement.mapper.OrgPersonMapper;
import com.zeroone.star.orgmanagement.service.IOrgPersonService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.ArrayList;
import java.util.List;

/**
 * @author: zlw
 * @date: 2024-10-27
 */

public class UserListener extends AnalysisEventListener<EasyExcelOrgPerson> {


    private  IOrgPersonService orgPersonService;

    public UserListener(IOrgPersonService service){
        this.orgPersonService = service;
    }
    private  List<OrgPerson> userList = new ArrayList<>();
    @Override
    public void invoke(EasyExcelOrgPerson easyExcelOrgPerson, AnalysisContext analysisContext) {
        //在这里处理读取到的行数据
        //转换数据格式
        OrgPerson orgPerson = BeanUtil.copyProperties(easyExcelOrgPerson, OrgPerson.class);
        userList.add(orgPerson);
    }

    @Override
    public void doAfterAllAnalysed(AnalysisContext analysisContext) {
        // 所有数据解析完成后可以做一些后续处理
        //调用保存方法
        orgPersonService.saveBatch(userList);
    }
}
