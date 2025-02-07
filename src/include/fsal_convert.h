/* SPDX-License-Identifier: LGPL-3.0-or-later */
/*
 * Copyright CEA/DAM/DIF  (2008)
 * contributeur : Philippe DENIEL   philippe.deniel@cea.fr
 *                Thomas LEIBOVICI  thomas.leibovici@cea.fr
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 * ---------------------------------------
 */

/**
 * @defgroup FSAL File-System Abstraction Layer
 * @{
 */

/**
 * @file fsal_convert.h
 * @brief FSAL conversion function.
 */

#ifndef FSAL_CONVERT_H
#define FSAL_CONVERT_H

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#include "fsal_types.h"

/* convert error codes */
fsal_errors_t posix2fsal_error(int posix_errorcode);

static inline fsal_status_t posix2fsal_status(int posix_errorcode)
{
	return fsalstat(posix2fsal_error(posix_errorcode), posix_errorcode);
}

/** converts an fsal open flag to a POSIX open flag. */
void fsal2posix_openflags(fsal_openflags_t fsal_flags, int *p_posix_flags);

/** converts an FSAL permission test to a Posix permission test. */
int fsal2posix_testperm(fsal_accessflags_t testperm);

/**
 * Converts POSIX attributes (struct stat) to FSAL attributes
 * (fsal_attrib_list_t)
 */
void posix2fsal_attributes(const struct stat *buffstat,
			   struct fsal_attrlist *fsalattr_out);
void posix2fsal_attributes_all(const struct stat *buffstat,
			       struct fsal_attrlist *fsalattr_out);

/* mode bits are a uint16_t and chmod masks off type */

#define S_IALLUGO (~S_IFMT & 0xFFFF)

/**
 * @brief Convert FSAL mode to POSIX mode
 *
 * @param[in] fsal_mode FSAL mode to be translated
 *
 * @return The POSIX mode associated to fsal_mode.
 */
static inline mode_t fsal2unix_mode(uint32_t fsal_mode)
{
	return fsal_mode & S_IALLUGO;
}

/**
 * @brief Convert POSIX mode to FSAL mode
 *
 * @param[in] unix_mode POSIX mode to be translated
 *
 * @return FSAL mode associated with @c unix_mode
 */

static inline uint32_t unix2fsal_mode(mode_t unix_mode)
{
	return unix_mode & S_IALLUGO;
}

/** converts POSIX object type to fsal object type. */
object_file_type_t posix2fsal_type(mode_t posix_type_in);

/** converts posix fsid to fsal FSid. */
fsal_fsid_t posix2fsal_fsid(dev_t posix_devid);

/**
 * posix2fsal_time:
 * Convert POSIX time structure (time_t)
 * to FSAL time type (now struct timespec).
 */
static inline struct timespec posix2fsal_time(time_t tsec, time_t nsec)
{
	struct timespec ts = { .tv_sec = tsec, .tv_nsec = nsec };
	return ts;
}

const char *object_file_type_to_str(object_file_type_t type);

#define my_high32m(a) ((unsigned int)(a >> 32))
#define my_low32m(a) ((unsigned int)a)

fsal_dev_t posix2fsal_devt(dev_t posix_devid);

#endif /* !FSAL_CONVERT_H */
/** @} */
