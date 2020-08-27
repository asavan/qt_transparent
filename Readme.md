# Прозрачное окно на qt со звуком

1) Собрать релизную сборку qt-creatorом
2) Сделать новую папку build - скопировать туда exeшник
3) Найти в папке с qt-creatorom запускалку консоли которая выставляет переменные среды (%APPDATA%\Microsoft\Windows\Start Menu\Programs\Qt 5.14.2\5.14.2\MSVC 2017 (64-bit))
4) Запустить в папке с exeшником windeployqt --qmldir .. qmltest.exe (где ..  - это путь до qml файла из исходников)
5) Скопировать в эту папку из исходников keys.txt bass.dll и папку sounds (copy ..\dependencies\bass.dll .       copy ..\keys.txt .                   xcopy ..\sound .\sound\)
