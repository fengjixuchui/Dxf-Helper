#pragma once

//#define Send_����CALL(cdov){\
//	__asm {\
//		__asm push cdov\
//		__asm mov ecx, __������ַ\
//		__asm mov ecx, [ecx]\
//		__asm mov eax, __����CALL\
//		__asm call eax\
//	}\
//}
//
//#define Send_�ܰ�CALL(param,len,type){\
//	int cdov = 0;\
//	if (len == 1)cdov = __�ܰ�CALL;\
//	if (len == 2)cdov = __�ܰ�CALL + 0x30;\
//	if (len == 3)cdov = __�ܰ�CALL + 0x60;\
//	if (len == 4)cdov = __�ܰ�CALL + 0x90;\
//	if(type == true){\
//		__asm {\
//			__asm mov eax, param\
//			__asm push dword ptr[eax]\
//			__asm mov ecx, __������ַ\
//			__asm mov ecx, dword ptr ss : [ecx]\
//			__asm mov eax, cdov\
//			__asm call eax\
//		}\
//	}else {\
//		__asm {\
//			__asm push param\
//			__asm mov ecx, __������ַ\
//			__asm mov ecx, dword ptr ss : [ecx]\
//			__asm mov eax, cdov\
//			__asm call eax\
//		}\
//	}\
//}
//
//#define Send_����CALL(){\
//	__asm {\
//		__asm mov eax, __����CALL\
//		__asm call eax\
//	}\
//}

//static inline __declspec(naked) void Send_���ؽ�ɫ(DWORD_PTR parameter)
//{
//	/*Send_����CALL(0x7);
//	Send_����CALL();
//	__asm ret*/
//}

//static inline __declspec(naked) void Send_ѡ���ɫ(DWORD_PTR parameter)
//{
//	/*Send_����CALL(4);
//	Send_�ܰ�CALL(parameter, 3,true);
//	Send_����CALL();
//	__asm ret*/
//}
//
//static inline __declspec(naked) void Send_����˲��(DWORD_PTR parameter)
//{
//	//int max_map_id = read<int>(parameter + 0);
//	//int min_map_id = read<int>(parameter + 4);
//	//int x = read<int>(parameter + 8);
//	//int y = read<int>(parameter + 12);
//	//int goods_index = read<int>(parameter + 16);// get_goods_index_by_goods_name(L"˲���ƶ�ҩ��");
//	//if (goods_index > 0)
//	//{
//	//	Send_����CALL(237);
//	//	Send_�ܰ�CALL(parameter + 0, 2, true);
//	//	Send_�ܰ�CALL(2600014, 3,false);
//	//	Send_�ܰ�CALL(0, 1,false);
//	//	Send_�ܰ�CALL(parameter + 4, 1, true);
//	//	Send_�ܰ�CALL(parameter + 8, 1, true);
//	//	Send_�ܰ�CALL(parameter + 12, 2, true);
//	//	Send_�ܰ�CALL(parameter + 16, 2, true);
//	//	Send_����CALL();
//	//}
//	//else {
//	//	Send_����CALL(36);
//	//	Send_�ܰ�CALL(parameter + 0, 1, true);
//	//	Send_�ܰ�CALL(parameter + 0, 1, true);
//	//	Send_�ܰ�CALL(parameter + 0, 2, true);
//	//	Send_�ܰ�CALL(parameter + 0, 2, true);
//	//	Send_�ܰ�CALL(5, 1, false);
//	//	Send_�ܰ�CALL(38, 2, false);
//	//	Send_�ܰ�CALL(1, 2, false);
//	//	Send_�ܰ�CALL(0, 3, false);
//	//	Send_�ܰ�CALL(0, 1, false);
//	//	Send_����CALL();
//	//}
//}
//
//static inline __declspec(naked) void Send_����ѡͼ(DWORD_PTR parameter)
//{
//	/*Send_����CALL(15);
//	Send_�ܰ�CALL(0, 3,false);
//	Send_����CALL();
//	__asm ret*/
//}
//
//static inline __declspec(naked) void Send_ѡ�񸱱�(DWORD_PTR parameter)
//{
//	//int ������� = read<int>(parameter);
//	//int �����Ѷ� = read<int>(parameter + 4);
//	//int ����ģʽ = read<int>(parameter + 8) == -1 ? 0 : read<int>(parameter + 8);
//	//Send_����CALL(16);
//	//Send_�ܰ�CALL(�������, 3);
//	//if (������� > 7100 && ������� < 7200)
//	//{
//	//	Send_�ܰ�CALL(2, 1);
//	//	Send_�ܰ�CALL(�����Ѷ�, 2);
//	//}
//	//else
//	//{
//	//	Send_�ܰ�CALL(�����Ѷ�, 1);
//	//	Send_�ܰ�CALL(0, 2);
//	//}
//	//if (����ģʽ == ��Ԩ) { // ��Ԩ
//	//	Send_�ܰ�CALL(1, 1);
//	//	Send_�ܰ�CALL(0, 1);
//	//}
//	//else if (����ģʽ == ��ϰ) {
//	//	Send_�ܰ�CALL(0, 1);//��ϰ
//	//	Send_�ܰ�CALL(1, 1);
//	//}
//	//else {//��ͨ
//	//	Send_�ܰ�CALL(0, 1);
//	//	Send_�ܰ�CALL(0, 1);
//	//}
//	//Send_�ܰ�CALL(65535, 2);
//	//Send_�ܰ�CALL(0, 3);
//	//Send_�ܰ�CALL(0, 1);
//	//Send_�ܰ�CALL(0, 3);
//	//Send_����CALL();
//}
//
//static inline __declspec(naked) void Send_���ʰȡ(DWORD_PTR parameter)
//{
//	/*DWORD loot_address = read<int>(parameter);
//	DWORD x = read<int>(parameter + 4);
//	DWORD y = read<int>(parameter + 8);
//
//	Send_����CALL(43);
//	Send_�ܰ�CALL(loot_address, 3);
//	Send_�ܰ�CALL(0, 1);
//	Send_�ܰ�CALL(1, 1);
//	Send_�ܰ�CALL(x, 2);
//	Send_�ܰ�CALL(y, 2);
//	Send_�ܰ�CALL(0, 2);
//	Send_�ܰ�CALL(x + ((x % 4) + 1), 2);
//	Send_�ܰ�CALL(y + ((y % 4) + 1), 2);
//	Send_�ܰ�CALL(0, 2);
//	Send_�ܰ�CALL(0, 2);
//	Send_����CALL();*/
//}
//
//static inline __declspec(naked) void Send_�������(DWORD_PTR parameter)
//{
//	/*Send_����CALL(69);
//	Send_����CALL();
//
//	Send_����CALL(70);
//	Send_����CALL();
//
//	Send_����CALL(71);
//	Send_�ܰ�CALL(0, 1);
//	Send_����CALL();
//
//	Send_����CALL(1431);
//	Send_����CALL();*/
//}
//
//static inline __declspec(naked) void Send_�������(DWORD_PTR parameter)
//{
//	/*DWORD ��Ʒ�±� = read<int>(parameter);
//
//	Send_����CALL(593);
//	Send_�ܰ�CALL(2, 3);
//	Send_�ܰ�CALL(0, 3);
//	Send_����CALL();
//
//	Send_����CALL(22);
//	Send_�ܰ�CALL(0, 1);
//	Send_�ܰ�CALL(parameter, 2,true);
//	Send_�ܰ�CALL(1, 3);
//	Send_�ܰ�CALL(1000, 3);
//	Send_�ܰ�CALL(parameter * 2 + 3, 3, true);
//	Send_����CALL();*/
//}
//
//
//static inline __declspec(naked) void Send_����س�(DWORD_PTR parameter)
//{
//	/*Send_����CALL(123);
//	Send_�ܰ�CALL(createRandom(1, 1500), 3);
//	Send_�ܰ�CALL(createRandom(1, 1500), 3);
//	Send_�ܰ�CALL(createRandom(1, 1500), 3);
//	Send_�ܰ�CALL(createRandom(1, 1500), 3);
//	Send_�ܰ�CALL(createRandom(1, 1500), 3);
//	Send_�ܰ�CALL(createRandom(1, 1500), 3);
//	Send_����CALL();
//	Send_����CALL(42);
//	Send_����CALL();*/
//}