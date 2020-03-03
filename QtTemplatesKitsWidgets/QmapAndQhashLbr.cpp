#include "myClass.h"
#include <qdebug.h>

//2.2.2Qmap类和Qhash类
//Qhash,以任意的顺序存储数据项,键类型的key必须提供全等==()的操作符重载和全局的qHash(Key)
//qmap按照键的顺序存储数据,必须提供小于<()的操作符重载

void STLstyleItr()
{
	QMap<QString, QString>map;
//插入数据
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

//Qvariant类,类似于union,能保存多个数据类型
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
//调用相应的转换函数并输出
	qDebug() << map["int"] << map["int"].toInt();
	qDebug() << map["double"] << map["double"].toDouble();
	qDebug() << map["string"] << map["string"].toString();
	qDebug() << map["color"] << map["color"].value<QColor>();
}