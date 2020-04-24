#ifndef __split_H_
#define __split_H_

typedef char *String;
typedef String *Strings;
typedef unsigned int Index;

​typedef struct
{
  Strings substrings;
  unsigned int count;
} Substrings;

​unsigned int length_of(char *);
String substring(String, Index, Index);
Substrings *copy_substrings(Strings, int);
Substrings *split(String, char)

#endif