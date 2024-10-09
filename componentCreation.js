//import CppToJsText

function createSpriteObjects() {
    var component = Qt.createComponent("myText.qml");
    var line = component.createObject(pages.children[0], {x: 0, y: 0});
    line.text = "---------"

    if (sprite === null) {
        // Error Handling
        console.log("Error creating object");
    }
}
