# =============================================================================
#  Make include file proba1_rti.mk:
#
#   RTI1005 5.6 (16-Nov-2007)
#   Wed Mar 19 12:01:30 2014
#
#   Copyright (c) 1999-2002 dSPACE GmbH, GERMANY
# =============================================================================

# Initialize variables used in blockset makefiles -----------------------------

BLOCKSET_LIBS     :=
BLOCKSET_SRCS     :=
BLOCKSET_INCLUDES :=

# Default rules for additional blocksets --------------------------------------

blockset_init  :
blockset_clean :
blockset_deps  :

# Includes for additional blocksets -------------------------------------------



# Model-specific options ------------------------------------------------------

# Additional C source files declared by the model
MDL_CUSTOM_C_SRCS = rti_assert.c

# Additional assembler source files declared by the model
MDL_CUSTOM_ASM_SRCS =

# Additional libraries declared by the model
MDL_CUSTOM_LIBS = \
  "$(DSPACE_ROOT)\DS1005\RTPython\dsrtt1005.lib"

# Additional objects declared by the model
MDL_CUSTOM_OBJS =

# Directories where additional C and assembler source files are stored
MDL_CUSTOM_SRCS_DIR =

# Directories where additional header files are stored
MDL_CUSTOM_INCLUDES_PATH = \
  "$(DSPACE_ROOT)\DS1005\RTPython"


# EOF -------------------------------------------------------------------------
