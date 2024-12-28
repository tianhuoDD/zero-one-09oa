package com.zeroone.star.oaj2syssecurity.mapper;


import com.zeroone.star.oaj2syssecurity.entity.LoginConfig;
import org.springframework.data.mongodb.repository.MongoRepository;

/**
 * className: SystemSecLoginConfigMapper
 * author: maomaomao
 * date: 2024/10/28 18:46
 * Version: 1.0
 * description:
 */
public interface SystemSecLoginConfigMapper extends MongoRepository<LoginConfig, Integer> {
}
