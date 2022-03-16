#! /bin/bash

# Get directory of the script
SCRIPT=$(readlink -f "$0")
SCRIPTPATH=$(dirname "$SCRIPT")
AIRCRAFTPATH=$SCRIPTPATH/../../libraries/ladac-examples-data/FlightGear

# Set FG_AIRCRAFT environment variable
export FG_AIRCRAFT=$AIRCRAFTPATH:${FG_AIRCRAFT}

#cd /usr/share/games/flightgear

#setenv LD_LIBRARY_PATH /usr/share/games/flightgear/lib:$LD_LIBRARY_PATH
#setenv FG_ROOT /usr/share/games/flightgear/data
#setenv FG_SCENERY /usr/share/games/flightgear/Scenery:$FG_ROOT/Scenery:$FG_ROOT/WorldScenery

fgfs --aircraft=ViTOLmina --fdm=null --native-fdm=socket,in,30,localhost,5502,udp --native-ctrls=socket,out,30,127.0.0.1,5503,udp --fog-fastest --disable-clouds --start-date-lat=2004:06:01:09:00:00 --disable-sound --in-air --enable-freeze --airport=KSFO --runway=10L --altitude=7224 --heading=113 --offset-distance=4.72 --offset-azimuth=0 --geometry=640x480 --max-fps=30 --enable-terrasync
