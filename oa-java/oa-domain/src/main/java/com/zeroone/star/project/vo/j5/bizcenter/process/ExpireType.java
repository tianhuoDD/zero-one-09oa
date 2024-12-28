package com.zeroone.star.project.vo.j5.bizcenter.process;

public enum ExpireType {

    NEVER("never"),
    APPOINT("appoint"),
    SCRIPT("script");

    private final String message;

    ExpireType(String message) {
        this.message = message;
    }
}
