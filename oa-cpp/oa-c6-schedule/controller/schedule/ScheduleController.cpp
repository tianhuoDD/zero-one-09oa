#include "stdafx.h"
#include "ScheduleController.h"
#include "../../service/event/EventService.h"
#include "../ApiDeclarativeServicesHelper.h"

/**
 * ����״̬��ʾ��Ϣ
 */
#ifdef LINUX
#define RS_REPEAT_LOGIC_ERR ResultStatus("repeat related parameter errors", 9919)
#define RS_EMPTY_ERR ResultStatus("parameter is empty", 9918)
#define RS_OVERSIZE_ERR ResultStatus("comment oversize", 9917)
#define RS_DATEFORMAT_ERR ResultStatus("date format err", 9916)
#define RS_DBOPTION_ERR ResultStatus("database operation error", 9915)
#else
#define RS_REPEAT_LOGIC_ERR ResultStatus("repeat related parameter errors", 9919)
#define RS_EMPTY_ERR ResultStatus("parameter is empty", 9918)
#define RS_OVERSIZE_ERR ResultStatus("comment oversize", 9917)
#define RS_DATEFORMAT_ERR ResultStatus("date format err", 9916)
#define RS_DBOPTION_ERR ResultStatus("database operation error", 9915)
const int FLAG1 = -1;
#endif

bool validateDateFormat(const string& dateTime) {
	std::tm tm = {};
	std::istringstream ss(dateTime);

	// �����ַ�������ʽΪ"YYYY-MM-DD HH:MM:SS"
	ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");

	// �������ʧ�ܻ��ж����ַ���˵����ʽ����ȷ
	return !ss.fail() && ss.eof();
}

Uint64JsonVO::Wrapper ScheduleController::execAddSchdule(const ScheduleInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	bool flag = true;

	if (dto->xcalendarId == "" || !dto->xcalendarId) {    //�ؼ�����Ϊ��
		flag = false;
		jvo->init(flag, RS_EMPTY_ERR);
		return jvo;
	}

	if ((dto->xrepeat != "NO" && dto->xrecurrenceRule == "")) {  //�ظ��߼�����
		flag = false;
		jvo->init(flag, RS_REPEAT_LOGIC_ERR);
		return jvo;
	}

	if (dto->xcomment->size() > 255) {  //����̫��
		flag = false;
		jvo->init(flag, RS_EMPTY_ERR);
		return jvo;
	}

	if(!validateDateFormat(dto->xstartTime) || !validateDateFormat(dto->xendTime)){  //���ڸ�ʽ����
		flag = false;
		jvo->init(flag, RS_DATEFORMAT_ERR);
		return jvo;
	}

	payload.getUsername();
	// ����һ��Service
	EventService service;
	// ִ����������
	//cout << payload.getUsername() << endl;
	bool id = service.saveEventData(dto, payload.getXsequence());
	if (id > 0) {
		jvo->success(id);
	}
	else
	{
		jvo->init(id, RS_DBOPTION_ERR);
		
	}
	//��Ӧ���
	return jvo;
	//return ScheduleInfoJsonVO::Wrapper();
}

Uint64JsonVO::Wrapper ScheduleController::execModifySchdule(const ScheduleInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	bool flag = true;
	// ����У��
	if (!dto->xid || dto->xid == "")    //�ؼ�����Ϊ��
	{
		flag = false;
		jvo->init(flag, RS_EMPTY_ERR);
		return jvo;
	}

	// ����У��

	if (dto->xcalendarId == "" || !dto->xcalendarId) {    //�ؼ�����Ϊ��
		flag = false;
		jvo->init(flag, RS_EMPTY_ERR);
		return jvo;
	}

	if ((dto->xrepeat != "NO" && dto->xrecurrenceRule == "")) {  //�ظ��߼�����
		flag = false;
		jvo->init(flag, RS_REPEAT_LOGIC_ERR);
		return jvo;
	}

	if (dto->xcomment->size() > 255) {  //����̫��
		flag = false;
		jvo->init(flag, RS_EMPTY_ERR);
		return jvo;
	}

	if (!validateDateFormat(dto->xstartTime) || !validateDateFormat(dto->xendTime)) {  //���ڸ�ʽ����
		flag = false;
		jvo->init(flag, RS_DATEFORMAT_ERR);
		return jvo;
	}


	// ����һ��Service
	EventService service;
	// ִ�������޸�
	bool id;
	id = service.updateEventData(dto, payload.getXsequence());

	if (id) jvo->success(id);
	else jvo->init(id, RS_DBOPTION_ERR);
	
	// ��Ӧ���
	return jvo;
	//return StringJsonVO::Wrapper();
}

Uint64JsonVO::Wrapper ScheduleController::execRemoveSchdule(const ScheduleDelDTO::Wrapper& dto)
{

	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	bool flag = true;
	if (dto->xidList->empty() || dto->xidList->size() == 0)
	{
		flag = false;
		jvo->init(flag, RS_EMPTY_ERR);
		return jvo;
	}
	// ����һ��Service
	EventService service;
	// ִ������ɾ��
	bool id;
	id = service.removeEventData(dto);

	if (id) jvo->success(id);
	else jvo->init(id, RS_DBOPTION_ERR);

	return jvo;
}
