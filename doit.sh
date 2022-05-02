cmake -B build -S .
cmake --build build
mkdir -p S
cp build/CMakeFiles/test_*.dir/*.s S
#rm -rf build