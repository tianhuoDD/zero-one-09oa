package com.zeroone.star.project.j3.columnbasicinformation;

import com.zeroone.star.project.j3.columnbasicinformation.dto.BasicinformationDTO;
import com.zeroone.star.project.j3.columnbasicinformation.query.BasicinformationQuery;
import com.zeroone.star.project.j3.columnbasicinformation.dto.AppinfoDTO;
import com.zeroone.star.project.j3.columnbasicinformation.vo.BasicinformationVo;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.multipart.MultipartFile;

/**
 * <p>
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @version 1.0.0
 */
public interface ColumnBasicinformationApis {

    /**
     * 通过编号查询返回结果
     *
     * @param basicinformationQuery
     * @return
     */
    public JsonVO<BasicinformationVo> queryBasicinformation(BasicinformationQuery basicinformationQuery);

    /**
     * 修改栏目基础信息
     * @param basicinformationDTO 栏目基础信息
     * @return 栏目基础信息
     */
    public JsonVO<BasicinformationVo> modifyBasicinformation(BasicinformationDTO basicinformationDTO, MultipartFile file);

    /**
     * 新建栏目
     * @param appinfoDTO 数据对象
     * @return 新增栏目id
     */
    public JsonVO<String> addAppinfo(AppinfoDTO appinfoDTO, MultipartFile file) throws Exception;

    /**
     * 根据栏目id标识删除栏目
     * @param xid 栏目标识
     * @return 删除栏目结果
     */
    public JsonVO<String> removeAppinfoByXid(String xid);


}
