DESCRIPTION = "C++ bindings for dbus"
LICENSE = "LGPLv2.1+"
LIC_FILES_CHKSUM = "file://COPYING;md5=fbc093901857fcd118f065f900982c24"
SECTION = "libs"
SRCREV = "1f6f3e6e966e0b453edc4a82338dc27966c37505"

PE = "1"
PV = "0.9.0+gitr${SRCPV}"

SRC_URI = "git://git.baserock.org/delta/dbus-c++.git \
           file://add_missing_unistd_header.patch \
          "

S = "${WORKDIR}/git"

inherit autotools pkgconfig

EXTRA_OECONF_append = " --disable-ecore --enable-examples=no --enable-tests=no "
CXXFLAGS_append = " -fpermissive"

FILES_${PN}-dbg += "${bindir}/dbusxx-xml2cpp ${bindir}/dbusxx-introspect"
FILES_${PN}-dev += "${bindir}/.dev"
FILES_${PN} = "${libdir}/*.so.*"
