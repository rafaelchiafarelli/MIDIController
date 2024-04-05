This is not a Midi device, but a MIDI interpreter.

MIDI is a standard protocol used in musical instruments to turn sound notes into 3 digital values. 

This software interprets the midi notes sent by the device, and turns this into a set of keystrokes.

For instance, we have the note 144, 2, 127 (this represent some key at the keyboard pressed). The MidiControllerApp will grab this value and turn it into the keystroke Win_Key + D (witch is the shortcut to show the desktop in windows 11)

Implicit Features:
a small language to turn strings into keyboard shortcuts
several modes

Features:
Midi send back to the device
    midi_normal - just echo back the midi signal
    midi_trigger_higher - when the third byte reaches a certain high level, it triggers a mode change
    midi_trigger_lower - when the third byte reaches a certain low level, it triggers a mode change
    midi_spot - when a certain midi code comes in, it triggers a imediate "on" and "off" (tipical signals are the last byte as 127 for on and 0 for "off")
    midi_blink - it will start a blink or stop a blink. Blink is for every 1 second.
Keystrokes arre sent to the computer
    This is windows only, for now.
      oneKey - send a one key to the computer, something like, send the letter "a" or send the key "ctrl".
          hold - will hold the key "forever". Basically, in windows, we can send the key pressed event and never the key release event
          not_hold - send the key send and the key release
          hold_delay - will hold the key for some time and than release it.
      hotkey - this will send a "hot-key" or "shortcut", however it is limited to 4 keystrokes
      text - will send a set of letters, it is not yet limited, but this is a bug. It will be limited to a high number, such as 65k letters.
MouseEvents -- not yet implemented
    mouse events are tricky because most users will keep their hands on the mouse during operations. But features will be
  move_to - will move to a absolute position on the screen
  left_click - will click the left mouse button
  right_click - will click the right_mouse button
  middle_click - will click the midle button (or wheel button)
  wheel_forward - will simulate the wheel forward motion
  wheel_backward - will simulate the wheel backward motion
