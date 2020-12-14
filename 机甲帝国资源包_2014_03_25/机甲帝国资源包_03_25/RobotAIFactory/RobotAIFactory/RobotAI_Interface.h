#pragma once

using namespace std;


typedef void (*FP_TRACE)(string);
typedef string (*FP_GET_STRING_W)(weapontypename);
typedef int (*FP_GET_INT_W)(weapontypename);
typedef double (*FP_GET_DOUBLE_W)(weapontypename);
typedef string (*FP_GET_STRING_E)(enginetypename);
typedef int (*FP_GET_INT_E)(enginetypename);
typedef double (*FP_GET_DOUBLE_E)(enginetypename);


//---------------------------------------------------------------
//���ܺ���ָ��ĺ�����ʹ�ú�������ʹ�������¹��ܺ���������ϰ��
//---------------------------------------------------------------

//�������string
//�÷���TRACE("�٣����Ӱ���һǹ");
#define TRACE (*trace)


//�����������������Ӧ��̬������Ϣ��������һ���磩
//�÷���get_weapon_name(WT_Cannon)
//tip:	����������������ö������ weapontypename �� enginetypename
//		�����ĵ�������ϸ˵������Ҳ������RobotAIstruct.h��ֱ���ҵ����ǵĴ���
#define get_weapon_name (*getWeaponName)
#define get_weapon_damage (*getWeaponDamage)
#define get_weapon_ammo (*getWeaponAmmo)
#define get_weapon_coolingTime (*getWeaponCoolingTime)
#define get_weapon_inaccuracy (*getWeaponInaccuracy)
#define get_weapon_rotationSpeed (*getWeaponRotationSpeed)
#define get_engine_name (*getEngineName)
#define get_engine_maxSpeed (*getEngineMaxSpeed)
#define get_engine_maxHp (*getEngineMaxHp)
#define get_engine_rotationSpeed (*getEngineRotationSpeed)
#define get_engine_acceleration (*getEngineAcceleration)

//----------------------------------------------------------------------------




//����AI�Ľӿڣ��������κ��޸ģ�����ȫ���Ժ�������Ĵ��룩
//RobotAI_Interface.h:"�����ҿ��������ǲ��迴�ģ���Ϊ�Ҳ������κθ��ģ�ȥ�����޸�RobotAI.h��RobotAI.cpp��"

class RobotAI_Interface
{
public:
	virtual ~RobotAI_Interface(){};

	virtual void Update(RobotAI_Order& , const RobotAI_BattlefieldInformation&, int)=0;
	virtual void ChooseArmor(weapontypename&,enginetypename&,bool)=0;
	

	virtual string GetName()=0;
	virtual string GetAuthor()=0;
	virtual int GetWeaponRed()=0;
	virtual int GetWeaponGreen()=0;
	virtual int GetWeaponBlue()=0;
	virtual int GetEngineRed()=0;
	virtual int GetEngineGreen()=0;
	virtual int GetEngineBlue()=0;
	///////////////////////////////////////





	
	FP_TRACE trace;	
	//weapon
	FP_GET_STRING_W getWeaponName;
	FP_GET_INT_W getWeaponDamage;
	FP_GET_INT_W getWeaponAmmo;
	FP_GET_INT_W getWeaponCoolingTime;
	FP_GET_DOUBLE_W getWeaponInaccuracy;
	FP_GET_DOUBLE_W getWeaponRotationSpeed;
	//engine
	FP_GET_STRING_E getEngineName;
	FP_GET_DOUBLE_E getEngineMaxSpeed;
	FP_GET_INT_E getEngineMaxHp;
	FP_GET_DOUBLE_E getEngineRotationSpeed;
	FP_GET_DOUBLE_E getEngineAcceleration;
	/////////////////////////////////////////////


	//Trigger Function
	virtual void onBattleStart(const RobotAI_BattlefieldInformation&,int)=0;
	virtual void onBattleEnd(const RobotAI_BattlefieldInformation&,int)=0;
	virtual void onHit(bullettypename)=0;
	
};