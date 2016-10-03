#include <stdlib.h>
#include <stdio.h>

int strleni(char *);
char* strcati(char *, char *);
char* strncpyi(char *, char *,int);
char* strchri(char *, char);
int strcmpi(char *, char *);

char* strstri(char *, char *);
char* strcpy(char*, char*);
char* strncati(char *, char *, int);

void main(){
  char test1[12] = "Happy ";
  char test2[12] = "Birday";
  printf("Test1: \"%s\" | Test2: \"%s\"\n", test1, test2);
  printf("Size of test1: %d    | ", strleni(test1));
  printf("  Size of test2: %d\n\n", strleni(test2));

  strcati(test1,test2);
  printf("Test1 after strcati: %s\n", test1);
  printf("Test2 after strcati: %s\n\n", test2);

  strncpyi(test2,test1,7);
  printf("Test1 after strncpyi (to 7 char): %s\n",test1);
  printf("Test2 after strncpyi (to 7 char): %s\n\n", test2);

  printf("Where is 'd' in test1? %s\n", strchri(test1,'d'));
  printf("Mem. Address? %p\n", strchri(test1,'i'));
  printf("Where is 'g' in test2? %s\n", strchri(test2,'g'));
  printf("Mem. Address? %p\n\n", strchri(test2,'r'));

  printf("Comparing test1 to test2: %d\n", strcmpi(test1,test2));
  printf("Comparing test2 to test1: %d\n\n", strcmpi(test2,test1));
  strncpyi(test2,test1,12);
  printf("test1 and test 2 after copy: %s, %s\n",test1,test2);
  printf("Comparing test1 to test2 after: %d\n", strcmpi(test1,test2));

  printf("\n=========Extra stuff=====\n");
  printf("Where's \"Hey\" in \"Why Hey\"? %s\n", strstri("Why Hey There.", "Hey"));
  printf("How about \"wya\" in \"familydinner\"? %s\n\n", strstri("familydinner","wya"));

  char t1[20] = "I really want";
  char t2[10] = "walnuts";
  printf("Before strcpyi: \"%s\", \"%s\"\n",t1,t2);
  strcpy(t1,t2);
  printf("After strcpyi: \"%s\", \"%s\"\n\n",t1,t2);

  printf("Before strncati (to 4 chars): \"%s\", \"%s\"\n",t1,t2);
  strncati(t1,t2,4);
  printf("After strncati (to 4 chars): \"%s\", \"%s\"\n",t1,t2);
  
}

int strleni(char *s){
  int r = 0;
  while (*s){
    r++;
    s++;
  }
  return r;
}

char* strcati(char *dest, char *src){
  dest += strleni(dest);
  while (*src){
    *dest = *src;
    src++;
    dest++;
  }
  *dest = 0;
  return dest;
}

char* strncpyi(char *dest, char *src, int n){
    char *dst = dest;
    if (strleni(dest) < (strleni(src) - n)){
      dst += (strleni(src) - n);
      *dst = 0;
      dst -= (strleni(src) - n);
      }
    
    while (*src && n){
        *dst = *src;
        dst++;
        src++;
	n--;
    }
    
    return dest;
}


char* strchri(char *src, char fnd){
  while (*src && *src != fnd){
    src++;
  }
  if (*src == 0) {return NULL;}
  return src;
}

int strcmpi(char *src, char *cmp){
  while (*src && *src == *cmp){
    src++;
    cmp++;
  }
  if (*src == *cmp) {return 0;}
  if (*src > *cmp) {return 1;}
  else return -1;
}

/*~~~~~~~ Extra stuff ~~~~~~~~*/
char* strstri(char *src, char *fnd){
  char *h = fnd;
  while (*src && *h){
    if (*src == *h){h++;}    
    else if (*src != *h){h = fnd;}
    src++;
  }
  if (*h == 0) {return src;}
  return NULL;
}

char* strcpyi(char *dest, char *src){
    char *dst = dest;
    if (strleni(dest) < strleni(src)){
      dst += strleni(src);
      *dst = 0;
      dst -= strleni(src);
      }
    
    while (*src){
        *dst = *src;
        dst++;
        src++;
    }
    
    return dest;
}

char* strncati(char *dest, char *src, int n){
  dest += strleni(dest);
  while (*src && n){
    *dest = *src;
    src++;
    dest++;
    n--;
  }
  *dest = 0;
  return dest;
}
