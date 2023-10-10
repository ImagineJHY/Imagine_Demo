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
#include "MapReduceMaster.h"

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

string aaaaa(char *a)
{
    cout << strlen(a) << endl;
    return "";
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

    // master用9000端口
    string port_ = argv[1];

    MapReduceMaster master("192.168.83.130", port_, "192.168.83.130", "9999", 5);
    master.loop();

    sleep(2);

    std::vector<std::string> ddd;
    ddd.push_back("testfile.txt");
    master.MapReduce(ddd, 5, 40);
    while (1);

    return 0;
}