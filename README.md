# Tips

## Serial BAUD rate

- BAUD rate limit is related to MCU Freq (F_CPU)

- Configure BAUD rate in the platformio.ini only for devices with serial ports

```ini
build_flags = -D BAUD=19200
monitor_speed = 19200
```

- Reference: datasheet page 172 20.3.1 Internal Clock Generation

- <http://wormfood.net/avrbaudcalc.php>

## Fuses

- Never put your F_CPU bellow 2000UL (2kHz)! (This is the limit for avrdude)
- Never disable SPIEN fuse!
- Never enable RSTDISBL fuse!

If you do any of those things, you will have to do a High-Voltage Programming
to recover access to your MCU.

Use this site for fuses calculation: <https://www.engbedded.com/fusecalc/>

Adjust fuses values in the platformio.ini file.

## MCU Setup

Everything is disabled by default in the include/mcusetup/*.h files.

## Author

Vinícius Serafim <vinicius@serafim.eti.br>
