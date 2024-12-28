package com.zeroone.star.bizcenter.service.impl;


import com.zeroone.star.bizcenter.mapper.ProcessTableMapper;
import com.zeroone.star.bizcenter.service.ProcessTableService;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessFormVO;
import com.zeroone.star.project.vo.j5.bizcenter.formData.Form;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Service
public class ProcessTableServiceImpl implements ProcessTableService {

    @Resource
    private ProcessTableMapper processTableMapper;

    @Override
    public ProcessFormVO getProcessTableByXid(String xid) {
        Form form = processTableMapper.selectTableByXid(xid);
        form.setXid(xid);
        return ProcessFormVO.builder()
                .form(form)
                .maxAge(86400)
                .build();
    }


}
