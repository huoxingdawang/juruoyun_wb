#ifndef __JRY_WB_SIGNAL_CALLBACK_H
#define __JRY_WB_SIGNAL_CALLBACK_H

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
extern int jry_wb_socket_handle;
void jry_wb_signal_callback(int sign);

#endif
