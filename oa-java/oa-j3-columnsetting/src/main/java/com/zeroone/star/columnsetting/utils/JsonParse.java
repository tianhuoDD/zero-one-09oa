package com.zeroone.star.columnsetting.utils;

import cn.hutool.json.JSONUtil;
import com.alibaba.nacos.shaded.com.google.common.reflect.TypeToken;
import com.alibaba.nacos.shaded.com.google.gson.Gson;
import com.baomidou.mybatisplus.core.toolkit.IdWorker;
import com.zeroone.star.columnsetting.entity.CmsAppdictitem;
import org.springframework.beans.BeanUtils;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Map;
import java.util.Set;

/**
 * <p>
 * 描述：层级json解析工具
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 落
 * @version 1.0.0
 */

public class JsonParse {
    /**
     * 设置数组类型当前元素的路径
     * @param item 当前元素
     * @param layer 当前层级
     * @param index 改元素对应的索引
     */
    private static void setListXPath(CmsAppdictitem item, int layer, int index) {
        switch (layer) {
            case 0:
                item.setXpath0("" + index);
                item.setXpath0Location(index);
                break;
            case 1:
                item.setXpath1("" + index);
                item.setXpath1Location(index);
                break;
            case 2:
                item.setXpath2("" + index);
                item.setXpath2Location(index);
                break;
            case 3:
                item.setXpath3("" + index);
                item.setXpath3Location(index);
                break;
            case 4:
                item.setXpath4("" + index);
                item.setXpath4Location(index);
                break;
            case 5:
                item.setXpath5("" + index);
                item.setXpath5Location(index);
                break;
            case 6:
                item.setXpath6("" + index);
                item.setXpath6Location(index);
                break;
            case 7:
                item.setXpath7("" + index);
                item.setXpath7Location(index);
                break;
            default:
                break;
        }
    }

    /**
     * 设置对象类型元素的当前路径
     *
     * @param item 当前元素
     * @param layer 当前层级
     * @param name  对象名字
     */
    private static void setObjectXPath(CmsAppdictitem item, int layer, String name) {
        switch (layer) {
            case 0:
                item.setXpath0(name);
                //对象类型的xpathiLocation默认为-1
                item.setXpath0Location(-1);
                break;
            case 1:
                item.setXpath1(name);
                item.setXpath1Location(-1);
                break;
            case 2:
                item.setXpath2(name);
                item.setXpath2Location(-1);
                break;
            case 3:
                item.setXpath3(name);
                item.setXpath3Location(-1);
                break;
            case 4:
                item.setXpath4(name);
                item.setXpath4Location(-1);
                break;
            case 5:
                item.setXpath5(name);
                item.setXpath5Location(-1);
                break;
            case 6:
                item.setXpath6(name);
                item.setXpath6Location(-1);
                break;
            case 7:
                item.setXpath7(name);
                item.setXpath7Location(-1);
                break;
            default:
                break;
        }
    }


    /**
     * 将json解析为CmsAppdicitem对象
     * @param o 通过Gson转换成的map对象
     * @param list 解析后的结构存放地
     * @param layer 当前层级
     * @param parentPath 父级嵌套路径
     * @param xappId  所属appid
     * @param xbundle 所属appndictid
     */
    private void parse(Object o, ArrayList<CmsAppdictitem> list, int layer, Path parentPath, String xappId, String xbundle) {
        //判断是否是arraylist类型
        if (o.getClass().getSimpleName().equals("ArrayList")) {
            //强制为ArrayList集合
            ArrayList root = (ArrayList) o;

            //遍历集合
            for (int i = 0; i < root.size(); i++) {
                //获取集合中的值
                Object value = root.get(i);

                //创建item对象
                CmsAppdictitem item = new CmsAppdictitem();
                //设置xappId
                item.setXappId(xappId);
                //设置xbundle
                item.setXbundle(xbundle);
                //设置 xid
                String id = IdWorker.getIdStr();
                item.setXid(id);
                //设置 xcreateTime,xupdatetime
                LocalDateTime now = LocalDateTime.now();
                item.setXcreateTime(now);
                item.setXupdateTime(now);
                //设置xsequence
                DateTimeFormatter pattern = DateTimeFormatter.ofPattern("yyyyMMddHHmmss");
                String formatTime = now.format(pattern);
                item.setXsequence(formatTime+id);
                //设置xitemCategory
                item.setXitemCategory("pp_dict");



                //记录xitemPrimitiveType的值
                String primitiveType = "s";
                //记录xitemStringValueType的值
                String stringValueType = "u";
                //记录xitemType的值
                String itemType = "p";

                //数据处理
                switch (value.getClass().getSimpleName()) {
                    case "Double":
                        primitiveType = "n";
                        item.setXnumberValue((Double) value);
                        break;
                    case "Boolean":
                        primitiveType = "b";
                        item.setXbooleanValue((Boolean) value);
                        break;
                    case "String":
                        String str = (String) value;
                        primitiveType = "s";
                        stringValueType = "s";
                        if (str.length() > 255) {
                            item.setXstringLongValue(str);
                        } else {
                            item.setXstringShortValue(str);
                        }
                        break;
                    case "ArrayList":
                    case "LinkedTreeMap":
                        if (value.getClass().getSimpleName().equals("ArrayList")) {
                            itemType = "a";
                        } else {
                            itemType = "o";
                        }
                        primitiveType = "u";

                        //拷贝父路径
                        BeanUtils.copyProperties(parentPath, item);

                        //设置类型
                        item.setXitemPrimitiveType(primitiveType);
                        item.setXitemStringValueType(stringValueType);
                        item.setXitemType(itemType);
                        //判断当前层级是否大于7
                        if (layer>=7){
                            item.setXitemType("j");
                            //将当前对象转为json格式
                            String jsonStr = JSONUtil.toJsonStr(value);
                            //将剩余部分以json格式存入
                            if (jsonStr.length() > 255) {
                                item.setXstringLongValue(jsonStr);
                            } else {
                                item.setXstringShortValue(jsonStr);
                            }
                            //设置当前层级路径
                            setListXPath(item, 7, i);
                            //加入list集合
                            list.add(item);
                            continue;

                        }else{
                            //设置当前层级路径
                            setListXPath(item, layer, i);
                            //加入list集合
                            list.add(item);
                            //传入父路径
                            Path path = new Path();
                            BeanUtils.copyProperties(item, path);
                            //递归调用
                            parse(value, list, layer + 1, path,xappId,xbundle);
                        }
                        continue;
                    default:
                        break;

                }

                //拷贝父路径
                BeanUtils.copyProperties(parentPath, item);
                //设置当前层级路径
                setListXPath(item, layer, i);
                //设置类型
                item.setXitemPrimitiveType(primitiveType);
                item.setXitemStringValueType(stringValueType);
                item.setXitemType(itemType);
                //加入list集合
                list.add(item);
            }
        } else {
            Map<String, Object> map = (Map<String, Object>) o;

            Set<Map.Entry<String, Object>> entries = map.entrySet();
            for (Map.Entry<String, Object> entry : entries) {
                Object value = entry.getValue();

                //创建item对象
                CmsAppdictitem item = new CmsAppdictitem();
                //设置xappId
                item.setXappId(xappId);
                //设置xbundle
                item.setXbundle(xbundle);
                //设置 xid
                String id = IdWorker.getIdStr();
                item.setXid(id);
                //设置 xcreateTime,xupdatetime
                LocalDateTime now = LocalDateTime.now();
                item.setXcreateTime(now);
                item.setXupdateTime(now);
                //设置xsequence
                DateTimeFormatter pattern = DateTimeFormatter.ofPattern("yyyyMMddHHmmss");
                String formatTime = now.format(pattern);
                item.setXsequence(formatTime+id);
                //设置xitemCategory
                item.setXitemCategory("pp_dict");


                //记录xitemPrimitiveType的值
                String primitiveType = "s";
                //记录xitemStringValueType的值
                String stringValueType = "u";
                //记录xitemType的值
                String itemType = "p";

                switch (value.getClass().getSimpleName()) {
                    case "Double":
                        primitiveType = "n";
                        item.setXnumberValue((Double) value);
                        break;
                    case "Boolean":
                        primitiveType = "b";
                        item.setXbooleanValue((Boolean) value);
                        break;
                    case "String":
                        primitiveType = "s";
                        stringValueType = "s";
                        String str = (String) value;
                        if (str.length() > 255) {
                            item.setXstringLongValue(str);
                        } else {
                            item.setXstringShortValue(str);
                        }
                        break;
                    case "ArrayList":
                    case "LinkedTreeMap":
                        primitiveType = "u";
                        if (value.getClass().getSimpleName().equals("ArrayList")) {
                            itemType = "a";

                        } else {
                            itemType = "o";

                        }

                        //继承父路径
                        BeanUtils.copyProperties(parentPath, item);
                        //设置类型
                        item.setXitemPrimitiveType(primitiveType);
                        item.setXitemStringValueType(stringValueType);
                        item.setXitemType(itemType);

                        //判断当前层级是否大于7
                        if (layer>=7){
                            item.setXitemType("j");
                            //将当前对象转为json格式
                            String jsonStr = JSONUtil.toJsonStr(value);
                            //将剩余部分以json格式存入
                            if (jsonStr.length() > 255) {
                                item.setXstringLongValue(jsonStr);
                            } else {
                                item.setXstringShortValue(jsonStr);
                            }
                            //设置当前层级路径
                            setObjectXPath(item, 7,entry.getKey() );
                            //加入list集合
                            list.add(item);
                            continue;
                        }else{
                            //设置当前层级路径
                            setObjectXPath(item, layer,entry.getKey() );
                            //加入list集合
                            list.add(item);
                            //传入父路径
                            Path path = new Path();
                            BeanUtils.copyProperties(item, path);
                            //递归调用
                            parse(value, list, layer + 1, path,xappId,xbundle);
                        }
                        continue;
                    default:
                        break;

                }

                //继承父路径
                BeanUtils.copyProperties(parentPath, item);
                //设置路径
                setObjectXPath(item, layer, entry.getKey());
                //设置类型
                item.setXitemPrimitiveType(primitiveType);
                item.setXitemStringValueType(stringValueType);
                item.setXitemType(itemType);
                list.add(item);
            }
        }
    }


    /**
     * 解析接送数据
     * @param json json数据
     * @param xappId 所属appid
     * @param xbundle 所属目录id
     * @return 返回cmsappdictitem对象的list集合
     */
    public ArrayList<CmsAppdictitem> jsonToCmsAppdictitemList(String json,String xappId,String xbundle){

        //解析后的结果集合
        ArrayList<CmsAppdictitem> appdictitems =  new ArrayList<>();
        //插入根节点
        CmsAppdictitem root = new CmsAppdictitem();
        root.setXbundle(xbundle);
        String id = IdWorker.getIdStr();
        root.setXid(id);
        root.setXappId(xappId);
        LocalDateTime now = LocalDateTime.now();
        root.setXupdateTime(now);
        root.setXcreateTime(now);
        DateTimeFormatter pattern = DateTimeFormatter.ofPattern("yyyyMMddHHmmss");
        String formatTime = now.format(pattern);
        root.setXsequence(formatTime+id);
        root.setXitemStringValueType("u");
        root.setXitemPrimitiveType("u");


        //json解析结果，list集合或map集合
        Object parseJson = null;
        //去除首尾空格
        json= json.trim();
        if (json.charAt(0)=='[') {
           parseJson = new Gson().fromJson(json, new TypeToken<ArrayList<Object>>() {
            }.getType());
            root.setXitemType("a");
        }else {
           parseJson = new Gson().fromJson(json,
                    new TypeToken<Map<String, Object>>() {
                    }.getType());
            root.setXitemType("o");
        }
        appdictitems.add(root);

        //进行解析
        parse(parseJson,appdictitems,0,new Path(),xappId,xbundle);
        return appdictitems;
    }

}
