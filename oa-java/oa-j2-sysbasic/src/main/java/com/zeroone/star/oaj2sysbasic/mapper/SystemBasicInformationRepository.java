package com.zeroone.star.oaj2sysbasic.mapper;

import com.zeroone.star.oaj2sysbasic.entity.SystemBasicInformation;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.data.mongodb.repository.MongoRepository;

/**
 * @ClassName: SystemBasicInformationRepository
 * @Package: com.zeroone.star.oaj2sysbasic.mapper
 * @Description:  系统基本信息mapper接口层
 * @Author: zk
 * @Create: 2024/10/24 - 下午12:39
 */

public interface SystemBasicInformationRepository extends MongoRepository<SystemBasicInformation, String> {
}
