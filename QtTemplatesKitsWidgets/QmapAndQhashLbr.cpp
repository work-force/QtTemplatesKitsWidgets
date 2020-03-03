#include "myClass.h"
#include <qdebug.h>

//2.2.2Qmap���Qhash��
//Qhash,�������˳��洢������,�����͵�key�����ṩȫ��==()�Ĳ��������غ�ȫ�ֵ�qHash(Key)
//qmap���ռ���˳��洢����,�����ṩС��<()�Ĳ���������

void STLstyleItr()
{
	QMap<QString, QString>map;
//��������
	map.insert("beijing", "111");
	map.insert("shanghai", "021");
	map.insert("nanjing", "025");

	QMap<QString, QString>::const_iterator i;
	for (i = map.constBegin(); i != map.constEnd(); ++i)
	{
		qDebug() << "  " << i.key() << " " << i.value();
	}

	QMap<QString, QString>::iterator mi;
	mi = map.find("beijing");
	if (mi != map.end())
	{
		mi.value() = "010";
	}
	QMap<QString, QString>::const_iterator modi;
	qDebug() << " ";
	for (modi = map.constBegin(); modi != map.constEnd(); ++modi)
	{
		qDebug() << " " << modi.key() << " " << modi.value();
	}
}

//Qvariant��,������union,�ܱ�������������
void qvariant()
{
	QVariant v(709);
	qDebug() << v.toInt();
	QVariant w("How are you! ");
	qDebug() << w.toString();
	QMap<QString, QVariant>map;
	map["int"] = 709;
	map["double"] = 709.709;
	map["string"] = "How are you!";
	map["color"] = QColor(255, 0, 0);
//������Ӧ��ת�����������
	qDebug() << map["int"] << map["int"].toInt();
	qDebug() << map["double"] << map["double"].toDouble();
	qDebug() << map["string"] << map["string"].toString();
	qDebug() << map["color"] << map["color"].value<QColor>();
}