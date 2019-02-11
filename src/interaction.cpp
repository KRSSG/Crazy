#include "interaction.h"

Interaction::Interaction(QObject *parent):QObject(parent){
    udpSender = new QUdpSocket();
    radioPacket = new RadioPacket(udpSender);
    frequency.append(6);                        stringFrequency.append("6");
    frequency.append(8);                        stringFrequency.append("8");
    address.append(QHostAddress("10.12.225.78"));   stringAddress.append("10.12.225.78");
    address.append(QHostAddress("10.12.225.109"));  stringAddress.append("10.12.225.109");
    address.append(QHostAddress("127.0.0.1"));  stringAddress.append("127.0.0.1");
    addressIndex = 2;
    radioPacket->updateAddress(address[addressIndex]);
    frequencyIndex = 1;
}

QStringList Interaction::getCrazySetting(int itemIndex) const{
    switch(itemIndex){
    case 0:
        return stringAddress;
    case 1:
        return stringFrequency;
    default:
        break;
    }
    return QStringList();
}
void Interaction::sendCrazySetting(int itemIndex,int index){
    switch(itemIndex){
    case 0:
        addressIndex = index;
        radioPacket->updateAddress(address[addressIndex]);
    case 1:
        frequencyIndex = index;
    default:
        break;
    }
}
int Interaction::getDefaultIndex(int itemIndex) const{
    switch(itemIndex){
    case 0:
        return addressIndex;
    case 1:
        return frequencyIndex;
    default:
        break;
    }
    return 0;
}

void Interaction::sendStartPacket(int index){
    radioPacket->sendStartPacket(index);
}

