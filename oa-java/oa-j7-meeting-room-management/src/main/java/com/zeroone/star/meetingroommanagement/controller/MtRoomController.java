package com.zeroone.star.meetingroommanagement.controller;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.meetingroommanagement.MeetingRoomLocationDto;
import com.zeroone.star.project.dto.j7.meetingroommangement.MtRoomDTO;
import com.zeroone.star.project.j7.meetingroommanagement.MeetingRoomManagementApis;
import com.zeroone.star.project.dto.j7.mtroom.MtBuildingDto;
import com.zeroone.star.project.query.j7.meetingroommanagement.MtRoomQuery;
import com.zeroone.star.meetingroommanagement.service.IMtRoomService;
import com.zeroone.star.project.query.meetingroom.MeetingRoomQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author zlw
 * @since 2024-10-18
 */
@RestController
@RequestMapping("/mt-room")
@Api(tags = "会议室管理控制器")
public class MtRoomController implements MeetingRoomManagementApis {

    @Autowired
    private IMtRoomService mtRoomService;

    @GetMapping("/deleteMtRoomLocation")
    @ApiOperation("删除会议室位置")
    public JsonVO deleteMtRoomLocation(@RequestParam String xId){

        return mtRoomService.deleteMtRoomLocation(xId);
    }

    @PutMapping("/updateMtRoomLocation")
    @ApiOperation("修改会议室位置")
    public JsonVO updateMtRoomLocation(@RequestBody MeetingRoomLocationDto dto){

        return mtRoomService.updateMtRoomLocation(dto);
    }


    @Override
    @PostMapping("/add-meetingRoom")
    @ApiOperation("新建会议室")
    public JsonVO addMeetingRoom(@RequestBody MtRoomDTO mtRoomDTO) {

        mtRoomService.saveRoom(mtRoomDTO);
        return JsonVO.success("新建会议室成功");
    }

    @Override
    @GetMapping("/query-meetingRoom-page-by-conditions/{xid}")
    @ApiOperation("获取会议室列表(条件 + 分页)")
    public JsonVO queryMeetingRoomPageByConditions(@RequestBody MtRoomQuery query) {
        PageVO mtRoomPage = mtRoomService.listRoom(query);
        return JsonVO.success(mtRoomPage);
    }

    @Override
    @ApiOperation("修改会议室")
    @PutMapping("/update-meetingRoom")
    public JsonVO updateMeetingRoom(com.zeroone.star.project.dto.j7.meetingroommangement.MtRoomDTO mtRoomDTO) {

        return mtRoomService.updateRoom(mtRoomDTO);
    }

    @GetMapping("query-all")
    @ApiOperation(value = "分页查询")
    @Override
    public JsonVO QueryListMeetingRoom(MeetingRoomQuery condition) {
        return JsonVO.success(mtRoomService.listAllMtRoom(condition));
    }

    @GetMapping("/queryMeetingRoomLocation")
    @ApiOperation("获取会议室位置列表（分页）")
    public JsonVO<PageDTO<MtBuildingDto>> getMeetingRoomLocation(String xbuilding,
                                                                 PageDTO pageDTO) {

        return mtRoomService.getMeetingRoomLocation(xbuilding, pageDTO);
    }

    @DeleteMapping("/delete-meetingRoom/{xid}")
    @ApiOperation("删除会议室")
    public JsonVO deleteMeetingRoom(@PathVariable String xid) {

        return mtRoomService.deleteRoom(xid);
    }

    @PostMapping("/add-meetingRoomLocation")
    @ApiOperation("新增会议室位置")
    public JsonVO saveMeetingRoomLocation(@RequestBody MtBuildingDto mtBuildingDto) {
        return mtRoomService.saveMeetingRoomLocation(mtBuildingDto);

    }

}

