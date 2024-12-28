package com.zeroone.star.login.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.login.entity.OrgAuthcode;
import com.zeroone.star.project.vo.JsonVO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface OrgAuthcodeMapper extends BaseMapper<OrgAuthcode> {
    JsonVO<Boolean> saveVoucherInfo(OrgAuthcode orgAuthcode);
}
