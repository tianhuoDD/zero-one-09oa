package com.zeroone.star.project.vo.j1.captcha;

import java.util.HashMap;
import java.util.Map;

/**
 * @author LLL
 * 判断传进来的参数的异常值
 */
public class CodeStatus {

    private static final Map<String, String> repCodeMessages = new HashMap<>();

    static {
        repCodeMessages.put("0000", "无异常，代表成功");
        repCodeMessages.put("9999", "服务器内部异常");
        repCodeMessages.put("0011", "参数不能为空");
        repCodeMessages.put("6110", "验证码已失效，请重新获取");
        repCodeMessages.put("6111", "验证失败");
        repCodeMessages.put("6112", "获取验证码失败,请联系管理员");
        repCodeMessages.put("6113", "底图未初始化成功，请检查路径");
        repCodeMessages.put("6201", "get接口请求次数超限，请稍后再试!");
        repCodeMessages.put("6206", "无效请求，请重新获取验证码");
        repCodeMessages.put("6202", "接口验证失败数过多，请稍后再试");
        repCodeMessages.put("6204", "check接口请求次数超限，请稍后再试!");
    }

    public static String getMessageByCode(String code) {
        return repCodeMessages.get(code);
    }

}



