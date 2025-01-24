
del db.dat
clear
make clean
make

echo "./ex17.exe db.dat c"
./ex17.exe db.dat c
echo "./ex17.exe db.dat s 1 zed zed@zedshaw.com"
./ex17.exe db.dat s 1 zed zed@zedshaw.com
echo "./ex17.exe db.dat s 2 frank frank@zedshaw.com"
./ex17.exe db.dat s 2 frank frank@zedshaw.com
echo "./ex17.exe db.dat s 3 joe joe@zedshaw.com"
./ex17.exe db.dat s 3 joe joe@zedshaw.com
echo "./ex17.exe db.dat l"
./ex17.exe db.dat l
echo "./ex17.exe db.dat d 3"
./ex17.exe db.dat d 3
echo "./ex17.exe db.dat l"
./ex17.exe db.dat l
echo "./ex17.exe db.dat g 2"
./ex17.exe db.dat g 2

#drmemory ./ex17.exe db2.dat c
del db.dat

echo "drmemory ./ex17.exe db.dat c"
drmemory ./ex17.exe db.dat c
echo "drmemory ./ex17.exe db.dat s 1 zed zed@zedshaw.com"
drmemory ./ex17.exe db.dat s 1 zed zed@zedshaw.com
echo "drmemory ./ex17.exe db.dat s 2 frank frank@zedshaw.com"
drmemory ./ex17.exe db.dat s 2 frank frank@zedshaw.com
echo "drmemory ./ex17.exe db.dat s 3 joe joe@zedshaw.com"
drmemory ./ex17.exe db.dat s 3 joe joe@zedshaw.com
echo "drmemory ./ex17.exe db.dat l"
drmemory ./ex17.exe db.dat l
echo "drmemory ./ex17.exe db.dat d 3"
drmemory ./ex17.exe db.dat d 3
echo "drmemory ./ex17.exe db.dat l"
drmemory ./ex17.exe db.dat l
echo "drmemory ./ex17.exe db.dat g 2"
drmemory ./ex17.exe db.dat g 2

