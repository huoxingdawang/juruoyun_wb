#include "jry_wb_signal_callback.h"
void jry_wb_signal_callback(int sign)
{
	fputs("\nSIGNAL INTERRUPT\n",stdout);
	for(int i=0;i<jry_wb_pid_list_cnt;i++)
		kill(jry_wb_pid_list[i],SIGINT);
	for(int i=0;i<jry_wb_pid_list_cnt;i++)
		printf("Child progress %d exit,%d left\n",wait(jry_wb_pid_list),jry_wb_pid_list_cnt-i-1);
	fputs("Bye juruoyun webserve! \nSAFE EXIT\n",stdout);
	exit(0);
}
void jry_wb_signal_callback_child(int sign)
{
	exit(0);
}
void jry_wb_signal_callback_listener(int sign)
{
	close(jry_wb_socket_handle);
	exit(0);
}