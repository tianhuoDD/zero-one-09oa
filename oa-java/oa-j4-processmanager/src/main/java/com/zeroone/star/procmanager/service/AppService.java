package com.zeroone.star.procmanager.service;

import com.zeroone.star.procmanager.entity.PpEApplication;
import com.zeroone.star.project.dto.j4.procmanager.application.manage.ApplicationPropertiesDto;
import com.zeroone.star.project.vo.j4.procmanager.QueryOrgMemberVO.QueryOrgMemberVO;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.ApplicationPropertiesVo;

import javax.swing.tree.TreeNode;
import java.util.List;

public interface AppService {

    boolean addApplication(ApplicationPropertiesDto applicationPropertiesDto) throws Exception;

    boolean updateApplication(ApplicationPropertiesDto applicationPropertiesDTO);

//    ApplicationPropertiesVo queryApplication(String xid);

    boolean deleteApplication(String id);

    List<QueryOrgMemberVO> queryOrganizationMemberTree();


    List<QueryOrgMemberVO> queryOrganizationTree(String keywords);

}
