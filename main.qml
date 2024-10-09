import QtQuick
import QtQuick.Window
import QtQuick.Controls.Universal
import "componentCreation.js" as MyScript
import CppToJsText

ApplicationWindow {
    id: root
    //width: 640
    width: 900
    //height: 480
    height: 1000
    visible: true
    //title: qsTr("Hello World")
    //title: CppToJsText.lines.length
    //title: CppToJsText.pages.length
    title: pages.children.length
    property int _fontSize: 12
    //visibility: "Maximized"

    Universal.theme: Universal.Dark
    Universal.accent: Universal.Violet

    Component {
        id: componentRectangle

        Rectangle {
            width: 10
            height: 50
            color: "transparent"
            //color: "lightblue"
        }
    }

    Component {
        id: componentImage

        Image {
            source: "file:thmb/0000.jpg"
            asynchronous: true
            cache: true
            width: 256
            height: 256
        }
    }

    //Component.onCompleted: MyScript.createSpriteObjects();
    Component.onCompleted: function () {
        for (var ipage = 0; ipage < CppToJsText.pages.length; ipage++) {
//        for (var ipage = 0; ipage < 5; ipage++) {
            let cppPage = CppToJsText.pages[ipage]
            let qmlPage = componentRectangle.createObject(pages, {});

            for (var j = 0; j < cppPage.images.length; j++) {
                console.log('j is:', j, cppPage.images[j].line)
                var cppImage = cppPage.images[j]
                let qmlImage = componentImage.createObject(qmlPage, {y: cppImage.line * _fontSize, x:20});
            }



            for (var i = 0; i < cppPage.lines.length; i++) {
                let component = Qt.createComponent("myText.qml");
                let line = component.createObject(qmlPage,
                                                  {
                                                      x: 20,
                                                      y: i*(_fontSize),
                                                      text: cppPage.lines[i],
                                                  });


            }

            if (ipage % 2) {
                qmlPage.color = "blue"
            } else {
                qmlPage.color = "green"
            }

            qmlPage.height = cppPage.lines.length * root._fontSize

        }
    }


    ScrollView {
        id: scrollView
        anchors.fill: parent
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        ScrollBar.vertical.stepSize: 50
        clip: false

//        focus: true

//        Keys.onPressed: function (event) {
//            if (event.key === Qt.Key_PageUp) {
//                console.log("PageUp key pressed");
//                //pages.flick(0, 111)
//                //scrollView.baseline = 5;
//                // Add your code for PageUp here
//            } else if (event.key === Qt.Key_PageDown) {
//                console.log("PageDown key pressed");
//                // Add your code for PageDown here
//            }
//            // Mark event as handled
//            event.accepted = true;
//        }

        Flickable {
            id: flickable
            contentWidth: parent.width
            contentHeight: pages.height
            clip: false

            Column {
                id: pages
                width: flickable.width

//                Rectangle {
//                    width: parent.width
//                    height: 300
//                    color: "green"
//                }

//                Rectangle {
//                    width: parent.width
//                    height: 300
//                    color: "blue"
//                }

//                Rectangle {
//                    width: parent.width
//                    height: 300
//                    color: "green"
//                }
            }
        }
    }
}
