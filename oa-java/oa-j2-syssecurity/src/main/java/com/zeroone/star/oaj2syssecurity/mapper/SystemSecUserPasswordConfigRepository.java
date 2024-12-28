package com.zeroone.star.oaj2syssecurity.mapper;

import com.zeroone.star.oaj2syssecurity.entity.UserPasswordConfig;
import org.springframework.data.mongodb.repository.MongoRepository;

/**
 * 用户密码配置持久层
 * @author JIAN
 */
public interface SystemSecUserPasswordConfigRepository extends MongoRepository<UserPasswordConfig, Integer> {
}