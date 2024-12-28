package com.zeroone.star.columnsetting.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.util.BooleanUtil;
import cn.hutool.core.util.ObjectUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.columnsetting.entity.CmsForm;
import com.zeroone.star.columnsetting.mapper.CmsFormMapper;
import com.zeroone.star.columnsetting.service.ICmsFormService;
import com.zeroone.star.columnsetting.utils.UuidUtil;
import com.zeroone.star.project.j3.formattribute.dto.ColumnFormDTO;
import com.zeroone.star.project.j3.formattribute.vo.ColumnFormVO;
import com.zeroone.star.project.vo.JsonVO;
import net.minidev.json.writer.UpdaterMapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 *  栏目表单实现类
 * </p>
 *
 * @author lenyan
 * @since 2024-10-19
 */
@Service
public class CmsFormServiceImpl extends ServiceImpl<CmsFormMapper, CmsForm> implements ICmsFormService {

    @Resource
    private CmsFormMapper cmsFormMapper;

    /**
     * 添加栏目表单
     * @param columnFormDTO
     * @return
     */
    @Override
    public JsonVO<ColumnFormVO> addColumnForm(ColumnFormDTO columnFormDTO) {
        CmsForm cmsForm = BeanUtil.toBean(columnFormDTO, CmsForm.class);
        String Xsequence = UuidUtil.getUuid();
        cmsForm.setXsequence(Xsequence);

        boolean save = this.save(cmsForm);
        if(BooleanUtil.isTrue(save)) {
            return JsonVO.success(BeanUtil.toBean(cmsForm, ColumnFormVO.class));
        } else {
            throw new RuntimeException("添加栏目表单失败");
        }
    }

    /**
     * 删除栏目表单
     * @param id
     * @return
     */
    @Override
    public JsonVO<Boolean> deleteColumnForm(String id) {
        if(ObjectUtil.isEmpty(id)) {
            throw new RuntimeException("删除栏目表单id为空");
        }
        boolean deleted = removeById(id);
        if(BooleanUtil.isFalse(deleted)) {
            throw new RuntimeException("删除栏目表单失败");
        }
        return JsonVO.success(deleted);
    }



    @Override
    public JsonVO<ColumnFormVO> modifyColumnForm(ColumnFormDTO cmsFormDTO) {
        if (ObjectUtil.isEmpty(cmsFormDTO)) {
            throw new RuntimeException("修改栏目表单参数为空");
        }
        CmsForm cmsForm = BeanUtil.toBean(cmsFormDTO, CmsForm.class);

        // 构建更新条件
        UpdateWrapper<CmsForm> updateWrapper = new UpdateWrapper<>();
        updateWrapper.eq("xid", cmsFormDTO.getXid());

        // 执行更新操作
        boolean update = update(cmsForm, updateWrapper);
        if (BooleanUtil.isFalse(update)) {
            throw new RuntimeException("修改栏目表单失败");
        }
        return JsonVO.success(BeanUtil.toBean(cmsForm, ColumnFormVO.class));
    }


    @Override
    public JsonVO<ColumnFormVO> queryColumnForm(String id) {
        if(ObjectUtil.isEmpty(id)) {
            throw new RuntimeException("查询栏目表单id为空");
        } else {
            CmsForm cmsForm = getById(id);
            ColumnFormVO columnFormVO = BeanUtil.toBean(cmsForm, ColumnFormVO.class);
            return JsonVO.success(columnFormVO);
        }
    }

    @Override
    public JsonVO<List<ColumnFormVO>> queryColumnFormList(String id) {
        if(ObjectUtil.isEmpty(id)) {
            throw new RuntimeException("查询栏目表单列表的appid为空");
        } else {
            LambdaQueryWrapper<CmsForm> queryWrapper = new LambdaQueryWrapper<>();
            queryWrapper.eq(CmsForm::getXappId, id);
            List<CmsForm> cmsForms = list(queryWrapper);
            return JsonVO.success(BeanUtil.copyToList(cmsForms, ColumnFormVO.class));
        }
    }
}
