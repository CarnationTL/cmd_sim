#!/bin/bash - 
#===============================================================================
#
#          FILE: clang_gen.sh
# 
#         USAGE: ./clang_gen.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: tongl (), 
#  ORGANIZATION: 
#       CREATED: 2013年07月11日 16时35分41秒 CST
#      REVISION:  ---
#===============================================================================

make CC='~/.vim/bundle/clang_complete/bin/cc_args.py gcc' CXX='~/.vim/bundle/clang_complete/bin/cc_args.py g++' -B

