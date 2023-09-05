"""
BANO
"""

import argparse
import sys

from core.constants import CURRENT_VERSION

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='A command line utility for banco BANO', prog='bbn')
    parser.add_argument('-v', '--version', help='Display the current version', action="store_true")
    #subparsers = parser.add_subparsers(dest='command', help='command help')

    args = parser.parse_args()

    if args.version:
        print("bbn version %s" % CURRENT_VERSION)
    elif args.command is not None:
        args.func(args)
    else:
        parser.print_help(sys.stderr)
        exit(1)

    exit(0)