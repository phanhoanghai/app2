#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include "../server/multiprocess/connection.h"
#include "../server/multiprocess/message.h"

class MsgQueue
{
private:
    MsgQueue();

public:
    static MsgQueue* getInstance();

public:
    void initMsgQueue();
    void listeningMsg();
    void sendingMsg(app_msg::Msg msg);
    void closeMsgQueue();

private:
};

#endif // MSGQUEUE_H
