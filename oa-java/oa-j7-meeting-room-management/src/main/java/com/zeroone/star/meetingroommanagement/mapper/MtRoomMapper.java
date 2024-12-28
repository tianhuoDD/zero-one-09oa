package com.zeroone.star.meetingroommanagement.mapper;

import com.zeroone.star.meetingroommanagement.entity.MtRoom;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j7.meetingroommangement.MtRoomDTO;
import com.zeroone.star.project.query.j7.meetingroommanagement.MtRoomQuery;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author zlw
 * @since 2024-10-18
 */
@Mapper
public interface MtRoomMapper extends BaseMapper<MtRoom> {


    int updateRoom(MtRoomDTO mtRoomDTO);


    int deleteRoom(String xid);

    // /**
    //  * 新增会议室
    //  * @param mtRoom
    //  */
    // @Insert("insert into mt_room (xcreateTime, xsequence, xupdateTime, xdistributeFactor, xauditor, xavailable, xbuilding, xcapacity, xdevice, xfloor, xname, xphoneNumber, xphoto, xpinyin, xpinyinInitial, xroomNumber) " +
    //         "values (#{xcreateTime}, #{xsequence}, #{xupdateTime}, #{xdistributeFactor}, #{xauditor}, #{xavailable}, #{xbuilding}, #{xcapacity}, #{xdevice}, #{xfloor}, #{xname}, #{xphoneNumber}, #{xphoto}, #{xpinyin}, #{xpinyinInitial}, #{xroomNumber}) ")
    // void insertRoom(MtRoom mtRoom);


    /**
     * 获取会议室列表(条件 + 分页)
     * @param start 起始
     * @param pageSize 每页数量
     * @return List
     */
    List<MtRoom> selectRoomPage(long start, long pageSize, String xbuilding);

    /**
     * 查询总数量
     * @return
     */
    @Select("select count(*) from mt_room")
    Long count();
}
