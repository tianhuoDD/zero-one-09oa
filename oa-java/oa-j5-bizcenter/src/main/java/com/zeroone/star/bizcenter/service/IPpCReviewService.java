package com.zeroone.star.bizcenter.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.bizcenter.entity.PpCReview;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.bizcenter.PpCReviewDTO;
import com.zeroone.star.project.query.j5.bizcenter.PpCReviewQuery;

/**
 * <p>
 *  服务类,参阅查询接口
 *  条件加分页查询
 * </p>
 *
 * @author hamhuo
 * @since 2024-10-27
 */
public interface IPpCReviewService extends IService<PpCReview> {
    public PageDTO<PpCReviewDTO> selectReviewByPerson(PpCReviewQuery ppCReviewQuery);

}
