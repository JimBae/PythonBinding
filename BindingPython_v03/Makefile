#----------##
# Makefile ##
#-----------------------------#
# Jinhyuk Bae   			  #
# Updated data : 2016.06.27   #
#-----------------------------#

HOME_DIR   = $(shell pwd)

PROJECTS    = spam

HEADER_PATH = ./header
SOURCE_PATH = ./source
OBJECT_PATH = ./object
OUTPUT_PATH = .

CC               = g++
NVCC             = nvcc

HEADER_DIR       := -I/usr/include 
HEADER_DIR       += -I/usr/local/include
HEADER_DIR       += -I/usr/include/OpenEXR
HEADER_DIR       += -I/usr/include/python2.7
HEADER_DIR       += -I$(HEADER_PATH)

LIBS             = -L/usr/lib64
LIBS			+= -L/usr/lib
LIBS			+= -L/usr/lib/x86_64-linux-gnu
LIBS			+= -L/usr/local/lib
LIBS            += -lpthread -lgomp -lz
LIBS            += -lHalf -lpython2.7


#CCFLAGS        = -O3 -m64 -fpic -fopenmp -Wno-deprecated -std=c++11 -g -DNDEBUG #-DNDEBUG  #-Os -DNDEBUG
#CCFLAGS        = -Wall -O3 -m64 -std=c++11 -fpic -fopenmp  -Wno-deprecated -Wno-unused-variable
CCFLAGS        = -Wall -m64 -fPIC -DNDEBUG -lX11#-DNDEBUG  #-Os -DNDEBUG
LDFLAGS       := -shared -fopenmp
CUFLAGS       := -m64 -Xcompiler -fPIC

CPP_SOURCES   := $(wildcard $(SOURCE_PATH)/*.cpp)
CPP_LIST      := $(notdir $(CPP_SOURCES))							# *.cpp
OBJ_LIST      := $(addprefix $(OBJECT_PATH)/,$(CPP_LIST:.cpp=.o)) 	# object/*.o

.SILENT:

all: $(PROJECTS).so

# .o -> project
$(PROJECTS).so: $(OBJ_LIST)
	$(CC) $(LDFLAGS) $(LIBS) -o $(OUTPUT_PATH)/$@ $(OBJ_LIST)

# .cpp -> .o
$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.cpp
	$(CC) $(CCFLAGS) $(HEADER_DIR) $(SWITCHES) -c $< -o $@

clean:
	rm -rf ./object/*
	rm -rf $(PROJECTS)*



#HOME_DIR   = $(shell pwd)
#
#PROJECTS    = spammodule
#
#HEADER_PATH = ./header
#SOURCE_PATH = ./source
#OBJECT_PATH = ./object
#OUTPUT_PATH = .
#
#CC               = g++
#NVCC             = nvcc
#
#HEADER_DIR       := -I/usr/include 
#HEADER_DIR       += -I/usr/local/include
#HEADER_DIR       += -I/usr/include/OpenEXR
#HEADER_DIR       += -I/usr/include/python2.7
#HEADER_DIR       += -I$(HEADER_PATH)
#
#LIBS             = -L/usr/lib64
#LIBS			+= -L/usr/lib
#LIBS			+= -L/usr/lib/x86_64-linux-gnu
#LIBS			+= -L/usr/local/lib
#LIBS            += -lpthread -lgomp -lz
#LIBS            += -lHalf
#
#CCFLAGS        = -O3 -m64 -fpic -fopenmp -Wno-deprecated -std=c++11 -g -DNDEBUG #-DNDEBUG  #-Os -DNDEBUG
##CCFLAGS        = -Wall -O3 -m64 -std=c++11 -fpic -fopenmp  -Wno-deprecated -Wno-unused-variable
#LDFLAGS       := -shared -fopenmp
#CUFLAGS       := -m64 -Xcompiler -fPIC
#
#CPP_SOURCES   := $(wildcard $(SOURCE_PATH)/*.cpp)
#CPP_LIST      := $(notdir $(CPP_SOURCES))							# *.cpp
#OBJ_LIST      := $(addprefix $(OBJECT_PATH)/,$(CPP_LIST:.cpp=.o)) 	# object/*.o
#
#.SILENT:
#
#all: lib$(PROJECTS).so
#
## .o -> .so
#lib$(PROJECTS).so: $(OBJ_LIST)
#	$(CC) $(LDFLAGS) $(LIBS) -o $(OUTPUT_PATH)/$@ $(OBJ_LIST)
#
## .cpp -> .o
#$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.cpp
#	$(CC) $(CCFLAGS) $(HEADER_DIR) $(SWITCHES) -c $< -o $@
#
#clean:
#	rm -rf ./object/*
#	rm -rf $(PROJECTS)*
