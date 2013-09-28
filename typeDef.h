#ifndef TYPEDEF_H
#define TYPEDEF_H

#define YC "YC" //遥测
#define YX "YX" //遥信
#define YK "YK" //遥控

#include <QtCore>
//智能设备数据结构
struct IED
{
    QString id; //智能设备唯一标识ID bigint(19)
    QString name;   //智能设备名称  varchar(45)
    QString desc;   //智能设备描述    varchar(256)
    QString pId;    //智能设备父节点ID bigint(19)
    QString cId;    //智能设备子节点ID bigint(19)

    QString factory;    //智能设备厂商    varchar(45)
    QString ipa;        //智能设备A网地址  varchar(45)
    QString ipb;        //智能设备B网地址  varchar(45)

    QString comtradePath; //录波目录的路径:varchar(45) *.* ; /Comtrade/ ; /Comtrade
    QString abFileRead;   //录波文件的路径:varchar(45) 0:相对路径 ; 1:绝对路径
    IED()
    {
        comtradePath = "*.*";
        abFileRead = "1";
    }
    QStringList accPoints;  //访问点
};

//网络数据结构
struct TcpNet
{
    QString id; //网络地址唯一标识ID bigint(19)
    QString name; //网络地址名称  varchar(45)
    QString ip; //网络地址IP    varchar(45)
    QString subNet; //网络地址子网    varchar(45)
    QString gateWay;    //网络地址网关    varchar(45)
    QString pId;    //网络地址父节点ID bigint(19)
    QString cId;    //网络地址子节点ID bigint(19)
};

//逻辑节点数据结构
struct LdNode
{
    QString id; //逻辑设备唯一标识ID bigint(19)
    QString desc;   //逻辑设备描述 varchar(256)
    QString prefix;
    QString lnType;
    QString lnClass;
    QString inst;
    QString pId;    //逻辑设备父节点 bigint(19)
    QString cId;    //逻辑设备子节点 bigint(19)
};

//数据集结构类型
struct Dataset
{
    QString id;   //数据集唯一标识ID bigint(19)
    QString name; //数据集名称   varchar(45)
    QString desc;   //数据集描述  varchar(256)
    QString pId;    //数据集父节点 bigint(19)
    QString cId;    //数据集子节点 bigint(19)
};

//控制块数据结构
struct ReportCtrl
{
    QString id; //控制块唯一标识   bigint(19)
    QString name;   //控制块名称 varchar(45)
    QString tripoption; //控制块触发选项 varchar(45)
    QString reportid;   //控制块报告ID   varchar(256)
    QString pId;    //控制块   bigint(19)
    QString cId;    //控制块   bigint(19)
    QString optionIndex;    //控制块系统选项varchar(45)
};

//逻辑设备数据结构
struct Ldevice
{
    QString id; //逻辑设备唯一标识ID bigint(19)
    QString name;   //逻辑设备名称 varchar(45)
    QString desc;   //逻辑设备描述 varchar(256)
    QString pId;    //逻辑设备父节点 bigint(19)
    QString cId;    //逻辑设备子节点 bigint(19)
};


//数据点结构类型
struct Pointdef
{
    QString id; //数据点唯一标识   bigint(19)
    QString name;   //数据点名称 varchar(1024)
    QString desc;   //数据点描述 varchar(256)
    QString pointName;  //模型文件中的名称
    QString pointDesc;  //模型文件中的描述
    QString cdc;    //数据点公用数据类型 varchar(45)
    QString fc;     //数据点功能约束   varchar(45)

};

struct Mxlink
{
    QString id;
    QString unit;
    QString multiplier;
    QString llLim;
    QString lLim;
    QString hhLim;
    QString hLim;
    QString max;
    QString min;
    QString scaleFactor;
    QString pId;
    QString cId;
    QString db;
    QString zerodb;

    //cc1 和 cc2 只有遥测(测量量)才有
    double cc1;   //倍数关系 ；默认 1
    double cc2;  // 偏移量； 默认 0
    Mxlink()
    {
        cc1 = 1;
        cc2 = 0;
    }
};

#endif // TYPEDEF_H
