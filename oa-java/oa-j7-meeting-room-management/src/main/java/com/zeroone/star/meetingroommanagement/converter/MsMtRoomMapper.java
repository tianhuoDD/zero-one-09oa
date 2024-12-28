package com.zeroone.star.meetingroommanagement.converter;

import com.zeroone.star.meetingroommanagement.entity.MtRoom;
import com.zeroone.star.project.dto.j7.meetingroommangement.MtRoomDTO;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsMtRoomMapper {


        /**
         * 将MtRoomDO转换为MtRoomDTO
         *
         * @param mtRoom do对象
         * @return 转换结果
         */
        MtRoomDTO MtRoom2MtRoomDTO(MtRoom mtRoom);

}
