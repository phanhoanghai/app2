#ifndef APPDEFINE_H
#define APPDEFINE_H

#ifndef COMMON_H_
#define COMMON_H_

#include <string>

const std::string json_defined_datas[7] = {"index", "name", "assem", "cplus", "js", "qml", "openGL"};

#define CHECK(x) \
    do { \
        if (!(x)) { \
            fprintf(stderr, "%s:%d: ", __func__, __LINE__); \
            perror(#x); \
            exit(-1); \
        } \
    } while (0) \

#define ROUNDF(f, c) (((float)((int)((f) * (c))) / (c)))

#endif /* #ifndef COMMON_H_ */

#endif // APPDEFINE_H
