package com.zeroone.star.meetingmanagement.config;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.validation.BindException;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.HttpMediaTypeException;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.MissingServletRequestParameterException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

import javax.validation.ConstraintViolation;
import javax.validation.ConstraintViolationException;
import javax.validation.Path;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

@RestControllerAdvice
public class GlobalExceptionHandler {

    @ExceptionHandler(value = Exception.class)
    public JsonVO<String> exceptionHandler(Exception e) {
        if (e instanceof HttpMediaTypeException) {
            return JsonVO.create(e.getMessage(), ResultStatus.CONTENT_TYPE_ERR);
        }
        return JsonVO.create(e.getMessage(), ResultStatus.SERVER_ERROR);
    }

    @ExceptionHandler(value = {
            MethodArgumentNotValidException.class,
            BindException.class})
    public JsonVO<String> methodArgumentNotValidHandler(Exception e) {
        BindingResult bindingResult;
        if (e instanceof MethodArgumentNotValidException) {

            bindingResult = ((MethodArgumentNotValidException) e).getBindingResult();
        } else {
            bindingResult = ((BindException) e).getBindingResult();
        }
        FieldError fieldError = bindingResult.getFieldError();
        String data = "";
        if (fieldError != null) {
            data = "[" + fieldError.getField() + "]" +
                    fieldError.getDefaultMessage();
        }
        return JsonVO.create(data, ResultStatus.PARAMS_INVALID);
    }

    @ExceptionHandler(value = {
            ConstraintViolationException.class,
            MissingServletRequestParameterException.class})
    public JsonVO<String> constraintViolationHandler(Exception e) {
        String field = "";
        String msg = "";
        if (e instanceof ConstraintViolationException) {
            ConstraintViolation<?> constraint = ((ConstraintViolationException) e)

                    .getConstraintViolations().stream().findFirst().orElse(null);
            if (constraint != null) {
                List<Path.Node> pathList = StreamSupport.stream
                                (constraint.getPropertyPath().spliterator(), false)
                        .collect(Collectors.toList());
                field = pathList.get(pathList.size() - 1).getName();
                msg = constraint.getMessage();
            }
        } else {

            field = ((MissingServletRequestParameterException) e).getParameterName();
            msg = "参数值缺失";
        }
        return JsonVO.create("[" + field + "]" + msg,
                ResultStatus.PARAMS_INVALID);
    }
}
