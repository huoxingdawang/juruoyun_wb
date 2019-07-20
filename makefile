CC = gcc
all:server clean
	@echo -e "\nOK................................\n\n\n"
clean:
	-rm *.o
server: main.o jry_wb_color_text.o jry_wb_http_content_type.o jry_wb_signal_callback.o
	$(CC) -o server main.o jry_wb_color_text.o jry_wb_http_content_type.o jry_wb_signal_callback.o
main.o: main.c
	$(CC) -c -o main.o main.c
jry_wb_http_content_type.o: ./jry_wb_basic_lib/jry_wb_http_content_type.c
	$(CC) -c -o jry_wb_http_content_type.o ./jry_wb_basic_lib/jry_wb_http_content_type.c
jry_wb_color_text.o: ./jry_wb_basic_lib/jry_wb_color_text.c
	$(CC) -c -o jry_wb_color_text.o ./jry_wb_basic_lib/jry_wb_color_text.c	
jry_wb_signal_callback.o: ./jry_wb_basic_lib/jry_wb_signal_callback.c
	$(CC) -c -o jry_wb_signal_callback.o ./jry_wb_basic_lib/jry_wb_signal_callback.c