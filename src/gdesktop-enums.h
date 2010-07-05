/*
 * Copyright © 2010 Codethink Limited
 *
 * This is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/**
 * SECTION:gdesktop-enums
 * @short_description:
 *
 * Long description.
 */
#ifndef __gdesktop_enums_h__
#define __gdesktop_enums_h__

/**
 * GDesktopProxyMode:
 * @G_DESKTOP_PROXY_MODE_NONE:
 * @G_DESKTOP_PROXY_MODE_MANUAL:
 * @G_DESKTOP_PROXY_MODE_AUTO:
 */
typedef enum
{
  G_DESKTOP_PROXY_MODE_NONE,
  G_DESKTOP_PROXY_MODE_MANUAL,
  G_DESKTOP_PROXY_MODE_AUTO
} GDesktopProxyMode;

/**
 * GDesktopToolbarStyle:
 * @G_DESKTOP_TOOLBAR_STYLE_BOTH:
 * @G_DESKTOP_TOOLBAR_STYLE_BOTH_HORIZ:
 * @G_DESKTOP_TOOLBAR_STYLE_ICONS:
 * @G_DESKTOP_TOOLBAR_STYLE_TEXT:
 */
typedef enum
{
  G_DESKTOP_TOOLBAR_STYLE_BOTH,
  G_DESKTOP_TOOLBAR_STYLE_BOTH_HORIZ,
  G_DESKTOP_TOOLBAR_STYLE_ICONS,
  G_DESKTOP_TOOLBAR_STYLE_TEXT
} GDesktopToolbarStyle;

/**
 * GDesktopToolbarIconSize:
 * @G_DESKTOP_TOOLBAR_ICON_SIZE_SMALL:
 * @G_DESKTOP_TOOLBAR_ICON_SIZE_LARGE:
 */
typedef enum
{
  G_DESKTOP_TOOLBAR_ICON_SIZE_SMALL,
  G_DESKTOP_TOOLBAR_ICON_SIZE_LARGE
} GDesktopToolbarIconSize;

/**
 * GDesktopBackgroundStyle:
 * @G_DESKTOP_BACKGROUND_STYLE_NONE:
 * @G_DESKTOP_BACKGROUND_STYLE_WALLPAPER:
 * @G_DESKTOP_BACKGROUND_STYLE_CENTERED:
 * @G_DESKTOP_BACKGROUND_STYLE_SCALED:
 * @G_DESKTOP_BACKGROUND_STYLE_STRETCHED:
 * @G_DESKTOP_BACKGROUND_STYLE_ZOOM:
 * @G_DESKTOP_BACKGROUND_STYLE_SPANNED:
 */
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

/**
 * GDesktopBackgroundShading:
 * @G_DESKTOP_BACKGROUND_SHADING_SOLID,
 * @G_DESKTOP_BACKGROUND_SHADING_VERTICAL,
 * @G_DESKTOP_BACKGROUND_SHADING_HORIZONTAL
 */
typedef enum
{
  G_DESKTOP_BACKGROUND_SHADING_SOLID,
  G_DESKTOP_BACKGROUND_SHADING_VERTICAL,
  G_DESKTOP_BACKGROUND_SHADING_HORIZONTAL
} GDesktopBackgroundShading;

#endif /* __gdesktop_enums_h__ */
