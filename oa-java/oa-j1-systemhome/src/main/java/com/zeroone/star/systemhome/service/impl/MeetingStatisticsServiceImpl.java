package com.zeroone.star.systemhome.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.zeroone.star.project.vo.j1.system.home.MeetingStatisticsInfoVo;
import com.zeroone.star.systemhome.entity.file.MtBuilding;
import com.zeroone.star.systemhome.entity.file.MtMeeting;
import com.zeroone.star.systemhome.entity.file.MtMeetingAcceptPersonList;
import com.zeroone.star.systemhome.entity.file.MtRoom;
import com.zeroone.star.systemhome.mapper.MtBuildingMapper;
import com.zeroone.star.systemhome.mapper.MtMeetingAcceptPersonListMapper;
import com.zeroone.star.systemhome.mapper.MtMeetingMapper;
import com.zeroone.star.systemhome.mapper.MtRoomMapper;
import com.zeroone.star.systemhome.service.MeetingStatisticsService;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;


@Service
public class MeetingStatisticsServiceImpl implements MeetingStatisticsService {
    @Autowired
    private MtMeetingAcceptPersonListMapper mtMeetingAcceptPersonListMapper;

    @Autowired
    private MtMeetingMapper mtMeetingMapper;

    @Autowired
    private MtRoomMapper mtRoomMapper;

    @Autowired
    private MtBuildingMapper mtBuildingMapper;
    /**
     * 根据用户id，获得会议统计的部分信息，包括会议主题，会议开始时间，会议结束时间，会议室建筑名，会议室名字
     * @param id 用户id
     * @return 会议统计的相关数据，包括会议主题，会议开始时间，会议结束时间，会议室建筑名，会议室名字
     */
    @Override
    public List<MeetingStatisticsInfoVo> getMeetingInfo(String id) {
        ArrayList<MeetingStatisticsInfoVo> resultVoList = new ArrayList<>();

        //1.从 mt_meeting_acceptpersonlist 表中:通过用户id,获得这个用户参加所有的会议
        // 并返回这些会议的id集合

        //查询mt_meeting_acceptpersonlist表中所有MtMeetingAcceptPersonList对象
        // 并放进一个集合中
        List<MtMeetingAcceptPersonList> allMeetingStatistics = mtMeetingAcceptPersonListMapper.selectList(null);
        //用stream流操作这个 集合
        //先筛选出 哪些MeetingStatistics对象的xacceptPersonList中包含 id
        //然后获得这些 MeetingStatistics对象的MeetingXid 的集合
        List<String> meetingXidList = allMeetingStatistics.stream()
                .filter(item -> item.getXacceptPersonList() != null &&
                        containsUserId(item.getXacceptPersonList(), id))
                .map(MtMeetingAcceptPersonList::getMeetingXid)
                .collect(Collectors.toList());



        //2.从mt_meeting表中:通过会议id，获得会议主题，会议开始时间，会议结束时间，会议室编号()
        // 设置查询条件，mt_meeting中哪些MtMeeting对象的id在这个meetingXidList中，并获得一个集合
        LambdaQueryWrapper<MtMeeting> mtmlqw = new LambdaQueryWrapper<>();
        mtmlqw.in(MtMeeting::getXid,meetingXidList);
        List<MtMeeting> meetingList = mtMeetingMapper.selectList(mtmlqw);
        //将得到的集合，遍历，每一个MtMeeting对象的会议主题，会议开始时间，会议结束时间添加到resultVo中
        for (MtMeeting mtMeeting : meetingList) {
            //新建一个MeetingStatisticsInfoVo对象
            MeetingStatisticsInfoVo vo = new MeetingStatisticsInfoVo();
            vo.setMeetingSubject(mtMeeting.getXsubject());
            vo.setMeetingStartTime(mtMeeting.getXstartTime());
            vo.setMeetingCompletedTime(mtMeeting.getXcompletedTime());
            //将对象添加到集合
            resultVoList.add(vo);
        }

        
        //3.从mt_room 表中：通过会议室编号，获得会议室名字，建筑物编号
        //遍历集合mtMeetings，得到会议室编号的集合
        List<String> roomIdList = meetingList.stream()
                .map(MtMeeting::getXroomId)
                .collect(Collectors.toList());
        //查询mt_room表格中，id在会议室编号的集合的行，生成roomList
        LambdaQueryWrapper<MtRoom> mtrlqw = new LambdaQueryWrapper<>();
        mtrlqw.in(MtRoom::getXid,roomIdList);
        List<MtRoom> roomList = mtRoomMapper.selectList(mtrlqw);
        //在roomList，中获得roomName的集合,加入resultVo中
        int indexOfResultVoList=0;
        for (MtRoom room : roomList) {
            resultVoList.get(indexOfResultVoList).setRoomName(room.getXname());
            indexOfResultVoList++;

        }

        //4.从mt_building表中：通过建筑物编号，获得建筑物名字
        //在roomList，中获得xbuilding的集合
        List<String> buildingIdList = roomList.stream()
                .map(MtRoom::getXbuilding)
                .collect(Collectors.toList());
        //查询mt_building表中，id在xbuilding集合中的行，生成集合buildingList
        LambdaQueryWrapper<MtBuilding> mtblqw = new LambdaQueryWrapper<>();
        mtblqw.in(MtBuilding::getXid,buildingIdList);
        List<MtBuilding> buildingList = mtBuildingMapper.selectList(mtblqw);
        //遍历buildingList，得到build的名字，依次加入到vo中
        indexOfResultVoList=0;
        for (MtBuilding building : buildingList) {
            resultVoList.get(indexOfResultVoList).setBuildingName(building.getXname());
            indexOfResultVoList++;
        }


        //返回这个vo
        return resultVoList;
    }

    /**
     * 判断xacceptPersonList这个集合对象中 有没有userId
     * @param xAcceptPersonList xacceptPersonList对象
     * @param userId 需要查找是否包含的userId
     * @return 有或者没有
     */
    public boolean containsUserId(String xAcceptPersonList ,String userId) {
        String[] list = xAcceptPersonList.split(",");
        for(String xAcceptPerson:list){
          if(xAcceptPerson.equals(userId)){
              return true;
          }
        }
        return false;
    }
}
