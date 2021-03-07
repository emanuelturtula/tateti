#ifndef __CONFIG_H__
#define __CONFIG_H__

#ifdef DEBUG
# define DEBUG_PRINT(x) printf x
#else
# define DEBUG_PRINT(x) do {} while (0)
#endif

#define TCP_PORT 2000

#endif