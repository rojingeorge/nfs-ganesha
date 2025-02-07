/* SPDX-License-Identifier: LGPL-3.0-or-later */
/*
 *
 * contributeur : Sachin Bhamare   sbhamare@panasas.com
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
 * @file os/mntent.h
 * @brief Platform dependent utilities for reading/writing fstab, mtab, etc..
 */

#ifndef MNTENT_H
#define MNTENT_H

#ifdef LINUX
#include <mntent.h>
#elif FREEBSD
#include <os/freebsd/mntent.h>
#endif

#endif /* MNTENT_H */
