package com.zeroone.star.cmshome.service.impl;

import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.cmshome.entity.CmsDocumentHyk;
import com.zeroone.star.cmshome.mapper.CmsDocumentHykMapper;
import com.zeroone.star.cmshome.service.CmsDocumentHykService;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.cmshome.Category;
import com.zeroone.star.project.vo.j5.cmshome.GetColumnMessagesVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.*;
import java.util.function.Function;

@Service
public class CmsDocumentHykServiceImpl implements CmsDocumentHykService {

    @Autowired
    private CmsDocumentHykMapper cmsDocumentHykMapper;

    @Override
    public JsonVO<List<GetColumnMessagesVO>> getColumnMessages(String xid) {
        // Step 1: Retrieve data from the database using the mapper
        List<GetColumnMessagesVO> results = cmsDocumentHykMapper.selectColumnMessagesByXid(xid);

        // Step 2: Process the retrieved data (additionalFields and xcategoryNameFields)
        for (GetColumnMessagesVO result : results) {
            // Process additionalFields
            String additionalFieldsStr = result.getAdditionalFields();
            if (additionalFieldsStr != null && !additionalFieldsStr.isEmpty()) {
                // Split the comma-separated string into an array and remove duplicates
                String[] categorysArray = additionalFieldsStr.split(",");
                Set<String> categorysSet = new HashSet<>(Arrays.asList(categorysArray)); // Remove duplicates using Set
                result.setCategorys(categorysSet.toArray(new String[0])); // Set the unique categories
            } else {
                result.setCategorys(new String[0]); // If empty, set an empty array
            }

            // Process xcategoryNameFields
            String xcategoryNameFieldsStr = result.getXcategoryNameFields();
            if (xcategoryNameFieldsStr != null && !xcategoryNameFieldsStr.isEmpty()) {
                // Split the comma-separated string into an array and remove duplicates
                String[] categoryNamesArray = xcategoryNameFieldsStr.split(",");
                Set<String> categoryNamesSet = new HashSet<>(Arrays.asList(categoryNamesArray)); // Remove duplicates
                result.setCategoryNames(categoryNamesSet.toArray(new String[0])); // Set the unique category names
            } else {
                result.setCategoryNames(new String[0]); // If empty, set an empty array
            }

            // Step 3: Create category list with Category objects
            List<Category> categoryList = new ArrayList<>();
            String[] categoryIds = result.getCategorys();
            String[] categoryNames = result.getCategoryNames();

            // Ensure the arrays are of the same length before creating Category objects
            int length = Math.min(categoryIds.length, categoryNames.length);
            for (int i = 0; i < length; i++) {
                Category category = new Category(categoryIds[i], categoryNames[i]);
                categoryList.add(category);
            }

            // Step 4: Set the categoryList and clean up other fields
            result.setCategorylist(categoryList);
            result.setAdditionalFields(null); // Clean up additionalFields
            result.setXcategoryNameFields(null); // Clean up xcategoryNameFields
            result.setCategorys(null); // Clean up categorys
            result.setCategoryNames(null); // Clean up categoryNames
        }

        // Step 5: Return the result wrapped in a JsonVO with appropriate status
        return JsonVO.success(results); // Using success method from JsonVO class
    }

    @Override
    public boolean saveBatch(Collection<CmsDocumentHyk> entityList, int batchSize) {
        return false;
    }

    @Override
    public boolean saveOrUpdateBatch(Collection<CmsDocumentHyk> entityList, int batchSize) {
        return false;
    }

    @Override
    public boolean updateBatchById(Collection<CmsDocumentHyk> entityList, int batchSize) {
        return false;
    }

    @Override
    public boolean saveOrUpdate(CmsDocumentHyk entity) {
        return false;
    }

    @Override
    public CmsDocumentHyk getOne(Wrapper<CmsDocumentHyk> queryWrapper, boolean throwEx) {
        return null;
    }

    @Override
    public Map<String, Object> getMap(Wrapper<CmsDocumentHyk> queryWrapper) {
        return null;
    }

    @Override
    public <V> V getObj(Wrapper<CmsDocumentHyk> queryWrapper, Function<? super Object, V> mapper) {
        return null;
    }

    @Override
    public BaseMapper<CmsDocumentHyk> getBaseMapper() {
        return null;
    }

    @Override
    public Class<CmsDocumentHyk> getEntityClass() {
        return null;
    }
}
