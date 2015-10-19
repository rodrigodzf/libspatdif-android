# Install file for generating swig files and the android library library

#swig -c++ -java -package libspatdif -includeall -verbose -I/System/Library/Frameworks/JavaVM.framework/Headers -I./jni -o swig/jni/libspatdifwrapper.c spatdiflib.i
swig -c++ -java -package libspatdif -verbose -I/System/Library/Frameworks/JavaVM.framework/Headers -I./jni -o swig/jni/libspatdifwrapper.c spatdiflib.i
