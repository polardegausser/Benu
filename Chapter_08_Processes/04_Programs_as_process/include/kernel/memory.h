/*! Memory management */
#pragma once

/*! interface to threads (via syscall) */
int sys__sysinfo ( void *p );

#ifdef _KERNEL_ /* (for kernel and arch layer) */

#include <types/basic.h>

extern inline void *k_mem_init ( void *segment, size_t size );
extern inline void *kmalloc ( size_t size );
extern inline int kfree ( void *chunk );

struct _kproc_object_t_; typedef struct _kproc_object_t_ kproc_object_t;
struct _kprog_t_; typedef struct _kprog_t_ kprog_t;
struct _kprocess_t_; typedef struct _kprocess_t_ kprocess_t;

extern inline void *k_process_start_adr ( void *proc );
extern inline size_t k_process_size ( void *proc );

extern inline void *k_u2k_adr ( void *uadr, kprocess_t *proc );
extern inline void *k_k2u_adr ( void *kadr, kprocess_t *proc );

#define U2K_GET_ADR(ADR,PROC)	k_u2k_adr (ADR, PROC)
#define U2K_GET_INT(ADR,PROC)	( *( (int *) k_u2k_adr (ADR, PROC) ) )

#define K2U_GET_ADR(ADR,PROC)	k_k2u_adr (ADR, PROC)

#endif /* _KERNEL_ */