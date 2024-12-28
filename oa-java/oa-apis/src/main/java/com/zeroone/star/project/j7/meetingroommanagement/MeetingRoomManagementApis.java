package com.zeroone.star.project.j7.meetingroommanagement;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.meetingroommanagement.MeetingRoomLocationDto;;
import com.zeroone.star.project.dto.j7.meetingroommangement.MtRoomDTO;
import com.zeroone.star.project.dto.j7.mtroom.MtBuildingDto;
import com.zeroone.star.project.query.j7.meetingroommanagement.MtRoomQuery;
import com.zeroone.star.project.query.meetingroom.MeetingRoomQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;

public interface MeetingRoomManagementApis {

    /**
     * 修改会议室位置
     * @param dto
     * @return
     */
    public JsonVO updateMtRoomLocation(@RequestBody MeetingRoomLocationDto dto);

    /**
     * 删除会议室位置
     * @param xId
     * @return
     */
    public JsonVO deleteMtRoomLocation(@RequestParam String xId);

    /**
     * 修改会议室
     * @return 封装对象
     */
    public JsonVO updateMeetingRoom(MtRoomDTO mtRoomDTO);


    /**
     * 删除会议室
     * @param xid 唯一id
     * @return 响应封装对象
     */
    public JsonVO deleteMeetingRoom(String xid);


    /**
     * 分页查询
     * @param condition
     * @return
     */
    public JsonVO QueryListMeetingRoom(MeetingRoomQuery condition);

    /**
     * 新建会议室
     * @param mtRoomDTO
     * @return
     */
    public JsonVO addMeetingRoom(MtRoomDTO mtRoomDTO);

    /**
     * 获取会议室列表(条件 + 分页)
     * @param query
     * @return
     */
    public JsonVO queryMeetingRoomPageByConditions(MtRoomQuery query);


    /**
     * 获取会议室位置列表（分页）
     * @param xbuilding
     */
    JsonVO<PageDTO<MtBuildingDto>> getMeetingRoomLocation(String xbuilding, PageDTO pageDTO);

    /**
     * 新增会议室位置
     * @param mtBuildingDto
     */
    JsonVO saveMeetingRoomLocation(MtBuildingDto mtBuildingDto);
}
