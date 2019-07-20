#include "jry_wb_signal_callback.h"
void jry_wb_signal_callback(int sign)
{
	fputs("\nSIGNAL INTERRUPT \nBye juruoyun webserve! \nSAFE EXIT\n",stdout);
	close(jry_wb_socket_handle);
	exit(0);
}