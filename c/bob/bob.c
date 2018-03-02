#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "bob.h"

char* hey_bob(const char* str) { 
   char* trimmed = remove_spaces(str);
   if (strlen(trimmed) == 0)
      return SILENCE_RESPONSE;
   if (contain_some_letter(trimmed) && you_yell_at_him(trimmed))
      return YELL_RESPONSE;  
   if (you_ask_him_a_question(trimmed))
      return QUESTION_RESPONSE;
   return GENERIC_RESPONSE;
}

char* remove_spaces(const char *str) {
   size_t str_size = strlen(str);
   char *trimmed = malloc(str_size);
   char *oldstr = malloc(str_size);
   strncpy(oldstr, str, str_size);
   char *np = trimmed, *op = oldstr;
   do if (*op != ' ') *np++ = *op; while (*op++);
   return trimmed;
}

bool contain_some_letter(const char* str) {
   char* upp_str = str_toupper(str);
   for(size_t index = 0; index < strlen(str); index++) {
      if (upp_str[index] >= 'A' && upp_str[index] <= 'Z') return true;
   }
   return false;
}

bool you_yell_at_him(const char* str) {
   char* upp_str = str_toupper(str);
   return (strcmp(upp_str,str) == 0);
}

char* str_toupper(const char* str) {
   size_t str_size = strlen(str);
   int index = 0;
   char* upp_str = malloc(str_size);
   strncpy(upp_str, str, str_size);
   upp_str[str_size] = '\0';
   while(upp_str[index]) {
      upp_str[index] = toupper(str[index]);
      index++;
   }
   return upp_str;
}

bool you_ask_him_a_question(const char* str) {
   return (*str && str[strlen(str) - 1] == '?') ? true : false;
}

