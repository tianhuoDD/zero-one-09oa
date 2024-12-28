package com.zeroone.star.meetingroommanagement.service;

import com.zeroone.star.meetingroommanagement.entity.MtRoom;
import com.baomidou.mybatisplus.extension.service.IService;;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.meetingroommanagement.MeetingRoomLocationDto;
import com.zeroone.star.project.dto.j7.meetingroommangement.MtRoomDTO;
import com.zeroone.star.project.dto.j7.mtroom.MtBuildingDto;
import com.zeroone.star.project.query.meetingroom.MeetingRoomQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.query.j7.meetingroommanagement.MtRoomQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author zlw
 * @since 2024-10-18
 */
public interface IMtRoomService extends IService<MtRoom> {

    /**
     * 修改会议室
     *
     * @param mtRoomDTO
     * @return
     */
    JsonVO updateRoom(MtRoomDTO mtRoomDTO);

    /**
     * 删除会议室
     *
     * @param xid
     * @return
     */
    JsonVO deleteRoom(String xid);

    // /**
    //  * 新增会议室
    //  * @param mtRoomDTO
    //  */
    // void saveRoom(MtRoomDTO mtRoomDTO);
    /**
     * 新增会议室
     * @param mtRoomDTO
     */
    void saveRoom(MtRoomDTO mtRoomDTO);

    /**
     * 获取会议室列表(条件 + 分页)
     * @param query
     * @return
     */
    PageVO listRoom(MtRoomQuery query);

    /**
     * 分页查询数据
     * @param query 查询条件
     * @return 查询结果
     */
    PageDTO<MtRoomDTO> listAllMtRoom(MeetingRoomQuery query);


    /**
     * 获取会议室位置
     * @param xbuilding
     * @param pageDTO
     * @return
     */
    JsonVO<PageDTO<MtBuildingDto>> getMeetingRoomLocation(String xbuilding, PageDTO pageDTO);

    /**
     * 新增会议室位置
     * @param mtBuildingDto
     * @return
     */
    JsonVO saveMeetingRoomLocation(MtBuildingDto mtBuildingDto);
    /**
     * 根据Id删除会议室位置
     * @param xId
     * @return
     */
    JsonVO deleteMtRoomLocation(String xId);

    /**
     * 修改会议室位置
     * @param dto
     * @return
     */
    JsonVO updateMtRoomLocation(MeetingRoomLocationDto dto);
}
