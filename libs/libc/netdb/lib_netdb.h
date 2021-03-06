/****************************************************************************
 * libs/libc/net/lib_netdb.h
 *
 *   Copyright (C) 2015 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __LIBS_LIBC_NETDB_LIB_NETDB_H
#define __LIBS_LIBC_NETDB_LIB_NETDB_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <netdb.h>

#ifdef CONFIG_LIBC_NETDB

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* This is the maximum number of alternate host names supported by this
 * implementation:
 */

#ifndef CONFIG_NETDB_MAX_ALTNAMES
#  define CONFIG_NETDB_MAX_ALTNAMES 4
#endif

/* This is the path to the system hosts file */

#ifndef CONFIG_NETDB_HOSTCONF_PATH
#  define CONFIG_NETDB_HOSTCONF_PATH "/etc/hosts"
#endif

/* Size of the buffer available for host data */

#ifndef CONFIG_NETDB_BUFSIZE
#  define CONFIG_NETDB_BUFSIZE 128
#endif

/****************************************************************************
 * Public Types
 ****************************************************************************/

struct services_db_s
{
  FAR const char *s_name;
  int s_port;
  int s_protocol;
};

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

EXTERN struct hostent g_hostent;
EXTERN char g_hostbuffer[CONFIG_NETDB_BUFSIZE];
EXTERN const struct services_db_s g_services_db[];

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* CONFIG_LIBC_NETDB */
#endif /* __LIBS_LIBC_NETDB_LIB_NETDB_H */
