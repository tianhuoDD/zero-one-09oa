package com.zeroone.star.oaj2msgservice.controller;

import com.zeroone.star.oaj2msgservice.service.MessageSendService;
import com.zeroone.star.project.components.mail.MailComponent;
import com.zeroone.star.project.components.mail.MailMessage;
import com.zeroone.star.project.components.sms.aliyun.SmsComponent;
import com.zeroone.star.project.components.sms.aliyun.SmsResult;
import com.zeroone.star.project.dto.j2.message.service.MessagePhoneSendDTO;
import com.zeroone.star.project.dto.mail.MailDTO;
import com.zeroone.star.project.j2.message.service.MessageSendApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.message.service.MessageSendMailVO;
import com.zeroone.star.project.vo.j2.message.service.MessageSendPhoneVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Value;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 消息发送
 * @author qingjiu
 */
@RestController
@Api(tags = "消息发送")
@RequestMapping("/message-note")
@Slf4j
public class MessageSvcSendController implements MessageSendApis {


    @Resource
    private MailComponent mailComponent;

    @Resource
    private MessageSendService messageSendService;

    @Resource
    private SmsComponent smsComponent;

    /**
     * signName       签名名称，如：阿里云短信测试
     */
    @Value("${aliyun.sms.signName}")
    private String signName;

    /**
     * 短信模板CODE，如：SMS_15******
     */
    @Value("${aliyun.sms.templateCode}")
    private String templateCode;

    /**
     * 发送单条短信消息
     * @param messagePhoneSendDTO
     * @return
     */

    @Override
    @ApiOperation("发送单条短信消息")
    @PostMapping("/sendSinglePhoneMessage")
    public JsonVO<MessageSendPhoneVO> sendSinglePhoneMessage(MessagePhoneSendDTO messagePhoneSendDTO) {
        // 创建一个HashMap用于存储短信的参数
        HashMap<String, String> param = new HashMap<>();
        // 从DTO中获取短信内容并放入参数中
        param.put("body", messagePhoneSendDTO.getXbody());

        // 初始化短信发送返回对象为 null
        MessageSendPhoneVO messageSendPhoneVO = null;
        try {
            // 判断接收人手机号列表是否为空
            if (messagePhoneSendDTO.getXpersons() == null || messagePhoneSendDTO.getXpersons().isEmpty()) {
                log.error("接收人手机号为空");
                // 返回失败响应
                return JsonVO.fail(null);
            }

            // 获取第一个接收人的手机号
            String recipientPhone = messagePhoneSendDTO.getXpersons().get(0);
            if (!isValidPhoneNumber(recipientPhone)) {
                log.error("接收人手机号无效");
                // 返回失败响应
                return JsonVO.fail(null);
            }

            // 判断签名名称和模板代码是否为空
            if (signName == null || signName.trim().isEmpty()) {
                log.error("短信签名名称为空");
                // 返回失败响应
                return JsonVO.fail(null);
            }
            if (templateCode == null || templateCode.trim().isEmpty()) {
                log.error("短信模板代码为空");
                // 返回失败响应
                return JsonVO.fail(null);
            }

            // 调用smsComponent发送短信，传入接收人手机号、模板名称、模板ID和参数
            SmsResult result = smsComponent.sendSms(recipientPhone, signName, templateCode, param);

            // 判断短信是否发送成功
            if ("OK".equals(result.getCode())) {
                // 初始化成功返回对象
                messageSendPhoneVO = new MessageSendPhoneVO();
                messageSendPhoneVO.setSendTime(LocalDateTime.now());
                messageSendPhoneVO.setCode(result.getCode());
                messageSendPhoneVO.setMessage(result.getMessage());
                messageSendPhoneVO.setRecipientPhone(recipientPhone);

                // 将发送记录保存到数据库中
                boolean saveResult = messageSendService.saveSinglePhone(messagePhoneSendDTO);
                if (!saveResult) {
                    log.error("保存发送记录失败");
                    return JsonVO.fail(null);
                }
            } else {
                // 初始化失败返回对象
                messageSendPhoneVO = new MessageSendPhoneVO();
                log.error("短信发送失败: {}", result.getMessage());
                messageSendPhoneVO.setErrorCode(result.getCode());
                messageSendPhoneVO.setErrorDescription(result.getMessage());
                return JsonVO.fail(messageSendPhoneVO);
            }

            log.info("短信发送成功: {}, 收件人: {}", result.getCode(), recipientPhone);
        } catch (Exception e) {
            // 捕获发送短信过程中的异常
            log.error("发送短信过程中发生异常", e);
            messageSendPhoneVO = new MessageSendPhoneVO();
            messageSendPhoneVO.setErrorCode("ERROR");
            messageSendPhoneVO.setErrorDescription("发送短信失败: " + e.getMessage());
            return JsonVO.fail(messageSendPhoneVO);
        }

        // 返回成功响应，包含发送信息
        return JsonVO.success(messageSendPhoneVO);

    }

    /**
     * 校验手机号的方法
     * @param phoneNumber
     * @return
     */
    private boolean isValidPhoneNumber(String phoneNumber) {
        if (phoneNumber == null || phoneNumber.trim().isEmpty()) {
            log.error("接收人手机号无效");
            return false;
        }
        if (!phoneNumber.matches("^1[3-9]\\d{9}$")) {
            // 记录错误日志，提示手机号格式不正确
            log.error("接收人手机号格式不正确: {}", phoneNumber);
            return false;
        }
        return true;
    }




    /**
     * 发送批量短信消息
     * @param messagePhoneSendDTO
     * @return
     */
    @Override
    @ApiOperation("发送批量短信消息")
    @PostMapping("/sendBatchPhoneMessages")
    public JsonVO<MessageSendPhoneVO> sendBatchPhoneMessages(MessagePhoneSendDTO messagePhoneSendDTO) {
        // 参数判空处理
        if (messagePhoneSendDTO == null || messagePhoneSendDTO.getXpersons() == null || messagePhoneSendDTO.getXpersons().isEmpty()) {
            log.error("参数 messagePhoneSendDTO 或接收人列表为空");
            return JsonVO.fail(null);
        }
        if (signName == null || signName.trim().isEmpty()) {
            log.error("短信签名名称为空");
            return JsonVO.fail(null);
        }
        if (templateCode == null || templateCode.trim().isEmpty()) {
            log.error("短信模板代码为空");
            return JsonVO.fail(null);
        }
        if (messagePhoneSendDTO.getXbody() == null || messagePhoneSendDTO.getXbody().trim().isEmpty()) {
            log.error("短信内容为空");
            return JsonVO.fail(null);
        }

        List<String> phoneNumbers = new ArrayList<>();
        List<String> signNames = new ArrayList<>();
        List<Map<String, String>> templateParams = new ArrayList<>();

        MessageSendPhoneVO messageSendPhoneVO = null;
        try {
            // 添加参数
            for (String phone : messagePhoneSendDTO.getXpersons()) {
                phoneNumbers.add(phone);
                signNames.add(signName);
                HashMap<String, String> param = new HashMap<>();
                param.put("body", messagePhoneSendDTO.getXbody());
                templateParams.add(param);
            }

            // 调用批量发送短信方法
            SmsResult result = smsComponent.sendSmsBatch(phoneNumbers, signNames, templateCode, templateParams);

            // 处理发送结果
            if ("OK".equals(result.getCode())) {
                messageSendPhoneVO = new MessageSendPhoneVO();
                messageSendPhoneVO.setCode(result.getCode());
                messageSendPhoneVO.setSendTime(LocalDateTime.now());
                messageSendPhoneVO.setMessage(result.getMessage());
                String phones = String.join(",", phoneNumbers);
                messageSendPhoneVO.setRecipientPhone(phones);
                log.info("批量短信信息封装成功: 收件人: {}, 返回码: {}", phones, result.getCode());


                boolean saveResult = messageSendService.saveBatchPhone(messagePhoneSendDTO);
                if(!saveResult){
                    log.error("批量短信信息保存失败: 收件人: {}", phones);
                    return JsonVO.fail(null);
                }
            } else {
                messageSendPhoneVO = new MessageSendPhoneVO();
                messageSendPhoneVO.setErrorCode(result.getCode());
                messageSendPhoneVO.setErrorDescription(result.getMessage());

                log.error("批量短信发送失败: 收件人: {}, 错误码: {}, 错误信息: {}", String.join(",", phoneNumbers), result.getCode(), result.getMessage());
                return JsonVO.fail(messageSendPhoneVO);
            }
        } catch (Exception e) {
            // 捕获发送短信过程中的异常
            log.error("批量发送短信过程中发生异常: 收件人: {}, 异常信息: {}", String.join(",", phoneNumbers), e.getMessage(), e);

            messageSendPhoneVO = new MessageSendPhoneVO();
            messageSendPhoneVO.setErrorCode("ERROR");
            messageSendPhoneVO.setErrorDescription("发送短信失败: " + e.getMessage());
            return JsonVO.fail(messageSendPhoneVO);
        }

        return JsonVO.success(messageSendPhoneVO);
    }


    /**
     * 发送单条（多条）邮件消息
     * @param mailDTO
     * @return JsonVO
     */
    @Override
    @ApiOperation("发送单条(多条)邮件消息")
    @PostMapping("/sendMailMessage")
    public JsonVO<MessageSendMailVO> sendMailMessage(MailDTO mailDTO) {
        // 参数判空处理
        if (mailDTO == null) {
            log.error("参数 mailDTO 为空");
            return JsonVO.fail(null);
        }
        if (mailDTO.getTo() == null || mailDTO.getTo().isEmpty()) {
            log.error("收件人列表为空");
            return JsonVO.fail(null);
        }
        if (mailDTO.getSubject() == null || mailDTO.getSubject().trim().isEmpty()) {
            log.error("邮件主题为空");
            return JsonVO.fail(null);
        }
        if (mailDTO.getText() == null || mailDTO.getText().trim().isEmpty()) {
            log.error("邮件内容为空");
            return JsonVO.fail(null);
        }

        // 封装邮件消息
        MailMessage mailMessage = new MailMessage();
        mailMessage.setTo(mailDTO.getTo());
        mailMessage.setCc(mailDTO.getCc());
        mailMessage.setBcc(mailDTO.getBcc());
        mailMessage.setSubject(mailDTO.getSubject());
        mailMessage.setText(mailDTO.getText());
        mailMessage.setMultipartFiles(mailDTO.getMultipartFiles());

        MessageSendMailVO messageSendMailVO = new MessageSendMailVO();
        try {
            // 发送邮件
            MailMessage result = mailComponent.sendMail(mailMessage);

            if (result != null && "ok".equalsIgnoreCase(result.getStatus())) {
                // 邮件发送成功，封装返回值
                prepareSuccessResponse(messageSendMailVO, mailDTO);
                log.info("邮件发送成功: 收件人: {}, 主题: {}", String.join(",", mailDTO.getTo()), mailDTO.getSubject());

                // 保存邮件消息并处理保存结果
                JsonVO<MessageSendMailVO> saveResult = saveMailMessage(mailDTO);
                if (saveResult != null) {
                    // 如果保存失败，直接返回错误响应
                    log.error("邮件消息保存失败: 收件人: {}, 主题: {}", String.join(",", mailDTO.getTo()), mailDTO.getSubject());
                    return saveResult;
                }

            } else {
                // 邮件发送失败，设置错误信息
                log.error("邮件发送失败: 收件人: {}, 主题: {}, 错误信息: {}", String.join(",", mailDTO.getTo()), mailDTO.getSubject(), result != null ? result.getStatus() : "未知错误");
                return prepareErrorResponse(messageSendMailVO, result);
            }
        } catch (Exception e) {
            // 捕获发送邮件过程中的异常
            log.error("发送邮件过程中发生异常: 收件人: {}, 主题: {}, 异常信息: {}", String.join(",", mailDTO.getTo()), mailDTO.getSubject(), e.getMessage(), e);
            messageSendMailVO.setErrorCode("ERROR");
            messageSendMailVO.setErrorDescription("发送邮件失败: " + e.getMessage());
            return JsonVO.fail(messageSendMailVO);
        }

        return JsonVO.success(messageSendMailVO);
    }


    /**
     * 保存邮件消息
     * @param mailDTO
     */
    private JsonVO<MessageSendMailVO> saveMailMessage(MailDTO mailDTO) {
        if (!messageSendService.save(mailDTO)) {
            MessageSendMailVO messageSendMailVO = new MessageSendMailVO();
            messageSendMailVO.setErrorCode("SAVE_ERROR");
            messageSendMailVO.setErrorDescription("邮件消息保存失败");
            // 返回保存失败的错误响应
            return JsonVO.fail(messageSendMailVO);
        }
        // 保存成功，返回null，表示没有错误
        return null;
    }

    /**
     * 封装成功响应
     * @param response
     * @param mailDTO
     */
    private void prepareSuccessResponse(MessageSendMailVO response, MailDTO mailDTO) {
        response.setSendTime(LocalDateTime.now());
        response.setCode("OK");
        response.setMessage("邮件发送成功");
        response.setRecipientEmail(mailDTO.getTo());
    }

    /**
     * 封装错误响应
     * @param response
     * @param result
     * @return
     */
    private JsonVO<MessageSendMailVO> prepareErrorResponse(MessageSendMailVO response, MailMessage result) {
        response.setErrorCode("ERROR");
        response.setErrorDescription(result != null ? "邮件发送失败" : "发送结果为空");
        return JsonVO.fail(response);
    }




}
