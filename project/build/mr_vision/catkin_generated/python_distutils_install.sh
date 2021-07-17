#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/dixuan/Document/robotique/project/src/mr_vision"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/dixuan/Document/robotique/project/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/dixuan/Document/robotique/project/install/lib/python3/dist-packages:/home/dixuan/Document/robotique/project/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/dixuan/Document/robotique/project/build" \
    "/usr/bin/python3" \
    "/home/dixuan/Document/robotique/project/src/mr_vision/setup.py" \
     \
    build --build-base "/home/dixuan/Document/robotique/project/build/mr_vision" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/dixuan/Document/robotique/project/install" --install-scripts="/home/dixuan/Document/robotique/project/install/bin"
