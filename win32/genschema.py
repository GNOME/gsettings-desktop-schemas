# Simple Python script to generate the full .schema.xml files

import os
import sys
import argparse

from replace import replace_multi

def main(argv):
    parser = argparse.ArgumentParser(description='Generate .schema.xml from its template.')
    parser.add_argument('-i', '--input', help='Input file', required=True)
    parser.add_argument('-o', '--output', help='Output file', required=True)
    parser.add_argument('--package', help='Package Name', required=True)
    parser.add_argument('--prefix', help='Installation Prefix', required=False)
    parser.add_argument('--datadir', help='Datadir (default $(prefix)/share)', required=False)
    args = parser.parse_args()

    if args.prefix is None and args.datadir is None:
        raise AttributeError('Either --datadir or --prefix is required')
    if args.prefix is not None and args.datadir is not None:
        print('--prefix argument ignored as --datadir is specified')

    datadir = ''
    if args.datadir is not None:
        datadir = args.datadir
    else:
        datadir = os.path.join(args.prefix, 'share')

    if not os.path.exists(datadir):
        raise AssertionError('The specified --datadir or --prefix does not exist!')

    # We need to convert Windows '\' into '/'
    datadir_forward_slash = os.path.abspath(datadir).replace('\\','/')
    replace_items = {'@GETTEXT_PACKAGE@': args.package,
                     '@datadir@': '/' + datadir_forward_slash}

    replace_multi(args.input,
                  args.output,
                  replace_items)

if __name__ == '__main__':
    sys.exit(main(sys.argv))
