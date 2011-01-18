#ifndef __CURL_CURLVER_H
#define __CURL_CURLVER_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2009, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at http://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 * $Id: curlver.h,v 1.47 2009-05-18 07:58:00 bagder Exp $
 ***************************************************************************/

/* This header file contains nothing but libcurl version info, generated by
   a script at release-time. This was made its own header file in 7.11.2 */

/* This is the global package copyright */
#define LIBCURL_COPYRIGHT "1996 - 2009 Daniel Stenberg, <daniel@haxx.se>."

/* This is the version number of the libcurl package from which this header
   file origins: */
#define LIBCURL_VERSION "7.19.6"

/* The numeric version number is also available "in parts" by using these
   defines: */
#define LIBCURL_VERSION_MAJOR 7
#define LIBCURL_VERSION_MINOR 19
#define LIBCURL_VERSION_PATCH 6

/* This is the numeric version of the libcurl version number, meant for easier
   parsing and comparions by programs. The LIBCURL_VERSION_NUM define will
   always follow this syntax:

         0xXXYYZZ

   Where XX, YY and ZZ are the main version, release and patch numbers in
   hexadecimal (using 8 bits each). All three numbers are always represented
   using two digits.  1.2 would appear as "0x010200" while version 9.11.7
   appears as "0x090b07".

   This 6-digit (24 bits) hexadecimal number does not show pre-release number,
   and it is always a greater number in a more recent release. It makes
   comparisons with greater than and less than work.
*/
#define LIBCURL_VERSION_NUM 0x071306

/*
 * This is the date and time when the full source package was created. The
 * timestamp is not stored in CVS, as the timestamp is properly set in the
 * tarballs by the maketgz script.
 *
 * The format of the date should follow this template:
 *
 * "Mon Feb 12 11:35:33 UTC 2007"
 */
#define LIBCURL_TIMESTAMP "Wed Aug 12 08:59:35 UTC 2009"

#endif /* __CURL_CURLVER_H */
