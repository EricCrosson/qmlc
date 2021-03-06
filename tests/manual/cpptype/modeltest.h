/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
** Copyright (C) 2014 Nomovok Ltd. All rights reserved.
** Contact: info@nomovok.com
**
** This file is part of the documentation of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#if !defined(MODELTEST_H)
#define MODELTEST_H

#include <QString>
#include <QObject>
#include "submodel.h"

class ModelTest : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString strprop READ strprop WRITE setStrprop NOTIFY strpropChanged)
    Q_PROPERTY(int intprop READ intprop WRITE setIntprop NOTIFY intpropChanged)
    Q_PROPERTY(SubModel *sub READ sub WRITE setSub NOTIFY subChanged)
    Q_CLASSINFO("DefaultProperty", "sub")

public:
    ModelTest(QObject *parent = 0);
    ~ModelTest();

    QString strprop() const;
    void setStrprop(QString value);
    Q_INVOKABLE void changeProperty(QString value);

    int intprop() const;
    void setIntprop(int value);

    SubModel* sub() const;
    void setSub(const SubModel *value);

signals:
    void strpropChanged(QString newValue);
    void intpropChanged();
    void subChanged();

private:
    QString m_strprop;
    int m_intprop;
    SubModel *m_sub;
};
#endif
