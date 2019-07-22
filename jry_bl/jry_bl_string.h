#ifndef __JRY_BL_STRING_H
#define __JRY_BL_STRING_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

#define JRY_BL_STRING_BASIC_LENGTH 1024

#define JRY_BL_STRING_INIT_BY_NONE		0
#define JRY_BL_STRING_INIT_BY_LENGTH	1
#define JRY_BL_STRING_INIT_BY_STRING	2

typedef struct
{
	int len;
	int size;
	char * s;
}jry_bl_string;

int jry_bl_string_init(jry_bl_string *s,int init_by,...);
int jry_bl_string_deinit(jry_bl_string *s);
int jry_bl_string_link(jry_bl_string *s1,jry_bl_string *s2);
int jry_bl_string_view(FILE * file,jry_bl_string *s);
int jry_bl_string_add(jry_bl_string *s1,char * s2);
long long jry_bl_string_string_to_int(jry_bl_string *s,int start);
int jry_bl_string_int_to_string(jry_bl_string *s,long long in);
#endif
