#ifdef __WATCOMC__
#define NULL ((void *)0)
#define FAR __far
#define NEAR __near
#else
#define FAR /*far*/
#define NEAR /*near*/
#endif
