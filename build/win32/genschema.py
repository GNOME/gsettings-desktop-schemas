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
    parser.add_argument('--prefix', help='Installation Prefix', required=True)
    args = parser.parse_args()

    replace_items = {'@GETTEXT_PACKAGE@': args.package,
                     '@datadir@': '/' + args.prefix + '/share'}

    replace_multi(args.input,
                  args.output,
                  replace_items)

if __name__ == '__main__':
    sys.exit(main(sys.argv))
