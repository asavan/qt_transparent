import QtQuick 2.3
import QtQuick.Controls 2.12


ApplicationWindow {//наша главная форма
    id: window
    visible: true
    width: 500 //по ширине рисунка
    height: 340 //по высоте рисунка
    //Цвет записывается в формате ARGB и 00 означает, что форма будет прозрачной,
    //а ffffff означаеn белый цвет, хотя это и не важно
    // color: "#00ffffff"
    color : "transparent"

    flags: Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint

    property int key;
    property string key_str;

    MouseArea {
        id: mouseRegion
        anchors.fill: parent;
        property variant clickPos: "1,1"

        onPressed: {
            clickPos  = Qt.point(mouse.x,mouse.y)
        }

        onPositionChanged: {
            var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y)
            window.x = window.x+delta.x
            window.y = window.y+delta.y
        }
    }

    Image {//добавляем рисунок
        id: image1// к рисунку потом можно обращаться по этому имени
        x: 0//ставим рисунок в верхний левый угол
        y: 0
        // width: 500//автоматически размеры не подстраиваются
        // height: 340//и приходится их вручную писать
        source: "main.png"//так как рисунок уже в ресурсах, то полный путь не нужен
    }


    Item {
        id: keyHandler
        anchors.fill: parent
        focus: true
        Keys.onPressed: {
            key_str = event.text;
            key = event.key;
            if (key === Qt.Key_Escape) {
                application.quit();
            }
            sound.playMusic(key);
            dialog.show(key_str);
        }
    }
    Rectangle {
        id: dialog
        opacity: 0
        anchors.centerIn: parent
        property int fsize : 50
        property int dtime : 2000
        z: 65535 //Arbitrary number chosen to be above all the items, including the scaled perspective ones.

        function show(str){
            dialogText.text = str;
            dialogAnim.start();
        }

        Text {
            id: dialogText
            visible : true
            anchors.centerIn: parent
            font.pixelSize: parent.fsize
            color : 'red'
        }

        SequentialAnimation {
            id: dialogAnim
            ParallelAnimation {
                NumberAnimation { target: dialog; property:"opacity"; to: 0.5; duration: 1 }
                NumberAnimation { target: dialog; property:"opacity"; to: 3; duration: dialog.dtime}
                NumberAnimation {target: dialog; property:"fsize"; to: 400; duration: dialog.dtime }
            }
            PauseAnimation { duration: 1500 }
            NumberAnimation { target: dialog; property:"opacity"; to: 0; duration: dialog.dtime/2 }
            NumberAnimation {target: dialog; property:"fsize"; to: 50; duration: 1 }

        }
    }
    // SystemPalette { id: activePalette }

}
