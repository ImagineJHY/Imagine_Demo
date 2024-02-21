#include "Imagine_Rpc/Imagine_Rpc.h"

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

using namespace std;
using namespace Imagine_Rpc;

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

    // unsigned int ip=Rpc::ConvertIpFromStringToNet("3.4.5.6");
    // unsigned short int po=Rpc::ConvertPortFromStringToNet("3456");

    // cout<<ip<<endl;
    // cout<<Rpc::ConvertIpFromNetToString(ip)<<endl;
    // cout<<po<<endl;
    // cout<<Rpc::ConvertPortFromNetToString(po)<<endl;
    Imagine_Rpc::RpcZooKeeperBuilder builder("../config/zookeeper_profile.yaml");
    builder.Start();

    return 0;
}
