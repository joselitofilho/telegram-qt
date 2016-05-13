/*
   Copyright (C) 2014-2015 Alexandr Akulich <akulichalexander@gmail.com>

   This file is a part of TelegramQt library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

 */

#ifndef CMESSAGINGMODEL_HPP
#define CMESSAGINGMODEL_HPP

#include <QAbstractTableModel>

#include "TelegramNamespace.hpp"

class CMessagingModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum Columns {
        Peer,
        Contact,
        Direction,
        Timestamp,
        MessageId,
        Message,
        Status,
        ForwardFromContact,
        ForwardTimestamp,
        ColumnsCount
    };

    struct SMessage : public TelegramNamespace::Message
    {
        SMessage() :
            TelegramNamespace::Message(),
            id64(0),
            status(TelegramNamespace::MessageDeliveryStatusUnknown)
        {
        }

        SMessage(const TelegramNamespace::Message &m) :
            TelegramNamespace::Message(m),
            id64(0),
            status(TelegramNamespace::MessageDeliveryStatusUnknown)
        {
        }

        quint64 id64;
        TelegramNamespace::MessageDeliveryStatus status;
        QVariant mediaData;
    };

    explicit CMessagingModel(QObject *parent = 0);

    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant rowData(quint32 messageIndex, int column) const;
    const SMessage *messageAt(quint32 messageIndex) const;

    int messageIndex(quint64 messageId) const; // Messages id should be quint32, but it require "outgoing random to incremental message id resolving" (Not implemented yet).

public slots:
    void addMessage(const SMessage &message);
    int setMessageMediaData(quint64 messageId, const QVariant &data);
    void setMessageDeliveryStatus(quint32 messageId, TelegramNamespace::MessageDeliveryStatus status);
    void setResolvedMessageId(quint64 randomId, quint32 resolvedId);

private:
    QList<SMessage> m_messages;

};

inline int CMessagingModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return ColumnsCount;
}

inline int CMessagingModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_messages.count();
}

#endif // CMESSAGINGMODEL_HPP
