#ifndef __JRY_WB_COLOR_TEXT_H
#define __JRY_WB_COLOR_TEXT_H

#include "include.h"

#define JRY_WB_COLOR_TEXT_LIGHT_RED 	0
#define JRY_WB_COLOR_TEXT_LIGHT_GREEN	1
#define JRY_WB_COLOR_TEXT_LIGHT_BLUE	2
#define JRY_WB_COLOR_TEXT_LIGHT_CYAN	3
#define JRY_WB_COLOR_TEXT_YELLOW		4
#define JRY_WB_COLOR_TEXT_MAGENTA		5
#define JRY_WB_COLOR_TEXT_WHITE			6
#define JRY_WB_COLOR_TEXT_NORMAL		7
#define JRY_WB_COLOR_TEXT_BLACK			8
#define JRY_WB_COLOR_TEXT_RED			9
#define JRY_WB_COLOR_TEXT_GREEN			10
#define JRY_WB_COLOR_TEXT_BROWN			11
#define JRY_WB_COLOR_TEXT_BLUE			12
#define JRY_WB_COLOR_TEXT_CYAN			13
#define JRY_WB_COLOR_TEXT_BOLD			14
#define JRY_WB_COLOR_TEXT_UNDERESCORE	15
#define JRY_WB_COLOR_TEXT_REVERSE		16


void jry_wb_color_text(int color,char* buf,char* string);

#endif
