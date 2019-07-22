CC = gcc
all:server clean
	@echo -e "\nOK................................\n\n\n"
clean:
	-rm *.o
server: main.o jry_wb_color_text.o jry_wb_http_content_type.o jry_wb_signal_callback.o jry_bl_string.o
	$(CC) -o server main.o jry_wb_color_text.o jry_wb_http_content_type.o jry_wb_signal_callback.o jry_bl_string.o -lm
main.o:
	$(CC) -c -lm -o main.o main.c
jry_wb_http_content_type.o:
	$(CC) -c -lm -o jry_wb_http_content_type.o ./jry_wb_basic_lib/jry_wb_http_content_type.c
jry_wb_color_text.o:
	$(CC) -c -lm -o jry_wb_color_text.o ./jry_wb_basic_lib/jry_wb_color_text.c	
jry_wb_signal_callback.o:
	$(CC) -c -lm -o jry_wb_signal_callback.o ./jry_wb_basic_lib/jry_wb_signal_callback.c
jry_bl_string.o:
	$(CC) -c -lm -o jry_bl_string.o ./jry_bl/jry_bl_string.c