#include "pch.h"
#include "game_status_3.h"
#include "game_astar.hpp"


game_status_3::game_status_3()
{
}


game_status_3::~game_status_3()
{
}
//�Ƿ��ѿ���
bool game_status_3::door_whether_open()
{

}
//�Ƿ�boss����
bool game_status_3::room_whether_boss()
{

}

// �Ƿ���Ԩ����
bool game_status_3::room_whether_abyss()
{

}
// �ж�Ӫ��
bool game_status_3::campfire_whether_exist()
{

}
// �����Ƿ����
bool game_status_3::monster_whether_exist()
{

}
// ��ȡ������Ϣ
MAP_OBJECT_STRUCT game_status_3::get_object_info(DWORD object_pointer)
{
	MAP_OBJECT_STRUCT object;
	DWORD pos_pointer;
	object.address = object_pointer;
	object.type = read<DWORD>(object_pointer + __����ƫ��);
	object.camp = read<DWORD>(object_pointer + __��Ӫƫ��);
	object.health_point = read<DWORD>(object_pointer + __Ѫ��ƫ��);
	object.code = read<DWORD>(object_pointer + __����ƫ��);
	object.name = read_wstring(read<DWORD>(object_pointer + __����ƫ��), 100);
	if (object.type == 273)
	{
		pos_pointer = read<int>(object_pointer + __��������ƫ��);
		object.x = (int)read<float>(__��ɫ���� + 0);
		object.y = (int)read<float>(__��ɫ���� + 4);
		object.z = (int)read<float>(__��ɫ���� + 8);
	}
	else {
		pos_pointer = read<int>(object_pointer + __����ƫ��);
		object.x = (int)read<float>(pos_pointer + 0x10);
		object.y = (int)read<float>(pos_pointer + 0x14);
		object.z = (int)read<float>(pos_pointer + 0x18);
	}
	return object;
}

DWORD game_status_3::get_map_address()
{

	return read_offset<int>(__�����ַ, { __��ͼƫ�� });
}

DWORD game_status_3::get_map_start_address()
{
	return read<int>(get_map_address() + __�׵�ַ);
}

int game_status_3::get_map_object_count(DWORD map_start_address)
{
	return  (read<int>(get_map_address() + __β��ַ) - map_start_address) / 4;
}

void game_status_3::move_to_next_room(int direction)
{
	DWORD temp_data;
	DWORD coordinate_struct;
	int x, y, xf, yf, cx, cy = 0;
	temp_data = read<DWORD>(__�̵��ַ - 8);
	temp_data = read<DWORD>(temp_data + __ʱ���ַ);
	temp_data = read<DWORD>(temp_data + 140);
	coordinate_struct = temp_data + (direction + direction * 8) * 4 + 5948 + (direction * 4);
	x = read<int>(coordinate_struct + 0x0);
	y = read<int>(coordinate_struct + 0x4);
	xf = read<int>(coordinate_struct + 0x8);
	yf = read<int>(coordinate_struct + 0xc);
	if (direction == 0)
	{
		cx = x + xf + 20;
		cy = y + yf / 2;
		doKeyPress(VK_NUMPAD1);
	}
	else if (direction == 1)
	{
		cx = x - 20;
		cy = y + yf / 2;
		doKeyPress(VK_NUMPAD3);
	}
	else if (direction == 2)
	{
		cx = x + xf / 2;
		cy = y + yf + 20;
	}
	else if (direction == 3)
	{
		cx = x + xf / 2;
		cy = y - 20;
	}
	Sleep(200);
	//main_thread_exec_call(Call_����Call, { read<int>(__�����ַ),cx,cy,0 });
	Sleep(200);
	//main_thread_exec_call(Call_����Call, { read<int>(__�����ַ),(x + xf / 2), y, 0 });
	Sleep(1000);
}

// ��ӡ����������Ϣ
void game_status_3::output_map_objects_info()
{
	DWORD map_start_address = get_map_start_address();
	green_print("map_start_address %x\n", map_start_address);
	DWORD map_object_count = get_map_object_count(map_start_address);
	green_print("map_object_count %d\n", map_object_count);
	MAP_OBJECT_STRUCT _ObjectInfo;
	DWORD object_address;
	for (size_t i = 0; i < map_object_count; i++)
	{
		object_address = read<int>(map_start_address + i * 4);
		if (object_address <= 0)continue;
		_ObjectInfo = get_object_info(object_address);
		green_print("=====================================");
		green_print("address 0x%x", _ObjectInfo.address);
		green_print("code %d", _ObjectInfo.code);
		green_print("type %d", _ObjectInfo.type);
		green_print("camp %d", _ObjectInfo.camp);
		green_print("health_point %d", _ObjectInfo.health_point);
		green_print("pos %d,%d,%d", _ObjectInfo.x, _ObjectInfo.y, _ObjectInfo.z);
		green_print("name %s", _ObjectInfo.name.c_str());
	}
}

