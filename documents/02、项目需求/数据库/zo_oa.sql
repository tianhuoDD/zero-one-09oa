-- ----------------------------
--  Create database and change database
-- ----------------------------
DROP DATABASE IF EXISTS `zo_oa`;
CREATE DATABASE `zo_oa` CHARACTER SET 'utf8mb4' COLLATE 'utf8mb4_0900_ai_ci';
USE `zo_oa`;

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for atdc_attendance_detail
-- ----------------------------
CREATE TABLE `atdc_attendance_detail`  (
                                           `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                           `xcreateTime` datetime NULL DEFAULT NULL,
                                           `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xupdateTime` datetime NULL DEFAULT NULL,
                                           `xdistributeFactor` int NULL DEFAULT NULL,
                                           `xabnormalDutyDayTime` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xabsence` double NULL DEFAULT NULL,
                                           `xabsentDayTime` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xafternoonOnDutyTime` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xappealDescription` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                           `xappealProcessor` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xappealReason` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xappealStatus` int NULL DEFAULT NULL,
                                           `xarchiveTime` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xattendance` double NULL DEFAULT NULL,
                                           `xbatchName` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xcycleMonth` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xcycleYear` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xempName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xempNo` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xgetSelfHolidayDays` double NULL DEFAULT NULL,
                                           `xisAbnormalDuty` bit(1) NULL DEFAULT NULL,
                                           `xisAbsent` bit(1) NULL DEFAULT NULL,
                                           `xisExternal` bit(1) NULL DEFAULT NULL,
                                           `xisGetSelfHolidays` bit(1) NULL DEFAULT NULL,
                                           `xisHoliday` bit(1) NULL DEFAULT NULL,
                                           `xisLackOfTime` bit(1) NULL DEFAULT NULL,
                                           `xisLate` bit(1) NULL DEFAULT NULL,
                                           `xisLeaveEarlier` bit(1) NULL DEFAULT NULL,
                                           `xisWeekend` bit(1) NULL DEFAULT NULL,
                                           `xisWorkOvertime` bit(1) NULL DEFAULT NULL,
                                           `xisWorkday` bit(1) NULL DEFAULT NULL,
                                           `xlateTimeDuration` bigint NULL DEFAULT NULL,
                                           `xleaveEarlierTimeDuration` bigint NULL DEFAULT NULL,
                                           `xleaveType` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xmiddayRestEndTime` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xmiddayRestStartTime` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xmonthString` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xmorningOffDutyTime` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xoffDutyTime` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xoffWorkTime` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xonDutyTime` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xonWorkTime` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xoptMachineType` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xrecordAddress` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xrecordDate` datetime NULL DEFAULT NULL,
                                           `xrecordDateString` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xrecordStatus` int NULL DEFAULT NULL,
                                           `xselfHolidayDayTime` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xtopUnitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xunitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xworkOvertimeTimeDuration` bigint NULL DEFAULT NULL,
                                           `xworkTimeDuration` bigint NULL DEFAULT NULL,
                                           `xyearString` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           PRIMARY KEY (`xid`) USING BTREE,
                                           UNIQUE INDEX `ATDC_ATTENDANCE_DETAIL_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for atdc_attendance_setting
-- ----------------------------
CREATE TABLE `atdc_attendance_setting`  (
                                            `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                            `xcreateTime` datetime NULL DEFAULT NULL,
                                            `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xupdateTime` datetime NULL DEFAULT NULL,
                                            `xdistributeFactor` int NULL DEFAULT NULL,
                                            `xconfigCode` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xconfigName` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xconfigValue` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xisMultiple` bit(1) NULL DEFAULT NULL,
                                            `xorderNumber` int NULL DEFAULT NULL,
                                            `xselectContent` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xvalueType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            PRIMARY KEY (`xid`) USING BTREE,
                                            UNIQUE INDEX `ATDC_ATTENDANCE_SETTING_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for atdc_attendance_statistic_requirelog
-- ----------------------------
CREATE TABLE `atdc_attendance_statistic_requirelog`  (
                                                         `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                                         `xcreateTime` datetime NULL DEFAULT NULL,
                                                         `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                         `xupdateTime` datetime NULL DEFAULT NULL,
                                                         `xdistributeFactor` int NULL DEFAULT NULL,
                                                         `xdescription` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                                         `xprocessStatus` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                         `xprocessTime` datetime NULL DEFAULT NULL,
                                                         `xstatisticDay` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                         `xstatisticKey` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                         `xstatisticMonth` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                         `xstatisticName` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                         `xstatisticType` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                         `xstatisticYear` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                         PRIMARY KEY (`xid`) USING BTREE,
                                                         UNIQUE INDEX `ATDC_ATTENDANCE_STATISTIC_REQUIRELOG_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_alert_message
-- ----------------------------
CREATE TABLE `attend_v2_alert_message`  (
                                            `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                            `xcreateTime` datetime NULL DEFAULT NULL,
                                            `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xupdateTime` datetime NULL DEFAULT NULL,
                                            `xdistributeFactor` int NULL DEFAULT NULL,
                                            `xcheckInType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xsendDateTime` datetime NULL DEFAULT NULL,
                                            `xsendStatus` bit(1) NULL DEFAULT NULL,
                                            `xuserId` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            PRIMARY KEY (`xid`) USING BTREE,
                                            UNIQUE INDEX `ATTEND_V2_ALERT_MESSAGE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_appeal_info
-- ----------------------------
CREATE TABLE `attend_v2_appeal_info`  (
                                          `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                          `xcreateTime` datetime NULL DEFAULT NULL,
                                          `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                          `xupdateTime` datetime NULL DEFAULT NULL,
                                          `xdistributeFactor` int NULL DEFAULT NULL,
                                          `xendTime` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                          `xjobId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                          `xreason` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                          `xrecordDate` datetime NULL DEFAULT NULL,
                                          `xrecordDateString` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                          `xrecordId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                          `xsendStatus` bit(1) NULL DEFAULT NULL,
                                          `xstartTime` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                          `xstatus` int NULL DEFAULT NULL,
                                          `xupdateStatusAdminPerson` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                          `xuserId` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                          PRIMARY KEY (`xid`) USING BTREE,
                                          UNIQUE INDEX `ATTEND_V2_APPEAL_INFO_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_config
-- ----------------------------
CREATE TABLE `attend_v2_config`  (
                                     `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                     `xcreateTime` datetime NULL DEFAULT NULL,
                                     `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xupdateTime` datetime NULL DEFAULT NULL,
                                     `xdistributeFactor` int NULL DEFAULT NULL,
                                     `xappealEnable` bit(1) NULL DEFAULT NULL,
                                     `xappealMaxTimes` int NULL DEFAULT NULL,
                                     `xcheckInAlertEnable` bit(1) NULL DEFAULT NULL,
                                     `xcloseOldAttendance` bit(1) NULL DEFAULT NULL,
                                     `xdetailStatisticCronString` varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xexceptionAlertDate` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xexceptionAlertEnable` bit(1) NULL DEFAULT NULL,
                                     `xexceptionAlertTime` varchar(8) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xoffDutyFastCheckInEnable` bit(1) NULL DEFAULT NULL,
                                     `xonDutyFastCheckInEnable` bit(1) NULL DEFAULT NULL,
                                     `xprocessId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xprocessName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     PRIMARY KEY (`xid`) USING BTREE,
                                     UNIQUE INDEX `ATTEND_V2_CONFIG_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_detail
-- ----------------------------
CREATE TABLE `attend_v2_detail`  (
                                     `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                     `xcreateTime` datetime NULL DEFAULT NULL,
                                     `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xupdateTime` datetime NULL DEFAULT NULL,
                                     `xdistributeFactor` int NULL DEFAULT NULL,
                                     `xabsenteeismDays` int NULL DEFAULT NULL,
                                     `xattendance` int NULL DEFAULT NULL,
                                     `xfieldWorkTimes` int NULL DEFAULT NULL,
                                     `xgroupId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xgroupName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xlateTimeDuration` bigint NULL DEFAULT NULL,
                                     `xlateTimes` int NULL DEFAULT NULL,
                                     `xleaveDays` int NULL DEFAULT NULL,
                                     `xleaveEarlierTimeDuration` bigint NULL DEFAULT NULL,
                                     `xleaveEarlierTimes` int NULL DEFAULT NULL,
                                     `xmonthString` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xoffDutyAbsenceTimes` int NULL DEFAULT NULL,
                                     `xonDutyAbsenceTimes` int NULL DEFAULT NULL,
                                     `xrecordDateString` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xrecordDay` varchar(4) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xrest` int NULL DEFAULT NULL,
                                     `xshiftId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xshiftName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xuserId` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xworkDay` bit(1) NULL DEFAULT NULL,
                                     `xworkTimeDuration` bigint NULL DEFAULT NULL,
                                     `xyearString` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     PRIMARY KEY (`xid`) USING BTREE,
                                     UNIQUE INDEX `ATTEND_V2_DETAIL_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_detail_recordidlist
-- ----------------------------
CREATE TABLE `attend_v2_detail_recordidlist`  (
                                                  `ATTENDANCEV2DETAIL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xrecordIdList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `ATTEND_V2_DETAILrecordIdList_element`(`xrecordIdList` ASC) USING BTREE,
                                                  INDEX `ATTEND_V2_DETAILrecordIdList_join`(`ATTENDANCEV2DETAIL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_group
-- ----------------------------
CREATE TABLE `attend_v2_group`  (
                                    `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                    `xcreateTime` datetime NULL DEFAULT NULL,
                                    `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xupdateTime` datetime NULL DEFAULT NULL,
                                    `xdistributeFactor` int NULL DEFAULT NULL,
                                    `xallowFieldWork` bit(1) NULL DEFAULT NULL,
                                    `xcheckType` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xfieldWorkMarkError` bit(1) NULL DEFAULT NULL,
                                    `xgroupName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xoperator` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xrequiredFieldWorkRemarks` bit(1) NULL DEFAULT NULL,
                                    `xshiftId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xstatus` int NULL DEFAULT NULL,
                                    `xworkDateList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xworkDateProperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                    PRIMARY KEY (`xid`) USING BTREE,
                                    UNIQUE INDEX `ATTEND_V2_GROUP_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_group_assistadminlist
-- ----------------------------
CREATE TABLE `attend_v2_group_assistadminlist`  (
                                                    `ATTENDANCEV2GROUP_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xassistAdminList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `ATTEND_V2_GROUPassistAdminList_element`(`xassistAdminList` ASC) USING BTREE,
                                                    INDEX `ATTEND_V2_GROUPassistAdminList_join`(`ATTENDANCEV2GROUP_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_group_noneedcheckindatelist
-- ----------------------------
CREATE TABLE `attend_v2_group_noneedcheckindatelist`  (
                                                          `ATTENDANCEV2GROUP_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                          `xnoNeedCheckInDateList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                          `xorderColumn` int NULL DEFAULT NULL,
                                                          INDEX `ATTEND_V2_GROUPnoNeedCheckInDateList_element`(`xnoNeedCheckInDateList` ASC) USING BTREE,
                                                          INDEX `ATTEND_V2_GROUPnoNeedCheckInDateList_join`(`ATTENDANCEV2GROUP_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_group_participatelist
-- ----------------------------
CREATE TABLE `attend_v2_group_participatelist`  (
                                                    `ATTENDANCEV2GROUP_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xparticipateList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `ATTEND_V2_GROUPparticipateList_element`(`xparticipateList` ASC) USING BTREE,
                                                    INDEX `ATTEND_V2_GROUPparticipateList_join`(`ATTENDANCEV2GROUP_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_group_requiredcheckindatelist
-- ----------------------------
CREATE TABLE `attend_v2_group_requiredcheckindatelist`  (
                                                            `ATTENDANCEV2GROUP_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                            `xrequiredCheckInDateList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                            `xorderColumn` int NULL DEFAULT NULL,
                                                            INDEX `ATTEND_V2_GROUPrequiredCheckInDateList_element`(`xrequiredCheckInDateList` ASC) USING BTREE,
                                                            INDEX `ATTEND_V2_GROUPrequiredCheckInDateList_join`(`ATTENDANCEV2GROUP_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_group_trueparticipantlist
-- ----------------------------
CREATE TABLE `attend_v2_group_trueparticipantlist`  (
                                                        `ATTENDANCEV2GROUP_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xtrueParticipantList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xorderColumn` int NULL DEFAULT NULL,
                                                        INDEX `ATTEND_V2_GROUPtrueParticipantList_element`(`xtrueParticipantList` ASC) USING BTREE,
                                                        INDEX `ATTEND_V2_GROUPtrueParticipantList_join`(`ATTENDANCEV2GROUP_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_group_unparticipatelist
-- ----------------------------
CREATE TABLE `attend_v2_group_unparticipatelist`  (
                                                      `ATTENDANCEV2GROUP_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xunParticipateList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xorderColumn` int NULL DEFAULT NULL,
                                                      INDEX `ATTEND_V2_GROUPunParticipateList_element`(`xunParticipateList` ASC) USING BTREE,
                                                      INDEX `ATTEND_V2_GROUPunParticipateList_join`(`ATTENDANCEV2GROUP_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_group_workplaceidlist
-- ----------------------------
CREATE TABLE `attend_v2_group_workplaceidlist`  (
                                                    `ATTENDANCEV2GROUP_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xworkPlaceIdList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `ATTEND_V2_GROUPworkPlaceIdList_element`(`xworkPlaceIdList` ASC) USING BTREE,
                                                    INDEX `ATTEND_V2_GROUPworkPlaceIdList_join`(`ATTENDANCEV2GROUP_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_leave_data
-- ----------------------------
CREATE TABLE `attend_v2_leave_data`  (
                                         `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                         `xcreateTime` datetime NULL DEFAULT NULL,
                                         `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xupdateTime` datetime NULL DEFAULT NULL,
                                         `xdistributeFactor` int NULL DEFAULT NULL,
                                         `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xendTime` datetime NULL DEFAULT NULL,
                                         `xjobId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xleaveDayNumber` double NULL DEFAULT NULL,
                                         `xleaveType` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xperson` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xstartTime` datetime NULL DEFAULT NULL,
                                         PRIMARY KEY (`xid`) USING BTREE,
                                         UNIQUE INDEX `ATTEND_V2_LEAVE_DATA_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_shift
-- ----------------------------
CREATE TABLE `attend_v2_shift`  (
                                    `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                    `xcreateTime` datetime NULL DEFAULT NULL,
                                    `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xupdateTime` datetime NULL DEFAULT NULL,
                                    `xdistributeFactor` int NULL DEFAULT NULL,
                                    `xabsenteeismLateMinutes` int NULL DEFAULT NULL,
                                    `xlateAndEarlyOffTime` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xlateAndEarlyOnTime` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xneedLimitWorkTime` bit(1) NULL DEFAULT NULL,
                                    `xoperator` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                    `xseriousTardinessLateMinutes` int NULL DEFAULT NULL,
                                    `xshiftName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xworkTime` int NULL DEFAULT NULL,
                                    PRIMARY KEY (`xid`) USING BTREE,
                                    UNIQUE INDEX `ATTEND_V2_SHIFT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for attend_v2_work_place
-- ----------------------------
CREATE TABLE `attend_v2_work_place`  (
                                         `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                         `xcreateTime` datetime NULL DEFAULT NULL,
                                         `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xupdateTime` datetime NULL DEFAULT NULL,
                                         `xdistributeFactor` int NULL DEFAULT NULL,
                                         `xcreator` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xerrorRange` int NULL DEFAULT NULL,
                                         `xgpsLat` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xgpsLng` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xlatitude` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xlongitude` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xplaceAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xplaceName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xpositionType` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         PRIMARY KEY (`xid`) USING BTREE,
                                         UNIQUE INDEX `ATTEND_V2_WORK_PLACE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_configsetting
-- ----------------------------
CREATE TABLE `bbs_configsetting`  (
                                      `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                      `xcreateTime` datetime NULL DEFAULT NULL,
                                      `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xupdateTime` datetime NULL DEFAULT NULL,
                                      `xdistributeFactor` int NULL DEFAULT NULL,
                                      `xconfigCode` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xconfigName` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xconfigValue` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xisMultiple` bit(1) NULL DEFAULT NULL,
                                      `xorderNumber` int NULL DEFAULT NULL,
                                      `xselectContent` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xvalueType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      PRIMARY KEY (`xid`) USING BTREE,
                                      UNIQUE INDEX `BBS_CONFIGSETTING_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                      INDEX `BBS_CONFIGSETTING_configCode`(`xconfigCode` ASC) USING BTREE,
                                      INDEX `BBS_CONFIGSETTING_description`(`xdescription` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_foruminfo
-- ----------------------------
CREATE TABLE `bbs_foruminfo`  (
                                  `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                  `xcreateTime` datetime NULL DEFAULT NULL,
                                  `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xupdateTime` datetime NULL DEFAULT NULL,
                                  `xdistributeFactor` int NULL DEFAULT NULL,
                                  `xcreatorName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xforumColor` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xforumIndexStyle` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xforumName` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xforumNotice` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xforumStatus` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xforumVisible` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xindexListStyle` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xindexRecommendable` bit(1) NULL DEFAULT NULL,
                                  `xorderNumber` int NULL DEFAULT NULL,
                                  `xreplyMessageNotify` bit(1) NULL DEFAULT NULL,
                                  `xreplyMessageNotifyType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xreplyNeedAudit` bit(1) NULL DEFAULT NULL,
                                  `xreplyPublishAble` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xreplyTotal` bigint NULL DEFAULT NULL,
                                  `xreplyTotalToday` bigint NULL DEFAULT NULL,
                                  `xsectionCreateAble` bit(1) NULL DEFAULT NULL,
                                  `xsectionTotal` bigint NULL DEFAULT NULL,
                                  `xsubjectMessageNotify` bit(1) NULL DEFAULT NULL,
                                  `xsubjectMessageNotifyType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xsubjectNeedAudit` bit(1) NULL DEFAULT NULL,
                                  `xsubjectPublishAble` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xsubjectTotal` bigint NULL DEFAULT NULL,
                                  `xsubjectTotalToday` bigint NULL DEFAULT NULL,
                                  `xsubjectType` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xtypeCategory` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  PRIMARY KEY (`xid`) USING BTREE,
                                  UNIQUE INDEX `BBS_FORUMINFO_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                  INDEX `BBS_FORUMINFO_forumStatus`(`xforumStatus` ASC) USING BTREE,
                                  INDEX `BBS_FORUMINFO_forumVisible`(`xforumVisible` ASC) USING BTREE,
                                  INDEX `BBS_FORUMINFO_subjectPublishAble`(`xsubjectPublishAble` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_foruminfo_forummanagerlist
-- ----------------------------
CREATE TABLE `bbs_foruminfo_forummanagerlist`  (
                                                   `BBSFORUMINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xforumManagerList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `BBS_FORUMINFO_forumManagerList_element`(`xforumManagerList` ASC) USING BTREE,
                                                   INDEX `BBS_FORUMINFO_forumManagerList_join`(`BBSFORUMINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_foruminfo_publishpermissionlist
-- ----------------------------
CREATE TABLE `bbs_foruminfo_publishpermissionlist`  (
                                                        `BBSFORUMINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xpublishPermissionList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xorderColumn` int NULL DEFAULT NULL,
                                                        INDEX `BBS_FORUMINFO_publishPermissionList_element`(`xpublishPermissionList` ASC) USING BTREE,
                                                        INDEX `BBS_FORUMINFO_publishPermissionList_join`(`BBSFORUMINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_foruminfo_replypermissionlist
-- ----------------------------
CREATE TABLE `bbs_foruminfo_replypermissionlist`  (
                                                      `BBSFORUMINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xreplyPermissionList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xorderColumn` int NULL DEFAULT NULL,
                                                      INDEX `BBS_FORUMINFO_replyPermissionList_element`(`xreplyPermissionList` ASC) USING BTREE,
                                                      INDEX `BBS_FORUMINFO_replyPermissionList_join`(`BBSFORUMINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_foruminfo_visiblepermissionlist
-- ----------------------------
CREATE TABLE `bbs_foruminfo_visiblepermissionlist`  (
                                                        `BBSFORUMINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xvisiblePermissionList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xorderColumn` int NULL DEFAULT NULL,
                                                        INDEX `BBS_FORUMINFO_visiblePermissionList_element`(`xvisiblePermissionList` ASC) USING BTREE,
                                                        INDEX `BBS_FORUMINFO_visiblePermissionList_join`(`BBSFORUMINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_operationrecord
-- ----------------------------
CREATE TABLE `bbs_operationrecord`  (
                                        `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                        `xcreateTime` datetime NULL DEFAULT NULL,
                                        `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xupdateTime` datetime NULL DEFAULT NULL,
                                        `xdistributeFactor` int NULL DEFAULT NULL,
                                        `xforumId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xforumName` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xhostIp` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xhostname` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xmainSectionId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xmainSectionName` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xobjectId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xobjectName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xobjectType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xoperatorName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xoptType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xsectionId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xsectionName` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xsubjectId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        PRIMARY KEY (`xid`) USING BTREE,
                                        UNIQUE INDEX `BBS_OPERATIONRECORD_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                        INDEX `BBS_OPERATIONRECORD_forumId`(`xforumId` ASC) USING BTREE,
                                        INDEX `BBS_OPERATIONRECORD_hostname`(`xhostname` ASC) USING BTREE,
                                        INDEX `BBS_OPERATIONRECORD_mainSectionId`(`xmainSectionId` ASC) USING BTREE,
                                        INDEX `BBS_OPERATIONRECORD_mainSectionName`(`xmainSectionName` ASC) USING BTREE,
                                        INDEX `BBS_OPERATIONRECORD_objectId`(`xobjectId` ASC) USING BTREE,
                                        INDEX `BBS_OPERATIONRECORD_objectName`(`xobjectName` ASC) USING BTREE,
                                        INDEX `BBS_OPERATIONRECORD_objectType`(`xobjectType` ASC) USING BTREE,
                                        INDEX `BBS_OPERATIONRECORD_operatorName`(`xoperatorName` ASC) USING BTREE,
                                        INDEX `BBS_OPERATIONRECORD_optType`(`xoptType` ASC) USING BTREE,
                                        INDEX `BBS_OPERATIONRECORD_sectionId`(`xsectionId` ASC) USING BTREE,
                                        INDEX `BBS_OPERATIONRECORD_sectionName`(`xsectionName` ASC) USING BTREE,
                                        INDEX `BBS_OPERATIONRECORD_subjectId`(`xsubjectId` ASC) USING BTREE,
                                        INDEX `BBS_OPERATIONRECORD_title`(`xtitle` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_replyinfo
-- ----------------------------
CREATE TABLE `bbs_replyinfo`  (
                                  `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                  `xcreateTime` datetime NULL DEFAULT NULL,
                                  `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xupdateTime` datetime NULL DEFAULT NULL,
                                  `xdistributeFactor` int NULL DEFAULT NULL,
                                  `xauditorName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xcontent` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xcreatorName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xforumId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xforumName` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xhostIp` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xmachineName` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xmainSectionId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xmainSectionName` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xnickName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xorderNumber` int NULL DEFAULT NULL,
                                  `xparentId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xpicId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xreplyAuditStatus` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xsectionId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xsectionName` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xsubjectId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xsystemType` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  PRIMARY KEY (`xid`) USING BTREE,
                                  UNIQUE INDEX `BBS_REPLYINFO_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                  INDEX `BBS_REPLYINFO_auditorName`(`xauditorName` ASC) USING BTREE,
                                  INDEX `BBS_REPLYINFO_creatorName`(`xcreatorName` ASC) USING BTREE,
                                  INDEX `BBS_REPLYINFO_forumId`(`xforumId` ASC) USING BTREE,
                                  INDEX `BBS_REPLYINFO_hostIp`(`xhostIp` ASC) USING BTREE,
                                  INDEX `BBS_REPLYINFO_machineName`(`xmachineName` ASC) USING BTREE,
                                  INDEX `BBS_REPLYINFO_mainSectionId`(`xmainSectionId` ASC) USING BTREE,
                                  INDEX `BBS_REPLYINFO_parentId`(`xparentId` ASC) USING BTREE,
                                  INDEX `BBS_REPLYINFO_picId`(`xpicId` ASC) USING BTREE,
                                  INDEX `BBS_REPLYINFO_replyAuditStatus`(`xreplyAuditStatus` ASC) USING BTREE,
                                  INDEX `BBS_REPLYINFO_sectionId`(`xsectionId` ASC) USING BTREE,
                                  INDEX `BBS_REPLYINFO_subjectId`(`xsubjectId` ASC) USING BTREE,
                                  INDEX `BBS_REPLYINFO_systemType`(`xsystemType` ASC) USING BTREE,
                                  INDEX `BBS_REPLYINFO_title`(`xtitle` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_sectioninfo
-- ----------------------------
CREATE TABLE `bbs_sectioninfo`  (
                                    `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                    `xcreateTime` datetime NULL DEFAULT NULL,
                                    `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xupdateTime` datetime NULL DEFAULT NULL,
                                    `xdistributeFactor` int NULL DEFAULT NULL,
                                    `xcreatorName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xforumId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xforumName` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xicon` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                    `xindexRecommendable` bit(1) NULL DEFAULT NULL,
                                    `xmainSectionId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xmainSectionName` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xorderNumber` int NULL DEFAULT NULL,
                                    `xreplyMessageNotify` bit(1) NULL DEFAULT NULL,
                                    `xreplyMessageNotifyType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xreplyNeedAudit` bit(1) NULL DEFAULT NULL,
                                    `xreplyPublishAble` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xreplyTotal` bigint NULL DEFAULT NULL,
                                    `xreplyTotalToday` bigint NULL DEFAULT NULL,
                                    `xsectionDescription` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                    `xsectionGrade` bit(1) NULL DEFAULT NULL,
                                    `xsectionLevel` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xsectionName` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xsectionNotice` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                    `xsectionStatus` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xsectionType` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xsectionVisible` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xsubSectionCreateAble` bit(1) NULL DEFAULT NULL,
                                    `xsubjectMessageNotify` bit(1) NULL DEFAULT NULL,
                                    `xsubjectMessageNotifyType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xsubjectNeedAudit` bit(1) NULL DEFAULT NULL,
                                    `xsubjectPublishAble` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xsubjectTotal` bigint NULL DEFAULT NULL,
                                    `xsubjectTotalToday` bigint NULL DEFAULT NULL,
                                    `xsubjectType` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xtypeCategory` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    PRIMARY KEY (`xid`) USING BTREE,
                                    UNIQUE INDEX `BBS_SECTIONINFO_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                    INDEX `BBS_SECTIONINFO_forumId`(`xforumId` ASC) USING BTREE,
                                    INDEX `BBS_SECTIONINFO_mainSectionId`(`xmainSectionId` ASC) USING BTREE,
                                    INDEX `BBS_SECTIONINFO_sectionLevel`(`xsectionLevel` ASC) USING BTREE,
                                    INDEX `BBS_SECTIONINFO_sectionName`(`xsectionName` ASC) USING BTREE,
                                    INDEX `BBS_SECTIONINFO_sectionStatus`(`xsectionStatus` ASC) USING BTREE,
                                    INDEX `BBS_SECTIONINFO_sectionVisible`(`xsectionVisible` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_sectioninfo_moderatornames
-- ----------------------------
CREATE TABLE `bbs_sectioninfo_moderatornames`  (
                                                   `BBSSECTIONINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xmoderatorNames` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `BBS_SECTIONINFO_moderatorNames_element`(`xmoderatorNames` ASC) USING BTREE,
                                                   INDEX `BBS_SECTIONINFO_moderatorNames_join`(`BBSSECTIONINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_sectioninfo_publishpermissionlist
-- ----------------------------
CREATE TABLE `bbs_sectioninfo_publishpermissionlist`  (
                                                          `BBSSECTIONINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                          `xpublishPermissionList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                          `xorderColumn` int NULL DEFAULT NULL,
                                                          INDEX `BBS_SECTIONINFO_publishPermissionList_element`(`xpublishPermissionList` ASC) USING BTREE,
                                                          INDEX `BBS_SECTIONINFO_publishPermissionList_join`(`BBSSECTIONINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_sectioninfo_replypermissionlist
-- ----------------------------
CREATE TABLE `bbs_sectioninfo_replypermissionlist`  (
                                                        `BBSSECTIONINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xreplyPermissionList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xorderColumn` int NULL DEFAULT NULL,
                                                        INDEX `BBS_SECTIONINFO_replyPermissionList_element`(`xreplyPermissionList` ASC) USING BTREE,
                                                        INDEX `BBS_SECTIONINFO_replyPermissionList_join`(`BBSSECTIONINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_sectioninfo_subjecttypelist
-- ----------------------------
CREATE TABLE `bbs_sectioninfo_subjecttypelist`  (
                                                    `BBSSECTIONINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xsubjectTypeList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `BBS_SECTIONINFO_subjectTypeList_element`(`xsubjectTypeList` ASC) USING BTREE,
                                                    INDEX `BBS_SECTIONINFO_subjectTypeList_join`(`BBSSECTIONINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_sectioninfo_visiblepermissionlist
-- ----------------------------
CREATE TABLE `bbs_sectioninfo_visiblepermissionlist`  (
                                                          `BBSSECTIONINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                          `xvisiblePermissionList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                          `xorderColumn` int NULL DEFAULT NULL,
                                                          INDEX `BBS_SECTIONINFO_visiblePermissionList_element`(`xvisiblePermissionList` ASC) USING BTREE,
                                                          INDEX `BBS_SECTIONINFO_visiblePermissionList_join`(`BBSSECTIONINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_shutup
-- ----------------------------
CREATE TABLE `bbs_shutup`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xoperator` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xreason` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xunmuteDate` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xunmuteDateTime` datetime NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `BBS_SHUTUP_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               UNIQUE INDEX `BBS_SHUTUP_person`(`xperson` ASC) USING BTREE,
                               INDEX `BBS_SHUTUP_unmuteDateTime`(`xunmuteDateTime` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_subjectinfo
-- ----------------------------
CREATE TABLE `bbs_subjectinfo`  (
                                    `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                    `xcreateTime` datetime NULL DEFAULT NULL,
                                    `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xupdateTime` datetime NULL DEFAULT NULL,
                                    `xdistributeFactor` int NULL DEFAULT NULL,
                                    `xacceptReplyId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xanonymousSubject` bit(1) NULL DEFAULT NULL,
                                    `xauditorName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xbBSIndexSetterName` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xbBSIndexSetterTime` datetime NULL DEFAULT NULL,
                                    `xcreatorName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xforumId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xforumIndexSetterName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xforumIndexSetterTime` datetime NULL DEFAULT NULL,
                                    `xforumName` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xgrade` int NULL DEFAULT NULL,
                                    `xhostIp` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xhot` bigint NULL DEFAULT NULL,
                                    `xisCompleted` bit(1) NULL DEFAULT NULL,
                                    `xisCreamSubject` bit(1) NULL DEFAULT NULL,
                                    `xisOriginalSubject` bit(1) NULL DEFAULT NULL,
                                    `xisRecommendSubject` bit(1) NULL DEFAULT NULL,
                                    `xisTopSubject` bit(1) NULL DEFAULT NULL,
                                    `xlastUpdateUser` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xlatestReplyId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xlatestReplyTime` datetime NULL DEFAULT NULL,
                                    `xlatestReplyUser` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xmachineName` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xmainSectionId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xmainSectionName` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xnickName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xorderNumber` int NULL DEFAULT NULL,
                                    `xoriginalSetterName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xoriginalSetterTime` datetime NULL DEFAULT NULL,
                                    `xpicId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xrecommendTime` datetime NULL DEFAULT NULL,
                                    `xrecommendToBBSIndex` bit(1) NULL DEFAULT NULL,
                                    `xrecommendToForumIndex` bit(1) NULL DEFAULT NULL,
                                    `xrecommendorName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xreplyTotal` bigint NULL DEFAULT NULL,
                                    `xscreamSetterName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xscreamSetterTime` datetime NULL DEFAULT NULL,
                                    `xsectionId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xsectionName` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xstopReply` bit(1) NULL DEFAULT NULL,
                                    `xsubjectAuditStatus` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xsubjectStatus` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xsummary` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xsystemType` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xtitle` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xtopToBBS` bit(1) NULL DEFAULT NULL,
                                    `xtopToForum` bit(1) NULL DEFAULT NULL,
                                    `xtopToMainSection` bit(1) NULL DEFAULT NULL,
                                    `xtopToSection` bit(1) NULL DEFAULT NULL,
                                    `xtype` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xtypeCategory` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xviewTotal` bigint NULL DEFAULT NULL,
                                    `xvoteLimitTime` datetime NULL DEFAULT NULL,
                                    `xvotePersonVisible` bit(1) NULL DEFAULT NULL,
                                    `xvoteResultVisible` bit(1) NULL DEFAULT NULL,
                                    PRIMARY KEY (`xid`) USING BTREE,
                                    UNIQUE INDEX `BBS_SUBJECTINFO_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                    INDEX `BBS_SUBJECTINFO_creatorName`(`xcreatorName` ASC) USING BTREE,
                                    INDEX `BBS_SUBJECTINFO_forumId`(`xforumId` ASC) USING BTREE,
                                    INDEX `BBS_SUBJECTINFO_mainSectionId`(`xmainSectionId` ASC) USING BTREE,
                                    INDEX `BBS_SUBJECTINFO_sectionId`(`xsectionId` ASC) USING BTREE,
                                    INDEX `BBS_SUBJECTINFO_type`(`xtype` ASC) USING BTREE,
                                    INDEX `BBS_SUBJECTINFO_typeCategory`(`xtypeCategory` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_subjectinfo_attachmentlist
-- ----------------------------
CREATE TABLE `bbs_subjectinfo_attachmentlist`  (
                                                   `BBSSUBJECTINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xattachmentList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `BBS_SUBJECTINFO_attachmentList_element`(`xattachmentList` ASC) USING BTREE,
                                                   INDEX `BBS_SUBJECTINFO_attachmentList_join`(`BBSSUBJECTINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_subjectinfo_editorlist
-- ----------------------------
CREATE TABLE `bbs_subjectinfo_editorlist`  (
                                               `BBSSUBJECTINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xeditorList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `BBS_SUBJECTINFO_editorList_element`(`xeditorList` ASC) USING BTREE,
                                               INDEX `BBS_SUBJECTINFO_editorList_join`(`BBSSUBJECTINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_userinfo
-- ----------------------------
CREATE TABLE `bbs_userinfo`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xcardId` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcreamCount` bigint NULL DEFAULT NULL,
                                 `xcredit` bigint NULL DEFAULT NULL,
                                 `xfansCount` bigint NULL DEFAULT NULL,
                                 `xlastOperationTime` datetime NULL DEFAULT NULL,
                                 `xlastVisitTime` datetime NULL DEFAULT NULL,
                                 `xmobile` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xnickName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xonline` bit(1) NULL DEFAULT NULL,
                                 `xorderNumber` int NULL DEFAULT NULL,
                                 `xoriginalCount` bigint NULL DEFAULT NULL,
                                 `xpermissionContent` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xpopularity` bigint NULL DEFAULT NULL,
                                 `xreplyCount` bigint NULL DEFAULT NULL,
                                 `xreplyCountToday` bigint NULL DEFAULT NULL,
                                 `xsex` int NULL DEFAULT NULL,
                                 `xsignContent` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xsubjectCount` bigint NULL DEFAULT NULL,
                                 `xsubjectCountToday` bigint NULL DEFAULT NULL,
                                 `xuserName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xuserStatus` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `BBS_USERINFO_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                 INDEX `BBS_USERINFO_userName`(`xuserName` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for bbs_userrole
-- ----------------------------
CREATE TABLE `bbs_userrole`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xforumId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xmainSectionId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xobjectName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xobjectType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xorderNumber` int NULL DEFAULT NULL,
                                 `xroleCode` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xroleId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xroleName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xsectionId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xtopUnitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xuniqueId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xunitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `BBS_USERROLE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                 INDEX `BBS_USERROLE_forumId`(`xforumId` ASC) USING BTREE,
                                 INDEX `BBS_USERROLE_mainSectionId`(`xmainSectionId` ASC) USING BTREE,
                                 INDEX `BBS_USERROLE_objectType`(`xobjectType` ASC) USING BTREE,
                                 INDEX `BBS_USERROLE_roleCode`(`xroleCode` ASC) USING BTREE,
                                 INDEX `BBS_USERROLE_roleId`(`xroleId` ASC) USING BTREE,
                                 INDEX `BBS_USERROLE_sectionId`(`xsectionId` ASC) USING BTREE,
                                 INDEX `BBS_USERROLE_topUnitName`(`xtopUnitName` ASC) USING BTREE,
                                 INDEX `BBS_USERROLE_uniqueId`(`xuniqueId` ASC) USING BTREE,
                                 INDEX `BBS_USERROLE_unitName`(`xunitName` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_calendar
-- ----------------------------
CREATE TABLE `cal_calendar`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xcolor` varchar(8) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcreateor` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xisPublic` bit(1) NULL DEFAULT NULL,
                                 `xname` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xsource` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xstatus` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xtarget` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xtype` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `CAL_CALENDAR_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                 INDEX `CAL_CALENDAR_createor`(`xcreateor` ASC) USING BTREE,
                                 INDEX `CAL_CALENDAR_name`(`xname` ASC) USING BTREE,
                                 INDEX `CAL_CALENDAR_status`(`xstatus` ASC) USING BTREE,
                                 INDEX `CAL_CALENDAR_target`(`xtarget` ASC) USING BTREE,
                                 INDEX `CAL_CALENDAR_type`(`xtype` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_calendar_followers
-- ----------------------------
CREATE TABLE `cal_calendar_followers`  (
                                           `CALENDAR_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xfollowers` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xorderColumn` int NULL DEFAULT NULL,
                                           INDEX `CAL_CALENDAR_followers_element`(`xfollowers` ASC) USING BTREE,
                                           INDEX `CAL_CALENDAR_followers_join`(`CALENDAR_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_calendar_manageablepersonlist
-- ----------------------------
CREATE TABLE `cal_calendar_manageablepersonlist`  (
                                                      `CALENDAR_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xmanageablePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xorderColumn` int NULL DEFAULT NULL,
                                                      INDEX `CAL_CALENDAR_manageablePersonList_element`(`xmanageablePersonList` ASC) USING BTREE,
                                                      INDEX `CAL_CALENDAR_manageablePersonList_join`(`CALENDAR_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_calendar_publishablegrouplist
-- ----------------------------
CREATE TABLE `cal_calendar_publishablegrouplist`  (
                                                      `CALENDAR_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xpublishableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xorderColumn` int NULL DEFAULT NULL,
                                                      INDEX `CAL_CALENDAR_publishableGroupList_element`(`xpublishableGroupList` ASC) USING BTREE,
                                                      INDEX `CAL_CALENDAR_publishableGroupList_join`(`CALENDAR_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_calendar_publishablepersonlist
-- ----------------------------
CREATE TABLE `cal_calendar_publishablepersonlist`  (
                                                       `CALENDAR_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xpublishablePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xorderColumn` int NULL DEFAULT NULL,
                                                       INDEX `CAL_CALENDAR_publishablePersonList_element`(`xpublishablePersonList` ASC) USING BTREE,
                                                       INDEX `CAL_CALENDAR_publishablePersonList_join`(`CALENDAR_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_calendar_publishableunitlist
-- ----------------------------
CREATE TABLE `cal_calendar_publishableunitlist`  (
                                                     `CALENDAR_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xpublishableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xorderColumn` int NULL DEFAULT NULL,
                                                     INDEX `CAL_CALENDAR_publishableUnitList_element`(`xpublishableUnitList` ASC) USING BTREE,
                                                     INDEX `CAL_CALENDAR_publishableUnitList_join`(`CALENDAR_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_calendar_viewablegrouplist
-- ----------------------------
CREATE TABLE `cal_calendar_viewablegrouplist`  (
                                                   `CALENDAR_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xviewableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `CAL_CALENDAR_viewableGroupList_element`(`xviewableGroupList` ASC) USING BTREE,
                                                   INDEX `CAL_CALENDAR_viewableGroupList_join`(`CALENDAR_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_calendar_viewablepersonlist
-- ----------------------------
CREATE TABLE `cal_calendar_viewablepersonlist`  (
                                                    `CALENDAR_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xviewablePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `CAL_CALENDAR_viewablePersonList_element`(`xviewablePersonList` ASC) USING BTREE,
                                                    INDEX `CAL_CALENDAR_viewablePersonList_join`(`CALENDAR_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_calendar_viewableunitlist
-- ----------------------------
CREATE TABLE `cal_calendar_viewableunitlist`  (
                                                  `CALENDAR_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xviewableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `CAL_CALENDAR_viewableUnitList_element`(`xviewableUnitList` ASC) USING BTREE,
                                                  INDEX `CAL_CALENDAR_viewableUnitList_join`(`CALENDAR_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_event
-- ----------------------------
CREATE TABLE `cal_event`  (
                              `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                              `xcreateTime` datetime NULL DEFAULT NULL,
                              `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xupdateTime` datetime NULL DEFAULT NULL,
                              `xdistributeFactor` int NULL DEFAULT NULL,
                              `xalarm` bit(1) NULL DEFAULT NULL,
                              `xalarmAlready` bit(1) NULL DEFAULT NULL,
                              `xalarmTime` datetime NULL DEFAULT NULL,
                              `xbundle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcalendarId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcolor` varchar(8) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcomment` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcommentId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcreatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xdaysOfDuration` int NULL DEFAULT NULL,
                              `xendTime` datetime NULL DEFAULT NULL,
                              `xendTimeStr` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xeventType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xisAllDayEvent` bit(1) NULL DEFAULT NULL,
                              `xisPublic` bit(1) NULL DEFAULT NULL,
                              `xlatitude` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xlocationName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xlongitude` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xrecurrenceExc` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xrecurrenceRule` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xrepeatMasterId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xsource` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstartTime` datetime NULL DEFAULT NULL,
                              `xstartTimeStr` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xtargetType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xtitle` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xupdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xvalarmTime_config` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xvalarm_Summary` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xvalarm_description` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xvalarm_mailto` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              PRIMARY KEY (`xid`) USING BTREE,
                              UNIQUE INDEX `CAL_EVENT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                              INDEX `CAL_EVENT_bundle`(`xbundle` ASC) USING BTREE,
                              INDEX `CAL_EVENT_calendarId`(`xcalendarId` ASC) USING BTREE,
                              INDEX `CAL_EVENT_createPerson`(`xcreatePerson` ASC) USING BTREE,
                              INDEX `CAL_EVENT_daysOfDuration`(`xdaysOfDuration` ASC) USING BTREE,
                              INDEX `CAL_EVENT_endTime`(`xendTime` ASC) USING BTREE,
                              INDEX `CAL_EVENT_endTimeStr`(`xendTimeStr` ASC) USING BTREE,
                              INDEX `CAL_EVENT_eventType`(`xeventType` ASC) USING BTREE,
                              INDEX `CAL_EVENT_repeatMasterId`(`xrepeatMasterId` ASC) USING BTREE,
                              INDEX `CAL_EVENT_source`(`xsource` ASC) USING BTREE,
                              INDEX `CAL_EVENT_startTime`(`xstartTime` ASC) USING BTREE,
                              INDEX `CAL_EVENT_startTimeStr`(`xstartTimeStr` ASC) USING BTREE,
                              INDEX `CAL_EVENT_targetType`(`xtargetType` ASC) USING BTREE,
                              INDEX `CAL_EVENT_updatePerson`(`xupdatePerson` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_event_comment
-- ----------------------------
CREATE TABLE `cal_event_comment`  (
                                      `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                      `xcreateTime` datetime NULL DEFAULT NULL,
                                      `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xupdateTime` datetime NULL DEFAULT NULL,
                                      `xdistributeFactor` int NULL DEFAULT NULL,
                                      `xcheckTime` datetime NULL DEFAULT NULL,
                                      `xlobValue` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                      PRIMARY KEY (`xid`) USING BTREE,
                                      UNIQUE INDEX `CAL_EVENT_COMMENT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_event_manageablepersonlist
-- ----------------------------
CREATE TABLE `cal_event_manageablepersonlist`  (
                                                   `CALENDAR_EVENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xmanageablePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `CAL_EVENT_manageablePersonList_element`(`xmanageablePersonList` ASC) USING BTREE,
                                                   INDEX `CAL_EVENT_manageablePersonList_join`(`CALENDAR_EVENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_event_participants
-- ----------------------------
CREATE TABLE `cal_event_participants`  (
                                           `CALENDAR_EVENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xparticipants` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xorderColumn` int NULL DEFAULT NULL,
                                           INDEX `CAL_EVENT_participants_element`(`xparticipants` ASC) USING BTREE,
                                           INDEX `CAL_EVENT_participants_join`(`CALENDAR_EVENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_event_repm
-- ----------------------------
CREATE TABLE `cal_event_repm`  (
                                   `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                   `xcreateTime` datetime NULL DEFAULT NULL,
                                   `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xupdateTime` datetime NULL DEFAULT NULL,
                                   `xdistributeFactor` int NULL DEFAULT NULL,
                                   `xalarm` bit(1) NULL DEFAULT NULL,
                                   `xalarmTime` datetime NULL DEFAULT NULL,
                                   `xcalendarId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xcolor` varchar(8) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xcomment` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xcommentId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xcreatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xdaysOfDuration` int NULL DEFAULT NULL,
                                   `xendTime` datetime NULL DEFAULT NULL,
                                   `xeventType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xisAllDayEvent` bit(1) NULL DEFAULT NULL,
                                   `xisPublic` bit(1) NULL DEFAULT NULL,
                                   `xlatitude` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xlocationName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xlongitude` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xrecurrenceExc` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xrecurrenceRule` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xrecurrenceStartTime` datetime NULL DEFAULT NULL,
                                   `xrepeatStatus` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xsource` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xstartTime` datetime NULL DEFAULT NULL,
                                   `xtargetType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xtitle` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xupdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xvalarmTime_config` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xvalarm_Summary` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xvalarm_description` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xvalarm_mailto` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   PRIMARY KEY (`xid`) USING BTREE,
                                   UNIQUE INDEX `CAL_EVENT_REPM_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                   INDEX `CAL_EVENT_REPM_calendarId`(`xcalendarId` ASC) USING BTREE,
                                   INDEX `CAL_EVENT_REPM_createPerson`(`xcreatePerson` ASC) USING BTREE,
                                   INDEX `CAL_EVENT_REPM_daysOfDuration`(`xdaysOfDuration` ASC) USING BTREE,
                                   INDEX `CAL_EVENT_REPM_endTime`(`xendTime` ASC) USING BTREE,
                                   INDEX `CAL_EVENT_REPM_eventType`(`xeventType` ASC) USING BTREE,
                                   INDEX `CAL_EVENT_REPM_repeatStatus`(`xrepeatStatus` ASC) USING BTREE,
                                   INDEX `CAL_EVENT_REPM_source`(`xsource` ASC) USING BTREE,
                                   INDEX `CAL_EVENT_REPM_startTime`(`xstartTime` ASC) USING BTREE,
                                   INDEX `CAL_EVENT_REPM_targetType`(`xtargetType` ASC) USING BTREE,
                                   INDEX `CAL_EVENT_REPM_updatePerson`(`xupdatePerson` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_event_repm_createdmonthlist
-- ----------------------------
CREATE TABLE `cal_event_repm_createdmonthlist`  (
                                                    `CALENDAR_EVENTREPEATMASTER_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xcreatedMonthList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `CAL_EVENT_REPM_createdMonthList_element`(`xcreatedMonthList` ASC) USING BTREE,
                                                    INDEX `CAL_EVENT_REPM_createdMonthList_join`(`CALENDAR_EVENTREPEATMASTER_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_event_repm_manageablepersonlist
-- ----------------------------
CREATE TABLE `cal_event_repm_manageablepersonlist`  (
                                                        `CALENDAR_EVENTREPEATMASTER_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xmanageablePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xorderColumn` int NULL DEFAULT NULL,
                                                        INDEX `CAL_EVENT_REPM_manageablePersonList_element`(`xmanageablePersonList` ASC) USING BTREE,
                                                        INDEX `CAL_EVENT_REPM_manageablePersonList_join`(`CALENDAR_EVENTREPEATMASTER_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_event_repm_participants
-- ----------------------------
CREATE TABLE `cal_event_repm_participants`  (
                                                `CALENDAR_EVENTREPEATMASTER_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xparticipants` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `CAL_EVENT_REPM_participants_element`(`xparticipants` ASC) USING BTREE,
                                                INDEX `CAL_EVENT_REPM_participants_join`(`CALENDAR_EVENTREPEATMASTER_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_event_repm_viewablegrouplist
-- ----------------------------
CREATE TABLE `cal_event_repm_viewablegrouplist`  (
                                                     `CALENDAR_EVENTREPEATMASTER_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xviewableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xorderColumn` int NULL DEFAULT NULL,
                                                     INDEX `CAL_EVENT_REPM_viewableGroupList_element`(`xviewableGroupList` ASC) USING BTREE,
                                                     INDEX `CAL_EVENT_REPM_viewableGroupList_join`(`CALENDAR_EVENTREPEATMASTER_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_event_repm_viewablepersonlist
-- ----------------------------
CREATE TABLE `cal_event_repm_viewablepersonlist`  (
                                                      `CALENDAR_EVENTREPEATMASTER_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xviewablePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xorderColumn` int NULL DEFAULT NULL,
                                                      INDEX `CAL_EVENT_REPM_viewablePersonList_element`(`xviewablePersonList` ASC) USING BTREE,
                                                      INDEX `CAL_EVENT_REPM_viewablePersonList_join`(`CALENDAR_EVENTREPEATMASTER_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_event_repm_viewableunitlist
-- ----------------------------
CREATE TABLE `cal_event_repm_viewableunitlist`  (
                                                    `CALENDAR_EVENTREPEATMASTER_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xviewableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `CAL_EVENT_REPM_viewableUnitList_element`(`xviewableUnitList` ASC) USING BTREE,
                                                    INDEX `CAL_EVENT_REPM_viewableUnitList_join`(`CALENDAR_EVENTREPEATMASTER_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_event_viewablegrouplist
-- ----------------------------
CREATE TABLE `cal_event_viewablegrouplist`  (
                                                `CALENDAR_EVENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xviewableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `CAL_EVENT_viewableGroupList_element`(`xviewableGroupList` ASC) USING BTREE,
                                                INDEX `CAL_EVENT_viewableGroupList_join`(`CALENDAR_EVENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_event_viewablepersonlist
-- ----------------------------
CREATE TABLE `cal_event_viewablepersonlist`  (
                                                 `CALENDAR_EVENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xviewablePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `CAL_EVENT_viewablePersonList_element`(`xviewablePersonList` ASC) USING BTREE,
                                                 INDEX `CAL_EVENT_viewablePersonList_join`(`CALENDAR_EVENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cal_event_viewableunitlist
-- ----------------------------
CREATE TABLE `cal_event_viewableunitlist`  (
                                               `CALENDAR_EVENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xviewableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `CAL_EVENT_viewableUnitList_element`(`xviewableUnitList` ASC) USING BTREE,
                                               INDEX `CAL_EVENT_viewableUnitList_join`(`CALENDAR_EVENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_appdictitem
-- ----------------------------
CREATE TABLE `cms_appdictitem`  (
                                    `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                    `xcreateTime` datetime NULL DEFAULT NULL,
                                    `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xupdateTime` datetime NULL DEFAULT NULL,
                                    `xdistributeFactor` int NULL DEFAULT NULL,
                                    `xappId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xbooleanValue` bit(1) NULL DEFAULT NULL,
                                    `xbundle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xdateTimeValue` datetime NULL DEFAULT NULL,
                                    `xdateValue` date NULL DEFAULT NULL,
                                    `xitemCategory` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xitemPrimitiveType` varchar(1) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xitemStringValueType` varchar(2) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xitemType` varchar(1) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xnumberValue` double NULL DEFAULT NULL,
                                    `xpath0` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xpath0Location` int NULL DEFAULT NULL,
                                    `xpath1` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xpath1Location` int NULL DEFAULT NULL,
                                    `xpath2` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xpath2Location` int NULL DEFAULT NULL,
                                    `xpath3` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xpath3Location` int NULL DEFAULT NULL,
                                    `xpath4` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xpath4Location` int NULL DEFAULT NULL,
                                    `xpath5` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xpath5Location` int NULL DEFAULT NULL,
                                    `xpath6` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xpath6Location` int NULL DEFAULT NULL,
                                    `xpath7` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xpath7Location` int NULL DEFAULT NULL,
                                    `xstringLongValue` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                    `xstringShortValue` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xtimeValue` time NULL DEFAULT NULL,
                                    PRIMARY KEY (`xid`) USING BTREE,
                                    UNIQUE INDEX `CMS_APPDICTITEM_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_appId`(`xappId` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_bundle`(`xbundle` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_dateTimeValue`(`xdateTimeValue` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_dateValue`(`xdateValue` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_itemCategory`(`xitemCategory` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_itemPrimitiveType`(`xitemPrimitiveType` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_itemStringValueType`(`xitemStringValueType` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_itemType`(`xitemType` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_numberValue`(`xnumberValue` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path0`(`xpath0` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path0Location`(`xpath0Location` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path1`(`xpath1` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path1Location`(`xpath1Location` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path2`(`xpath2` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path2Location`(`xpath2Location` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path3`(`xpath3` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path3Location`(`xpath3Location` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path4`(`xpath4` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path4Location`(`xpath4Location` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path5`(`xpath5` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path5Location`(`xpath5Location` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path6`(`xpath6` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path6Location`(`xpath6Location` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path7`(`xpath7` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_path7Location`(`xpath7Location` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_stringShortValue`(`xstringShortValue` ASC) USING BTREE,
                                    INDEX `CMS_APPDICTITEM_timeValue`(`xtimeValue` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_appinfo
-- ----------------------------
CREATE TABLE `cms_appinfo`  (
                                `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                `xcreateTime` datetime NULL DEFAULT NULL,
                                `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xupdateTime` datetime NULL DEFAULT NULL,
                                `xdistributeFactor` int NULL DEFAULT NULL,
                                `xallPeoplePublish` bit(1) NULL DEFAULT NULL,
                                `xallPeopleView` bit(1) NULL DEFAULT NULL,
                                `xshowAllDocuments` bit(1) NULL DEFAULT NULL,
                                `xanonymousAble` bit(1) NULL DEFAULT NULL,
                                `xappAlias` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xappIcon` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xappInfoSeq` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xappMemo` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xappName` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xappType` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xcreatorIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xcreatorTopUnitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xcreatorUnitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xdefaultEditForm` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xdefaultReadForm` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xdocumentType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xiconColor` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xsendNotify` bit(1) NULL DEFAULT NULL,
                                PRIMARY KEY (`xid`) USING BTREE,
                                UNIQUE INDEX `CMS_APPINFO_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                INDEX `CMS_APPINFO_appAlias`(`xappAlias` ASC) USING BTREE,
                                INDEX `CMS_APPINFO_appName`(`xappName` ASC) USING BTREE,
                                INDEX `CMS_APPINFO_documentType`(`xdocumentType` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_appinfo_categorylist
-- ----------------------------
CREATE TABLE `cms_appinfo_categorylist`  (
                                             `APPINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xcategoryList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `CMS_APPINFO_categoryList_element`(`xcategoryList` ASC) USING BTREE,
                                             INDEX `CMS_APPINFO_categoryList_join`(`APPINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_appinfo_config
-- ----------------------------
CREATE TABLE `cms_appinfo_config`  (
                                       `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                       `xcreateTime` datetime NULL DEFAULT NULL,
                                       `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xupdateTime` datetime NULL DEFAULT NULL,
                                       `xdistributeFactor` int NULL DEFAULT NULL,
                                       `xconfig` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                       PRIMARY KEY (`xid`) USING BTREE,
                                       UNIQUE INDEX `CMS_APPINFO_CONFIG_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_appinfo_manageablegrouplist
-- ----------------------------
CREATE TABLE `cms_appinfo_manageablegrouplist`  (
                                                    `APPINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xmanageableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `CMS_APPINFO_manageableGroupList_element`(`xmanageableGroupList` ASC) USING BTREE,
                                                    INDEX `CMS_APPINFO_manageableGroupList_join`(`APPINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_appinfo_manageablepersonlist
-- ----------------------------
CREATE TABLE `cms_appinfo_manageablepersonlist`  (
                                                     `APPINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xmanageablePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xorderColumn` int NULL DEFAULT NULL,
                                                     INDEX `CMS_APPINFO_manageablePersonList_element`(`xmanageablePersonList` ASC) USING BTREE,
                                                     INDEX `CMS_APPINFO_manageablePersonList_join`(`APPINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_appinfo_manageableunitlist
-- ----------------------------
CREATE TABLE `cms_appinfo_manageableunitlist`  (
                                                   `APPINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xmanageableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `CMS_APPINFO_manageableUnitList_element`(`xmanageableUnitList` ASC) USING BTREE,
                                                   INDEX `CMS_APPINFO_manageableUnitList_join`(`APPINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_appinfo_publishablegrouplist
-- ----------------------------
CREATE TABLE `cms_appinfo_publishablegrouplist`  (
                                                     `APPINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xpublishableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xorderColumn` int NULL DEFAULT NULL,
                                                     INDEX `CMS_APPINFO_publishableGroupList_element`(`xpublishableGroupList` ASC) USING BTREE,
                                                     INDEX `CMS_APPINFO_publishableGroupList_join`(`APPINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_appinfo_publishablepersonlist
-- ----------------------------
CREATE TABLE `cms_appinfo_publishablepersonlist`  (
                                                      `APPINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xpublishablePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xorderColumn` int NULL DEFAULT NULL,
                                                      INDEX `CMS_APPINFO_publishablePersonList_element`(`xpublishablePersonList` ASC) USING BTREE,
                                                      INDEX `CMS_APPINFO_publishablePersonList_join`(`APPINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_appinfo_publishableunitlist
-- ----------------------------
CREATE TABLE `cms_appinfo_publishableunitlist`  (
                                                    `APPINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xpublishableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `CMS_APPINFO_publishableUnitList_element`(`xpublishableUnitList` ASC) USING BTREE,
                                                    INDEX `CMS_APPINFO_publishableUnitList_join`(`APPINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_appinfo_viewablegrouplist
-- ----------------------------
CREATE TABLE `cms_appinfo_viewablegrouplist`  (
                                                  `APPINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xviewableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `CMS_APPINFO_viewableGroupList_element`(`xviewableGroupList` ASC) USING BTREE,
                                                  INDEX `CMS_APPINFO_viewableGroupList_join`(`APPINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_appinfo_viewablepersonlist
-- ----------------------------
CREATE TABLE `cms_appinfo_viewablepersonlist`  (
                                                   `APPINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xviewablePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `CMS_APPINFO_viewablePersonList_element`(`xviewablePersonList` ASC) USING BTREE,
                                                   INDEX `CMS_APPINFO_viewablePersonList_join`(`APPINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_appinfo_viewableunitlist
-- ----------------------------
CREATE TABLE `cms_appinfo_viewableunitlist`  (
                                                 `APPINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xviewableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `CMS_APPINFO_viewableUnitList_element`(`xviewableUnitList` ASC) USING BTREE,
                                                 INDEX `CMS_APPINFO_viewableUnitList_join`(`APPINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_appndict
-- ----------------------------
CREATE TABLE `cms_appndict`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xappId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcreatorUid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `CMS_APPNDICT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                 INDEX `CMS_APPNDICT_alias`(`xalias` ASC) USING BTREE,
                                 INDEX `CMS_APPNDICT_appId`(`xappId` ASC) USING BTREE,
                                 INDEX `CMS_APPNDICT_creatorUid`(`xcreatorUid` ASC) USING BTREE,
                                 INDEX `CMS_APPNDICT_description`(`xdescription` ASC) USING BTREE,
                                 INDEX `CMS_APPNDICT_name`(`xname` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_batch_operation
-- ----------------------------
CREATE TABLE `cms_batch_operation`  (
                                        `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                        `xcreateTime` datetime NULL DEFAULT NULL,
                                        `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xupdateTime` datetime NULL DEFAULT NULL,
                                        `xdistributeFactor` int NULL DEFAULT NULL,
                                        `xbundle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xerrorCount` int NULL DEFAULT NULL,
                                        `xisRunning` bit(1) NULL DEFAULT NULL,
                                        `xobjType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xoldInfo` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xoptType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        PRIMARY KEY (`xid`) USING BTREE,
                                        UNIQUE INDEX `CMS_BATCH_OPERATION_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_categoryext
-- ----------------------------
CREATE TABLE `cms_categoryext`  (
                                    `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                    `xcreateTime` datetime NULL DEFAULT NULL,
                                    `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xupdateTime` datetime NULL DEFAULT NULL,
                                    `xdistributeFactor` int NULL DEFAULT NULL,
                                    `xcontent` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                    PRIMARY KEY (`xid`) USING BTREE,
                                    UNIQUE INDEX `CMS_CATEGORYEXT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_categoryinfo
-- ----------------------------
CREATE TABLE `cms_categoryinfo`  (
                                     `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                     `xcreateTime` datetime NULL DEFAULT NULL,
                                     `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xupdateTime` datetime NULL DEFAULT NULL,
                                     `xdistributeFactor` int NULL DEFAULT NULL,
                                     `xallPeoplePublish` bit(1) NULL DEFAULT NULL,
                                     `xallPeopleView` bit(1) NULL DEFAULT NULL,
                                     `xanonymousAble` bit(1) NULL DEFAULT NULL,
                                     `xappId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xappName` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xblankToAllNotify` bit(1) NULL DEFAULT NULL,
                                     `xcategoryAlias` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xcategoryIcon` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                     `xcategoryMemo` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xcategoryName` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xcategorySeq` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xcreatorIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xcreatorTopUnitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xcreatorUnitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xdefaultViewId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xdefaultViewName` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xdocumentType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xformId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xformName` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `ximportViewAppId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `ximportViewId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `ximportViewName` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xparentId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xprojection` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                     `xreadFormId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xreadFormName` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xsendNotify` bit(1) NULL DEFAULT NULL,
                                     `xworkflowAppId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xworkflowAppName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xworkflowFlag` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xworkflowName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xworkflowType` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     PRIMARY KEY (`xid`) USING BTREE,
                                     UNIQUE INDEX `CMS_CATEGORYINFO_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                     INDEX `CMS_CATEGORYINFO_appId`(`xappId` ASC) USING BTREE,
                                     INDEX `CMS_CATEGORYINFO_categoryAlias`(`xcategoryAlias` ASC) USING BTREE,
                                     INDEX `CMS_CATEGORYINFO_categoryName`(`xcategoryName` ASC) USING BTREE,
                                     INDEX `CMS_CATEGORYINFO_categorySeq`(`xcategorySeq` ASC) USING BTREE,
                                     INDEX `CMS_CATEGORYINFO_creatorIdentity`(`xcreatorIdentity` ASC) USING BTREE,
                                     INDEX `CMS_CATEGORYINFO_creatorPerson`(`xcreatorPerson` ASC) USING BTREE,
                                     INDEX `CMS_CATEGORYINFO_creatorTopUnitName`(`xcreatorTopUnitName` ASC) USING BTREE,
                                     INDEX `CMS_CATEGORYINFO_creatorUnitName`(`xcreatorUnitName` ASC) USING BTREE,
                                     INDEX `CMS_CATEGORYINFO_documentType`(`xdocumentType` ASC) USING BTREE,
                                     INDEX `CMS_CATEGORYINFO_parentId`(`xparentId` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_categoryinfo_manageablegrouplist
-- ----------------------------
CREATE TABLE `cms_categoryinfo_manageablegrouplist`  (
                                                         `CATEGORYINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                         `xmanageableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                         `xorderColumn` int NULL DEFAULT NULL,
                                                         INDEX `CMS_CATEGORYINFO_manageableGroupList_element`(`xmanageableGroupList` ASC) USING BTREE,
                                                         INDEX `CMS_CATEGORYINFO_manageableGroupList_join`(`CATEGORYINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_categoryinfo_manageablepersonlist
-- ----------------------------
CREATE TABLE `cms_categoryinfo_manageablepersonlist`  (
                                                          `CATEGORYINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                          `xmanageablePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                          `xorderColumn` int NULL DEFAULT NULL,
                                                          INDEX `CMS_CATEGORYINFO_manageablePersonList_element`(`xmanageablePersonList` ASC) USING BTREE,
                                                          INDEX `CMS_CATEGORYINFO_manageablePersonList_join`(`CATEGORYINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_categoryinfo_manageableunitlist
-- ----------------------------
CREATE TABLE `cms_categoryinfo_manageableunitlist`  (
                                                        `CATEGORYINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xmanageableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xorderColumn` int NULL DEFAULT NULL,
                                                        INDEX `CMS_CATEGORYINFO_manageableUnitList_element`(`xmanageableUnitList` ASC) USING BTREE,
                                                        INDEX `CMS_CATEGORYINFO_manageableUnitList_join`(`CATEGORYINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_categoryinfo_publishablegrouplist
-- ----------------------------
CREATE TABLE `cms_categoryinfo_publishablegrouplist`  (
                                                          `CATEGORYINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                          `xpublishableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                          `xorderColumn` int NULL DEFAULT NULL,
                                                          INDEX `CMS_CATEGORYINFO_publishableGroupList_element`(`xpublishableGroupList` ASC) USING BTREE,
                                                          INDEX `CMS_CATEGORYINFO_publishableGroupList_join`(`CATEGORYINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_categoryinfo_publishablepersonlist
-- ----------------------------
CREATE TABLE `cms_categoryinfo_publishablepersonlist`  (
                                                           `CATEGORYINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                           `xpublishablePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                           `xorderColumn` int NULL DEFAULT NULL,
                                                           INDEX `CMS_CATEGORYINFO_publishablePersonList_element`(`xpublishablePersonList` ASC) USING BTREE,
                                                           INDEX `CMS_CATEGORYINFO_publishablePersonList_join`(`CATEGORYINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_categoryinfo_publishableunitlist
-- ----------------------------
CREATE TABLE `cms_categoryinfo_publishableunitlist`  (
                                                         `CATEGORYINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                         `xpublishableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                         `xorderColumn` int NULL DEFAULT NULL,
                                                         INDEX `CMS_CATEGORYINFO_publishableUnitList_element`(`xpublishableUnitList` ASC) USING BTREE,
                                                         INDEX `CMS_CATEGORYINFO_publishableUnitList_join`(`CATEGORYINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_categoryinfo_viewablegrouplist
-- ----------------------------
CREATE TABLE `cms_categoryinfo_viewablegrouplist`  (
                                                       `CATEGORYINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xviewableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xorderColumn` int NULL DEFAULT NULL,
                                                       INDEX `CMS_CATEGORYINFO_viewableGroupList_element`(`xviewableGroupList` ASC) USING BTREE,
                                                       INDEX `CMS_CATEGORYINFO_viewableGroupList_join`(`CATEGORYINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_categoryinfo_viewablepersonlist
-- ----------------------------
CREATE TABLE `cms_categoryinfo_viewablepersonlist`  (
                                                        `CATEGORYINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xviewablePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xorderColumn` int NULL DEFAULT NULL,
                                                        INDEX `CMS_CATEGORYINFO_viewablePersonList_element`(`xviewablePersonList` ASC) USING BTREE,
                                                        INDEX `CMS_CATEGORYINFO_viewablePersonList_join`(`CATEGORYINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_categoryinfo_viewableunitlist
-- ----------------------------
CREATE TABLE `cms_categoryinfo_viewableunitlist`  (
                                                      `CATEGORYINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xviewableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xorderColumn` int NULL DEFAULT NULL,
                                                      INDEX `CMS_CATEGORYINFO_viewableUnitList_element`(`xviewableUnitList` ASC) USING BTREE,
                                                      INDEX `CMS_CATEGORYINFO_viewableUnitList_join`(`CATEGORYINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_document
-- ----------------------------
CREATE TABLE `cms_document`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xappAlias` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xappId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xappName` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcategoryAlias` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcategoryId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcategoryName` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcommendCount` bigint NULL DEFAULT NULL,
                                 `xcommentCount` bigint NULL DEFAULT NULL,
                                 `xcreatorIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcreatorTopUnitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcreatorUnitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdateTimeValue01` datetime NULL DEFAULT NULL,
                                 `xdateTimeValue02` datetime NULL DEFAULT NULL,
                                 `xdateTimeValue03` datetime NULL DEFAULT NULL,
                                 `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdocStatus` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdocumentType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdoubleValue01` double NULL DEFAULT NULL,
                                 `xdoubleValue02` double NULL DEFAULT NULL,
                                 `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xformName` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xhasIndexPic` bit(1) NULL DEFAULT NULL,
                                 `ximportBatchName` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xindexPics` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xisAllRead` bit(1) NULL DEFAULT NULL,
                                 `xisTop` bit(1) NULL DEFAULT NULL,
                                 `xlongValue01` bigint NULL DEFAULT NULL,
                                 `xlongValue02` bigint NULL DEFAULT NULL,
                                 `xmodifyTime` datetime NULL DEFAULT NULL,
                                 `xobjectSecurityClearance` int NULL DEFAULT NULL,
                                 `xppFormId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xpublishTime` datetime NULL DEFAULT NULL,
                                 `xreadFormId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xreadFormName` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xreviewed` bit(1) NULL DEFAULT NULL,
                                 `xsequenceAppAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xsequenceCategoryAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xsequenceCreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xsequenceCreatorUnitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xsequenceTitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xstringValue01` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xstringValue02` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xstringValue03` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xstringValue04` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xstringValue05` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xstringValue06` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xstringValue07` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xstringValue08` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xstringValue09` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xstringValue10` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xsummary` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xviewCount` bigint NULL DEFAULT NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `CMS_DOCUMENT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_appId`(`xappId` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_categoryAlias`(`xcategoryAlias` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_categoryId`(`xcategoryId` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_dateTimeValue01`(`xdateTimeValue01` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_dateTimeValue02`(`xdateTimeValue02` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_dateTimeValue03`(`xdateTimeValue03` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_docStatus`(`xdocStatus` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_documentType`(`xdocumentType` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_doubleValue01`(`xdoubleValue01` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_doubleValue02`(`xdoubleValue02` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_importBatchName`(`ximportBatchName` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_longValue01`(`xlongValue01` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_longValue02`(`xlongValue02` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_modifyTime`(`xmodifyTime` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_objectSecurityClearance`(`xobjectSecurityClearance` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_publishTime`(`xpublishTime` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_sequenceAppAlias`(`xsequenceAppAlias` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_sequenceCategoryAlias`(`xsequenceCategoryAlias` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_sequenceCreatorPerson`(`xsequenceCreatorPerson` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_sequenceCreatorUnitName`(`xsequenceCreatorUnitName` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_sequenceTitle`(`xsequenceTitle` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_stringValue01`(`xstringValue01` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_stringValue02`(`xstringValue02` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_stringValue03`(`xstringValue03` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_stringValue04`(`xstringValue04` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_stringValue05`(`xstringValue05` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_stringValue06`(`xstringValue06` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_stringValue07`(`xstringValue07` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_stringValue08`(`xstringValue08` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_stringValue09`(`xstringValue09` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_stringValue10`(`xstringValue10` ASC) USING BTREE,
                                 INDEX `CMS_DOCUMENT_title`(`xtitle` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_document_authorgrouplist
-- ----------------------------
CREATE TABLE `cms_document_authorgrouplist`  (
                                                 `DOCUMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xauthorGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `CMS_DOCUMENT_authorGroupList_element`(`xauthorGroupList` ASC) USING BTREE,
                                                 INDEX `CMS_DOCUMENT_authorGroupList_join`(`DOCUMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_document_authorpersonlist
-- ----------------------------
CREATE TABLE `cms_document_authorpersonlist`  (
                                                  `DOCUMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xauthorPersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `CMS_DOCUMENT_authorPersonList_element`(`xauthorPersonList` ASC) USING BTREE,
                                                  INDEX `CMS_DOCUMENT_authorPersonList_join`(`DOCUMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_document_authorunitlist
-- ----------------------------
CREATE TABLE `cms_document_authorunitlist`  (
                                                `DOCUMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xauthorUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `CMS_DOCUMENT_authorUnitList_element`(`xauthorUnitList` ASC) USING BTREE,
                                                INDEX `CMS_DOCUMENT_authorUnitList_join`(`DOCUMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_document_commend
-- ----------------------------
CREATE TABLE `cms_document_commend`  (
                                         `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                         `xcreateTime` datetime NULL DEFAULT NULL,
                                         `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xupdateTime` datetime NULL DEFAULT NULL,
                                         `xdistributeFactor` int NULL DEFAULT NULL,
                                         `xcommendPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xcommentId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xcommentTitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xdocumentId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xtype` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT 'document',
                                         PRIMARY KEY (`xid`) USING BTREE,
                                         UNIQUE INDEX `CMS_DOCUMENT_COMMEND_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                         INDEX `CMS_DOCUMENT_COMMEND_commendPerson`(`xcommendPerson` ASC) USING BTREE,
                                         INDEX `CMS_DOCUMENT_COMMEND_commentId`(`xcommentId` ASC) USING BTREE,
                                         INDEX `CMS_DOCUMENT_COMMEND_creatorPerson`(`xcreatorPerson` ASC) USING BTREE,
                                         INDEX `CMS_DOCUMENT_COMMEND_documentId`(`xdocumentId` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_document_managerlist
-- ----------------------------
CREATE TABLE `cms_document_managerlist`  (
                                             `DOCUMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xmanagerList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `CMS_DOCUMENT_managerList_element`(`xmanagerList` ASC) USING BTREE,
                                             INDEX `CMS_DOCUMENT_managerList_join`(`DOCUMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_document_picturelist
-- ----------------------------
CREATE TABLE `cms_document_picturelist`  (
                                             `DOCUMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xpictureList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `CMS_DOCUMENT_pictureList_element`(`xpictureList` ASC) USING BTREE,
                                             INDEX `CMS_DOCUMENT_pictureList_join`(`DOCUMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_document_readgrouplist
-- ----------------------------
CREATE TABLE `cms_document_readgrouplist`  (
                                               `DOCUMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `CMS_DOCUMENT_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                               INDEX `CMS_DOCUMENT_readGroupList_join`(`DOCUMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_document_readpersonlist
-- ----------------------------
CREATE TABLE `cms_document_readpersonlist`  (
                                                `DOCUMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreadPersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `CMS_DOCUMENT_readPersonList_element`(`xreadPersonList` ASC) USING BTREE,
                                                INDEX `CMS_DOCUMENT_readPersonList_join`(`DOCUMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_document_readunitlist
-- ----------------------------
CREATE TABLE `cms_document_readunitlist`  (
                                              `DOCUMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `CMS_DOCUMENT_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                              INDEX `CMS_DOCUMENT_readUnitList_join`(`DOCUMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_document_viewrecord
-- ----------------------------
CREATE TABLE `cms_document_viewrecord`  (
                                            `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                            `xcreateTime` datetime NULL DEFAULT NULL,
                                            `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xupdateTime` datetime NULL DEFAULT NULL,
                                            `xdistributeFactor` int NULL DEFAULT NULL,
                                            `xappId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xappName` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xcategoryId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xcategoryName` varchar(96) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xdocumentId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xlastViewTime` datetime NULL DEFAULT NULL,
                                            `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xviewCount` int NULL DEFAULT NULL,
                                            `xviewerName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xviewerTopUnitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xviewerUnitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            PRIMARY KEY (`xid`) USING BTREE,
                                            UNIQUE INDEX `CMS_DOCUMENT_VIEWRECORD_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                            INDEX `CMS_DOCUMENT_VIEWRECORD_documentId`(`xdocumentId` ASC) USING BTREE,
                                            INDEX `CMS_DOCUMENT_VIEWRECORD_lastViewTime`(`xlastViewTime` ASC) USING BTREE,
                                            INDEX `CMS_DOCUMENT_VIEWRECORD_title`(`xtitle` ASC) USING BTREE,
                                            INDEX `CMS_DOCUMENT_VIEWRECORD_viewerName`(`xviewerName` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_file
-- ----------------------------
CREATE TABLE `cms_file`  (
                             `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                             `xcreateTime` datetime NULL DEFAULT NULL,
                             `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xupdateTime` datetime NULL DEFAULT NULL,
                             `xdistributeFactor` int NULL DEFAULT NULL,
                             `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xappId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xfileName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xlastUpdateTime` datetime NULL DEFAULT NULL,
                             `xlength` bigint NULL DEFAULT NULL,
                             `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             PRIMARY KEY (`xid`) USING BTREE,
                             UNIQUE INDEX `CMS_FILE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                             INDEX `CMS_FILE_appId`(`xappId` ASC) USING BTREE,
                             INDEX `CMS_FILE_length`(`xlength` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_fileinfo
-- ----------------------------
CREATE TABLE `cms_fileinfo`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xencryptKey` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xappId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcategoryId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcloudId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcreatorUid` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdeepPath` bit(1) NULL DEFAULT NULL,
                                 `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdocumentId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xextension` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xfileExtType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xfileHost` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xfileName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xfilePath` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xfileType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xlastUpdateTime` datetime NULL DEFAULT NULL,
                                 `xlength` bigint NULL DEFAULT NULL,
                                 `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xobjectSecurityClearance` int NULL DEFAULT NULL,
                                 `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xseqNumber` int NULL DEFAULT NULL,
                                 `xsite` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xstorage` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xtext` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xtype` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `CMS_FILEINFO_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                 INDEX `CMS_FILEINFO_documentId`(`xdocumentId` ASC) USING BTREE,
                                 INDEX `CMS_FILEINFO_lastUpdateTime`(`xlastUpdateTime` ASC) USING BTREE,
                                 INDEX `CMS_FILEINFO_length`(`xlength` ASC) USING BTREE,
                                 INDEX `CMS_FILEINFO_objectSecurityClearance`(`xobjectSecurityClearance` ASC) USING BTREE,
                                 INDEX `CMS_FILEINFO_storage`(`xstorage` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_fileinfo_controlleridentitylist
-- ----------------------------
CREATE TABLE `cms_fileinfo_controlleridentitylist`  (
                                                        `FILEINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xcontrollerIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xorderColumn` int NULL DEFAULT NULL,
                                                        INDEX `CMS_FILEINFO_controllerIdentityList_element`(`xcontrollerIdentityList` ASC) USING BTREE,
                                                        INDEX `CMS_FILEINFO_controllerIdentityList_join`(`FILEINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_fileinfo_controllerunitlist
-- ----------------------------
CREATE TABLE `cms_fileinfo_controllerunitlist`  (
                                                    `FILEINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xcontrollerUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `CMS_FILEINFO_controllerUnitList_element`(`xcontrollerUnitList` ASC) USING BTREE,
                                                    INDEX `CMS_FILEINFO_controllerUnitList_join`(`FILEINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_fileinfo_editidentitylist
-- ----------------------------
CREATE TABLE `cms_fileinfo_editidentitylist`  (
                                                  `FILEINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xeditIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `CMS_FILEINFO_editIdentityList_element`(`xeditIdentityList` ASC) USING BTREE,
                                                  INDEX `CMS_FILEINFO_editIdentityList_join`(`FILEINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_fileinfo_editunitlist
-- ----------------------------
CREATE TABLE `cms_fileinfo_editunitlist`  (
                                              `FILEINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xeditUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `CMS_FILEINFO_editUnitList_element`(`xeditUnitList` ASC) USING BTREE,
                                              INDEX `CMS_FILEINFO_editUnitList_join`(`FILEINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_fileinfo_readidentitylist
-- ----------------------------
CREATE TABLE `cms_fileinfo_readidentitylist`  (
                                                  `FILEINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `CMS_FILEINFO_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                                  INDEX `CMS_FILEINFO_readIdentityList_join`(`FILEINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_fileinfo_readunitlist
-- ----------------------------
CREATE TABLE `cms_fileinfo_readunitlist`  (
                                              `FILEINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `CMS_FILEINFO_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                              INDEX `CMS_FILEINFO_readUnitList_join`(`FILEINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_form
-- ----------------------------
CREATE TABLE `cms_form`  (
                             `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                             `xcreateTime` datetime NULL DEFAULT NULL,
                             `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xupdateTime` datetime NULL DEFAULT NULL,
                             `xdistributeFactor` int NULL DEFAULT NULL,
                             `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xappId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xeditor` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xhasMobile` bit(1) NULL DEFAULT NULL,
                             `xmobileData` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             PRIMARY KEY (`xid`) USING BTREE,
                             UNIQUE INDEX `CMS_FORM_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                             INDEX `CMS_FORM_alias`(`xalias` ASC) USING BTREE,
                             INDEX `CMS_FORM_appId`(`xappId` ASC) USING BTREE,
                             INDEX `CMS_FORM_name`(`xname` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_form_version
-- ----------------------------
CREATE TABLE `cms_form_version`  (
                                     `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                     `xcreateTime` datetime NULL DEFAULT NULL,
                                     `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xupdateTime` datetime NULL DEFAULT NULL,
                                     `xdistributeFactor` int NULL DEFAULT NULL,
                                     `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                     `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     PRIMARY KEY (`xid`) USING BTREE,
                                     UNIQUE INDEX `CMS_FORM_VERSION_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                     INDEX `CMS_FORM_VERSION_form`(`xform` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_log
-- ----------------------------
CREATE TABLE `cms_log`  (
                            `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                            `xcreateTime` datetime NULL DEFAULT NULL,
                            `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xupdateTime` datetime NULL DEFAULT NULL,
                            `xdistributeFactor` int NULL DEFAULT NULL,
                            `xappId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xcategoryId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xdocumentId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xfileId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xoperationLevel` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xoperationType` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xoperatorName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xoperatorUid` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            PRIMARY KEY (`xid`) USING BTREE,
                            UNIQUE INDEX `CMS_LOG_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                            INDEX `CMS_LOG_appId`(`xappId` ASC) USING BTREE,
                            INDEX `CMS_LOG_categoryId`(`xcategoryId` ASC) USING BTREE,
                            INDEX `CMS_LOG_operationLevel`(`xoperationLevel` ASC) USING BTREE,
                            INDEX `CMS_LOG_operationType`(`xoperationType` ASC) USING BTREE,
                            INDEX `CMS_LOG_operatorUid`(`xoperatorUid` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_m_documentevent
-- ----------------------------
CREATE TABLE `cms_m_documentevent`  (
                                        `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                        `xcreateTime` datetime NULL DEFAULT NULL,
                                        `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xupdateTime` datetime NULL DEFAULT NULL,
                                        `xdistributeFactor` int NULL DEFAULT NULL,
                                        `xappInfo` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xdocument` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xtype` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        PRIMARY KEY (`xid`) USING BTREE,
                                        UNIQUE INDEX `CMS_M_DOCUMENTEVENT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                        INDEX `CMS_M_DOCUMENTEVENT_appInfo`(`xappInfo` ASC) USING BTREE,
                                        INDEX `CMS_M_DOCUMENTEVENT_document`(`xdocument` ASC) USING BTREE,
                                        INDEX `CMS_M_DOCUMENTEVENT_type`(`xtype` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_review
-- ----------------------------
CREATE TABLE `cms_review`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xappAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xappId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xappName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xcategoryAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xcategoryId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xcategoryName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xcreatorIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xcreatorTopUnitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xcreatorUnitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdocCreateTime` datetime NULL DEFAULT NULL,
                               `xdocId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdocSequence` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdocStatus` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdocumentType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xpermissionObj` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xpermissionObjType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xpublishTime` datetime NULL DEFAULT NULL,
                               `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `CMS_REVIEW_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `CMS_REVIEW_docId`(`xdocId` ASC, `xpermissionObj` ASC) USING BTREE,
                               INDEX `CMS_REVIEW_permissionObj`(`xpermissionObj` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_script
-- ----------------------------
CREATE TABLE `cms_script`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xappId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xlastUpdateTime` datetime NULL DEFAULT NULL,
                               `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtext` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xvalidated` bit(1) NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `CMS_SCRIPT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `CMS_SCRIPT_appId`(`xappId` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_script_dependscriptlist
-- ----------------------------
CREATE TABLE `cms_script_dependscriptlist`  (
                                                `SCRIPT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xdependScriptList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `CMS_SCRIPT_dependScriptList_element`(`xdependScriptList` ASC) USING BTREE,
                                                INDEX `CMS_SCRIPT_dependScriptList_join`(`SCRIPT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_templateform
-- ----------------------------
CREATE TABLE `cms_templateform`  (
                                     `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                     `xcreateTime` datetime NULL DEFAULT NULL,
                                     `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xupdateTime` datetime NULL DEFAULT NULL,
                                     `xdistributeFactor` int NULL DEFAULT NULL,
                                     `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xcategory` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                     `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xicon` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                     `xmobileData` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                     `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xoutline` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                     PRIMARY KEY (`xid`) USING BTREE,
                                     UNIQUE INDEX `CMS_TEMPLATEFORM_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                     INDEX `CMS_TEMPLATEFORM_category`(`xcategory` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_view
-- ----------------------------
CREATE TABLE `cms_view`  (
                             `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                             `xcreateTime` datetime NULL DEFAULT NULL,
                             `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xupdateTime` datetime NULL DEFAULT NULL,
                             `xdistributeFactor` int NULL DEFAULT NULL,
                             `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xappId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xcontent` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xeditor` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xformId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xorderField` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xorderFieldType` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xorderType` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xpageSize` int NULL DEFAULT NULL,
                             PRIMARY KEY (`xid`) USING BTREE,
                             UNIQUE INDEX `CMS_VIEW_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                             INDEX `CMS_VIEW_appId`(`xappId` ASC) USING BTREE,
                             INDEX `CMS_VIEW_formId`(`xformId` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_view_fieldconfiglist
-- ----------------------------
CREATE TABLE `cms_view_fieldconfiglist`  (
                                             `VIEW_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xfieldConfigList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `CMS_VIEW_fieldConfigList_element`(`xfieldConfigList` ASC) USING BTREE,
                                             INDEX `CMS_VIEW_fieldConfigList_join`(`VIEW_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_viewcategory
-- ----------------------------
CREATE TABLE `cms_viewcategory`  (
                                     `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                     `xcreateTime` datetime NULL DEFAULT NULL,
                                     `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xupdateTime` datetime NULL DEFAULT NULL,
                                     `xdistributeFactor` int NULL DEFAULT NULL,
                                     `xcategoryId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xeditor` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xviewId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     PRIMARY KEY (`xid`) USING BTREE,
                                     UNIQUE INDEX `CMS_VIEWCATEGORY_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                     INDEX `CMS_VIEWCATEGORY_categoryId`(`xcategoryId` ASC) USING BTREE,
                                     INDEX `CMS_VIEWCATEGORY_viewId`(`xviewId` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cms_viewfield_config
-- ----------------------------
CREATE TABLE `cms_viewfield_config`  (
                                         `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                         `xcreateTime` datetime NULL DEFAULT NULL,
                                         `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xupdateTime` datetime NULL DEFAULT NULL,
                                         `xdistributeFactor` int NULL DEFAULT NULL,
                                         `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xeditor` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xfieldName` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xfieldTitle` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xshowSequence` int NULL DEFAULT NULL,
                                         `xviewId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         PRIMARY KEY (`xid`) USING BTREE,
                                         UNIQUE INDEX `CMS_VIEWFIELD_CONFIG_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                         INDEX `CMS_VIEWFIELD_CONFIG_viewId`(`xviewId` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cpt_component
-- ----------------------------
CREATE TABLE `cpt_component`  (
                                  `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                  `xcreateTime` datetime NULL DEFAULT NULL,
                                  `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xupdateTime` datetime NULL DEFAULT NULL,
                                  `xdistributeFactor` int NULL DEFAULT NULL,
                                  `xiconPath` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xorderNumber` int NULL DEFAULT NULL,
                                  `xpath` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xtype` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xvisible` bit(1) NULL DEFAULT NULL,
                                  PRIMARY KEY (`xid`) USING BTREE,
                                  UNIQUE INDEX `CPT_COMPONENT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                  INDEX `CPT_COMPONENT_name`(`xname` ASC) USING BTREE,
                                  INDEX `CPT_COMPONENT_orderNumber`(`xorderNumber` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cpt_component_allowlist
-- ----------------------------
CREATE TABLE `cpt_component_allowlist`  (
                                            `COMPONENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xallowList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xorderColumn` int NULL DEFAULT NULL,
                                            INDEX `CPT_COMPONENT_allowList_element`(`xallowList` ASC) USING BTREE,
                                            INDEX `CPT_COMPONENT_allowList_join`(`COMPONENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cpt_component_denylist
-- ----------------------------
CREATE TABLE `cpt_component_denylist`  (
                                           `COMPONENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xdenyList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xorderColumn` int NULL DEFAULT NULL,
                                           INDEX `CPT_COMPONENT_denyList_element`(`xdenyList` ASC) USING BTREE,
                                           INDEX `CPT_COMPONENT_denyList_join`(`COMPONENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cte_agent
-- ----------------------------
CREATE TABLE `cte_agent`  (
                              `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                              `xcreateTime` datetime NULL DEFAULT NULL,
                              `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xupdateTime` datetime NULL DEFAULT NULL,
                              `xdistributeFactor` int NULL DEFAULT NULL,
                              `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcron` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xenable` bit(1) NULL DEFAULT NULL,
                              `xlastEndTime` datetime NULL DEFAULT NULL,
                              `xlastStartTime` datetime NULL DEFAULT NULL,
                              `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xtext` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              `xvalidated` bit(1) NULL DEFAULT NULL,
                              PRIMARY KEY (`xid`) USING BTREE,
                              UNIQUE INDEX `CTE_AGENT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                              INDEX `CTE_AGENT_cron`(`xcron` ASC) USING BTREE,
                              INDEX `CTE_AGENT_lastEndTime`(`xlastEndTime` ASC) USING BTREE,
                              INDEX `CTE_AGENT_lastStartTime`(`xlastStartTime` ASC) USING BTREE,
                              INDEX `CTE_AGENT_name`(`xname` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cte_captcha
-- ----------------------------
CREATE TABLE `cte_captcha`  (
                                `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                `xcreateTime` datetime NULL DEFAULT NULL,
                                `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xupdateTime` datetime NULL DEFAULT NULL,
                                `xdistributeFactor` int NULL DEFAULT NULL,
                                `xanswer` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xmeta` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                PRIMARY KEY (`xid`) USING BTREE,
                                UNIQUE INDEX `CTE_CAPTCHA_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cte_code
-- ----------------------------
CREATE TABLE `cte_code`  (
                             `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                             `xcreateTime` datetime NULL DEFAULT NULL,
                             `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xupdateTime` datetime NULL DEFAULT NULL,
                             `xdistributeFactor` int NULL DEFAULT NULL,
                             `xanswer` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xmeta` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xmobile` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xverifyNumber` int NULL DEFAULT NULL,
                             PRIMARY KEY (`xid`) USING BTREE,
                             UNIQUE INDEX `CTE_CODE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cte_invoke
-- ----------------------------
CREATE TABLE `cte_invoke`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xenable` bit(1) NULL DEFAULT NULL,
                               `xenableToken` bit(1) NULL DEFAULT NULL,
                               `xlastEndTime` datetime NULL DEFAULT NULL,
                               `xlastStartTime` datetime NULL DEFAULT NULL,
                               `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xremoteAddrRegex` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtext` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xvalidated` bit(1) NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `CTE_INVOKE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `CTE_INVOKE_lastEndTime`(`xlastEndTime` ASC) USING BTREE,
                               INDEX `CTE_INVOKE_lastStartTime`(`xlastStartTime` ASC) USING BTREE,
                               INDEX `CTE_INVOKE_name`(`xname` ASC) USING BTREE,
                               INDEX `CTE_INVOKE_remoteAddrRegex`(`xremoteAddrRegex` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cte_prompterrorlog
-- ----------------------------
CREATE TABLE `cte_prompterrorlog`  (
                                       `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                       `xcreateTime` datetime NULL DEFAULT NULL,
                                       `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xupdateTime` datetime NULL DEFAULT NULL,
                                       `xdistributeFactor` int NULL DEFAULT NULL,
                                       `xcollected` bit(1) NULL DEFAULT NULL,
                                       `xexceptionClass` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xloggerName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xmessage` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                       `xoccurTime` datetime NULL DEFAULT NULL,
                                       `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xrequestBody` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                       `xrequestBodyLength` bigint NULL DEFAULT NULL,
                                       `xrequestHead` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                       `xrequestMethod` varchar(8) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xrequestRemoteAddr` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xrequestRemoteHost` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xrequestUrl` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                       `xstackTrace` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                       `xversion` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       PRIMARY KEY (`xid`) USING BTREE,
                                       UNIQUE INDEX `CTE_PROMPTERRORLOG_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                       INDEX `CTE_PROMPTERRORLOG_exceptionClass`(`xexceptionClass` ASC) USING BTREE,
                                       INDEX `CTE_PROMPTERRORLOG_loggerName`(`xloggerName` ASC) USING BTREE,
                                       INDEX `CTE_PROMPTERRORLOG_occurTime`(`xoccurTime` ASC) USING BTREE,
                                       INDEX `CTE_PROMPTERRORLOG_person`(`xperson` ASC) USING BTREE,
                                       INDEX `CTE_PROMPTERRORLOG_requestRemoteAddr`(`xrequestRemoteAddr` ASC) USING BTREE,
                                       INDEX `CTE_PROMPTERRORLOG_requestRemoteHost`(`xrequestRemoteHost` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cte_schedulelog
-- ----------------------------
CREATE TABLE `cte_schedulelog`  (
                                    `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                    `xcreateTime` datetime NULL DEFAULT NULL,
                                    `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xupdateTime` datetime NULL DEFAULT NULL,
                                    `xdistributeFactor` int NULL DEFAULT NULL,
                                    `xapplication` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xclassName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xelapsed` bigint NULL DEFAULT NULL,
                                    `xfireTime` datetime NULL DEFAULT NULL,
                                    `xnode` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xstackTrace` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                    `xsuccess` bit(1) NULL DEFAULT NULL,
                                    `xtype` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    PRIMARY KEY (`xid`) USING BTREE,
                                    UNIQUE INDEX `CTE_SCHEDULELOG_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                    INDEX `CTE_SCHEDULELOG_application`(`xapplication` ASC) USING BTREE,
                                    INDEX `CTE_SCHEDULELOG_className`(`xclassName` ASC) USING BTREE,
                                    INDEX `CTE_SCHEDULELOG_elapsed`(`xelapsed` ASC) USING BTREE,
                                    INDEX `CTE_SCHEDULELOG_fireTime`(`xfireTime` ASC) USING BTREE,
                                    INDEX `CTE_SCHEDULELOG_node`(`xnode` ASC) USING BTREE,
                                    INDEX `CTE_SCHEDULELOG_type`(`xtype` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cte_script
-- ----------------------------
CREATE TABLE `cte_script`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xlastUpdateTime` datetime NULL DEFAULT NULL,
                               `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtext` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xvalidated` bit(1) NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `CTE_SCRIPT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               UNIQUE INDEX `CTE_SCRIPT_name`(`xname` ASC) USING BTREE,
                               INDEX `CTE_SCRIPT_alias`(`xalias` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cte_script_dependscriptlist
-- ----------------------------
CREATE TABLE `cte_script_dependscriptlist`  (
                                                `SCRIPT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xdependScriptList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `CTE_SCRIPT_dependScriptList_element`(`xdependScriptList` ASC) USING BTREE,
                                                INDEX `CTE_SCRIPT_dependScriptList_join`(`SCRIPT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cte_structure
-- ----------------------------
CREATE TABLE `cte_structure`  (
                                  `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                  `xcreateTime` datetime NULL DEFAULT NULL,
                                  `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xupdateTime` datetime NULL DEFAULT NULL,
                                  `xdistributeFactor` int NULL DEFAULT NULL,
                                  `xencryptKey` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xdeepPath` bit(1) NULL DEFAULT NULL,
                                  `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xdescriptionLob` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xextension` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xlastUpdateTime` datetime NULL DEFAULT NULL,
                                  `xlength` bigint NULL DEFAULT NULL,
                                  `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xstorage` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  PRIMARY KEY (`xid`) USING BTREE,
                                  UNIQUE INDEX `CTE_STRUCTURE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                  INDEX `CTE_STRUCTURE_lastUpdateTime`(`xlastUpdateTime` ASC) USING BTREE,
                                  INDEX `CTE_STRUCTURE_length`(`xlength` ASC) USING BTREE,
                                  INDEX `CTE_STRUCTURE_name`(`xname` ASC) USING BTREE,
                                  INDEX `CTE_STRUCTURE_storage`(`xstorage` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cte_unexpectederrorlog
-- ----------------------------
CREATE TABLE `cte_unexpectederrorlog`  (
                                           `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                           `xcreateTime` datetime NULL DEFAULT NULL,
                                           `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xupdateTime` datetime NULL DEFAULT NULL,
                                           `xdistributeFactor` int NULL DEFAULT NULL,
                                           `xcollected` bit(1) NULL DEFAULT NULL,
                                           `xexceptionClass` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xloggerName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xmessage` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                           `xoccurTime` datetime NULL DEFAULT NULL,
                                           `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xrequestBody` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                           `xrequestBodyLength` bigint NULL DEFAULT NULL,
                                           `xrequestHead` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                           `xrequestMethod` varchar(8) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xrequestRemoteAddr` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xrequestRemoteHost` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xrequestUrl` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                           `xstackTrace` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                           `xversion` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           PRIMARY KEY (`xid`) USING BTREE,
                                           UNIQUE INDEX `CTE_UNEXPECTEDERRORLOG_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                           INDEX `CTE_UNEXPECTEDERRORLOG_exceptionClass`(`xexceptionClass` ASC) USING BTREE,
                                           INDEX `CTE_UNEXPECTEDERRORLOG_loggerName`(`xloggerName` ASC) USING BTREE,
                                           INDEX `CTE_UNEXPECTEDERRORLOG_occurTime`(`xoccurTime` ASC) USING BTREE,
                                           INDEX `CTE_UNEXPECTEDERRORLOG_person`(`xperson` ASC) USING BTREE,
                                           INDEX `CTE_UNEXPECTEDERRORLOG_requestRemoteAddr`(`xrequestRemoteAddr` ASC) USING BTREE,
                                           INDEX `CTE_UNEXPECTEDERRORLOG_requestRemoteHost`(`xrequestRemoteHost` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for cte_warnlog
-- ----------------------------
CREATE TABLE `cte_warnlog`  (
                                `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                `xcreateTime` datetime NULL DEFAULT NULL,
                                `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xupdateTime` datetime NULL DEFAULT NULL,
                                `xdistributeFactor` int NULL DEFAULT NULL,
                                `xcollected` bit(1) NULL DEFAULT NULL,
                                `xloggerName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xmessage` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xoccurTime` datetime NULL DEFAULT NULL,
                                `xversion` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                PRIMARY KEY (`xid`) USING BTREE,
                                UNIQUE INDEX `CTE_WARNLOG_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                INDEX `CTE_WARNLOG_loggerName`(`xloggerName` ASC) USING BTREE,
                                INDEX `CTE_WARNLOG_occurTime`(`xoccurTime` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for file_attachment
-- ----------------------------
CREATE TABLE `file_attachment`  (
                                    `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                    `xcreateTime` datetime NULL DEFAULT NULL,
                                    `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xupdateTime` datetime NULL DEFAULT NULL,
                                    `xdistributeFactor` int NULL DEFAULT NULL,
                                    `xencryptKey` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xdeepPath` bit(1) NULL DEFAULT NULL,
                                    `xextension` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xfolder` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xlastUpdateTime` datetime NULL DEFAULT NULL,
                                    `xlength` bigint NULL DEFAULT NULL,
                                    `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xstorage` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    PRIMARY KEY (`xid`) USING BTREE,
                                    UNIQUE INDEX `FILE_ATTACHMENT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                    INDEX `FILE_ATTACHMENT_folder`(`xfolder` ASC) USING BTREE,
                                    INDEX `FILE_ATTACHMENT_lastUpdatePerson`(`xlastUpdatePerson` ASC) USING BTREE,
                                    INDEX `FILE_ATTACHMENT_lastUpdateTime`(`xlastUpdateTime` ASC) USING BTREE,
                                    INDEX `FILE_ATTACHMENT_length`(`xlength` ASC) USING BTREE,
                                    INDEX `FILE_ATTACHMENT_name`(`xname` ASC) USING BTREE,
                                    INDEX `FILE_ATTACHMENT_person`(`xperson` ASC) USING BTREE,
                                    INDEX `FILE_ATTACHMENT_storage`(`xstorage` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for file_attachment2
-- ----------------------------
CREATE TABLE `file_attachment2`  (
                                     `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                     `xcreateTime` datetime NULL DEFAULT NULL,
                                     `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xupdateTime` datetime NULL DEFAULT NULL,
                                     `xdistributeFactor` int NULL DEFAULT NULL,
                                     `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xextension` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xfileVersion` int NULL DEFAULT NULL,
                                     `xfolder` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xlastUpdateTime` datetime NULL DEFAULT NULL,
                                     `xlength` bigint NULL DEFAULT NULL,
                                     `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xoriginFile` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xstatus` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xtype` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     PRIMARY KEY (`xid`) USING BTREE,
                                     UNIQUE INDEX `FILE_ATTACHMENT2_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                     INDEX `FILE_ATTACHMENT2_description`(`xdescription` ASC) USING BTREE,
                                     INDEX `FILE_ATTACHMENT2_folder`(`xfolder` ASC) USING BTREE,
                                     INDEX `FILE_ATTACHMENT2_lastUpdatePerson`(`xlastUpdatePerson` ASC) USING BTREE,
                                     INDEX `FILE_ATTACHMENT2_lastUpdateTime`(`xlastUpdateTime` ASC) USING BTREE,
                                     INDEX `FILE_ATTACHMENT2_length`(`xlength` ASC) USING BTREE,
                                     INDEX `FILE_ATTACHMENT2_name`(`xname` ASC) USING BTREE,
                                     INDEX `FILE_ATTACHMENT2_originFile`(`xoriginFile` ASC) USING BTREE,
                                     INDEX `FILE_ATTACHMENT2_person`(`xperson` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for file_attachment_editorlist
-- ----------------------------
CREATE TABLE `file_attachment_editorlist`  (
                                               `ATTACHMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xeditorList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `FILE_ATTACHMENT_editorList_element`(`xeditorList` ASC) USING BTREE,
                                               INDEX `FILE_ATTACHMENT_editorList_join`(`ATTACHMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for file_attachment_sharelist
-- ----------------------------
CREATE TABLE `file_attachment_sharelist`  (
                                              `ATTACHMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xshareList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `FILE_ATTACHMENT_shareList_element`(`xshareList` ASC) USING BTREE,
                                              INDEX `FILE_ATTACHMENT_shareList_join`(`ATTACHMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for file_config
-- ----------------------------
CREATE TABLE `file_config`  (
                                `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                `xcreateTime` datetime NULL DEFAULT NULL,
                                `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xupdateTime` datetime NULL DEFAULT NULL,
                                `xdistributeFactor` int NULL DEFAULT NULL,
                                `xcapacity` int NULL DEFAULT NULL,
                                `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xproperties` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xrecycleDays` int NULL DEFAULT NULL,
                                PRIMARY KEY (`xid`) USING BTREE,
                                UNIQUE INDEX `FILE_CONFIG_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                INDEX `FILE_CONFIG_person`(`xperson` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for file_folder
-- ----------------------------
CREATE TABLE `file_folder`  (
                                `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                `xcreateTime` datetime NULL DEFAULT NULL,
                                `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xupdateTime` datetime NULL DEFAULT NULL,
                                `xdistributeFactor` int NULL DEFAULT NULL,
                                `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xsuperior` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                PRIMARY KEY (`xid`) USING BTREE,
                                UNIQUE INDEX `FILE_FOLDER_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                INDEX `FILE_FOLDER_person`(`xperson` ASC) USING BTREE,
                                INDEX `FILE_FOLDER_superior`(`xsuperior` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for file_recycle
-- ----------------------------
CREATE TABLE `file_recycle`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xextension` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xfileId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xfileType` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xlength` bigint NULL DEFAULT NULL,
                                 `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xvalidTime` datetime NULL DEFAULT NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `FILE_RECYCLE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                 INDEX `FILE_RECYCLE_length`(`xlength` ASC) USING BTREE,
                                 INDEX `FILE_RECYCLE_name`(`xname` ASC) USING BTREE,
                                 INDEX `FILE_RECYCLE_person`(`xperson` ASC) USING BTREE,
                                 INDEX `FILE_RECYCLE_validTime`(`xvalidTime` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for gen_dict
-- ----------------------------
CREATE TABLE `gen_dict`  (
                             `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                             `xcreateTime` datetime NULL DEFAULT NULL,
                             `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xupdateTime` datetime NULL DEFAULT NULL,
                             `xdistributeFactor` int NULL DEFAULT NULL,
                             `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             PRIMARY KEY (`xid`) USING BTREE,
                             UNIQUE INDEX `GEN_DICT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                             UNIQUE INDEX `GEN_DICT_application`(`xapplication` ASC, `xname` ASC) USING BTREE,
                             INDEX `GEN_DICT_alias`(`xalias` ASC) USING BTREE,
                             INDEX `GEN_DICT_name`(`xname` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for gen_general_file
-- ----------------------------
CREATE TABLE `gen_general_file`  (
                                     `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                     `xcreateTime` datetime NULL DEFAULT NULL,
                                     `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xupdateTime` datetime NULL DEFAULT NULL,
                                     `xdistributeFactor` int NULL DEFAULT NULL,
                                     `xencryptKey` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xdeepPath` bit(1) NULL DEFAULT NULL,
                                     `xextension` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xlastUpdateTime` datetime NULL DEFAULT NULL,
                                     `xlength` bigint NULL DEFAULT NULL,
                                     `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xstorage` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     PRIMARY KEY (`xid`) USING BTREE,
                                     UNIQUE INDEX `GEN_GENERAL_FILE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                     INDEX `GEN_GENERAL_FILE_lastUpdateTime`(`xlastUpdateTime` ASC) USING BTREE,
                                     INDEX `GEN_GENERAL_FILE_name`(`xname` ASC) USING BTREE,
                                     INDEX `GEN_GENERAL_FILE_person`(`xperson` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for hot_picture_info
-- ----------------------------
CREATE TABLE `hot_picture_info`  (
                                     `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                     `xcreateTime` datetime NULL DEFAULT NULL,
                                     `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xupdateTime` datetime NULL DEFAULT NULL,
                                     `xdistributeFactor` int NULL DEFAULT NULL,
                                     `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xcreator` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xinfoId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xpicId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xsummary` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     PRIMARY KEY (`xid`) USING BTREE,
                                     UNIQUE INDEX `HOT_PICTURE_INFO_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                     INDEX `HOT_PICTURE_INFO_application`(`xapplication` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for jpush_device
-- ----------------------------
CREATE TABLE `jpush_device`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xdeviceId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdeviceType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xpushType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xunique` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `JPUSH_DEVICE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                 INDEX `JPUSH_DEVICE_deviceId`(`xdeviceId` ASC) USING BTREE,
                                 INDEX `JPUSH_DEVICE_deviceType`(`xdeviceType` ASC) USING BTREE,
                                 INDEX `JPUSH_DEVICE_person`(`xperson` ASC) USING BTREE,
                                 INDEX `JPUSH_DEVICE_pushType`(`xpushType` ASC) USING BTREE,
                                 INDEX `JPUSH_DEVICE_unique`(`xunique` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mind_base_info
-- ----------------------------
CREATE TABLE `mind_base_info`  (
                                   `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                   `xcreateTime` datetime NULL DEFAULT NULL,
                                   `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xupdateTime` datetime NULL DEFAULT NULL,
                                   `xdistributeFactor` int NULL DEFAULT NULL,
                                   `xcooperative` bit(1) NULL DEFAULT NULL,
                                   `xcooperative_sequence` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xcreator` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xcreatorUnit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xcreatorUnit_sequence` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xcreator_sequence` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xfileVersion` int NULL DEFAULT NULL,
                                   `xfolderId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xfolder_sequence` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xicon` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xshared` bit(1) NULL DEFAULT NULL,
                                   `xshared_sequence` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   PRIMARY KEY (`xid`) USING BTREE,
                                   UNIQUE INDEX `MIND_BASE_INFO_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                   INDEX `MIND_BASE_INFO_cooperative_sequence`(`xcooperative_sequence` ASC) USING BTREE,
                                   INDEX `MIND_BASE_INFO_creator`(`xcreator` ASC) USING BTREE,
                                   INDEX `MIND_BASE_INFO_creatorUnit_sequence`(`xcreatorUnit_sequence` ASC) USING BTREE,
                                   INDEX `MIND_BASE_INFO_creator_sequence`(`xcreator_sequence` ASC) USING BTREE,
                                   INDEX `MIND_BASE_INFO_folderId`(`xfolderId` ASC) USING BTREE,
                                   INDEX `MIND_BASE_INFO_folder_sequence`(`xfolder_sequence` ASC) USING BTREE,
                                   INDEX `MIND_BASE_INFO_name`(`xname` ASC) USING BTREE,
                                   INDEX `MIND_BASE_INFO_shared_sequence`(`xshared_sequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mind_base_info_editorlist
-- ----------------------------
CREATE TABLE `mind_base_info_editorlist`  (
                                              `MINDBASEINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xeditorList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `MIND_BASE_INFO_editorList_element`(`xeditorList` ASC) USING BTREE,
                                              INDEX `MIND_BASE_INFO_editorList_join`(`MINDBASEINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mind_base_info_sharegrouplist
-- ----------------------------
CREATE TABLE `mind_base_info_sharegrouplist`  (
                                                  `MINDBASEINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xshareGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `MIND_BASE_INFO_shareGroupList_element`(`xshareGroupList` ASC) USING BTREE,
                                                  INDEX `MIND_BASE_INFO_shareGroupList_join`(`MINDBASEINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mind_base_info_sharepersonlist
-- ----------------------------
CREATE TABLE `mind_base_info_sharepersonlist`  (
                                                   `MINDBASEINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xsharePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `MIND_BASE_INFO_sharePersonList_element`(`xsharePersonList` ASC) USING BTREE,
                                                   INDEX `MIND_BASE_INFO_sharePersonList_join`(`MINDBASEINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mind_base_info_shareunitlist
-- ----------------------------
CREATE TABLE `mind_base_info_shareunitlist`  (
                                                 `MINDBASEINFO_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xshareUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `MIND_BASE_INFO_shareUnitList_element`(`xshareUnitList` ASC) USING BTREE,
                                                 INDEX `MIND_BASE_INFO_shareUnitList_join`(`MINDBASEINFO_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mind_folder_info
-- ----------------------------
CREATE TABLE `mind_folder_info`  (
                                     `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                     `xcreateTime` datetime NULL DEFAULT NULL,
                                     `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xupdateTime` datetime NULL DEFAULT NULL,
                                     `xdistributeFactor` int NULL DEFAULT NULL,
                                     `xcreator` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xcreatorUnit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xorderNumber` int NULL DEFAULT NULL,
                                     `xparentId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     PRIMARY KEY (`xid`) USING BTREE,
                                     UNIQUE INDEX `MIND_FOLDER_INFO_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                     INDEX `MIND_FOLDER_INFO_creator`(`xcreator` ASC) USING BTREE,
                                     INDEX `MIND_FOLDER_INFO_name`(`xname` ASC) USING BTREE,
                                     INDEX `MIND_FOLDER_INFO_parentId`(`xparentId` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for msg_instant
-- ----------------------------
CREATE TABLE `msg_instant`  (
                                `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                `xcreateTime` datetime NULL DEFAULT NULL,
                                `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xupdateTime` datetime NULL DEFAULT NULL,
                                `xdistributeFactor` int NULL DEFAULT NULL,
                                `xbody` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xconsumed` bit(1) NULL DEFAULT NULL,
                                `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xtype` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                PRIMARY KEY (`xid`) USING BTREE,
                                UNIQUE INDEX `MSG_INSTANT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                INDEX `MSG_INSTANT_person`(`xperson` ASC) USING BTREE,
                                INDEX `MSG_INSTANT_title`(`xtitle` ASC) USING BTREE,
                                INDEX `MSG_INSTANT_type`(`xtype` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for msg_message
-- ----------------------------
CREATE TABLE `msg_message`  (
                                `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                `xcreateTime` datetime NULL DEFAULT NULL,
                                `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xupdateTime` datetime NULL DEFAULT NULL,
                                `xdistributeFactor` int NULL DEFAULT NULL,
                                `xbody` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xconsumed` bit(1) NULL DEFAULT NULL,
                                `xconsumer` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xinstant` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xtype` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                PRIMARY KEY (`xid`) USING BTREE,
                                UNIQUE INDEX `MSG_MESSAGE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                INDEX `MSG_MESSAGE_consumer`(`xconsumer` ASC) USING BTREE,
                                INDEX `MSG_MESSAGE_instant`(`xinstant` ASC) USING BTREE,
                                INDEX `MSG_MESSAGE_person`(`xperson` ASC) USING BTREE,
                                INDEX `MSG_MESSAGE_title`(`xtitle` ASC) USING BTREE,
                                INDEX `MSG_MESSAGE_type`(`xtype` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mt_attachment
-- ----------------------------
CREATE TABLE `mt_attachment`  (
                                  `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                  `xcreateTime` datetime NULL DEFAULT NULL,
                                  `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xupdateTime` datetime NULL DEFAULT NULL,
                                  `xdistributeFactor` int NULL DEFAULT NULL,
                                  `xencryptKey` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xdeepPath` bit(1) NULL DEFAULT NULL,
                                  `xextension` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xlastUpdateTime` datetime NULL DEFAULT NULL,
                                  `xlength` bigint NULL DEFAULT NULL,
                                  `xmeeting` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xstorage` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xsummary` bit(1) NULL DEFAULT NULL,
                                  PRIMARY KEY (`xid`) USING BTREE,
                                  UNIQUE INDEX `MT_ATTACHMENT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                  INDEX `MT_ATTACHMENT_lastUpdatePerson`(`xlastUpdatePerson` ASC) USING BTREE,
                                  INDEX `MT_ATTACHMENT_lastUpdateTime`(`xlastUpdateTime` ASC) USING BTREE,
                                  INDEX `MT_ATTACHMENT_length`(`xlength` ASC) USING BTREE,
                                  INDEX `MT_ATTACHMENT_meeting`(`xmeeting` ASC) USING BTREE,
                                  INDEX `MT_ATTACHMENT_name`(`xname` ASC) USING BTREE,
                                  INDEX `MT_ATTACHMENT_storage`(`xstorage` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mt_building
-- ----------------------------
CREATE TABLE `mt_building`  (
                                `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                `xcreateTime` datetime NULL DEFAULT NULL,
                                `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xupdateTime` datetime NULL DEFAULT NULL,
                                `xdistributeFactor` int NULL DEFAULT NULL,
                                `xaddress` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xpinyin` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xpinyinInitial` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                PRIMARY KEY (`xid`) USING BTREE,
                                UNIQUE INDEX `MT_BUILDING_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                INDEX `MT_BUILDING_address`(`xaddress` ASC) USING BTREE,
                                INDEX `MT_BUILDING_name`(`xname` ASC) USING BTREE,
                                INDEX `MT_BUILDING_pinyin`(`xpinyin` ASC) USING BTREE,
                                INDEX `MT_BUILDING_pinyinInitial`(`xpinyinInitial` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mt_config
-- ----------------------------
CREATE TABLE `mt_config`  (
                              `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                              `xcreateTime` datetime NULL DEFAULT NULL,
                              `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xupdateTime` datetime NULL DEFAULT NULL,
                              `xdistributeFactor` int NULL DEFAULT NULL,
                              `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xproperties` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              PRIMARY KEY (`xid`) USING BTREE,
                              UNIQUE INDEX `MT_CONFIG_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                              UNIQUE INDEX `MT_CONFIG_name`(`xname` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mt_meeting
-- ----------------------------
CREATE TABLE `mt_meeting`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xactualCompletedTime` time NULL DEFAULT NULL,
                               `xactualStartTime` time NULL DEFAULT NULL,
                               `xapplicant` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xauditor` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xcompletedTime` datetime NULL DEFAULT NULL,
                               `xconfirmStatus` varchar(8) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xhostPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xhostUnit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xmanualCompleted` bit(1) NULL DEFAULT NULL,
                               `xmemo` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xmode` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xpinyin` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xpinyinInitial` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xroom` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xroomId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xroomLink` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xstartTime` datetime NULL DEFAULT NULL,
                               `xsubject` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xsummary` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xtype` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `MT_MEETING_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `MT_MEETING_actualCompletedTime`(`xactualCompletedTime` ASC) USING BTREE,
                               INDEX `MT_MEETING_actualStartTime`(`xactualStartTime` ASC) USING BTREE,
                               INDEX `MT_MEETING_applicant`(`xapplicant` ASC) USING BTREE,
                               INDEX `MT_MEETING_auditor`(`xauditor` ASC) USING BTREE,
                               INDEX `MT_MEETING_completedTime`(`xcompletedTime` ASC) USING BTREE,
                               INDEX `MT_MEETING_description`(`xdescription` ASC) USING BTREE,
                               INDEX `MT_MEETING_hostPerson`(`xhostPerson` ASC) USING BTREE,
                               INDEX `MT_MEETING_hostUnit`(`xhostUnit` ASC) USING BTREE,
                               INDEX `MT_MEETING_pinyin`(`xpinyin` ASC) USING BTREE,
                               INDEX `MT_MEETING_pinyinInitial`(`xpinyinInitial` ASC) USING BTREE,
                               INDEX `MT_MEETING_room`(`xroom` ASC) USING BTREE,
                               INDEX `MT_MEETING_roomId`(`xroomId` ASC) USING BTREE,
                               INDEX `MT_MEETING_startTime`(`xstartTime` ASC) USING BTREE,
                               INDEX `MT_MEETING_subject`(`xsubject` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mt_meeting_acceptpersonlist
-- ----------------------------
CREATE TABLE `mt_meeting_acceptpersonlist`  (
                                                `MEETING_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xacceptPersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `MT_MEETING_acceptPersonList_element`(`xacceptPersonList` ASC) USING BTREE,
                                                INDEX `MT_MEETING_acceptPersonList_join`(`MEETING_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mt_meeting_checkinpersonlist
-- ----------------------------
CREATE TABLE `mt_meeting_checkinpersonlist`  (
                                                 `MEETING_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xcheckinPersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `MT_MEETING_checkinPersonList_element`(`xcheckinPersonList` ASC) USING BTREE,
                                                 INDEX `MT_MEETING_checkinPersonList_join`(`MEETING_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mt_meeting_invitedelpersonlist
-- ----------------------------
CREATE TABLE `mt_meeting_invitedelpersonlist`  (
                                                   `MEETING_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xinviteDelPersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `MT_MEETING_inviteDelPersonList_element`(`xinviteDelPersonList` ASC) USING BTREE,
                                                   INDEX `MT_MEETING_inviteDelPersonList_join`(`MEETING_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mt_meeting_invitememberlist
-- ----------------------------
CREATE TABLE `mt_meeting_invitememberlist`  (
                                                `MEETING_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xinviteMemberList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `MT_MEETING_inviteMemberList_element`(`xinviteMemberList` ASC) USING BTREE,
                                                INDEX `MT_MEETING_inviteMemberList_join`(`MEETING_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mt_meeting_invitepersonlist
-- ----------------------------
CREATE TABLE `mt_meeting_invitepersonlist`  (
                                                `MEETING_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xinvitePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `MT_MEETING_invitePersonList_element`(`xinvitePersonList` ASC) USING BTREE,
                                                INDEX `MT_MEETING_invitePersonList_join`(`MEETING_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mt_meeting_rejectpersonlist
-- ----------------------------
CREATE TABLE `mt_meeting_rejectpersonlist`  (
                                                `MEETING_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xrejectPersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `MT_MEETING_rejectPersonList_element`(`xrejectPersonList` ASC) USING BTREE,
                                                INDEX `MT_MEETING_rejectPersonList_join`(`MEETING_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for mt_room
-- ----------------------------
CREATE TABLE `mt_room`  (
                            `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                            `xcreateTime` datetime NULL DEFAULT NULL,
                            `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xupdateTime` datetime NULL DEFAULT NULL,
                            `xdistributeFactor` int NULL DEFAULT NULL,
                            `xauditor` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xavailable` bit(1) NULL DEFAULT NULL,
                            `xbuilding` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xcapacity` int NULL DEFAULT NULL,
                            `xdevice` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                            `xfloor` int NULL DEFAULT NULL,
                            `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xphoneNumber` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xphoto` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                            `xpinyin` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xpinyinInitial` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            `xroomNumber` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            PRIMARY KEY (`xid`) USING BTREE,
                            UNIQUE INDEX `MT_ROOM_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                            INDEX `MT_ROOM_auditor`(`xauditor` ASC) USING BTREE,
                            INDEX `MT_ROOM_building`(`xbuilding` ASC) USING BTREE,
                            INDEX `MT_ROOM_name`(`xname` ASC) USING BTREE,
                            INDEX `MT_ROOM_phoneNumber`(`xphoneNumber` ASC) USING BTREE,
                            INDEX `MT_ROOM_pinyin`(`xpinyin` ASC) USING BTREE,
                            INDEX `MT_ROOM_pinyinInitial`(`xpinyinInitial` ASC) USING BTREE,
                            INDEX `MT_ROOM_roomNumber`(`xroomNumber` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_a_empower
-- ----------------------------
CREATE TABLE `org_a_empower`  (
                                  `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                  `xcreateTime` datetime NULL DEFAULT NULL,
                                  `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xupdateTime` datetime NULL DEFAULT NULL,
                                  `xdistributeFactor` int NULL DEFAULT NULL,
                                  `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xapplicationAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xapplicationName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xcompletedTime` datetime NULL DEFAULT NULL,
                                  `xedition` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xenable` bit(1) NULL DEFAULT NULL,
                                  `xfilterListData` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xfromIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xfromPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xkeepEnable` bit(1) NULL DEFAULT NULL,
                                  `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xprocessAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xprocessName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xstartTime` datetime NULL DEFAULT NULL,
                                  `xtoIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xtoPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xtype` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  PRIMARY KEY (`xid`) USING BTREE,
                                  UNIQUE INDEX `ORG_A_EMPOWER_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                  INDEX `ORG_A_EMPOWER_application`(`xapplication` ASC) USING BTREE,
                                  INDEX `ORG_A_EMPOWER_completedTime`(`xcompletedTime` ASC) USING BTREE,
                                  INDEX `ORG_A_EMPOWER_edition`(`xedition` ASC) USING BTREE,
                                  INDEX `ORG_A_EMPOWER_fromIdentity`(`xfromIdentity` ASC) USING BTREE,
                                  INDEX `ORG_A_EMPOWER_process`(`xprocess` ASC) USING BTREE,
                                  INDEX `ORG_A_EMPOWER_startTime`(`xstartTime` ASC) USING BTREE,
                                  INDEX `ORG_A_EMPOWER_toIdentity`(`xtoIdentity` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_a_empowerlog
-- ----------------------------
CREATE TABLE `org_a_empowerlog`  (
                                     `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                     `xcreateTime` datetime NULL DEFAULT NULL,
                                     `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xupdateTime` datetime NULL DEFAULT NULL,
                                     `xdistributeFactor` int NULL DEFAULT NULL,
                                     `xactivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xactivityAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xactivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xapplicationAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xapplicationName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xempowerTime` datetime NULL DEFAULT NULL,
                                     `xfromIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xfromPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xprocessAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xprocessName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xtoIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xtoPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xwork` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     PRIMARY KEY (`xid`) USING BTREE,
                                     UNIQUE INDEX `ORG_A_EMPOWERLOG_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_activity`(`xactivity` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_activityAlias`(`xactivityAlias` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_activityName`(`xactivityName` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_application`(`xapplication` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_applicationAlias`(`xapplicationAlias` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_applicationName`(`xapplicationName` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_empowerTime`(`xempowerTime` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_fromIdentity`(`xfromIdentity` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_fromPerson`(`xfromPerson` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_job`(`xjob` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_process`(`xprocess` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_processAlias`(`xprocessAlias` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_processName`(`xprocessName` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_title`(`xtitle` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_toIdentity`(`xtoIdentity` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_toPerson`(`xtoPerson` ASC) USING BTREE,
                                     INDEX `ORG_A_EMPOWERLOG_work`(`xwork` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_bind
-- ----------------------------
CREATE TABLE `org_bind`  (
                             `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                             `xcreateTime` datetime NULL DEFAULT NULL,
                             `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xupdateTime` datetime NULL DEFAULT NULL,
                             `xdistributeFactor` int NULL DEFAULT NULL,
                             `xmeta` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             PRIMARY KEY (`xid`) USING BTREE,
                             UNIQUE INDEX `ORG_BIND_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                             INDEX `ORG_BIND_meta`(`xmeta` ASC) USING BTREE,
                             INDEX `ORG_BIND_name`(`xname` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_custom
-- ----------------------------
CREATE TABLE `org_custom`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `ORG_CUSTOM_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `ORG_CUSTOM_name`(`xname` ASC) USING BTREE,
                               INDEX `ORG_CUSTOM_person`(`xperson` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_defintion
-- ----------------------------
CREATE TABLE `org_defintion`  (
                                  `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                  `xcreateTime` datetime NULL DEFAULT NULL,
                                  `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xupdateTime` datetime NULL DEFAULT NULL,
                                  `xdistributeFactor` int NULL DEFAULT NULL,
                                  `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  PRIMARY KEY (`xid`) USING BTREE,
                                  UNIQUE INDEX `ORG_DEFINTION_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                  INDEX `ORG_DEFINTION_name`(`xname` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_group
-- ----------------------------
CREATE TABLE `org_group`  (
                              `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                              `xcreateTime` datetime NULL DEFAULT NULL,
                              `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xupdateTime` datetime NULL DEFAULT NULL,
                              `xdistributeFactor` int NULL DEFAULT NULL,
                              `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xdistinguishedName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xorderNumber` int NULL DEFAULT NULL,
                              `xpinyin` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xpinyinInitial` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xunique` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              PRIMARY KEY (`xid`) USING BTREE,
                              UNIQUE INDEX `ORG_GROUP_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                              INDEX `ORG_GROUP_description`(`xdescription` ASC) USING BTREE,
                              INDEX `ORG_GROUP_distinguishedName`(`xdistinguishedName` ASC) USING BTREE,
                              INDEX `ORG_GROUP_name`(`xname` ASC) USING BTREE,
                              INDEX `ORG_GROUP_orderNumber`(`xorderNumber` ASC) USING BTREE,
                              INDEX `ORG_GROUP_pinyin`(`xpinyin` ASC) USING BTREE,
                              INDEX `ORG_GROUP_pinyinInitial`(`xpinyinInitial` ASC) USING BTREE,
                              INDEX `ORG_GROUP_unique`(`xunique` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_group_grouplist
-- ----------------------------
CREATE TABLE `org_group_grouplist`  (
                                        `GROUP_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xgroupList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xorderColumn` int NULL DEFAULT NULL,
                                        INDEX `ORG_GROUP_groupList_element`(`xgroupList` ASC) USING BTREE,
                                        INDEX `ORG_GROUP_groupList_join`(`GROUP_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_group_identitylist
-- ----------------------------
CREATE TABLE `org_group_identitylist`  (
                                           `GROUP_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xidentityList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xorderColumn` int NULL DEFAULT NULL,
                                           INDEX `ORG_GROUP_identityList_element`(`xidentityList` ASC) USING BTREE,
                                           INDEX `ORG_GROUP_identityList_join`(`GROUP_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_group_personlist
-- ----------------------------
CREATE TABLE `org_group_personlist`  (
                                         `GROUP_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xpersonList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xorderColumn` int NULL DEFAULT NULL,
                                         INDEX `ORG_GROUP_personList_element`(`xpersonList` ASC) USING BTREE,
                                         INDEX `ORG_GROUP_personList_join`(`GROUP_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_group_unitlist
-- ----------------------------
CREATE TABLE `org_group_unitlist`  (
                                       `GROUP_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xunitList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xorderColumn` int NULL DEFAULT NULL,
                                       INDEX `ORG_GROUP_unitList_element`(`xunitList` ASC) USING BTREE,
                                       INDEX `ORG_GROUP_unitList_join`(`GROUP_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_identity
-- ----------------------------
CREATE TABLE `org_identity`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdistinguishedName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xmajor` bit(1) NULL DEFAULT NULL,
                                 `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xorderNumber` int NULL DEFAULT NULL,
                                 `xperson` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xpinyin` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xpinyinInitial` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xunique` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xunit` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xunitLevel` int NULL DEFAULT NULL,
                                 `xunitLevelName` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xunitName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `ORG_IDENTITY_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                 INDEX `ORG_IDENTITY_description`(`xdescription` ASC) USING BTREE,
                                 INDEX `ORG_IDENTITY_distinguishedName`(`xdistinguishedName` ASC) USING BTREE,
                                 INDEX `ORG_IDENTITY_name`(`xname` ASC) USING BTREE,
                                 INDEX `ORG_IDENTITY_orderNumber`(`xorderNumber` ASC) USING BTREE,
                                 INDEX `ORG_IDENTITY_person`(`xperson` ASC) USING BTREE,
                                 INDEX `ORG_IDENTITY_pinyin`(`xpinyin` ASC) USING BTREE,
                                 INDEX `ORG_IDENTITY_pinyinInitial`(`xpinyinInitial` ASC) USING BTREE,
                                 INDEX `ORG_IDENTITY_unique`(`xunique` ASC) USING BTREE,
                                 INDEX `ORG_IDENTITY_unit`(`xunit` ASC) USING BTREE,
                                 INDEX `ORG_IDENTITY_unitLevel`(`xunitLevel` ASC) USING BTREE,
                                 INDEX `ORG_IDENTITY_unitName`(`xunitName` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_oauthcode
-- ----------------------------
CREATE TABLE `org_oauthcode`  (
                                  `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                  `xcreateTime` datetime NULL DEFAULT NULL,
                                  `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xupdateTime` datetime NULL DEFAULT NULL,
                                  `xdistributeFactor` int NULL DEFAULT NULL,
                                  `xaccessToken` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xclientId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xcode` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xcodeUsed` bit(1) NULL DEFAULT NULL,
                                  `xperson` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xscope` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  PRIMARY KEY (`xid`) USING BTREE,
                                  UNIQUE INDEX `ORG_OAUTHCODE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                  INDEX `ORG_OAUTHCODE_clientId`(`xclientId` ASC) USING BTREE,
                                  INDEX `ORG_OAUTHCODE_code`(`xcode` ASC) USING BTREE,
                                  INDEX `ORG_OAUTHCODE_person`(`xperson` ASC) USING BTREE,
                                  INDEX `ORG_OAUTHCODE_scope`(`xscope` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_person
-- ----------------------------
CREATE TABLE `org_person`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xage` int NULL DEFAULT NULL,
                               `xandFxHash` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xandFxId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbirthday` date NULL DEFAULT NULL,
                               `xboardDate` date NULL DEFAULT NULL,
                               `xchangePasswordTime` date NULL DEFAULT NULL,
                               `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdingdingHash` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdingdingId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdistinguishedName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xemployee` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xfailureCount` int NULL DEFAULT NULL,
                               `xfailureTime` datetime NULL DEFAULT NULL,
                               `xgenderType` varchar(1) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xhiddenMobile` bit(1) NULL DEFAULT NULL,
                               `xicon` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xiconLdpi` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xiconMdpi` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xipAddress` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xlanguage` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xlastLoginAddress` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xlastLoginClient` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xlastLoginTime` datetime NULL DEFAULT NULL,
                               `xlockTime` datetime NULL DEFAULT NULL,
                               `xmail` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xmobile` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xmpwxopenId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xnickName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xofficePhone` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xopen1Id` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xopen2Id` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xopen3Id` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xopen4Id` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xopen5Id` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xorderNumber` int NULL DEFAULT NULL,
                               `xpassword` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xpasswordExpiredTime` date NULL DEFAULT NULL,
                               `xpinyin` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xpinyinInitial` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xqiyeweixinHash` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xqiyeweixinId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xqq` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xsignature` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xstatus` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xstatusDes` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xsubjectSecurityClearance` int NULL DEFAULT NULL,
                               `xsuperior` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xunique` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xweLinkHash` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xweLinkId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xweixin` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xzhengwuDingdingHash` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xzhengwuDingdingId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `ORG_PERSON_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `ORG_PERSON_andFxId`(`xandFxId` ASC) USING BTREE,
                               INDEX `ORG_PERSON_dingdingId`(`xdingdingId` ASC) USING BTREE,
                               INDEX `ORG_PERSON_distinguishedName`(`xdistinguishedName` ASC) USING BTREE,
                               INDEX `ORG_PERSON_employee`(`xemployee` ASC) USING BTREE,
                               INDEX `ORG_PERSON_lastLoginAddress`(`xlastLoginAddress` ASC) USING BTREE,
                               INDEX `ORG_PERSON_lastLoginTime`(`xlastLoginTime` ASC) USING BTREE,
                               INDEX `ORG_PERSON_mail`(`xmail` ASC) USING BTREE,
                               INDEX `ORG_PERSON_mobile`(`xmobile` ASC) USING BTREE,
                               INDEX `ORG_PERSON_mpwxopenId`(`xmpwxopenId` ASC) USING BTREE,
                               INDEX `ORG_PERSON_name`(`xname` ASC) USING BTREE,
                               INDEX `ORG_PERSON_open1Id`(`xopen1Id` ASC) USING BTREE,
                               INDEX `ORG_PERSON_open2Id`(`xopen2Id` ASC) USING BTREE,
                               INDEX `ORG_PERSON_open3Id`(`xopen3Id` ASC) USING BTREE,
                               INDEX `ORG_PERSON_open4Id`(`xopen4Id` ASC) USING BTREE,
                               INDEX `ORG_PERSON_open5Id`(`xopen5Id` ASC) USING BTREE,
                               INDEX `ORG_PERSON_orderNumber`(`xorderNumber` ASC) USING BTREE,
                               INDEX `ORG_PERSON_pinyin`(`xpinyin` ASC) USING BTREE,
                               INDEX `ORG_PERSON_pinyinInitial`(`xpinyinInitial` ASC) USING BTREE,
                               INDEX `ORG_PERSON_qiyeweixinId`(`xqiyeweixinId` ASC) USING BTREE,
                               INDEX `ORG_PERSON_qq`(`xqq` ASC) USING BTREE,
                               INDEX `ORG_PERSON_superior`(`xsuperior` ASC) USING BTREE,
                               INDEX `ORG_PERSON_unique`(`xunique` ASC) USING BTREE,
                               INDEX `ORG_PERSON_weixin`(`xweixin` ASC) USING BTREE,
                               INDEX `ORG_PERSON_weLinkId`(`xweLinkId` ASC) USING BTREE,
                               INDEX `ORG_PERSON_zhengwuDingdingId`(`xzhengwuDingdingId` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_person_controllerlist
-- ----------------------------
CREATE TABLE `org_person_controllerlist`  (
                                              `PERSON_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xcontrollerList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `ORG_PERSON_controllerList_element`(`xcontrollerList` ASC) USING BTREE,
                                              INDEX `ORG_PERSON_controllerList_join`(`PERSON_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_person_topunitlist
-- ----------------------------
CREATE TABLE `org_person_topunitlist`  (
                                           `PERSON_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xtopUnitList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xorderColumn` int NULL DEFAULT NULL,
                                           INDEX `ORG_PERSON_topUnitList_element`(`xtopUnitList` ASC) USING BTREE,
                                           INDEX `ORG_PERSON_topUnitList_join`(`PERSON_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_personattribute
-- ----------------------------
CREATE TABLE `org_personattribute`  (
                                        `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                        `xcreateTime` datetime NULL DEFAULT NULL,
                                        `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xupdateTime` datetime NULL DEFAULT NULL,
                                        `xdistributeFactor` int NULL DEFAULT NULL,
                                        `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xdistinguishedName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xorderNumber` int NULL DEFAULT NULL,
                                        `xperson` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xpinyin` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xpinyinInitial` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xunique` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        PRIMARY KEY (`xid`) USING BTREE,
                                        UNIQUE INDEX `ORG_PERSONATTRIBUTE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                        INDEX `ORG_PERSONATTRIBUTE_description`(`xdescription` ASC) USING BTREE,
                                        INDEX `ORG_PERSONATTRIBUTE_distinguishedName`(`xdistinguishedName` ASC) USING BTREE,
                                        INDEX `ORG_PERSONATTRIBUTE_name`(`xname` ASC) USING BTREE,
                                        INDEX `ORG_PERSONATTRIBUTE_orderNumber`(`xorderNumber` ASC) USING BTREE,
                                        INDEX `ORG_PERSONATTRIBUTE_person`(`xperson` ASC) USING BTREE,
                                        INDEX `ORG_PERSONATTRIBUTE_pinyin`(`xpinyin` ASC) USING BTREE,
                                        INDEX `ORG_PERSONATTRIBUTE_pinyinInitial`(`xpinyinInitial` ASC) USING BTREE,
                                        INDEX `ORG_PERSONATTRIBUTE_unique`(`xunique` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_personattribute_attributelist
-- ----------------------------
CREATE TABLE `org_personattribute_attributelist`  (
                                                      `PERSONATTRIBUTE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xattributeList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xorderColumn` int NULL DEFAULT NULL,
                                                      INDEX `ORG_PERSONATTRIBUTE_attributeList_element`(`xattributeList` ASC) USING BTREE,
                                                      INDEX `ORG_PERSONATTRIBUTE_attributeList_join`(`PERSONATTRIBUTE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_personextend
-- ----------------------------
CREATE TABLE `org_personextend`  (
                                     `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                     `xcreateTime` datetime NULL DEFAULT NULL,
                                     `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xupdateTime` datetime NULL DEFAULT NULL,
                                     `xdistributeFactor` int NULL DEFAULT NULL,
                                     `xperson` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                     `xtype` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     PRIMARY KEY (`xid`) USING BTREE,
                                     UNIQUE INDEX `ORG_PERSONEXTEND_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                     INDEX `ORG_PERSONEXTEND_person`(`xperson` ASC) USING BTREE,
                                     INDEX `ORG_PERSONEXTEND_type`(`xtype` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_role
-- ----------------------------
CREATE TABLE `org_role`  (
                             `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                             `xcreateTime` datetime NULL DEFAULT NULL,
                             `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xupdateTime` datetime NULL DEFAULT NULL,
                             `xdistributeFactor` int NULL DEFAULT NULL,
                             `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdistinguishedName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xorderNumber` int NULL DEFAULT NULL,
                             `xpinyin` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xpinyinInitial` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xunique` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             PRIMARY KEY (`xid`) USING BTREE,
                             UNIQUE INDEX `ORG_ROLE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                             INDEX `ORG_ROLE_description`(`xdescription` ASC) USING BTREE,
                             INDEX `ORG_ROLE_distinguishedName`(`xdistinguishedName` ASC) USING BTREE,
                             INDEX `ORG_ROLE_name`(`xname` ASC) USING BTREE,
                             INDEX `ORG_ROLE_orderNumber`(`xorderNumber` ASC) USING BTREE,
                             INDEX `ORG_ROLE_pinyin`(`xpinyin` ASC) USING BTREE,
                             INDEX `ORG_ROLE_pinyinInitial`(`xpinyinInitial` ASC) USING BTREE,
                             INDEX `ORG_ROLE_unique`(`xunique` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_role_grouplist
-- ----------------------------
CREATE TABLE `org_role_grouplist`  (
                                       `ROLE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xgroupList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xorderColumn` int NULL DEFAULT NULL,
                                       INDEX `ORG_ROLE_groupList_element`(`xgroupList` ASC) USING BTREE,
                                       INDEX `ORG_ROLE_groupList_join`(`ROLE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_role_personlist
-- ----------------------------
CREATE TABLE `org_role_personlist`  (
                                        `ROLE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xpersonList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xorderColumn` int NULL DEFAULT NULL,
                                        INDEX `ORG_ROLE_personList_element`(`xpersonList` ASC) USING BTREE,
                                        INDEX `ORG_ROLE_personList_join`(`ROLE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_unit
-- ----------------------------
CREATE TABLE `org_unit`  (
                             `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                             `xcreateTime` datetime NULL DEFAULT NULL,
                             `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xupdateTime` datetime NULL DEFAULT NULL,
                             `xdistributeFactor` int NULL DEFAULT NULL,
                             `xandFxHash` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xandFxId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdingdingHash` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdingdingId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdistinguishedName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xlevel` int NULL DEFAULT NULL,
                             `xlevelName` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xlevelOrderNumber` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xorderNumber` int NULL DEFAULT NULL,
                             `xpinyin` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xpinyinInitial` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xqiyeweixinHash` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xqiyeweixinId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xshortName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xsuperior` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xunique` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xweLinkHash` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xweLinkId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xzhengwuDingdingHash` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xzhengwuDingdingId` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             PRIMARY KEY (`xid`) USING BTREE,
                             UNIQUE INDEX `ORG_UNIT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                             INDEX `ORG_UNIT_andFxHash`(`xandFxHash` ASC) USING BTREE,
                             INDEX `ORG_UNIT_andFxId`(`xandFxId` ASC) USING BTREE,
                             INDEX `ORG_UNIT_description`(`xdescription` ASC) USING BTREE,
                             INDEX `ORG_UNIT_dingdingHash`(`xdingdingHash` ASC) USING BTREE,
                             INDEX `ORG_UNIT_dingdingId`(`xdingdingId` ASC) USING BTREE,
                             INDEX `ORG_UNIT_distinguishedName`(`xdistinguishedName` ASC) USING BTREE,
                             INDEX `ORG_UNIT_level`(`xlevel` ASC) USING BTREE,
                             INDEX `ORG_UNIT_name`(`xname` ASC) USING BTREE,
                             INDEX `ORG_UNIT_orderNumber`(`xorderNumber` ASC) USING BTREE,
                             INDEX `ORG_UNIT_pinyin`(`xpinyin` ASC) USING BTREE,
                             INDEX `ORG_UNIT_pinyinInitial`(`xpinyinInitial` ASC) USING BTREE,
                             INDEX `ORG_UNIT_qiyeweixinHash`(`xqiyeweixinHash` ASC) USING BTREE,
                             INDEX `ORG_UNIT_qiyeweixinId`(`xqiyeweixinId` ASC) USING BTREE,
                             INDEX `ORG_UNIT_superior`(`xsuperior` ASC) USING BTREE,
                             INDEX `ORG_UNIT_unique`(`xunique` ASC) USING BTREE,
                             INDEX `ORG_UNIT_weLinkHash`(`xweLinkHash` ASC) USING BTREE,
                             INDEX `ORG_UNIT_weLinkId`(`xweLinkId` ASC) USING BTREE,
                             INDEX `ORG_UNIT_zhengwuDingdingHash`(`xzhengwuDingdingHash` ASC) USING BTREE,
                             INDEX `ORG_UNIT_zhengwuDingdingId`(`xzhengwuDingdingId` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_unit_controllerlist
-- ----------------------------
CREATE TABLE `org_unit_controllerlist`  (
                                            `UNIT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xcontrollerList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xorderColumn` int NULL DEFAULT NULL,
                                            INDEX `ORG_UNITcontrollerList_element`(`xcontrollerList` ASC) USING BTREE,
                                            INDEX `ORG_UNIT_controllerList_join`(`UNIT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_unit_typelist
-- ----------------------------
CREATE TABLE `org_unit_typelist`  (
                                      `UNIT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xtypeList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xorderColumn` int NULL DEFAULT NULL,
                                      INDEX `ORG_UNIT_typeList_element`(`xtypeList` ASC) USING BTREE,
                                      INDEX `ORG_UNIT_typeList_join`(`UNIT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_unitattribute
-- ----------------------------
CREATE TABLE `org_unitattribute`  (
                                      `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                      `xcreateTime` datetime NULL DEFAULT NULL,
                                      `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xupdateTime` datetime NULL DEFAULT NULL,
                                      `xdistributeFactor` int NULL DEFAULT NULL,
                                      `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xdistinguishedName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xorderNumber` int NULL DEFAULT NULL,
                                      `xpinyin` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xpinyinInitial` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xunique` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xunit` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      PRIMARY KEY (`xid`) USING BTREE,
                                      UNIQUE INDEX `ORG_UNITATTRIBUTE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                      INDEX `ORG_UNITATTRIBUTE_description`(`xdescription` ASC) USING BTREE,
                                      INDEX `ORG_UNITATTRIBUTE_distinguishedName`(`xdistinguishedName` ASC) USING BTREE,
                                      INDEX `ORG_UNITATTRIBUTE_name`(`xname` ASC) USING BTREE,
                                      INDEX `ORG_UNITATTRIBUTE_orderNumber`(`xorderNumber` ASC) USING BTREE,
                                      INDEX `ORG_UNITATTRIBUTE_pinyin`(`xpinyin` ASC) USING BTREE,
                                      INDEX `ORG_UNITATTRIBUTE_pinyinInitial`(`xpinyinInitial` ASC) USING BTREE,
                                      INDEX `ORG_UNITATTRIBUTE_unique`(`xunique` ASC) USING BTREE,
                                      INDEX `ORG_UNITATTRIBUTE_unit`(`xunit` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_unitattribute_attributelist
-- ----------------------------
CREATE TABLE `org_unitattribute_attributelist`  (
                                                    `UNITATTRIBUTE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xattributeList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `ORG_UNITATTRIBUTE_attributeList_element`(`xattributeList` ASC) USING BTREE,
                                                    INDEX `ORG_UNITATTRIBUTE_attributeList_join`(`UNITATTRIBUTE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_unitduty
-- ----------------------------
CREATE TABLE `org_unitduty`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdistinguishedName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xorderNumber` int NULL DEFAULT NULL,
                                 `xpinyin` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xpinyinInitial` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xunique` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xunit` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `ORG_UNITDUTY_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                 INDEX `ORG_UNITDUTY_description`(`xdescription` ASC) USING BTREE,
                                 INDEX `ORG_UNITDUTY_distinguishedName`(`xdistinguishedName` ASC) USING BTREE,
                                 INDEX `ORG_UNITDUTY_name`(`xname` ASC) USING BTREE,
                                 INDEX `ORG_UNITDUTY_orderNumber`(`xorderNumber` ASC) USING BTREE,
                                 INDEX `ORG_UNITDUTY_pinyin`(`xpinyin` ASC) USING BTREE,
                                 INDEX `ORG_UNITDUTY_pinyinInitial`(`xpinyinInitial` ASC) USING BTREE,
                                 INDEX `ORG_UNITDUTY_unique`(`xunique` ASC) USING BTREE,
                                 INDEX `ORG_UNITDUTY_unit`(`xunit` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for org_unitduty_identitylist
-- ----------------------------
CREATE TABLE `org_unitduty_identitylist`  (
                                              `UNITDUTY_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xidentityList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `ORG_UNITDUTY_identityList_element`(`xidentityList` ASC) USING BTREE,
                                              INDEX `ORG_UNITDUTY_identityList_join`(`UNITDUTY_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_attachment
-- ----------------------------
CREATE TABLE `pp_c_attachment`  (
                                    `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                    `xcreateTime` datetime NULL DEFAULT NULL,
                                    `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xupdateTime` datetime NULL DEFAULT NULL,
                                    `xdistributeFactor` int NULL DEFAULT NULL,
                                    `xencryptKey` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xactivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xactivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xactivityToken` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xactivityType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xcompleted` bit(1) NULL DEFAULT NULL,
                                    `xdeepPath` bit(1) NULL DEFAULT NULL,
                                    `xextension` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xfromId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xfromJob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xfromPath` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xlastUpdateTime` datetime NULL DEFAULT NULL,
                                    `xlength` bigint NULL DEFAULT NULL,
                                    `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xobjectSecurityClearance` int NULL DEFAULT NULL,
                                    `xorderNumber` int NULL DEFAULT NULL,
                                    `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                    `xsite` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xstorage` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xstringValue01` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xstringValue02` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xstringValue03` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xtext` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                    `xtype` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xwork` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xworkCompleted` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                    `xworkCreateTime` datetime NULL DEFAULT NULL,
                                    PRIMARY KEY (`xid`) USING BTREE,
                                    UNIQUE INDEX `PP_C_ATTACHMENT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_activity`(`xactivity` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_activityName`(`xactivityName` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_activityToken`(`xactivityToken` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_activityType`(`xactivityType` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_application`(`xapplication` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_fromId`(`xfromId` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_job`(`xjob` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_lastUpdatePerson`(`xlastUpdatePerson` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_lastUpdateTime`(`xlastUpdateTime` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_length`(`xlength` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_name`(`xname` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_objectSecurityClearance`(`xobjectSecurityClearance` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_orderNumber`(`xorderNumber` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_person`(`xperson` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_process`(`xprocess` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_storage`(`xstorage` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_stringValue01`(`xstringValue01` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_stringValue02`(`xstringValue02` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_stringValue03`(`xstringValue03` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_work`(`xwork` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_workCompleted`(`xworkCompleted` ASC) USING BTREE,
                                    INDEX `PP_C_ATTACHMENT_workCreateTime`(`xworkCreateTime` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_attachment_controlleridentitylist
-- ----------------------------
CREATE TABLE `pp_c_attachment_controlleridentitylist`  (
                                                           `ATTACHMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                           `xcontrollerIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                           `xorderColumn` int NULL DEFAULT NULL,
                                                           INDEX `PP_C_ATTACHMENT_controllerIdentityList_element`(`xcontrollerIdentityList` ASC) USING BTREE,
                                                           INDEX `PP_C_ATTACHMENT_controllerIdentityList_join`(`ATTACHMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_attachment_controllerunitlist
-- ----------------------------
CREATE TABLE `pp_c_attachment_controllerunitlist`  (
                                                       `ATTACHMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xcontrollerUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xorderColumn` int NULL DEFAULT NULL,
                                                       INDEX `PP_C_ATTACHMENT_controllerUnitList_element`(`xcontrollerUnitList` ASC) USING BTREE,
                                                       INDEX `PP_C_ATTACHMENT_controllerUnitList_join`(`ATTACHMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_attachment_divisionlist
-- ----------------------------
CREATE TABLE `pp_c_attachment_divisionlist`  (
                                                 `ATTACHMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xdivisionList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_C_ATTACHMENT_divisionList_element`(`xdivisionList` ASC) USING BTREE,
                                                 INDEX `PP_C_ATTACHMENT_divisionList_join`(`ATTACHMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_attachment_editidentitylist
-- ----------------------------
CREATE TABLE `pp_c_attachment_editidentitylist`  (
                                                     `ATTACHMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xeditIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xorderColumn` int NULL DEFAULT NULL,
                                                     INDEX `PP_C_ATTACHMENT_editIdentityList_element`(`xeditIdentityList` ASC) USING BTREE,
                                                     INDEX `PP_C_ATTACHMENT_editIdentityList_join`(`ATTACHMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_attachment_editunitlist
-- ----------------------------
CREATE TABLE `pp_c_attachment_editunitlist`  (
                                                 `ATTACHMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xeditUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_C_ATTACHMENT_editUnitList_element`(`xeditUnitList` ASC) USING BTREE,
                                                 INDEX `PP_C_ATTACHMENT_editUnitList_join`(`ATTACHMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_attachment_readidentitylist
-- ----------------------------
CREATE TABLE `pp_c_attachment_readidentitylist`  (
                                                     `ATTACHMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xorderColumn` int NULL DEFAULT NULL,
                                                     INDEX `PP_C_ATTACHMENT_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                                     INDEX `PP_C_ATTACHMENT_readIdentityList_join`(`ATTACHMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_attachment_readunitlist
-- ----------------------------
CREATE TABLE `pp_c_attachment_readunitlist`  (
                                                 `ATTACHMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_C_ATTACHMENT_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                                 INDEX `PP_C_ATTACHMENT_readUnitList_join`(`ATTACHMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_documentversion
-- ----------------------------
CREATE TABLE `pp_c_documentversion`  (
                                         `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                         `xcreateTime` datetime NULL DEFAULT NULL,
                                         `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xupdateTime` datetime NULL DEFAULT NULL,
                                         `xdistributeFactor` int NULL DEFAULT NULL,
                                         `xactivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xactivityAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xactivityDescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xactivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xactivityToken` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xactivityType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xcategory` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xcompleted` bit(1) NULL DEFAULT NULL,
                                         `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                         `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         PRIMARY KEY (`xid`) USING BTREE,
                                         UNIQUE INDEX `PP_C_DOCUMENTVERSION_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                         INDEX `PP_C_DOCUMENTVERSION_activity`(`xactivity` ASC) USING BTREE,
                                         INDEX `PP_C_DOCUMENTVERSION_activityAlias`(`xactivityAlias` ASC) USING BTREE,
                                         INDEX `PP_C_DOCUMENTVERSION_activityDescription`(`xactivityDescription` ASC) USING BTREE,
                                         INDEX `PP_C_DOCUMENTVERSION_activityName`(`xactivityName` ASC) USING BTREE,
                                         INDEX `PP_C_DOCUMENTVERSION_activityToken`(`xactivityToken` ASC) USING BTREE,
                                         INDEX `PP_C_DOCUMENTVERSION_activityType`(`xactivityType` ASC) USING BTREE,
                                         INDEX `PP_C_DOCUMENTVERSION_application`(`xapplication` ASC) USING BTREE,
                                         INDEX `PP_C_DOCUMENTVERSION_category`(`xcategory` ASC) USING BTREE,
                                         INDEX `PP_C_DOCUMENTVERSION_job`(`xjob` ASC) USING BTREE,
                                         INDEX `PP_C_DOCUMENTVERSION_person`(`xperson` ASC) USING BTREE,
                                         INDEX `PP_C_DOCUMENTVERSION_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_draft
-- ----------------------------
CREATE TABLE `pp_c_draft`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xapplicationAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xapplicationName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xidentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xprocessAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xprocessName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xunit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `PP_C_DRAFT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `PP_C_DRAFT_application`(`xapplication` ASC) USING BTREE,
                               INDEX `PP_C_DRAFT_applicationName`(`xapplicationName` ASC) USING BTREE,
                               INDEX `PP_C_DRAFT_identity`(`xidentity` ASC) USING BTREE,
                               INDEX `PP_C_DRAFT_person`(`xperson` ASC) USING BTREE,
                               INDEX `PP_C_DRAFT_process`(`xprocess` ASC) USING BTREE,
                               INDEX `PP_C_DRAFT_processName`(`xprocessName` ASC) USING BTREE,
                               INDEX `PP_C_DRAFT_title`(`xtitle` ASC) USING BTREE,
                               INDEX `PP_C_DRAFT_unit`(`xunit` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_handover
-- ----------------------------
CREATE TABLE `pp_c_handover`  (
                                  `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                  `xcreateTime` datetime NULL DEFAULT NULL,
                                  `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xupdateTime` datetime NULL DEFAULT NULL,
                                  `xdistributeFactor` int NULL DEFAULT NULL,
                                  `xcreator` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xscheme` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xstatus` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xtargetIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xtargetPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xtype` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  PRIMARY KEY (`xid`) USING BTREE,
                                  UNIQUE INDEX `PP_C_HANDOVER_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                  INDEX `PP_C_HANDOVER_person`(`xperson` ASC) USING BTREE,
                                  INDEX `PP_C_HANDOVER_targetIdentity`(`xtargetIdentity` ASC) USING BTREE,
                                  INDEX `PP_C_HANDOVER_targetPerson`(`xtargetPerson` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_handover_handoverjoblist
-- ----------------------------
CREATE TABLE `pp_c_handover_handoverjoblist`  (
                                                  `HANDOVER_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xhandoverJobList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_C_HANDOVER_handoverJobList_element`(`xhandoverJobList` ASC) USING BTREE,
                                                  INDEX `PP_C_HANDOVER_handoverJobList_join`(`HANDOVER_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_keylock
-- ----------------------------
CREATE TABLE `pp_c_keylock`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xkey` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `PP_C_KEYLOCK_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                 INDEX `PP_C_KEYLOCK_key`(`xkey` ASC) USING BTREE,
                                 INDEX `PP_C_KEYLOCK_person`(`xperson` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_read
-- ----------------------------
CREATE TABLE `pp_c_read`  (
                              `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                              `xcreateTime` datetime NULL DEFAULT NULL,
                              `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xupdateTime` datetime NULL DEFAULT NULL,
                              `xdistributeFactor` int NULL DEFAULT NULL,
                              `xactivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityDescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityToken` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xapplicationAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xapplicationName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xbooleanValue01` bit(1) NULL DEFAULT NULL,
                              `xbooleanValue02` bit(1) NULL DEFAULT NULL,
                              `xcompleted` bit(1) NULL DEFAULT NULL,
                              `xcreatorIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcreatorUnit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcurrentActivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xdateTimeValue01` datetime NULL DEFAULT NULL,
                              `xdateTimeValue02` datetime NULL DEFAULT NULL,
                              `xdateTimeValue03` datetime NULL DEFAULT NULL,
                              `xdateTimeValue04` datetime NULL DEFAULT NULL,
                              `xdateTimeValue05` datetime NULL DEFAULT NULL,
                              `xdateValue01` date NULL DEFAULT NULL,
                              `xdateValue02` date NULL DEFAULT NULL,
                              `xdoubleValue01` double NULL DEFAULT NULL,
                              `xdoubleValue02` double NULL DEFAULT NULL,
                              `xdoubleValue03` double NULL DEFAULT NULL,
                              `xdoubleValue04` double NULL DEFAULT NULL,
                              `xdoubleValue05` double NULL DEFAULT NULL,
                              `xidentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xlongValue01` bigint NULL DEFAULT NULL,
                              `xlongValue02` bigint NULL DEFAULT NULL,
                              `xlongValue03` bigint NULL DEFAULT NULL,
                              `xlongValue04` bigint NULL DEFAULT NULL,
                              `xlongValue05` bigint NULL DEFAULT NULL,
                              `xopinion` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xopinionLob` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xprocessAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xprocessName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              `xserial` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstartTime` datetime NULL DEFAULT NULL,
                              `xstartTimeMonth` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue01` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue02` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue03` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue04` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue05` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue06` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue07` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue08` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue09` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue10` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xtimeValue01` time NULL DEFAULT NULL,
                              `xtimeValue02` time NULL DEFAULT NULL,
                              `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xunit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xviewTime` datetime NULL DEFAULT NULL,
                              `xwork` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xworkCompleted` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              PRIMARY KEY (`xid`) USING BTREE,
                              UNIQUE INDEX `PP_C_READ_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                              INDEX `PP_C_READ_activity`(`xactivity` ASC) USING BTREE,
                              INDEX `PP_C_READ_activityAlias`(`xactivityAlias` ASC) USING BTREE,
                              INDEX `PP_C_READ_activityDescription`(`xactivityDescription` ASC) USING BTREE,
                              INDEX `PP_C_READ_activityName`(`xactivityName` ASC) USING BTREE,
                              INDEX `PP_C_READ_activityToken`(`xactivityToken` ASC) USING BTREE,
                              INDEX `PP_C_READ_activityType`(`xactivityType` ASC) USING BTREE,
                              INDEX `PP_C_READ_application`(`xapplication` ASC) USING BTREE,
                              INDEX `PP_C_READ_applicationName`(`xapplicationName` ASC) USING BTREE,
                              INDEX `PP_C_READ_creatorIdentity`(`xcreatorIdentity` ASC) USING BTREE,
                              INDEX `PP_C_READ_creatorPerson`(`xcreatorPerson` ASC) USING BTREE,
                              INDEX `PP_C_READ_creatorUnit`(`xcreatorUnit` ASC) USING BTREE,
                              INDEX `PP_C_READ_currentActivityName`(`xcurrentActivityName` ASC) USING BTREE,
                              INDEX `PP_C_READ_dateTimeValue01`(`xdateTimeValue01` ASC) USING BTREE,
                              INDEX `PP_C_READ_dateTimeValue02`(`xdateTimeValue02` ASC) USING BTREE,
                              INDEX `PP_C_READ_dateTimeValue03`(`xdateTimeValue03` ASC) USING BTREE,
                              INDEX `PP_C_READ_dateTimeValue04`(`xdateTimeValue04` ASC) USING BTREE,
                              INDEX `PP_C_READ_dateTimeValue05`(`xdateTimeValue05` ASC) USING BTREE,
                              INDEX `PP_C_READ_dateValue01`(`xdateValue01` ASC) USING BTREE,
                              INDEX `PP_C_READ_dateValue02`(`xdateValue02` ASC) USING BTREE,
                              INDEX `PP_C_READ_doubleValue01`(`xdoubleValue01` ASC) USING BTREE,
                              INDEX `PP_C_READ_doubleValue02`(`xdoubleValue02` ASC) USING BTREE,
                              INDEX `PP_C_READ_doubleValue03`(`xdoubleValue03` ASC) USING BTREE,
                              INDEX `PP_C_READ_doubleValue04`(`xdoubleValue04` ASC) USING BTREE,
                              INDEX `PP_C_READ_doubleValue05`(`xdoubleValue05` ASC) USING BTREE,
                              INDEX `PP_C_READ_identity`(`xidentity` ASC) USING BTREE,
                              INDEX `PP_C_READ_job`(`xjob` ASC) USING BTREE,
                              INDEX `PP_C_READ_longValue01`(`xlongValue01` ASC) USING BTREE,
                              INDEX `PP_C_READ_longValue02`(`xlongValue02` ASC) USING BTREE,
                              INDEX `PP_C_READ_longValue03`(`xlongValue03` ASC) USING BTREE,
                              INDEX `PP_C_READ_longValue04`(`xlongValue04` ASC) USING BTREE,
                              INDEX `PP_C_READ_longValue05`(`xlongValue05` ASC) USING BTREE,
                              INDEX `PP_C_READ_opinion`(`xopinion` ASC) USING BTREE,
                              INDEX `PP_C_READ_person`(`xperson` ASC) USING BTREE,
                              INDEX `PP_C_READ_process`(`xprocess` ASC) USING BTREE,
                              INDEX `PP_C_READ_processName`(`xprocessName` ASC) USING BTREE,
                              INDEX `PP_C_READ_serial`(`xserial` ASC) USING BTREE,
                              INDEX `PP_C_READ_startTime`(`xstartTime` ASC) USING BTREE,
                              INDEX `PP_C_READ_startTimeMonth`(`xstartTimeMonth` ASC) USING BTREE,
                              INDEX `PP_C_READ_stringValue01`(`xstringValue01` ASC) USING BTREE,
                              INDEX `PP_C_READ_stringValue02`(`xstringValue02` ASC) USING BTREE,
                              INDEX `PP_C_READ_stringValue03`(`xstringValue03` ASC) USING BTREE,
                              INDEX `PP_C_READ_stringValue04`(`xstringValue04` ASC) USING BTREE,
                              INDEX `PP_C_READ_stringValue05`(`xstringValue05` ASC) USING BTREE,
                              INDEX `PP_C_READ_stringValue06`(`xstringValue06` ASC) USING BTREE,
                              INDEX `PP_C_READ_stringValue07`(`xstringValue07` ASC) USING BTREE,
                              INDEX `PP_C_READ_stringValue08`(`xstringValue08` ASC) USING BTREE,
                              INDEX `PP_C_READ_stringValue09`(`xstringValue09` ASC) USING BTREE,
                              INDEX `PP_C_READ_stringValue10`(`xstringValue10` ASC) USING BTREE,
                              INDEX `PP_C_READ_timeValue01`(`xtimeValue01` ASC) USING BTREE,
                              INDEX `PP_C_READ_timeValue02`(`xtimeValue02` ASC) USING BTREE,
                              INDEX `PP_C_READ_title`(`xtitle` ASC) USING BTREE,
                              INDEX `PP_C_READ_unit`(`xunit` ASC) USING BTREE,
                              INDEX `PP_C_READ_work`(`xwork` ASC) USING BTREE,
                              INDEX `PP_C_READ_workCompleted`(`xworkCompleted` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_readcompleted
-- ----------------------------
CREATE TABLE `pp_c_readcompleted`  (
                                       `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                       `xcreateTime` datetime NULL DEFAULT NULL,
                                       `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xupdateTime` datetime NULL DEFAULT NULL,
                                       `xdistributeFactor` int NULL DEFAULT NULL,
                                       `xactivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xactivityAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xactivityDescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xactivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xactivityToken` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xactivityType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xapplicationAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xapplicationName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xbooleanValue01` bit(1) NULL DEFAULT NULL,
                                       `xbooleanValue02` bit(1) NULL DEFAULT NULL,
                                       `xcompleted` bit(1) NULL DEFAULT NULL,
                                       `xcompletedTime` datetime NULL DEFAULT NULL,
                                       `xcompletedTimeMonth` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xcreatorIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xcreatorUnit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xcurrentActivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xdateTimeValue01` datetime NULL DEFAULT NULL,
                                       `xdateTimeValue02` datetime NULL DEFAULT NULL,
                                       `xdateTimeValue03` datetime NULL DEFAULT NULL,
                                       `xdateTimeValue04` datetime NULL DEFAULT NULL,
                                       `xdateTimeValue05` datetime NULL DEFAULT NULL,
                                       `xdateValue01` date NULL DEFAULT NULL,
                                       `xdateValue02` date NULL DEFAULT NULL,
                                       `xdoubleValue01` double NULL DEFAULT NULL,
                                       `xdoubleValue02` double NULL DEFAULT NULL,
                                       `xdoubleValue03` double NULL DEFAULT NULL,
                                       `xdoubleValue04` double NULL DEFAULT NULL,
                                       `xdoubleValue05` double NULL DEFAULT NULL,
                                       `xduration` bigint NULL DEFAULT NULL,
                                       `xidentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xlongValue01` bigint NULL DEFAULT NULL,
                                       `xlongValue02` bigint NULL DEFAULT NULL,
                                       `xlongValue03` bigint NULL DEFAULT NULL,
                                       `xlongValue04` bigint NULL DEFAULT NULL,
                                       `xlongValue05` bigint NULL DEFAULT NULL,
                                       `xopinion` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xopinionLob` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                       `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xprocessAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xprocessName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                       `xread` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xserial` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstartTime` datetime NULL DEFAULT NULL,
                                       `xstartTimeMonth` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue01` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue02` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue03` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue04` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue05` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue06` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue07` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue08` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue09` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue10` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xtimeValue01` time NULL DEFAULT NULL,
                                       `xtimeValue02` time NULL DEFAULT NULL,
                                       `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xunit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xwork` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xworkCompleted` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       PRIMARY KEY (`xid`) USING BTREE,
                                       UNIQUE INDEX `PP_C_READCOMPLETED_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_activity`(`xactivity` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_activityAlias`(`xactivityAlias` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_activityDescription`(`xactivityDescription` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_activityName`(`xactivityName` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_activityToken`(`xactivityToken` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_activityType`(`xactivityType` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_application`(`xapplication` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_applicationName`(`xapplicationName` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_completedTime`(`xcompletedTime` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_completedTimeMonth`(`xcompletedTimeMonth` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_creatorIdentity`(`xcreatorIdentity` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_creatorPerson`(`xcreatorPerson` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_creatorUnit`(`xcreatorUnit` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_currentActivityName`(`xcurrentActivityName` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_dateTimeValue01`(`xdateTimeValue01` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_dateTimeValue02`(`xdateTimeValue02` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_dateTimeValue03`(`xdateTimeValue03` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_dateTimeValue04`(`xdateTimeValue04` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_dateTimeValue05`(`xdateTimeValue05` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_dateValue01`(`xdateValue01` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_dateValue02`(`xdateValue02` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_doubleValue01`(`xdoubleValue01` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_doubleValue02`(`xdoubleValue02` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_doubleValue03`(`xdoubleValue03` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_doubleValue04`(`xdoubleValue04` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_doubleValue05`(`xdoubleValue05` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_identity`(`xidentity` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_job`(`xjob` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_longValue01`(`xlongValue01` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_longValue02`(`xlongValue02` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_longValue03`(`xlongValue03` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_longValue04`(`xlongValue04` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_longValue05`(`xlongValue05` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_opinion`(`xopinion` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_person`(`xperson` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_process`(`xprocess` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_processName`(`xprocessName` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_read`(`xread` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_serial`(`xserial` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_startTime`(`xstartTime` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_startTimeMonth`(`xstartTimeMonth` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_stringValue01`(`xstringValue01` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_stringValue02`(`xstringValue02` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_stringValue03`(`xstringValue03` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_stringValue04`(`xstringValue04` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_stringValue05`(`xstringValue05` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_stringValue06`(`xstringValue06` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_stringValue07`(`xstringValue07` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_stringValue08`(`xstringValue08` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_stringValue09`(`xstringValue09` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_stringValue10`(`xstringValue10` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_timeValue01`(`xtimeValue01` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_timeValue02`(`xtimeValue02` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_title`(`xtitle` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_unit`(`xunit` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_work`(`xwork` ASC) USING BTREE,
                                       INDEX `PP_C_READCOMPLETED_workCompleted`(`xworkCompleted` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_record
-- ----------------------------
CREATE TABLE `pp_c_record`  (
                                `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                `xcreateTime` datetime NULL DEFAULT NULL,
                                `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xupdateTime` datetime NULL DEFAULT NULL,
                                `xdistributeFactor` int NULL DEFAULT NULL,
                                `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xcompleted` bit(1) NULL DEFAULT NULL,
                                `xdisplay` bit(1) NULL DEFAULT NULL,
                                `xfromActivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xfromActivityAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xfromActivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xfromActivityToken` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xfromActivityType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xidentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xorder` bigint NULL DEFAULT NULL,
                                `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xrecordTime` datetime NULL DEFAULT NULL,
                                `xtype` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xunit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xwork` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xworkCompleted` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                PRIMARY KEY (`xid`) USING BTREE,
                                UNIQUE INDEX `PP_C_Record_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                INDEX `PP_C_Record_application`(`xapplication` ASC) USING BTREE,
                                INDEX `PP_C_Record_fromActivity`(`xfromActivity` ASC) USING BTREE,
                                INDEX `PP_C_Record_fromActivityAlias`(`xfromActivityAlias` ASC) USING BTREE,
                                INDEX `PP_C_Record_fromActivityName`(`xfromActivityName` ASC) USING BTREE,
                                INDEX `PP_C_Record_fromActivityToken`(`xfromActivityToken` ASC) USING BTREE,
                                INDEX `PP_C_Record_fromActivityType`(`xfromActivityType` ASC) USING BTREE,
                                INDEX `PP_C_Record_identity`(`xidentity` ASC) USING BTREE,
                                INDEX `PP_C_Record_job`(`xjob` ASC) USING BTREE,
                                INDEX `PP_C_Record_order`(`xorder` ASC) USING BTREE,
                                INDEX `PP_C_Record_person`(`xperson` ASC) USING BTREE,
                                INDEX `PP_C_Record_process`(`xprocess` ASC) USING BTREE,
                                INDEX `PP_C_Record_recordTime`(`xrecordTime` ASC) USING BTREE,
                                INDEX `PP_C_Record_type`(`xtype` ASC) USING BTREE,
                                INDEX `PP_C_Record_unit`(`xunit` ASC) USING BTREE,
                                INDEX `PP_C_Record_work`(`xwork` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_review
-- ----------------------------
CREATE TABLE `pp_c_review`  (
                                `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                `xcreateTime` datetime NULL DEFAULT NULL,
                                `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xupdateTime` datetime NULL DEFAULT NULL,
                                `xdistributeFactor` int NULL DEFAULT NULL,
                                `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xapplicationAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xapplicationName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xbooleanValue01` bit(1) NULL DEFAULT NULL,
                                `xbooleanValue02` bit(1) NULL DEFAULT NULL,
                                `xcompleted` bit(1) NULL DEFAULT NULL,
                                `xcompletedTime` datetime NULL DEFAULT NULL,
                                `xcompletedTimeMonth` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xcreatorIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xcreatorUnit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xcurrentActivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xdateTimeValue01` datetime NULL DEFAULT NULL,
                                `xdateTimeValue02` datetime NULL DEFAULT NULL,
                                `xdateTimeValue03` datetime NULL DEFAULT NULL,
                                `xdateTimeValue04` datetime NULL DEFAULT NULL,
                                `xdateTimeValue05` datetime NULL DEFAULT NULL,
                                `xdateValue01` date NULL DEFAULT NULL,
                                `xdateValue02` date NULL DEFAULT NULL,
                                `xdoubleValue01` double NULL DEFAULT NULL,
                                `xdoubleValue02` double NULL DEFAULT NULL,
                                `xdoubleValue03` double NULL DEFAULT NULL,
                                `xdoubleValue04` double NULL DEFAULT NULL,
                                `xdoubleValue05` double NULL DEFAULT NULL,
                                `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xlongValue01` bigint NULL DEFAULT NULL,
                                `xlongValue02` bigint NULL DEFAULT NULL,
                                `xlongValue03` bigint NULL DEFAULT NULL,
                                `xlongValue04` bigint NULL DEFAULT NULL,
                                `xlongValue05` bigint NULL DEFAULT NULL,
                                `xpermissionWrite` bit(1) NULL DEFAULT NULL,
                                `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xprocessAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xprocessName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xserial` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xstartTime` datetime NULL DEFAULT NULL,
                                `xstartTimeMonth` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xstringValue01` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xstringValue02` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xstringValue03` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xstringValue04` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xstringValue05` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xstringValue06` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xstringValue07` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xstringValue08` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xstringValue09` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xstringValue10` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xtimeValue01` time NULL DEFAULT NULL,
                                `xtimeValue02` time NULL DEFAULT NULL,
                                `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xwork` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xworkCompleted` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                PRIMARY KEY (`xid`) USING BTREE,
                                UNIQUE INDEX `PP_C_REVIEW_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                UNIQUE INDEX `PP_C_REVIEW_JP`(`xjob` ASC, `xperson` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_application`(`xapplication` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_applicationName`(`xapplicationName` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_completedTime`(`xcompletedTime` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_completedTimeMonth`(`xcompletedTimeMonth` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_creatorIdentity`(`xcreatorIdentity` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_creatorPerson`(`xcreatorPerson` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_creatorUnit`(`xcreatorUnit` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_currentActivityName`(`xcurrentActivityName` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_dateTimeValue01`(`xdateTimeValue01` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_dateTimeValue02`(`xdateTimeValue02` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_dateTimeValue03`(`xdateTimeValue03` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_dateTimeValue04`(`xdateTimeValue04` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_dateTimeValue05`(`xdateTimeValue05` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_dateValue01`(`xdateValue01` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_dateValue02`(`xdateValue02` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_doubleValue01`(`xdoubleValue01` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_doubleValue02`(`xdoubleValue02` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_doubleValue03`(`xdoubleValue03` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_doubleValue04`(`xdoubleValue04` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_doubleValue05`(`xdoubleValue05` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_job`(`xjob` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_longValue01`(`xlongValue01` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_longValue02`(`xlongValue02` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_longValue03`(`xlongValue03` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_longValue04`(`xlongValue04` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_longValue05`(`xlongValue05` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_person`(`xperson` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_process`(`xprocess` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_processName`(`xprocessName` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_serial`(`xserial` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_startTime`(`xstartTime` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_startTimeMonth`(`xstartTimeMonth` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_stringValue01`(`xstringValue01` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_stringValue02`(`xstringValue02` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_stringValue03`(`xstringValue03` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_stringValue04`(`xstringValue04` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_stringValue05`(`xstringValue05` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_stringValue06`(`xstringValue06` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_stringValue07`(`xstringValue07` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_stringValue08`(`xstringValue08` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_stringValue09`(`xstringValue09` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_stringValue10`(`xstringValue10` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_timeValue01`(`xtimeValue01` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_timeValue02`(`xtimeValue02` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_title`(`xtitle` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_work`(`xwork` ASC) USING BTREE,
                                INDEX `PP_C_REVIEW_workCompleted`(`xworkCompleted` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_serialnumber
-- ----------------------------
CREATE TABLE `pp_c_serialnumber`  (
                                      `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                      `xcreateTime` datetime NULL DEFAULT NULL,
                                      `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xupdateTime` datetime NULL DEFAULT NULL,
                                      `xdistributeFactor` int NULL DEFAULT NULL,
                                      `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xserial` int NULL DEFAULT NULL,
                                      PRIMARY KEY (`xid`) USING BTREE,
                                      UNIQUE INDEX `PP_C_SERIALNUMBER_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                      INDEX `PP_C_SERIALNUMBER_application`(`xapplication` ASC) USING BTREE,
                                      INDEX `PP_C_SERIALNUMBER_name`(`xname` ASC) USING BTREE,
                                      INDEX `PP_C_SERIALNUMBER_process`(`xprocess` ASC) USING BTREE,
                                      INDEX `PP_C_SERIALNUMBER_serial`(`xserial` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_snap
-- ----------------------------
CREATE TABLE `pp_c_snap`  (
                              `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                              `xcreateTime` datetime NULL DEFAULT NULL,
                              `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xupdateTime` datetime NULL DEFAULT NULL,
                              `xdistributeFactor` int NULL DEFAULT NULL,
                              `xactivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityDescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityToken` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xapplicationAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xapplicationName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcreatorIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcreatorUnit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xprocessAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xprocessName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              `xstartTime` datetime NULL DEFAULT NULL,
                              `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xtype` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              PRIMARY KEY (`xid`) USING BTREE,
                              UNIQUE INDEX `PP_C_SNAP_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                              INDEX `PP_C_SNAP_activity`(`xactivity` ASC) USING BTREE,
                              INDEX `PP_C_SNAP_activityName`(`xactivityName` ASC) USING BTREE,
                              INDEX `PP_C_SNAP_activityType`(`xactivityType` ASC) USING BTREE,
                              INDEX `PP_C_SNAP_application`(`xapplication` ASC) USING BTREE,
                              INDEX `PP_C_SNAP_applicationName`(`xapplicationName` ASC) USING BTREE,
                              INDEX `PP_C_SNAP_creatorIdentity`(`xcreatorIdentity` ASC) USING BTREE,
                              INDEX `PP_C_SNAP_creatorPerson`(`xcreatorPerson` ASC) USING BTREE,
                              INDEX `PP_C_SNAP_creatorUnit`(`xcreatorUnit` ASC) USING BTREE,
                              INDEX `PP_C_SNAP_job`(`xjob` ASC) USING BTREE,
                              INDEX `PP_C_SNAP_person`(`xperson` ASC) USING BTREE,
                              INDEX `PP_C_SNAP_process`(`xprocess` ASC) USING BTREE,
                              INDEX `PP_C_SNAP_processName`(`xprocessName` ASC) USING BTREE,
                              INDEX `PP_C_SNAP_startTime`(`xstartTime` ASC) USING BTREE,
                              INDEX `PP_C_SNAP_title`(`xtitle` ASC) USING BTREE,
                              INDEX `PP_C_SNAP_type`(`xtype` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_task
-- ----------------------------
CREATE TABLE `pp_c_task`  (
                              `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                              `xcreateTime` datetime NULL DEFAULT NULL,
                              `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xupdateTime` datetime NULL DEFAULT NULL,
                              `xdistributeFactor` int NULL DEFAULT NULL,
                              `xactivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityDescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityToken` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xallowRapid` bit(1) NULL DEFAULT NULL,
                              `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xapplicationAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xapplicationName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xbooleanValue01` bit(1) NULL DEFAULT NULL,
                              `xbooleanValue02` bit(1) NULL DEFAULT NULL,
                              `xcreatorIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcreatorUnit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xdateTimeValue01` datetime NULL DEFAULT NULL,
                              `xdateTimeValue02` datetime NULL DEFAULT NULL,
                              `xdateTimeValue03` datetime NULL DEFAULT NULL,
                              `xdateTimeValue04` datetime NULL DEFAULT NULL,
                              `xdateTimeValue05` datetime NULL DEFAULT NULL,
                              `xdateValue01` date NULL DEFAULT NULL,
                              `xdateValue02` date NULL DEFAULT NULL,
                              `xdistinguishedName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xdoubleValue01` double NULL DEFAULT NULL,
                              `xdoubleValue02` double NULL DEFAULT NULL,
                              `xdoubleValue03` double NULL DEFAULT NULL,
                              `xdoubleValue04` double NULL DEFAULT NULL,
                              `xdoubleValue05` double NULL DEFAULT NULL,
                              `xempowerFromIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xexpireTime` datetime NULL DEFAULT NULL,
                              `xexpired` bit(1) NULL DEFAULT NULL,
                              `xfirst` bit(1) NULL DEFAULT NULL,
                              `xfromDistinguishedName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xidentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xlabel` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xlongValue01` bigint NULL DEFAULT NULL,
                              `xlongValue02` bigint NULL DEFAULT NULL,
                              `xlongValue03` bigint NULL DEFAULT NULL,
                              `xlongValue04` bigint NULL DEFAULT NULL,
                              `xlongValue05` bigint NULL DEFAULT NULL,
                              `xmediaOpinion` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xmodified` bit(1) NULL DEFAULT NULL,
                              `xopinion` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xopinionLob` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              `xpause` bit(1) NULL DEFAULT NULL,
                              `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xprocessAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xprocessName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              `xrouteAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xrouteName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xserial` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xseries` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstartTime` datetime NULL DEFAULT NULL,
                              `xstartTimeMonth` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue01` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue02` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue03` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue04` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue05` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue06` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue07` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue08` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue09` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue10` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xtimeValue01` time NULL DEFAULT NULL,
                              `xtimeValue02` time NULL DEFAULT NULL,
                              `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xunit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xurgeTime` datetime NULL DEFAULT NULL,
                              `xurged` bit(1) NULL DEFAULT NULL,
                              `xviewTime` datetime NULL DEFAULT NULL,
                              `xwork` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xworkCreateType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              PRIMARY KEY (`xid`) USING BTREE,
                              UNIQUE INDEX `PP_C_TASK_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                              INDEX `PP_C_TASK_activity`(`xactivity` ASC) USING BTREE,
                              INDEX `PP_C_TASK_activityAlias`(`xactivityAlias` ASC) USING BTREE,
                              INDEX `PP_C_TASK_activityDescription`(`xactivityDescription` ASC) USING BTREE,
                              INDEX `PP_C_TASK_activityName`(`xactivityName` ASC) USING BTREE,
                              INDEX `PP_C_TASK_activityToken`(`xactivityToken` ASC) USING BTREE,
                              INDEX `PP_C_TASK_activityType`(`xactivityType` ASC) USING BTREE,
                              INDEX `PP_C_TASK_application`(`xapplication` ASC) USING BTREE,
                              INDEX `PP_C_TASK_applicationName`(`xapplicationName` ASC) USING BTREE,
                              INDEX `PP_C_TASK_creatorIdentity`(`xcreatorIdentity` ASC) USING BTREE,
                              INDEX `PP_C_TASK_creatorPerson`(`xcreatorPerson` ASC) USING BTREE,
                              INDEX `PP_C_TASK_creatorUnit`(`xcreatorUnit` ASC) USING BTREE,
                              INDEX `PP_C_TASK_dateTimeValue01`(`xdateTimeValue01` ASC) USING BTREE,
                              INDEX `PP_C_TASK_dateTimeValue02`(`xdateTimeValue02` ASC) USING BTREE,
                              INDEX `PP_C_TASK_dateTimeValue03`(`xdateTimeValue03` ASC) USING BTREE,
                              INDEX `PP_C_TASK_dateTimeValue04`(`xdateTimeValue04` ASC) USING BTREE,
                              INDEX `PP_C_TASK_dateTimeValue05`(`xdateTimeValue05` ASC) USING BTREE,
                              INDEX `PP_C_TASK_dateValue01`(`xdateValue01` ASC) USING BTREE,
                              INDEX `PP_C_TASK_dateValue02`(`xdateValue02` ASC) USING BTREE,
                              INDEX `PP_C_TASK_distinguishedName`(`xdistinguishedName` ASC) USING BTREE,
                              INDEX `PP_C_TASK_doubleValue01`(`xdoubleValue01` ASC) USING BTREE,
                              INDEX `PP_C_TASK_doubleValue02`(`xdoubleValue02` ASC) USING BTREE,
                              INDEX `PP_C_TASK_doubleValue03`(`xdoubleValue03` ASC) USING BTREE,
                              INDEX `PP_C_TASK_doubleValue04`(`xdoubleValue04` ASC) USING BTREE,
                              INDEX `PP_C_TASK_doubleValue05`(`xdoubleValue05` ASC) USING BTREE,
                              INDEX `PP_C_TASK_empowerFromIdentity`(`xempowerFromIdentity` ASC) USING BTREE,
                              INDEX `PP_C_TASK_expireTime`(`xexpireTime` ASC) USING BTREE,
                              INDEX `PP_C_TASK_fromDistinguishedName`(`xfromDistinguishedName` ASC) USING BTREE,
                              INDEX `PP_C_TASK_identity`(`xidentity` ASC) USING BTREE,
                              INDEX `PP_C_TASK_job`(`xjob` ASC) USING BTREE,
                              INDEX `PP_C_TASK_label`(`xlabel` ASC) USING BTREE,
                              INDEX `PP_C_TASK_longValue01`(`xlongValue01` ASC) USING BTREE,
                              INDEX `PP_C_TASK_longValue02`(`xlongValue02` ASC) USING BTREE,
                              INDEX `PP_C_TASK_longValue03`(`xlongValue03` ASC) USING BTREE,
                              INDEX `PP_C_TASK_longValue04`(`xlongValue04` ASC) USING BTREE,
                              INDEX `PP_C_TASK_longValue05`(`xlongValue05` ASC) USING BTREE,
                              INDEX `PP_C_TASK_opinion`(`xopinion` ASC) USING BTREE,
                              INDEX `PP_C_TASK_person`(`xperson` ASC) USING BTREE,
                              INDEX `PP_C_TASK_process`(`xprocess` ASC) USING BTREE,
                              INDEX `PP_C_TASK_processName`(`xprocessName` ASC) USING BTREE,
                              INDEX `PP_C_TASK_serial`(`xserial` ASC) USING BTREE,
                              INDEX `PP_C_TASK_series`(`xseries` ASC) USING BTREE,
                              INDEX `PP_C_TASK_startTime`(`xstartTime` ASC) USING BTREE,
                              INDEX `PP_C_TASK_startTimeMonth`(`xstartTimeMonth` ASC) USING BTREE,
                              INDEX `PP_C_TASK_stringValue01`(`xstringValue01` ASC) USING BTREE,
                              INDEX `PP_C_TASK_stringValue02`(`xstringValue02` ASC) USING BTREE,
                              INDEX `PP_C_TASK_stringValue03`(`xstringValue03` ASC) USING BTREE,
                              INDEX `PP_C_TASK_stringValue04`(`xstringValue04` ASC) USING BTREE,
                              INDEX `PP_C_TASK_stringValue05`(`xstringValue05` ASC) USING BTREE,
                              INDEX `PP_C_TASK_stringValue06`(`xstringValue06` ASC) USING BTREE,
                              INDEX `PP_C_TASK_stringValue07`(`xstringValue07` ASC) USING BTREE,
                              INDEX `PP_C_TASK_stringValue08`(`xstringValue08` ASC) USING BTREE,
                              INDEX `PP_C_TASK_stringValue09`(`xstringValue09` ASC) USING BTREE,
                              INDEX `PP_C_TASK_stringValue10`(`xstringValue10` ASC) USING BTREE,
                              INDEX `PP_C_TASK_timeValue01`(`xtimeValue01` ASC) USING BTREE,
                              INDEX `PP_C_TASK_timeValue02`(`xtimeValue02` ASC) USING BTREE,
                              INDEX `PP_C_TASK_title`(`xtitle` ASC) USING BTREE,
                              INDEX `PP_C_TASK_unit`(`xunit` ASC) USING BTREE,
                              INDEX `PP_C_TASK_urgeTime`(`xurgeTime` ASC) USING BTREE,
                              INDEX `PP_C_TASK_work`(`xwork` ASC) USING BTREE,
                              INDEX `PP_C_TASK_workCreateType`(`xworkCreateType` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_task_process_mode
-- ----------------------------
CREATE TABLE `pp_c_task_process_mode`  (
                                           `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                           `xcreateTime` datetime NULL DEFAULT NULL,
                                           `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xupdateTime` datetime NULL DEFAULT NULL,
                                           `xdistributeFactor` int NULL DEFAULT NULL,
                                           `xaction` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xactivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xactivityAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xactivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xhitCount` int NULL DEFAULT NULL,
                                           `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xprocessName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                           `xrouteId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xrouteName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           PRIMARY KEY (`xid`) USING BTREE,
                                           UNIQUE INDEX `PP_C_TASK_PROCESS_MODE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                           UNIQUE INDEX `PP_C_TASK_PROCESS_MODE_person`(`xperson` ASC, `xprocess` ASC, `xactivity` ASC, `xrouteId` ASC) USING BTREE,
                                           INDEX `PP_C_TASK_PROCESS_MODE_activity`(`xactivity` ASC) USING BTREE,
                                           INDEX `PP_C_TASK_PROCESS_MODE_activityName`(`xactivityName` ASC) USING BTREE,
                                           INDEX `PP_C_TASK_PROCESS_MODE_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_task_routedecisionopinionlist
-- ----------------------------
CREATE TABLE `pp_c_task_routedecisionopinionlist`  (
                                                       `TASK_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xrouteDecisionOpinionList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xorderColumn` int NULL DEFAULT NULL,
                                                       INDEX `PP_C_TASK_routeDecisionOpinionList_join`(`TASK_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_task_routelist
-- ----------------------------
CREATE TABLE `pp_c_task_routelist`  (
                                        `TASK_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xrouteList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xorderColumn` int NULL DEFAULT NULL,
                                        INDEX `PP_C_TASK_routeList_join`(`TASK_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_task_routenamelist
-- ----------------------------
CREATE TABLE `pp_c_task_routenamelist`  (
                                            `TASK_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xrouteNameList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xorderColumn` int NULL DEFAULT NULL,
                                            INDEX `PP_C_TASK_routeNameList_join`(`TASK_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_task_routeopinionlist
-- ----------------------------
CREATE TABLE `pp_c_task_routeopinionlist`  (
                                               `TASK_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xrouteOpinionList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `PP_C_TASK_routeOpinionList_join`(`TASK_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_taskcompleted
-- ----------------------------
CREATE TABLE `pp_c_taskcompleted`  (
                                       `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                       `xcreateTime` datetime NULL DEFAULT NULL,
                                       `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xupdateTime` datetime NULL DEFAULT NULL,
                                       `xdistributeFactor` int NULL DEFAULT NULL,
                                       `xactivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xactivityAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xactivityDescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xactivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xactivityToken` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xactivityType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xapplicationAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xapplicationName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xbooleanValue01` bit(1) NULL DEFAULT NULL,
                                       `xbooleanValue02` bit(1) NULL DEFAULT NULL,
                                       `xcompleted` bit(1) NULL DEFAULT NULL,
                                       `xcompletedTime` datetime NULL DEFAULT NULL,
                                       `xcompletedTimeMonth` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xcreatorIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xcreatorUnit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xcurrentActivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xdateTimeValue01` datetime NULL DEFAULT NULL,
                                       `xdateTimeValue02` datetime NULL DEFAULT NULL,
                                       `xdateTimeValue03` datetime NULL DEFAULT NULL,
                                       `xdateTimeValue04` datetime NULL DEFAULT NULL,
                                       `xdateTimeValue05` datetime NULL DEFAULT NULL,
                                       `xdateValue01` date NULL DEFAULT NULL,
                                       `xdateValue02` date NULL DEFAULT NULL,
                                       `xdistinguishedName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xdoubleValue01` double NULL DEFAULT NULL,
                                       `xdoubleValue02` double NULL DEFAULT NULL,
                                       `xdoubleValue03` double NULL DEFAULT NULL,
                                       `xdoubleValue04` double NULL DEFAULT NULL,
                                       `xdoubleValue05` double NULL DEFAULT NULL,
                                       `xduration` bigint NULL DEFAULT NULL,
                                       `xempowerFromIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xempowerToIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xexpireTime` datetime NULL DEFAULT NULL,
                                       `xexpired` bit(1) NULL DEFAULT NULL,
                                       `xidentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xjoinInquire` bit(1) NULL DEFAULT NULL,
                                       `xlabel` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xlatest` bit(1) NULL DEFAULT NULL,
                                       `xlongValue01` bigint NULL DEFAULT NULL,
                                       `xlongValue02` bigint NULL DEFAULT NULL,
                                       `xlongValue03` bigint NULL DEFAULT NULL,
                                       `xlongValue04` bigint NULL DEFAULT NULL,
                                       `xlongValue05` bigint NULL DEFAULT NULL,
                                       `xmediaOpinion` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xopinion` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xopinionLob` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                       `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xpressActivityToken` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xpressCount` int NULL DEFAULT NULL,
                                       `xpressTime` datetime NULL DEFAULT NULL,
                                       `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xprocessAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xprocessName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xprocessingType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                       `xretractTime` datetime NULL DEFAULT NULL,
                                       `xrouteAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xrouteName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xserial` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstartTime` datetime NULL DEFAULT NULL,
                                       `xstartTimeMonth` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue01` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue02` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue03` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue04` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue05` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue06` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue07` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue08` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue09` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue10` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xtask` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xtimeValue01` time NULL DEFAULT NULL,
                                       `xtimeValue02` time NULL DEFAULT NULL,
                                       `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xunit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xviewTime` datetime NULL DEFAULT NULL,
                                       `xwork` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xworkCompleted` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       PRIMARY KEY (`xid`) USING BTREE,
                                       UNIQUE INDEX `PP_C_TASKCOMPLETED_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_activity`(`xactivity` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_activityName`(`xactivityName` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_activityToken`(`xactivityToken` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_application`(`xapplication` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_applicationName`(`xapplicationName` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_completedTime`(`xcompletedTime` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_completedTimeMonth`(`xcompletedTimeMonth` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_creatorIdentity`(`xcreatorIdentity` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_creatorPerson`(`xcreatorPerson` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_creatorUnit`(`xcreatorUnit` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_dateTimeValue01`(`xdateTimeValue01` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_dateTimeValue02`(`xdateTimeValue02` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_dateTimeValue03`(`xdateTimeValue03` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_dateTimeValue04`(`xdateTimeValue04` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_dateTimeValue05`(`xdateTimeValue05` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_dateValue01`(`xdateValue01` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_dateValue02`(`xdateValue02` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_distinguishedName`(`xdistinguishedName` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_doubleValue01`(`xdoubleValue01` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_doubleValue02`(`xdoubleValue02` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_doubleValue03`(`xdoubleValue03` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_doubleValue04`(`xdoubleValue04` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_doubleValue05`(`xdoubleValue05` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_expireTime`(`xexpireTime` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_identity`(`xidentity` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_job`(`xjob` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_label`(`xlabel` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_longValue01`(`xlongValue01` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_longValue02`(`xlongValue02` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_longValue03`(`xlongValue03` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_longValue04`(`xlongValue04` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_longValue05`(`xlongValue05` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_opinion`(`xopinion` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_person`(`xperson` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_process`(`xprocess` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_processName`(`xprocessName` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_serial`(`xserial` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_startTime`(`xstartTime` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_startTimeMonth`(`xstartTimeMonth` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_stringValue01`(`xstringValue01` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_stringValue02`(`xstringValue02` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_stringValue03`(`xstringValue03` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_stringValue04`(`xstringValue04` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_stringValue05`(`xstringValue05` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_stringValue06`(`xstringValue06` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_stringValue07`(`xstringValue07` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_stringValue08`(`xstringValue08` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_stringValue09`(`xstringValue09` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_stringValue10`(`xstringValue10` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_task`(`xtask` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_timeValue01`(`xtimeValue01` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_timeValue02`(`xtimeValue02` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_title`(`xtitle` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_unit`(`xunit` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_work`(`xwork` ASC) USING BTREE,
                                       INDEX `PP_C_TASKCOMPLETED_workCompleted`(`xworkCompleted` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_work
-- ----------------------------
CREATE TABLE `pp_c_work`  (
                              `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                              `xcreateTime` datetime NULL DEFAULT NULL,
                              `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xupdateTime` datetime NULL DEFAULT NULL,
                              `xdistributeFactor` int NULL DEFAULT NULL,
                              `xactivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityArrivedTime` datetime NULL DEFAULT NULL,
                              `xactivityDescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityToken` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xactivityType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xapplicationAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xapplicationName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xbeforeExecuted` bit(1) NULL DEFAULT NULL,
                              `xbooleanValue01` bit(1) NULL DEFAULT NULL,
                              `xbooleanValue02` bit(1) NULL DEFAULT NULL,
                              `xcreatorIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcreatorUnit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcreatorUnitLevelName` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              `xdataChanged` bit(1) NULL DEFAULT NULL,
                              `xdateTimeValue01` datetime NULL DEFAULT NULL,
                              `xdateTimeValue02` datetime NULL DEFAULT NULL,
                              `xdateTimeValue03` datetime NULL DEFAULT NULL,
                              `xdateTimeValue04` datetime NULL DEFAULT NULL,
                              `xdateTimeValue05` datetime NULL DEFAULT NULL,
                              `xdateValue01` date NULL DEFAULT NULL,
                              `xdateValue02` date NULL DEFAULT NULL,
                              `xdestinationActivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xdestinationActivityType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xdestinationRoute` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xdestinationRouteName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xdoubleValue01` double NULL DEFAULT NULL,
                              `xdoubleValue02` double NULL DEFAULT NULL,
                              `xdoubleValue03` double NULL DEFAULT NULL,
                              `xdoubleValue04` double NULL DEFAULT NULL,
                              `xdoubleValue05` double NULL DEFAULT NULL,
                              `xembedTargetWork` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xexpireTime` datetime NULL DEFAULT NULL,
                              `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xlongValue01` bigint NULL DEFAULT NULL,
                              `xlongValue02` bigint NULL DEFAULT NULL,
                              `xlongValue03` bigint NULL DEFAULT NULL,
                              `xlongValue04` bigint NULL DEFAULT NULL,
                              `xlongValue05` bigint NULL DEFAULT NULL,
                              `xobjectSecurityClearance` int NULL DEFAULT NULL,
                              `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xprocessAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xprocessName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              `xserial` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xsplitToken` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xsplitValue` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xsplitting` bit(1) NULL DEFAULT NULL,
                              `xstartTime` datetime NULL DEFAULT NULL,
                              `xstartTimeMonth` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue01` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue02` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue03` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue04` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue05` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue06` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue07` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue08` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue09` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xstringValue10` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xtimeValue01` time NULL DEFAULT NULL,
                              `xtimeValue02` time NULL DEFAULT NULL,
                              `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xworkCreateType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xworkStatus` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xworkThroughManual` bit(1) NULL DEFAULT NULL,
                              PRIMARY KEY (`xid`) USING BTREE,
                              UNIQUE INDEX `PP_C_WORK_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                              INDEX `PP_C_WORK_activity`(`xactivity` ASC) USING BTREE,
                              INDEX `PP_C_WORK_activityAlias`(`xactivityAlias` ASC) USING BTREE,
                              INDEX `PP_C_WORK_activityArrivedTime`(`xactivityArrivedTime` ASC) USING BTREE,
                              INDEX `PP_C_WORK_activityDescription`(`xactivityDescription` ASC) USING BTREE,
                              INDEX `PP_C_WORK_activityName`(`xactivityName` ASC) USING BTREE,
                              INDEX `PP_C_WORK_activityToken`(`xactivityToken` ASC) USING BTREE,
                              INDEX `PP_C_WORK_activityType`(`xactivityType` ASC) USING BTREE,
                              INDEX `PP_C_WORK_application`(`xapplication` ASC) USING BTREE,
                              INDEX `PP_C_WORK_applicationName`(`xapplicationName` ASC) USING BTREE,
                              INDEX `PP_C_WORK_creatorIdentity`(`xcreatorIdentity` ASC) USING BTREE,
                              INDEX `PP_C_WORK_creatorPerson`(`xcreatorPerson` ASC) USING BTREE,
                              INDEX `PP_C_WORK_creatorUnit`(`xcreatorUnit` ASC) USING BTREE,
                              INDEX `PP_C_WORK_dateTimeValue01`(`xdateTimeValue01` ASC) USING BTREE,
                              INDEX `PP_C_WORK_dateTimeValue02`(`xdateTimeValue02` ASC) USING BTREE,
                              INDEX `PP_C_WORK_dateTimeValue03`(`xdateTimeValue03` ASC) USING BTREE,
                              INDEX `PP_C_WORK_dateTimeValue04`(`xdateTimeValue04` ASC) USING BTREE,
                              INDEX `PP_C_WORK_dateTimeValue05`(`xdateTimeValue05` ASC) USING BTREE,
                              INDEX `PP_C_WORK_dateValue01`(`xdateValue01` ASC) USING BTREE,
                              INDEX `PP_C_WORK_dateValue02`(`xdateValue02` ASC) USING BTREE,
                              INDEX `PP_C_WORK_destinationActivity`(`xdestinationActivity` ASC) USING BTREE,
                              INDEX `PP_C_WORK_destinationActivityType`(`xdestinationActivityType` ASC) USING BTREE,
                              INDEX `PP_C_WORK_doubleValue01`(`xdoubleValue01` ASC) USING BTREE,
                              INDEX `PP_C_WORK_doubleValue02`(`xdoubleValue02` ASC) USING BTREE,
                              INDEX `PP_C_WORK_doubleValue03`(`xdoubleValue03` ASC) USING BTREE,
                              INDEX `PP_C_WORK_doubleValue04`(`xdoubleValue04` ASC) USING BTREE,
                              INDEX `PP_C_WORK_doubleValue05`(`xdoubleValue05` ASC) USING BTREE,
                              INDEX `PP_C_WORK_embedTargetWork`(`xembedTargetWork` ASC) USING BTREE,
                              INDEX `PP_C_WORK_expireTime`(`xexpireTime` ASC) USING BTREE,
                              INDEX `PP_C_WORK_job`(`xjob` ASC) USING BTREE,
                              INDEX `PP_C_WORK_longValue01`(`xlongValue01` ASC) USING BTREE,
                              INDEX `PP_C_WORK_longValue02`(`xlongValue02` ASC) USING BTREE,
                              INDEX `PP_C_WORK_longValue03`(`xlongValue03` ASC) USING BTREE,
                              INDEX `PP_C_WORK_longValue04`(`xlongValue04` ASC) USING BTREE,
                              INDEX `PP_C_WORK_longValue05`(`xlongValue05` ASC) USING BTREE,
                              INDEX `PP_C_WORK_objectSecurityClearance`(`xobjectSecurityClearance` ASC) USING BTREE,
                              INDEX `PP_C_WORK_process`(`xprocess` ASC) USING BTREE,
                              INDEX `PP_C_WORK_processName`(`xprocessName` ASC) USING BTREE,
                              INDEX `PP_C_WORK_serial`(`xserial` ASC) USING BTREE,
                              INDEX `PP_C_WORK_startTime`(`xstartTime` ASC) USING BTREE,
                              INDEX `PP_C_WORK_startTimeMonth`(`xstartTimeMonth` ASC) USING BTREE,
                              INDEX `PP_C_WORK_stringValue01`(`xstringValue01` ASC) USING BTREE,
                              INDEX `PP_C_WORK_stringValue02`(`xstringValue02` ASC) USING BTREE,
                              INDEX `PP_C_WORK_stringValue03`(`xstringValue03` ASC) USING BTREE,
                              INDEX `PP_C_WORK_stringValue04`(`xstringValue04` ASC) USING BTREE,
                              INDEX `PP_C_WORK_stringValue05`(`xstringValue05` ASC) USING BTREE,
                              INDEX `PP_C_WORK_stringValue06`(`xstringValue06` ASC) USING BTREE,
                              INDEX `PP_C_WORK_stringValue07`(`xstringValue07` ASC) USING BTREE,
                              INDEX `PP_C_WORK_stringValue08`(`xstringValue08` ASC) USING BTREE,
                              INDEX `PP_C_WORK_stringValue09`(`xstringValue09` ASC) USING BTREE,
                              INDEX `PP_C_WORK_stringValue10`(`xstringValue10` ASC) USING BTREE,
                              INDEX `PP_C_WORK_timeValue01`(`xtimeValue01` ASC) USING BTREE,
                              INDEX `PP_C_WORK_timeValue02`(`xtimeValue02` ASC) USING BTREE,
                              INDEX `PP_C_WORK_title`(`xtitle` ASC) USING BTREE,
                              INDEX `PP_C_WORK_workCreateType`(`xworkCreateType` ASC) USING BTREE,
                              INDEX `PP_C_WORK_workStatus`(`xworkStatus` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_work_splittokenlist
-- ----------------------------
CREATE TABLE `pp_c_work_splittokenlist`  (
                                             `WORK_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xsplitTokenList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `PP_C_WORK_splitTokenList_element`(`xsplitTokenList` ASC) USING BTREE,
                                             INDEX `PP_C_WORK_splitTokenList_join`(`WORK_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_workcompleted
-- ----------------------------
CREATE TABLE `pp_c_workcompleted`  (
                                       `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                       `xcreateTime` datetime NULL DEFAULT NULL,
                                       `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xupdateTime` datetime NULL DEFAULT NULL,
                                       `xdistributeFactor` int NULL DEFAULT NULL,
                                       `xactivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xactivityAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xactivityDescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xactivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xallowRollback` bit(1) NULL DEFAULT NULL,
                                       `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xapplicationAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xapplicationName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xbooleanValue01` bit(1) NULL DEFAULT NULL,
                                       `xbooleanValue02` bit(1) NULL DEFAULT NULL,
                                       `xcompletedTime` datetime NULL DEFAULT NULL,
                                       `xcompletedTimeMonth` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xcompletedType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xcreatorIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xcreatorUnit` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xcreatorUnitLevelName` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                       `xdateTimeValue01` datetime NULL DEFAULT NULL,
                                       `xdateTimeValue02` datetime NULL DEFAULT NULL,
                                       `xdateTimeValue03` datetime NULL DEFAULT NULL,
                                       `xdateTimeValue04` datetime NULL DEFAULT NULL,
                                       `xdateTimeValue05` datetime NULL DEFAULT NULL,
                                       `xdateValue01` date NULL DEFAULT NULL,
                                       `xdateValue02` date NULL DEFAULT NULL,
                                       `xdoubleValue01` double NULL DEFAULT NULL,
                                       `xdoubleValue02` double NULL DEFAULT NULL,
                                       `xdoubleValue03` double NULL DEFAULT NULL,
                                       `xdoubleValue04` double NULL DEFAULT NULL,
                                       `xdoubleValue05` double NULL DEFAULT NULL,
                                       `xduration` bigint NULL DEFAULT NULL,
                                       `xexpireTime` datetime NULL DEFAULT NULL,
                                       `xexpired` bit(1) NULL DEFAULT NULL,
                                       `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xlongValue01` bigint NULL DEFAULT NULL,
                                       `xlongValue02` bigint NULL DEFAULT NULL,
                                       `xlongValue03` bigint NULL DEFAULT NULL,
                                       `xlongValue04` bigint NULL DEFAULT NULL,
                                       `xlongValue05` bigint NULL DEFAULT NULL,
                                       `xmerged` bit(1) NULL DEFAULT NULL,
                                       `xobjectSecurityClearance` int NULL DEFAULT NULL,
                                       `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xprocessAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xprocessName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                       `xserial` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstartTime` datetime NULL DEFAULT NULL,
                                       `xstartTimeMonth` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue01` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue02` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue03` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue04` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue05` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue06` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue07` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue08` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue09` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xstringValue10` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xtimeValue01` time NULL DEFAULT NULL,
                                       `xtimeValue02` time NULL DEFAULT NULL,
                                       `xtitle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       `xwork` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                       PRIMARY KEY (`xid`) USING BTREE,
                                       UNIQUE INDEX `PP_C_WORKCOMPLETED_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_activity`(`xactivity` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_activityAlias`(`xactivityAlias` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_activityDescription`(`xactivityDescription` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_activityName`(`xactivityName` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_application`(`xapplication` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_applicationName`(`xapplicationName` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_completedTime`(`xcompletedTime` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_completedTimeMonth`(`xcompletedTimeMonth` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_completedType`(`xcompletedType` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_creatorIdentity`(`xcreatorIdentity` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_creatorPerson`(`xcreatorPerson` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_creatorUnit`(`xcreatorUnit` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_dateTimeValue01`(`xdateTimeValue01` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_dateTimeValue02`(`xdateTimeValue02` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_dateTimeValue03`(`xdateTimeValue03` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_dateTimeValue04`(`xdateTimeValue04` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_dateTimeValue05`(`xdateTimeValue05` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_dateValue01`(`xdateValue01` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_dateValue02`(`xdateValue02` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_doubleValue01`(`xdoubleValue01` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_doubleValue02`(`xdoubleValue02` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_doubleValue03`(`xdoubleValue03` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_doubleValue04`(`xdoubleValue04` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_doubleValue05`(`xdoubleValue05` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_expireTime`(`xexpireTime` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_form`(`xform` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_job`(`xjob` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_longValue01`(`xlongValue01` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_longValue02`(`xlongValue02` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_longValue03`(`xlongValue03` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_longValue04`(`xlongValue04` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_longValue05`(`xlongValue05` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_objectSecurityClearance`(`xobjectSecurityClearance` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_process`(`xprocess` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_processName`(`xprocessName` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_serial`(`xserial` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_startTime`(`xstartTime` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_startTimeMonth`(`xstartTimeMonth` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_stringValue01`(`xstringValue01` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_stringValue02`(`xstringValue02` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_stringValue03`(`xstringValue03` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_stringValue04`(`xstringValue04` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_stringValue05`(`xstringValue05` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_stringValue06`(`xstringValue06` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_stringValue07`(`xstringValue07` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_stringValue08`(`xstringValue08` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_stringValue09`(`xstringValue09` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_stringValue10`(`xstringValue10` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_timeValue01`(`xtimeValue01` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_timeValue02`(`xtimeValue02` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_title`(`xtitle` ASC) USING BTREE,
                                       INDEX `PP_C_WORKCOMPLETED_work`(`xwork` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_c_worklog
-- ----------------------------
CREATE TABLE `pp_c_worklog`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xapplicationAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xapplicationName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xarrivedActivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xarrivedActivityAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xarrivedActivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xarrivedActivityToken` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xarrivedActivityType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xarrivedGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xarrivedOpinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xarrivedTime` datetime NULL DEFAULT NULL,
                                 `xcompleted` bit(1) NULL DEFAULT NULL,
                                 `xconnected` bit(1) NULL DEFAULT NULL,
                                 `xduration` bigint NULL DEFAULT NULL,
                                 `xfromActivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xfromActivityAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xfromActivityName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xfromActivityToken` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xfromActivityType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xfromGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xfromOpinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xfromTime` datetime NULL DEFAULT NULL,
                                 `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xprocessAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xprocessName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xroute` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xrouteName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xsplitToken` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xsplitValue` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xsplitWork` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xsplitting` bit(1) NULL DEFAULT NULL,
                                 `xtype` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xwork` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xworkCompleted` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `PP_C_WORKLOG_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                 INDEX `PP_C_WORKLOGtypesplitWork`(`xtype` ASC) USING BTREE,
                                 INDEX `PP_C_WORKLOG_arrivedActivity`(`xarrivedActivity` ASC) USING BTREE,
                                 INDEX `PP_C_WORKLOG_arrivedActivityToken`(`xarrivedActivityToken` ASC) USING BTREE,
                                 INDEX `PP_C_WORKLOG_arrivedActivityType`(`xarrivedActivityType` ASC) USING BTREE,
                                 INDEX `PP_C_WORKLOG_fromActivity`(`xfromActivity` ASC) USING BTREE,
                                 INDEX `PP_C_WORKLOG_fromActivityToken`(`xfromActivityToken` ASC) USING BTREE,
                                 INDEX `PP_C_WORKLOG_fromActivityType`(`xfromActivityType` ASC) USING BTREE,
                                 INDEX `PP_C_WORKLOG_fromTime`(`xfromTime` ASC) USING BTREE,
                                 INDEX `PP_C_WORKLOG_job`(`xjob` ASC) USING BTREE,
                                 INDEX `PP_C_WORKLOG_routeName`(`xrouteName` ASC) USING BTREE,
                                 INDEX `PP_C_WORKLOG_splitWork`(`xsplitWork` ASC) USING BTREE,
                                 INDEX `PP_C_WORKLOG_work`(`xwork` ASC) USING BTREE,
                                 INDEX `PP_C_WORKLOG_workCompleted`(`xworkCompleted` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_agent
-- ----------------------------
CREATE TABLE `pp_e_agent`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xafterArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xafterExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xafterInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xagentInterruptScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xagentInterruptScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xallowReroute` bit(1) NULL DEFAULT NULL,
                               `xallowRerouteTo` bit(1) NULL DEFAULT NULL,
                               `xbeforeArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xbeforeExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xbeforeInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdisplayLogScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdisplayLogScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xextension` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xgroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xopinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xposition` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreadDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreadScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xreadScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreviewDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreviewScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xreviewScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xroute` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xscript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xscriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `PP_E_AGENT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `PP_E_AGENT_form`(`xform` ASC) USING BTREE,
                               INDEX `PP_E_AGENT_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_agent_readdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_agent_readdatapathlist`  (
                                                `AGENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreadDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_AGENT_readDataPathList_element`(`xreadDataPathList` ASC) USING BTREE,
                                                INDEX `PP_E_AGENT_readDataPathList_join`(`AGENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_agent_readgrouplist
-- ----------------------------
CREATE TABLE `pp_e_agent_readgrouplist`  (
                                             `AGENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `PP_E_AGENT_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                             INDEX `PP_E_AGENT_readGroupList_join`(`AGENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_agent_readidentitylist
-- ----------------------------
CREATE TABLE `pp_e_agent_readidentitylist`  (
                                                `AGENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_AGENT_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                                INDEX `PP_E_AGENT_readIdentityList_join`(`AGENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_agent_readunitlist
-- ----------------------------
CREATE TABLE `pp_e_agent_readunitlist`  (
                                            `AGENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xorderColumn` int NULL DEFAULT NULL,
                                            INDEX `PP_E_AGENT_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                            INDEX `PP_E_AGENT_readUnitList_join`(`AGENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_agent_reviewdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_agent_reviewdatapathlist`  (
                                                  `AGENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreviewDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_AGENT_reviewDataPathList_element`(`xreviewDataPathList` ASC) USING BTREE,
                                                  INDEX `PP_E_AGENT_reviewDataPathList_join`(`AGENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_agent_reviewgrouplist
-- ----------------------------
CREATE TABLE `pp_e_agent_reviewgrouplist`  (
                                               `AGENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xreviewGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `PP_E_AGENT_reviewGroupList_element`(`xreviewGroupList` ASC) USING BTREE,
                                               INDEX `PP_E_AGENT_reviewGroupList_join`(`AGENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_agent_reviewidentitylist
-- ----------------------------
CREATE TABLE `pp_e_agent_reviewidentitylist`  (
                                                  `AGENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreviewIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_AGENT_reviewIdentityList_element`(`xreviewIdentityList` ASC) USING BTREE,
                                                  INDEX `PP_E_AGENT_reviewIdentityList_join`(`AGENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_agent_reviewunitlist
-- ----------------------------
CREATE TABLE `pp_e_agent_reviewunitlist`  (
                                              `AGENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreviewUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PP_E_AGENT_reviewUnitList_element`(`xreviewUnitList` ASC) USING BTREE,
                                              INDEX `PP_E_AGENT_reviewUnitList_join`(`AGENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_application
-- ----------------------------
CREATE TABLE `pp_e_application`  (
                                     `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                     `xcreateTime` datetime NULL DEFAULT NULL,
                                     `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xupdateTime` datetime NULL DEFAULT NULL,
                                     `xdistributeFactor` int NULL DEFAULT NULL,
                                     `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xapplicationCategory` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xicon` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                     `xiconHue` varchar(8) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xlastUpdateTime` datetime NULL DEFAULT NULL,
                                     `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                     PRIMARY KEY (`xid`) USING BTREE,
                                     UNIQUE INDEX `PP_E_APPLICATION_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                     INDEX `PP_E_APPLICATION_name`(`xname` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_application_availablegrouplist
-- ----------------------------
CREATE TABLE `pp_e_application_availablegrouplist`  (
                                                        `APPLICATION_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xavailableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xorderColumn` int NULL DEFAULT NULL,
                                                        INDEX `PP_E_APPLICATION_availableGroupList_element`(`xavailableGroupList` ASC) USING BTREE,
                                                        INDEX `PP_E_APPLICATION_availableGroupList_join`(`APPLICATION_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_application_availableidentitylist
-- ----------------------------
CREATE TABLE `pp_e_application_availableidentitylist`  (
                                                           `APPLICATION_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                           `xavailableIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                           `xorderColumn` int NULL DEFAULT NULL,
                                                           INDEX `PP_E_APPLICATION_availableIdentityList_element`(`xavailableIdentityList` ASC) USING BTREE,
                                                           INDEX `PP_E_APPLICATION_availableIdentityList_join`(`APPLICATION_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_application_availableunitlist
-- ----------------------------
CREATE TABLE `pp_e_application_availableunitlist`  (
                                                       `APPLICATION_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xavailableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xorderColumn` int NULL DEFAULT NULL,
                                                       INDEX `PP_E_APPLICATION_availableUnitList_element`(`xavailableUnitList` ASC) USING BTREE,
                                                       INDEX `PP_E_APPLICATION_availableUnitList_join`(`APPLICATION_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_application_controllerlist
-- ----------------------------
CREATE TABLE `pp_e_application_controllerlist`  (
                                                    `APPLICATION_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xcontrollerList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `PP_E_APPLICATION_controllerList_element`(`xcontrollerList` ASC) USING BTREE,
                                                    INDEX `PP_E_APPLICATION_controllerList_join`(`APPLICATION_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_applicationdict
-- ----------------------------
CREATE TABLE `pp_e_applicationdict`  (
                                         `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                         `xcreateTime` datetime NULL DEFAULT NULL,
                                         `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xupdateTime` datetime NULL DEFAULT NULL,
                                         `xdistributeFactor` int NULL DEFAULT NULL,
                                         `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                         PRIMARY KEY (`xid`) USING BTREE,
                                         UNIQUE INDEX `PP_E_APPLICATIONDICT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                         INDEX `PP_E_APPLICATIONDICT_alias`(`xalias` ASC) USING BTREE,
                                         INDEX `PP_E_APPLICATIONDICT_application`(`xapplication` ASC) USING BTREE,
                                         INDEX `PP_E_APPLICATIONDICT_description`(`xdescription` ASC) USING BTREE,
                                         INDEX `PP_E_APPLICATIONDICT_name`(`xname` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_applicationdictitem
-- ----------------------------
CREATE TABLE `pp_e_applicationdictitem`  (
                                             `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                             `xcreateTime` datetime NULL DEFAULT NULL,
                                             `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xupdateTime` datetime NULL DEFAULT NULL,
                                             `xdistributeFactor` int NULL DEFAULT NULL,
                                             `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xbooleanValue` bit(1) NULL DEFAULT NULL,
                                             `xbundle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xdateTimeValue` datetime NULL DEFAULT NULL,
                                             `xdateValue` date NULL DEFAULT NULL,
                                             `xitemCategory` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xitemPrimitiveType` varchar(1) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xitemStringValueType` varchar(2) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xitemType` varchar(1) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xnumberValue` double NULL DEFAULT NULL,
                                             `xpath0` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xpath0Location` int NULL DEFAULT NULL,
                                             `xpath1` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xpath1Location` int NULL DEFAULT NULL,
                                             `xpath2` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xpath2Location` int NULL DEFAULT NULL,
                                             `xpath3` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xpath3Location` int NULL DEFAULT NULL,
                                             `xpath4` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xpath4Location` int NULL DEFAULT NULL,
                                             `xpath5` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xpath5Location` int NULL DEFAULT NULL,
                                             `xpath6` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xpath6Location` int NULL DEFAULT NULL,
                                             `xpath7` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xpath7Location` int NULL DEFAULT NULL,
                                             `xstringLongValue` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                             `xstringShortValue` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xtimeValue` time NULL DEFAULT NULL,
                                             PRIMARY KEY (`xid`) USING BTREE,
                                             UNIQUE INDEX `PP_E_APPLICATIONDICTITEM_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_application`(`xapplication` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_bundle`(`xbundle` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_dateTimeValue`(`xdateTimeValue` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_dateValue`(`xdateValue` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_itemCategory`(`xitemCategory` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_itemPrimitiveType`(`xitemPrimitiveType` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_itemStringValueType`(`xitemStringValueType` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_itemType`(`xitemType` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_numberValue`(`xnumberValue` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path0`(`xpath0` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path0Location`(`xpath0Location` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path1`(`xpath1` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path1Location`(`xpath1Location` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path2`(`xpath2` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path2Location`(`xpath2Location` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path3`(`xpath3` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path3Location`(`xpath3Location` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path4`(`xpath4` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path4Location`(`xpath4Location` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path5`(`xpath5` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path5Location`(`xpath5Location` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path6`(`xpath6` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path6Location`(`xpath6Location` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path7`(`xpath7` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_path7Location`(`xpath7Location` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_stringShortValue`(`xstringShortValue` ASC) USING BTREE,
                                             INDEX `PP_E_APPLICATIONDICTITEM_timeValue`(`xtimeValue` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_begin
-- ----------------------------
CREATE TABLE `pp_e_begin`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xafterArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xafterExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xafterInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xallowReroute` bit(1) NULL DEFAULT NULL,
                               `xallowRerouteTo` bit(1) NULL DEFAULT NULL,
                               `xbeforeArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xbeforeExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xbeforeInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdisplayLogScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdisplayLogScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xextension` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xgroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xopinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xposition` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreadDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreadScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xreadScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreviewDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreviewScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xreviewScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xroute` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `PP_E_BEGIN_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `PP_E_BEGIN_form`(`xform` ASC) USING BTREE,
                               INDEX `PP_E_BEGIN_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_begin_readdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_begin_readdatapathlist`  (
                                                `BEGIN_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreadDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_BEGIN_readDataPathList_element`(`xreadDataPathList` ASC) USING BTREE,
                                                INDEX `PP_E_BEGIN_readDataPathList_join`(`BEGIN_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_begin_readgrouplist
-- ----------------------------
CREATE TABLE `pp_e_begin_readgrouplist`  (
                                             `BEGIN_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `PP_E_BEGIN_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                             INDEX `PP_E_BEGIN_readGroupList_join`(`BEGIN_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_begin_readidentitylist
-- ----------------------------
CREATE TABLE `pp_e_begin_readidentitylist`  (
                                                `BEGIN_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_BEGIN_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                                INDEX `PP_E_BEGIN_readIdentityList_join`(`BEGIN_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_begin_readunitlist
-- ----------------------------
CREATE TABLE `pp_e_begin_readunitlist`  (
                                            `BEGIN_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xorderColumn` int NULL DEFAULT NULL,
                                            INDEX `PP_E_BEGIN_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                            INDEX `PP_E_BEGIN_readUnitList_join`(`BEGIN_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_begin_reviewdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_begin_reviewdatapathlist`  (
                                                  `BEGIN_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreviewDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_BEGIN_reviewDataPathList_element`(`xreviewDataPathList` ASC) USING BTREE,
                                                  INDEX `PP_E_BEGIN_reviewDataPathList_join`(`BEGIN_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_begin_reviewgrouplist
-- ----------------------------
CREATE TABLE `pp_e_begin_reviewgrouplist`  (
                                               `BEGIN_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xreviewGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `PP_E_BEGIN_reviewGroupList_element`(`xreviewGroupList` ASC) USING BTREE,
                                               INDEX `PP_E_BEGIN_reviewGroupList_join`(`BEGIN_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_begin_reviewidentitylist
-- ----------------------------
CREATE TABLE `pp_e_begin_reviewidentitylist`  (
                                                  `BEGIN_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreviewIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_BEGIN_reviewIdentityList_element`(`xreviewIdentityList` ASC) USING BTREE,
                                                  INDEX `PP_E_BEGIN_reviewIdentityList_join`(`BEGIN_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_begin_reviewunitlist
-- ----------------------------
CREATE TABLE `pp_e_begin_reviewunitlist`  (
                                              `BEGIN_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreviewUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PP_E_BEGIN_reviewUnitList_element`(`xreviewUnitList` ASC) USING BTREE,
                                              INDEX `PP_E_BEGIN_reviewUnitList_join`(`BEGIN_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_cancel
-- ----------------------------
CREATE TABLE `pp_e_cancel`  (
                                `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                `xcreateTime` datetime NULL DEFAULT NULL,
                                `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xupdateTime` datetime NULL DEFAULT NULL,
                                `xdistributeFactor` int NULL DEFAULT NULL,
                                `xafterArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xafterArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xafterExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xafterExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xafterInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xafterInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xallowReroute` bit(1) NULL DEFAULT NULL,
                                `xallowRerouteTo` bit(1) NULL DEFAULT NULL,
                                `xbeforeArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xbeforeArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xbeforeExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xbeforeExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xbeforeInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xbeforeInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xdisplayLogScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xdisplayLogScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xextension` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xgroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xopinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xposition` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreadDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreadScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xreadScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreviewDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreviewScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xreviewScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                PRIMARY KEY (`xid`) USING BTREE,
                                UNIQUE INDEX `PP_E_CANCEL_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                INDEX `PP_E_CANCEL_form`(`xform` ASC) USING BTREE,
                                INDEX `PP_E_CANCEL_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_cancel_readdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_cancel_readdatapathlist`  (
                                                 `CANCEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xreadDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_E_CANCEL_readDataPathList_element`(`xreadDataPathList` ASC) USING BTREE,
                                                 INDEX `PP_E_CANCEL_readDataPathList_join`(`CANCEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_cancel_readgrouplist
-- ----------------------------
CREATE TABLE `pp_e_cancel_readgrouplist`  (
                                              `CANCEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PP_E_CANCEL_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                              INDEX `PP_E_CANCEL_readGroupList_join`(`CANCEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_cancel_readidentitylist
-- ----------------------------
CREATE TABLE `pp_e_cancel_readidentitylist`  (
                                                 `CANCEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_E_CANCEL_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                                 INDEX `PP_E_CANCEL_readIdentityList_join`(`CANCEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_cancel_readunitlist
-- ----------------------------
CREATE TABLE `pp_e_cancel_readunitlist`  (
                                             `CANCEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `PP_E_CANCEL_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                             INDEX `PP_E_CANCEL_readUnitList_join`(`CANCEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_cancel_reviewdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_cancel_reviewdatapathlist`  (
                                                   `CANCEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xreviewDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `PP_E_CANCEL_reviewDataPathList_element`(`xreviewDataPathList` ASC) USING BTREE,
                                                   INDEX `PP_E_CANCEL_reviewDataPathList_join`(`CANCEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_cancel_reviewgrouplist
-- ----------------------------
CREATE TABLE `pp_e_cancel_reviewgrouplist`  (
                                                `CANCEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreviewGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_CANCEL_reviewGroupList_element`(`xreviewGroupList` ASC) USING BTREE,
                                                INDEX `PP_E_CANCEL_reviewGroupList_join`(`CANCEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_cancel_reviewidentitylist
-- ----------------------------
CREATE TABLE `pp_e_cancel_reviewidentitylist`  (
                                                   `CANCEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xreviewIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `PP_E_CANCEL_reviewIdentityList_element`(`xreviewIdentityList` ASC) USING BTREE,
                                                   INDEX `PP_E_CANCEL_reviewIdentityList_join`(`CANCEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_cancel_reviewunitlist
-- ----------------------------
CREATE TABLE `pp_e_cancel_reviewunitlist`  (
                                               `CANCEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xreviewUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `PP_E_CANCEL_reviewUnitList_element`(`xreviewUnitList` ASC) USING BTREE,
                                               INDEX `PP_E_CANCEL_reviewUnitList_join`(`CANCEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_choice
-- ----------------------------
CREATE TABLE `pp_e_choice`  (
                                `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                `xcreateTime` datetime NULL DEFAULT NULL,
                                `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xupdateTime` datetime NULL DEFAULT NULL,
                                `xdistributeFactor` int NULL DEFAULT NULL,
                                `xafterArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xafterArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xafterExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xafterExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xafterInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xafterInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xallowReroute` bit(1) NULL DEFAULT NULL,
                                `xallowRerouteTo` bit(1) NULL DEFAULT NULL,
                                `xbeforeArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xbeforeArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xbeforeExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xbeforeExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xbeforeInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xbeforeInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xdisplayLogScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xdisplayLogScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xextension` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xgroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xopinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xposition` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreadDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreadScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xreadScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreviewDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreviewScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xreviewScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                PRIMARY KEY (`xid`) USING BTREE,
                                UNIQUE INDEX `PP_E_CHOICE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                INDEX `PP_E_CHOICE_form`(`xform` ASC) USING BTREE,
                                INDEX `PP_E_CHOICE_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_choice_readdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_choice_readdatapathlist`  (
                                                 `CHOICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xreadDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_E_CHOICE_readDataPathList_element`(`xreadDataPathList` ASC) USING BTREE,
                                                 INDEX `PP_E_CHOICE_readDataPathList_join`(`CHOICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_choice_readgrouplist
-- ----------------------------
CREATE TABLE `pp_e_choice_readgrouplist`  (
                                              `CHOICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PP_E_CHOICE_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                              INDEX `PP_E_CHOICE_readGroupList_join`(`CHOICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_choice_readidentitylist
-- ----------------------------
CREATE TABLE `pp_e_choice_readidentitylist`  (
                                                 `CHOICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_E_CHOICE_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                                 INDEX `PP_E_CHOICE_readIdentityList_join`(`CHOICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_choice_readunitlist
-- ----------------------------
CREATE TABLE `pp_e_choice_readunitlist`  (
                                             `CHOICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `PP_E_CHOICE_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                             INDEX `PP_E_CHOICE_readUnitList_join`(`CHOICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_choice_reviewdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_choice_reviewdatapathlist`  (
                                                   `CHOICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xreviewDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `PP_E_CHOICE_reviewDataPathList_element`(`xreviewDataPathList` ASC) USING BTREE,
                                                   INDEX `PP_E_CHOICE_reviewDataPathList_join`(`CHOICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_choice_reviewgrouplist
-- ----------------------------
CREATE TABLE `pp_e_choice_reviewgrouplist`  (
                                                `CHOICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreviewGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_CHOICE_reviewGroupList_element`(`xreviewGroupList` ASC) USING BTREE,
                                                INDEX `PP_E_CHOICE_reviewGroupList_join`(`CHOICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_choice_reviewidentitylist
-- ----------------------------
CREATE TABLE `pp_e_choice_reviewidentitylist`  (
                                                   `CHOICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xreviewIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `PP_E_CHOICE_reviewIdentityList_element`(`xreviewIdentityList` ASC) USING BTREE,
                                                   INDEX `PP_E_CHOICE_reviewIdentityList_join`(`CHOICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_choice_reviewunitlist
-- ----------------------------
CREATE TABLE `pp_e_choice_reviewunitlist`  (
                                               `CHOICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xreviewUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `PP_E_CHOICE_reviewUnitList_element`(`xreviewUnitList` ASC) USING BTREE,
                                               INDEX `PP_E_CHOICE_reviewUnitList_join`(`CHOICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_choice_routelist
-- ----------------------------
CREATE TABLE `pp_e_choice_routelist`  (
                                          `CHOICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                          `xrouteList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                          `xorderColumn` int NULL DEFAULT NULL,
                                          INDEX `PP_E_CHOICE_routeList_element`(`xrouteList` ASC) USING BTREE,
                                          INDEX `PP_E_CHOICE_routeList_join`(`CHOICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_delay
-- ----------------------------
CREATE TABLE `pp_e_delay`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xafterArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xafterExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xafterInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xallowReroute` bit(1) NULL DEFAULT NULL,
                               `xallowRerouteTo` bit(1) NULL DEFAULT NULL,
                               `xbeforeArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xbeforeExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xbeforeInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xdelayDataPath` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdelayMinute` int NULL DEFAULT NULL,
                               `xdelayScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdelayScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xdelayTime` datetime NULL DEFAULT NULL,
                               `xdelayType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdisplayLogScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdisplayLogScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xextension` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xgroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xopinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xposition` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreadDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreadScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xreadScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreviewDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreviewScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xreviewScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xroute` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xworkMinute` bit(1) NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `PP_E_DELAY_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `PP_E_DELAY_form`(`xform` ASC) USING BTREE,
                               INDEX `PP_E_DELAY_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_delay_readdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_delay_readdatapathlist`  (
                                                `DELAY_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreadDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_DELAY_readDataPathList_element`(`xreadDataPathList` ASC) USING BTREE,
                                                INDEX `PP_E_DELAY_readDataPathList_join`(`DELAY_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_delay_readgrouplist
-- ----------------------------
CREATE TABLE `pp_e_delay_readgrouplist`  (
                                             `DELAY_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `PP_E_DELAY_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                             INDEX `PP_E_DELAY_readGroupList_join`(`DELAY_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_delay_readidentitylist
-- ----------------------------
CREATE TABLE `pp_e_delay_readidentitylist`  (
                                                `DELAY_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_DELAY_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                                INDEX `PP_E_DELAY_readIdentityList_join`(`DELAY_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_delay_readunitlist
-- ----------------------------
CREATE TABLE `pp_e_delay_readunitlist`  (
                                            `DELAY_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xorderColumn` int NULL DEFAULT NULL,
                                            INDEX `PP_E_DELAY_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                            INDEX `PP_E_DELAY_readUnitList_join`(`DELAY_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_delay_reviewdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_delay_reviewdatapathlist`  (
                                                  `DELAY_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreviewDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_DELAY_reviewDataPathList_element`(`xreviewDataPathList` ASC) USING BTREE,
                                                  INDEX `PP_E_DELAY_reviewDataPathList_join`(`DELAY_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_delay_reviewgrouplist
-- ----------------------------
CREATE TABLE `pp_e_delay_reviewgrouplist`  (
                                               `DELAY_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xreviewGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `PP_E_DELAY_reviewGroupList_element`(`xreviewGroupList` ASC) USING BTREE,
                                               INDEX `PP_E_DELAY_reviewGroupList_join`(`DELAY_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_delay_reviewidentitylist
-- ----------------------------
CREATE TABLE `pp_e_delay_reviewidentitylist`  (
                                                  `DELAY_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreviewIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_DELAY_reviewIdentityList_element`(`xreviewIdentityList` ASC) USING BTREE,
                                                  INDEX `PP_E_DELAY_reviewIdentityList_join`(`DELAY_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_delay_reviewunitlist
-- ----------------------------
CREATE TABLE `pp_e_delay_reviewunitlist`  (
                                              `DELAY_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreviewUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PP_E_DELAY_reviewUnitList_element`(`xreviewUnitList` ASC) USING BTREE,
                                              INDEX `PP_E_DELAY_reviewUnitList_join`(`DELAY_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_embed
-- ----------------------------
CREATE TABLE `pp_e_embed`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xafterArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xafterExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xafterInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xallowReroute` bit(1) NULL DEFAULT NULL,
                               `xallowRerouteTo` bit(1) NULL DEFAULT NULL,
                               `xbeforeArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xbeforeExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xbeforeInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdisplayLogScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdisplayLogScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xembedCreatorType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xextension` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xgroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xinheritAttachment` bit(1) NULL DEFAULT NULL,
                               `xinheritData` bit(1) NULL DEFAULT NULL,
                               `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xopinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xposition` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreadDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreadScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xreadScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreviewDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreviewScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xreviewScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xroute` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtargetApplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtargetApplicationAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtargetApplicationName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtargetAssginDataScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtargetAssginDataScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xtargetIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtargetIdentityScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtargetIdentityScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xtargetProcess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtargetProcessAlias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtargetProcessName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtargetTitleScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtargetTitleScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xwaitUntilCompleted` bit(1) NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `PP_E_EMBED_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `PP_E_EMBED_form`(`xform` ASC) USING BTREE,
                               INDEX `PP_E_EMBED_process`(`xprocess` ASC) USING BTREE,
                               INDEX `PP_E_EMBED_targetApplication`(`xtargetApplication` ASC) USING BTREE,
                               INDEX `PP_E_EMBED_targetApplicationAlias`(`xtargetApplicationAlias` ASC) USING BTREE,
                               INDEX `PP_E_EMBED_targetApplicationName`(`xtargetApplicationName` ASC) USING BTREE,
                               INDEX `PP_E_EMBED_targetIdentity`(`xtargetIdentity` ASC) USING BTREE,
                               INDEX `PP_E_EMBED_targetProcess`(`xtargetProcess` ASC) USING BTREE,
                               INDEX `PP_E_EMBED_targetProcessAlias`(`xtargetProcessAlias` ASC) USING BTREE,
                               INDEX `PP_E_EMBED_targetProcessName`(`xtargetProcessName` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_embed_readdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_embed_readdatapathlist`  (
                                                `EMBED_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreadDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_EMBED_readDataPathList_element`(`xreadDataPathList` ASC) USING BTREE,
                                                INDEX `PP_E_EMBED_readDataPathList_join`(`EMBED_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_embed_readgrouplist
-- ----------------------------
CREATE TABLE `pp_e_embed_readgrouplist`  (
                                             `EMBED_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `PP_E_EMBED_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                             INDEX `PP_E_EMBED_readGroupList_join`(`EMBED_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_embed_readidentitylist
-- ----------------------------
CREATE TABLE `pp_e_embed_readidentitylist`  (
                                                `EMBED_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_EMBED_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                                INDEX `PP_E_EMBED_readIdentityList_join`(`EMBED_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_embed_readunitlist
-- ----------------------------
CREATE TABLE `pp_e_embed_readunitlist`  (
                                            `EMBED_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xorderColumn` int NULL DEFAULT NULL,
                                            INDEX `PP_E_EMBED_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                            INDEX `PP_E_EMBED_readUnitList_join`(`EMBED_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_embed_reviewdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_embed_reviewdatapathlist`  (
                                                  `EMBED_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreviewDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_EMBED_reviewDataPathList_element`(`xreviewDataPathList` ASC) USING BTREE,
                                                  INDEX `PP_E_EMBED_reviewDataPathList_join`(`EMBED_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_embed_reviewgrouplist
-- ----------------------------
CREATE TABLE `pp_e_embed_reviewgrouplist`  (
                                               `EMBED_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xreviewGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `PP_E_EMBED_reviewGroupList_element`(`xreviewGroupList` ASC) USING BTREE,
                                               INDEX `PP_E_EMBED_reviewGroupList_join`(`EMBED_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_embed_reviewidentitylist
-- ----------------------------
CREATE TABLE `pp_e_embed_reviewidentitylist`  (
                                                  `EMBED_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreviewIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_EMBED_reviewIdentityList_element`(`xreviewIdentityList` ASC) USING BTREE,
                                                  INDEX `PP_E_EMBED_reviewIdentityList_join`(`EMBED_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_embed_reviewunitlist
-- ----------------------------
CREATE TABLE `pp_e_embed_reviewunitlist`  (
                                              `EMBED_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreviewUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PP_E_EMBED_reviewUnitList_element`(`xreviewUnitList` ASC) USING BTREE,
                                              INDEX `PP_E_EMBED_reviewUnitList_join`(`EMBED_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_end
-- ----------------------------
CREATE TABLE `pp_e_end`  (
                             `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                             `xcreateTime` datetime NULL DEFAULT NULL,
                             `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xupdateTime` datetime NULL DEFAULT NULL,
                             `xdistributeFactor` int NULL DEFAULT NULL,
                             `xafterArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xafterArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xafterExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xafterExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xafterInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xafterInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xallowReroute` bit(1) NULL DEFAULT NULL,
                             `xallowRerouteTo` bit(1) NULL DEFAULT NULL,
                             `xallowRollback` bit(1) NULL DEFAULT NULL,
                             `xbeforeArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xbeforeArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xbeforeExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xbeforeExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xbeforeInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xbeforeInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdisplayLogScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdisplayLogScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xextension` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xgroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xopinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xposition` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xreadDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xreadScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xreadScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xreviewDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xreviewScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xreviewScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             PRIMARY KEY (`xid`) USING BTREE,
                             UNIQUE INDEX `PP_E_END_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                             INDEX `PP_E_END_form`(`xform` ASC) USING BTREE,
                             INDEX `PP_E_END_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_end_readdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_end_readdatapathlist`  (
                                              `END_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreadDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PP_E_END_readDataPathList_element`(`xreadDataPathList` ASC) USING BTREE,
                                              INDEX `PP_E_END_readDataPathList_join`(`END_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_end_readgrouplist
-- ----------------------------
CREATE TABLE `pp_e_end_readgrouplist`  (
                                           `END_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                           `xorderColumn` int NULL DEFAULT NULL,
                                           INDEX `PP_E_END_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                           INDEX `PP_E_END_readGroupList_join`(`END_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_end_readidentitylist
-- ----------------------------
CREATE TABLE `pp_e_end_readidentitylist`  (
                                              `END_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PP_E_END_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                              INDEX `PP_E_END_readIdentityList_join`(`END_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_end_readunitlist
-- ----------------------------
CREATE TABLE `pp_e_end_readunitlist`  (
                                          `END_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                          `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                          `xorderColumn` int NULL DEFAULT NULL,
                                          INDEX `PP_E_END_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                          INDEX `PP_E_END_readUnitList_join`(`END_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_end_reviewdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_end_reviewdatapathlist`  (
                                                `END_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreviewDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_END_reviewDataPathList_element`(`xreviewDataPathList` ASC) USING BTREE,
                                                INDEX `PP_E_END_reviewDataPathList_join`(`END_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_end_reviewgrouplist
-- ----------------------------
CREATE TABLE `pp_e_end_reviewgrouplist`  (
                                             `END_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xreviewGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `PP_E_END_reviewGroupList_element`(`xreviewGroupList` ASC) USING BTREE,
                                             INDEX `PP_E_END_reviewGroupList_join`(`END_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_end_reviewidentitylist
-- ----------------------------
CREATE TABLE `pp_e_end_reviewidentitylist`  (
                                                `END_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreviewIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_END_reviewIdentityList_element`(`xreviewIdentityList` ASC) USING BTREE,
                                                INDEX `PP_E_END_reviewIdentityList_join`(`END_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_end_reviewunitlist
-- ----------------------------
CREATE TABLE `pp_e_end_reviewunitlist`  (
                                            `END_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xreviewUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xorderColumn` int NULL DEFAULT NULL,
                                            INDEX `PP_E_END_reviewUnitList_element`(`xreviewUnitList` ASC) USING BTREE,
                                            INDEX `PP_E_END_reviewUnitList_join`(`END_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_file
-- ----------------------------
CREATE TABLE `pp_e_file`  (
                              `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                              `xcreateTime` datetime NULL DEFAULT NULL,
                              `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xupdateTime` datetime NULL DEFAULT NULL,
                              `xdistributeFactor` int NULL DEFAULT NULL,
                              `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                            --   `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              `xurl` varchar(2048) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xfileName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xlastUpdateTime` datetime NULL DEFAULT NULL,
                              `xlength` bigint NULL DEFAULT NULL,
                              `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              PRIMARY KEY (`xid`) USING BTREE,
                              UNIQUE INDEX `PP_E_FILE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                              INDEX `PP_E_FILE_application`(`xapplication` ASC) USING BTREE,
                              INDEX `PP_E_FILE_length`(`xlength` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_form
-- ----------------------------
CREATE TABLE `pp_e_form`  (
                              `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                              `xcreateTime` datetime NULL DEFAULT NULL,
                              `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xupdateTime` datetime NULL DEFAULT NULL,
                              `xdistributeFactor` int NULL DEFAULT NULL,
                              `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcategory` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xhasMobile` bit(1) NULL DEFAULT NULL,
                              `xicon` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xlastUpdateTime` datetime NULL DEFAULT NULL,
                              `xmobileData` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              PRIMARY KEY (`xid`) USING BTREE,
                              UNIQUE INDEX `PP_E_FORM_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                              INDEX `PP_E_FORM_application`(`xapplication` ASC) USING BTREE,
                              INDEX `PP_E_FORM_category`(`xcategory` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_formfield
-- ----------------------------
CREATE TABLE `pp_e_formfield`  (
                                   `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                   `xcreateTime` datetime NULL DEFAULT NULL,
                                   `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xupdateTime` datetime NULL DEFAULT NULL,
                                   `xdistributeFactor` int NULL DEFAULT NULL,
                                   `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xdataType` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   PRIMARY KEY (`xid`) USING BTREE,
                                   UNIQUE INDEX `PP_E_FORMFIELD_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                   INDEX `PP_E_FORMFIELD_application`(`xapplication` ASC) USING BTREE,
                                   INDEX `PP_E_FORMFIELD_form`(`xform` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_formversion
-- ----------------------------
CREATE TABLE `pp_e_formversion`  (
                                     `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                     `xcreateTime` datetime NULL DEFAULT NULL,
                                     `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xupdateTime` datetime NULL DEFAULT NULL,
                                     `xdistributeFactor` int NULL DEFAULT NULL,
                                     `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                     `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     PRIMARY KEY (`xid`) USING BTREE,
                                     UNIQUE INDEX `PP_E_FORMVERSION_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                     INDEX `PP_E_FORMVERSION_form`(`xform` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_invoke
-- ----------------------------
CREATE TABLE `pp_e_invoke`  (
                                `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                `xcreateTime` datetime NULL DEFAULT NULL,
                                `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xupdateTime` datetime NULL DEFAULT NULL,
                                `xdistributeFactor` int NULL DEFAULT NULL,
                                `xafterArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xafterArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xafterExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xafterExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xafterInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xafterInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xallowReroute` bit(1) NULL DEFAULT NULL,
                                `xallowRerouteTo` bit(1) NULL DEFAULT NULL,
                                `xasync` bit(1) NULL DEFAULT NULL,
                                `xbeforeArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xbeforeArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xbeforeExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xbeforeExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xbeforeInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xbeforeInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xdisplayLogScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xdisplayLogScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xextension` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xgroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xinternal` bit(1) NULL DEFAULT NULL,
                                `xinternalProject` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xinvokeMode` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xjaxrsAddress` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xjaxrsBodyScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xjaxrsBodyScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xjaxrsContentType` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xjaxrsHeadScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xjaxrsHeadScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xjaxrsMethod` varchar(8) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xjaxrsParameterScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xjaxrsParameterScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xjaxrsResponseScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xjaxrsResponseScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xjaxrsWithCipher` bit(1) NULL DEFAULT NULL,
                                `xjaxwsAddress` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xjaxwsMethod` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xjaxwsParameterScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xjaxwsParameterScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xjaxwsResponseScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xjaxwsResponseScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xopinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xposition` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreadDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreadScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xreadScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreviewDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreviewScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xreviewScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xroute` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                PRIMARY KEY (`xid`) USING BTREE,
                                UNIQUE INDEX `PP_E_INVOKE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                INDEX `PP_E_INVOKE_form`(`xform` ASC) USING BTREE,
                                INDEX `PP_E_INVOKE_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_invoke_readdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_invoke_readdatapathlist`  (
                                                 `INVOKE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xreadDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_E_INVOKE_readDataPathList_element`(`xreadDataPathList` ASC) USING BTREE,
                                                 INDEX `PP_E_INVOKE_readDataPathList_join`(`INVOKE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_invoke_readgrouplist
-- ----------------------------
CREATE TABLE `pp_e_invoke_readgrouplist`  (
                                              `INVOKE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PP_E_INVOKE_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                              INDEX `PP_E_INVOKE_readGroupList_join`(`INVOKE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_invoke_readidentitylist
-- ----------------------------
CREATE TABLE `pp_e_invoke_readidentitylist`  (
                                                 `INVOKE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_E_INVOKE_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                                 INDEX `PP_E_INVOKE_readIdentityList_join`(`INVOKE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_invoke_readunitlist
-- ----------------------------
CREATE TABLE `pp_e_invoke_readunitlist`  (
                                             `INVOKE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `PP_E_INVOKE_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                             INDEX `PP_E_INVOKE_readUnitList_join`(`INVOKE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_invoke_reviewdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_invoke_reviewdatapathlist`  (
                                                   `INVOKE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xreviewDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `PP_E_INVOKE_reviewDataPathList_element`(`xreviewDataPathList` ASC) USING BTREE,
                                                   INDEX `PP_E_INVOKE_reviewDataPathList_join`(`INVOKE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_invoke_reviewgrouplist
-- ----------------------------
CREATE TABLE `pp_e_invoke_reviewgrouplist`  (
                                                `INVOKE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreviewGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_INVOKE_reviewGroupList_element`(`xreviewGroupList` ASC) USING BTREE,
                                                INDEX `PP_E_INVOKE_reviewGroupList_join`(`INVOKE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_invoke_reviewidentitylist
-- ----------------------------
CREATE TABLE `pp_e_invoke_reviewidentitylist`  (
                                                   `INVOKE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xreviewIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `PP_E_INVOKE_reviewIdentityList_element`(`xreviewIdentityList` ASC) USING BTREE,
                                                   INDEX `PP_E_INVOKE_reviewIdentityList_join`(`INVOKE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_invoke_reviewunitlist
-- ----------------------------
CREATE TABLE `pp_e_invoke_reviewunitlist`  (
                                               `INVOKE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xreviewUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `PP_E_INVOKE_reviewUnitList_element`(`xreviewUnitList` ASC) USING BTREE,
                                               INDEX `PP_E_INVOKE_reviewUnitList_join`(`INVOKE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_manual
-- ----------------------------
CREATE TABLE `pp_e_manual`  (
                                `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                `xcreateTime` datetime NULL DEFAULT NULL,
                                `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xupdateTime` datetime NULL DEFAULT NULL,
                                `xdistributeFactor` int NULL DEFAULT NULL,
                                `xafterArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xafterArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xafterExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xafterExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xafterInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xafterInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xallowAddSplit` bit(1) NULL DEFAULT NULL,
                                `xallowDeleteWork` bit(1) NULL DEFAULT NULL,
                                `xallowPause` bit(1) NULL DEFAULT NULL,
                                `xallowPress` bit(1) NULL DEFAULT NULL,
                                `xallowRapid` bit(1) NULL DEFAULT NULL,
                                `xallowReroute` bit(1) NULL DEFAULT NULL,
                                `xallowRerouteTo` bit(1) NULL DEFAULT NULL,
                                `xallowReset` bit(1) NULL DEFAULT NULL,
                                `xallowRetract` bit(1) NULL DEFAULT NULL,
                                `xallowRollback` bit(1) NULL DEFAULT NULL,
                                `xbeforeArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xbeforeArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xbeforeExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xbeforeExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xbeforeInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xbeforeInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xdisplayLogScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xdisplayLogScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xextension` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xgroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xmanualAfterTaskScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xmanualAfterTaskScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xmanualBeforeTaskScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xmanualBeforeTaskScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xmanualMergeSameJobActivity` bit(1) NULL DEFAULT NULL,
                                `xmanualMode` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xmanualStayScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xmanualStayScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xmanualUncompletedTaskToRead` bit(1) NULL DEFAULT NULL,
                                `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xopinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xposition` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreadDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreadScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xreadScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xresetCount` int NULL DEFAULT NULL,
                                `xresetRange` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xresetRangeScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreviewDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xreviewScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xreviewScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xtaskDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xtaskExpireDay` int NULL DEFAULT NULL,
                                `xtaskExpireHour` int NULL DEFAULT NULL,
                                `xtaskExpireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xtaskExpireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xtaskExpireType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xtaskExpireWorkTime` bit(1) NULL DEFAULT NULL,
                                `xtaskScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xtaskScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                PRIMARY KEY (`xid`) USING BTREE,
                                UNIQUE INDEX `PP_E_MANUAL_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                INDEX `PP_E_MANUAL_form`(`xform` ASC) USING BTREE,
                                INDEX `PP_E_MANUAL_manualMode`(`xmanualMode` ASC) USING BTREE,
                                INDEX `PP_E_MANUAL_process`(`xprocess` ASC) USING BTREE,
                                INDEX `PP_E_MANUAL_taskExpireType`(`xtaskExpireType` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_manual_readdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_manual_readdatapathlist`  (
                                                 `MANUAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xreadDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_E_MANUAL_readDataPathList_element`(`xreadDataPathList` ASC) USING BTREE,
                                                 INDEX `PP_E_MANUAL_readDataPathList_join`(`MANUAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_manual_readgrouplist
-- ----------------------------
CREATE TABLE `pp_e_manual_readgrouplist`  (
                                              `MANUAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PP_E_MANUAL_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                              INDEX `PP_E_MANUAL_readGroupList_join`(`MANUAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_manual_readidentitylist
-- ----------------------------
CREATE TABLE `pp_e_manual_readidentitylist`  (
                                                 `MANUAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_E_MANUAL_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                                 INDEX `PP_E_MANUAL_readIdentityList_join`(`MANUAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_manual_readunitlist
-- ----------------------------
CREATE TABLE `pp_e_manual_readunitlist`  (
                                             `MANUAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `PP_E_MANUAL_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                             INDEX `PP_E_MANUAL_readUnitList_join`(`MANUAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_manual_reviewdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_manual_reviewdatapathlist`  (
                                                   `MANUAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xreviewDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `PP_E_MANUAL_reviewDataPathList_element`(`xreviewDataPathList` ASC) USING BTREE,
                                                   INDEX `PP_E_MANUAL_reviewDataPathList_join`(`MANUAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_manual_reviewgrouplist
-- ----------------------------
CREATE TABLE `pp_e_manual_reviewgrouplist`  (
                                                `MANUAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreviewGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_MANUAL_reviewGroupList_element`(`xreviewGroupList` ASC) USING BTREE,
                                                INDEX `PP_E_MANUAL_reviewGroupList_join`(`MANUAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_manual_reviewidentitylist
-- ----------------------------
CREATE TABLE `pp_e_manual_reviewidentitylist`  (
                                                   `MANUAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xreviewIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `PP_E_MANUAL_reviewIdentityList_element`(`xreviewIdentityList` ASC) USING BTREE,
                                                   INDEX `PP_E_MANUAL_reviewIdentityList_join`(`MANUAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_manual_reviewunitlist
-- ----------------------------
CREATE TABLE `pp_e_manual_reviewunitlist`  (
                                               `MANUAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xreviewUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `PP_E_MANUAL_reviewUnitList_element`(`xreviewUnitList` ASC) USING BTREE,
                                               INDEX `PP_E_MANUAL_reviewUnitList_join`(`MANUAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_manual_routelist
-- ----------------------------
CREATE TABLE `pp_e_manual_routelist`  (
                                          `MANUAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                          `xrouteList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                          `xorderColumn` int NULL DEFAULT NULL,
                                          INDEX `PP_E_MANUAL_routeList_element`(`xrouteList` ASC) USING BTREE,
                                          INDEX `PP_E_MANUAL_routeList_join`(`MANUAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_manual_taskdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_manual_taskdatapathlist`  (
                                                 `MANUAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xtaskDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_E_MANUAL_taskDataPathList_element`(`xtaskDataPathList` ASC) USING BTREE,
                                                 INDEX `PP_E_MANUAL_taskDataPathList_join`(`MANUAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_manual_taskgrouplist
-- ----------------------------
CREATE TABLE `pp_e_manual_taskgrouplist`  (
                                              `MANUAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xtaskGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PP_E_MANUAL_taskGroupList_element`(`xtaskGroupList` ASC) USING BTREE,
                                              INDEX `PP_E_MANUAL_taskGroupList_join`(`MANUAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_manual_taskidentitylist
-- ----------------------------
CREATE TABLE `pp_e_manual_taskidentitylist`  (
                                                 `MANUAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xtaskIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_E_MANUAL_taskIdentityList_element`(`xtaskIdentityList` ASC) USING BTREE,
                                                 INDEX `PP_E_MANUAL_taskIdentityList_join`(`MANUAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_manual_taskunitlist
-- ----------------------------
CREATE TABLE `pp_e_manual_taskunitlist`  (
                                             `MANUAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xtaskUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `PP_E_MANUAL_taskUnitList_element`(`xtaskUnitList` ASC) USING BTREE,
                                             INDEX `PP_E_MANUAL_taskUnitList_join`(`MANUAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_mapping
-- ----------------------------
CREATE TABLE `pp_e_mapping`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xenable` bit(1) NULL DEFAULT NULL,
                                 `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xtableName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `PP_E_MAPPING_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                 INDEX `PP_E_MAPPING_application`(`xapplication` ASC) USING BTREE,
                                 INDEX `PP_E_MAPPING_process`(`xprocess` ASC) USING BTREE,
                                 INDEX `PP_E_MAPPING_tableName`(`xtableName` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_merge
-- ----------------------------
CREATE TABLE `pp_e_merge`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xafterArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xafterExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xafterInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xallowReroute` bit(1) NULL DEFAULT NULL,
                               `xallowRerouteTo` bit(1) NULL DEFAULT NULL,
                               `xbeforeArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xbeforeExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xbeforeInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdisplayLogScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdisplayLogScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xextension` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xgroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xopinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xposition` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreadDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreadScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xreadScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreviewDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreviewScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xreviewScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xroute` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `PP_E_MERGE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `PP_E_MERGE_form`(`xform` ASC) USING BTREE,
                               INDEX `PP_E_MERGE_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_merge_readdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_merge_readdatapathlist`  (
                                                `MERGE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreadDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_MERGE_readDataPathList_element`(`xreadDataPathList` ASC) USING BTREE,
                                                INDEX `PP_E_MERGE_readDataPathList_join`(`MERGE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_merge_readgrouplist
-- ----------------------------
CREATE TABLE `pp_e_merge_readgrouplist`  (
                                             `MERGE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `PP_E_MERGE_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                             INDEX `PP_E_MERGE_readGroupList_join`(`MERGE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_merge_readidentitylist
-- ----------------------------
CREATE TABLE `pp_e_merge_readidentitylist`  (
                                                `MERGE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_MERGE_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                                INDEX `PP_E_MERGE_readIdentityList_join`(`MERGE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_merge_readunitlist
-- ----------------------------
CREATE TABLE `pp_e_merge_readunitlist`  (
                                            `MERGE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xorderColumn` int NULL DEFAULT NULL,
                                            INDEX `PP_E_MERGE_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                            INDEX `PP_E_MERGE_readUnitList_join`(`MERGE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_merge_reviewdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_merge_reviewdatapathlist`  (
                                                  `MERGE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreviewDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_MERGE_reviewDataPathList_element`(`xreviewDataPathList` ASC) USING BTREE,
                                                  INDEX `PP_E_MERGE_reviewDataPathList_join`(`MERGE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_merge_reviewgrouplist
-- ----------------------------
CREATE TABLE `pp_e_merge_reviewgrouplist`  (
                                               `MERGE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xreviewGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `PP_E_MERGE_reviewGroupList_element`(`xreviewGroupList` ASC) USING BTREE,
                                               INDEX `PP_E_MERGE_reviewGroupList_join`(`MERGE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_merge_reviewidentitylist
-- ----------------------------
CREATE TABLE `pp_e_merge_reviewidentitylist`  (
                                                  `MERGE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreviewIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_MERGE_reviewIdentityList_element`(`xreviewIdentityList` ASC) USING BTREE,
                                                  INDEX `PP_E_MERGE_reviewIdentityList_join`(`MERGE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_merge_reviewunitlist
-- ----------------------------
CREATE TABLE `pp_e_merge_reviewunitlist`  (
                                              `MERGE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreviewUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PP_E_MERGE_reviewUnitList_element`(`xreviewUnitList` ASC) USING BTREE,
                                              INDEX `PP_E_MERGE_reviewUnitList_join`(`MERGE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_parallel
-- ----------------------------
CREATE TABLE `pp_e_parallel`  (
                                  `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                  `xcreateTime` datetime NULL DEFAULT NULL,
                                  `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xupdateTime` datetime NULL DEFAULT NULL,
                                  `xdistributeFactor` int NULL DEFAULT NULL,
                                  `xafterArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xafterArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xafterExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xafterExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xafterInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xafterInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xallowReroute` bit(1) NULL DEFAULT NULL,
                                  `xallowRerouteTo` bit(1) NULL DEFAULT NULL,
                                  `xbeforeArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xbeforeArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xbeforeExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xbeforeExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xbeforeInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xbeforeInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xdisplayLogScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xdisplayLogScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xextension` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xgroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xopinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xposition` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xreadDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xreadScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xreadScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xreviewDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xreviewScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xreviewScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  PRIMARY KEY (`xid`) USING BTREE,
                                  UNIQUE INDEX `PP_E_PARALLEL_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                  INDEX `PP_E_PARALLEL_form`(`xform` ASC) USING BTREE,
                                  INDEX `PP_E_PARALLEL_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_parallel_readdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_parallel_readdatapathlist`  (
                                                   `PARALLEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xreadDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `PP_E_PARALLEL_readDataPathList_element`(`xreadDataPathList` ASC) USING BTREE,
                                                   INDEX `PP_E_PARALLEL_readDataPathList_join`(`PARALLEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_parallel_readgrouplist
-- ----------------------------
CREATE TABLE `pp_e_parallel_readgrouplist`  (
                                                `PARALLEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_PARALLEL_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                                INDEX `PP_E_PARALLEL_readGroupList_join`(`PARALLEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_parallel_readidentitylist
-- ----------------------------
CREATE TABLE `pp_e_parallel_readidentitylist`  (
                                                   `PARALLEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `PP_E_PARALLEL_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                                   INDEX `PP_E_PARALLEL_readIdentityList_join`(`PARALLEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_parallel_readunitlist
-- ----------------------------
CREATE TABLE `pp_e_parallel_readunitlist`  (
                                               `PARALLEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `PP_E_PARALLEL_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                               INDEX `PP_E_PARALLEL_readUnitList_join`(`PARALLEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_parallel_reviewdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_parallel_reviewdatapathlist`  (
                                                     `PARALLEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xreviewDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xorderColumn` int NULL DEFAULT NULL,
                                                     INDEX `PP_E_PARALLEL_reviewDataPathList_element`(`xreviewDataPathList` ASC) USING BTREE,
                                                     INDEX `PP_E_PARALLEL_reviewDataPathList_join`(`PARALLEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_parallel_reviewgrouplist
-- ----------------------------
CREATE TABLE `pp_e_parallel_reviewgrouplist`  (
                                                  `PARALLEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreviewGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_PARALLEL_reviewGroupList_element`(`xreviewGroupList` ASC) USING BTREE,
                                                  INDEX `PP_E_PARALLEL_reviewGroupList_join`(`PARALLEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_parallel_reviewidentitylist
-- ----------------------------
CREATE TABLE `pp_e_parallel_reviewidentitylist`  (
                                                     `PARALLEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xreviewIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xorderColumn` int NULL DEFAULT NULL,
                                                     INDEX `PP_E_PARALLEL_reviewIdentityList_element`(`xreviewIdentityList` ASC) USING BTREE,
                                                     INDEX `PP_E_PARALLEL_reviewIdentityList_join`(`PARALLEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_parallel_reviewunitlist
-- ----------------------------
CREATE TABLE `pp_e_parallel_reviewunitlist`  (
                                                 `PARALLEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xreviewUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_E_PARALLEL_reviewUnitList_element`(`xreviewUnitList` ASC) USING BTREE,
                                                 INDEX `PP_E_PARALLEL_reviewUnitList_join`(`PARALLEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_parallel_routelist
-- ----------------------------
CREATE TABLE `pp_e_parallel_routelist`  (
                                            `PARALLEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xrouteList` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xorderColumn` int NULL DEFAULT NULL,
                                            INDEX `PP_E_PARALLEL_routeList_element`(`xrouteList` ASC) USING BTREE,
                                            INDEX `PP_E_PARALLEL_routeList_join`(`PARALLEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_process
-- ----------------------------
CREATE TABLE `pp_e_process`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xafterArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xafterArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xafterBeginScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xafterBeginScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xafterEndScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xafterEndScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xafterExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xafterExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xafterInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xafterInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xbeforeArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xbeforeArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xbeforeExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xbeforeExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xbeforeInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xbeforeInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xcategory` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcheckDraft` bit(1) NULL DEFAULT NULL,
                                 `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdefaultStartMode` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xeditionDes` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xeditionEnable` bit(1) NULL DEFAULT NULL,
                                 `xeditionName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xeditionNumber` double NULL DEFAULT NULL,
                                 `xexpireDay` int NULL DEFAULT NULL,
                                 `xexpireHour` int NULL DEFAULT NULL,
                                 `xexpireType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xexpireWorkTime` bit(1) NULL DEFAULT NULL,
                                 `xicon` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xlastUpdateTime` datetime NULL DEFAULT NULL,
                                 `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xprojection` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xprojectionFully` bit(1) NULL DEFAULT NULL,
                                 `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xrouteNameAsOpinion` bit(1) NULL DEFAULT NULL,
                                 `xserialActivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xserialPhase` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xserialTexture` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xstartableTerminal` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `PP_E_PROCESS_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_process_controllerlist
-- ----------------------------
CREATE TABLE `pp_e_process_controllerlist`  (
                                                `PROCESS_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xcontrollerList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_PROCESS_controllerList_element`(`xcontrollerList` ASC) USING BTREE,
                                                INDEX `PP_E_PROCESS_controllerList_join`(`PROCESS_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_process_startablegrouplist
-- ----------------------------
CREATE TABLE `pp_e_process_startablegrouplist`  (
                                                    `PROCESS_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xstartableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `PP_E_PROCESS_startableGroupList_element`(`xstartableGroupList` ASC) USING BTREE,
                                                    INDEX `PP_E_PROCESS_startableGroupList_join`(`PROCESS_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_process_startableidentitylist
-- ----------------------------
CREATE TABLE `pp_e_process_startableidentitylist`  (
                                                       `PROCESS_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xstartableIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xorderColumn` int NULL DEFAULT NULL,
                                                       INDEX `PP_E_PROCESS_startableIdentityList_element`(`xstartableIdentityList` ASC) USING BTREE,
                                                       INDEX `PP_E_PROCESS_startableIdentityList_join`(`PROCESS_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_process_startableunitlist
-- ----------------------------
CREATE TABLE `pp_e_process_startableunitlist`  (
                                                   `PROCESS_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xstartableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `PP_E_PROCESS_startableUnitList_element`(`xstartableUnitList` ASC) USING BTREE,
                                                   INDEX `PP_E_PROCESS_startableUnitList_join`(`PROCESS_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_processversion
-- ----------------------------
CREATE TABLE `pp_e_processversion`  (
                                        `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                        `xcreateTime` datetime NULL DEFAULT NULL,
                                        `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xupdateTime` datetime NULL DEFAULT NULL,
                                        `xdistributeFactor` int NULL DEFAULT NULL,
                                        `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                        `xperson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                        PRIMARY KEY (`xid`) USING BTREE,
                                        UNIQUE INDEX `PP_E_PROCESSVERSION_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                        INDEX `PP_E_PROCESSVERSION_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_publish
-- ----------------------------
CREATE TABLE `pp_e_publish`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xafterArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xafterArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xafterExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xafterExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xafterInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xafterInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xallowReroute` bit(1) NULL DEFAULT NULL,
                                 `xallowRerouteTo` bit(1) NULL DEFAULT NULL,
                                 `xauthorDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xbeforeArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xbeforeArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xbeforeExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xbeforeExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xbeforeInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xbeforeInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xcategoryId` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcategoryIdDataPath` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcategorySelectType` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcmsCreatorIdentity` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcmsCreatorScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xcmsCreatorScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xpublishCmsCreatorType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdisplayLogScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdisplayLogScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xextension` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xgroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xinheritAttachment` bit(1) NULL DEFAULT NULL,
                                 `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xnotifyDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xopinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xpictureDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xposition` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xpublishTarget` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xreadDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xreadScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xreadScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xreaderDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xreviewDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xreviewScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xreviewScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xroute` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xtargetAssignDataScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xtargetAssignDataScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xtitleDataPath` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xuseProcessForm` bit(1) NULL DEFAULT NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `PP_E_PUBLISH_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                 INDEX `PP_E_PUBLISH_form`(`xform` ASC) USING BTREE,
                                 INDEX `PP_E_PUBLISH_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_publish_readdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_publish_readdatapathlist`  (
                                                  `PUBLISH_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreadDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_PUBLISH_readDataPathList_element`(`xreadDataPathList` ASC) USING BTREE,
                                                  INDEX `PP_E_PUBLISH_readDataPathList_join`(`PUBLISH_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_publish_readgrouplist
-- ----------------------------
CREATE TABLE `pp_e_publish_readgrouplist`  (
                                               `PUBLISH_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `PP_E_PUBLISH_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                               INDEX `PP_E_PUBLISH_readGroupList_join`(`PUBLISH_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_publish_readidentitylist
-- ----------------------------
CREATE TABLE `pp_e_publish_readidentitylist`  (
                                                  `PUBLISH_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_PUBLISH_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                                  INDEX `PP_E_PUBLISH_readIdentityList_join`(`PUBLISH_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_publish_readunitlist
-- ----------------------------
CREATE TABLE `pp_e_publish_readunitlist`  (
                                              `PUBLISH_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PP_E_PUBLISH_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                              INDEX `PP_E_PUBLISH_readUnitList_join`(`PUBLISH_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_publish_reviewdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_publish_reviewdatapathlist`  (
                                                    `PUBLISH_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xreviewDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `PP_E_PUBLISH_reviewDataPathList_element`(`xreviewDataPathList` ASC) USING BTREE,
                                                    INDEX `PP_E_PUBLISH_reviewDataPathList_join`(`PUBLISH_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_publish_reviewgrouplist
-- ----------------------------
CREATE TABLE `pp_e_publish_reviewgrouplist`  (
                                                 `PUBLISH_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xreviewGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_E_PUBLISH_reviewGroupList_element`(`xreviewGroupList` ASC) USING BTREE,
                                                 INDEX `PP_E_PUBLISH_reviewGroupList_join`(`PUBLISH_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_publish_reviewidentitylist
-- ----------------------------
CREATE TABLE `pp_e_publish_reviewidentitylist`  (
                                                    `PUBLISH_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xreviewIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `PP_E_PUBLISH_reviewIdentityList_element`(`xreviewIdentityList` ASC) USING BTREE,
                                                    INDEX `PP_E_PUBLISH_reviewIdentityList_join`(`PUBLISH_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_publish_reviewunitlist
-- ----------------------------
CREATE TABLE `pp_e_publish_reviewunitlist`  (
                                                `PUBLISH_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreviewUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_PUBLISH_reviewUnitList_element`(`xreviewUnitList` ASC) USING BTREE,
                                                INDEX `PP_E_PUBLISH_reviewUnitList_join`(`PUBLISH_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_route
-- ----------------------------
CREATE TABLE `pp_e_route`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xactivity` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xactivityType` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xappendTaskIdentityScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xappendTaskIdentityScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xappendTaskIdentityType` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdecisionOpinion` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdisplayNameScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdisplayNameScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xhiddenScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xhiddenScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xopinion` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xopinionRequired` bit(1) NULL DEFAULT NULL,
                               `xorderNumber` int NULL DEFAULT NULL,
                               `xpassExpired` bit(1) NULL DEFAULT NULL,
                               `xpassSameTarget` bit(1) NULL DEFAULT NULL,
                               `xposition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xscript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xscriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xselectConfig` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xsole` bit(1) NULL DEFAULT NULL,
                               `xtrack` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtype` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xvalidationScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xvalidationScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `PP_E_ROUTE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `PP_E_ROUTE_activity`(`xactivity` ASC) USING BTREE,
                               INDEX `PP_E_ROUTE_activityType`(`xactivityType` ASC) USING BTREE,
                               INDEX `PP_E_ROUTE_orderNumber`(`xorderNumber` ASC) USING BTREE,
                               INDEX `PP_E_ROUTE_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_script
-- ----------------------------
CREATE TABLE `pp_e_script`  (
                                `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                `xcreateTime` datetime NULL DEFAULT NULL,
                                `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xupdateTime` datetime NULL DEFAULT NULL,
                                `xdistributeFactor` int NULL DEFAULT NULL,
                                `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xlastUpdateTime` datetime NULL DEFAULT NULL,
                                `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                `xtext` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                `xvalidated` bit(1) NULL DEFAULT NULL,
                                PRIMARY KEY (`xid`) USING BTREE,
                                UNIQUE INDEX `PP_E_SCRIPT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                INDEX `PP_E_SCRIPT_application`(`xapplication` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_script_dependscriptlist
-- ----------------------------
CREATE TABLE `pp_e_script_dependscriptlist`  (
                                                 `SCRIPT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xdependScriptList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_E_SCRIPT_dependScriptList_element`(`xdependScriptList` ASC) USING BTREE,
                                                 INDEX `PP_E_SCRIPT_dependScriptList_join`(`SCRIPT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_service
-- ----------------------------
CREATE TABLE `pp_e_service`  (
                                 `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                 `xcreateTime` datetime NULL DEFAULT NULL,
                                 `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xupdateTime` datetime NULL DEFAULT NULL,
                                 `xdistributeFactor` int NULL DEFAULT NULL,
                                 `xafterArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xafterArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xafterExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xafterExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xafterInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xafterInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xallowReroute` bit(1) NULL DEFAULT NULL,
                                 `xallowRerouteTo` bit(1) NULL DEFAULT NULL,
                                 `xbeforeArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xbeforeArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xbeforeExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xbeforeExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xbeforeInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xbeforeInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdisplayLogScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xdisplayLogScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xextension` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xgroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xopinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xposition` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xreadDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xreadScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xreadScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xreviewDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xreviewScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xreviewScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 `xroute` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xscript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                 `xscriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                 PRIMARY KEY (`xid`) USING BTREE,
                                 UNIQUE INDEX `PP_E_SERVICE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                 INDEX `PP_E_SERVICE_form`(`xform` ASC) USING BTREE,
                                 INDEX `PP_E_SERVICE_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_service_readdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_service_readdatapathlist`  (
                                                  `SERVICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreadDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_SERVICE_readDataPathList_element`(`xreadDataPathList` ASC) USING BTREE,
                                                  INDEX `PP_E_SERVICE_readDataPathList_join`(`SERVICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_service_readgrouplist
-- ----------------------------
CREATE TABLE `pp_e_service_readgrouplist`  (
                                               `SERVICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `PP_E_SERVICE_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                               INDEX `PP_E_SERVICE_readGroupList_join`(`SERVICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_service_readidentitylist
-- ----------------------------
CREATE TABLE `pp_e_service_readidentitylist`  (
                                                  `SERVICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_SERVICE_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                                  INDEX `PP_E_SERVICE_readIdentityList_join`(`SERVICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_service_readunitlist
-- ----------------------------
CREATE TABLE `pp_e_service_readunitlist`  (
                                              `SERVICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PP_E_SERVICE_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                              INDEX `PP_E_SERVICE_readUnitList_join`(`SERVICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_service_reviewdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_service_reviewdatapathlist`  (
                                                    `SERVICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xreviewDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `PP_E_SERVICE_reviewDataPathList_element`(`xreviewDataPathList` ASC) USING BTREE,
                                                    INDEX `PP_E_SERVICE_reviewDataPathList_join`(`SERVICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_service_reviewgrouplist
-- ----------------------------
CREATE TABLE `pp_e_service_reviewgrouplist`  (
                                                 `SERVICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xreviewGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PP_E_SERVICE_reviewGroupList_element`(`xreviewGroupList` ASC) USING BTREE,
                                                 INDEX `PP_E_SERVICE_reviewGroupList_join`(`SERVICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_service_reviewidentitylist
-- ----------------------------
CREATE TABLE `pp_e_service_reviewidentitylist`  (
                                                    `SERVICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xreviewIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `PP_E_SERVICE_reviewIdentityList_element`(`xreviewIdentityList` ASC) USING BTREE,
                                                    INDEX `PP_E_SERVICE_reviewIdentityList_join`(`SERVICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_service_reviewunitlist
-- ----------------------------
CREATE TABLE `pp_e_service_reviewunitlist`  (
                                                `SERVICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreviewUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_SERVICE_reviewUnitList_element`(`xreviewUnitList` ASC) USING BTREE,
                                                INDEX `PP_E_SERVICE_reviewUnitList_join`(`SERVICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_service_trustaddresslist
-- ----------------------------
CREATE TABLE `pp_e_service_trustaddresslist`  (
                                                  `SERVICE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xtrustAddressList` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_SERVICE_trustAddressList_element`(`xtrustAddressList` ASC) USING BTREE,
                                                  INDEX `PP_E_SERVICE_trustAddressList_join`(`SERVICE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_split
-- ----------------------------
CREATE TABLE `pp_e_split`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xafterArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xafterExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xafterInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xafterInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xallowReroute` bit(1) NULL DEFAULT NULL,
                               `xallowRerouteTo` bit(1) NULL DEFAULT NULL,
                               `xbeforeArriveScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeArriveScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xbeforeExecuteScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeExecuteScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xbeforeInquireScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xbeforeInquireScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdisplayLogScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdisplayLogScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xedition` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xextension` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xform` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xgroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xopinionGroup` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xposition` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xprocess` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreadDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreadScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xreadScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreviewDuty` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xreviewScript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xreviewScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xroute` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xscript` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xscriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `PP_E_SPLIT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `PP_E_SPLIT_form`(`xform` ASC) USING BTREE,
                               INDEX `PP_E_SPLIT_process`(`xprocess` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_split_readdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_split_readdatapathlist`  (
                                                `SPLIT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreadDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_SPLIT_readDataPathList_element`(`xreadDataPathList` ASC) USING BTREE,
                                                INDEX `PP_E_SPLIT_readDataPathList_join`(`SPLIT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_split_readgrouplist
-- ----------------------------
CREATE TABLE `pp_e_split_readgrouplist`  (
                                             `SPLIT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `PP_E_SPLIT_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                             INDEX `PP_E_SPLIT_readGroupList_join`(`SPLIT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_split_readidentitylist
-- ----------------------------
CREATE TABLE `pp_e_split_readidentitylist`  (
                                                `SPLIT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreadIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PP_E_SPLIT_readIdentityList_element`(`xreadIdentityList` ASC) USING BTREE,
                                                INDEX `PP_E_SPLIT_readIdentityList_join`(`SPLIT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_split_readunitlist
-- ----------------------------
CREATE TABLE `pp_e_split_readunitlist`  (
                                            `SPLIT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xorderColumn` int NULL DEFAULT NULL,
                                            INDEX `PP_E_SPLIT_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                            INDEX `PP_E_SPLIT_readUnitList_join`(`SPLIT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_split_reviewdatapathlist
-- ----------------------------
CREATE TABLE `pp_e_split_reviewdatapathlist`  (
                                                  `SPLIT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreviewDataPathList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_SPLIT_reviewDataPathList_element`(`xreviewDataPathList` ASC) USING BTREE,
                                                  INDEX `PP_E_SPLIT_reviewDataPathList_join`(`SPLIT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_split_reviewgrouplist
-- ----------------------------
CREATE TABLE `pp_e_split_reviewgrouplist`  (
                                               `SPLIT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xreviewGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `PP_E_SPLIT_reviewGroupList_element`(`xreviewGroupList` ASC) USING BTREE,
                                               INDEX `PP_E_SPLIT_reviewGroupList_join`(`SPLIT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_split_reviewidentitylist
-- ----------------------------
CREATE TABLE `pp_e_split_reviewidentitylist`  (
                                                  `SPLIT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xreviewIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PP_E_SPLIT_reviewIdentityList_element`(`xreviewIdentityList` ASC) USING BTREE,
                                                  INDEX `PP_E_SPLIT_reviewIdentityList_join`(`SPLIT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_split_reviewunitlist
-- ----------------------------
CREATE TABLE `pp_e_split_reviewunitlist`  (
                                              `SPLIT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xreviewUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PP_E_SPLIT_reviewUnitList_element`(`xreviewUnitList` ASC) USING BTREE,
                                              INDEX `PP_E_SPLIT_reviewUnitList_join`(`SPLIT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_e_templateform
-- ----------------------------
CREATE TABLE `pp_e_templateform`  (
                                      `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                      `xcreateTime` datetime NULL DEFAULT NULL,
                                      `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xupdateTime` datetime NULL DEFAULT NULL,
                                      `xdistributeFactor` int NULL DEFAULT NULL,
                                      `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xcategory` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                      `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xicon` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                      `xmobileData` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                      `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xoutline` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                      PRIMARY KEY (`xid`) USING BTREE,
                                      UNIQUE INDEX `PP_E_TEMPLATEFORM_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                      INDEX `PP_E_TEMPLATEFORM_category`(`xcategory` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_m_event
-- ----------------------------
CREATE TABLE `pp_m_event`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xfailure` int NULL DEFAULT NULL,
                               `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtarget` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtype` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `PP_M_EVENT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `PP_M_EVENT_type`(`xtype` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_m_workcompletedevent
-- ----------------------------
CREATE TABLE `pp_m_workcompletedevent`  (
                                            `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                            `xcreateTime` datetime NULL DEFAULT NULL,
                                            `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xupdateTime` datetime NULL DEFAULT NULL,
                                            `xdistributeFactor` int NULL DEFAULT NULL,
                                            `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xtype` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            `xworkCompleted` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                            PRIMARY KEY (`xid`) USING BTREE,
                                            UNIQUE INDEX `PP_M_WORKCOMPLETEDEVENT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                            INDEX `PP_M_WORKCOMPLETEDEVENT_application`(`xapplication` ASC) USING BTREE,
                                            INDEX `PP_M_WORKCOMPLETEDEVENT_job`(`xjob` ASC) USING BTREE,
                                            INDEX `PP_M_WORKCOMPLETEDEVENT_type`(`xtype` ASC) USING BTREE,
                                            INDEX `PP_M_WORKCOMPLETEDEVENT_workCompleted`(`xworkCompleted` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for pp_m_workevent
-- ----------------------------
CREATE TABLE `pp_m_workevent`  (
                                   `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                   `xcreateTime` datetime NULL DEFAULT NULL,
                                   `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xupdateTime` datetime NULL DEFAULT NULL,
                                   `xdistributeFactor` int NULL DEFAULT NULL,
                                   `xapplication` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xjob` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xtype` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   `xwork` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                   PRIMARY KEY (`xid`) USING BTREE,
                                   UNIQUE INDEX `PP_M_WORKEVENT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                   INDEX `PP_M_WORKEVENT_application`(`xapplication` ASC) USING BTREE,
                                   INDEX `PP_M_WORKEVENT_job`(`xjob` ASC) USING BTREE,
                                   INDEX `PP_M_WORKEVENT_type`(`xtype` ASC) USING BTREE,
                                   INDEX `PP_M_WORKEVENT_work`(`xwork` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for ptl_file
-- ----------------------------
CREATE TABLE `ptl_file`  (
                             `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                             `xcreateTime` datetime NULL DEFAULT NULL,
                             `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xupdateTime` datetime NULL DEFAULT NULL,
                             `xdistributeFactor` int NULL DEFAULT NULL,
                             `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xfileName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xlastUpdateTime` datetime NULL DEFAULT NULL,
                             `xlength` bigint NULL DEFAULT NULL,
                             `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xportal` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xshortUrlCode` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             PRIMARY KEY (`xid`) USING BTREE,
                             UNIQUE INDEX `PTL_FILE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                             INDEX `PTL_FILE_alias`(`xalias` ASC) USING BTREE,
                             INDEX `PTL_FILE_portal`(`xportal` ASC) USING BTREE,
                             INDEX `PTL_FILE_shortUrlCode`(`xshortUrlCode` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for ptl_page
-- ----------------------------
CREATE TABLE `ptl_page`  (
                             `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                             `xcreateTime` datetime NULL DEFAULT NULL,
                             `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xupdateTime` datetime NULL DEFAULT NULL,
                             `xdistributeFactor` int NULL DEFAULT NULL,
                             `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xcategory` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xhasMobile` bit(1) NULL DEFAULT NULL,
                             `xmobileData` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xportal` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             PRIMARY KEY (`xid`) USING BTREE,
                             UNIQUE INDEX `PTL_PAGE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                             INDEX `PTL_PAGE_alias`(`xalias` ASC) USING BTREE,
                             INDEX `PTL_PAGE_category`(`xcategory` ASC) USING BTREE,
                             INDEX `PTL_PAGE_name`(`xname` ASC) USING BTREE,
                             INDEX `PTL_PAGE_portal`(`xportal` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for ptl_portal
-- ----------------------------
CREATE TABLE `ptl_portal`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xfirstPage` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xicon` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xlastUpdateTime` datetime NULL DEFAULT NULL,
                               `xmobileClient` bit(1) NULL DEFAULT NULL,
                               `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xpcClient` bit(1) NULL DEFAULT NULL,
                               `xportalCategory` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `PTL_PORTAL_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `PTL_PORTAL_alias`(`xalias` ASC) USING BTREE,
                               INDEX `PTL_PORTAL_creatorPerson`(`xcreatorPerson` ASC) USING BTREE,
                               INDEX `PTL_PORTAL_lastUpdatePerson`(`xlastUpdatePerson` ASC) USING BTREE,
                               INDEX `PTL_PORTAL_lastUpdateTime`(`xlastUpdateTime` ASC) USING BTREE,
                               INDEX `PTL_PORTAL_name`(`xname` ASC) USING BTREE,
                               INDEX `PTL_PORTAL_portalCategory`(`xportalCategory` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for ptl_portal_availablegrouplist
-- ----------------------------
CREATE TABLE `ptl_portal_availablegrouplist`  (
                                                  `PORTAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xavailableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `PTL_PORTAL_availableGroupList_element`(`xavailableGroupList` ASC) USING BTREE,
                                                  INDEX `PTL_PORTAL_availableGroupList_join`(`PORTAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for ptl_portal_availableidentitylist
-- ----------------------------
CREATE TABLE `ptl_portal_availableidentitylist`  (
                                                     `PORTAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xavailableIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                     `xorderColumn` int NULL DEFAULT NULL,
                                                     INDEX `PTL_PORTAL_availableIdentityList_element`(`xavailableIdentityList` ASC) USING BTREE,
                                                     INDEX `PTL_PORTAL_availableIdentityList_join`(`PORTAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for ptl_portal_availableunitlist
-- ----------------------------
CREATE TABLE `ptl_portal_availableunitlist`  (
                                                 `PORTAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xavailableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `PTL_PORTAL_availableUnitList_element`(`xavailableUnitList` ASC) USING BTREE,
                                                 INDEX `PTL_PORTAL_availableUnitList_join`(`PORTAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for ptl_portal_controllerlist
-- ----------------------------
CREATE TABLE `ptl_portal_controllerlist`  (
                                              `PORTAL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xcontrollerList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `PTL_PORTAL_controllerList_element`(`xcontrollerList` ASC) USING BTREE,
                                              INDEX `PTL_PORTAL_controllerList_join`(`PORTAL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for ptl_script
-- ----------------------------
CREATE TABLE `ptl_script`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xlastUpdateTime` datetime NULL DEFAULT NULL,
                               `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xportal` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xtext` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xvalidated` bit(1) NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `PTL_SCRIPT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `PTL_SCRIPT_alias`(`xalias` ASC) USING BTREE,
                               INDEX `PTL_SCRIPT_name`(`xname` ASC) USING BTREE,
                               INDEX `PTL_SCRIPT_portal`(`xportal` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for ptl_script_dependscriptlist
-- ----------------------------
CREATE TABLE `ptl_script_dependscriptlist`  (
                                                `SCRIPT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xdependScriptList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `PTL_SCRIPT_dependScriptList_element`(`xdependScriptList` ASC) USING BTREE,
                                                INDEX `PTL_SCRIPT_dependScriptList_join`(`SCRIPT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for ptl_widget
-- ----------------------------
CREATE TABLE `ptl_widget`  (
                               `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                               `xcreateTime` datetime NULL DEFAULT NULL,
                               `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xupdateTime` datetime NULL DEFAULT NULL,
                               `xdistributeFactor` int NULL DEFAULT NULL,
                               `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xcategory` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xhasMobile` bit(1) NULL DEFAULT NULL,
                               `xmobileData` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                               `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               `xportal` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                               PRIMARY KEY (`xid`) USING BTREE,
                               UNIQUE INDEX `PTL_WIDGET_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                               INDEX `PTL_WIDGET_alias`(`xalias` ASC) USING BTREE,
                               INDEX `PTL_WIDGET_category`(`xcategory` ASC) USING BTREE,
                               INDEX `PTL_WIDGET_name`(`xname` ASC) USING BTREE,
                               INDEX `PTL_WIDGET_portal`(`xportal` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_idx_state
-- ----------------------------
CREATE TABLE `qry_idx_state`  (
                                  `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                  `xcreateTime` datetime NULL DEFAULT NULL,
                                  `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xupdateTime` datetime NULL DEFAULT NULL,
                                  `xdistributeFactor` int NULL DEFAULT NULL,
                                  `xfreq` varchar(8) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xlatestUpdateTime` datetime NULL DEFAULT NULL,
                                  `xmode` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xnode` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xproperties` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xtype` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  PRIMARY KEY (`xid`) USING BTREE,
                                  UNIQUE INDEX `QRY_IDX_STATE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_import_model
-- ----------------------------
CREATE TABLE `qry_import_model`  (
                                     `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                     `xcreateTime` datetime NULL DEFAULT NULL,
                                     `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xupdateTime` datetime NULL DEFAULT NULL,
                                     `xdistributeFactor` int NULL DEFAULT NULL,
                                     `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xcode` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                     `xcount` int NULL DEFAULT NULL,
                                     `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                     `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xdisplay` bit(1) NULL DEFAULT NULL,
                                     `xenableValid` bit(1) NULL DEFAULT NULL,
                                     `xlayout` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                     `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xorderNumber` int NULL DEFAULT NULL,
                                     `xprocessStatus` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xquery` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     `xtype` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                     PRIMARY KEY (`xid`) USING BTREE,
                                     UNIQUE INDEX `QRY_IMPORT_MODEL_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                     INDEX `QRY_IMPORT_MODELxquery`(`xquery` ASC) USING BTREE,
                                     INDEX `QRY_IMPORT_MODEL_orderNumber`(`xorderNumber` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_import_model_availablegrouplist
-- ----------------------------
CREATE TABLE `qry_import_model_availablegrouplist`  (
                                                        `IMPORTMODEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xavailableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xorderColumn` int NULL DEFAULT NULL,
                                                        INDEX `QRY_IMPORT_MODEL_availableGroupList_element`(`xavailableGroupList` ASC) USING BTREE,
                                                        INDEX `QRY_IMPORT_MODEL_availableGroupList_join`(`IMPORTMODEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_import_model_availableidentitylist
-- ----------------------------
CREATE TABLE `qry_import_model_availableidentitylist`  (
                                                           `IMPORTMODEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                           `xavailableIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                           `xorderColumn` int NULL DEFAULT NULL,
                                                           INDEX `QRY_IMPORT_MODEL_availableIdentityList_element`(`xavailableIdentityList` ASC) USING BTREE,
                                                           INDEX `QRY_IMPORT_MODEL_availableIdentityList_join`(`IMPORTMODEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_import_model_availableunitlist
-- ----------------------------
CREATE TABLE `qry_import_model_availableunitlist`  (
                                                       `IMPORTMODEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xavailableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xorderColumn` int NULL DEFAULT NULL,
                                                       INDEX `QRY_IMPORT_MODEL_availableUnitList_element`(`xavailableUnitList` ASC) USING BTREE,
                                                       INDEX `QRY_IMPORT_MODEL_availableUnitList_join`(`IMPORTMODEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_item
-- ----------------------------
CREATE TABLE `qry_item`  (
                             `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                             `xcreateTime` datetime NULL DEFAULT NULL,
                             `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xupdateTime` datetime NULL DEFAULT NULL,
                             `xdistributeFactor` int NULL DEFAULT NULL,
                             `xbooleanValue` bit(1) NULL DEFAULT NULL,
                             `xbundle` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdateTimeValue` datetime NULL DEFAULT NULL,
                             `xdateValue` date NULL DEFAULT NULL,
                             `xitemCategory` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xitemPrimitiveType` varchar(1) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xitemStringValueType` varchar(2) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xitemType` varchar(1) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xnumberValue` double NULL DEFAULT NULL,
                             `xpath0` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xpath0Location` int NULL DEFAULT NULL,
                             `xpath1` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xpath1Location` int NULL DEFAULT NULL,
                             `xpath2` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xpath2Location` int NULL DEFAULT NULL,
                             `xpath3` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xpath3Location` int NULL DEFAULT NULL,
                             `xpath4` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xpath4Location` int NULL DEFAULT NULL,
                             `xpath5` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xpath5Location` int NULL DEFAULT NULL,
                             `xpath6` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xpath6Location` int NULL DEFAULT NULL,
                             `xpath7` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xpath7Location` int NULL DEFAULT NULL,
                             `xstringLongValue` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xstringShortValue` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xtimeValue` time NULL DEFAULT NULL,
                             PRIMARY KEY (`xid`) USING BTREE,
                             UNIQUE INDEX `QRY_ITEM_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                             INDEX `QRY_ITEM_bundle`(`xbundle` ASC, `xpath0` ASC, `xpath1` ASC, `xpath2` ASC, `xpath3` ASC) USING BTREE,
                             INDEX `QRY_ITEM_stringShortValue`(`xbundle` ASC, `xstringShortValue` ASC, `xpath0` ASC, `xpath1` ASC, `xpath2` ASC, `xpath3` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_nrl_model
-- ----------------------------
CREATE TABLE `qry_nrl_model`  (
                                  `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                  `xcreateTime` datetime NULL DEFAULT NULL,
                                  `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xupdateTime` datetime NULL DEFAULT NULL,
                                  `xdistributeFactor` int NULL DEFAULT NULL,
                                  `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xanalyzeType` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xattachmentScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xdataType` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xeffectiveEntryCount` int NULL DEFAULT NULL,
                                  `xendDate` datetime NULL DEFAULT NULL,
                                  `xentryCount` int NULL DEFAULT NULL,
                                  `xgeneratingPercent` int NULL DEFAULT NULL,
                                  `xinValueCount` int NULL DEFAULT NULL,
                                  `xinValueScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xintermediateNnet` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xlearnEntryCount` int NULL DEFAULT NULL,
                                  `xmaxResult` int NULL DEFAULT NULL,
                                  `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xneuralNetworkType` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xnnet` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xoutValueCount` int NULL DEFAULT NULL,
                                  `xoutValueScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xstartDate` datetime NULL DEFAULT NULL,
                                  `xstatus` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xtotalError` double NULL DEFAULT NULL,
                                  `xvalidationEntryCount` int NULL DEFAULT NULL,
                                  `xvalidationMeanSquareError` double NULL DEFAULT NULL,
                                  PRIMARY KEY (`xid`) USING BTREE,
                                  UNIQUE INDEX `QRY_NRL_MODEL_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                  INDEX `QRY_NRL_MODEL_effectiveEntryCount`(`xeffectiveEntryCount` ASC) USING BTREE,
                                  INDEX `QRY_NRL_MODEL_endDate`(`xendDate` ASC) USING BTREE,
                                  INDEX `QRY_NRL_MODEL_entryCount`(`xentryCount` ASC) USING BTREE,
                                  INDEX `QRY_NRL_MODEL_name`(`xname` ASC) USING BTREE,
                                  INDEX `QRY_NRL_MODEL_startDate`(`xstartDate` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_nrl_model_applicationlist
-- ----------------------------
CREATE TABLE `qry_nrl_model_applicationlist`  (
                                                  `MODEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xapplicationList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                  `xorderColumn` int NULL DEFAULT NULL,
                                                  INDEX `QRY_NRL_MODEL_applicationList_element`(`xapplicationList` ASC) USING BTREE,
                                                  INDEX `QRY_NRL_MODEL_applicationList_join`(`MODEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_nrl_model_processlist
-- ----------------------------
CREATE TABLE `qry_nrl_model_processlist`  (
                                              `MODEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xprocessList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xorderColumn` int NULL DEFAULT NULL,
                                              INDEX `QRY_NRL_MODEL_processList_element`(`xprocessList` ASC) USING BTREE,
                                              INDEX `QRY_NRL_MODEL_processList_join`(`MODEL_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_nrl_model_propertymap
-- ----------------------------
CREATE TABLE `qry_nrl_model_propertymap`  (
                                              `MODEL_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xkey` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              `xpropertyMap` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                              INDEX `QRY_NRL_MODEL_propertyMap_element`(`xpropertyMap` ASC) USING BTREE,
                                              INDEX `QRY_NRL_MODEL_propertyMap_join`(`MODEL_XID` ASC) USING BTREE,
                                              INDEX `QRY_NRL_MODEL_propertyMap_key`(`xkey` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_query
-- ----------------------------
CREATE TABLE `qry_query`  (
                              `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                              `xcreateTime` datetime NULL DEFAULT NULL,
                              `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xupdateTime` datetime NULL DEFAULT NULL,
                              `xdistributeFactor` int NULL DEFAULT NULL,
                              `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xicon` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                              `xiconHue` varchar(8) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xlastUpdateTime` datetime NULL DEFAULT NULL,
                              `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              `xqueryCategory` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                              PRIMARY KEY (`xid`) USING BTREE,
                              UNIQUE INDEX `QRY_QUERY_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                              INDEX `QRY_QUERY_name`(`xname` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_query_availablegrouplist
-- ----------------------------
CREATE TABLE `qry_query_availablegrouplist`  (
                                                 `QUERY_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xavailableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `QRY_QUERY_availableGroupList_element`(`xavailableGroupList` ASC) USING BTREE,
                                                 INDEX `QRY_QUERY_availableGroupList_join`(`QUERY_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_query_availableidentitylist
-- ----------------------------
CREATE TABLE `qry_query_availableidentitylist`  (
                                                    `QUERY_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xavailableIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                    `xorderColumn` int NULL DEFAULT NULL,
                                                    INDEX `QRY_QUERY_availableIdentityList_element`(`xavailableIdentityList` ASC) USING BTREE,
                                                    INDEX `QRY_QUERY_availableIdentityList_join`(`QUERY_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_query_availableunitlist
-- ----------------------------
CREATE TABLE `qry_query_availableunitlist`  (
                                                `QUERY_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xavailableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `QRY_QUERY_availableUnitList_element`(`xavailableUnitList` ASC) USING BTREE,
                                                INDEX `QRY_QUERY_availableUnitList_join`(`QUERY_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_query_controllerlist
-- ----------------------------
CREATE TABLE `qry_query_controllerlist`  (
                                             `QUERY_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xcontrollerList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                             `xorderColumn` int NULL DEFAULT NULL,
                                             INDEX `QRY_QUERY_controllerList_element`(`xcontrollerList` ASC) USING BTREE,
                                             INDEX `QRY_QUERY_controllerList_join`(`QUERY_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_sch_statement
-- ----------------------------
CREATE TABLE `qry_sch_statement`  (
                                      `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                      `xcreateTime` datetime NULL DEFAULT NULL,
                                      `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xupdateTime` datetime NULL DEFAULT NULL,
                                      `xdistributeFactor` int NULL DEFAULT NULL,
                                      `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xanonymousAccessible` bit(1) NULL DEFAULT NULL,
                                      `xcountData` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                      `xcountMethod` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xcountScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                      `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xdata` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                      `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xdisplay` bit(1) NULL DEFAULT NULL,
                                      `xentityCategory` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xentityClassName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xformat` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xfv` double NULL DEFAULT NULL,
                                      `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xlastUpdateTime` datetime NULL DEFAULT NULL,
                                      `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xorderNumber` int NULL DEFAULT NULL,
                                      `xquery` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xscriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                      `xsql` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                      `xsqlCount` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                      `xsqlCountScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                      `xsqlScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                      `xtable` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                      `xtestParameters` longtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                      `xview` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                      `xviewEnable` bit(1) NULL DEFAULT NULL,
                                      PRIMARY KEY (`xid`) USING BTREE,
                                      UNIQUE INDEX `QRY_SCH_STATEMENT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                      INDEX `QRY_SCH_STATEMENTxquery`(`xquery` ASC) USING BTREE,
                                      INDEX `QRY_SCH_STATEMENT_alias`(`xalias` ASC) USING BTREE,
                                      INDEX `QRY_SCH_STATEMENT_countMethod`(`xcountMethod` ASC) USING BTREE,
                                      INDEX `QRY_SCH_STATEMENT_format`(`xformat` ASC) USING BTREE,
                                      INDEX `QRY_SCH_STATEMENT_name`(`xname` ASC) USING BTREE,
                                      INDEX `QRY_SCH_STATEMENT_orderNumber`(`xorderNumber` ASC) USING BTREE,
                                      INDEX `QRY_SCH_STATEMENT_table`(`xtable` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_sch_statement_executegrouplist
-- ----------------------------
CREATE TABLE `qry_sch_statement_executegrouplist`  (
                                                       `STATEMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xexecuteGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                       `xorderColumn` int NULL DEFAULT NULL,
                                                       INDEX `QRY_SCH_STATEMENT_executeGroupList_element`(`xexecuteGroupList` ASC) USING BTREE,
                                                       INDEX `QRY_SCH_STATEMENT_executeGroupList_join`(`STATEMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_sch_statement_executepersonlist
-- ----------------------------
CREATE TABLE `qry_sch_statement_executepersonlist`  (
                                                        `STATEMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xexecutePersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                        `xorderColumn` int NULL DEFAULT NULL,
                                                        INDEX `QRY_SCH_STATEMENT_executePersonList_element`(`xexecutePersonList` ASC) USING BTREE,
                                                        INDEX `QRY_SCH_STATEMENT_executePersonList_join`(`STATEMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_sch_statement_executeunitlist
-- ----------------------------
CREATE TABLE `qry_sch_statement_executeunitlist`  (
                                                      `STATEMENT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xexecuteUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                      `xorderColumn` int NULL DEFAULT NULL,
                                                      INDEX `QRY_SCH_STATEMENT_executeUnitList_element`(`xexecuteUnitList` ASC) USING BTREE,
                                                      INDEX `QRY_SCH_STATEMENT_executeUnitList_join`(`STATEMENT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_sch_table
-- ----------------------------
CREATE TABLE `qry_sch_table`  (
                                  `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                                  `xcreateTime` datetime NULL DEFAULT NULL,
                                  `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xupdateTime` datetime NULL DEFAULT NULL,
                                  `xdistributeFactor` int NULL DEFAULT NULL,
                                  `xalias` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xbuildSuccess` bit(1) NULL DEFAULT NULL,
                                  `xcreatorPerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xdisplay` bit(1) NULL DEFAULT NULL,
                                  `xdraftData` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                                  `xlastUpdatePerson` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xlastUpdateTime` datetime NULL DEFAULT NULL,
                                  `xname` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xorderNumber` int NULL DEFAULT NULL,
                                  `xquery` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  `xstatus` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                  PRIMARY KEY (`xid`) USING BTREE,
                                  UNIQUE INDEX `QRY_SCH_TABLE_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                                  INDEX `QRY_SCH_TABLExquery`(`xquery` ASC) USING BTREE,
                                  INDEX `QRY_SCH_TABLE_alias`(`xalias` ASC) USING BTREE,
                                  INDEX `QRY_SCH_TABLE_name`(`xname` ASC) USING BTREE,
                                  INDEX `QRY_SCH_TABLE_orderNumber`(`xorderNumber` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_sch_table_editgrouplist
-- ----------------------------
CREATE TABLE `qry_sch_table_editgrouplist`  (
                                                `TABLE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xeditGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `QRY_SCH_TABLE_editGroupList_element`(`xeditGroupList` ASC) USING BTREE,
                                                INDEX `QRY_SCH_TABLE_editGroupList_join`(`TABLE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_sch_table_editpersonlist
-- ----------------------------
CREATE TABLE `qry_sch_table_editpersonlist`  (
                                                 `TABLE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xeditPersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `QRY_SCH_TABLE_editPersonList_element`(`xeditPersonList` ASC) USING BTREE,
                                                 INDEX `QRY_SCH_TABLE_editPersonList_join`(`TABLE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_sch_table_editunitlist
-- ----------------------------
CREATE TABLE `qry_sch_table_editunitlist`  (
                                               `TABLE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xeditUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `QRY_SCH_TABLE_editUnitList_element`(`xeditUnitList` ASC) USING BTREE,
                                               INDEX `QRY_SCH_TABLE_editUnitList_join`(`TABLE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_sch_table_readgrouplist
-- ----------------------------
CREATE TABLE `qry_sch_table_readgrouplist`  (
                                                `TABLE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xreadGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `QRY_SCH_TABLE_readGroupList_element`(`xreadGroupList` ASC) USING BTREE,
                                                INDEX `QRY_SCH_TABLE_readGroupList_join`(`TABLE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_sch_table_readpersonlist
-- ----------------------------
CREATE TABLE `qry_sch_table_readpersonlist`  (
                                                 `TABLE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xreadPersonList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                 `xorderColumn` int NULL DEFAULT NULL,
                                                 INDEX `QRY_SCH_TABLE_readPersonList_element`(`xreadPersonList` ASC) USING BTREE,
                                                 INDEX `QRY_SCH_TABLE_readPersonList_join`(`TABLE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_sch_table_readunitlist
-- ----------------------------
CREATE TABLE `qry_sch_table_readunitlist`  (
                                               `TABLE_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xreadUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `QRY_SCH_TABLE_readUnitList_element`(`xreadUnitList` ASC) USING BTREE,
                                               INDEX `QRY_SCH_TABLE_readUnitList_join`(`TABLE_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_stat
-- ----------------------------
CREATE TABLE `qry_stat`  (
                             `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                             `xcreateTime` datetime NULL DEFAULT NULL,
                             `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xupdateTime` datetime NULL DEFAULT NULL,
                             `xdistributeFactor` int NULL DEFAULT NULL,
                             `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdisplay` bit(1) NULL DEFAULT NULL,
                             `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xorderNumber` int NULL DEFAULT NULL,
                             `xquery` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xview` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             PRIMARY KEY (`xid`) USING BTREE,
                             UNIQUE INDEX `QRY_STAT_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                             INDEX `QRY_STATxquery`(`xquery` ASC) USING BTREE,
                             INDEX `QRY_STAT_name`(`xname` ASC) USING BTREE,
                             INDEX `QRY_STAT_orderNumber`(`xorderNumber` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_stat_availablegrouplist
-- ----------------------------
CREATE TABLE `qry_stat_availablegrouplist`  (
                                                `STAT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xavailableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `QRY_STAT_availableGroupList_element`(`xavailableGroupList` ASC) USING BTREE,
                                                INDEX `QRY_STAT_availableGroupList_join`(`STAT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_stat_availableidentitylist
-- ----------------------------
CREATE TABLE `qry_stat_availableidentitylist`  (
                                                   `STAT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xavailableIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `QRY_STAT_availableIdentityList_element`(`xavailableIdentityList` ASC) USING BTREE,
                                                   INDEX `QRY_STAT_availableIdentityList_join`(`STAT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_stat_availableunitlist
-- ----------------------------
CREATE TABLE `qry_stat_availableunitlist`  (
                                               `STAT_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xavailableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `QRY_STAT_availableUnitList_element`(`xavailableUnitList` ASC) USING BTREE,
                                               INDEX `QRY_STAT_availableUnitList_join`(`STAT_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_view
-- ----------------------------
CREATE TABLE `qry_view`  (
                             `xid` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
                             `xcreateTime` datetime NULL DEFAULT NULL,
                             `xsequence` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xupdateTime` datetime NULL DEFAULT NULL,
                             `xdistributeFactor` int NULL DEFAULT NULL,
                             `xafterCalculateGridScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xafterGridScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xafterGroupGridScriptText` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xalias` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xcacheAccess` bit(1) NULL DEFAULT NULL,
                             `xcode` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xcount` int NULL DEFAULT NULL,
                             `xdata` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xdisplay` bit(1) NULL DEFAULT NULL,
                             `xenableCache` bit(1) NULL DEFAULT NULL,
                             `xlayout` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xname` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xorderNumber` int NULL DEFAULT NULL,
                             `xpageSize` int NULL DEFAULT NULL,
                             `xquery` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             `xtoolbar` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NULL,
                             `xtype` varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                             PRIMARY KEY (`xid`) USING BTREE,
                             UNIQUE INDEX `QRY_VIEW_DUC`(`xid` ASC, `xcreateTime` ASC, `xupdateTime` ASC, `xsequence` ASC) USING BTREE,
                             INDEX `QRY_VIEWxquery`(`xquery` ASC) USING BTREE,
                             INDEX `QRY_VIEW_orderNumber`(`xorderNumber` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_view_availablegrouplist
-- ----------------------------
CREATE TABLE `qry_view_availablegrouplist`  (
                                                `VIEW_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xavailableGroupList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                `xorderColumn` int NULL DEFAULT NULL,
                                                INDEX `QRY_VIEW_availableGroupList_element`(`xavailableGroupList` ASC) USING BTREE,
                                                INDEX `QRY_VIEW_availableGroupList_join`(`VIEW_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_view_availableidentitylist
-- ----------------------------
CREATE TABLE `qry_view_availableidentitylist`  (
                                                   `VIEW_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xavailableIdentityList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                                   `xorderColumn` int NULL DEFAULT NULL,
                                                   INDEX `QRY_VIEW_availableIdentityList_element`(`xavailableIdentityList` ASC) USING BTREE,
                                                   INDEX `QRY_VIEW_availableIdentityList_join`(`VIEW_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for qry_view_availableunitlist
-- ----------------------------
CREATE TABLE `qry_view_availableunitlist`  (
                                               `VIEW_XID` varchar(64) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xavailableUnitList` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
                                               `xorderColumn` int NULL DEFAULT NULL,
                                               INDEX `QRY_VIEW_availableUnitList_element`(`xavailableUnitList` ASC) USING BTREE,
                                               INDEX `QRY_VIEW_availableUnitList_join`(`VIEW_XID` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;



CREATE TABLE `org_role_menulist`
(
    `role_id`      VARCHAR(64) NOT NULL,
    `menuList`     VARCHAR(64) NOT NULL,
    `xorderColumn` INT         NULL
) COMMENT '角色-菜单关联表'
    ENGINE = InnoDB
    CHARACTER SET = utf8
    COLLATE = utf8_general_ci
    ROW_FORMAT = Dynamic;

create table org_menu
(
    menu_id     varchar(64)              not null comment '菜单ID'
        primary key,
    menu_name   varchar(64)              not null comment '菜单名称',
    menu_type   smallint     default 0   not null comment '菜单类型(1为普通菜单2为目录3为内嵌iFrame4为外链跳转)',
    is_button   tinyint(1)   default 0   not null comment '是否按钮',
    parent_id   varchar(64)  default '0' not null comment '父菜单ID',
    permission  varchar(128)             null comment '权限标识',
    status      smallint     default 0   not null comment '菜单状态（1启用 0停用）',
    icon        varchar(255)             null,
    level       int          default 0   not null comment '所在层数，用于快速查询同层结点',
    link_url    varchar(256) default ''  null comment '外链跳转页面对应URL',
    remark      varchar(256) default ''  null comment '备注',
    creator_id  varchar(64)              null comment '创建者ID',
    create_time datetime                 null comment '创建时间',
    updater_id  varchar(64)              null comment '更新者ID',
    update_time datetime                 null comment '更新时间',
    deleted     tinyint(1)   default 0   not null comment '逻辑删除'
)
    comment '菜单权限表' charset = utf8
                         row_format = DYNAMIC;


