# Display source code automatically
layout src
layout regs

set auto-load safe-path on
set debuginfod enabled on
# enable pretty print
set print pretty on

# Load executable automatically
file build/all

# Search header/source files
directory src

# Stop at main
break main
