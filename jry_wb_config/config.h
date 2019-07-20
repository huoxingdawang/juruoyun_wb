#ifndef __CONFIG_H
#define __CONFIG_H


#define JRY_WB_PORT 8888
#define JRY_WB_MAX_QUEUE_SIZE 20
#define JRY_WB_MAX_BUFF_SIZE 1024
#define JRY_WB_RESPONSE_HEAD	"HTTP/1.1 200 OK\r\n"\
								"Server:juruoyun web serve V1.0\r\n"\
								"Accept-Ranges: bytes\r\n"\
								"Content-Length: %d\r\n"\
								"Connection: close\r\n"\
								"Content-Type: %s\r\n\r\n"

#endif
