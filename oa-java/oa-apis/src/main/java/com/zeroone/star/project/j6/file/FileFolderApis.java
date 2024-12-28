package com.zeroone.star.project.j6.file;

import com.zeroone.star.project.vo.JsonVO;

/**
 * 文件夹操作相关接口声明
 */
public interface FileFolderApis {
    /**
     * 修改文件夹名称
     * @param xid
     * @param new_xname
     * @return
     */
    JsonVO<Integer> modifyFileFolderName(String xid,String new_xname,String xsuperior);
}
