#!/bin/sh

datadir=$1

# Package managers set this so we don't need to run
if [ -z "$DESTDIR" ]; then
  echo Compiling GSettings schemas...
  glib-compile-schemas ${datadir}/glib-2.0/schemas
fi
