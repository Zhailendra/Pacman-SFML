rm -rf ./build ./libs ./pacman
mkdir build
cd build
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build . -j "$(find ../include ../src -name '*.cpp' | wc -l)"
cd ..
ls ./pacman ./libs