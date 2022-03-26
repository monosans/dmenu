# dmenu

[Suckless dmenu](https://tools.suckless.org/dmenu/) with some additional features.

## Features

- dmenu is centered in the middle of the screen.

## Installation on Arch Linux based distributions

### Download the source code

```bash
git clone https://github.com/monosans/dmenu.git
cd dmenu
```

### Configure

To use a custom `config.h`, place it in the package directory.

### Compile and install

To compile dmenu you need to install the `base-devel` package group if you haven't done it previously.

If you have `paru` installed:

```bash
paru -Ui
```

Otherwise:

```bash
makepkg -cirs
```

## Installation on other distributions

```bash
git clone https://github.com/monosans/dmenu.git
cd dmenu
sudo make clean install
```

## Note on emojis and special characters in status bar

If dmenu crashes when displaying emojis, install [libxft-bgra](https://aur.archlinux.org/packages/libxft-bgra) or [libxft-bgra-git](https://aur.archlinux.org/packages/libxft-bgra-git) from the AUR.

## Note for multi-monitor users

Xinerama is disabled in `config.mk` by default.

## Note for OpenBSD users

Be sure to edit `config.mk` by commenting 17th line `FREETYPEINC = /usr/include/freetype2` and uncommenting 19th line.

## Uninstallation on Arch Linux

`sudo pacman -Rns dmenu-monosans-git`

## Uninstallation on other distributions

```bash
git clone https://github.com/monosans/dmenu.git
cd dmenu
sudo make clean uninstall
```
