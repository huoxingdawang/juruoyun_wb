#include "jry_bl_string.h"
int jry_bl_string_init(jry_bl_string *s,int init_by,...)
{
	if(s->len!=0||s->size!=0||s->size!=0)
		return 0;
	if(init_by==JRY_BL_STRING_INIT_BY_NONE)
	{
		s->len=0;
		s->size=JRY_BL_STRING_BASIC_LENGTH;
		s->s=(char *)malloc(s->size);
		if(s->s==NULL)
			return 0;
	}
	else if(init_by==JRY_BL_STRING_INIT_BY_LENGTH)
	{
		va_list valist;
		va_start(valist,init_by);
		s->len=0;
		s->size=va_arg(valist, int);
		s->s=(char *)malloc(s->size);
		va_end(valist);	
		if(s->s==NULL)
			return 0;		
	}
	else if(init_by==JRY_BL_STRING_INIT_BY_STRING)
	{
		va_list valist;
		va_start(valist,init_by);
		char *in=va_arg(valist,char*);
		s->len=strlen(in);
		s->size=(ceil((double)s->len/JRY_BL_STRING_BASIC_LENGTH))*JRY_BL_STRING_BASIC_LENGTH;
		s->s=(char *)malloc(s->size);
		stpcpy(s->s,in);
		va_end(valist);	
		
	}
	else
	{
		return 0;
	}
	return 1;
}
int jry_bl_string_deinit(jry_bl_string *s)
{
	free(s->s);
	s->s=NULL;
	s->size=0;
	s->len=0;
}
int jry_bl_string_view(FILE * file,jry_bl_string *s)
{
	fprintf(file,"len:\t%d\nsize:\t%d\ns:\t%s\n",s->len,s->size,s->s);
}
int jry_bl_string_link(jry_bl_string *s1,jry_bl_string *s2)
{
	if((s1->len+s2->len)>s1->size)
	{
		s1->size=(ceil((double)(s1->len+s2->len)/JRY_BL_STRING_BASIC_LENGTH))*JRY_BL_STRING_BASIC_LENGTH;
		char * sb=realloc(s1->s,s1->size);
		if(sb==NULL)
			return 0;
		s1->s=sb;
	}
	for(int i=0;i<s2->len;i++)
		s1->s[s1->len+i]=s2->s[i];
	s1->len=(s1->len+s2->len);
	s1->s[s1->len]=0;
	return 1;
}
int jry_bl_string_add(jry_bl_string *s1,char * s2)
{
	int s2_len=strlen(s2);
	if((s1->len+s2_len)>s1->size)
	{
		s1->size=(ceil((double)(s1->len+s2_len)/JRY_BL_STRING_BASIC_LENGTH))*JRY_BL_STRING_BASIC_LENGTH;
		char * sb=realloc(s1->s,s1->size);
		if(sb==NULL)
			return 0;
		s1->s=sb;
	}
	for(int i=0;i<s2_len;i++)
		s1->s[s1->len+i]=s2[i];	
	s1->len=(s1->len+s2_len);
	s1->s[s1->len]=0;
	return 1;
}
long long jry_bl_string_string_to_int(jry_bl_string *s,int start)
{
	register int f,i;register char c;register long long x=0;
	for (f=0,i=start;(c=s->s[i])<'0'||c>'9'&&i<s->len;f=c=='-',++i);
	for (x=c-'0',++i; (c=s->s[i])>='0'&&c<='9'&&i<s->len; x=(x<<3)+(x<<1)+c-'0',++i);
	return f?-x:x;
}
int jry_bl_string_int_to_string(jry_bl_string *s,long long in)
{
	register int f=(in<0),cnt=20;
	char b[21];
	if(f)
		in=-in;
	b[cnt--]=0;
	while(in)
	{
		b[cnt--]=in%10+'0';
		in/=10;
	}
	if(f)
		b[cnt--]='-';
	jry_bl_string_add(s,b+cnt+1);
	return 1;
}

