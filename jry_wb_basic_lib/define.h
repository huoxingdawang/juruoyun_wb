#ifndef __DEFINE_H
#define __DEFINE_H


#define jry_wb_error_exit(x) {perror((jry_wb_color_text(JRY_WB_COLOR_TEXT_RED,char_buf,x),char_buf));exit(0);}
#define jry_wb_color_put(x,y) {puts((jry_wb_color_text(y,char_buf,x),char_buf));}

#endif

