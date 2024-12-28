package com.zeroone.star.bizcenter.mapper;

import com.zeroone.star.project.dto.j5.bizcenter.ProcessFormItemDTO;
import org.apache.ibatis.annotations.Select;

import javax.annotation.Resource;
import java.util.List;

@Resource
public interface ProcessTableDataMapper {

    /**
     * 通过xbundle 查询流程表格数据
     * @param xbundle
     * @return
     */
    @Select("select xid, xcreateTime, xupdateTime,  xbundle, xdateTimeValue, xdateValue, xitemCategory, xitemPrimitiveType, xitemStringValueType, xitemType, xnumberValue, xpath0, xpath0Location, xpath1, xpath1Location, xpath2, xpath2Location, xpath3, xpath3Location, xpath4, xpath4Location, xpath5, xpath5Location, xpath6, xpath6Location, xpath7, xpath7Location, xstringLongValue, xstringShortValue, xtimeValue\n" +
            "from qry_item\n" +
            "where xbundle = #{xbundle}")
    List<ProcessFormItemDTO> selectTableDataByXbundle(String xbundle);

}
