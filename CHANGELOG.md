# Changelog

All notable changes to HPL2-X / Amnesia will be documented in this file.


### Engine (HPL2)
#### Added
- HDR rendering & Tone mapping post effects
- PCF Soft Shadow support, as an alternative to the existing hard jagged ones
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
- HDR and Tone Mapping options in graphics settings (off by default, may alter the game's look)
- PCF Soft Shadows option in graphics settings (off by default, may alter the game's look)
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

---

### Deploying the new shaders
The HDR / tone mapping / PCF soft shadow features ship with two shader files in this repo
under `core/shaders/`:
- `posteffect_tonemap_frag.glsl` (new)
- `deferred_light_frag.glsl` (modified, adds PCF soft shadow path)

The engine loads shaders from the game's working directory (`core/shaders`), so these are not
loaded from the repo directly. After building, copy both files into your game install's
`core/shaders\` folder (overwriting `deferred_light_frag.glsl`) alongside `Lux.exe`.
