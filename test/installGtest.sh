set -e 

echo "INSTALLING GTEST"

cd googletest && cmake .

cd googletest && sudo make all install
