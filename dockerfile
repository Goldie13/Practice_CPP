FROM ubuntu:latest
RUN apt-get -y update && 
apt install -y libprotobuf-dev protobuf-compiler &&
apt install -y gcc clang clang-tools cmake python3 gdb &&
apt-get -y install vim