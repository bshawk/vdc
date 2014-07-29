export LD_LIBRARY_PATH=/home/ubu/work/ve/linux/lib/:$LD_LIBRARY_PATH
mkdir -p ./ve/videodb/

###########NO GUI #############################
export QT_QPA_FONTDIR=.
./bin/vdcEyeManager -platform offscreen
###############################################

