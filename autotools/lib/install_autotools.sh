#!/bin/bash

OPTION="X86"
#OPTION="MIPS"
#OPTION="ARM"

if [ x${OPTION} = x"ARM" ]
then
PALTFORM="--build=arm-linux"
elif [ x${OPTION} = x"MIPS" ]
then
PALTFORM="--build=mips64el-neokylin-linux"
else
PALTFORM=""
fi

#参考链接:https://blog.csdn.net/hhko12322/article/details/21335503
#安装顺序是M4 ->  autoconf  -> automake
function build_autotools(){
	CURR_DIR=$(cd "$(dirname "$0")"; pwd)
	COMPILE_DIR="${CURR_DIR}/compile"

	[ ! -d  "${COMPILE_DIR}" ] && mkdir -p  ${COMPILE_DIR}

	unzip  -qo  "${CURR_DIR}/autotools.zip"  -d    ${COMPILE_DIR}

    DIR="${COMPILE_DIR}/autotools/"

	array=([0]="m4-1.4.18"  [1]="autoconf-2.69"  [2]="automake-1.16.2"  [3]="libtool-2.4.6")

	for autotool in  ${array[@]}
	do
		cd  ${DIR}
	    tar zxvf  ${autotool}.tar.gz
		cd  ${autotool}
	    ./configure  ${PALTFORM}
	    echo  "["${0} $FUNCNAME  $LINENO   `date +"%Y-%m-%d %H:%M:%S"` "]"   "./configure  ${PALTFORM}"
		make -j4; make install
	done

    M4_BIN="/usr/bin/m4"
    AUTOCONFIG_BIN="/usr/bin/autoconf"
    AUTOMAKE_BIN="/usr/bin/automake"
    LIBTOOL_BIN="/usr/bin/libtool"

	if [ -e ${M4_BIN} ]
	then
		echo "build m4 success!"
	else
		echo "build m4 failed!"
	fi

	if [ -e ${AUTOCONFIG_BIN} ]
	then
		echo "build autoconf success!"
	else
		echo "build autoconf failed!"
	fi


	if [ -e ${AUTOMAKE_BIN} ]
	then
		echo "build automake success!"
	else
		echo "build automake failed!"
	fi

	if [ -e ${LIBTOOL_BIN} ]
	then
		echo "build libtool success!"
	else
		echo "build libtool failed!"
	fi

    autoscan  --version
    aclocal   --version
    autoconf   --version
    autoheader  --version
    automake   --version



}

function main(){
	build_autotools
}

#----------------------------------------------------------------------------------------------------------
#   main  function  enter
#----------------------------------------------------------------------------------------------------------
main


