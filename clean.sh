#!/bin/bash

GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Go through each Cpp directory
for cpp_dir in Cpp*/; do
    echo -e "${GREEN}Entering directory: ${BLUE}$cpp_dir${NC}"
    
    # Go through each exercise directory
    cd "$cpp_dir"
    for ex_dir in ex*/; do
        echo -e "  ${GREEN}Cleaning: ${BLUE}$ex_dir${NC}"
        cd "$ex_dir"
        make fclean
        cd ..
    done
    
    cd ..
done