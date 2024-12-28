package com.zeroone.star.procmanager.mapper;
import java.util.List;

import com.zeroone.star.project.vo.j4.form.data.FormInfoVO;
import org.apache.ibatis.annotations.Param;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.procmanager.entity.PpEForm;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface FormMapper extends BaseMapper<PpEForm> {
    /**
     * ��ѯӦ�õı�
     * @param id
     * @return
     */
    List<String> selectNameById(@Param("xid") String id);

    FormInfoVO queryFormInfo(String xid);
}
