// RobotAIFactory.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"

//���ﲻ��Ҫ���κθĶ�

extern "C" _declspec(dllexport) RobotAI_Interface* Export()
{
	return (RobotAI_Interface*)new RobotAI();
}

extern "C" _declspec(dllexport) void FreeRobotAIPointer(RobotAI_Interface* p)
{
	delete p;
}