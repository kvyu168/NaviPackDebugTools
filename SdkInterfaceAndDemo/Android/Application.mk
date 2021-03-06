
# NDK的编译系统，默认没有打开STL的支持，需要设置APP_STL后，才可以在代码中使用STL
# 设置APP_STL后，NDK的编译系统，将自动添加其所需要的头文件路径和lib文件到相关的编译环境中
APP_STL := stlport_static

# 只编译 armeabi-v7a 指令集
APP_ABI := armeabi-v7a

# 设置 NDK_TOOLCHAIN_VERSION 用于选择所使用的编译工具链
# 设置为clang，表示使用Clang编译，设置为4.9，表示使用gcc编译
# Android NDK 的官方文档建议采用clang编译。系统默认采用gcc
# 原话是：We strongly recommend switching to Cla/downloads/reng. 具体可以参考如下网址：
# https://developer.android.com/ndkvision_history.html
# 实测，在 i5, 16G RAM 的机器上，gcc编译需要90秒，clang编译需要60秒
NDK_TOOLCHAIN_VERSION:= clang

# 编译器默认是没有启用异常的，因此，需要手动指定 -fexceptions 参数，才可以在c++中使用异常。
APP_CPPFLAGS := -fexceptions  \
#		-std=c++11

# 设置输出目标文件的路径
NDK_APP_LIBS_OUT:=../bin/android

# 设置中间文件和目标文件路径
NDK_APP_OUT:=./objs/android