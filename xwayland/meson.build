lib_wlr_xwayland = static_library(
	'wlr_xwayland',
	files(
		'selection.c',
		'sockets.c',
		'xwayland.c',
		'xwm.c',
	),
	include_directories: wlr_inc,
	dependencies: [
		wayland_server,
		xcb,
		xcb_composite,
		xcb_xfixes,
		xcb_image,
		xcb_render,
		xcb_icccm,
		pixman,
	],
)
