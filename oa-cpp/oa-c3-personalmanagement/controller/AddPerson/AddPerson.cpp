#include"AddPerson.h"

Uint64JsonVO::Wrapper AddPersonController::execAddPerson(const PersioninfoDTO::Wrapper& dto) {
	//���ݷ��ض���
	auto ans = Uint64JsonVO::createShared();
	 
	if (!dto->renyuanmingcheng || !dto->weiyibianma || !dto->shoujihaoma || !dto->xingbie) {
		ans->init(UInt64(-1), RS_PARAMS_INVALID);
		return ans;
	}
	//��Чֵ����
	if (!dto->renyuanmingcheng->size() || !dto->weiyibianma->size() || !dto->shoujihaoma->size() || !dto->xingbie->size()) {
		ans->init(UInt64(-1), RS_PARAMS_INVALID);
		return ans;
	}
	//���������Ƿ�Ϸ�
	if (dto->chushengriqi->size()) {
		string s = string(dto->chushengriqi->c_str());
		for (auto i : s) {
			if (!(i >= '0' && i <= '9') && i != '-') {
				ans->init(UInt64(-1), RS_PARAMS_INVALID);
				return ans;
			}
		}
	}
	if (dto->ruzhishijian->size()) {
		string s = string(dto->ruzhishijian->c_str());
		for (auto i : s) {
			if (!(i >= '0' && i <= '9') && i != '-') {
				ans->init(UInt64(-1), RS_PARAMS_INVALID);
				return ans;
			}
		}
	}
	//�����Ա��Ƿ�Ϸ�
	if (dto->xingbie->size()) {
		string s = string(dto->xingbie->c_str());
		if (s != "m" && s != "f" && s != "d") {
			ans->init(UInt64(-1), RS_PARAMS_INVALID);
			return ans;
		}
	}
	//�����ܼ���ʶ�Ƿ�Ϸ�
	if (dto->mijibiaoshi->size()) {
		string s = string(dto->mijibiaoshi->c_str());
		cout << " "<<s;
		if (s != "100" && s != "200" && s != "300" && s != "400") {
			ans->init(UInt64(-1), RS_PARAMS_INVALID);
			return ans;
		}
	}
	


	//// ����һ��Service
	AddServe service;
	//// ִ����������
	uint64_t id = service.saveData(dto);
	if(id)
	ans->success(UInt64(id));
	else {
		ans->fail(UInt64(id));
	}

	///////////////////////////
	

	//////////////////
	return ans;
	
}