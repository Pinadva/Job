# Алгоритм работы
Предлагаемая структура для хранения данных
```c++
struct MosaicPhoto
{
 QImage *photo;
 QString fileName;
 QString exposureTime;
 QString fNumber;
 QString iSO;
 QString flashExposureComp;
};
```

  * Запросить у пользователя путь до папки с фотографиями, запомнить в QString folderPath;
  * Создать список файлов в папке с расширениями *.jpg *.jpeg
  * Если файлов < 17 вывести сообщение о том что найдено менее 17 файлов и перейти в изначальное состояние программы
  * Пропустить первую фотографию и запомнить названия следующих 16
  * Загрузить 16 фотографии в QHash<int, MosaicPhoto> photos заполнив photo и fileName;
  * в цикле перебрать photos
    * убедиться что exif поля {Make, Model, LensInfo, FocalLength, Megapixels, FullImageSize, ModifyDate, ExposureProgram, ISOAutoMin, ISOAutoMax} одинаковые, если да, то запомнить их в переменные(например QHash<QString, QString> globalEXIF;), иначе вывести об этом сообщение и перейти в изначальное состояние программы
    * записать в структуру MosaicPhoto значения тэгов {ExposureTime, FNumber, ISO, FlashExposureComp}
  * Спросить у пользователя текстовое значение для "Производитель объектива", добавить в globalEXIF
  * Создать QPixmap result; размером {photoSize.width, photoSize.height + 200}

Далее нужно представить что result и все фотографии в photos разбиты на 16 одинаковых сегментов сеткой 4х4, размеры одного сегмента QSize(photoSize.width / 4, photoSize.height / 4).
  Нумерация сегментов сверху вниз слева направо.
  * for (auto item : photos)
    * у фотографии item.value() взять сегмент под номером item.key() и запомнить как QPixmap segment;
    * если какого то поля exif не существует - спросить значение у пользователя
    * с помощью QPainter::drawText наносим на segment текст полей из MosaicPhoto {fileName, exposureTime, fNumber, iSO, flashExposureComp} начиная с левого верхнего угла с отступом 20, 20; одно поле в одной строчке; между строчками 100 пикселей (т.е. вторая строчка в координатах 20, 120); шрифт Arial 36 зеленый
    * получившийся segment рисуем на result в сегмент под номером item.key()
  * В нижнюю полоску высотой 200 пикселей добавить тексты значении из globalEXIF
  * Сохранить result в файл result.png с quality = 100 в папку folderPath
