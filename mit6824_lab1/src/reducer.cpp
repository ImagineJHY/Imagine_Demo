#include "Reducer.h"

#include <iostream>
#include <unordered_map>
#include <string>
#include <signal.h>
#include <list>
#include <vector>

using namespace std;

void addsig(int sg, void(handler)(int))
{
    struct sigaction sa;
    // memset(&sa,'\0',sizeof(sa));
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

    addsig(SIGPIPE, SIG_IGN);

    // Reducer用9500端口
    int port_ = atoi(argv[1]);

    Imagine_MapReduce::Reducer<string, string> reducer("192.168.83.129", argv[1]);
    reducer.loop();

    return 0;
}
