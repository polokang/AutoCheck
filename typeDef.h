#ifndef TYPEDEF_H
#define TYPEDEF_H

#define YC "YC" //ң��
#define YX "YX" //ң��
#define YK "YK" //ң��

#include <QtCore>
//�����豸���ݽṹ
struct IED
{
    QString id; //�����豸Ψһ��ʶID bigint(19)
    QString name;   //�����豸����  varchar(45)
    QString desc;   //�����豸����    varchar(256)
    QString pId;    //�����豸���ڵ�ID bigint(19)
    QString cId;    //�����豸�ӽڵ�ID bigint(19)

    QString factory;    //�����豸����    varchar(45)
    QString ipa;        //�����豸A����ַ  varchar(45)
    QString ipb;        //�����豸B����ַ  varchar(45)

    QString comtradePath; //¼��Ŀ¼��·��:varchar(45) *.* ; /Comtrade/ ; /Comtrade
    QString abFileRead;   //¼���ļ���·��:varchar(45) 0:���·�� ; 1:����·��
    IED()
    {
        comtradePath = "*.*";
        abFileRead = "1";
    }
    QStringList accPoints;  //���ʵ�
};

//�������ݽṹ
struct TcpNet
{
    QString id; //�����ַΨһ��ʶID bigint(19)
    QString name; //�����ַ����  varchar(45)
    QString ip; //�����ַIP    varchar(45)
    QString subNet; //�����ַ����    varchar(45)
    QString gateWay;    //�����ַ����    varchar(45)
    QString pId;    //�����ַ���ڵ�ID bigint(19)
    QString cId;    //�����ַ�ӽڵ�ID bigint(19)
};

//�߼��ڵ����ݽṹ
struct LdNode
{
    QString id; //�߼��豸Ψһ��ʶID bigint(19)
    QString desc;   //�߼��豸���� varchar(256)
    QString prefix;
    QString lnType;
    QString lnClass;
    QString inst;
    QString pId;    //�߼��豸���ڵ� bigint(19)
    QString cId;    //�߼��豸�ӽڵ� bigint(19)
};

//���ݼ��ṹ����
struct Dataset
{
    QString id;   //���ݼ�Ψһ��ʶID bigint(19)
    QString name; //���ݼ�����   varchar(45)
    QString desc;   //���ݼ�����  varchar(256)
    QString pId;    //���ݼ����ڵ� bigint(19)
    QString cId;    //���ݼ��ӽڵ� bigint(19)
};

//���ƿ����ݽṹ
struct ReportCtrl
{
    QString id; //���ƿ�Ψһ��ʶ   bigint(19)
    QString name;   //���ƿ����� varchar(45)
    QString tripoption; //���ƿ鴥��ѡ�� varchar(45)
    QString reportid;   //���ƿ鱨��ID   varchar(256)
    QString pId;    //���ƿ�   bigint(19)
    QString cId;    //���ƿ�   bigint(19)
    QString optionIndex;    //���ƿ�ϵͳѡ��varchar(45)
};

//�߼��豸���ݽṹ
struct Ldevice
{
    QString id; //�߼��豸Ψһ��ʶID bigint(19)
    QString name;   //�߼��豸���� varchar(45)
    QString desc;   //�߼��豸���� varchar(256)
    QString pId;    //�߼��豸���ڵ� bigint(19)
    QString cId;    //�߼��豸�ӽڵ� bigint(19)
};


//���ݵ�ṹ����
struct Pointdef
{
    QString id; //���ݵ�Ψһ��ʶ   bigint(19)
    QString name;   //���ݵ����� varchar(1024)
    QString desc;   //���ݵ����� varchar(256)
    QString pointName;  //ģ���ļ��е�����
    QString pointDesc;  //ģ���ļ��е�����
    QString cdc;    //���ݵ㹫���������� varchar(45)
    QString fc;     //���ݵ㹦��Լ��   varchar(45)

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

    //cc1 �� cc2 ֻ��ң��(������)����
    double cc1;   //������ϵ ��Ĭ�� 1
    double cc2;  // ƫ������ Ĭ�� 0
    Mxlink()
    {
        cc1 = 1;
        cc2 = 0;
    }
};

#endif // TYPEDEF_H
