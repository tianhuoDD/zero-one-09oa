package com.zeroone.star.meetingroommanagement.service.impl;


import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.meetingroommanagement.entity.MtBuilding;
import com.zeroone.star.meetingroommanagement.entity.MtRoom;
import com.zeroone.star.meetingroommanagement.converter.MsMtRoomMapper;
import com.zeroone.star.meetingroommanagement.mapper.MtBuildingMapper;
import com.zeroone.star.project.dto.j7.meetingroommangement.MtRoomDTO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.meetingroommanagement.mapper.MtRoomMapper;
import com.zeroone.star.meetingroommanagement.service.IMtRoomService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.meetingroommanagement.MeetingRoomLocationDto;
import com.zeroone.star.project.dto.j7.mtroom.MtBuildingDto;
import com.zeroone.star.project.query.meetingroom.MeetingRoomQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.query.j7.meetingroommanagement.MtRoomQuery;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

import java.time.LocalDateTime;
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
public class MtRoomServiceImpl extends ServiceImpl<MtRoomMapper, MtRoom> implements IMtRoomService {

    @Resource
    private MtRoomMapper mtRoomMapper;
    @Resource
    private MsMtRoomMapper msMtRoomMapper;

    @Autowired
    private MtBuildingMapper mtBuildingMapper;

    /**
     * 修改会议室
     *
     * @param mtRoomDTO 修改数据
     * @return 返回
     */
    @Override
    public JsonVO updateRoom(MtRoomDTO mtRoomDTO) {
        if(StrUtil.isBlank(mtRoomDTO.getXid())){
            return JsonVO.fail("参数错误");
        }
        int i = mtRoomMapper.updateRoom(mtRoomDTO);
        if (i != 1){
            return JsonVO.fail("修改失败");
        }
        return JsonVO.success("修改成功");
    }

    /**
     * 删除会议室
     *
     * @param xid 根据id删除对象
     * @return 返回
     */
    @Override
    public JsonVO deleteRoom(String xid) {
        if (StrUtil.isBlank(xid)){
            return JsonVO.fail("参数错误");
        }
        int i = mtRoomMapper.deleteRoom(xid);
        if (i != 1){
            return JsonVO.fail("删除失败");
        }
        return JsonVO.success("删除成功");
    }

    /**
     * 新增会议室
     * @param mtRoomDTO
     */
    @Override
    public void saveRoom(MtRoomDTO mtRoomDTO) {
        MtRoom mtRoom = new MtRoom();
        BeanUtils.copyProperties(mtRoomDTO, mtRoom);
        mtRoom.setXcreateTime(LocalDateTime.now());
        mtRoom.setXupdateTime(LocalDateTime.now());
        mtRoomMapper.insert(mtRoom);
    }


    /**
     * 获取会议室列表(条件 + 分页)
     *
     * @param query
     * @return
     */
    @Override
    public PageVO listRoom(MtRoomQuery query) {
        long page = query.getPageIndex();
        long pageSize = query.getPageSize();

        String xbuilding = null;
        if(query.getXBuilding() != null) {
            xbuilding = query.getXBuilding();
        }


        // 1. 获取总记录数
        Long count = mtRoomMapper.count();

        // 2. 获取分页查询结果列表
        long start = (page - 1) * pageSize;
        List<MtRoom> mtRoomList = mtRoomMapper.selectRoomPage(start, pageSize, xbuilding);

        // 3. 把结果封装进PageBean对象，并返回
        return new PageVO(count, mtRoomList);
    }
    @Override
    public PageDTO<MtRoomDTO> listAllMtRoom(MeetingRoomQuery query) {
        // 构建分页对象
        Page<MtRoom> page = new Page<>(query.getPageIndex(),query.getPageSize());
        // 构建查询条件
        QueryWrapper<MtRoom> queryWrapper = new QueryWrapper<>();
        queryWrapper.like("xauditor",query.getXauditor());
        // 执行查询
        Page<MtRoom> result = baseMapper.selectPage(page,queryWrapper);
        // 转换结果
        return PageDTO.create(result,msMtRoomMapper::MtRoom2MtRoomDTO);
    }

    @Override
    public JsonVO<PageDTO<MtBuildingDto>> getMeetingRoomLocation(String xbuilding, PageDTO pageDTO) {
        return null;
    }

    @Override
    public JsonVO saveMeetingRoomLocation(MtBuildingDto mtBuildingDto) {
        return null;
    }


    @Override
    public JsonVO deleteMtRoomLocation(String xId) {
        if(StrUtil.isBlank(xId)){
            return JsonVO.fail("参数不能为空");
        }
        int delete = mtBuildingMapper.deleteById(xId);
        if(delete != 1){
            return JsonVO.fail("数据删除失败");
        }
        return JsonVO.success("删除成功");
    }

    @Override
    public JsonVO updateMtRoomLocation(MeetingRoomLocationDto dto) {
        //转换成实体
        MtBuilding mtBuilding = BeanUtil.copyProperties(dto, MtBuilding.class);
        if(mtBuilding != null){
            //修改数据
            int update = mtBuildingMapper.updateById(mtBuilding);
            if(update != 1){
                return JsonVO.fail("数据修改失败");
            }
        }
        return JsonVO.success("数据修改成功");
    }
}
