#!/usr/bin/python
#
# Simple utility script to get URI from a given path
#
# Author: Fan, Chun-wei
# Date: September 03, 2014

import os
import sys
import string

def get_abs_path(path):
    return os.path.abspath(path)

def get_abs_path_posix(path):
    path_mid = get_abs_path(path)
    return path_mid.replace('\\','/')

def get_uri_from_path(path):
    return '/' + get_abs_path_posix(path)

def main(argv):
    if len(argv) != 2:
        raise SystemExit('Error: Usage: python %s <path>' % __file__)
    if not os.path.exists(argv[1]):
        raise SystemExit('Error: Entered path does not exist')
    print(get_uri_from_path(argv[1]))

if __name__ == '__main__':
    sys.exit(main(sys.argv))
