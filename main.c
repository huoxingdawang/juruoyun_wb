#include "main.h"



#define JRY_WB_PID_MAX_COUNT 10
char char_buf[JRY_WB_MAX_BUFF_SIZE];
pid_t jry_wb_pid_list[JRY_WB_PID_MAX_COUNT];
int jry_wb_pid_list_cnt=0;

int jry_wb_socket_handle;
void http_send(int sock_client,char *content)
{
	char HTTP_HEADER[JRY_WB_MAX_BUFF_SIZE],HTTP_INFO[JRY_WB_MAX_BUFF_SIZE];
	int len=strlen(content);
	sprintf(HTTP_HEADER,JRY_WB_RESPONSE_HEAD,len,"text/html");
	len=sprintf(HTTP_INFO,"%s%s",HTTP_HEADER,content);
	send(sock_client,HTTP_INFO,len,0);
}
void progress(int i)
{
	pid_t pid=getpid();
	switch(i)
	{
		case 0:
			prctl(PR_SET_NAME,"jry_wb_listener",NULL,NULL,NULL);
			signal(SIGINT,jry_wb_signal_callback_listener);
			signal(SIGTERM,jry_wb_signal_callback_listener);
			int count=0;			
			jry_wb_socket_handle=socket(AF_INET,SOCK_STREAM,0);
			struct sockaddr_in skaddr;
			skaddr.sin_family=AF_INET;
			skaddr.sin_port=htons(JRY_WB_PORT);
			skaddr.sin_addr.s_addr=inet_addr("0.0.0.0");
			if(bind(jry_wb_socket_handle,(struct sockaddr *)&skaddr,sizeof(skaddr))==-1)
				jry_wb_error_exit("bind error");
			if(listen(jry_wb_socket_handle,JRY_WB_MAX_QUEUE_SIZE)==-1)
				jry_wb_error_exit("listen error");
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
			break;
		case 1:
			prctl(PR_SET_NAME,"jry_wb_1",NULL,NULL,NULL);
			signal(SIGINT,jry_wb_signal_callback_child);
			signal(SIGTERM,jry_wb_signal_callback_child);
			while(1)sleep(1);
			break;
		case 2:
			prctl(PR_SET_NAME,"jry_wb_2",NULL,NULL,NULL);
			signal(SIGINT,jry_wb_signal_callback_child);
			signal(SIGTERM,jry_wb_signal_callback_child);			
			while(1)sleep(1);
			break;			
	}	
}


int main()
{
	pid_t pid;
	signal(SIGINT,jry_wb_signal_callback);
	signal(SIGTERM,jry_wb_signal_callback);
	prctl(PR_SET_NAME,"jry_wb_main",NULL,NULL,NULL);
	for(int i=0;i<3;i++)
		if((pid=jry_wb_pid_list[jry_wb_pid_list_cnt++]=fork())<0)
			printf("forkerror\n");
		else if(pid==0)
			progress(i);
	pid_t jry_wb_pid_list_cpy[JRY_WB_PID_MAX_COUNT];
	for(int i=0;i<jry_wb_pid_list_cnt;i++)
		jry_wb_pid_list_cpy[i]=jry_wb_pid_list[i];
	jry_wb_color_text(JRY_WB_COLOR_TEXT_GREEN,char_buf,"OK ");				
	printf("%s %d children creat success.\n",char_buf,jry_wb_pid_list_cnt);	
	jry_bl_string s1={0,0,0};
	jry_bl_string_init(&s1,JRY_BL_STRING_INIT_BY_STRING,"pstree -p ");	
	jry_bl_string_int_to_string(&s1,(int)getpid());
	system(s1.s);
	jry_bl_string_deinit(&s1);
	for(;;)
	{
		pid=wait(jry_wb_pid_list);
		for(int i=0;i<jry_wb_pid_list_cnt;i++)
			if(jry_wb_pid_list_cpy[i]==pid)
			{
				jry_wb_color_text(JRY_WB_COLOR_TEXT_RED,char_buf,"Warning ");
				printf("%s child %d at %d has been killed,restarting now.\n",char_buf,pid,i);
				if((pid=jry_wb_pid_list[i]=fork())<0)
					printf("forkerror\n");
				else if(pid==0)
					progress(i);
				jry_wb_color_text(JRY_WB_COLOR_TEXT_GREEN,char_buf,"OK ");				
				printf("%s child %d at %d restarting success.\n",char_buf,pid,i);
				break;
			}
	}
}
