echo -n "**** BUILDING PEDALBOARD TESTS ****"

TEST_PATH=$(pwd)

mkdir build
cd build && cmake $TEST_PATH && make all
echo $'\n'
echo -n "**** RUNNIG PEDALBOARD TESTS ****"
echo $'\n'
cd $TEST_PATH && ./build/pedalboardTests
