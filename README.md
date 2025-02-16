# Cursed Luna
A simple game made with C++, Nodepp and raylib

## Dependencies
```bash
📌Nodepp: https://github.com/NodeppOficial/nodepp-wasm
📌Raylib: https://www.raylib.com/
```

## Preview
[Preview](https://github.com/user-attachments/assets/b09a8798-3dba-4e7b-9996-79415deead11)

## Build & Use
```bash
export LD_LIBRARY_PATH=./lib
time g++ -o main main.cpp -I./include -L./lib -lraylib -lssl -lcrypto ; ./main
```
