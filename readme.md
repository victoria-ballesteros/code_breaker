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
***Windows*** 
Download and install MinGW-w64 and CMake from their official websites.

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
***Windows***
```sh
cd build
make
CodeBreaker.exe
```

