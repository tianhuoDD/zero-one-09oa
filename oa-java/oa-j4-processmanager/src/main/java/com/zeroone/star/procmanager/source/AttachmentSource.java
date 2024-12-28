package com.zeroone.star.procmanager.source;

import org.springframework.cloud.stream.annotation.Output;
import org.springframework.messaging.MessageChannel;

public interface AttachmentSource {

    @Output("attachment-upload-output")
    MessageChannel attachmentUploadOutput();

}