
SRC := ./src
INC := ./inc

CPPFLAGS := -Wall -Werror -std=c++11
INCLUDES := -I${INC}

heapsort: ${SRC}/heapsort.cpp
	g++ -o ./programs/heapsort ${CPPFLAGS} ${INCLUDES} ${SRC}/heapsort.cpp
