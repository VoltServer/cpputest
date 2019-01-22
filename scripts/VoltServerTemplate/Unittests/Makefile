#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = Project
#Set this to @ to keep the makefile quiet
SILENCE = @

#--- Inputs ----#
PROJECT_HOME_DIR = .
ifeq "$(CPPUTEST_HOME)" ""
    CPPUTEST_HOME = ../CppUTest
endif
CPP_PLATFORM = Gcc

# to pick specific files (rather than directories) use this:    
SRC_FILES = ../code_under_test.c

TEST_SRC_DIRS = .

MOCKS_SRC_DIRS = mocks

INCLUDE_DIRS = \
  . \
  .. \
  $(CPPUTEST_HOME)/include/ \
  $(CPPUTEST_HOME)/include/Platforms/Gcc\
  mocks

CPPUTEST_WARNINGFLAGS = -Wall -Werror -Wswitch-default 
CPPUTEST_WARNINGFLAGS += -Wconversion -Wswitch-enum 
CPPUTEST_CPPFLAGS += -DCOMPILE_FOR_UNIT_TEST

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

