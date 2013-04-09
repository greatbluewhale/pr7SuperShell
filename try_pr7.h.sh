# compile and run try_pr7.h.c
#    sh try_pr7.h.sh >& x
#
#  C89 with the default settings
#    [Sun]  cc -v ...
#    [GCC]  gcc -Wall -Wextra ...
#
#  C99 with the minimal settings for Posix conformance
#    [Sun]  c99 -v -D_POSIX_C_SOURCE=200112L ...
#    [GCC]  gcc -std=c99 -Wall -Wextra -D_POSIX_C_SOURCE=200112L ...
#

source=try_pr7.h.c

system=`uname -s`
echo Testing $source on $system
echo

# Solaris
if [ $system = SunOS ]
then
  for compile in \
    "cc -v" \
    "cc -v -D_POSIX_C_SOURCE" \
    "cc -v -D_POSIX_C_SOURCE=200112L" \
    "c99 -v" \
    "c99 -v -D_POSIX_C_SOURCE" \
    "c99 -v -D_POSIX_C_SOURCE=200112L"
  do
    echo
    echo $compile $source
    $compile $source
    if [ -f a.out -a -x a.out ]
    then
      echo ; ./a.out ; echo ; rm a.out
    fi
  done
fi

# Solaris, Linux, Mac OS X
for compile in \
  "gcc -Wall -Wextra" \
  "gcc -Wall -Wextra -D_POSIX_C_SOURCE" \
  "gcc -Wall -Wextra -D_POSIX_C_SOURCE=200112L" \
  "gcc -std=c99 -Wall -Wextra" \
  "gcc -std=c99 -Wall -Wextra -D_POSIX_C_SOURCE" \
  "gcc -std=c99 -Wall -Wextra -D_POSIX_C_SOURCE=200112L"
do
  echo
  echo $compile $source
  $compile $source
  if [ -f a.out -a -x a.out ]
  then
    echo ; ./a.out ; echo ; rm a.out
  fi
done
