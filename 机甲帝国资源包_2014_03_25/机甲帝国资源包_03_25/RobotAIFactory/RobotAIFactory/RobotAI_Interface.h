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
//功能函数指针的宏名，使用宏名可以使调用以下功能函数更符合习惯
//---------------------------------------------------------------

//输出调试string
//用法：TRACE("操，老子挨了一枪");
#define TRACE (*trace)


//返回武器、引擎的相应静态数据信息（下面这一大坨）
//用法：get_weapon_name(WT_Cannon)
//tip:	括号里的输入参数是枚举类型 weapontypename 或 enginetypename
//		开发文档中有详细说明，你也可以在RobotAIstruct.h中直接找到它们的代码
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




//机甲AI的接口，不能做任何修改（你完全可以忽略下面的代码）
//RobotAI_Interface.h:"别盯着我看啊，我是不需看的，因为我不能做任何更改，去看和修改RobotAI.h和RobotAI.cpp！"

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