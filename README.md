# QlickInspector

QlickInspector is a small embbedable library for widget based Qt applications which purpose is to help you to refine your UI. When embedded in your application QlickInspector records clicks by a user and is able to render element based heatmaps that visualize the click frequency on the specific elements. With the hotkey <F12> a screenshot of the current window can be generated, which will be overlayed with the heatmap. 

![Heatmap Example](https://cloud.githubusercontent.com/assets/13846346/26528919/1a6849c4-43b6-11e7-88fe-f5f6f40f512d.png)

## Integration

Use to following statements to integrate and activate QlickInspector into your application:

```cpp
#include <QtWidgets/QApplication>
#include <QtCore/QDir>
#include <qlickinspector.h>#include <QtWidgets/QApplication>
#include <QtCore/QDir>
#include <qlickinspector.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QlickInspector inspector(qApp, QDir::homePath() + "/eventlog");
    inspector.setEnabled(true);
    // NOTE: enable only for user which should be able to generate heatmap reports
    inspector.setHotKeyEnabled(true);
    // ...
    return a.exec();
}wh

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QlickInspector inspector(qApp, QDir::homePath() + "/eventlog");
    inspector.setEnabled(true);
    // NOTE: enable only for user which should be able to generate heatmap reports
    inspector.setHotKeyEnabled(true);
    // ...
    return a.exec();
}
```

## Limitations

- 
- No server component, data is only stored locally on the client side.

## Compiling

TODO
