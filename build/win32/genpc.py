# Simple script to generate pkg-config (.pc) file
# for gsettings-desktop-schemas

import os
import sys

from replace import replace_multi
from pc_base import BasePCItems

def main(argv):
    base_pc = BasePCItems()

    base_pc.setup(argv)

    # Generate gsettings-desktop-schemas.pc
    replace_multi(base_pc.top_srcdir + '/gsettings-desktop-schemas.pc.in',
                  base_pc.srcdir + '/gsettings-desktop-schemas.pc',
                  base_pc.base_replace_items)

if __name__ == '__main__':
    sys.exit(main(sys.argv))
