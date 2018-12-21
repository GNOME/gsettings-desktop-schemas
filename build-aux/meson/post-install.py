#!/usr/bin/env python3

import os
import subprocess
import sys

datadir = sys.argv[1]

# Packaging tools define DESTDIR and this isn't needed for them
if 'DESTDIR' not in os.environ:
    print('Compiling GSettings schemas...')
    subprocess.call(['glib-compile-schemas',
                    os.path.join(datadir, 'glib-2.0', 'schemas')])
