OBJS = ./src/*.cpp

# Change these paths to wherever your 'i686-w64-mingw32' folder is. 
# In my scenario it is in D:\programming\i686-w64-mingw32 and therefore the line should be: -ID:\programming   
INC_PATH = -IC:/Users/Phong/Desktop/SDL2-2.0.14
LIB_PATH = -LC:/Users/Phong/Desktop/SDL2-2.0.14

HEADERS =  -I./src/headers
OBJ_NAME = ./debug/starbg
INCLUDE = $(INC_PATH)/x86_64-w64-mingw32/include
LIBRARY = $(LIB_PATH)/x86_64-w64-mingw32/lib
FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

all : $(OBJS)
	g++ $(OBJS) $(INCLUDE) $(HEADERS) $(LIBRARY) $(FLAGS) -o $(OBJ_NAME)
