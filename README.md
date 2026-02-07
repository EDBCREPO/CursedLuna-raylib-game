# Cursed Luna
A simple game made with C++, Nodepp and raylib 
https://edbcrepo.itch.io/cursed-luna

## Dependencies
```bash
📌Nodepp: https://github.com/NodeppOficial/nodepp-wasm
📌Raylib: https://www.raylib.com/
```

## Preview
https://github.com/user-attachments/assets/3647b5b6-fbfd-4281-af0f-f35f3260a319

## Build & Use
```bash
export LD_LIBRARY_PATH=./lib
time g++ -o main main.cpp -I./include -L./lib -lraylib -lssl -lcrypto ; ./main
```
