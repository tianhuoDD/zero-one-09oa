package com.zeroone.star.user.base;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.extension.activerecord.Model;
import java.util.Date;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * Entity基类
 *
 * @author valarchie
 */
@EqualsAndHashCode(callSuper = true)
@Data
public class BaseEntity<T extends Model<?>> extends Model<T> {

    @TableField(value = "xcreateTime", fill = FieldFill.INSERT)
    private Date xcreateTime;

    @TableField(value = "xupdateTime", fill = FieldFill.UPDATE)
    private Date xupdateTime;


}
