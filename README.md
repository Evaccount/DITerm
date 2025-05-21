# DITerm

This project lets you display images in a terminal. It's not very complete, but the main thing is there.

## Dependencies

this project needs OpenCV to be compiled. You can install it as follows:
```
sudo apt install -y g++ cmake make wget unzip
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
unzip opencv.zip
mv opencv-4.x opencv
mkdir -p build && cd build
cmake ../opencv
make -j4
sudo make install
```

## Compile

Then you can compile the project as follows :
```
cd DITerm
mkdir build
cd build
cmake ..
make
```
