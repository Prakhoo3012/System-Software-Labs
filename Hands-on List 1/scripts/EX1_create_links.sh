# !/bin/bash

echo "This is a original file." > "original.txt"
ls -l original.txt
echo    

ln -s original.txt soft_link.txt
ls -l soft_link.txt
echo "Content via soft link:"
cat soft_link.txt    
echo

ln original.txt hard_link.txt
echo "Inode numbers (should match for original.txt & hard.txt):"
ls -li original.txt hard_link.txt
echo

mkfifo myfifo
ls -l myfifo
echo "FIFO created. To text manually, open two terminals:"
echo "Terminal 1: echo hello > myfifo"
echo "Terminal 2: cat myfifo"

