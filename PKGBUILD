_pkgname=dmenu
pkgname=${_pkgname}-monosans-git
pkgver=5.2.r115.690436e
pkgrel=1
pkgdesc='monosans dmenu build'
url=https://github.com/monosans/dmenu
arch=(any)
license=(MIT)
makedepends=(git)
depends=(sh libxinerama libxft)
provides=("${_pkgname}")
conflicts=("${_pkgname}")
source=("${pkgname}::git+${url}.git")
sha256sums=('SKIP')

pkgver() {
	cd "${pkgname}"
	echo "$(awk '/^VERSION =/ {print $3}' config.mk).r$(git rev-list --count HEAD).$(git rev-parse --short HEAD)"
}

prepare() {
	cd "${pkgname}"
	{
		echo "CPPFLAGS+=${CPPFLAGS}"
		echo "CFLAGS+=${CFLAGS}"
		echo "LDFLAGS+=${LDFLAGS}"
	} >>config.mk
}

build() {
	cd "${pkgname}"
	make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
	cd "${pkgname}"
	make PREFIX=/usr DESTDIR="${pkgdir}" install
	install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
