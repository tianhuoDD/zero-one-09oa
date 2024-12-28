package com.zeroone.star.procmanager.mapper;

import com.zeroone.star.project.dto.j4.process.*;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface PpEProcessShowAndModifyMapper {

        @Select("select * from pp_e_begin where xprocess = #{xid1}")
        List<BeginDTO> selectstart(String xid1);
        @Select("select * from pp_e_route where xprocess = #{xid1}")

        List<RouteDTO> selectroute(String xid1);
        @Select("select * from pp_e_manual where xprocess = #{xid1}")

        List<ManualDTO> selectmanual(String xid1);
        @Select("select * from pp_e_parallel where xprocess = #{xid1}")

        List<ParallelDTO> selectparallel(String xid1);
        @Select("select * from pp_e_merge where xprocess = #{xid1}")

        List<MergeDTO> selectmerge(String xid1);
        @Select("select * from pp_e_end where xprocess = #{xid1}")

        List<EndDTO> selectend(String xid1);

        @Select("select * from pp_e_process where xid = #{xid1}")
        PpEProcessDTO selectById(String xid1);

        void update(ModifyProcessDTO ppEProcess);
}
