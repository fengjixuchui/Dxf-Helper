#pragma once
#define 驱动路径 "C:\\Users\\lw\\Source\\Repos\\liwei1024\\Dxf-Helper\\x64\\Release\\RW.sys"
#define 驱动名称 "RW"



#define __HOOK消息地址 0
#define __HOOK消息还原 0
#define __MY_MESSAGE_ID 10024

#pragma once

#define TIMER_MIN 100
#define MY_MESSAGE_ID 10024 //自定义消息ID

#define __人物基址 0x05739288 
#define __当前疲劳 0x05739528 
#define __最大疲劳 0x05739530 
#define __商店基址 0x05625A90 
#define __对话基址 0x056261b4
#define __释放CALL 0x02377730 

#define __发包基址 0x0576F964
#define __缓冲CALL 0x0370BC80
#define __密包CALL 0x0370BD90
#define __发包CALL 0x0370D4C0
#define __接受CALL 0x01EC0970
#define __完成CALL 0x01EC0870
#define __提交CALL 0x01EC08F0
#define __任务基址 0x05625AC8
#define __房间编号 0x05625A88

#define __过图CALL 0x028D66A0
//#define __跳过CALL 0x1C59380
#define __游戏状态 0x551C22C
#define __角色等级 0x0560835C 

#define __召唤参数 0x0564C7B0

//#define __大区域ID 0x056062F8 
//#define __小区域ID 0x055EF7A4 

#define __解密基址 0x0577AA98 
#define __背包基址 0x05625A94 
#define __区域CALL 0x03662F60 
#define __区域参数 0x0576DBD4
//#define __城镇移动CALL 0x23DE600
#define __时间基址 0x20A028 
#define __技能CALL 0x024D57D0

//#define __地图名称 0x0564D370
#define __怪物CALL 0x027C5D20
#define __角色坐标 0x056264cc
#define __遍历取值 0x05625380
//#define __区域地址 0x5625550
#define __任务完成ECX 0x0
#define __分解CALL 0x0

#define  __攻击阵营  55938496
#define  __技能坐标  40079936
#define  __目录基址  107784148
#define  __路径基址  90331632
#define  __副本信息  90331612
#define  __路径CALL  59503072
#define  __加载CALL  57738400
#define  __分割CALL  58318400


#define __喇叭公告 0x29c0f80

#define __地图偏移 0xC8
#define __首地址 0xC0
#define __尾地址 0xC4

#define __A星_当前房间X 0xcc
#define __A星_当前房间Y 0xd0

#define __阵营偏移 0x824
#define __类型偏移 0xA4
#define __血量偏移 0x3AE4
#define __坐标偏移 0xb8
#define __人物坐标偏移 0x1D0

#define __名称偏移 0x400
#define __代码偏移 0x3FC
//#define __地图名称偏移 0x1A0
//#define __地图编号偏移 0x19c
#define __门型偏移 0xc8
#define __当前房间X 0xBCC
#define __当前房间Y 0xBD0
#define __BOSS房间X 0xC70
#define __BOSS房间Y 0xC78
#define __深渊房间X 0xB80
#define __深渊房间Y 0xB88
#define __宽高偏移 0x2AC
#define __数组偏移 0x2C0
#define __区域偏移 0xcbc4
#define __开门偏移 0x118
#define __角色下标偏移 0x108
#define __大区域偏移 0x1E4
#define __小区域偏移 0x1Ec
#define __角色数量偏移2 0x3c0
#define __当前角色数量 0xa70
#define __最大角色数量 0xa78



#define 搬砖 1
#define 剧情 2
#define 深渊 3
#define 黄龙 4
#define 练习 5

// NPC编号
#define 格蓝迪门口 0
#define 克伦特 1
#define 歌兰蒂斯 2
#define 月光酒馆 3

// 副本编号
#define 格蓝迪 104

//键码
#define VK_0  48
#define VK_1  49
#define VK_2  50
#define VK_3  51
#define VK_4  52
#define VK_5  53
#define VK_6  54
#define VK_7  55
#define VK_8  56
#define VK_9  57
#define VK_A  65
#define VK_B  66
#define VK_C  67
#define VK_D  68
#define VK_E  69
#define VK_F  70
#define VK_G  71
#define VK_H  72
#define VK_I  73
#define VK_J  74
#define VK_K  75
#define VK_L  76
#define VK_M  77
#define VK_N  78
#define VK_O  79
#define VK_P  80
#define VK_Q  81
#define VK_R  82
#define VK_S  83
#define VK_T  84
#define VK_U  85
#define VK_V  86
#define VK_W  87
#define VK_X  88
#define VK_Y  89
#define VK_Z  90


#define Code_成长之泉水 490007518
#define Code_肉块 10158893
#define Code_鸡腿 10158901



