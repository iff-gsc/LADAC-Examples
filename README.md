# Examples for the Library for Aircraft Dynamics And Control (LADAC)

This repository contains multiple examples to demonstrate the usage of LADAC.
There are multicopter, airplane and eVTOL flight dynamic models as well as flight controllers for the specific vehicles.
The flight dynamic models and the flight controllers are based on LADAC and written in MATLAB/Simulink.
Moreover, there are interfaces to external programs like FlightGear (for visualization) and ArduPilot (for software in the loop tests and flight tests).


## Motivation

It is sometimes not clear how to get new aircraft configurations to fly with existing software such as ArduPilot or PX4.
With such software, you usually have no insight into the dynamics of the open and closed loop of the aircraft and are limited to an empirical controller design through flight tests or simulations. 
This project provides the opportunity to design controllers specifically in MATLAB/Simulink.
First, you can quickly parameterize existing aircraft models or easily create new aircraft models based on LADAC building blocks.
Then you can analyze the dynamics of the aircraft and design controllers.
Then it is possible to translate the created controller into C/C++ code (code generation) and implement it in software like ArduPilot. 
Finally, you can test your software in a software-in-the-loop simulation before running your code on a Pixhawk for flight testing.


## Installation

- **MATLAB:**  
  1. You need MATLAB/Simulink 2018b or later (older versions may work but they are not supported).
  2. You may also need some MATLAB toolboxes like Curve Fitting Toolbox, 
	   Aerospace Blockset, Aerospace Toolbox, MATLAB Coder, MATLAB Compiler, 
	   Simulink Control Design, Simulink Coder depending on what you want to do.

- **Remote control:**  
  You can use a remote control via USB if you have one.

- **FlightGear:** 
  1. You also should install FlightGear for visualization. Tested versions are FlightGear 3.4.0 and FlightGear 2019.1.1.
  2. On Windows you have to copy and paste the folder FlightGear/<models> into $FG_HOME/Aircraft/

- **ArduPilot SITL:**  
  You might install [ArduPilot SITL](https://ardupilot.org/dev/docs/sitl-simulator-software-in-the-loop.html) if you want to do software in the loop simulations.

- **Ground control station:**  
  You might install a ground control station like QGroundControl or MissionPlanner
	   for communication with ArduPilot SITL.

- **LADAC-Examples:**  
  Clone this project including the submodules LADAC and LADAC-Example-Data:
  ```
  git clone --recursive https://github.com/iff-gsc/ladac-examples.git
  ```


## Examples

- Start a simulation of quadcopter Bebop2 with loiter controller (both quadcopter dynamics and controller run in MATLAB/Simulink):  
  1. Open MATLAB/Simulink.
  2. Run the parameters file `workbenches/Bebop2/init_quadcopter_Bebop2_Loiter_INDI_simple`.
      ```
      cd('workbenches/Bebop2')
      init_quadcopter_Bebop2_Loiter_INDI_simple
      ```
  3. Plug in a remote control via USB. If you do not have connected a remote control, set: `jystck.enable = 0` (else an error will accur).  
  By default, the calibration settings of the Xbox-360 joystick are used as you can see in the init script `init_quadcopter_Bebop2_Loiter_INDI_simple` in the line `jystck = joystickLoadParams( 'joystick_params_Xbox_360', 2, 0 );`.  
  This calibration settings may not be compatible with your joystick! Therefore, you should [test and calibrate your joystick](https://github.com/iff-gsc/ladac/tree/main/control/joystick).
  4. Run the Simulink file `QuadcopterSimModel_INDI_Loiter_simple.slx` (should open after step 2) to start the simulation. You can either control the system with the remote
        control (vertical velocity, yaw rate, pitch angle, roll angle) or dummy
	   inputs will be performed. 
      ```
      sim('QuadcopterSimModel_INDI_Loiter_simple')
      ```
  5. You can view the system outputs in the block visualization clicking on the scopes. 
	   However, this is not visually intuitive.

- Visualize simulation with FlightGear:  
  1. Run the start script of FlightGear by running runfg_IRIS.bat (Windows) or runfg_IRIS.sh (Linux):
        ```
        ./FlightGear/runfg_IRIS.sh
        ```
        This will open FlightGear and load an IRIS quadcopter animation (for visualization 
        only, the computation is carried out by MATLAB).

- Use the dynamics model of MATLAB/Simulink for software in the loop simulation of ArduPilot (controller runs in ArduPilot):  
  1. Run a new MATLAB/Simulink simulation with Bebop2 quadcopter with the ArduPilot SITL interface:
      ```
      cd('workbenches/Bebop2')
      init_quadcopter_Bebop2_ArduPilot_SITL
      sim('QuadcopterSimModel_ArduCopter_SITL')
      ```
  2. Run ArduPilot SITL in Gazebo mode from terminal (sim_vehicle.py must be on the path or you find it in Tools/autotest/).
	 You also have to specify the ArduPilot parameters file of the Bebop2 with the `add-param-file` parameter: 
        ```
		sim_vehicle.py -v ArduCopter --model=gazebo --add-param-file=<path-to-multicopter>/libraries/ladac-examples-data/ArduPilot_Frame_params/Parrot_Bebop2_MATLAB_SITL.param
        ```
  3. Control the quadcopter from ArduPilot. Therefore, you should use
	   a ground control station (read QGroundControl or MissionPlanner documentation) or the
	   [MAVProxy command prompt](https://ardupilot.org/dev/docs/copter-sitl-mavproxy-tutorial.html#copter-sitl-mavproxy-tutorial). 



## How to use?

### General use of the MATLAB/Simulink files
There are initialization m-files in multiple workbenches subfolders (e.g. `workbenches/Bebop2/init_...`) to initialize the parameters of
the physical model as well as of the controller. There are simulation
slx-file (e.g. `models/QuadcoterSimModel_...`) for different kinds of vehicles
and different types of controllers.

### General use of ArduPilot SITL
Standard ArduPilot flight modes will only work if you load appropriate parameters for you vehicle.
The default parameters (e.g. `-f gazebo-iris`) only work for similar quadcopters (e.g. IRIS quadcopter).
For other vehicles you have to load different parameters using the `--add-param-file option`.
For some vehicles you find the parameters in `<path-to-ardupilot>/Tools/Frame_params/`.

- **IRIS:**  
You can load the ArduPilot IRIS parameters with the `-f` parameter: `sim_vehicle.py -v ArduCopter -f gazebo-iris --model=gazebo`

- **Muetze:**  
Muetze is very similar to IRIS. That is why ArduCopter works with `-f gazebo-iris` option.

### Use of LADAC

Please have a look at the LADAC README.
	
### Design Incremental Nonlinear Dynamic Inversion (INDI) controllers:
There are control design tools in the `tools/` subfolder.
There are multiple controllers and flightmodes available in the subfolder `libraries/ladac/control/flight_modes` - take a look at them!
You can adjust/design the parameters of an existing controller as follows.
If you want to add a new controller, you have to create and add a Simulink block to the library.
1. Create a physical model as described in the section [General use of the MATLAB/Simulink files](#general-use-of-the-matlab) (take a look at the `copterLoadParams` function and create a parameters file based on the `copter_params_default` template). Therefore, you should create a new subfolder in the `workbenches` subfolder.
2. Initialize the physical model so that you have a `copter` struct in your MATLAB workspace.
3. The goal is to create a flight mode parameters file based on the available flight modes (attitude, altitude hold, loiter). E.g. for the loiter flight mode, take a look at the `fmCopterLoiterIndiLoadParams` function and the `fm_copter_loiter_indi_params_default` template.
These parameter files contain additional parameter files to initialize the reference model parameters, the control allocation parameters etc. 
Make copies of these template (default) files and replace the parameters in the next steps.
There are different types of parameters:
	- **reference models (rm):** define these parameters directly based on your requirements!  
	- **control allocation (ca):** define these parameters directly based on your requirements!  
	- **sensor filter (sens_filt):** defaults are recommended.
	- **motor time constant:** insert the motor time constants (usually `copter.motor.R*copter.prop.I/copter.motor.KT^2` is a good guess).
	- **control effectiveness:** see step 4.
	- **controller gains (K):** see step 5.  
The reference model parameters and the control allocation parameters must be replaced based on the requirements!
4. Call the function `indiCopterCntrlEffect`. You will get the control effectiveness of the multicoter. 
Copy and paste the optained control effectiveness variables to your controller parameters file.
5. Call the function `indiCntrlGainAltHold` to compute the feedback gain of the inner loop controller (attitude control with altitude hold - can also be used for attitude control).
Therefore, you can use the `indi_cntrl_gain_alt_hold_example` script in the first place. 
You may want to adjust the weighting parameters according to the instructions in the script.
Make a copy of the example script and paste it to your workbenches subfolder.
Rename it and make your adjustments.
You can use a similar procedure if you want to design the feedback gain for the horizontal position control loop (take a look at the script `indi_cntrl_gain_loiter_cascaded_example`).
6. You can now finalize your initialization script in your workbenches subfolder like `init_quadcopter_Bebop2_Loiter_INDI_simple`.
After adjusting and running the initialization script, you should be able to run the corresponding Simulink model located in the `models/` subfolder like `QuadcopterSimModel_INDI_Loiter_simple`.
If the controller does not perform as expected, check if you followed all of the above steps carefully. Moreover, you could check again all your controller parameters.
Otherwise you should report a bug.

### Implement controllers in ArduPilot:  
You can implement you controllers in ArduPilot to quickly proceed to flight tests, see [ArduPilot Custom Controller](https://github.com/iff-gsc/ladac/tree/main/utilities/interfaces_external_programs/ArduPilot_custom_controller).


## Contribute

### Fix or report bugs

Before reporting a bug, please try the following:
- check `git status`  
- restart MATLAB/Simulink

Create an issue and provide the following information:
- error message or discription of the problem
- steps of how to reproduce the error/problem
- utilized commit SHA-1 hash (e.g. 7d2e1a6c)

