###########################################################################
####             created by zsjum -- 07.12.11                          ####
#####                                                                ######
###########################################################################
#编译工具
#compile tool
CC = g++
 
#存放头文件路径
#the path of the head files
INCLUDE_DIR= -Iinclude -I/usr/local/include/libavformat/ -I/usr/local/include/libavutil/ -I/usr/local/include/libavcodec/ -I/usr/local/include/libswscale -I/usr/local/include/opencv
 
#加载库 -L 加载路径 -l 加载库的名称
#load lib   -L load path of the lib ; -l load name of the lib
LIBS=-L/usr/local/lib/ -lavformat -lavcodec -lswscale -lcv -lcvaux -lcxcore -lhighgui
 
#目标工程命名
#name the target project
TARGET=DSD
 
# 编译器设置 (-wall 输出警告信息; -O 编译时进行优化),请参看GCC 参数设置
# compile option(-wall output warning message; -O optimize compile)
CFLAGS = -Wall -O3
 
# 获取本地 .c 后缀所有文件列表并赋值变量SOURCES
# get all files name is *.c to SOURCES
SOURCES=$(wildcard src/*.c) $(wildcard src/*.cpp)
 
#将变量SOUTCE_C的所有*.c改成*.o,付直给变量OBJECT_O
#replace *.c to *.o from variable SOUTCE_C, and get the name string to variable OBJECT_O
OBJECT_O=$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCES)))
 
#下面是"隐含规则"生成函数库打包文件(也可以用"后缀规则"生成, 请参考详细Makefile文档)
#%.o表明所有以“.o”后缀的目标集, 如 "test1.o test2.o"
#依赖模式"%.c"就是取模式“%.o”的“%”,并加上".c"的后缀,如 "test1.c test2.c" 
#"$<"是指所有的依赖目标集,如 "test1.c test2.c"
#"$@"是指所表示目标 集,如 "test1.o test2.o" 
#参数 -c:编译但不连接; -I:头文件路径; -o:输出 (参照 gcc --help)
#Compile and assemble, but do not link
 
#.c.o:
%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDE_DIR) $< -o $@
%.o: %.cpp
	$(CC) -c $(CFLAGS) $(INCLUDE_DIR) $< -o $@
#$(CC) -c $(CFLAGS) $(INCLUDE_DIR) $< -o $@  
 
#$(CC) $(CFLAGS) $(MENUINC) -c $< -o $@
 
 
$(TARGET): $(OBJECT_O)
# $(CC) $(OBJECT_O) -o $(TARGET)
# $(CC) ${CFLAGS}   $(OBJECT_O) $(INCLUDE_DIR) $(LIBS) -o $(TARGET)
	$(CC) ${CFLAGS}   $(OBJECT_O) $(INCLUDE_DIR) $(LIBS) -o $@
clean:
	rm test src/*.o -rf
