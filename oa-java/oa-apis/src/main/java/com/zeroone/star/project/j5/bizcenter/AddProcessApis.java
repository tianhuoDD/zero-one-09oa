package com.zeroone.star.project.j5.bizcenter;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.bizcenter.ApplicationListVO;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessFromVO;
import com.zeroone.star.project.vo.j5.bizcenter.publishProcessVO;
import org.springframework.validation.annotation.Validated;

import javax.validation.constraints.NotNull;
import javax.validation.constraints.Size;
import java.util.List;


/**
 * <p>
 * 描述：办公中心-添加流程接口
 * </p>
 * @author
 * @version 1.0.0
 */
public interface AddProcessApis {


    /**
     * 获取全部应用列表接口
     * @return
     */
    JsonVO<List<ApplicationListVO>> queryApplicationList();

    /**
     * 获取公共流程列表接口 -【通知公告】
     * @return
     */
    JsonVO<List<publishProcessVO>> queryPublishWithProcess();

    /**
     *  获取流程表单接口
     * @param id 表单id
     * @return
     */
    JsonVO<ProcessFromVO> queryProcessFrom(@Validated
                                           @NotNull(message = "ID不能为空")
                                           @Size(min = 1, max = 50, message = "ID长度必须在1到50之间")
                                           String id);


}
