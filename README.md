# QlickInspector

QlickInspector is a small embbedable library for widget based Qt applications which purpose is to help you to refine your UI. When embedded in your application, QlickInspector records clicks by users and is able to render element based heatmaps that visualize the click frequency on the specific elements. With the hotkey F12 (when enabled) a screenshot of the current window with a heatmap overlay can be generated. 

![Heatmap Example](https://cloud.githubusercontent.com/assets/13846346/26528919/1a6849c4-43b6-11e7-88fe-f5f6f40f512d.png)

## Integration

Use to following statements to integrate QlickInspector into your application:

```cpp
#include <QtWidgets/QApplication>
#include <QtCore/QDir>
#include <qlickinspector.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QlickInspector inspector(qApp, QDir::homePath() + "/eventlog");
    inspector.setEnabled(true);
    // NOTE: enable only for users which should be able to generate heatmap reports
    inspector.setHotKeyEnabled(true);
    // ...
    return a.exec();
}
```

Furthermore all widgets in your application require a unique object name because the object name of a widget, including all object names its parent widgets are used for id generation (e.g. dialog/groupBox/pushButton).

## Limitations

- Widgets require unique object names (in the current child context) for correct data acquisition.
- The hotkey can only generate a report for the current window (e.g. no support for menu hierarchies).
- Qt Quick is currently not supported (since I do not have experience in this area).
- Only click based interactions are measured.
- No server component, data is only stored and processed on the client side.

## Compiling

TODO

© 2017 Thomas Ascher
