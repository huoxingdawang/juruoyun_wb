#include "main.h"


char char_buf[JRY_WB_MAX_BUFF_SIZE];
int jry_wb_socket_handle;

void http_send(int sock,char *content);



int main()
{
	signal(SIGINT,jry_wb_signal_callback);
	
	int count = 0; // 计数
	
	jry_wb_socket_handle=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in skaddr;
	skaddr.sin_family=AF_INET;
	skaddr.sin_port=htons(JRY_WB_PORT);
	skaddr.sin_addr.s_addr=inet_addr("0.0.0.0");
	if(bind(jry_wb_socket_handle,(struct sockaddr *)&skaddr,sizeof(skaddr))==-1)
		jry_wb_error_exit("bind error");
	if(listen(jry_wb_socket_handle,JRY_WB_MAX_QUEUE_SIZE)==-1)
		jry_wb_error_exit("listen error");
	jry_wb_color_put("OK",JRY_WB_COLOR_TEXT_GREEN);
	char char_buff[JRY_WB_MAX_BUFF_SIZE];
	struct sockaddr_in claddr;
	socklen_t length=sizeof(claddr);
	while(1)
	{
		int sock_client=accept(jry_wb_socket_handle,(struct sockaddr *)&claddr,&length);
		printf("%d\n",++count);
		if( sock_client <0 )
		{
			perror("accept error");
			exit(1);
		}
		memset(char_buff,0,sizeof(char_buff));
		int len=recv(sock_client,char_buff,sizeof(char_buff),0);
		
		
		fputs(char_buff,stdout);
		
		
		http_send(sock_client,"Hello World!");
		close(sock_client);
	}
	fputs("Bye juruoyun webserve",stdout);
	close(jry_wb_socket_handle);
	return 0;
}


void http_send(int sock_client,char *content)
{
	char HTTP_HEADER[JRY_WB_MAX_BUFF_SIZE],HTTP_INFO[JRY_WB_MAX_BUFF_SIZE];
	int len=strlen(content);
	sprintf(HTTP_HEADER,JRY_WB_RESPONSE_HEAD,len,"text/html");
	len=sprintf(HTTP_INFO,"%s%s",HTTP_HEADER,content);
	send(sock_client,HTTP_INFO,len,0);
}
