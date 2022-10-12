/*
 * Digital rights management delegate
 * 
 * Copyright 2022 Bytedance Inc.
 * SPDX license identifier: LGPL-2.1-or-later
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <stddef.h>

#include "ttexport.h"

typedef struct DrmCtx {
    tt_drm_open open;
    tt_drm_decrypt decrypt;
    tt_drm_close close;
} DrmCtx;

static DrmCtx g_drm = {
    .open = NULL,
    .decrypt = NULL,
    .close = NULL,
};

void tt_register_drm(tt_drm_open open, tt_drm_decrypt decrypt, tt_drm_close close)
{
    g_drm.open = open;
    g_drm.decrypt = decrypt;
    g_drm.close = close;
}
