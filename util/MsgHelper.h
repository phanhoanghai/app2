#ifndef MSGHELPER_H
#define MSGHELPER_H

#include "../server/multiprocess/message.h"

using namespace app_msg;

Msg messagere_refresh() {
    Msg m;
    m.client = CLIENT_2;
    m.index = -1;
    m.msgType = RELOAD_DATA;
    int dataDefault[5] = {0, 0, 0, 0, 0};
    std::copy(std::begin(dataDefault), std::end(dataDefault), std::begin(dataDefault));
    return m;
};

#endif // MSGHELPER_H
