#include "jry_wb_color_text.h"
const char *jry_wb_color_text_data[]=
{	"\x1b[31m",
	"\x1b[32m",
	"\x1b[34m",
	"\x1b[36m",
	"\x1b[33m",
	"\x1b[35m",
	"\x1b[37m",
	"\x1b[0m",
	"\x1b[30m",
	"\x1b[31m",
	"\x1b[32m",
	"\x1b[33m",
	"\x1b[34m",
	"\x1b[36m",
	"\x1b[1m",
	"\x1b[4m",
	"\x1b[7m"
};
void jry_wb_color_text(int color,char* buf,char* string)
{
	if(color<0||color>16)
		color=JRY_WB_COLOR_TEXT_NORMAL;
	strcpy(buf,jry_wb_color_text_data[color]);
	strcat(buf,string);
	strcat(buf,"\x1b[0m");
}