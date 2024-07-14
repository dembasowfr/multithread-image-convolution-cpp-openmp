

# clean the current build
make clean
make

# create necessary directories if they don't exist
mkdir -p output/img_mats
mkdir -p output/out_mats

# make image matrices and store them
python3 helpers/make_mats.py output/img_mats/out.dat

# run the filter program
./output/main output/img_mats/out.dat output/img_mats/filter_out.dat < input/text/kernel.txt

# run python program to generate images from matrix
# output written as 0.bmp, 1.bmp ...
python3 helpers/load_img.py output/img_mats/filter_out.dat output/out_mats
