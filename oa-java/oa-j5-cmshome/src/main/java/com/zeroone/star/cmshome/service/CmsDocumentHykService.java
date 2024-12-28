package com.zeroone.star.cmshome.service;

import com.zeroone.star.cmshome.entity.CmsDocumentHyk;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.GetColumnMessagesVO;


import java.util.List;

/**
 * <p>
 * 服务类
 * </p>
 *
 * @author hyk
 * @since 2024-10-30
 */
public interface CmsDocumentHykService extends IService<CmsDocumentHyk> {
    // 获取栏目信息
    JsonVO<List<GetColumnMessagesVO>> getColumnMessages(String xid);
}
