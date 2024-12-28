# 系统基础配置

命名格式\
SystemBasic+功能名+Controller(Service/Mapper..)

1. 获取系统基本信息 SystemBasicInformationController-->queryBasicInfo();
2. 修改系统名称    SystemBasicInformationController-->modifySystemTitle(String title);
3. 修改系统副标题  SystemBasicInformationController-->modifySystemFooter(String footer);