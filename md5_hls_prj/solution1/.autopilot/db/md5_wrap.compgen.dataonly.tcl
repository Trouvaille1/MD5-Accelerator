# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_CTRL {
ap_start { }
ap_done { }
ap_ready { }
ap_idle { }
ap_return { 
	dir o
	width 32
	depth 1
	mode ap_ctrl_hs
	offset 16
	offset_end 0
}
text_length { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 24
	offset_end 31
}
interrupt {
}
}
dict set axilite_register_dict CTRL $port_CTRL


set port_control {
text_input { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 16
	offset_end 27
}
result { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 28
	offset_end 39
}
}
dict set axilite_register_dict control $port_control


