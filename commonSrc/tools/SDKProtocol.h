﻿//版本更新记录 
//				3.0.3 
//					(1)升级文件支持超大文件
//				3.0.4 
//					(1)AlgMapData支持超大数组传输，AlgMapData 中map[] 改为 *map
//					(2)内部支持数据录制与回放
#ifndef __NAVI_PACK_PROTOCOL_H__
#define __NAVI_PACK_PROTOCOL_H__

#define LIDAR_RESOLUTION 360
#define MAX_TARGET_LIST_SIZE 360
#define UNIFIED_SENSOR_RESOLUTION 360
#define MAX_MAP_SIZE	(2000*2000)

#define FILE_PATH_MAX_LEN 128
/// 获得当前SDK的版本号
/// @return 返回NaviPack对象的ID
/// @note 属性值由3个部分组成: 主版本号(Bits 24 ~31), 子版本号(Bits 16 ~ 23), 编译号(Bits 0 ~ 15)
#define MAIN_VER		3
#define CHILD_VER		4
#define COMPILE_VER		0
#define NAVIPACK_VISION		(MAIN_VER<<24 | CHILD_VER << 16 | COMPILE_VER)




typedef float f32;
typedef double f64;

typedef signed long long s64;
typedef signed int  s32;
typedef signed short s16;
typedef signed char  s8;

typedef signed long long const sc64;
typedef signed int  const sc32;  /* Read Only */
typedef signed short const sc16;  /* Read Only */
typedef signed char  const sc8;   /* Read Only */

typedef volatile signed long long vs64;
typedef volatile signed int  vs32;
typedef volatile signed short vs16;
typedef volatile signed char  vs8;

typedef volatile signed long long  const vsc64;
typedef volatile signed int  const vsc32;  /* Read Only */
typedef volatile signed short const vsc16;  /* Read Only */
typedef volatile signed char  const vsc8;   /* Read Only */

typedef unsigned long long u64;
typedef unsigned int  u32;
typedef unsigned short u16;
typedef unsigned char  u8;

typedef unsigned long long const uc64;
typedef unsigned int  const uc32;  /* Read Only */
typedef unsigned short const uc16;  /* Read Only */
typedef unsigned char  const uc8;   /* Read Only */

typedef volatile unsigned long long  vu64;
typedef volatile unsigned int  vu32;
typedef volatile unsigned short vu16;
typedef volatile unsigned char  vu8;

typedef volatile unsigned long long const vuc64;  /* Read Only */
typedef volatile unsigned int  const vuc32;  /* Read Only */
typedef volatile unsigned short const vuc16;  /* Read Only */
typedef volatile unsigned char  const vuc8;   /* Read Only */



#define MAX_MAP_LIST 8
#define  ULTRASOUND_NUM      8

#define SN_CODE_LEN 64

enum mapType
{
	TOTOAL_MAP = 0,
	LIDAR_MAP,
	ULTRASON_MAP,
	COLLISION_MAP,
	GROUND_MAP
};

enum ConnectType {
	TCP_CONNECT = 0,
	SERIAL_CONNECT = 1,
};

enum SensorType
{
	ST_LIDAR2D = 0x00,
	ST_ULTRASOUND = 0x01,
	ST_ENCODER,
	ST_SWITCH,
	ST_CARRIER,
	//	ST_MPU6500,
	ST_CAMERA3D,
	ST_UNIFIED,
	ST_LAST
};

enum NaviPackMode {
	MODE_NAVIGATION = 0X00,		//naviPack套件模式为导航模式  默认模式
	MODE_SENSOR = 0X01,			//naviPack套件模式为传感器模式 只回传激光雷达数据
};

// Device Address
#define LIDAR_ADDRESS 0X10
#define ALG_ADDRESS 0x11
#define MCU_ADDRESS 0x12
#define MF_COMPARE_MAP_DATA  0x13     
#define MF_CREATE_SN  0x14       
#define MF_ADDRESS  0x15       //MF开头的消息表示生产制造相关。
                               //新加的生产制造相关通讯，统一放到这个设备地址里面-- ldw 170318

#define DEVICE_MSG 0x20		//表示状态的更新
#define ERROR_MSG 0x21		//表示错误的处理
#define SELF_MSG 0X22		//表示自定义消息

// Function Code
// ALG
#define ALG_STATUS_REG         0x01
#define ALG_CONTROL_REG_READ   0x02
#define ALG_CONTROL_REG        0x03
#define ALG_SAVE_MAP		   0x04
#define ALG_DATA_READ		   0x05		//old
#define ALG_BUILD_MAP_MANUAL   0x06
#define ALG_BUILD_MAP_AUTO     0x07
#define ALG_NAVIGATION         0x08
#define ALG_LOCATION_PF         0x09
#define ALG_RAWLOG_REVIEW		0x0A
#define ALG_SET_UNIFIED_SENSOR_DATA 0X0B
#define ALG_ENABLE_MAP_UPDATE 0x0C
#define ALG_ENABLE_OPTIMIZE		  0x0D
#define ALG_LOCATION_STOP         0x0E  

//ALG_DATA_READ ADDRESS
#define ALG_DATA_ADDR_LIDAR_MAP      0x01 // correlation struct AlgLidarMapData,MapData RunLengthCode Format
#define ALG_DATA_ADDR_TARGET_POINTS  0x02
#define ALG_DATA_ADDR_ULTROSON_MAP   0x03
#define ALG_DATA_ADDR_SWITCH_MAP     0x04
#define ALG_DATA_ADDR_MAP      0x05
#define ALG_DATA_ADDR_REAL_LIDAR_DATA 0x06
#define ALG_DATA_ADDR_PLANED_PATH    0x07
#define ALG_DATA_ADDR_STATUS_R    0x08
#define ALG_DATA_ADDR_REAL_ULTROSON_DATA 0x09
#define ALG_DATA_ADDR_REAL_COLLISION_DATA 0x0A
#define ALG_DATA_ADDR_LIDAR_RAW_DATA 0X10	//激光雷达原始数据
#define  ALG_DATA_ADDR_LIDAR_MAP_LZ4	0x11 //MapData Lz4 Format

//ALG_RAWLOG_REVIEW ADDRESS
#define MCU_DATA_CHASSIS_STATUS	0x01

//#define ALG_RAW_ADDR_BUILDMAP	0x01

typedef enum {
	ERROR_CODE = 0X00,				//有错误 错误码
	UPDATE_MAP = 0x01,				//地图有更新
	UPDATE_SENSOR_DATA = 0x02,		//传感器数据有更新
	INIT_LOCATION_STATUS = 0X03,		//初始定位状态
	UPDATE_ALG_ATATUS_REG = 0X04,	//状态寄存器有更新
	NAVIGATION_STATUS = 0X05,	//目标点设置有更新
	GET_NAVIPACK_VERSION = 0X06,//获取版本号
	SET_NAVAPACK_UPLOAD_MAP = 0X07,//让navipack程序上传当前地图
	SET_SAVE_CURRENT_MAP = 0X08,	//让NaviPack保存当前正在使用的地图
	SET_LOAD_MAP_FROME_LIST = 0X09,	//从地图列表中加载地图
	UPDATE_MAP_LIST = 0X10,			//更新地图列表
	SWITCH_NAVIPACK_MODE = 0X11,	//更改NaviPack模式
	MAPPINGAUTO_STATUS = 0X12,		//自动建图状态
	IMU_CALIBRATE_SUCCESS = 0X13,   //IMU标定成功

	//以下是需要回调的
	SET_CHARGE_POSITION = 0XA0,		//设置充电桩位置
	SET_UPDATE_FILE = 0XA1,		//设置更新包
	SET_WIFI_PARAM = 0XA2,		//设置wifi
	CHANGE_LIDAR_TO_SENSOR_MODE = 0XA3,//设置雷达到传感器模式
	CHANGE_LIDAR_TO_PACK_MODE = 0XA4,	//设置雷达为NaviPack模式
	LIDAR_CTRL_SELF_STREAM = 0XA5,		//自定义数据
	SEND_FILE_TYPE_MAP_PACKAGE = 0xA6,	//发送地图文件

	//底盘相关
	MCU_REG_DEVICE_MSG = 0xB1,
	
}DEVICE_CMD_SUB;

typedef enum  {
	USER_REG_READ = 0X00,				//用户自定义数据
}MCUDeviceCode;

typedef enum {
	INIT_STATUS_BEGIN = 0x00,           //开始初始定位
	INIT_STATUS_SUCCESS = 0X01,		    //初始定位完毕
	INIT_STATUS_STOP = 0X02,		    //终止初始定位
}InitStatusCode;

typedef enum {
	SEND_MAP_FILE_SUCCESS = 0x00,       // 发送地图文件成功
	SEND_MAP_FILE_FAILED = 0x01,        // 发送地图文件失败
}SendMapFileCode;

#define MCU_USER_REG_BUFFERSIZE 32

typedef enum {

	REACH_POINT = 0X00,				//Reach Target Point 到达运动点 
	TERMINATED = 0x01,				//Motion Terminated  终止
	PATH_UPGRADE = 0X02,			//Path Upgrade       路径有更新
	START_NAVIGATION = 0X03,		//Start Navigation   开始导航
	CANNOT_REACH=0x04,              //Cannot reach the target. Find a near target to Reach. 无法到达规划点，规划最靠近的路线
	FIND_WAY_OUT=0x05   ,           //Find way out        脱困
}TatgetStatus;

typedef enum DEVICE_CMD_ERROR_CODE
{
	LIDAR_NOT_FOUND = 100,
	MAP_OVER_RANGE = 101,
}DEVICE_CMD_ERROR_CODE;
//

#define ALG_CR_ADDR_SET_TARGET				0		//设置目标点组
#define ALG_CR_ADDR_SPEED_CONTROL			16
#define ALG_CR_ADDR_BACK_CHARGE				24
#define ALG_CR_ADDR_MAP_BUILDER				34
#define ALG_CR_ADDR_IDLE					37
#define ALG_CR_ADDR_IMU_CELIBRATE			50
#define ALG_CR_ADDR_UNIFIED_SENSOR			51
#define ALG_CR_ADDR_LIDAR_FIRMWARE_UPDATE	52
#define ALG_CR_ADDR_CLEAN					53



// MCU
#define MCU_CONTROL_REG_READ   0x01
#define MCU_CONTROL_REG        0x02
#define MCU_STATUS_REG         0x03
#define MCU_PARAM_REG          0x04
#define MCU_USER_REG_READ      0x05
#define MCU_USER_REG_WRITE     0x06


#define OFFSET_OF(TYPE, MEMBER) ((int)(&((TYPE *)0)->MEMBER))
#define LENGTH_OF(TYPE, MEMBER_START, MEMBER_END) (OFFSET_OF(TYPE, MEMBER_END) - OFFSET_OF(TYPE, MEMBER_START) + ((int)sizeof(((TYPE *)0)->MEMBER_END)))

//MF
#define MF_READ_SN             0x01

#pragma pack(push, 1) 

typedef struct
{
	u8 deviceAddr;	//  cmd
	u8 functionCode;	// sub cmd
	u16 startAddr;		//sub sub cmd
	u32 len;
}SdkProtocolHeader;

typedef struct  
{
	s32 x;
	s32 y;
}IntPoint;

//统一传感器数据结构（每次发一帧过来）
typedef struct
{
	s32 sensorPosX;//单位mm，传感器相对小车的安装位置X
	s32 sensorPosY;//单位mm，传感器相对小车的安装位置Y
	s32 sensorPosPhi;//单位mrad，传感器相对于小车的安装角度phi
	u32 minValidDis;//单位mm，最短有效距离（盲区）
	u32 maxValidDis;//单位mm，最大有效距离

	u32 detectedData[UNIFIED_SENSOR_RESOLUTION];//单位mm，
												//一圈等分，以传感器安装角度正前方开始
												//逆时针计数（目前为0°- 359°）
												//若为开关量，只认detectedData[0]=0为无，=1为有
	u8 sensorType;//0->距离传感器 1->开关量
	u32 delayTime;//单位ms，该帧数据采集的延时
	u32 memoryTime;//单位s，该帧数据在地图上的保留时间
}UnifiedSensorInfo;


struct TMapParam
{
public:
	TMapParam()
	{
		width = height = 0;
		resolution = x_min = y_min = 0;
	}
public:
	int   width;
	int   height;
	float resolution;
	float x_min;
	float y_min;
};

typedef struct {
	int mapListNum;
	int rev;
	int mapListId[MAX_MAP_LIST];
}MapListInfo;

typedef struct {
	u16 partNum;
	u16 temp;
	u32 partLen;
	u32 fileLen;
	char fileName[FILE_PATH_MAX_LEN];
	char md5[32];
}FileInfo;




typedef struct CompareMapData_S
{
	unsigned char result;
	unsigned char exists;
	unsigned char align[2];
	long long timeForSN;
	char sn[SN_CODE_LEN];
	float distanceoofUpDownLeftRight[4];
	CompareMapData_S()
	{
		timeForSN = 0;
		sn[0] = 0;
	}
}CompareMapData_S;


typedef struct {
	char ssid[64];
	char pwd[64];
}WifiParam;

/*清扫指令相关*/
enum CoverMode
{
	COVER_MODE_NORMAL,//普通扫
	COVER_MODE_FINE,//精细扫
	COVER_MODE_WALL,//虚拟墙
	COVER_MODE_FIXPT//定点清扫
};
enum CleanMode
{
	CLEAN_MODE_SWEEP,//扫地
	CLEAN_MODE_MOP//拖地
};

typedef enum _CleanPackType
{
	START_MID_SWIP,
	STOP_MID_SWIP,
	START_EDGE_SWIP,
	STOP_EDGE_SWIP,
	CHANGE_WIND_LEVEL
}CleanPackType;


typedef struct
{
	float x_min;
	float y_min;
	float width;
	float height;
	CoverMode cover_mode;
	CleanMode clean_mode;
}RegionRect;
enum InstructionType
{
	CI_IDLE,//空指令
	CI_PAUSE,//暂停当前任务
	CI_RESUME,//继续当前任务
	CI_BACK_CHARGE,//新建回充任务
	CI_CLEAN//新建清扫任务
};
#include <vector>
using namespace std;
typedef struct
{
	InstructionType type;
	std::vector<RegionRect>RegionRects;
	void Reset()
	{
		RegionRects.clear();
		type = CI_IDLE;
	}
}CleanInstruction;

typedef struct
{
	u16 ultrasound[8];
	u8 dropSensor;
	u16 irSensor;
	u8 collisionSensor;
	s16 angularPos;
	s32 leftEncoderPos;                  //当前左边里程计的积分位置
	s32 rightEncoderPos;                  //当前右边里程计的积分位置
	s32 lineVelocity;
	s32 angularVelocity;
	u8 chargeStatus;
	u8 batteryStatus;
	u8 pickupStatus;
	u16 errorState;
}ChassisStatusRegister;

typedef struct
{
	SdkProtocolHeader header;
	ChassisStatusRegister status;
	u8 error;
}ChassisDataInfo;

typedef struct
{
	s32 lineVelocity;
	s32 angularVelocity;
}ChassisControlRegister;


typedef struct
{
	//车的形状参数
	u8 chassisShapeParamNum;
	s16 chassisShapeParamX[8];
	s16 chassisShapeParamY[8];
	u16 minTurningRadius; //载体线速度为0原地旋转一周载体覆盖区域外接圆半径
	//超声波传感器
	u8 ultrasoundSensorNum;
	s16 ultrasoundSensorX[8];
	s16 ultrasoundSensorY[8];
	u16 ultrasoundSensorOrientationAngle[8]; //朝向角度
	u16 ultrasoundSensorMinMeasureDistance;
	u16 ultrasoundSensorMaxMeasureDistance;
	u16 ultrasoundSensorFOV; //视场角
	//防跌落传感器
	u8 dropSensorNum;
	s16 dropSensorX[8];
	s16 dropSensorY[8];
	//碰撞传感器
	u8 collisionSensorNum;
	s16 collisionSensorX[8];
	s16 collisionSensorY[8];
	//激光雷达参数
	s16 lidarSensorX;
	s16 lidarSensorY;
	u16 lidarSensorOrientationAngle; //朝向角度
}ChassisParamRegister;

typedef struct
{
	s32 vectorTargetDistance;
	s32 vectorTargetAngle;
	s32 relativeTargetPosX;
	s32 relativeTargetPosY;
	s32 setLineVelocity;
	s32 setAngularVelocity;
	u8 backuint8_tge;
	u8 backuint8_tgeThreshold;
	s32 setBackuint8_tgePosX;
	s32 setBackuint8_tgePosY;
	u8 startMapping;
	u8 stopMapping;
	u8 setDefaultMap;
	u8 emergencyStop;
}AlgControlRegister;

typedef struct
{
	u8 workMode;
	s32 lineVelocity;
	s32 angularVelocity;
	s32 posX;
	s32 posY;
	s32 posSita;
	u16 errorState;
}AlgStatusRegister;

typedef struct
{
	s32 nTargetPosNum;
	s32 phi;
	s32 PathPosX[MAX_TARGET_LIST_SIZE];
	s32 PathPosY[MAX_TARGET_LIST_SIZE];
}AlgTargetPos;


typedef struct mpu6500_info {
	s32 acce_x;
	s32 acce_y;
	s32 acce_z;

	s32 gyro_x;
	s32 gyro_y;
	s32 gyro_z;

	s32 temperature;
}mpu6500_info;



typedef struct Mpu6500PointsStr{
	char acce_x_str[320];
	char acce_y_str[320];
	char acce_z_str[320];
	char gyro_x_str[320];
	char gyro_y_str[320];
	char gyro_z_str[320];

	int acce_x_str_len;
	int acce_y_str_len;
	int acce_z_str_len;
	int gyro_x_str_len;
	int gyro_y_str_len;
	int gyro_z_str_len;
}Mpu6500PointsStr;

typedef struct Alg3DSensorData
{
	int frameWidth;
	int frameHeight;
	s32* xyzRawData;
#ifdef __cplusplus
	Alg3DSensorData()
	{
		frameWidth = 80;
		frameHeight = 60;
		xyzRawData = new s32[frameWidth *frameHeight *3];
	}
	~Alg3DSensorData()
	{
		delete[] xyzRawData;
	}
#endif
}Alg3DSensorData;

typedef struct
{
	u8 sensorType;
	u32 num;						//num of valid point saved in the PosX and PosY with index(0~num)
	s32 posX;					// global pose of Carrier 单位毫米
	s32 posY;
	s32 posSita;
	s32 localPosX[LIDAR_RESOLUTION];
	s32 localPosY[LIDAR_RESOLUTION];
}AlgSensorData;

typedef struct AlgMapData
{
	s32   width;
	s32   height;
	float resolution;
	float x_min;
	float y_min;
	u8* map;	//80*80米

#ifdef __cplusplus
	AlgMapData()
	{
		map = new u8[MAX_MAP_SIZE];
	}
	~AlgMapData()
	{
		if (map) {
			delete[] map;
		}
	}
#endif
}AlgMapData;

typedef struct  
{
	s32 LidarPosX;
}CarrierParam;

typedef struct 
{
	s16 maxLineVelocity;
	s16 minLineVelocity;
	s16 maxAngularVelocity;
	s16 minAngularVelocity;
	u16 minPassageWidth;
	u8 enableUltrasound;
	u8 enableUsingTotalMapForNavigation;
}NaviPackParam;

#pragma pack(pop)

typedef void(*DeviceMsgCallBack)(s32 id, s32 funcCode, s32 code, void* param);
typedef void(*RobotMsgCallBack)(s32 id, s32 Level, s32 Code, char* msg);
typedef void(*MapPackageCallBack)(s32 id, FileInfo* fileInfo, s32 checkedOk, const u8* buf, u32 len);
typedef void(*LidarPackageCallBack)(s32 id,const u8 *buffer, s32 len);
#endif
