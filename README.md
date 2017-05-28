# QlickInspector
A user interaction analysis and heatmap generation toolkit for widget based Qt applications.

![Heatmap Example](https://cloud.githubusercontent.com/assets/13846346/26528919/1a6849c4-43b6-11e7-88fe-f5f6f40f512d.png)

## Integration

```cpp
#include <QtWidgets/QApplication>
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
}
```

## Limitations

-

## Compiling

TODO
