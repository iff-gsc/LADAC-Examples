# Tailsitter Simulation and Control


## Example

- Start a simulation of the tailsitter Arkbird with attitude controller for hover (both tailsitter dynamics and controller run in MATLAB/Simulink):

  1. Open MATLAB/Simulink.
  2. Run the parameters file `init_Arkbird_INDI_simple` in MATLAB.
        ```
        cd workbenches/Arkbird
        init_Arkbird_INDI_simple
        ```
      Click `Change Folder` or `Add to Path`.  
  3. Plug in a remote control via USB. If you do not have connected a remote control, set: `jystck.enable = 0` (else an error will accur).  
  By default, the calibration settings of the Xbox-360 joystick are used as you can see in the init script `init_Arkbird_INDI_simple` in the line `jystck = joystickLoadParams( 'joystick_params_Xbox_360', 2, 0 );`.  
  This calibration settings may not be compatible with your joystick! Therefore, you should [test and calibrate your joystick](https://github.com/iff-gsc/ladac/tree/main/control/joystick).
  4. Run the Simulink file `TailsitterSimModel_INDI_simple.slx` (should open after step 2) to start the simulation.
    You can either control the system with the remote control (roll, pitch, yaw, throttle) or dummy inputs will be performed.
  5. You can view the system outputs in the block visualization clicking on the scopes. However, this is not visually intuitive.
  
- Visualize simulation with FlightGear:
  1. Run the start script of FlightGear by running `../../modules/ladac-examples-data/FlightGear/runfg_ViTOLmina.sh` (Linux; use .bat file for Windows):
        ```
        ./../../modules/ladac-examples-data/FlightGear/runfg_ViTOLmina.sh
        ```
  This will open FlightGear and load a tailsitter animation (for visualization only, the computation is carried out by MATLAB).
  
- Use the dynamics model of MATLAB/Simulink for software in the loop simulations of ArduPilot (controller runs in ArduPilot):
  
  **Hint:** If you want to restart a simulation, stop both simulations of step 3 and 4 and start them again.
  1. Initialize a new MATLAB/Simulink simulation with the tailsitter Arkbird and with the ArduPilot SITL interface:
        ```
        init_Arkbird_ArduPilot_SITL
        ```
  2. Run ArduPlane in Gazebo mode from terminal (sim_vehicle.py must be on the path or you find it in Tools/autotest/):
        ```
        sim_vehicle.py -v ArduPlane --add-param-file=<path-to-ladac-examples>/modules/ladac-examples-data/ArduPilot_params/20170919_0050-Arkbird-9_final_SITL.param --model=gazebo
        ```
		**Hint 1:** The option `--model=gazebo` tells ArduPilot to communicate with the physical model via a specific UDP communication.
		The Matlab/Simulink model is configured such that it uses this UDP communication as defined by ArduPilot.
		You do not need Gazebo.  
		**Hint 2:** You will receive the `no link` message until you proceed with step 3.  
        **Hint 3:** You can connect QGroundControl or MissionPlanner to control the tailsitter
		with a remote control or to create missions for GUIDED flight mode.
  3. Open the Simulink file `TailsitterSimModel_ArduPilot_SITL.slx` and click on run to 
        start the simulation **or** start the simulation from MATLAB command window: 
        ```
        sim('TailsitterSimModel_ArduPilot_SITL')
        ```
  4. (optional) Visualize simalation with FlightGear as explained above.  
        **Hint:** You may have to repeat from step 3 if initialization of the altitude fails (model will turn over).
        