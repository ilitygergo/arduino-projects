# Arduino project

This repository should be the GOTO, when starting a new project.
It helps setting up the basics for the hardware components.


### Soldering
https://www.youtube.com/watch?v=6rmErwU5E-k


### Atmega328 standalone

If you want to use only the chip, you'll need to:
* burn a bootloader beforehand (https://www.circuito.io/blog/atmega328p-bootloader/)
* add capacitors(22pF), oscillator(16MHz), resistor(10K), and  [diagrams/at-mega-328-standalone.png](https://github.com/ilitygergo/arduino-projects/blob/c748089001b662634f6602f3798ef04e50da4ce4/diagrams/at-mega-328-standalone.png)

### Workflow/Debugger
[PlatformIO IDE](https://platformio.org/install/ide?install=vscode)
