package com.zeroone.star.procmanager.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.procmanager.entity.PpEForm;
import com.zeroone.star.procmanager.mapper.FormManageMapper;
import com.zeroone.star.procmanager.service.IFormManageService;
import com.zeroone.star.project.dto.j4.form.manage.UpdateFormDTO;
import org.mapstruct.Mapper;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.UUID;

@Mapper(componentModel = "spring")
interface MsPpEFormMapper {
    /**
     * 将 PpEForm do 转换为 dto
     *
     * @param ppEForm do 对象
     * @return 转换结果
     */
    UpdateFormDTO PpEFormToUpdateFormDTO(PpEForm ppEForm);

    PpEForm UpdateFormDTOToPpEForm(UpdateFormDTO updateFormDTO);
}

@Service
public class FormManageServiceImpl extends ServiceImpl<FormManageMapper, PpEForm> implements IFormManageService {

    private static final Logger logger = LoggerFactory.getLogger(FormManageServiceImpl.class);

    @Resource
    MsPpEFormMapper ppEFormMapper;

    @Override
    public UpdateFormDTO getForm(String xid) {
        PpEForm form = baseMapper.selectById(xid);
        if (form!= null) {
            return ppEFormMapper.PpEFormToUpdateFormDTO(form);
        }
        return null;
    }

    @Override
    public Boolean addForm(UpdateFormDTO updateFormDTO) {
        //获取转化对象
        PpEForm form = ppEFormMapper.UpdateFormDTOToPpEForm(updateFormDTO);
        //设置默认参数
        form.setXid(UUID.randomUUID().toString());
        form.setXcreateTime(LocalDateTime.now());
        form.setXupdateTime(LocalDateTime.now());
        form.setXlastUpdateTime(LocalDateTime.now());
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyyMMddHHmmss");
        String formattedDateTime = form.getXcreateTime().format(formatter);
        form.setXsequence(formattedDateTime + form.getXid());
        form.setXapplication("获取应用信息");
        form.setXlastUpdatePerson("获取用户信息");

        //插入操作
        int result = baseMapper.insert(form);
        if (result > 0) {
            return true;
        } else {
            return false;
        }
    }

    @Override
    public Boolean updateForm(UpdateFormDTO updateFormDTO) {
        //updateFormDTO为通过点击查询获取的对象
        if (updateFormDTO == null) {
            //如果对象为空抛出一个异常
            throw new IllegalArgumentException("UpdateFormDTO cannot be null");
        }
        try {
            PpEForm form = ppEFormMapper.UpdateFormDTOToPpEForm(updateFormDTO);
            int result = baseMapper.updateById(form);
            form.setXupdateTime(LocalDateTime.now());
            form.setXlastUpdateTime(LocalDateTime.now());
            // 获取实际的用户信息
            form.setXlastUpdatePerson("getCurrentUserInformation()");
            return result > 0;
        } catch (Exception e) {
            // 记录日志
            logger.error("Error updating form", e);
            return false;
        }
    }

    @Override
    public Boolean deleteForm(String[] xids) {
        try {
            for (String xid : xids) {
                int deleteResult = baseMapper.deleteById(xid);
                if (deleteResult <= 0) {
                    logger.warn("Failed to delete form with id: {}", xid);
                }
            }
            return true;
        } catch (Exception e) {
            logger.error("Error occurred while deleting forms", e);
            return false;
        }
    }
}