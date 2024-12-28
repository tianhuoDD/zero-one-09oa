package com.zeroone.star.bizcenter.exception;

import lombok.Getter;

@Getter
public class BizcenterException extends RuntimeException {

    private String errMessage;

    public BizcenterException() {
        super();
    }

    public BizcenterException(String errMessage) {
        super(errMessage);
        this.errMessage = errMessage;
    }

    public static void cast(String errMessage){
        throw new BizcenterException(errMessage);
    }

}
