#Script to upload a Arducopter File to the Bebop2 Drone

echo "Please specify arducopter binary path (relative to this script's path)."

read path

cd $path

#disconecting all present adb connections
adb disconnect

#calculating checksum of the new ardupilot Version
newmd5sum=$(md5sum arducopter |cut -c  1-32)

echo $newmd5sum

#connecting to the adb-Server
echo "Press the power Button 4 times!"
sleep 5
message=$(adb connect 192.168.42.1:9050)


if [[ $message = "connected to 192.168.42.1:9050" ]]
then
    echo "succesfully connected"
else
    echo $message
    echo "please retry!"
    exit
fi
sleep 1
adb shell mount -o remount,rw /

oldmd5sum=$(adb shell md5sum /data/ftp/internal_000/APM/arducopter |cut -c  1-32)

#uploading and checking the new arducopter Version
adb push arducopter /data/ftp/internal_000/APM/
adb shell chmod u=rwx /data/ftp/internal_000/APM/arducopter
uploadedmd5=$(adb shell md5sum /data/ftp/internal_000/APM/arducopter |cut -c  1-32)

if  [ $newmd5sum = $uploadedmd5 ] ;then
    echo "uploaded succesfully!"
else
    echo "an error occured!"
    exit
fi


#checking launch skript
modifiedScipt='61318dba19b6510b9095762ba55e27b7'
presentScript=$(adb shell md5sum /etc/init.d/rcS_mode_default|cut -c  1-32)

if  [ $presentScript = $modifiedScipt ] 
then
    echo "launchskript ok"
else
    #Backup of the Standard launch skript
    adb shell cp etc/init.d/rcS_mode_default etc/init.d/rcS_mode_default_backup
    #changing of the skript
    #only works for the "real" default launch skript
    adb pull etc/init.d/rcS_mode_default
    sed -i s/DragonStarter/#DragonStarter/g rcS_mode_default
    sed -i ' /DragonStarter/G' rcS_mode_default
    sed -i '/DragonStarter/!b;n;c./data/ftp/internal_000/APM/arducopter -A udp:192.168.42.255:14550:bcast -B /dev/ttyPA1 -C udp:192.168.42.255:14551:bcast -l /data/ftp/internal_000/APM/logs -t /data/ftp/internal_000/APM/terrain' rcS_mode_default
    chmod u=rwx rcS_mode_default
    adb push rcS_mode_default etc/init.d/rcS_mode_default
    echo "please verify Launch that the launch skrip is correct"
fi

#restarting Drone
adb shell sync
adb shell reboot


