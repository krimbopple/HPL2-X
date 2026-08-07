# HPL2-X

HPL2-X aims to be a modernized fork of HPL2, based on [Amnesia64](https://github.com/buzer2020/Amnesia64).
The goal of this project is to bring the classic HPL2 engine closer to the features, stability, and overall polish of HPL3, while keeping the engine open, accessible, and beginner-friendly.

## Amnesia64 Key changes:
- Can be compiled in both 32-bit and 64-bit modes using VS2019 with latest build tools.
- Single solution file for all projects (main game, HPL2, dependencies and editors). No need to compile the engine separately.
- Produces self-contained .exe files without dependency on 3rd party dlls (this prevents cluttering user's game folder with 64-bit dlls).
- Some libraries were changed, most notably:
	- SDL2 was upgraded from 2.0.4 to 2.0.12
	- alut was replaced with freealut
	- Newton Dynamics was upgraded from 2.08 to 2.32 (I simply couldn't find the source code for 2.08)
	- Fbx support is temporarily removed (I'm planning to re-implement it using OpenFBX)
