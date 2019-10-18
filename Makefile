#############################################################################
# Makefile for building: materialManagement
# Generated by qmake (3.1) (Qt 5.8.0)
# Project:  uidemo01.pro
# Template: app
# Command: D:\programInstall\QT580\5.8\msvc2015_64\bin\qmake.exe -o Makefile uidemo01.pro -spec win32-msvc2015 "CONFIG+=debug" "CONFIG+=qml_debug"
#############################################################################

MAKEFILE      = Makefile

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = D:\programInstall\QT580\5.8\msvc2015_64\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: uidemo01.pro ..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\win32-msvc2015\qmake.conf ..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\spec_pre.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\common\angle.conf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\common\msvc-base.conf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\common\msvc-desktop.conf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\qconfig.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dcore.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dcore_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dextras.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dextras_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dinput.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dinput_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dlogic.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dlogic_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquick.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquick_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquickextras.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquickextras_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquickinput.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquickinput_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquickrender.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquickrender_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3drender.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3drender_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_accessibility_support_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_axbase.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_axbase_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_axcontainer.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_axcontainer_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_axserver.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_axserver_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_bluetooth.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_bluetooth_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_bootstrap_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_charts.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_charts_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_clucene_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_concurrent.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_concurrent_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_core.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_core_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_datavisualization.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_datavisualization_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_dbus.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_dbus_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_designer.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_designer_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_designercomponents_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_devicediscovery_support_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_egl_support_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_eventdispatcher_support_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_fb_support_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_fontdatabase_support_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_gamepad.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_gamepad_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_gui.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_gui_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_help.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_help_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_location.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_location_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_multimedia.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_multimedia_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_multimediawidgets.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_multimediawidgets_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_network.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_network_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_networkauth.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_networkauth_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_nfc.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_nfc_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_opengl.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_opengl_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_openglextensions.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_openglextensions_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_packetprotocol_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_platformcompositor_support_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_positioning.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_positioning_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_printsupport.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_printsupport_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_purchasing.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_purchasing_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_qml.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_qml_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_qmldebug_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_qmldevtools_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_qmltest.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_qmltest_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quick.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quick_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quickcontrols2.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quickcontrols2_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quickparticles_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quicktemplates2_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quickwidgets.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quickwidgets_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_script.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_script_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_scripttools.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_scripttools_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_scxml.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_scxml_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_sensors.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_sensors_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_serialbus.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_serialbus_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_serialport.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_serialport_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_sql.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_sql_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_svg.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_svg_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_testlib.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_testlib_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_texttospeech.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_texttospeech_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_theme_support_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_uiplugin.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_uitools.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_uitools_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webchannel.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webchannel_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webengine.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webengine_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webenginecore.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webenginecore_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webenginewidgets.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webenginewidgets_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_websockets.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_websockets_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webview.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webview_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_widgets.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_widgets_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_winextras.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_winextras_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_xml.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_xml_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_xmlpatterns.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_xmlpatterns_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_zlib_private.pri \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\qt_functions.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\qt_config.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\win32-msvc2015\qmake.conf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\spec_post.prf \
		..\.qmake.stash \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\exclusive_builds.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\toolchain.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\default_pre.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\win32\default_pre.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\resolve_config.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\exclusive_builds_post.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\default_post.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\warn_off.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\qt.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\resources.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\moc.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\win32\opengl.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\uic.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\qml_debug.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\win32\rtti.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\precompile_header.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\qmake_use.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\file_copies.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\win32\windows.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\testcase_targets.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\exceptions.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\yacc.prf \
		..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\lex.prf \
		uidemo01.pro \
		..\..\programInstall\QT580\5.8\msvc2015_64\lib\qtmaind.prl \
		..\..\programInstall\QT580\5.8\msvc2015_64\lib\Qt5Widgets.prl \
		..\..\programInstall\QT580\5.8\msvc2015_64\lib\Qt5Gui.prl \
		..\..\programInstall\QT580\5.8\msvc2015_64\lib\Qt5Sql.prl \
		..\..\programInstall\QT580\5.8\msvc2015_64\lib\Qt5Core.prl
	$(QMAKE) -o Makefile uidemo01.pro -spec win32-msvc2015 "CONFIG+=debug" "CONFIG+=qml_debug"
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\spec_pre.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\common\angle.conf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\common\msvc-base.conf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\common\msvc-desktop.conf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\qconfig.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dcore.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dcore_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dextras.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dextras_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dinput.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dinput_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dlogic.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dlogic_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquick.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquick_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquickextras.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquickextras_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquickinput.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquickinput_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquickrender.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3dquickrender_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3drender.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_3drender_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_accessibility_support_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_axbase.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_axbase_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_axcontainer.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_axcontainer_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_axserver.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_axserver_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_bluetooth.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_bluetooth_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_bootstrap_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_charts.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_charts_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_clucene_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_concurrent.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_concurrent_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_core.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_core_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_datavisualization.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_datavisualization_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_dbus.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_dbus_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_designer.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_designer_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_designercomponents_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_devicediscovery_support_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_egl_support_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_eventdispatcher_support_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_fb_support_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_fontdatabase_support_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_gamepad.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_gamepad_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_gui.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_gui_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_help.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_help_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_location.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_location_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_multimedia.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_multimedia_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_multimediawidgets.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_multimediawidgets_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_network.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_network_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_networkauth.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_networkauth_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_nfc.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_nfc_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_opengl.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_opengl_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_openglextensions.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_openglextensions_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_packetprotocol_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_platformcompositor_support_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_positioning.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_positioning_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_printsupport.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_printsupport_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_purchasing.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_purchasing_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_qml.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_qml_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_qmldebug_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_qmldevtools_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_qmltest.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_qmltest_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quick.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quick_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quickcontrols2.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quickcontrols2_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quickparticles_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quicktemplates2_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quickwidgets.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_quickwidgets_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_script.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_script_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_scripttools.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_scripttools_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_scxml.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_scxml_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_sensors.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_sensors_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_serialbus.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_serialbus_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_serialport.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_serialport_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_sql.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_sql_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_svg.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_svg_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_testlib.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_testlib_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_texttospeech.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_texttospeech_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_theme_support_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_uiplugin.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_uitools.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_uitools_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webchannel.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webchannel_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webengine.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webengine_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webenginecore.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webenginecore_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webenginewidgets.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webenginewidgets_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_websockets.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_websockets_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webview.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_webview_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_widgets.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_widgets_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_winextras.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_winextras_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_xml.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_xml_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_xmlpatterns.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_xmlpatterns_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\modules\qt_lib_zlib_private.pri:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\qt_functions.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\qt_config.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\win32-msvc2015\qmake.conf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\spec_post.prf:
..\.qmake.stash:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\exclusive_builds.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\toolchain.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\default_pre.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\win32\default_pre.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\resolve_config.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\exclusive_builds_post.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\default_post.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\warn_off.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\qt.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\resources.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\moc.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\win32\opengl.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\uic.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\qml_debug.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\win32\rtti.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\precompile_header.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\qmake_use.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\file_copies.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\win32\windows.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\testcase_targets.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\exceptions.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\yacc.prf:
..\..\programInstall\QT580\5.8\msvc2015_64\mkspecs\features\lex.prf:
uidemo01.pro:
..\..\programInstall\QT580\5.8\msvc2015_64\lib\qtmaind.prl:
..\..\programInstall\QT580\5.8\msvc2015_64\lib\Qt5Widgets.prl:
..\..\programInstall\QT580\5.8\msvc2015_64\lib\Qt5Gui.prl:
..\..\programInstall\QT580\5.8\msvc2015_64\lib\Qt5Sql.prl:
..\..\programInstall\QT580\5.8\msvc2015_64\lib\Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile uidemo01.pro -spec win32-msvc2015 "CONFIG+=debug" "CONFIG+=qml_debug"

qmake_all: FORCE

make_first: debug-make_first release-make_first  FORCE
all: debug-all release-all  FORCE
clean: debug-clean release-clean  FORCE
	-$(DEL_FILE) materialManagement.exp
	-$(DEL_FILE) materialManagement.vc.pdb
	-$(DEL_FILE) materialManagement.ilk
	-$(DEL_FILE) materialManagement.idb
distclean: debug-distclean release-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) materialManagement.lib materialManagement.pdb

debug-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
