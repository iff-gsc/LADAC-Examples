# Build ArduCopter for Bebop2 and Upload

With these instructions it should be relatively easy to fly with your Bebop2 with your own flight controller code.
Please take a look at the general instructions of how to [implement your Matlab/Simulink controller in the ArduPilot code](../../../libraries/LADAC/utilities/interfaces_external_programs/ArduPilot_custom_controller/).


## Motivation

The general instruction are restricted to Pixhawk boards.
For the Bebop2, some things will be different. This is described here.
You can either take [The default way](#the-default-way) based on the instructions on the ArduPilot website (problems included).
Or you can take [The easy way](#the-easy-way) based on the provided instructions here (recommended).


## Installation/Preparation

- Make yourself familiar with the general instruction of how to [implement your Matlab/Simulink controller in the ArduPilot code](../../../libraries/LADAC/utilities/interfaces_external_programs/ArduPilot_custom_controller/).
- Make yourself familiar with the instruction on the [ArduPilot website: Building for Bebop 2](https://ardupilot.org/dev/docs/building-for-bebop-2.html) (also watch the video!). 
  Note that for the Matlab/Simulink controller the ```./waf build``` must be replaced with ```./waf copter```.  
  If want to take [The easy way](#the-easy-way), you only need to install:
  - armhf toolchain
  - adb (android debug tool)


## How to use?

### The easy way:

1. Don't forget to add the required toolchain to the path:
    ```
    export PATH=/opt/arm-2016.02-linaro/bin:$PATH
    ```
2. Build ArduCopter (the `arducopter` binary will be created in `<local_ardupilot_repo>/build/bebop/bin/`):
    ```
    ./waf configure --board=bebop
    ./waf copter
    ```
3. Turn on the Bebop2 and connect to the Bebop2’s WiFi network.
4. Use the provided bash script to upload the binary automatically and follow the instructions:
    ```
    ./upload_script_bebop2
    ```
5. To control the Bebop2, you have to use a joystick:
    - You should configure your joystick according to the instruction on the [website](https://ardupilot.org/copter/docs/common-joystick.html) (only for MissionPlanner).
    - If you want to use QGroundControl instead of the MissionPlanner, you have to set the ArduCopter parameters ```RC1_MIN=1101``` and ```RC1_MAX=1901``` to make QGroundControl believe that the radio is calibrated.
    - If you want to switch to `mode 26` using QGroundControl (joysick button assignment), you can  
      - either exchanging the `mode_custom` (`mode 26`) with an ArduCopter standard flight mode (e.g. `mode_zigzag`).
        Therefore, exchange line 162 in `ArduCopter/mode.cpp` (```ret = &mode_zigzag;```) with line 47 (```ret = &mode_custom;```).
        Alternatively, you could modify the source code of QGroundControl so that it knows `mode_custom`.
      - or you can use [MAVProxy with the joystick module](../../data/MAVProxy_joystick).


### The default way + known problems

Just work through the instructions on the ArduPilot website.
As the instructions are quite old (2016), some problems might occur. Known problems:
- If you use the MissionPlanner for firmware upload, you may have to use version 1.3.41.
However, version 1.3.41 may not be able to connect with the Bebop 2 after firmware installation!
Newer versions and QGroundControl are able to connect though.
- You can skip the command ```adb mkdir ...``` as it may throw an error.
- There is not much space on the Bebop 2. A binary of about 2 MB is ok, 4 MB did not work (the exakt limit is extimated to be approx. 3.7 MB).
- If you cannot connect to the Bebop 2 after Firmware installation with MissionPlanner, try the manual method with the adb commands.
