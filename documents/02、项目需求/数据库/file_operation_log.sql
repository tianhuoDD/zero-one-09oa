/*
 Navicat Premium Data Transfer

 Source Server         : docker_mysql8
 Source Server Type    : MySQL
 Source Server Version : 80020
 Source Host           : 192.168.122.128:3306
 Source Schema         : zo_oa

 Target Server Type    : MySQL
 Target Server Version : 80020
 File Encoding         : 65001

 Date: 26/10/2024 21:03:40
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for file_operation_log
-- ----------------------------
DROP TABLE IF EXISTS `file_operation_log`;
CREATE TABLE `file_operation_log`  (
  `xid` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '唯一标识',
  `xOperationType` int NOT NULL COMMENT '1-发送，2-分享，3-删除，4-上传',
  `xFromPerson` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '发起者',
  `xToPerson` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '接收者',
  `xOperationTime` datetime NOT NULL COMMENT '操作时间',
  `file_attachment_id` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '操作文件的唯一标识',
  PRIMARY KEY (`xid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
