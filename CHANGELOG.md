# Changelog

All notable changes to HPL2-X / Amnesia will be documented in this file.


### Engine (HPL2)
#### Added
- Live window resizing and renderer reloading for resolution changes
- Hardware cursor instead of software
- Broadcast focus change while waiting for input focus
- Scale popup message boxes with the screen size so confirmations aren't tiny on widescreen

#### Changed
- Retargeted Visual Studio solution to v143 toolset (VS 2022)

#### Removed

---

### The Dark Descent
#### Added
- "Press any key" prompt to skip pre-menu splash screens.
- Live window resizing and renderer reloading for resolution changes
- Simulation Rate option (60/120/144/240 Hz)
- Uncap FPS option to render as fast as possible instead of locking to the simulation rate
- "Pause game on focus loss" option to keep the game running when the window is unfocused
- Hardware cursor instead of software
- Anti-Aliasing (MSAA) option in graphics settings (Off/2x/4x/8x)
- Scale menu popup windows with screen height so they stay proportional on widescreen

#### Changed
- Fix UI stretching on ultrawide by scaling by aspect ratio instead of difference

#### Removed