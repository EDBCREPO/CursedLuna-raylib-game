mkdir -p www ; mkdir -p build

if [ ! -d "./build/_deps" ]; then
   ( cd build ; cmake .. )
fi

( cd build ; make ) ; ./build/main