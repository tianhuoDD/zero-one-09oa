package com.zeroone.star.project.j4.process;

import com.zeroone.star.project.dto.j4.process.ModifyProcessDTO;
import com.zeroone.star.project.dto.j4.process.PpEProcessDetailDto;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

public interface ProcessShowAndModifyApis {
    /**
     * 查看流程详情
     * @param id
     * @return
     */
    JsonVO<List<PpEProcessDetailDto>> ProcessShowDetail(@RequestParam(value = "id") String id);

    /**
     * 修改流程
     */
    JsonVO<String> modifyProcess(ModifyProcessDTO ppEProcessDTO);
}
