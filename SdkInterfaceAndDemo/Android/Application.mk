
# NDK�ı���ϵͳ��Ĭ��û�д�STL��֧�֣���Ҫ����APP_STL�󣬲ſ����ڴ�����ʹ��STL
# ����APP_STL��NDK�ı���ϵͳ�����Զ�����������Ҫ��ͷ�ļ�·����lib�ļ�����صı��뻷����
APP_STL := stlport_static

# ֻ���� armeabi-v7a ָ�
APP_ABI := armeabi-v7a

# ���� NDK_TOOLCHAIN_VERSION ����ѡ����ʹ�õı��빤����
# ����Ϊclang����ʾʹ��Clang���룬����Ϊ4.9����ʾʹ��gcc����
# Android NDK �Ĺٷ��ĵ��������clang���롣ϵͳĬ�ϲ���gcc
# ԭ���ǣ�We strongly recommend switching to Cla/downloads/reng. ������Բο�������ַ��
# https://developer.android.com/ndkvision_history.html
# ʵ�⣬�� i5, 16G RAM �Ļ����ϣ�gcc������Ҫ90�룬clang������Ҫ60��
NDK_TOOLCHAIN_VERSION:= clang

# ������Ĭ����û�������쳣�ģ���ˣ���Ҫ�ֶ�ָ�� -fexceptions �������ſ�����c++��ʹ���쳣��
APP_CPPFLAGS := -fexceptions  \
#		-std=c++11

# �������Ŀ���ļ���·��
NDK_APP_LIBS_OUT:=../bin/android

# �����м��ļ���Ŀ���ļ�·��
NDK_APP_OUT:=./objs/android