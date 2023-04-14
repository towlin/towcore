# tow

Olin winch club  
Dac resource:
https://jakemakes.eu/arduino-digital-to-analog-converter-gy4725-mcp4725-tutorial/

# Sensorless Odrive setup

https://docs.odriverobotics.com/v/latest/getting-started.html

Install odrivetool and connect to the motor. We ran these tests with only 1 4s
5000mah lipo connected. Run the following commands to setup the config:

```
odrv = odrv0
odrv.config.dc_bus_overvoltage_trip_level = 17
odrv.config.dc_max_positive_current = 10
odrv.config.dc_max_negative_current = -10
odrv.axis0.config.motor.motor_type = MotorType.HIGH_CURRENT
odrv.axis0.config.motor.torque_constant = 0.043526315789473684
odrv.axis0.config.motor.pole_pairs = 7
odrv.axis0.config.motor.current_soft_max = 10
odrv.axis0.config.motor.current_hard_max = 28
odrv.axis0.config.motor.calibration_current = 10
odrv.axis0.config.motor.resistance_calib_max_voltage = 2
odrv.axis0.config.torque_soft_min = -8
odrv.axis0.config.torque_soft_max = 8
odrv.axis0.config.calibration_lockin.current = 10
odrv.axis0.controller.config.control_mode = ControlMode.VELOCITY_CONTROL
odrv.axis0.controller.config.input_mode = InputMode.VEL_RAMP
odrv.axis0.controller.config.vel_ramp_rate = 1
odrv.axis0.controller.config.vel_limit = 10
odrv.axis0.controller.config.vel_limit_tolerance = 1.2
odrv.axis0.config.load_encoder = EncoderId.SENSORLESS_ESTIMATOR
odrv.axis0.config.commutation_encoder = EncoderId.SENSORLESS_ESTIMATOR
```

To run the motor run this command:

```
odrv.axis0.requested_state = AxisState.CLOSED_LOOP_CONTROL

```
