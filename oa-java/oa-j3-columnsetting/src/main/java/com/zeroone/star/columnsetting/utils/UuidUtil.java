package com.zeroone.star.columnsetting.utils;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.UUID;

public class UuidUtil {

    public static String getUuid(){
        UUID uuid = UUID.randomUUID();
        LocalDateTime now = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyyMMddHHmm");
        String format = now.format(formatter);
        String result = format + uuid.toString();
        return result;
    }

}
