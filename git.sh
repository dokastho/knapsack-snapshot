#!/bin/bash
make clean 
make fullsubmit
sudo git add .
sudo git commit
sudo git push --force -u origin HEAD:main
echo done!
