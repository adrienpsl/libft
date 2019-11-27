rm -rf render/*
mkdir -p render/includes;
mkdir -p render/src;

cp Makefile render
cp includes/* render/includes
find ./src -type f -name "*.h" -exec cp {} ./render/includes \; ;
find ./src -type f -name "*.c" -not -name "*test*" -exec cp {} ./render/src \; ;

cd ./render
make;
cd ./..;

cp log.h ./render/includes/log.h;
norminette ./render/src;
norminette ./render/includes;
