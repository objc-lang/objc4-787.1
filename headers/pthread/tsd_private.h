#include <os/tsd.h>

/*
 * NOTE: this file conflicted with defintions in the next include so
 * we just use that header and keep the few defines that were specific
 * to this file.
 */
#include <System/pthread_machdep.h>

/* Constant TSD slots for inline pthread_getspecific() usage. */

/* Keys 0 - 9 are for Libsyscall/libplatform usage */
#define _PTHREAD_TSD_SLOT_PTHREAD_SELF __TSD_THREAD_SELF
#define _PTHREAD_TSD_SLOT_ERRNO __TSD_ERRNO
#define _PTHREAD_TSD_SLOT_MIG_REPLY __TSD_MIG_REPLY
#define _PTHREAD_TSD_SLOT_MACH_THREAD_SELF __TSD_MACH_THREAD_SELF
#define _PTHREAD_TSD_SLOT_PTHREAD_QOS_CLASS	__TSD_THREAD_QOS_CLASS
#define _PTHREAD_TSD_SLOT_RETURN_TO_KERNEL __TSD_RETURN_TO_KERNEL
#define _PTHREAD_TSD_SLOT_PTR_MUNGE __TSD_PTR_MUNGE
#define _PTHREAD_TSD_SLOT_MACH_SPECIAL_REPLY __TSD_MACH_SPECIAL_REPLY
//#define _PTHREAD_TSD_SLOT_SEMAPHORE_CACHE __TSD_SEMAPHORE_CACHE

/*
 * Windows 64-bit ABI bakes %gs relative accesses into its code in the same
 * range as our TSD keys.  To allow some limited interoperability for code
 * targeting that ABI, we leave slots 6 and 11 unused.
 *
 * The Go runtime on x86_64 also uses this because their ABI doesn't reserve a
 * register for the TSD base.  They were previously using an arbitrarily chosen
 * dynamic key and relying on being able to get it at runtime, but switched to
 * this slot to avoid issues with that approach.  It's assumed that Go and
 * Windows code won't run in the same address space.
 */
//#define _PTHREAD_TSD_SLOT_RESERVED_WIN64 6

#define _PTHREAD_TSD_RESERVED_SLOT_COUNT _PTHREAD_TSD_RESERVED_SLOT_COUNT
