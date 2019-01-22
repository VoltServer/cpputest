#!/bin/bash

# Modified project creation script for VoltServer

PROJECT_NAME=$1
CODE_LEGAL_PROJECT_NAME=$(echo $PROJECT_NAME | sed 's/-/_/g')
TEMPLATE_DIR=${CPPUTEST_HOME}/scripts/templates
ORIGINAL_DIR=$(pwd)

if [ -e ${PROJECT_NAME} ] ; then
	echo "The directory ${PROJECT_NAME} already exists"
	exit 1;
fi

# Changes all occurances of 'Project' in $1/$2 to $3
# $1 - path to file
# $2 - file name
# $3 - new project name
changeProjectName() {
    echo Modifying template file: $1/$2 ...
    sed "-e s/Project/$3/g" $1/$2 | tr -d "\r" >$1/$3$2
    mv $1/$3$2 $1/$2
}

echo "Copy template project"

mkdir ${PROJECT_NAME}
cd ${PROJECT_NAME}
mkdir -p Unittests/mocks

cp ${CPPUTEST_HOME}/scripts/VoltServerTemplate/code_under_test.c .
cp ${CPPUTEST_HOME}/scripts/VoltServerTemplate/code_under_test.h .
cp ${CPPUTEST_HOME}/scripts/VoltServerTemplate/Unittests/AllTests.cpp Unittests/
cp ${CPPUTEST_HOME}/scripts/VoltServerTemplate/Unittests/Makefile Unittests/
cp ${CPPUTEST_HOME}/scripts/VoltServerTemplate/Unittests/first_test.cpp Unittests/

changeProjectName Unittests Makefile ${CODE_LEGAL_PROJECT_NAME}

cd ${ORIGINAL_DIR}
echo "Be sure to update the Makefile as appropriate for the new project.  Good luck!"
