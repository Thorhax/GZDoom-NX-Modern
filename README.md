# GZDoom-NX-Modern
**GZDoom v4.14.2 for Nintendo Switch** with full ZScript, modern mod support (*Brutal Doom*, *Doom 64: Unseen Evil*, *Project Brutality*), custom hardware shaders, and integrated pre-launch GUI.

---

## 🌟 Features

- **Modern GZDoom Engine:** Based on GZDoom 4.14.2 with modern ZScript VM, DECORATE, and MAPINFO parser.
- **Hardware Acceleration:** OpenGL 3.3 Core Profile renderer powered by Mesa Nouveau on the Tegra X1 GPU.
- **Dynamic Custom Hardware Shaders:** Support for GLDEFS user shaders (`playercolor.fp`, sprite paletting, brightmaps, custom effects).
- **Comprehensive Audio Codecs:** Integrated **ZMusic 1.3.0** with static support for FLAC, OGG/Vorbis, MP3 (mpg123), Opus, Timidity++ MIDI (`gzdoom.sf2`), and FluidSynth.
- **Full Controller Support:** Native Joy-Con / Pro Controller analog stick navigation, deadzones, and configurable bindings.
- **nxlauncher GUI:** Built-in graphical pre-launch menu to select IWADs, enable/disable custom PWADs and mods, and configure resolution before launching the engine.

---

## 🎮 Controls (Default Gamepad Scheme)

| Button | Action |
| :--- | :--- |
| **ZR** | Primary Fire |
| **ZL** | Secondary Fire / Aim Down Sights |
| **L / R** | Previous / Next Weapon |
| **A** | Use / Open / Interact |
| **B** | Jump |
| **X** | Reload / Weapon Action |
| **Y** | Kick / Melee Attack |
| **Left Stick Click (L3)** | Crouch |
| **Right Stick Click (R3)** | Flashlight / Special Action |
| **D-Pad** | Weapon Slot Navigation |
| **+ (Plus)** | Main Menu / Pause |
| **- (Minus)** | Automap |

---

## 📦 Installation

1. Download the latest release package from the [Releases](https://github.com/Thorhax/GZDoom-NX-Modern/releases) tab.
2. Extract the contents directly to the root of your Switch SD card so that files are placed in:
   ```text
   sdmc:/switch/gzdoom/
   ```
3. Place your IWAD files (e.g. `doom.wad`, `doom2.wad`, `tnt.wad`, `plutonia.wad`, `heretic.wad`, `hexen.wad`) into:
   ```text
   sdmc:/switch/gzdoom/iwads/
   ```
4. Place any custom mods or PWADs (e.g. `brutalv22.pk3`, `D64UnseenEvil.pk3`) into:
   ```text
   sdmc:/switch/gzdoom/pwads/
   ```
5. Launch **GZDoom Launcher** from the Homebrew Menu.

---

## 🛠️ Building from Source

The build uses the official `devkitpro/devkita64` Docker container.

### Prerequisites
- Docker

### Compilation Steps
```bash
# 1. Clone repository
git clone --recursive https://github.com/Thorhax/GZDoom-NX-Modern.git
cd GZDoom-NX-Modern

# 2. Build using devkitA64 Docker container
docker run --rm \
  -v $(pwd):/gzdoom \
  -w /gzdoom/build \
  devkitpro/devkita64:latest \
  bash -c "
    export PATH=/opt/devkitpro/devkitA64/bin:/opt/devkitpro/tools/bin:\$PATH
    cmake -DCMAKE_TOOLCHAIN_FILE=/opt/devkitpro/cmake/Switch.cmake \
          -DNINTENDO_SWITCH=ON \
          -DCMAKE_BUILD_TYPE=Release ..
    cmake --build . -j\$(nproc)
  "
```

The output `gzdoom.nro`, `gzdoom.pk3`, and launcher will be created in `build/`.

---

## 📜 Credits & License

- **GZDoom Team & Contributors:** [ZDoom / GZDoom](https://github.com/ZDoom/gzdoom)
- **Original Switch Port & nxlauncher:** [fgsfds](https://github.com/fgsfdsfgs/gzdoom)
- **ZMusic:** Christoph Oelckers & GZDoom contributors
- **devkitPro:** devkitA64 toolchain and switch-portlibs

Licensed under the **GNU General Public License v3.0 (GPLv3)**.
