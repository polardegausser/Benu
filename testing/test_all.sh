#!/bin/bash

# ./test_all.sh
# ./test_all.sh qemu
# ./test_all.sh qemu debug=yes
# ./test_all.sh qemu debug=yes K_INIT_PROG=demo

for chapter in * ; do
  if [ -d $chapter ] ; then
    #echo $chapter
    cd $chapter

    for increment in * ; do
      if [ -d $increment ] ; then
        cd $increment

        echo
        echo
        echo "================================================================="
        echo "Test $chapter/$increment: starting"
        echo

        if [ -e build.sh ] ; then
          ./build.sh cleanall
          ./build.sh $1
          if [ ! $? -eq 0 ] ; then
            exit
          fi
          ./build.sh cleanall
        else
          make cleanall
          make "$@"
          if [ ! $? -eq 0 ] ; then
            exit
          fi
          make cleanall
        fi

        echo
        echo "Test $chapter/$increment: completed"
        echo "================================================================="
        echo
        echo
#        sleep 1
        cd ..
      fi
    done

    cd ..
  fi
done
