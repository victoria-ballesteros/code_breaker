# CodeBreaker  

## **Requirements**  
***Make sure you have CMake and OpenSSL tools installed.***  

### **Check installation:**  
Run the following commands to verify that you have everything installed:  
```sh
cmake --version
g++ --version
make --version
```
If something's missing, install the required tools:
***Linux (RedHat-based: Fedora, CentOS, RHEL)***
```sh
sudo dnf install cmake gcc-c++ make git -y
sudo dnf install openssl openssl-devel
sudo dnf install libssl-dev
```
## **Project setup:**
```sh
mkdir build
cd build
cmake ..
```
## **Compile and execute:**
***Linux and MacOs***
```sh
cd build
make
./CodeBreaker
```
### WINDOWS (IMPORTANT)
- There's two .lib files inside the assets folder. This ones must be always in the same folder as the main.exe
- To compile, cd the assets folder and execute the next line (must have mingw32 compiler installed):
```sh
x86_64-w64-mingw32-g++ ../src/*.cpp -std=c++11 -static-libstdc++ -o main.exe -Ilib/ -lssl libcrypto.lib libssl.lib
```