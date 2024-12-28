package com.zeroone.star.procmanager.sink;

import org.springframework.cloud.stream.annotation.Input;
import org.springframework.messaging.SubscribableChannel;

public interface AttachmentSink {

    String ATTACHMENT_UPLOAD_INPUT = "attachment-upload-input";

    @Input(ATTACHMENT_UPLOAD_INPUT)
    SubscribableChannel attachmentUploadInput();
}
