#ifndef WLR_TYPES_WLR_POINTER_H
#define WLR_TYPES_WLR_POINTER_H

#include <wlr/types/wlr_input_device.h>
#include <wayland-server.h>
#include <stdint.h>

struct wlr_pointer_impl;

struct wlr_pointer {
	struct wlr_pointer_impl *impl;

	struct {
		struct wl_signal motion;
		struct wl_signal motion_absolute;
		struct wl_signal button;
		struct wl_signal axis;
	} events;

	void *data;
};

struct wlr_event_pointer_motion {
	struct wlr_input_device *device;
	uint32_t time_msec;
	double delta_x, delta_y;
};

struct wlr_event_pointer_motion_absolute {
	struct wlr_input_device *device;
	uint32_t time_msec;
	double x_mm, y_mm;
	double width_mm, height_mm;
};

struct wlr_event_pointer_button {
	struct wlr_input_device *device;
	uint32_t time_msec;
	uint32_t button;
	enum wlr_button_state state;
};

enum wlr_axis_source {
	WLR_AXIS_SOURCE_WHEEL,
	WLR_AXIS_SOURCE_FINGER,
	WLR_AXIS_SOURCE_CONTINUOUS,
	WLR_AXIS_SOURCE_WHEEL_TILT,
};

enum wlr_axis_orientation {
	WLR_AXIS_ORIENTATION_VERTICAL,
	WLR_AXIS_ORIENTATION_HORIZONTAL,
};

struct wlr_event_pointer_axis {
	struct wlr_input_device *device;
	uint32_t time_msec;
	enum wlr_axis_source source;
	enum wlr_axis_orientation orientation;
	double delta;
};

#endif
