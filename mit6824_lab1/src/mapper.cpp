#include <iostream>
#include <unordered_map>
#include <string>
#include <signal.h>
#include <memory.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#include <sys/epoll.h>
#include <sys/timerfd.h>
#include <sys/types.h>
#include <functional>

#include "Imagine_MapReduce/Imagine_MapReduce.h"

using namespace std;
using namespace Imagine_MapReduce;

void addsig(int sg, void(handler)(int))
{
    struct sigaction sa;
    memset(&sa, '\0', sizeof(sa));
    sigfillset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = handler;
    sigaction(sg, &sa, NULL);
}

int main(int argc, char *argv[])
{

    if (argc <= 1)
    {
        printf("please input two parameter at least!\n");
        return 0;
    }

    // int port=atoi(argv[1]);

    addsig(SIGPIPE, SIG_IGN);

    string port = argv[1];

    Mapper<int, string, string, int> mapper(argv[1]);

    mapper.loop();

    while (1);

    return 0;
}