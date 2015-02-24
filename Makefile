#############################################################################
# Makefile for building: Lab2_client
# Generated by qmake (2.01a) (Qt 4.8.5) on: ?? 24. ??? 18:17:53 2015
# Project:  Lab2_client.pro
# Template: app
# Command: h:/Qt4.8.5/bin/qmake.exe -spec ../../../mkspecs/win32-g++ -o Makefile Lab2_client.pro
#############################################################################

first: debug
install: debug-install
uninstall: debug-uninstall
MAKEFILE      = Makefile
QMAKE         = h:/Qt4.8.5/bin/qmake.exe
DEL_FILE      = rm
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp
COPY_FILE     = $(COPY)
COPY_DIR      = cp -r
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = mv
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
SUBTARGETS    =  \
		debug \
		release

debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: Lab2_client.pro  ../../../mkspecs/win32-g++/qmake.conf ../../../mkspecs/features/device_config.prf \
		../../../mkspecs/qconfig.pri \
		../../../mkspecs/modules/qt_webkit_version.pri \
		../../../mkspecs/features/qt_functions.prf \
		../../../mkspecs/features/qt_config.prf \
		../../../mkspecs/features/exclusive_builds.prf \
		../../../mkspecs/features/default_pre.prf \
		../../../mkspecs/features/win32/default_pre.prf \
		../../../mkspecs/features/debug.prf \
		../../../mkspecs/features/debug_and_release.prf \
		../../../mkspecs/features/default_post.prf \
		../../../mkspecs/features/win32/default_post.prf \
		../../../mkspecs/features/win32/rtti.prf \
		../../../mkspecs/features/win32/exceptions.prf \
		../../../mkspecs/features/win32/stl.prf \
		../../../mkspecs/features/shared.prf \
		../../../mkspecs/features/warn_on.prf \
		../../../mkspecs/features/qt.prf \
		../../../mkspecs/features/win32/thread.prf \
		../../../mkspecs/features/moc.prf \
		../../../mkspecs/features/win32/windows.prf \
		../../../mkspecs/features/resources.prf \
		../../../mkspecs/features/uic.prf \
		../../../mkspecs/features/yacc.prf \
		../../../mkspecs/features/lex.prf \
		../../../mkspecs/features/include_source_dir.prf \
		h:/Qt4.8.5/lib/qtmaind.prl
	$(QMAKE) -spec ../../../mkspecs/win32-g++ -o Makefile Lab2_client.pro
../../../mkspecs/features/device_config.prf:
../../../mkspecs/qconfig.pri:
../../../mkspecs/modules/qt_webkit_version.pri:
../../../mkspecs/features/qt_functions.prf:
../../../mkspecs/features/qt_config.prf:
../../../mkspecs/features/exclusive_builds.prf:
../../../mkspecs/features/default_pre.prf:
../../../mkspecs/features/win32/default_pre.prf:
../../../mkspecs/features/debug.prf:
../../../mkspecs/features/debug_and_release.prf:
../../../mkspecs/features/default_post.prf:
../../../mkspecs/features/win32/default_post.prf:
../../../mkspecs/features/win32/rtti.prf:
../../../mkspecs/features/win32/exceptions.prf:
../../../mkspecs/features/win32/stl.prf:
../../../mkspecs/features/shared.prf:
../../../mkspecs/features/warn_on.prf:
../../../mkspecs/features/qt.prf:
../../../mkspecs/features/win32/thread.prf:
../../../mkspecs/features/moc.prf:
../../../mkspecs/features/win32/windows.prf:
../../../mkspecs/features/resources.prf:
../../../mkspecs/features/uic.prf:
../../../mkspecs/features/yacc.prf:
../../../mkspecs/features/lex.prf:
../../../mkspecs/features/include_source_dir.prf:
h:\Qt4.8.5\lib\qtmaind.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -spec ../../../mkspecs/win32-g++ -o Makefile Lab2_client.pro

qmake_all: FORCE

make_default: debug-make_default release-make_default FORCE
make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile

check: first

debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
