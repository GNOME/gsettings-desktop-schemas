/*
 * Copyright © 2010 Codethink Limited
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
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


#endif /* __gdesktop_enums_h__ */
