if [ $# -eq 0 ]; then
	echo "no argument supplied"
	exit ;
fi

for file in `ls $1/map_error`; do
	echo $file
	valgrind ./cub3D "$1/map_error/$file"
	read -n1
done