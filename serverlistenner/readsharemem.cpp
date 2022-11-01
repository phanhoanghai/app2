#include "readsharemem.h"
#include <QDebug>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

using namespace std;

static ReadShareMem* m_instance;

ReadShareMem::ReadShareMem()
{

}

ReadShareMem *ReadShareMem::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new ReadShareMem();
    }
    return m_instance;
}

std::string ReadShareMem::getSharemem()
{
    int shm_fd;
    void* ptr = NULL;

    shm_fd = shm_open("app_data", O_RDONLY, 0666);
    ptr = mmap(0, 4096, PROT_READ, MAP_SHARED, shm_fd, 0);
    m_stringData = (char*)ptr;

//    qDebug("%s", (char*)ptr);
//    shm_unlink("lg_dcv");

    return (char*)ptr;
}
