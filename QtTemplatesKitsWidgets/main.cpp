#include "myClass.h"
#include <QtWidgets/QApplication>
#include <QDebug>		//���а���QList���

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
	//Qstring�ַ�����,�������µĻ�����෽��
	QString str1 = "Welcome ";		//����qstring�Ĺ��캯��,����Ϊconst char*
	str1 = str1 += "to you! ";		//qstring�ṩ�����������
	QString str2 = "Hello, ";
	str2.append("World! ");			//����+=
//����cout����ʽ��ʽ����,�����QDebugͷ�ļ�,��������printf()�Ժ���������ʽ����
	qDebug() << str1 << endl << str2;
	//�ж��ַ����Ƿ���ĳ���ַ�����ͷ;contains()�ж��Ƿ���ֹ�
	if (str2.startsWith("He", Qt::CaseSensitive))		//��һ������Ϊ�ַ���(��Qstring�������)�ڶ�������ָ����Сд����(Ĭ������);���ƵĻ���endswith()
	{
		qDebug() << "str2 is start with He";
	}
//�����ַ���ת����int���ͻ�������p24
}

void containerLbr()
{
//QList,���ڲ�ͬ�����������в�ͬ�Ĵ洢����,�����Ļ������ļ̳���QQueue��
//QLinkedList,һ����ʽ�б�,�Է��������ڴ�鱣������,������ʹ���±�,ֻ���õ�������������,������һ���ܴ���������в���ʱ��QList��Ч��
//QVector,�����ڵ��ڴ��д洢����,��ǰ�����в��������ٶ���,�������±����,�����Ļ������ļ̳���QStack��
	QList<QString>list1;		//������һ��Qlist������,һ�����õ�������
	{
		QString str("This is a test string.");
		list1 << str;		//���������<<��str�洢��list������
	}						//�ֲ��������˽���,˵����QList<T>�����˶���ĸ���
	qDebug() << list1[0] << "How are you! ";
//"java"���ĵ�������������,Ч���Բ�,���������м�,���б�������
	/*{
		QList<int>lst;
		lst << 1 << 2 << 3 << 4 << 5;		//��ʽ����5��int
		QListIterator<int>i(lst);			//����������,��ʱ��������1ǰ��
		for (; i.hasNext();)				//���������Ƿ����б���
		{
			qDebug() << i.next();			//next������������һ���б���
		}

		lst.clear();						//��Է�ָ����clearֱ���ͷ�
		QMutableListIterator<int>iw(lst);	//��д������
		for (int j = 0; j < 10; ++j)
		{
			iw.insert(j);					//����
		}
		for (iw.toFront(); iw.hasNext(); )
		{
			qDebug() << iw.next();
		}
		for (iw.toBack(); iw.hasPrevious(); )
		{
			if (iw.previous() % 2 == 0)
			{
				iw.remove();		//ɾ��
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
//stl������������
	QList<int>list;
	for (int j = 0; j < 10; ++j)
	{
		list.insert(list.end(), j);
	}
	QList<int>::iterator i;
	for (i = list.begin(); i != list.end(); ++i)		//��ͬ��stl������,��Ҫ������
	{
		qDebug() << *i;
		*i = *i * 10;
	}
	QList<int>::ConstIterator ci;						//ֻ��������
	for (ci = list.constBegin(); ci != list.constEnd(); ++ci)
	{
		qDebug() << *ci;
	}
}