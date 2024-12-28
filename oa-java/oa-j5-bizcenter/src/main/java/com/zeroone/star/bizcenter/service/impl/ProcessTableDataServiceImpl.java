package com.zeroone.star.bizcenter.service.impl;


import cn.hutool.json.JSONObject;
import com.zeroone.star.bizcenter.mapper.ProcessTableDataMapper;
import com.zeroone.star.bizcenter.mapper.WorkMapper;
import com.zeroone.star.bizcenter.service.ProcessTableDataService;
import com.zeroone.star.project.dto.j5.bizcenter.ProcessFormItemDTO;
import com.zeroone.star.project.vo.j5.bizcenter.ProcessFormDataVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@Service
public class ProcessTableDataServiceImpl implements ProcessTableDataService {


    @Resource
    private WorkMapper workMapper;

    @Resource
    private ProcessTableDataMapper dataMapper;


    /**
     * 通过work表的xid 查询流程表格数据
     *
     * @param xid
     * @return
     */
    @Override
    public ProcessFormDataVO getProcessTableDataByXid(String xid) {
        //1、获取work表中的xjob
        String xjob = workMapper.selectXjobByXid(xid);

        //2、通过xjob，就是qry_item中的xbundle，查找这个表中的所有数据
        List<ProcessFormItemDTO> list = dataMapper.selectTableDataByXbundle(xjob);


        JSONObject result = new JSONObject();
        HashMap<String, Object> str = new HashMap<>();

        for (int i = 0; i < list.size(); i++) {
            ProcessFormItemDTO dto = list.get(i);
            String xpath0 = dto.getXpath0();
//            String value = dto.getXstringShortValue();
            String value = getValue(dto);
            if(xpath0 == null || value == null) continue;
            if(str.containsKey(xpath0 + "0")) continue;
            str.put(xpath0 + "0",1);

            //求相同的xpath0
            List<ProcessFormItemDTO> resList = list.stream().filter(s -> xpath0.equals(s.getXpath0())).collect(Collectors.toList());

            String xpath1 = dto.getXpath1();
            //对数组和对象进行判断
            if(xpath1 == null || xpath1.length() == 0){
                result.put(xpath0,value);
            }else if(Character.isDigit(xpath1.charAt(0)) ){
                if(dto.getXpath2() == null || dto.getXpath2().length() == 0){
                    //直接是数组的情况，checkbox["111","222"]
                    ArrayList<String> aList = new ArrayList<>();
                    for (int j = 0; j < resList.size(); j++){
                        ProcessFormItemDTO dto1 = resList.get(j);
                        String value1 = dto1.getXstringShortValue();
                        if(value1==null) continue;
                        aList.add(value1);
                    }
                    result.put(xpath0,new ArrayList<>(aList));
                }else{
                    //数组
                    Map<String, Object> map = new HashMap<>();
                    ArrayList<Map<String, Object>> aList = new ArrayList<>();

                    for (int j = 0; j < resList.size(); j++){
                        ProcessFormItemDTO numDto = resList.get(j);

                        String xpath11 = numDto.getXpath1();
                        if(xpath11 == null || xpath11.length() == 0) continue;
                        if(str.containsKey(xpath0 + numDto.getXpath1() + "2")) continue;

                        str.put(xpath0 + numDto.getXpath1() + "2",1);

                        List<ProcessFormItemDTO> collect = resList.stream()
                                .filter(s -> xpath11.equals(s.getXpath1()))
                                .collect(Collectors.toList());

                        for (int k = 0; k<collect.size();k++){
                            ProcessFormItemDTO dto1 = collect.get(k);
                            if(dto1.getXstringShortValue()==null) continue;
                            map.put(dto1.getXpath2(),getValue(dto1));
                        }
                        aList.add(new HashMap(map));
                        map.clear();
                    }

                    result.put(xpath0,new ArrayList<>(aList));
                }
            }else {
                //是对象的情况，对象里面还分对象和数组
                //xpath0是确定的，筛选xpath1，按照上面的步骤
                Map<String,Object> map = chooseXpath(resList);
                result.put(xpath0,new HashMap<>(map));
            }
        }

        return new ProcessFormDataVO(result);

    }

    private Map<String, Object> chooseXpath(List<ProcessFormItemDTO> list) {
        HashMap<String, Object> result = new HashMap<>();
        HashMap<String, Object> str = new HashMap<>();

        //以xpath1为基础，判断xpath2
        for (int i = 0; i < list.size(); i++) {
            ProcessFormItemDTO dto = list.get(i);
            String xpath1 = dto.getXpath1();
            String value = getValue(dto);

            if(xpath1 == null || value == null) continue;
            if(str.containsKey(xpath1 + "1")) continue;
            str.put(xpath1 + "1",1);

            //求相同的xpath1
            List<ProcessFormItemDTO> resList = list.stream().filter(s -> xpath1.equals(s.getXpath1())).collect(Collectors.toList());

            String xpath2 = dto.getXpath2();
            //对数组和对象进行判断
            if(xpath2 == null || xpath2.length() == 0){
                result.put(xpath1,value);
            }else if(Character.isDigit(xpath2.charAt(0)) ){
                if(dto.getXpath3() == null || dto.getXpath3().length() == 0){
                    //直接是数组的情况，checkbox["111","222"]
                    ArrayList<String> aList = new ArrayList<>();
                    for (int j = 0; j < resList.size(); j++){
                        ProcessFormItemDTO dto1 = resList.get(j);
                        String value1 = getValue(dto1);
                        if(value1==null) continue;
                        aList.add(value1);
                    }
                    result.put(xpath1,new ArrayList<>(aList));
                }else{
                    //数组,xpath2为 数组，xpath3为字段
                    Map<String, Object> map = new HashMap<>();
                    ArrayList<Map<String, Object>> aList = new ArrayList<>();

                    for (int j = 0; j < resList.size(); j++){
                        ProcessFormItemDTO numDto = resList.get(j);

                        String xpath22 = numDto.getXpath2();
                        if(xpath22 == null || xpath22.length() == 0) continue;
                        if(str.containsKey(numDto.getXpath0() +xpath1 + numDto.getXpath2() + "3")) continue;

                        str.put(numDto.getXpath0() + xpath1 + numDto.getXpath2() + "3",1);

                        List<ProcessFormItemDTO> collect = resList.stream()
                                .filter(s -> xpath22.equals(s.getXpath2()))
                                .collect(Collectors.toList());

                        for (int k = 0; k<collect.size();k++){
                            ProcessFormItemDTO dto1 = collect.get(k);
                            String value1 = getValue(dto1);
                            if(value1 == null) continue;
                            map.put(dto1.getXpath3(),value1);
                        }
                        aList.add(new HashMap(map));
                        map.clear();
                    }

                    result.put(xpath1,new ArrayList<>(aList));
                }
            }else{
                HashMap<String, Object> map = new HashMap<>();
                for(int k = 0 ; k<resList.size(); k++){
                    ProcessFormItemDTO numDto = resList.get(k);
                    String value1 = getValue(numDto);
                    String xpath21 = numDto.getXpath2();
                    if(xpath21 == null || xpath21.length() == 0) continue;
                    map.put(xpath21,value1);
                }
                result.put(xpath1,new HashMap<>(map));
            }
        }

        return result;

    }

    private String getValue( ProcessFormItemDTO dto){
        if(dto.getXnumberValue()!=null) return dto.getXnumberValue().toString();
        if(dto.getXstringShortValue()!=null) return dto.getXstringShortValue();
        if(dto.getXstringLongValue()!=null) return dto.getXstringLongValue();

        return null;
    }
}


