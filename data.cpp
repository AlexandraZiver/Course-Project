#include "data.h"
#include "record.h"
#include "ui_record.h"



Data::Data()
{

}

//Samira
void record::Save_xml(){
   // Открываем файл для Записи с помощью пути, указанного в lineEditWrite

    QFile   name_file("myDataFile.xml");
      if (name_file.open(QIODevice::WriteOnly))
      {
          qDebug() << " удалось открыть файл xml";

       // Создаем объект, с помощью которого осуществляется запись в файл
       QXmlStreamWriter xmlWriter(&name_file);
       xmlWriter.setAutoFormatting(true);  // Устанавливаем автоформатирование текста
       xmlWriter.writeStartDocument();     // Запускаем запись в документ
       xmlWriter.writeStartElement("Members");   // Записываем первый элемент с его именем

       xmlWriter.writeStartElement("Classes_and_architectures");  // Записываем тег с именем для первого чекбокса

       /* Записываем также в тело этого элемента строку
        * */
       xmlWriter.writeCharacters("Alexandra");
       xmlWriter.writeEndElement();        // Закрываем тег


    // ========================================================
       xmlWriter.writeStartElement("Exceptions");
       xmlWriter.writeCharacters("Elizabeth");

       xmlWriter.writeEndElement();
    // ========================================================
       xmlWriter.writeStartElement("Data_Base");
       xmlWriter.writeCharacters("Samira");

       xmlWriter.writeEndElement();

    // ========================================================
       xmlWriter.writeStartElement("Interface");
       xmlWriter.writeCharacters("Andrey");

       xmlWriter.writeEndElement();

    // ========================================================
       xmlWriter.writeStartElement("Algorithms");
       xmlWriter.writeCharacters("Dmitry");

       xmlWriter.writeEndElement();


       // Закрываем тег

       xmlWriter.writeEndElement();
       // Завершаем запись в документ

       xmlWriter.writeEndDocument();
       }
       name_file.close();   // Закрываем файл
}

void record::Read_xml()
{   ui->textEdit_2->clear();

    QFile name_file("myDataFile.xml");
        if (!name_file.open(QFile::ReadOnly | QFile::Text))
        {
             qDebug()<<"Не удалось открыть файл xml";


        } else {

            // Создается объект, с помощью которого осуществляется чтение из файла
            QXmlStreamReader xmlReader;
            //QXmlStreamReader xml;
            xmlReader.setDevice(&name_file);
            xmlReader.readNext();   // Переходит к первому элементу в файле

            // пока не достигнем конца документа


            while(!xmlReader.atEnd())
            {

                // Проверяем, является ли элемент началом тега

                if(xmlReader.isStartElement())
                    {

                       QString name = xmlReader.name().toString();

                        if (name == "Classes_and_architectures" )
                        {
                       QString memb1 = xmlReader.readElementText();
                        qDebug() << name;
                        qDebug() << memb1;
                        ui->textEdit_2->append(name + ": " + memb1);
                        }

                        if (name == "Exceptions" )
                        {
                       QString memb1 = xmlReader.readElementText();
                        qDebug() << name;
                        qDebug() << memb1;
                        ui->textEdit_2->append(name + ": " + memb1);
                        }

                        if (name == "Data_Base" )
                        {
                       QString memb1 = xmlReader.readElementText();
                        qDebug() << name;
                        qDebug() << memb1;
                        ui->textEdit_2->append(name + ": " + memb1);
                        }
                        if (name == "Interface" )
                        {
                       QString memb1 = xmlReader.readElementText();
                        qDebug() << name;
                        qDebug() << memb1;
                        ui->textEdit_2->append(name + ": " + memb1);
                        }
                        if (name == "Algorithms" )
                        {
                       QString memb1 = xmlReader.readElementText();
                        qDebug() << name;
                        qDebug() << memb1;
                        ui->textEdit_2->append(name + ": " + memb1);
                        }

                    }
                xmlReader.readNext();
            }

         name_file.close();
        }

}
