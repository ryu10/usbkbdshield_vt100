vt100_led_ctl:

This directory contains two files that control VT100 keyboard LED's:

1.led_all_on.txt ... contains the ESC sequence that turns on L1 - L4.
0.led_all_off.txt ... contains the ESC sequence that turns off L1 - L4.

To turn on/off the keyboard LED's, display the file contents on the VT100 session with the host machine.

Example:

% cat 1.led_all_on.txt
% cat 0.led_all_off.txt
