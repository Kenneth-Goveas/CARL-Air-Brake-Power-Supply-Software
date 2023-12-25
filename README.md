# CARL Air Brake Power Supply Software

This repository contains the software for the power supply module of the CARL
Air Brake computer. The CARL Air Brake computer (see [CARL Air Brake][cab-repo])
automatically controls a rocket air brake in flight, so that the vehicle attains
an apogee at the desired altitude. Its power supply module (see
[CARL Air Brake Power Supply Hardware][cab-psup-hw-repo]) distributes electrical
power to all systems in the computer.

## Description

A detailed description of the power supply module can be found in
[CARL Air Brake Power Supply Hardware][cab-psup-hw-repo]. As described there,
the software in this repository must be flashed onto the power supply module for
it to monitor the battery voltage and drive the indication LEDs.

## Prerequisites

The [Arduino IDE][ard-ide] is required for building and flashing the software.
Additionally, the following hardware is also needed.

- An Arduino Uno.
- An adjustable DC power supply unit.
- Six male to female jumper wires.
- Two multi stranded wires.
- A standard sized USB type B cable.
- A micro USB type B cable.

## Flashing

To properly configure, build, and flash the software for the power supply
module, carry out the following six steps.

### Configure Arduino IDE

Apply the following settings in the Arduino IDE. The same settings will be used
in all subsequent steps in the process.

- Set the target platform to *Arduino Uno* by clicking on *Tools > Board >
  Arduino AVR Boards > Arduino Uno*.
- Set the programmer to *Arduino as ISP* by clicking on *Tools > Programmer >
  Arduino as ISP*. This setting is not necessary if the power supply module
  already has the Arduino bootloader installed. If unsure, assume that the
  bootloader is not installed.

### Program Arduino Uno as ISP

Program the Arduino Uno to act as an ISP. This step is not necessary if the
power supply module already has the Arduino bootloader installed. If unsure,
assume that the bootloader is not installed.

- Open the *ArduinoISP* sketch by clicking on *File > Examples > ArduinoISP >
  ArduinoISP*.
- Connect the Arduino Uno to your computer with a USB cable. Do not connect any
  other circuitry to the Arduino Uno.
- Select the serial port connected to the Arduino Uno in *Tools > Port*.
- Upload the sketch.
- Disconnect the Arduino Uno from the computer.

### Install bootloader on power supply module

Using the Arduino Uno as an ISP, install the Arduino bootloader on the power
supply module. This step is not necessary if the power supply module already has
the Arduino bootloader installed. If unsure, assume that the bootloader is not
installed.

- Connect the ICSP port of the power supply module to the Arduino Uno by making
  the following connections with jumper wires.
  | **Arduino Uno** | **Power supply module** |
  | --------------- | ----------------------- |
  | 5V              | VCC                     |
  | GND             | GND                     |
  | 10              | RST                     |
  | 11              | MOSI                    |
  | 12              | MISO                    |
  | 13              | SCK                     |
- Connect the Arduino Uno to your computer with a USB cable.
- Select the serial port connected to the Arduino Uno in *Tools > Port*.
- Install the Arduino bootloader by clicking on *Tools > Burn bootloader*.
- Disconnect all devices from each other.

### Flash tuning app on power supply module

Flash the tuning app (contained in the [Tuning/App][tune-app-dir] directory) on
the power supply module.

- Connect the power supply module to your computer with a USB cable.
- Open the [Tuning/App/App.ino][tune-app-file] sketch in the Arduino IDE.
- Select the serial port connected to the power supply module in *Tools > Port*.
- Upload the sketch.
- Leave the power supply module connected to the computer.

### Configure voltage thresholds

Using the tuning app, configure battery voltage thresholds for the main app
(contained in the [Main/App][main-app-dir] directory). As described in
[CARL Air Brake Power Supply Hardware][cab-psup-hw-repo], the power supply
module has five LEDs to indicate battery voltage. After flashing the main app
(next step), the LEDs will light up in green when the battery is fully charged,
and turn red one by one as the voltage drops below the configured thresholds.

- Depending on the characteristics of the battery, choose five appropriate
  voltages *V1*, *V2*, *V3*, *V4*, and *V5* that indicate that the battery is at
  1/6, 2/6, 3/6, 4/6, and 5/6 of its full capacity respectively.
- Connect an adjustable DC source to the battery connector of the power supply
  module using multi stranded wire, and switch the power supply module on.
- Open the serial monitor in the Arduino IDE and set the baud rate to 115200.
- Adjust the DC source to the voltages *V1*, *V2*, *V3*, *V4*, and *V5* and note
  the corresponding readings shown on the serial monitor.
- Disconnect the DC source and switch off the power supply module. However,
  leave the power supply module connected to the computer over USB.
- Open the [Main/App/Configuration.h][main-app-conf-file] file and replace the
  default values in the `LEVEL_THRESHOLD` array with the values you noted.

### Flash main app on power supply module

Flash the main app on the power supply module.

- Open the [Main/App/App.ino][main-app-file] sketch in the Arduino IDE.
- Select the serial port connected to the power supply module in *Tools > Port*.
- Upload the sketch.
- Disconnect the power supply module from the computer.

## Documentation

The documentation for the source code can be generated with [Doxygen][dox].
Installation instructions can be found on the [Download][dox-dl] page. For each
app, run the following command from the respective app directory
([Tuning][tune-dir] for the tuning app, and [Main][main-dir] for the main app)
to generate the documentation for that app.

```
doxygen
```

This will create a directory named *Doc* and place the HTML documentation in it.

[tune-dir]:           ./Tuning
[tune-app-dir]:       ./Tuning/App
[tune-app-file]:      ./Tuning/App/App.ino
[main-dir]:           ./Main
[main-app-dir]:       ./Main/App
[main-app-file]:      ./Main/App/App.ino
[main-app-conf-file]: ./Main/App/Configuration.h

[cab-repo]:           https://github.com/Kenneth-Goveas/CARL-Air-Brake
[cab-psup-hw-repo]:   https://github.com/Kenneth-Goveas/CARL-Air-Brake-Power-Supply-Hardware

[ard-ide]:            https://www.arduino.cc/en/software

[dox]:                https://www.doxygen.nl
[dox-dl]:             https://www.doxygen.nl/download.html
