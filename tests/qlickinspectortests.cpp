/**
 * Copyright 2017 Thomas Ascher <thomas.ascher@gmx.at>
 * SPDX-License-Identifier: LGPL-3.0+
 */

#include <QtCore/QString>
#include <QtGui/QMouseEvent>
#include <QtTest/QtTest>
#include "ui_qlickinspectortestsui.h"
#include <qiscreenshotgrabber.h>
#include <qiwidgetidgenerator.h>
#include <qikeyvaluestore.h>
#include <qieventcounter.h>
#include <qieventinterceptor.h>
#include <qimaxeventcountevaluator.h>
#include <qicolormapping.h>
#include <qiheatmaprenderer.h>

using namespace std;

class QlickInspectorTestsUI : public QWidget, public Ui::QlickInspectorTestsUI
{
public:
    QlickInspectorTestsUI()
    {
        setupUi(this);
        setObjectName("window");
    }
};

class QlickInspectorTests : public QObject
{
    Q_OBJECT
private slots:
    void testGrabbing()
    {
        QlickInspectorTestsUI ui;

        QPixmap screenshot = QIScreenshotGrabber::grab(&ui);

        QVERIFY2(screenshot.size().isValid(), "screenshot is empty");
    }

    void testIDGeneration()
    {
        QlickInspectorTestsUI ui;

        QString id = QIWidgetIDGenerator::generate(ui.pushButton);

        QCOMPARE(QString("window/groupBox/pushButton"), id);
    }

    void testKeyValueStoring()
    {
        auto store = createStore();
        QString key = "test";

        bool exists = false;
        QString value = store->get(key, &exists);

        QCOMPARE(QString(), value);
        QCOMPARE(false, exists);

        QString expectedValue = "1";
        store->set(key, expectedValue);
        value = store->get(key, &exists);

        QCOMPARE(expectedValue, value);
        QCOMPARE(true, exists);

        expectedValue = "2";
        store->set(key, expectedValue);
        value = store->get(key, &exists);

        QCOMPARE(expectedValue, value);
        QCOMPARE(true, exists);
    }

    void testEventCounting()
    {
        auto counter = createCounter();
        QString id = "test";

        counter->increment(id);
        counter->increment(id);

        QCOMPARE(static_cast<unsigned int>(2), counter->get(id));
    }

    void testMaxEventCountEvaluation()
    {
        auto counter = createCounter();
        QlickInspectorTestsUI ui;
        ui.show();
        counter->increment(ui.pushButton);
        counter->increment(ui.pushButton);
        counter->increment(ui.radioButton);
        QIMaxEventCountEvaluator evaluator(counter);

        QCOMPARE(static_cast<unsigned int>(2), evaluator.getMaxCount(&ui));
    }

    void testColorMapping()
    {
        QIColorMapping mapping(100);

        QColor color = mapping.map(50);

         QCOMPARE(126, color.hue());
    }

    void testHeatmapReandering()
    {
        auto counter = createCounter();
        QlickInspectorTestsUI ui;
        ui.show();
        counter->increment(ui.pushButton);
        counter->increment(ui.pushButton);
        counter->increment(ui.radioButton);
        QIHeatmapRenderer renderer(counter);

        QPixmap heatmap = renderer.render(&ui);

        QVERIFY2(heatmap.size().isValid(), "heatmap is empty");
    }

private:
    std::shared_ptr<QIKeyValueStore> createStore() const
    {
        auto store = make_shared<QIKeyValueStore>();
        store->open();
        return store;
    }

    std::shared_ptr<QIEventCounter> createCounter() const
    {
        return make_shared<QIEventCounter>(createStore());
    }
};

QTEST_MAIN(QlickInspectorTests)

#include "qlickinspectortests.moc"
