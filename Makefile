#------VARIABLES------

CXX := clang++
CXXFLAGS :=-g -Wall -std=c++20

CC := clang
CCFLAGS := -g -Wall -std=c17

SRCS := $(wildcard *.c *.cpp *.cxx)
OBJCTS := $(SRCS:.cpp=.o)
OBJCTS := $(OBJCTS:.c=.o) 
OBJCTS := $(OBJCTS:.cxx=.o)
DEPS := deps.d
EXE := program
#------DEFAULT TARGET-----

.PHONY: all clean cleanprogram
all:	$(EXE)

#-------RUNNING TARGET------

run:	$(EXE)
	clear
	@echo "--------RUNNING PROGRAM-------"
	@./$(EXE)
#------COPILATION SOURCE FILES INTO SEPARATE OBJECT FILES-----
$(DEPS):
	$(CXX) $(CXXFLAGS) -MM $(SRCS) > $(DEPS)

-include $(DEPS)

%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o:	%.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o:	%.c
	$(CC) $(CCFLAGS) -c $< -o $@

#------GROUP OBJECT FILES-----

$(EXE): $(OBJCTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

#------CLEAN TARGET----------
clean:
	@rm -rf *.o *.d *.dSYM $(EXE)
cleanprogram:	clean
	@rm -f *.cpp *.h *.cxx *.hpp