package com.zeroone.star.orgmanagement.utils;

import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.ExcelWriter;
import com.alibaba.excel.write.builder.ExcelWriterBuilder;
import com.alibaba.excel.write.metadata.WriteSheet;
import org.springframework.stereotype.Component;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Collections;
import java.util.List;

/**
 * 描述：excel模板类，通过实体类型获取excel导入模板。
 */

@Component
public class ExcelTemplate{

    /**
     * @param sheetName sheet名称
     * @param os        输出流
     * @param clazz     导出数据类型
     * @param <T>
     * @throws IOException
     */
    public <T> void export(String sheetName, OutputStream os, Class<T> clazz) throws IOException {
        ExcelWriterBuilder builder = EasyExcel.write(os, clazz);
        ExcelWriter writer = builder.build();
        //创建一个空列表作为数据，这样生成的excel中没有数据
        List<T> dataList = Collections.emptyList();
        //创建分页标签
        WriteSheet sheet = new WriteSheet();
        sheet.setSheetNo(1);
        sheet.setSheetName(sheetName);
        //向输出流中写入模板文件
        writer.write(dataList, sheet);
        writer.finish();
        os.close();
    }
}
