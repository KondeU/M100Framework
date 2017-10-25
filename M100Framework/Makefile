# Project: M100Framework
# Date:    2017-07-19
# Version: 1.1
# Authors: Deyou Kong <370242479@qq.com>


TARGET = Run.out

CXX = g++

DIR_RELEASE = ./Release

LDFLAGS = -Wl,-rpath,./ -L./ -lrt -lpthread


# Onboard

DIR_ONBOARD = ./SDK_Onboard
DIR_FLGT_INC = $(DIR_ONBOARD)/osdk-core/inc $(DIR_ONBOARD)/platform/manifold/inc $(DIR_ONBOARD)/sample/CommandlineLinux_old/inc $(DIR_ONBOARD)/sample/CommandlineLinux_old/DJIscript/inc
DIR_FLGT_SRC_LIBS = $(DIR_ONBOARD)/osdk-core/src
DIR_FLGT_SRC_MANIFOLD = $(DIR_ONBOARD)/platform/manifold/src
DIR_FLGT_SRC_DJITHREAD = $(DIR_ONBOARD)/sample/CommandlineLinux_old/src
DIR_FLGT_SRC_DJISCRIPT = $(DIR_ONBOARD)/sample/CommandlineLinux_old/DJIscript/src

FLGT_SOURCES_LIBS = DJI_API.cpp DJI_App.cpp DJI_Camera.cpp DJI_Codec.cpp DJI_Flight.cpp DJI_Follow.cpp DJI_HardDriver.cpp DJI_HotPoint.cpp DJI_Link.cpp DJI_Memory.cpp DJI_Mission.cpp DJI_VirtualRC.cpp DJI_WayPoint.cpp
FLGT_DIRSRCS_LIBS = $(addprefix $(DIR_FLGT_SRC_LIBS)/,$(FLGT_SOURCES_LIBS))
FLGT_OBJECTS_LIBS = $(addprefix $(DIR_RELEASE)/,$(FLGT_SOURCES_LIBS:.cpp=.obj))

FLGT_SOURCES_MANIFOLD = DJIHardDriverManifold.cpp
FLGT_DIRSRCS_MANIFOLD = $(addprefix $(DIR_FLGT_SRC_MANIFOLD)/,$(FLGT_SOURCES_MANIFOLD))
FLGT_OBJECTS_MANIFOLD = $(addprefix $(DIR_RELEASE)/,$(FLGT_SOURCES_MANIFOLD:.cpp=.obj))

FLGT_SOURCES_DJITHREAD = APIThread.cpp conboardsdktask.cpp
FLGT_DIRSRCS_DJITHREAD = $(addprefix $(DIR_FLGT_SRC_DJITHREAD)/,$(FLGT_SOURCES_DJITHREAD))
FLGT_OBJECTS_DJITHREAD = $(addprefix $(DIR_RELEASE)/,$(FLGT_SOURCES_DJITHREAD:.cpp=.obj))

FLGT_SOURCES_DJISCRIPT = cmdCamera.cpp cmdCoreAPI.cpp cmdFlight.cpp cmdFollow.cpp cmdHotPoint.cpp cmdIO.cpp cmdSettings.cpp cmdVirtualRC.cpp cmdWayPoint.cpp DJI_Interpreter.cpp DJI_Script.cpp
FLGT_DIRSRCS_DJISCRIPT = $(addprefix $(DIR_FLGT_SRC_DJISCRIPT)/,$(FLGT_SOURCES_DJISCRIPT))
FLGT_OBJECTS_DJISCRIPT = $(addprefix $(DIR_RELEASE)/,$(FLGT_SOURCES_DJISCRIPT:.cpp=.obj))

FLGT_OBJECTS = $(FLGT_OBJECTS_LIBS) $(FLGT_OBJECTS_MANIFOLD) $(FLGT_OBJECTS_DJITHREAD) $(FLGT_OBJECTS_DJISCRIPT)
FLGT_CXXFLAGS = -g -Wall --std=c++11 $(addprefix -I,$(DIR_FLGT_INC)) -pthread


# Task

DIR_CUSTOM = .
DIR_CUST_INC = $(DIR_CUSTOM) $(DIR_FLGT_INC) $(DIR_THRD_INC)
DIR_CUST_SRC = $(DIR_CUSTOM)

CUST_OBJECTS = $(DIR_RELEASE)/_Main.o $(DIR_RELEASE)/_Task.o $(DIR_RELEASE)/Flight.o $(DIR_RELEASE)/FlightIndoor.o $(DIR_RELEASE)/MyTask.o
CUST_CXXFLAGS = -g -Wall --std=c++11 $(addprefix -I,$(DIR_CUST_INC))


# Relationships

$(TARGET) : $(FLGT_OBJECTS) $(CUST_OBJECTS)
	$(CXX) -o $(DIR_RELEASE)/$(TARGET) $(FLGT_OBJECTS) $(CUST_OBJECTS) $(LDFLAGS)

$(DIR_RELEASE)/%.obj : $(DIR_FLGT_SRC_LIBS)/%.cpp
	$(CXX) $(FLGT_CXXFLAGS) -o $@ -c $<

$(DIR_RELEASE)/%.obj : $(DIR_FLGT_SRC_MANIFOLD)/%.cpp
	$(CXX) $(FLGT_CXXFLAGS) -o $@ -c $<

$(DIR_RELEASE)/%.obj : $(DIR_FLGT_SRC_DJITHREAD)/%.cpp
	$(CXX) $(FLGT_CXXFLAGS) -o $@ -c $<

$(DIR_RELEASE)/%.obj : $(DIR_FLGT_SRC_DJISCRIPT)/%.cpp
	$(CXX) $(FLGT_CXXFLAGS) -o $@ -c $<

$(DIR_RELEASE)/_Main.o : $(DIR_CUST_SRC)/_Main.cpp
	$(CXX) $(CUST_CXXFLAGS) -o $(DIR_RELEASE)/_Main.o -c $(DIR_CUST_SRC)/_Main.cpp

$(DIR_RELEASE)/_Task.o : $(DIR_CUST_SRC)/_Task.cpp
	$(CXX) $(CUST_CXXFLAGS) -o $(DIR_RELEASE)/_Task.o -c $(DIR_CUST_SRC)/_Task.cpp

$(DIR_RELEASE)/Flight.o : $(DIR_CUST_SRC)/Flight.cpp
	$(CXX) $(CUST_CXXFLAGS) -o $(DIR_RELEASE)/Flight.o -c $(DIR_CUST_SRC)/Flight.cpp

$(DIR_RELEASE)/FlightIndoor.o : $(DIR_CUST_SRC)/FlightIndoor.cpp
	$(CXX) $(CUST_CXXFLAGS) -o $(DIR_RELEASE)/FlightIndoor.o -c $(DIR_CUST_SRC)/FlightIndoor.cpp

$(DIR_RELEASE)/RMTask.o : $(DIR_CUST_SRC)/MyTask.cpp
	$(CXX) $(CUST_CXXFLAGS) -o $(DIR_RELEASE)/RMTask.o -c $(DIR_CUST_SRC)/MyTask.cpp

$(DIR_RELEASE)/MyTask.o : $(DIR_CUST_SRC)/MyTask.cpp
	$(CXX) $(CUST_CXXFLAGS) -o $(DIR_RELEASE)/MyTask.o -c $(DIR_CUST_SRC)/MyTask.cpp


# Commands

# If change header files, please make clean
clean:
	rm -f $(DIR_RELEASE)/$(TARGET) $(DIR_RELEASE)/*.o
	rm -f *~

cleanall:
	rm -f $(DIR_RELEASE)/*
	rm -f *~

cleantmp:
	rm -f *~
