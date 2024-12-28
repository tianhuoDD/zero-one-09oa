package com.zeroone.star.project.j3.datacofig.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;



/**
 * <p>
 * 描述：修改和新增上传的数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 落
 * @version 1.0.0
 */
@ApiModel("修改和新增上传的数据对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class DataConfigDTO {
    @ApiModelProperty(value = "数据字典id", example = "763e8b7f-97e3-4e7b-8b9f-a07e6d94fd81")
    private String id;
    @ApiModelProperty(value = "数据字典名字", example = "配置字典",required = true)
    private String name;
    @ApiModelProperty(value = "数据字典别名", example = "配置字典",required = true)
    private String alias;
    @ApiModelProperty(value = "数据字典描述", example = "存放配置参数")
    private String description;
    @ApiModelProperty(value = "数据字典内容,可嵌套的json格式", example = " {\n" +
            "      \"Arr1\": [\n" +
            "        \"a1\",\n" +
            "        \"a2\",\n" +
            "        1111.0,\n" +
            "        [\n" +
            "          \"二级数据第一个元素\",\n" +
            "          [\n" +
            "            \"三级数据第一个元素\",\n" +
            "            [\n" +
            "              \"四级数据第一个元素\",\n" +
            "              [\n" +
            "                \"五级数据第一个元素\",\n" +
            "                [\n" +
            "                  \"六级数据第一个元素\",\n" +
            "                  [\n" +
            "                    \"七级数据第一个元素\",\n" +
            "                    [\n" +
            "                      \"八级数据第一个元素\",\n" +
            "                      \"八级数据第二个元素\",\n" +
            "                      [\n" +
            "                        \"九级数据第一个元素\"\n" +
            "                      ],\n" +
            "                      {\n" +
            "                        \"o1\": \"o1\"\n" +
            "                      }\n" +
            "                    ]\n" +
            "                  ]\n" +
            "                ]\n" +
            "              ]\n" +
            "            ]\n" +
            "          ]\n" +
            "        ]\n" +
            "      ],\n" +
            "      \"O2\": {},\n" +
            "      \"age\": 222.0,\n" +
            "      \"booleanTest\": true,\n" +
            "      \"name\": \"name\",\n" +
            "      \"obj2\": {},\n" +
            "      \"objectTest\": {\n" +
            "        \"Ochild1\": \"Ochild1\"\n" +
            "      }}",required = true)
    private String data;
    @ApiModelProperty(value = "所属的appid", example = "f99ab747-b144-451b-98ae-ac9e4c70702f",required = true)
    private String appid;


}
