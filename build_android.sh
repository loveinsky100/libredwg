export NDK_ROOT="/Applications/AndroidNDK8568313.app/Contents/NDK" # ndk path, api 30
export TOOLCHAIN=$NDK_ROOT/toolchains/llvm/prebuilt/darwin-x86_64
export SYSROOT=$TOOLCHAIN/sysroot
export CC=$TOOLCHAIN/bin/aarch64-linux-android21-clang
export CXX=$TOOLCHAIN/bin/aarch64-linux-android21-clang++

./autogen.sh  # 生成configure脚本（若未自动生成）
./configure --host=aarch64-linux-android

make clean
make CFLAGS="-Wno-sign-compare -Wno-format"
make install