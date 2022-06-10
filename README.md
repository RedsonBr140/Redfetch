<h1 align="center"><code>Redfetch</code></h1>
<p align="center">A fast fetch written in C, with the ppfetch Ascii Art.</p>
<p align="center">
<img src="https://github.com/RedsonBr140/Redfetch/actions/workflows/pre-release.yml/badge.svg"> 
<!--<img src="https://img.shields.io/github/commits-since/RedsonBr140/Redfetch/latest/main"> -->
<img src="https://img.shields.io/github/license/RedsonBr140/Redfetch?style=flat">
</p>

<p align="center">
<a href="screenshot.png">
  <img src="screenshot.png">
</a>
</p>

## Dependencies
 - `wmctrl`
 - `A C compiler` (such as clang or gcc)
 - `make`
## Installation

Package Manager:
```bash
paru -S redfetch-git # Arch-based, with any AUR helper

### Gentoo-based ###
eselect repository enable gentoobr # Enable the overlay
emaint sync -r gentoobr # Download the overlay ebuilds
emerge --ask app-misc/Redfetch # Installing
```

Manually:
```
git clone https://github.com/RedsonBr140/redfetch.git
cd redfetch
make
sudo make install
```

## TODO
 - [X] Add a reset at the end of the colors blocks.
 - [X] Add to AUR.

## Thanks to
 - [Pedro Portales](https://github.com/pedroportales) - by creating [ppfetch](https://github.com/pedroportales/ppfetch) and his beautiful bat ascii art.
