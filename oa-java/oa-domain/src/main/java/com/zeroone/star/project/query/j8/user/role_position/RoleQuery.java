package com.zeroone.star.project.query.j8.user.role_position;
import com.zeroone.star.project.query.PageQuery;
import java.io.Serializable;
import lombok.Data;
import lombok.EqualsAndHashCode;

@EqualsAndHashCode(callSuper = true)
@Data
public class RoleQuery extends PageQuery implements Serializable {

    private String roleName;

}
