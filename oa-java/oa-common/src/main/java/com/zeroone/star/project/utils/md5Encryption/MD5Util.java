package com.zeroone.star.project.utils.md5Encryption;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class MD5Util {

    private static final String SALT = "kaltsit";

    /**
     * MD5加密方法
     *
     * @param password 要加密的密码
     * @return 加密后的字符串
     */
    public static String encrypt(String password) {
        try {
            // 创建MD5摘要
            MessageDigest md = MessageDigest.getInstance("MD5");
            // 将盐和密码组合
            String saltedPassword = SALT + password;
            // 更新摘要
            md.update(saltedPassword.getBytes());
            // 获取加密后的字节数组
            byte[] digest = md.digest();

            // 转换为16进制字符串
            StringBuilder hexString = new StringBuilder();
            for (byte b : digest) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) {
                    hexString.append('0');
                }
                hexString.append(hex);
            }
            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException("MD5加密失败", e);
        }
    }
}
