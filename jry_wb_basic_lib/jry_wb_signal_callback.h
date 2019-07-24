#ifndef __JRY_WB_SIGNAL_CALLBACK_H
#define __JRY_WB_SIGNAL_CALLBACK_H

#include <stdio.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
extern int jry_wb_socket_handle;
extern int jry_wb_pid_list_cnt;
extern pid_t jry_wb_pid_list[10];
void jry_wb_signal_callback(int sign);
void jry_wb_signal_callback_child(int sign);
void jry_wb_signal_callback_listener(int sign);

#endif
