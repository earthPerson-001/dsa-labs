#! /bin/bash

run_flag='false'
files_flag=''
build_flag=''
files_available='false'
custom_build_folder='false'
doxygen_flag='false'

print_usage() {
  printf "\nUsage: compile.sh \
  \n [ -f Directory containing src and include files] \
  \n [ -r whether to run or not] \
  \n [ -b build directory] \
  \n [ -d whether to update doxygen or not] \
  \n"
}

# Taking the arguments with flags
while getopts 'rf:b:d' flag; do
  case "${flag}" in
    r) run_flag='true' 
       ;;
    f) files_flag="${OPTARG}"
       files_available='true' 
       ;;
    b) build_flag="${OPTARG}"
       custom_build_folder='true'
       ;;
    d) doxygen_flag='true' 
       ;;
    *) print_usage
       exit 1 
       ;;
  esac
done

# for changing colours
GREEN="\033[0;32m"
BLUE="\033[0;34m"
CYAN="\033[0;36m"
MAGENTA="\033[0;35m"
YELLOW="\033[0;33m"
RED="\033[0;31m"
RESET="\033[0m"

#message if parent folder of src and include directory isn't passed
if [[ $# -eq 0 ]] ; then
    print_usage
    exit 1
fi

# Terminating with message if parent folder isn't provided
if [[ ${files_available} == "false" ]] ; then
    echo -e "${RED}Please specify the parent directory containing src and include directories$ with -f flag ${RESET} \n"
    print_usage
    exit 1
fi

echo -e "${GREEN}Using files under ${YELLOW}${files_flag}${GREEN} directory \n"

# The folder containing the .cpp files
SOURCE_DIRECTORY="${files_flag}/src"

# The folder containing the .h files
INCLUDE_DIRECTORY="${files_flag}/include"

# The folder to save executables
if [[ ${custom_build_folder} == "true" ]] ; then
    BUILD_DIRECTORY=${build_flag}
else
    BUILD_DIRECTORY="${files_flag}/../build"
fi

echo -e "${GREEN}Source Directory: ${YELLOW} ${SOURCE_DIRECTORY} ${RESET}\n"

echo -e "${GREEN}Include Directory: ${YELLOW} ${INCLUDE_DIRECTORY} ${RESET}\n"

echo -e "${GREEN}Build Directory: ${YELLOW} ${BUILD_DIRECTORY} ${RESET}\n"

EXECUTABLE_NAME="app"

# The compiler command
g++ ${SOURCE_DIRECTORY}/*.cpp -o ${BUILD_DIRECTORY}/${EXECUTABLE_NAME} -I ${INCLUDE_DIRECTORY} \
   -Wall -Wextra

# Checking if the app is required to run or not, opening the app if it is required
if [[ ${run_flag} == "true" ]] ; then 
    echo -e "${CYAN}Opening the app from ${MAGENTA}${BUILD_DIRECTORY}/${EXECUTABLE_NAME} ${RESET}"
    ${BUILD_DIRECTORY}/${EXECUTABLE_NAME}
fi


#doxygen stuffs
if [[ ${doxygen_flag} == "true" ]] ; then

  FILE_TO_WRITE_TO="Doxygen.manual"; # the doxygen config file for output of the generated files
  GITIGNORE_PATH=".gitignore"; # the gitignore files to ignores files and folders present in there

  # making an array out of gitignores
  arr=()
  while IFS= read -r line || [[ "$line" ]]; do
    arr+=("$line")
  done < ${GITIGNORE_PATH}

  # TODO: exclude directories inside of gitignores
  echo "INPUT += \\ ">>${FILE_TO_WRITE_TO};
  find . -name "*.cpp" ! -wholename ${arr} -prune \ -exec bash -c "echo '\"{}\" \\' >> ${FILE_TO_WRITE_TO}" \;

  echo "INCLUDE_PATH += \\ ">> ${FILE_TO_WRITE_TO};
  find . -name "*.hpp" ! -wholename ${arr} -prune \ -exec bash -c "echo '\"{}\" \\' >> ${FILE_TO_WRITE_TO}" \;
fi