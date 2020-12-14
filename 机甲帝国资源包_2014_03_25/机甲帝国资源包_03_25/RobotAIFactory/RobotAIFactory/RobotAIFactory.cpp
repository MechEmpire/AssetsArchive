// RobotAIFactory.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

//这里不需要做任何改动

extern "C" _declspec(dllexport) RobotAI_Interface* Export()
{
	return (RobotAI_Interface*)new RobotAI();
}

extern "C" _declspec(dllexport) void FreeRobotAIPointer(RobotAI_Interface* p)
{
	delete p;
}