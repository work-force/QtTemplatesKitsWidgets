#include "myClass.h"
#include <QtWidgets/QApplication>
#include <QDebug>		//其中包含QList类等

void QstringLbr();
void containerLbr();

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	myClass w;
	w.show();
	//QstringLbr();
	//containerLbr();
	//STLstyleItr();
	return a.exec();
}

void QstringLbr()
{
	//Qstring字符串类,除了以下的还有许多方法
	QString str1 = "Welcome ";		//调用qstring的构造函数,参数为const char*
	str1 = str1 += "to you! ";		//qstring提供了运算符重载
	QString str2 = "Hello, ";
	str2.append("World! ");			//等于+=
//类似cout以流式方式传输,需添加QDebug头文件,或者类似printf()以函数参数方式传输
	qDebug() << str1 << endl << str2;
	//判断字符串是否以某个字符串打头;contains()判断是否出现过
	if (str2.startsWith("He", Qt::CaseSensitive))		//第一个参数为字符串(有Qstring类的重载)第二个参数指定大小写敏感(默认敏感);类似的还有endswith()
	{
		qDebug() << "str2 is start with He";
	}
//还有字符串转换成int类型或其他见p24
}

void containerLbr()
{
//QList,对于不同的数据类型有不同的存储策略,其他的还有它的继承类QQueue等
//QLinkedList,一个链式列表,以非连续的内存块保存数据,但不能使用下标,只能用迭代器访问数据,当进行一个很大的容器进行操作时比QList有效率
//QVector,在相邻的内存中存储数据,在前部或中部操作的速度慢,可以用下标访问,其他的还有它的继承类QStack等
	QList<QString>list1;		//声明了一个Qlist容器类,一个常用的容器类
	{
		QString str("This is a test string.");
		list1 << str;		//运算符重载<<将str存储到list对象中
	}						//局部变量到此结束,说明了QList<T>保存了对象的复制
	qDebug() << list1[0] << "How are you! ";
//"java"风格的迭代器遍历容器,效率略差,迭代点在中间,对列表向后遍历
	/*{
		QList<int>lst;
		lst << 1 << 2 << 3 << 4 << 5;		//流式输入5个int
		QListIterator<int>i(lst);			//建立迭代器,此时迭代点在1前面
		for (; i.hasNext();)				//检查迭代点是否有列表项
		{
			qDebug() << i.next();			//next函数会跳过下一个列表项
		}

		lst.clear();						//针对非指针用clear直接释放
		QMutableListIterator<int>iw(lst);	//读写迭代器
		for (int j = 0; j < 10; ++j)
		{
			iw.insert(j);					//插入
		}
		for (iw.toFront(); iw.hasNext(); )
		{
			qDebug() << iw.next();
		}
		for (iw.toBack(); iw.hasPrevious(); )
		{
			if (iw.previous() % 2 == 0)
			{
				iw.remove();		//删除
			}
			else
			{
				iw.setValue(iw.peekNext() * 10);
			}
		}
		for (iw.toFront(); iw.hasNext(); )
		{
			qDebug() << iw.next();
		}
	}*/
//stl风格迭代器遍历
	QList<int>list;
	for (int j = 0; j < 10; ++j)
	{
		list.insert(list.end(), j);
	}
	QList<int>::iterator i;
	for (i = list.begin(); i != list.end(); ++i)		//不同于stl迭代器,需要加括号
	{
		qDebug() << *i;
		*i = *i * 10;
	}
	QList<int>::ConstIterator ci;						//只读迭代器
	for (ci = list.constBegin(); ci != list.constEnd(); ++ci)
	{
		qDebug() << *ci;
	}
}