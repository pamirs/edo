#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define executables 
MD := mkdir
RM := rm
CC := g++

# define any compile-time flags
CFLAGS = -Wall -g -std=c++11

# define any directories containing header files other than /usr/include
#
INCLUDES = 

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LDFLAGS = 

CFLAGS += `pkg-config --cflags cppunit`
LDFLAGS += `pkg-config --libs cppunit`

OBJ_DIR = obj

SRCS = $(wildcard *.cpp) 

ifndef NOTEST
SRCS += $(wildcard ../test/*.cpp)
SRCS += $(wildcard ../../test/*.cpp)
endif

OBJS = $(join $(addsuffix $(OBJ_DIR)/, $(dir $(SRCS))), $(notdir $(SRCS:.cpp=.o)))

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix

#OBJS = $(CPP_FILES:.cpp=.o)

MAIN = boom

#The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all: $(MAIN)
	@echo  Compilation successful

$(MAIN): $(OBJS) 
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LDFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)

.cpp.o:
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

../test/obj/%.o : ../test/%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

../../test/obj/%.o : ../../test/%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@find ../. -name "*.o" -type f -delete
	@find ../. -name "*.~" -type f -delete
	@$(RM) -rf $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
