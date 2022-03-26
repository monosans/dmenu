_pkgname=dmenu
pkgname=$_pkgname-monosans-git
pkgver=5.0.r577.d78ff08
pkgrel=1
pkgdesc='monosans dmenu build'
url=https://github.com/monosans/dmenu
arch=(i686 x86_64)
license=(MIT)
makedepends=(git)
depends=(sh libxinerama libxft)
optdepends=(
	'libxft-bgra: if dmenu crashes when viewing emojis'
	'libxft-bgra-git: if dmenu crashes when viewing emojis')
provides=($_pkgname)
conflicts=($_pkgname)
source=(git+https://github.com/monosans/dmenu)
sha256sums=('SKIP')

pkgver() {
	cd $_pkgname
	echo "$(awk '/^VERSION =/ {print $3}' config.mk)".r"$(git rev-list --count HEAD)"."$(git rev-parse --short HEAD)"
}

prepare() {
	cd $_pkgname
	echo "CPPFLAGS+=${CPPFLAGS}" >> config.mk
	echo "CFLAGS+=${CFLAGS}" >> config.mk
	echo "LDFLAGS+=${LDFLAGS}" >> config.mk
	# to use a custom config.h, place it in the package directory
	if [[ -f "$SRCDEST/config.h" ]]; then
		cp -fv "$SRCDEST/config.h" .
	fi
}

build(){
	cd $_pkgname
	make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
	cd $_pkgname
	make PREFIX=/usr DESTDIR="$pkgdir" install
	install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# vim:set ts=4 sw=4 noet:
