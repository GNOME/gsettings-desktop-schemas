/*
 * Copyright © 2010 Codethink Limited
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 * Authors:
 *	Ryan Lortie <desrt@desrt.ca>
 */

#ifndef __gdesktop_enums_h__
#define __gdesktop_enums_h__

typedef enum
{
  G_DESKTOP_PROXY_MODE_NONE,
  G_DESKTOP_PROXY_MODE_MANUAL,
  G_DESKTOP_PROXY_MODE_AUTO
} GDesktopProxyMode;

typedef enum
{
  G_DESKTOP_TOOLBAR_STYLE_BOTH,
  G_DESKTOP_TOOLBAR_STYLE_BOTH_HORIZ,
  G_DESKTOP_TOOLBAR_STYLE_ICONS,
  G_DESKTOP_TOOLBAR_STYLE_TEXT
} GDesktopToolbarStyle;

typedef enum
{
  G_DESKTOP_TOOLBAR_ICON_SIZE_SMALL,
  G_DESKTOP_TOOLBAR_ICON_SIZE_LARGE
} GDesktopToolbarIconSize;

typedef enum
{
  G_DESKTOP_BACKGROUND_STYLE_NONE,
  G_DESKTOP_BACKGROUND_STYLE_WALLPAPER,
  G_DESKTOP_BACKGROUND_STYLE_CENTERED,
  G_DESKTOP_BACKGROUND_STYLE_SCALED,
  G_DESKTOP_BACKGROUND_STYLE_STRETCHED,
  G_DESKTOP_BACKGROUND_STYLE_ZOOM,
  G_DESKTOP_BACKGROUND_STYLE_SPANNED
} GDesktopBackgroundStyle;

typedef enum
{
  G_DESKTOP_BACKGROUND_SHADING_SOLID,
  G_DESKTOP_BACKGROUND_SHADING_VERTICAL,
  G_DESKTOP_BACKGROUND_SHADING_HORIZONTAL
} GDesktopBackgroundShading;

typedef enum
{
  G_DESKTOP_MOUSE_DWELL_MODE_WINDOW,
  G_DESKTOP_MOUSE_DWELL_MODE_GESTURE
} GDesktopMouseDwellMode;

typedef enum
{
  G_DESKTOP_MOUSE_DWELL_DIRECTION_LEFT,
  G_DESKTOP_MOUSE_DWELL_DIRECTION_RIGHT,
  G_DESKTOP_MOUSE_DWELL_DIRECTION_UP,
  G_DESKTOP_MOUSE_DWELL_DIRECTION_DOWN
} GDesktopMouseDwellDirection;

typedef enum
{
  G_DESKTOP_CLOCK_FORMAT_24H,
  G_DESKTOP_CLOCK_FORMAT_12H
} GDesktopClockFormat;

#endif /* __gdesktop_enums_h__ */
