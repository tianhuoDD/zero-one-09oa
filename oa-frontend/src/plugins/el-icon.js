// 这里导入你要使用的图标
// 写成多行避免解决冲突麻烦
import { Menu } from "@element-plus/icons-vue";
import { Setting } from "@element-plus/icons-vue";
import { User } from "@element-plus/icons-vue";
import { Tickets } from "@element-plus/icons-vue";
import { UploadFilled } from "@element-plus/icons-vue";
import { ArrowLeft, ArrowRight } from "@element-plus/icons-vue";
import { CirclePlusFilled } from "@element-plus/icons-vue";
import { Calendar } from "@element-plus/icons-vue";

export default (app) => {
	app.component("IconMenu", Menu);
	app.component("IconSetting", Setting);
	app.component("IconUser", User);
	app.component("IconTickets", Tickets);
	app.component("IconUpload", UploadFilled);
	app.component("IconArrowLeft", ArrowLeft);
	app.component("IconArrowRight", ArrowRight);
	app.component("IconCirclePlusFilled", CirclePlusFilled);
	app.component("IconCalendar", Calendar);
};
