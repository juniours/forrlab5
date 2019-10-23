#include <stdio.h>
#ifdef WIN32
#include <windows.h>
#define funcopenlibrary(libname) LoadLibrary(libname)
#else
#include <dlfcn.h>
#endif

void LoadRun(const char * const s) {
void * lib;
void (*mass)(void), (*matrixx)(void);
#ifdef WIN323
lib = LoadLibrary(s);
if (!lib) {
printf("cannot open library '%s'\n", s);
return;
}
if (s=="mas.dll"){ mass = (void (*)(void))GetProcAddress((HINSTANCE)lib, "mass");
if (mass == NULL) { printf("cannot load function\n");}
 else {
mass();}
}
if (s=="matrix.dll"){ matrixx = (void (*)(void))GetProcAddress((HINSTANCE)lib, "matrixx");
if (matrixx == NULL) { printf("cannot load function\n");}
 else {
matrixx();}
}
FreeLibrary((HINSTANCE)lib);
#else
lib = dlopen(s, RTLD_LAZY);
if (!lib) {
printf("cannot open library '%s'\n", s);
return;
}
if (s=="matrix.dll"){ matrixx = (void (*)(void))dlsym(lib, "matrixx");
if (matrixx == NULL) { printf("cannot load function\n");}
 else {
matrixx();}
if (s=="mas.dll"){ mass = (void (*)(void))dlsym(lib, "mass");
if (mass == NULL) { printf("cannot load function\n");}
 else {
mass();}}
}
dlclose(lib);
#endif
}

int main(void)
{
int a=0,b=1;
printf("Choose library:\n1-array\n2-matrix\n3-exit\n");
while(b)
{
scanf("%d",&a);
if(a==1)
LoadRun("mas.dll");
if(a==2)
LoadRun("matrix.dll");
if(a==3)
b=0;
}
return 0;
}
