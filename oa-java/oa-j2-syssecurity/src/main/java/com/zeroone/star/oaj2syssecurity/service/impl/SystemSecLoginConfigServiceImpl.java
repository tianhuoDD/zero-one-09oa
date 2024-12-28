package com.zeroone.star.oaj2syssecurity.service.impl;

import com.zeroone.star.oaj2syssecurity.entity.LoginConfig;
import com.zeroone.star.oaj2syssecurity.mapper.SystemSecLoginConfigMapper;
import com.zeroone.star.oaj2syssecurity.service.SystemSecLoginConfigService;
import com.zeroone.star.project.dto.j2.system.security.login.LoginSaveDTO;
import com.zeroone.star.project.vo.j2.system.security.login.LoginConfigVO;
import org.springframework.stereotype.Service;
import javax.annotation.Resource;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.Properties;


@Service
public class SystemSecLoginConfigServiceImpl implements SystemSecLoginConfigService {

    @Resource
    private SystemSecLoginConfigMapper loginConfigMapper;

    /**
     *
     * @param loginSaveDTO 登录配置参数
     */
    @Override
    public Boolean saveLoginConfig(LoginSaveDTO loginSaveDTO) {

        if (!loginConfigMapper.findById(1).isPresent()){
            return saveLoginConfigFromFile();
        } else {
            LoginConfig config = new LoginConfig();
            config.setEnableSmsLogin(loginSaveDTO.getEnableSmsLogin());
            config.setEnablePicLogin(loginSaveDTO.getEnablePicLogin());
            config.setId(loginSaveDTO.getId());
            try {
                loginConfigMapper.save(config);
                return true;
            } catch (Exception e){
                return false;
            }
        }
    }


    /**
     * 查询登录配置
     *
     * @return 登录配置列表
     */
    @Override
    public List<LoginConfigVO> queryLoginConfig() {
        List<LoginConfigVO> configVOList = new ArrayList<>();
        try {
            Optional<LoginConfig> configOptional = loginConfigMapper.findById(1);

            // 检查是否有数据
            if (configOptional.isPresent()) {
                LoginConfig config = configOptional.get();
                LoginConfigVO configVO = new LoginConfigVO();
                configVO.setEnableSmsLogin(config.getEnableSmsLogin());
                configVO.setEnablePicLogin(config.getEnablePicLogin());
                configVOList.add(configVO);
            }
        } catch (Exception e) {
            throw new RuntimeException("查询登录配置失败", e);
        }

        return configVOList;
    }

    /**
     * 判断是否需要验证码
     *
     * @return 1 需要开启短信验证码，2 需要开启图片验证码，3 不开启
     */
    @Override
    public int isCaptchaRequired() {

        List<LoginConfig> configList = loginConfigMapper.findAll();
        if (!configList.isEmpty()) {
            LoginConfig config = configList.get(0);
            if (config.getEnableSmsLogin()){
                return 1;
            } else if (config.getEnablePicLogin()){
                return 2;
            }
        }
        return 0;
    }

    /**
     * 从配置文件中读取初始数据
     *
     */
    @Override
    public Boolean saveLoginConfigFromFile() {
        Properties properties = new Properties();

        // 使用类加载器读取位于类路径下的文件
        try (InputStream input = getClass().getResourceAsStream("/loginConfig.properties")) {
            // 确保输入流不为空
            if (input == null) {
                System.out.println("Unable to find");
                return false;
            }

            properties.load(input);

            LoginConfig config = new LoginConfig();
            config.setId(Integer.parseInt(properties.getProperty("id")));
            config.setEnablePicLogin(Boolean.parseBoolean(properties.getProperty("enablePicLogin")));
            config.setEnableSmsLogin(Boolean.parseBoolean(properties.getProperty("enableSmsLogin")));


            loginConfigMapper.save(config);
            System.out.println("Success");
        } catch (IOException e) {
            System.out.println("error");
            e.printStackTrace();
            return false;
        } catch (NumberFormatException e) {
            System.out.println("ID格式不正确，请确保它是一个有效的整数");
            e.printStackTrace();
            return false;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
        return false;
    }


}
