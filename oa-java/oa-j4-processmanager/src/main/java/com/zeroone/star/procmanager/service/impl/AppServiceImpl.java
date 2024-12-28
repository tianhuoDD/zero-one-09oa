package com.zeroone.star.procmanager.service.impl;

import com.zeroone.star.procmanager.entity.*;
import com.zeroone.star.procmanager.mapper.ApplicationMapper;
import com.zeroone.star.procmanager.service.AppService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j4.procmanager.application.manage.ApplicationPropertiesDto;
import com.zeroone.star.project.utils.tree.TreeNode;
import com.zeroone.star.project.utils.tree.TreeNodeMapper;
import com.zeroone.star.project.utils.tree.TreeUtils;
import com.zeroone.star.project.vo.j4.procmanager.QueryOrgMemberVO.QueryOrgMemberVO;
import com.zeroone.star.project.vo.j4.procmanager.application.manage.ApplicationPropertiesVo;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

@Service
public class AppServiceImpl implements AppService {

    @Autowired
    ApplicationMapper applicationMapper;
    @Autowired
    UserHolder userHolder;


    /**
     * 添加应用
     * @param applicationPropertiesDto
     * @return
     * @throws Exception
     */
    @Override
    public boolean addApplication(ApplicationPropertiesDto applicationPropertiesDto) throws Exception  {
            boolean flag = false;
            //uuid作为唯一标识
            String uniqueId = UUID.randomUUID().toString();
            //设置创建时间、更新时间、序列号
            PpEApplication application = PpEApplication.builder()
                    .xcreateTime(LocalDateTime.now())
                    .xupdateTime(LocalDateTime.now())
                    .xsequence(LocalDateTime.now() + uniqueId)
                    .xlastUpdateTime(LocalDateTime.now())
                    .build();
            //将applicationPropertiesDto中的属性值复制到application中
            BeanUtils.copyProperties(applicationPropertiesDto,application);
            //防止被applicationPropertiesDto中xid的空值覆盖，拷贝后在设置uuid为唯一标识
            application.setXid(uniqueId);
            //设置创建者
            UserDTO user = userHolder.getCurrentUser();
            if (user == null){
                application.setXcreatorPerson(null);
                throw new Exception("未接收到有效的JWT令牌，请先登录");
            }
            else application.setXcreatorPerson(user.getUsername());

            //判断是否成功插入到数据库中
            flag  = applicationMapper.insertApplication(application);
            return flag;
    }

    /**
     * 更新应用属性
     * @param applicationPropertiesDTO
     * @return
     */
    @Override
    public boolean updateApplication(ApplicationPropertiesDto applicationPropertiesDTO) {
        //查询数据库中数据并保存到eApplication
        PpEApplication eApplication = applicationMapper.selectById(applicationPropertiesDTO.getXid());

        //如果eApplication不为空
        if (eApplication != null) {

            //将applicationPropertiesDTO中的属性值复制到application中
            PpEApplication application = new PpEApplication();
            BeanUtils.copyProperties(applicationPropertiesDTO,application);

            //设置上次更新的时间和这次更新的事件
            eApplication.setXlastUpdateTime(LocalDateTime.now());
            eApplication.setXupdateTime(LocalDateTime.now());

            //将查询到的数据和前端传过来要修改的数据进行替换
            //修改名称
            eApplication.setXname(applicationPropertiesDTO.getXname());
            //修改别名
            eApplication.setXalias(applicationPropertiesDTO.getXalias());
            //修改分类
            eApplication.setXapplicationCategory(applicationPropertiesDTO.getXapplicationCategory());
            //修改描述
            eApplication.setXdescription(applicationPropertiesDTO.getXdescription());
            //修改图标
            eApplication.setXicon(applicationPropertiesDTO.getXicon());
            //修改流程维护人和默认表单
            eApplication.setXproperties(application.getXproperties());
            //修改上次更新用户
            try {
                UserDTO user = userHolder.getCurrentUser();
                String username = user.getUsername();
                eApplication.setXlastUpdatePerson(username);
            } catch (Exception e) {
                throw new RuntimeException(e);
            }


            //修改可用组织
            String id = applicationPropertiesDTO.getXid();
            List<String> units = applicationMapper.selectAvailableUnitsById(id);
            Integer maxUtilOrder = applicationMapper.getMaxUtilOrderColumn(id);
            if (units.size() != 0){
                applicationMapper.deleteAvailableIdentityUnitById(id);
                applicationMapper.insertAvailableIdentityUnit(applicationPropertiesDTO.getAvailableUnit(),applicationPropertiesDTO.getXid(),maxUtilOrder);
            } else applicationMapper.insertAvailableIdentityUnit(applicationPropertiesDTO.getAvailableUnit(),applicationPropertiesDTO.getXid(),maxUtilOrder);


            //修改管理者
            List<String> controllers = applicationMapper.selectControllersById(id);
            Integer maxControllerOrder = applicationMapper.getMaxControllerOrderColumn(id);
            if (controllers.size() != 0){
                applicationMapper.deleteControllerById(id);
                applicationMapper.insertController(applicationPropertiesDTO.getController(),applicationPropertiesDTO.getXid(),maxControllerOrder);
            } else applicationMapper.insertController(applicationPropertiesDTO.getController(),applicationPropertiesDTO.getXid(),maxControllerOrder);

            //修改可用身份
            List<String> identiteis = applicationMapper.selectIdentitiesById(id);
            Integer maxIdentityOrder = applicationMapper.getMaxIdentityOrderColumn(id);
            if (identiteis.size() != 0){
                applicationMapper.deleteIdentityById(id);
                applicationMapper.insertIdentities(applicationPropertiesDTO.getAvailableIdentity(),applicationPropertiesDTO.getXid(),maxIdentityOrder);
            } else applicationMapper.insertIdentities(applicationPropertiesDTO.getAvailableIdentity(),applicationPropertiesDTO.getXid(),maxIdentityOrder);


            //更新数据库的数据
            return applicationMapper.updateApplication(eApplication);
        }
        return false;
    }

    /**
     * 根据xid查询应用信息
     * @param xid
     * @return
     */
//    public ApplicationPropertiesVo queryApplication(String xid) {
//        PpEApplication eApplication = applicationMapper.selectById(xid);
//        ApplicationPropertiesVo propertiesVo = new ApplicationPropertiesVo();
//        BeanUtils.copyProperties(eApplication,propertiesVo);
//        propertiesVo.setAvailableUnit(applicationMapper.selectAvailableUnitsById(xid));
//        propertiesVo.setController(applicationMapper.selectControllersById(xid).toString());
//        propertiesVo.setAvailableIdentity(applicationMapper.selectIdentitiesById(xid));
//        return propertiesVo;
//    }

    /**
     * 删除应用
     * @param id
     * @return
     */
    @Override
    public boolean deleteApplication(String id) {
        //根据id删除数据
       boolean flag = applicationMapper.deleteById(id);

        return flag;
    }

    /**
     * 获取组织成员名称树
     * @return
     */
    @Override
    public List<QueryOrgMemberVO> queryOrganizationMemberTree() {
        //新建一个列表存储数据
        List<QueryOrgMemberVO> list = new ArrayList<>();
        //查询所有的组织
        List<OrgUnit> units = applicationMapper.selectAllUnit();
        //将组织添加到列表中
        for (OrgUnit unit : units) {
            if(unit.getXid() != null){
                QueryOrgMemberVO queryOrgMemberVO = new QueryOrgMemberVO();
                queryOrgMemberVO.setXid(unit.getXid());
                queryOrgMemberVO.setXicon(unit.getXid());
                queryOrgMemberVO.setXname(unit.getXname());
                list.add(queryOrgMemberVO);
            }
        }
        //转换成树形结构
        List<QueryOrgMemberVO> tree = TreeUtils.listToTree(list, new TreeNodeMapper<QueryOrgMemberVO>() {
            @Override
            public TreeNode objectMapper(QueryOrgMemberVO object) {
                //将查询到的组织数据转换为树形结构
                QueryOrgMemberVO treeNode = new QueryOrgMemberVO();
                // 首先设置TreeNode计算层数使用属性
                if (treeNode.getXpid() == null){
                    treeNode.setXpid(null);
                }
                else {
                    treeNode.setXpid(object.getXpid());
                }
                // 设置组织扩展属性
                treeNode.setTnId(object.getXid());
                treeNode.setXid(object.getXid());
                treeNode.setXname(object.getXname());
                treeNode.setXicon(object.getXicon());

                //设置成员属性
                String xid = object.getXid();
                String id = applicationMapper.selectPersonIdByUnitId(xid);
                OrgPerson  person = applicationMapper.selectPersonById(id);
                QueryOrgMemberVO memberVO = new QueryOrgMemberVO();
                memberVO.setXpid(xid);
                memberVO.setTnId(person.getXid());
                memberVO.setXid(person.getXid());
                memberVO.setXicon(person.getXicon());
                memberVO.setXname(person.getXname());
                treeNode.setChildren(memberVO);

                return treeNode;
            }
        });

        return tree;
    }

    @Override
    public List<QueryOrgMemberVO> queryOrganizationTree(String keywords) {
        //新建一个列表存储数据
        List<QueryOrgMemberVO> list = new ArrayList<>();
        List<OrgUnit> units;
        //根据关键词查询组织
        units = applicationMapper.selectAllUnitByKeywords(keywords);

        //将组织添加到列表中
        for (OrgUnit unit : units) {
            if(unit.getXid() != null){
                QueryOrgMemberVO queryOrgMemberVO = new QueryOrgMemberVO();
                queryOrgMemberVO.setXid(unit.getXid());
                queryOrgMemberVO.setXicon(unit.getXid());
                queryOrgMemberVO.setXname(unit.getXname());
                list.add(queryOrgMemberVO);
            }
        }
        List<QueryOrgMemberVO> tree = TreeUtils.listToTree(list,new TreeNodeMapper<QueryOrgMemberVO>() {
            @Override
            public TreeNode objectMapper(QueryOrgMemberVO object) {
                //将查询到的组织数据转换为树形结构
                QueryOrgMemberVO treeNode = new QueryOrgMemberVO();
                // 首先设置TreeNode计算层数使用属性
                if (treeNode.getXpid() == null){
                    treeNode.setXpid(null);
                }
                else {
                    treeNode.setXpid(object.getXpid());
                }
                // 设置组织扩展属性
                treeNode.setTnId(object.getXid());
                treeNode.setXid(object.getXid());
                treeNode.setXname(object.getXname());
                treeNode.setXicon(object.getXicon());
                return treeNode;
            }
        });
        return tree;
    }
}
