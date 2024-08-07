/* Goxel 3D voxels editor
 *
 * copyright (c) 2021 Guillaume Chereau <guillaume@noctua-software.com>
 *
 * Goxel is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.

 * Goxel is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.

 * You should have received a copy of the GNU General Public License along with
 * goxel.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "goxel.h"

static int gui_quit_popup(void *data)
{
    int ret = 0;
    gui_text(_("File Has Unsaved Changes"));

    gui_row_begin(0);
    if (gui_button(_("Quit"), 0, 0)) {
        goxel.quit = true;
        ret = 1;
    }
    if (gui_button(_("Cancel"), 0, 0)) {
        ret = 2;
    }
    gui_row_end();
    return ret;
}

void gui_query_quit(void)
{
    if (image_get_key(goxel.image) == goxel.image->saved_key) {
        goxel.quit = true;
        return;
    }
    gui_open_popup("##Quit", GUI_POPUP_RESIZE, NULL, gui_quit_popup);
}
