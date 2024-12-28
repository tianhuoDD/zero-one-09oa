package com.zeroone.star.project.vo.j5.cmshome;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("获取栏目信息")
public class GetColumnMessagesVO {


    /*
     * 图片路径
     */
    @ApiModelProperty(value = "图片路径", example = "/images/sample.png")
    private String xappIcon;

    /*
     * 名称
     */
    @ApiModelProperty(value = "图片名称", example = "通知公告")
    private String xappName;

    /*
     * 描述信息
     */
    @ApiModelProperty(value = "描述信息", example = "这是一个关于通知公告的描述信息")
    private String xdescription;




    /*
     * 用于接收数据库返回的逗号分隔的字符串id
     */
    @ApiModelProperty(value = "appid", example = "[\"value1\", \"value2\", \"value3\"]")
    private String additionalFields; // 作为 String


    /*
     * 用于拆分后的字符串数组id
     */
    @ApiModelProperty(value = "分类数组", example = "[\"value1\", \"value2\", \"value3\"]")
    private String[] categorys; // 改为 String[] 类型

    /*
     * 用于接收数据库返回的逗号分隔的字符串name
     */
    @ApiModelProperty(value = "分类名称字段", example = "['固定资产','报废记录','调拨记录']")
    private String xcategoryNameFields;

    /*
     * 用于拆分后的字符串数组name
     */
    @ApiModelProperty(value = "分类名称数组", example = "[\"固定资产\", \"报废记录\", \"调拨记录\"]")
    private String[] categoryNames;



    /*
     * 用于保存最后展示的数据，示例数据为：[{"id": "6e1ee7c7-8c75-4c7d-b285-f5449627bdd9", "categoryName": "内部八卦"},
     * {"id": "cf276a67-c7c0-437a-8f74-9420a89fee42", "categoryName": "公司新闻"}]
     */
    @ApiModelProperty(value = "list数组", example = "[{\"id\": \"6e1ee7c7-8c75-4c7d-b285-f5449627bdd9\", \"categoryName\": \"内部八卦\"}, {\"id\": \"cf276a67-c7c0-437a-8f74-9420a89fee42\", \"categoryName\": \"公司新闻\"}]")
    private List<Category> categorylist;


}
